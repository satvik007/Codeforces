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
int n, m, r;
ll sq(ll a) {
    return a * a;
}

ll dist(ll a, ll b) {
    return sq(a / m - b / m) + sq(a % m - b % m);
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);


    cin >> n >> m >> r;

    vector <string> a(n);

    set <char> set1;
    bool flag = false;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] != 'S')
                set1.insert(a[i][j]);
            else
                flag = true;
        }
    }

    int k;
    cin >> k;

    string s;
    cin >> s;

    for(int i = 0; i < k; i++) {
        if(!set1.count((char)tolower(s[i]))) {
            cout << -1 << "\n";
            return 0;
        }
        if(s[i] <= 'Z' and !flag) {
            cout << -1 << "\n";
            return 0;
        }
    }

    vi pos;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'S') {
                pos.push_back(i * m + j);
            }
        }
    }

    map <char, int> dis;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != 'S') {
                int cur = INF;
                for(int p = 0; p < pos.size(); p++) {
                    cur = min(cur, (int)dist(i * m + j, pos[p]));
                }
                if(!dis.count(a[i][j])) {
                    dis[a[i][j]] = cur;
                } else {
                    dis[a[i][j]] = min(dis[a[i][j]], cur);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] >= 'a') continue;
        char c = (char) tolower(s[i]);
        if(dis[c] > sq(r)) ans++;
    }

    cout << ans << "\n";

}