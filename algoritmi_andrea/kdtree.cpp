#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF (1000000000)

typedef int ll;

struct point {
  ll x, y;
  inline bool operator ==(point const& other) const {
    return x == other.x && y == other.y;
  }
};

inline ll absll(ll x) {
  return x < 0 ? -x : x;
}

inline ll manh(ll x, ll y, point const& pt) {
  // printf("%lld %lld\n", x, y);
  return absll(pt.x-x) + absll(pt.y-y);
}

struct node {

  node(point *pts, int size) {
    x1 = x2 = pts[0].x;
    y1 = y2 = pts[0].y;
    for (int i = 1; i < size; i++) {
        x1 = min(x1, pts[i].x);
        x2 = max(x2, pts[i].x);
        y1 = min(y1, pts[i].y);
        y2 = max(y2, pts[i].y);
    }
    left = right = NULL;
    len = 0;
  }

  ll manhattan(point const& pt) {
    if (x1 <= pt.x && pt.x <= x2) {
      if (y1 <= pt.y && pt.y <= y2)
        return 0;
      return min(absll(pt.y-y1), absll(pt.y-y2));
    }
    if (y1 <= pt.y && pt.y <= y2)
      return min(absll(pt.x-x1), absll(pt.x-x2));

    ll dist = manh(x1, y1, pt);
    dist = min(dist, manh(x1, y2, pt));
    dist = min(dist, manh(x2, y1, pt));
    return min(dist, manh(x2, y2, pt));
  }

  // INTERSECTION contained(point const& pt, ll radsq) {
  //   ll d1 = manh(x1, y1, pt);
  //   ll d2 = manh(x1, y2, pt);
  //   ll d3 = manh(x2, y1, pt);
  //   ll d4 = manh(x2, y2, pt);
  //   if (d1 <= radsq &&
  //       d2 <= radsq &&
  //       d3 <= radsq &&
  //       d4 <= radsq)
  //           return CONTAINED;
  //
  //
  //   if (x1 <= pt.x && pt.x <= x2) {
  //     if (y1 <= pt.y && pt.y <= y2) {
  //       return INTERSECT;
  //     }
  //     if (min((pt.y-y1)*(pt.y-y1), (pt.y-y2)*(pt.y-y2)) <= radsq)
  //       return INTERSECT;
  //     return DISTINCT;
  //   }
  //   if (y1 <= pt.y && pt.y <= y2) {
  //     if (min((pt.x-x1)*(pt.x-x1), (pt.x-x2)*(pt.x-x2)) <= radsq)
  //       return INTERSECT;
  //     else
  //       return DISTINCT;
  //   }
  //   if (min(min(d1, d2), min(d3, d4)) > radsq) return DISTINCT;
  //   return INTERSECT;
  // }

  ll x1, y1;
  ll x2, y2;
  point *pts;
  int len;
  node *left;
  node *right;
};

struct xsort {
  inline bool operator()(point const& a, point const& b) {
    return a.x < b.x;
  }
};

struct ysort {
  inline bool operator()(point const& a, point const& b) {
    return a.y < b.y;
  }
};


node *create(point* pts, int len, int dim = 0) {
  node *n = new node(pts, len);
  if (len <= 96) {
    n->pts = pts;
    n->len = len;
    return n;
  }

  if (dim)
    nth_element(pts, pts+(len/2), pts+len, xsort());
  else
    nth_element(pts, pts+(len/2), pts+len, ysort());

  int cnt = len / 2;
  // while (cnt < len-1 && pts[cnt+1] == pts[cnt]) cnt++;

  n->left = create(pts, cnt, !dim);
  n->right = create(pts+cnt, len-cnt, !dim);
  return n;
}

ll nearest(node *root, point query, ll bsf) {
  if (root->len) {
    ll dst = INF;//manh(best.x, best.y, query);
    for (int i = 0; i < root->len; i++) {
      ll dst2 = manh(root->pts[i].x, root->pts[i].y, query);
      if (dst2 < dst && dst2>0) {
        dst = dst2;
      }
    }
    return dst;
  }

  ll ld = root->left ? root->left->manhattan(query) : INF;
  ll rd = root->right ? root->right->manhattan(query) : INF;
  bool right;

  if (ld <= rd && ld < bsf) {
    bsf = min(bsf, nearest(root->left, query, bsf));
    right = false;
  }
  else if (rd <= ld && rd < bsf) {
    bsf = min(bsf, nearest(root->right, query, bsf));
    right = true;
  }
  else
    return bsf;



  if (!right && rd < bsf) {
    bsf = min(bsf, nearest(root->right, query, bsf));
  }
  else if (right && ld < bsf) {
    bsf = min(bsf, nearest(root->left, query, bsf));
  }
  return bsf;
}

// ll countcircle(node *root, point center, ll sizesq) {
//   func++;
//
//   INTERSECTION status = root->contained(center, sizesq);
//
//   switch (status) {
//     case DISTINCT: return 0;
//     case CONTAINED: return root->cnt;
//   }
//
//   int count = 0;
//
//   if (root->pts.size()) {
//     for (int i = 0; i < root->pts.size(); i++) {
//       ll dst = manh(root->pts[i].x, root->pts[i].y, center);
//       if (dst <= sizesq) {
//         count++;
//       }
//     }
//     return count;
//   }
//
//   ll ld = root->left ? root->left->manhattan(center) : INF;
//   ll rd = root->right ? root->right->manhattan(center) : INF;
//
//   if (ld <= sizesq) {
//     count += countcircle(root->left, center, sizesq);
//   }
//   if (rd <= sizesq) {
//     count += countcircle(root->right, center, sizesq);
//   }
//   return count;
// }


ll naive(point* pts, int len, point query) {
  ll dist = max(manh(query.x, query.y, pts[0]), manh(query.x, query.y, pts[1]));
  for (int i = 0; i < len; i++) {
    ll d = manh(query.x, query.y, pts[i]);
    if (d < dist && d) {
      dist = d;
    }
  }
  return dist;
}

ll naivecnt(point* pts, int len, point center, ll radsq) {
  ll count = 0;
  for (int i = 0; i < len; i++) {
    ll d = manh(center.x, center.y, pts[i]);
    if (d <= radsq) {
      count++;
    }
  }
  return count;
}


void test() {
  vector<point> tmp;
  int N = 1000000;
  for (int i = 0; i < N; i++) tmp.push_back(point {rand()%1000000-N/2, rand()%1000000-N/2});
  node *kd = create(tmp.data(), tmp.size());

  int a = 0;
  for (int i = 0; i < N; i++) {
    point query = point {rand()%1000000, rand()%1000000};
    // func = 0;
    ll res = nearest(kd, query, INF);
    // ll radsq = rand()%1000000; radsq *= radsq;
    // ll res = countcircle(kd, query, radsq);
    // printf("CALL %d\n", func);

    // ll nai = naivecnt(tmp.data(), tmp.size(), query, radsq);

    ll nai = naive(tmp.data(), tmp.size(), query);
    a += res;
    // printf("KD %lld\n", res);
    // printf("NV %lld\n", nai);
    assert(res == nai);
    // printf("KD %lld %lld %f\n", res.x, res.y, sqrt(manh(res.x, res.y, query)));
    // printf("NV %lld %lld %f\n", nai.x, nai.y, sqrt(manh(nai.x, nai.y, query)));
    // assert(manh(res.x, res.y, query) == manh(nai.x, nai.y, query));
  }
  printf("A%d\n", a);
}

point pts[1000100];
point pts2[1000100];
int main(int argc, char const *argv[]) {
  // test();
  // return 0;
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d",&pts[i].x, &pts[i].y);
    pts2[i] = pts[i];
  }
  node *kd = create(pts, N);

  for (int j = 0; j < N; j++) {
    ll res = nearest(kd, pts2[j], INF);
    // assert(nai == res);

    printf("%d\n", res);
  }

  return 0;
}
