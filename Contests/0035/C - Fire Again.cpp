#define BZ
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

const int INF = 1e9;

#define maxn 100010



int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m, que;
    cin >> n >> m >> que;

    vector <vi> dist(n, vi(m, INF));

    queue <ii> q;
    ii ans;

    for(int i = 0; i < que; i++) {
        int u, v;
        cin >> u >> v;
        dist[u - 1][v - 1] = 0;
        q.push({u - 1, v - 1});
        ans = {u, v};
    }


    function <bool(int, int)> inside = [&](int x, int y) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    };

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};


    while(!q.empty()) {
        ii cur = q.front(); q.pop();
        ans = {cur.first + 1, cur.second + 1};
        for(int k = 0; k < 4; k++) {
            int tx = cur.first + dr[k];
            int ty = cur.second + dc[k];
            if(inside(tx, ty) && dist[tx][ty] > dist[cur.first][cur.second] + 1) {
                q.push({tx, ty});
                dist[tx][ty] = dist[cur.first][cur.second] + 1;
            }
        }
    }

    cout << ans.first << " " << ans.second << "\n";

}