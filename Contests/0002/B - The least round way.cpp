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

const int INF = 1 << 30;

#define maxn 100010



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    vector <vi> a(n, vi(n));
    bool zero = false;

    vector <vi> b(n, vi(n));
    vector <vi> c(n, vi(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0)
                zero = true;
            else {
                int l = 0, r = 0;
                while(a[i][j] % 2 == 0) {
                    a[i][j] >>= 1;
                    l++;
                }
                while(a[i][j] % 5 == 0) {
                    a[i][j] /= 5;
                    r++;
                }
                b[i][j] = l;
                c[i][j] = r;
            }
        }
    }

    vector <vi> two(n, vi (n, INF));
    vector <vi> ten(n, vi (n, INF));

    vector <vi> p1(n, vi (n, -1));
    vector <vi> p2(n, vi (n, -1));

    two[0][0] = b[0][0];
    ten[0][0] = c[0][0];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 and j == 0) continue;
            int f1 = INF, s1 = INF, f2 = INF, s2 = INF;
            if(i) f1 = two[i - 1][j], f2 = ten[i - 1][j];
            if(j) s1 = two[i][j - 1], s2 = ten[i][j - 1];
            if(f1 < s1) {
                p1[i][j] = 0;
                two[i][j] = f1;
            } else {
                p1[i][j] = 1;
                two[i][j] = s1;
            }
            if(f2 < s2) {
                p2[i][j] = 0;
                ten[i][j] = f2;
            } else {
                p2[i][j] = 1;
                ten[i][j] = s2;
            }
            two[i][j] += b[i][j];
            ten[i][j] += c[i][j];
        }
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            cout << two[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            cout << ten[i][j] << " ";
//        }
//        cout << "\n";
//    }


    int v = min(two[n - 1][n - 1], ten[n - 1][n - 1]);

    if(v and zero) {
        cout << 1 << "\n";
        int x, y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 0) {
                    x = i, y = j;
                    break;
                }
            }
        }
        for(int i = 0; i < x; i++) {
            cout << 'D';
        }
        for(int i = 0; i < n - 1; i++) {
            cout << 'R';
        }
        for(int i = 0 ; i < n - x - 1; i++) {
            cout << 'D';
        }
        cout << "\n";
    } else {
        cout << v << "\n";
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < n; j++) {
//                cout << p1[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < n; j++) {
//                cout << p2[i][j] << " ";
//            }
//            cout << "\n";
//        }
        int x = n - 1, y = n - 1;
        if(two[n - 1][n - 1] <= ten[n - 1][n - 1]) {
            int tx, ty;
            string ans;
            while(x >= 0 and y >= 0 and p1[x][y] != -1) {
                if(p1[x][y] == 0) {
                    tx = x - 1;
                    ty = y;
                    ans += 'D';
                } else {
                    tx = x;
                    ty = y - 1;
                    ans += 'R';
                }
                x = tx, y = ty;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        } else {
            int tx, ty;
            string ans;
            while(x >= 0 and y >= 0 and p2[x][y] != -1) {
                if(p2[x][y] == 0) {
                    tx = x - 1;
                    ty = y;
                    ans += 'D';
                } else {
                    tx = x;
                    ty = y - 1;
                    ans += 'R';
                }
                x = tx, y = ty;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }

}