// Warten auf das Licht, das nie kommt.
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

vector <string> a(3);//, b(3);
vector <vector<ll>> h(3);
#define mod 1000000009
int total;

ll p[100010];
int c[3] = {0, 1, 2};

int common(int u, int v) {
    bool flag = false;
    if(a[u].size() >= a[v].size()) {
        for(int i = 0; i < a[u].size() - a[v].size() + 1; i++) {
            if((h[u][a[v].size() + i] - h[u][i] + mod) % mod == (h[v][a[v].size()] * p[i]) % mod) flag = true;
        }
    } else {
        for(int i = 0; i < a[v].size() - a[u].size() + 1; i++) {
            if((h[v][a[u].size() + i] - h[v][i] + mod) % mod == (h[u][a[u].size()] * p[i]) % mod) flag = true;
        }
    }
    const int m = min(a[u].size(), a[v].size());

    if(flag) return m;

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if((h[v][i] * p[a[u].size() - i]) % mod == (h[u][a[u].size()] - h[u][a[u].size() - i] + mod) % mod) ans = i;
    }
    return ans;
}

int solve() {
    int c1 = common(c[0], c[1]);
    int c2 = common(c[1], c[2]);
    return total - c1 - c2;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    p[0] = 1;
    for(int i = 1; i <= 100002; i++) {
        p[i] = (p[i - 1] * 31) % mod;
    }

    total = 0;
    for(int i = 0; i < 3; i++) cin >> a[i], total += a[i].size();

    for(int i = 0; i < 3; i++) {
        ll cnt = 0;
        //ll base = 1;
        h[i].resize(a[i].size() + 1);
        h[i][0] = 0;
        for(int j = 1; j <= a[i].size(); j++) {
            cnt = (cnt + p[j] * (a[i][j - 1] - 'a' + 1)) % mod;
            h[i][j] = cnt;
        }
    }

    int ans = INF;
    do {
//        for(int i = 0; i < 3; i++) {
//            b[i] = a[c[i]];
//        }
        ans = min(ans, solve());
    } while(next_permutation(c, c + 3));

    cout << ans << "\n";
}