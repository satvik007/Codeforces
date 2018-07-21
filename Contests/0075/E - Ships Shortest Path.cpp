/*
When my time comes
Forget the wrong that I've done
Help me leave behind some reasons to be missed
And don't resent me
And when you're feeling empty
Keep me in your memory
Leave out all the rest
Leave out all the rest
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

typedef double T;


#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

// struct point_i { int x, y; };    // basic raw form, minimalist mode
struct point_i { int x, y;     // whenever possible, work with point_i
    point_i() { x = y = 0; }                      // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {} };         // user-defined
struct point { double x, y;   // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS)                 // useful for sorting
            return x < other.x;          // first criteria , by x-coordinate
        return y < other.y; }          // second criteria, by y-coordinate
    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };
istream& operator >> (istream& in, point &a) {
    in >> a.x >> a.y;
    return in;
}
ostream& operator << (ostream& out, point &a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}
double dist(point p1, point p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double
// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad)); }
struct line { double a, b, c; };          // a way to represent a line
// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } }
// not needed since we will use the more robust form: ax + by + c = 0 (see above)
struct line2 { double m, c; };      // another way to represent a line
int pointsToLine2(point p1, point p2, line2 &l) {
    if (abs(p1.x - p2.x) < EPS) {          // special case: vertical line
        l.m = INF;                    // l contains m = INF and c = x_value
        l.c = p1.x;                  // to denote vertical line x = x_value
        return 0;   // we need this return variable to differentiate result
    }
    else {
        l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
        l.c = p1.y - l.m * p1.x;
        return 1;     // l contains m and c of the line equation y = mx + c
    } }
bool areParallel(line l1, line l2) {       // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }
bool areSame(line l1, line l2) {           // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }
// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true; }
struct vec { double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s); }               // shorter.same.longer
point translate(point p, vec v) {        // translate p according to v
    return point(p.x + v.x , p.y + v.y); }
// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line &l) {
    l.a = -m;                                               // always -m
    l.b = 1;                                                 // always 1
    l.c = -((l.a * p.x) + (l.b * p.y)); }                // compute this
void closestPoint(line l, point p, point &ans) {
    line perpendicular;         // perpendicular to l and pass through p
    if (fabs(l.b) < EPS) {              // special case 1: vertical line
        ans.x = -(l.c);   ans.y = p.y;      return; }

    if (fabs(l.a) < EPS) {            // special case 2: horizontal line
        ans.x = p.x;      ans.y = -(l.c);   return; }

    pointSlopeToLine(p, 1 / l.a, perpendicular);          // normal line
    // intersect line l with this perpendicular line
    // the intersection point is the closest point
    areIntersect(l, perpendicular, ans); }
// returns the reflection of point on a line
void reflectionPoint(line l, point p, point &ans) {
    point b;
    closestPoint(l, p, b);                     // similar to distToLine
    vec v = toVec(p, b);                             // create a vector
    ans = translate(translate(p, v), v); }         // translate p twice
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));                  // translate a to c
    return dist(p, c); }           // Euclidean distance between p and c
// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y);                   // closer to a
        return dist(p, a); }         // Euclidean distance between p and a
    if (u > 1.0) { c = point(b.x, b.y);                   // closer to b
        return dist(p, b); }         // Euclidean distance between p and b
    return distToLine(p, a, b, c); }          // run distToLine as above
double angle(point a, point o, point b) {  // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
//// another variant
//int area2(point p, point q, point r) { // returns 'twice' the area of this triangle A-B-c
//  return p.x * q.y - p.y * q.x +
//         q.x * r.y - q.y * r.x +
//   }
// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

double d[60][60];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(8);

    point a, b;

    cin >> a >> b;

    int n;
    cin >> n;

    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }

    vector <point> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    line l;
    pointsToLine(a, b, l);

    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line c;

        pointsToLine(s[i], s[j], c);
        point p;

        if(areIntersect(l, c, p)) {
            double a1 = abs(angle(s[i], p, s[j]));
            double a2 = abs(angle(a, p, b));
            if(abs(a1 - PI) < EPS and abs(a2 - PI) < EPS) {
                s.push_back(p);
                d[s.size() - 1 + 2][i + 2] = d[i + 2][s.size() - 1 + 2] = dist(s[i], p);
                d[s.size() - 1 + 2][j + 2] = d[j + 2][s.size() - 1 + 2] = dist(s[j], p);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        point c;
        if(distToLine(s[i], a, b, c) < EPS) {
            s.push_back(s[i]);
            d[s.size() - 1 + 2][i + 2] = d[i + 2][s.size() - 1 + 2] = 0;
        }
    }

    //assert(s.size() == n || s.size() == n + 2);
    
    for(int i = 0; i < n; i++) {
        d[i + 2][2 + (i + 1) % n] = d[2 + (i + 1) % n][i + 2] = dist(s[i], s[(i + 1) % n]);
    }

    if(s.size() > n + 1) {
        if(dist(a, s[n]) < dist(a, s[n + 1])) {
            d[0][n + 2] = d[n + 2][0] = dist(a, s[n]);
            d[1][n + 3] = d[n + 3][1] = dist(b, s[n + 1]);
        } else {
            d[0][n + 3] = d[n + 3][0] = dist(a, s[n + 1]);
            d[1][n + 2] = d[n + 2][1] = dist(b, s[n]);
        }
        d[n + 2][n + 3] = d[n + 3][n + 2] = dist(s[n], s[n + 1]) * 2;

        n = s.size() + 2;

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        cout << d[0][1] << "\n";
    } else {
        cout << dist(a, b) << "\n";
    }

}