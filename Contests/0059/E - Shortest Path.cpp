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

struct Data {
    int x, y;
    Data () : x(0), y(0) {}
    Data (int _x, int _y) : x(_x), y(_y) {}
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m, k;
    cin >> n >> m >> k;

    vector <vi> a(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    // Data structure to keep track of the not allowed state for previous states u and v in order.
    map <ii, set <int>> b;

    for(int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        b[{u, v}].insert(w);
    }


    queue <Data> q;
    q.push({0, 1});
    vector <vi> visited(n + 1, vi (n + 1));
    vector <vi> dist(n + 1, vi (n + 1, INF));
    vector <vi> path(n + 1, vi (n + 1, -1));
    visited[0][1] = 1;
    dist[0][1] = 0;

    int ans = -1;

    int f = -1, s = - 1;

    // simple bfs search.
    while(!q.empty()) {
        Data t = q.front(); q.pop();
        if(t.y == n) {
            f = t.x;
            break;
        }
        // checking for previously visited and also not allowed because of order problem cases.
        for(auto v: a[t.y]) {
            if(!b[{t.x, t.y}].count(v) && !visited[t.y][v]) {
                visited[t.y][v] = 1;
                dist[t.y][v] = dist[t.x][t.y] + 1;
                path[t.y][v] = t.x;
                q.push({t.y, v});
            }
        }
    }

    s = n;

    if(f == -1) {
        cout << -1 << "\n";
        return 0;
    }

    cout << dist[f][s] << "\n";
    vi road;
    while(f != -1 && s != -1 && path[f][s] != -1) {
        int t = path[f][s];
        s = f;
        f = t;
        road.push_back(s);
    }

    reverse(road.begin(), road.end());

    for(auto el: road) {
        cout << el << " ";
    }

    cout << n << "\n";

}