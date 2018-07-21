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

vector <int> a[205];
int visited[205];
int dist[205];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
    }

    vi arr;

    int e1, e2;

    function <int(int)> bfs = [&](int u) {
        for(int i = 0; i < n; i++) dist[i] = INF;
        dist[u] = 0;
        queue <int> q;
        q.push(u);

        while(!q.empty()) {
            int c = q.front(); q.pop();
            visited[c] = 1;
            for(auto el: a[c]) {
                if(el == e1 && e2 == c || e1 == c && e2 == el) continue;
                if(dist[el] > dist[c] + 1) {
                    dist[el] = dist[c] + 1;
                    q.push(el);
                }
            }
        }

        for(int i = 0; i < n; i++) if(dist[i] == INF) dist[i] = -1;

        return (max_element(dist, dist + n) - dist);
    };

    function <int(int)> diameter = [&](int u) {
        int l1 = bfs(u);
        int l2 = bfs(l1);
        return dist[l2];
    };

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            arr.clear();
            memset(visited, 0, sizeof visited);
            e1 = i, e2 = a[i][j];
            for(int k = 0; k < n; k++) {
                if(!visited[k]) {
                    arr.push_back(diameter(k));
                }
            }
            sort(arr.begin(), arr.end(), greater <int> ());
            //cout << i + 1 << " " << a[i][j] + 1 << " --- ";
            //for(auto el: arr) cout << el << " "; cout << "\n";
            if(arr.size() >= 2) {
                ans = max(ans, (arr[0]) * (arr[1]));
            }
        }
    }

    cout << ans << "\n";

}