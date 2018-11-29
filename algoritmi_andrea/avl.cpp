#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

//16.05
//16.43
//17.32

enum CHILD {
  LEFT,
  RIGHT
};

struct node {
  int size;
  int value;
  node* left;
  node* right;
} nodes[10000000];

node *freen;


#define SZ(n) ((n) ? (n)->size : 0)

inline void updateup(node *&n) {
  n->size = SZ(n->left) + SZ(n->right) + 1;
}

inline void rrotate(node *&n) {
  // assert(n && n->child[!mode]);

  node *oldroot = n;
  n = oldroot->left;
  oldroot->left = n->right;
  n->right = oldroot;

  updateup(oldroot);
  updateup(n);
}

inline void lrotate(node *&n) {
  // assert(n && n->child[!mode]);

  node *oldroot = n;
  n = oldroot->right;
  oldroot->right = n->left;
  n->left = oldroot;

  updateup(oldroot);
  updateup(n);
}


inline int coeff(node *&n) {
    return SZ(n->left) - SZ(n->right);
}

void balance(node *&n) {
  int cf = coeff(n);
  if (cf > 1) {
    // if (coeff(n->left) < 0)
    //   lrotate(n->left);
    rrotate(n);
  }
  else if (cf < -1) {
    // if (coeff(n->right) > 0)
    //   rrotate(n->right);
    lrotate(n);
  }
}

void insert(node *&n, int pos, int value) {
  if (!n) {
    n = freen;
    n = new node {1, value, NULL, NULL};
    return;
  }

  int ls = SZ(n->left);
  if (pos <= ls) {
    insert(n->left, pos, value);
  }
  else {
    insert(n->right, pos-ls-1, value);
  }
  updateup(n);
  balance(n);
}

int reml(node *&n) {
  if (!n->left) {
    int val = n->value;
    node *tmp = n;
    n = n->right;
    freen = tmp;
    return val;
  }
  int v = reml(n->left);
  updateup(n);
  balance(n);
  return v;
}

int del(node *&n, int pos) {
  if (!n) return -1;
  int val;

  int ls = SZ(n->left);
  if (pos < ls) {
    val = del(n->left, pos);
  }
  else if (pos > ls) {
    val = del(n->right, pos-ls-1);
  }
  else {
    val = n->value;
    if (!n->right) {
      freen = n;
      n = n->left;
    }
    else {
      n->value = reml(n->right);
    }
  }
  if (n) {
    updateup(n);
    balance(n);
  }
  return val;
}

int get(node *n, int pos) {
  if (!n) return -1;

  int ls = SZ(n->left);

  if (pos < ls) {
    return get(n->left, pos);
  }
  else if (pos > ls) {
    return get(n->right, pos-ls-1);
  }

  return n->value;
}

void print(node *n, int d = 0) {
  if (!n) return;
  // for (int i = 0; i < d; i++) printf("\t");
  print(n->left, d+1);
  printf("%d ", n->value);//, n->size, SZ(n->left), SZ(n->right));
  print(n->right, d+1);
}

void create(node *&root, int s, int e) {
  if (e < s) return;
  int m = (s + e) / 2;
  root = nodes + m;
  *root = node {1, m, NULL, NULL};
  if (s == e) {
    return;
  }
  create(root->left, s, m-1);
  create(root->right, m+1, e);
  updateup(root);
}


int main(int argc, char const *argv[]) {

  int N, Q;

  assert(freopen("input.txt","r",stdin) != NULL);
  assert(freopen("output.txt","w",stdout) != NULL);
  assert(scanf("%d%d", &N, &Q) == 2);


  node *root = NULL;
  create(root, 0, N);
  // dfs(tree.root, 0);
  // printf("Done.\n");
  for (int i = 0; i < Q; i++) {
    // for (int i = 0; i < N; i++) {printf("%d ", blk.getval(i));}
    // puts("");

    char op[2];
    int start;
    assert(scanf("%1s %d\n", op, &start) == 2);
    switch (op[0]) {
      case 's': {
        int end;
        assert(scanf("%d", &end) == 1);
        // printf("S: %c %d %d\n", op[0], start, end);
        // printf("**************** Removal.\n");
        int tmp = del(root, start);
        // dfs(tree.root, 0);
        // printf("Done.\n");
        // printf("**************** Insertion.\n");
        insert(root, end, tmp);
        // assert(root->height < (log2(N)+2)*2);
        // print(root);
        // puts("");
        // dfs(tree.root, 0);
        // printf("Done.\n");
        break;
      }
      case 'c':
        printf("%d ", get(root, start));
        break;
    }
  }
  puts("");

  // for (int i = 0; i < N; i++) {printf("%d ", blk.getval(i));}
  // puts("");


  return 0;
}

// int main() {
//   node *root = NULL;
//   create(root, 0, 60);
//   // for (int i = 0; i < 60; i++) {
//   //   insert(root, i, i);
//   //   // del(root, 0);
//   //
//   //   // print(root);
//   // }
//   del(root, 15);
//   // del(root, 5);
//   // del(root, 5);
//   printf("Root: %d\n", root->size);
//   for (int i = 0; i < 60; i++) {
//     printf("%d ", get(root, i));
//   }
//
//
//   puts("");
// }
