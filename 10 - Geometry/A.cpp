#include <bits/stdc++.h>
#define EPS 0.000000001

using namespace std;

const double PI = 3.141592653589793238462643;

struct point {
  int x, y;
  point() { x = y = 0; }
  point(int _x, int _y) : x(_x), y(_y) {}
};

struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) { 
    l.a = 1.0; l.b = 0.0; l.c = -p1.x; 
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c =  -(double)(l.a * p1.x) - p1.y;
  }
}

double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

double area(double radius) { return PI * (radius * radius); }

int main() {

  int N, cx, cy;

  vector<point> polygon;
  vector<line> lines;

  scanf("%d %d %d", &N, &cx, &cy);

  point center = point(cx, cy);

  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);

    point tmp = point(x, y);
    polygon.push_back(tmp);
  }

  double farthest = dist(center, polygon[0]);
  double closest = dist(center, polygon[0]);

  for (int i = 1; i < polygon.size(); i++) {

    double tmpDist = dist(center, polygon[i]);

    if (tmpDist > farthest) {
      farthest = tmpDist;
    }
    if (tmpDist < closest) {
      closest = tmpDist;
    }
  }

  double largeArea = area(farthest);
  double smallArea = area(closest);

  printf("%.18f\n", largeArea - smallArea);

  return 0;
}