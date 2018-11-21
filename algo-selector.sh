#!/bin/bash

REPO="Algorithm-Anthology/Section-*"
SAVE="clean-cpp"
CODE_EXT="*.cpp"
ALGO_TEX="code.tex"

compilation_str="g++ -g -O2 -Wall -Wextra -std=gnu++14 -static -c -o \"%s\" \"%s\" -lm"
selected=(
        "2.3.2" "6.1" "1.3.4"
        "1.4.1" "2.5.2" "2.7.2"
        "5.3.4" "5.3.5" "5.3.6"
        "3.2.5" "3.3.4"
        )

rm -rf "$SAVE"
mkdir -p "$SAVE"

for code in $REPO/$CODE_EXT; do
    for s in ${selected[*]}; do
        if grep -q "/$s " <<< "$code"; then
            cp "$code" "$SAVE/$(basename "$code")"
        fi
    done
done

tmp=$(mktemp)
echo > "$ALGO_TEX"
for saved in $SAVE/$CODE_EXT; do
    sed -i '/\/\*\*\*.*/,$d' "$saved"
    sed '0,/\(#include <[a-z]\+>.*$\)\+/s//using namespace std;\n&/' <( tac "$saved") | tac > "$tmp"
    cat "$tmp" > "$saved"
    sed -i 's/std:://g' "$saved"
    python - << EOF
import re
comment_state = False
complexity_state = False
lines = []
new_file = []
with open("${saved}", 'r') as f:
    lines = f.readlines()
    for l in lines:
        if comment_state:
            if re.match(".*Complexity\:", l) and not complexity_state:
                complexity_state = True
                new_file[-1] = new_file[-1] + '\n\n' + l
            elif complexity_state:
                new_file[-1] = new_file[-1] + l
            else:
                new_file[-1] = new_file[-1] + l.strip() + ' '
        else:
            new_file.append(l)

        if re.match("\/\*", l):
            comment_state = True
            new_file[-1] = new_file[-1].strip() + ' '
        if re.match("\*\/", l):
            comment_state = False
            complexity_state = False
            new_file[-1] = new_file[-1][:-4] + '*/\n'
with open("${saved}", 'w') as f:
    for l in new_file:
        f.write("%s" % l)
EOF
    eval_comp_str="$(printf "$compilation_str" "$tmp" "$saved" )"
    if eval "$eval_comp_str" &>/dev/null; then
        printf "OK %s\n" "$saved"
    else
        printf "KO %s\n" "$saved"
    fi
    clean_name=$(sed 's/[0-9]\+\(\.[0-9]\+\)\+ //g;s/ /_/g' <(basename "$saved"))
    tex_name=$(sed   's/[0-9]\+\(\.[0-9]\+\)\+ //g;s/\.cpp//' <(basename "$saved"))
    mv "$saved" "$SAVE"/"$clean_name"
    cat << EOF >> "$ALGO_TEX"
\subsubsection*{${tex_name}}
\lstinputlisting[style=cpp]{${SAVE}/${clean_name}}
EOF
done
rm "$tmp"

