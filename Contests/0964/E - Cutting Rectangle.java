import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.min ; import static java.lang.Math.max ;
import static java.lang.Math.abs ; import static java.lang.Math.log ;
import static java.lang.Math.pow ; import static java.lang.Math.sqrt ;

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
        final int maxn = 200010;
        Data a[] = new Data [maxn];

        public void solve(int testNumber, InputReader in, BufferedWriter out) throws IOException {
            int n = in.nextInt();
            long g = -1;

            HashMap <Long, Long> wh = new HashMap<>(), lh = new HashMap<>();
            Long ct = new Long(0);

            for (int i = 0; i < n; i++) {
                long w, h, c;
                w = in.nextLong();
                h = in.nextLong();
                c = in.nextLong();

                if (wh.containsKey(w)) {
                    wh.replace(w, wh.get(w) + c);
                } else {
                    wh.put(w, c);
                }

                if (lh.containsKey(h)) {
                    lh.replace(h, lh.get(h) + c);
                } else {
                    lh.put(h, c);
                }

                a[i] = new Data (w, h, c);
                if (g == -1)
                    g = c;
                g = gcd(g, c);
                ct += c;
            }

            for(int i = 0; i < n; i++) {
                if (abs (1.0 * wh.get(a[i].w) / ct - 1.0 * a[i].c / lh.get(a[i].h)) > 1e-10) {
                    out.write("0");
                    return;
                }
            }

            int ans = 0;
            for(long i = 1; i * i <= g; i++) {
                if (g % i == 0) {
                    if (i * i != g)
                        ans++;
                    ans++;
                }
            }
            out.write(Integer.toString(ans));
        }

        public long gcd(long a, long b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        public class Data {
            public long w, h, c;
            public Data (long _w, long _h, long _c) {
                w = _w;
                h = _h;
                c = _c;
            }
            public Data () {
                w = 0;
                h = 0;
                c = 0;
            }
        }

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