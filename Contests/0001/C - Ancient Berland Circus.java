import java.io.*;
import java.util.*;
import java.math.*;
import java.util.function.DoublePredicate;
import java.util.function.DoubleToIntFunction;

import static java.lang.Math.*;

/**
 * Actual solution is at the top
 * This was not generated using chelper.
 * @author Satvik Choudhary (satvik007)
 */

public class Main {
    public static void main(String[] args) throws IOException{
        // Use for stdio
        InputStream inputStream = System.in;
        OutputStreamWriter outputStream = new OutputStreamWriter(System.out);
        InputReader in = new InputReader(inputStream);
        BufferedWriter out = new BufferedWriter(outputStream);
        /*/
        //*
        // Use for fileio
        FileInputStream inputStream = new FileInputStream (new File("in.txt"));
        InputReader in = new InputReader(inputStream);
        FileWriter fileWriter = new FileWriter("out.txt");
        BufferedWriter out = new BufferedWriter(fileWriter);
        //*/
        satvik solver = new satvik();
        solver.solve(1, in, out);
        out.close();
    }

    static class satvik {
        final int inf = (int) 1e9;
        final int maxn = 100010;

        public void solve(int testNumber, InputReader in, BufferedWriter out) throws IOException {
            point a = new point();
            point b = new point();
            point c = new point();

            a.x = in.nextDouble();
            a.y = in.nextDouble();
            b.x = in.nextDouble();
            b.y = in.nextDouble();
            c.x = in.nextDouble();
            c.y = in.nextDouble();

            point ctr = new point ();
            double r = circumCircle(a, b, c, ctr);

            int n;

            for (n = 3; n <= 100; n++) {
                double theta = 2 * Math.PI / n;
                double t1 = angle(a, ctr, b);
                double t2 = angle(b, ctr, c);
                t1 /= theta;
                t2 /= theta;

                if(abs(t1 - round(t1)) < 1e-4 && abs(t2 - round(t2)) < 1e-4) {
                    break;
                }
            }

            double theta = 2 * Math.PI / n;
            double ans = n * r * r / 2 * sin (theta);

            out.write(Double.toString(ans));


        }

        final double INF = 1e9;
        final double EPS = 1e-9;
        // we will use constant Math.PI in Java

        double DEG_to_RAD(double d) { return d * Math.PI / 180.0; }

        double RAD_to_DEG(double r) { return r * 180.0 / Math.PI; }

        //struct point_i { int x, y; };        // basic raw form, minimalist mode
        class point_i { int x, y;         // whenever possible, work with point_i
            point_i() { x = y = 0; }                         // default constructor
            point_i(int _x, int _y) { x = _x; y = _y; } };          // user-defined

        class point implements Comparable<point>{
            double x, y;                   // only used if more precision is needed
            point() { x = y = 0.0; }                         // default constructor
            point(double _x, double _y) { x = _x; y = _y; }         // user-defined
            // use EPS (1e-9) when testing equality of two floating points
            public int compareTo(point other) {      // override less than operator
                if (Math.abs(x - other.x) > EPS)                // useful for sorting
                    return (int)Math.ceil(x - other.x);       // first: by x-coordinate
                else if (Math.abs(y - other.y) > EPS)
                    return (int)Math.ceil(y - other.y);      // second: by y-coordinate
                else
                    return 0; } };                                    // they are equal

        double dist(point p1, point p2) {                   // Euclidean distance
            // Math.hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
            return Math.hypot(p1.x - p2.x, p1.y - p2.y); }         // return double

        // rotate p by theta degrees CCW w.r.t origin (0, 0)
        point rotate(point p, double theta) {
            double rad = DEG_to_RAD(theta);       // multiply theta with PI / 180.0
            return new point(p.x * Math.cos(rad) - p.y * Math.sin(rad),
                    p.x * Math.sin(rad) + p.y * Math.cos(rad)); }

        class line { double a, b, c; };              // a way to represent a line

        void pointsToLine(point p1, point p2, line l) {
            if (Math.abs(p1.x - p2.x) < EPS) {             // vertical line is fine
                l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;
            } else {
                l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
                l.b = 1.0;                 // IMPORTANT: we fix the value of b to 1.0
                l.c = -(double)(l.a * p1.x) - p1.y;
            } }

        class line2 { double m, c; };          // another way to represent a line

        int pointsToLine2(point p1, point p2, line2 l) {
            if (Math.abs(p1.x - p2.x) < EPS) {        // special case: vertical line
                l.m = INF;                       // l contains m = INF and c = x_value
                l.c = p1.x;                     // to denote vertical line x = x_value
                return 0;      // we need this return variable to differentiate result
            }
            else {
                l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
                l.c = p1.y - l.m * p1.x;
                return 1;        // l contains m and c of the line equation y = mx + c
            } }

        boolean areParallel(line l1, line l2) {       // check coefficients a & b
            return (Math.abs(l1.a-l2.a) < EPS) && (Math.abs(l1.b-l2.b) < EPS); }

        boolean areSame(line l1, line l2) {           // also check coefficient c
            return areParallel(l1 ,l2) && (Math.abs(l1.c - l2.c) < EPS); }

        boolean areIntersect(line l1, line l2, point p) {
            if (areParallel(l1, l2)) return false;               // no intersection
            // solve system of 2 linear algebraic equations with 2 unknowns
            p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
            // special case: test for vertical line to avoid division by zero
            if (Math.abs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
            else                      p.y = -(l2.a * p.x + l2.c);
            return true; }

        class vec { double x, y;     // name: `vec' is different from Java Vector
            vec(double _x, double _y) { x = _x; y = _y; } };

        vec toVec(point a, point b) {               // convert 2 points to vector
            return new vec(b.x - a.x, b.y - a.y); }

        vec scale(vec v, double s) {           // nonnegative s = [<1 .. 1 .. >1]
            return new vec(v.x * s, v.y * s); }              // shorter.same.longer

        point translate(point p, vec v) {           // translate p according to v
            return new point(p.x + v.x , p.y + v.y); }

        void pointSlopeToLine(point p, double m, line l) {
            l.a = -m;                                                  // always -m
            l.b = 1;                                                    // always 1
            l.c = -((l.a * p.x) + (l.b * p.y)); }                   // compute this

        void closestPoint(line l, point p, point ans) {
            line perpendicular = new line(); // perpendicular to l and pass through p
            if (Math.abs(l.b) < EPS) {             // special case 1: vertical line
                ans.x = -(l.c);   ans.y = p.y;      return; }

            if (Math.abs(l.a) < EPS) {           // special case 2: horizontal line
                ans.x = p.x;      ans.y = -(l.c);   return; }

            pointSlopeToLine(p, 1 / l.a, perpendicular);             // normal line
            // intersect line l with this perpendicular line
            // the intersection point is the closest point
            areIntersect(l, perpendicular, ans); }

        void reflectionPoint(line l, point p, point ans) {
            point b = new point();
            closestPoint(l, p, b);                         // similar to distToLine
            vec v = toVec(p, b);                                 // create a vector
            ans = translate(translate(p, v), v); }             // translate p twice

        double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

        double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

        double distToLine(point p, point a, point b, point c) {
            // formula: c = a + u * ab
            vec ap = toVec(a, p), ab = toVec(a, b);
            double u = dot(ap, ab) / norm_sq(ab);
            c = translate(a, scale(ab, u));                     // translate a to c
            return dist(p, c); }              // Euclidean distance between p and c

        double distToLineSegment(point p, point a, point b, point c) {
            vec ap = toVec(a, p), ab = toVec(a, b);
            double u = dot(ap, ab) / norm_sq(ab);
            if (u < 0.0) { c = new point(a.x, a.y);                  // closer to a
                return dist(p, a); }            // Euclidean distance between p and a
            if (u > 1.0) { c = new point(b.x, b.y);                  // closer to b
                return dist(p, b); }            // Euclidean distance between p and b
            return distToLine(p, a, b, c); }             // run distToLine as above

        double angle(point a, point o, point b) {     // returns angle aob in rad
            vec oa = toVec(o, a), ob = toVec(o, b);
            return Math.acos(dot(oa, ob) / Math.sqrt(norm_sq(oa) * norm_sq(ob))); }

        double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

        boolean ccw(point p, point q, point r) {
            return cross(toVec(p, q), toVec(p, r)) > 0; }

        boolean collinear(point p, point q, point r) {
            return Math.abs(cross(toVec(p, q), toVec(p, r))) < EPS; }

        double circumCircle(point p1, point p2, point p3, point ctr) {
            double a = p2.x - p1.x, b = p2.y - p1.y;
            double c = p3.x - p1.x, d = p3.y - p1.y;
            double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
            double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
            double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
            if (Math.abs(g) < EPS) return 0;

            ctr.x = (d*e - b*f) / g;
            ctr.y = (a*f - c*e) / g;
            return dist(p1, ctr); }

    }


    static class Util {

        static class pair implements Comparable<pair>{
            int x ; int y ; int z ;
            pair(int _x,int _y,int _z){ x=_x ; y=_y ; z=_z ;}
            public int compareTo(pair p){
                return (this.x<p.x ? -1 : (this.x>p.x ? 1 : (this.y<p.y ? -1 : (this.y>p.y ? 1 : 0)))) ;
            }
        }

        static public int min(int a[], int left, int right) {
            int res = (1 << 30);
            for(int i = left; i < right; i++) {
                res = Math.min(res, a[i]);
            }
            return res;
        }

        static public int min(int a[]) {
            return min(a, 0, a.length);
        }

        static public boolean next_permutation(int[] p) {
            for (int a = p.length - 2; a >= 0; --a)
                if (p[a] < p[a + 1])
                    for (int b = p.length - 1;; --b)
                        if (p[b] > p[a]) {
                            int t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                            for (++a, b = p.length - 1; a < b; ++a, --b) {
                                t = p[a];
                                p[a] = p[b];
                                p[b] = t;
                            }
                            return true;
                        }
            return false;
        }

        static public int max(int a[], int left, int right) {
            int res = -(1 << 30);
            for(int i = left; i < right; i++) {
                res = Math.max(res, a[i]);
            }
            return res;
        }

        static public int max(int a[]) {
            return max(a, 0, a.length);
        }

        static public int upper_bound(int[] a, int left, int right, int value) {
            int low = left;
            int high = right;
            while (low < high) {
                int mid = (low + high) / 2;
                if (a[mid] <= value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (low == right) {
                return -1;
            }
            return low;
        }

        static public int lower_bound(int[] a, int left, int right, int value) {
            int low = left;
            int high = right;
            while (low < high) {
                int mid = (low + high) / 2;
                if (a[mid] < value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (low == right) {
                return -1;
            }
            return low;
        }

        static public int upper_bound_rev(int[] a, int left, int right, int value) {
            while (left < right) {
                int mid = (left + right) >> 1;
                if (a[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left < 0) {
                left *= -1;
            }
            return --left;
        }

        static public int lower_bound_rev(int[] a, int left, int right, int value) {
            while (left < right) {
                int mid = (left + right) >> 1;
                if (a[mid] <= value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left < 0) {
                left *= -1;
            }
            return --left;
        }
    }

    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1) {
                return -1;
                //throw new InputMismatchException();

            }

            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                    //throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.parseDouble(readString());
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public int[][] next2dArray(int n, int m) {
            int a[][] = new int[n][m];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    a[i][j] = nextInt();
                }
            }
            return a;
        }

        public String readString() {
            int c = snext();
            if(c == -1) {
                return null;
            }
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = snext();
            if(c == -1) {
                return null;
            }
            while (isSpaceChar(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}