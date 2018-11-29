#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define INF (1000000000LL*1000000000LL)

typedef long long ll;

struct point {
  ll x, y;
  bool operator ==(point const& other) const {
    return x == other.x && y == other.y;
  }
};

enum INTERSECTION {
  DISTINCT,
  INTERSECT,
  CONTAINED
};

inline ll dsq(ll x, ll y, point const& pt) {
  // printf("%lld %lld\n", x, y);
  return (pt.x-x)*(pt.x-x) + (pt.y-y)*(pt.y-y);
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
    cnt = size;
  }

  ll distancesq(point const& pt) {
    if (x1 <= pt.x && pt.x <= x2) {
      if (y1 <= pt.y && pt.y <= y2)
        return 0;
      return min((pt.y-y1)*(pt.y-y1), (pt.y-y2)*(pt.y-y2));
    }
    if (y1 <= pt.y && pt.y <= y2)
      return min((pt.x-x1)*(pt.x-x1), (pt.x-x2)*(pt.x-x2));

    ll dist = dsq(x1, y1, pt);
    dist = min(dist, dsq(x1, y2, pt));
    dist = min(dist, dsq(x2, y1, pt));
    return min(dist, dsq(x2, y2, pt));
  }

  INTERSECTION contained(point const& pt, ll radsq) {
    ll d1 = dsq(x1, y1, pt);
    ll d2 = dsq(x1, y2, pt);
    ll d3 = dsq(x2, y1, pt);
    ll d4 = dsq(x2, y2, pt);
    if (d1 <= radsq &&
        d2 <= radsq &&
        d3 <= radsq &&
        d4 <= radsq)
            return CONTAINED;


    if (x1 <= pt.x && pt.x <= x2) {
      if (y1 <= pt.y && pt.y <= y2) {
        return INTERSECT;
      }
      if (min((pt.y-y1)*(pt.y-y1), (pt.y-y2)*(pt.y-y2)) <= radsq)
        return INTERSECT;
      return DISTINCT;
    }
    if (y1 <= pt.y && pt.y <= y2) {
      if (min((pt.x-x1)*(pt.x-x1), (pt.x-x2)*(pt.x-x2)) <= radsq)
        return INTERSECT;
      else
        return DISTINCT;
    }
    if (min(min(d1, d2), min(d3, d4)) > radsq) return DISTINCT;
    return INTERSECT;
  }

  ll x1, y1;
  ll x2, y2;
  ll cnt;
  vector<point> pts;
  node *left;
  node *right;
};

struct xsort {
  bool operator()(point const& a, point const& b) {
    return a.x < b.x;
  }
};

struct ysort {
  bool operator()(point const& a, point const& b) {
    return a.y < b.y;
  }
};


node *create(point* pts, int len, int dim = 0) {
  node *n = new node(pts, len);
  if (len <= 92) {
    for (int i = 0; i < len; i++)
      n->pts.push_back(pts[i]);
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

inline bool pvalid(point const& pt) {
  return pt.x != INF && pt.y != INF;
}

int func = 0;
point nearest(node *root, point query, ll bsf) {
  func++;
  if (root->pts.size()) {
    point best = *(root->pts.begin());
    ll dst = dsq(best.x, best.y, query);
    for (int i = 1; i < root->pts.size(); i++) {
      ll dst2 = dsq(root->pts[i].x, root->pts[i].y, query);
      if (dst2 < dst) {
        best = root->pts[i];
        dst = dst2;
      }
    }
    if (dst < bsf) return best;
    return point {INF, INF};
  }

  ll ld = root->left ? root->left->distancesq(query) : INF;
  ll rd = root->right ? root->right->distancesq(query) : INF;
  point cnd, cnd2;
  cnd = cnd2 = point {INF, INF};
  ll d, d2; d = d2 = INF;
  bool right;

  if (ld <= rd && ld < bsf) {
    cnd = nearest(root->left, query, bsf);
    right = false;
  }
  else if (rd <= ld && rd < bsf) {
    cnd = nearest(root->right, query, bsf);
    right = true;
  }
  else
    return point {INF, INF};

  if (pvalid(cnd))
    bsf = min(bsf, d = dsq(cnd.x, cnd.y, query));

  if (!right && rd < bsf) {
    cnd2 = nearest(root->right, query, bsf);
  }
  else if (right && ld < bsf) {
    cnd2 = nearest(root->left, query, bsf);
  }

  if (pvalid(cnd2))
    bsf = min(bsf, d2 = dsq(cnd2.x, cnd2.y, query));

  if (min(d, d2) > bsf)
    return point {INF, INF};

  return d2 > d ? cnd : cnd2;
}

ll countcircle(node *root, point center, ll sizesq) {
  func++;

  INTERSECTION status = root->contained(center, sizesq);

  switch (status) {
    case DISTINCT: return 0;
    case CONTAINED: return root->cnt;
  }

  int count = 0;

  if (root->pts.size()) {
    for (int i = 0; i < root->pts.size(); i++) {
      ll dst = dsq(root->pts[i].x, root->pts[i].y, center);
      if (dst <= sizesq) {
        count++;
      }
    }
    return count;
  }

  ll ld = root->left ? root->left->distancesq(center) : INF;
  ll rd = root->right ? root->right->distancesq(center) : INF;

  if (ld <= sizesq) {
    count += countcircle(root->left, center, sizesq);
  }
  if (rd <= sizesq) {
    count += countcircle(root->right, center, sizesq);
  }
  return count;
}


point *naive(point* pts, int len, point query) {
  ll dist = INF;
  point *res = pts;
  for (int i = 0; i < len; i++) {
    ll d = dsq(query.x, query.y, pts[i]);
    if (d < dist) {
      dist = d;
      res = pts + i;
    }
  }
  return res;
}

ll naivecnt(point* pts, int len, point center, ll radsq) {
  ll count = 0;
  for (int i = 0; i < len; i++) {
    ll d = dsq(center.x, center.y, pts[i]);
    if (d <= radsq) {
      count++;
    }
  }
  return count;
}


void test() {
  vector<point> tmp;
  for (int i = 0; i < 1000000; i++) tmp.push_back(point {rand()%1000000, rand()%1000000});
  node *kd = create(tmp.data(), tmp.size());

  int a = 0;
  for (int i = 0; i < 10000; i++) {
    point query = point {rand()%1000000, rand()%1000000};
    func = 0;
    // point res = nearestnearest(kd, query, INF);
    ll radsq = rand()%1000000; radsq *= radsq;
    ll res = countcircle(kd, query, radsq);
    // printf("CALL %d\n", func);

    // ll nai = naivecnt(tmp.data(), tmp.size(), query, radsq);

    // point nai = *naive(tmp.data(), tmp.size(), query);
    a += res;
    // printf("KD %lld\n", res);
    // printf("NV %lld\n", nai);
    // assert(res == nai);
    // printf("KD %lld %lld %f\n", res.x, res.y, sqrt(dsq(res.x, res.y, query)));
    // printf("NV %lld %lld %f\n", nai.x, nai.y, sqrt(dsq(nai.x, nai.y, query)));
    // assert(dsq(res.x, res.y, query) == dsq(nai.x, nai.y, query));
  }
  printf("A%d\n", a);
}

point pts[1000100];
int main(int argc, char const *argv[]) {
  int N, Q;
  scanf("%d%d", &N, &Q);
  for (int i = 0; i < N; i++) {
    scanf("%lld%lld",&pts[i].x, &pts[i].y);
  }
  node *kd = create(pts, N);

  for (int j = 0; j < Q; j++) {
    int x, y, r;
    scanf("%d%d%d", &x, &y, &r);
    point c = point {x, y};
    // ll nai = naivecnt(pts, N, c, r*r);
    ll res = countcircle(kd, c, ((ll)r)*r);
    // assert(nai == res);

    printf("%lld\n", res);
  }

  return 0;
}
