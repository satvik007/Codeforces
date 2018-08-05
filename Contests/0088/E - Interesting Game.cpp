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

const int INF = (int)1e9;

#define maxn 100010

int g[maxn], gx[maxn];

int mex(vi &v) {
    if(v.size() == 0) return 0;
    sort(v.begin(), v.end());
    if(v[0]) return 0;
    int i;
    for(i = 1; i < v.size(); ++i) {
        if(v[i] - v[i - 1] > 1)
            return v[i - 1] + 1;
    }
    return v[i - 1] + 1;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    g[0] = g[1] = g[2] = 0;
    int n;
    cin >> n;

    int r = -1;

    for(int i = 3; i <= n; i++) {
        vi v;
        for(int k = 2; k * (k - 1) / 2 <= i; k++) {
            int a = (i - k * (k - 1) / 2) / k;
            if(a >= 1 and k * a + (k * (k - 1) / 2) == i) {
                int b = a + k - 1;
                v.push_back(gx[b] ^ gx[a - 1]);
            }
        }
        g[i] = mex(v);
        gx[i] = gx[i - 1] ^ g[i];
    }

    if(gx[n]) {
        for(int k = 2; k * (k - 1) / 2 <= n; k++) {
            int a = (n - k * (k - 1) / 2) / k;
            if(a >= 1 and k * a + k * (k - 1) / 2 == n) {
                int b = a + k - 1;
                if((gx[b] ^ gx[a - 1]) == 0) {
                    r = k;
                    break;
                }
                if(r > -1) {
                    break;
                }
            }
        }
    }

    cout << r << "\n";
}