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

int n, m;
ii a[110];
int visited[110];
int col[110];
int b[110][110];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(u < v)
            a[i] = {u, v};
        else
            a[i] = {v, u};

    }

    memset(b, 0, sizeof b);

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == j) continue;
            if(a[i].first >= a[j].second || a[j].first >= a[i].second) continue;
            if(a[i].first < a[j].first && a[i].second < a[j].second || a[j].first < a[i].first && a[j].second < a[i].second) {
                b[i][j] = 1;
            }
        }
    }

//    for(int i = 1; i <= m; i++) {
//        for(int j = 1; j <= m; j++) {
//            cout << b[i][j] << " ";
//        }
//        cout << "\n";
//    }

    memset(visited, 0, sizeof visited);
    memset(col, -1, sizeof col);
    bool flag = true;

    function <void(int, int)> dfs = [&](int u, int cur) {
        if(col[u] == cur) return;
        if(col[u] != cur && col[u] != -1) {
            flag = false;
            return;
        }
        col[u] = cur;
        for(int i = 1; i <= m; i++) {
            if(b[u][i])
                dfs(i, !cur);
        }
    };

    for(int i = 1; i <= m; i++) {
        if(col[i] == -1) {
            dfs(i, 0);
        }
    }

//    for(int i = 1; i <= m; i++) {
//        if(col[i]) cout << "o";
//        else cout << "i";
//    }
//    cout << "\n";


    if(flag) {
        for(int i = 1; i <= m; i++) {
            if(col[i]) cout << "o";
            else cout << "i";
        }
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }



}