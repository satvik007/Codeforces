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

const int INF = 1 << 30;

#define maxn 100010

int n, m;
vector <vi> a;

struct Data{
    int x, y, z;
};

Data b[510][510][2];
int vis[510][510][2];

void bfs() {
    queue <Data> q; q.push({0, n - 1, 0});
    memset(vis, 0, sizeof vis);
    vis[0][n - 1][0] = 1;
    Data c;

    while(!q.empty()) {
        c = q.front(); q.pop();
        if(c.x == n - 1 && c.y == 0 && c.z == 0) {
            break;
        }
        if(c.z == 0) {
            for(auto e: a[c.x]) {
                if(!vis[e][c.y][1]) {
                    vis[e][c.y][1] = 1;
                    b[e][c.y][1] = c;
                    q.push({e, c.y, 1});
                }
            }
        } else {
            for(auto e: a[c.y]) {
                if(!vis[c.x][e][0] and e != c.x) {
                    vis[c.x][e][0] = 1;
                    b[c.x][e][0] = c;
                    q.push({c.x, e, 0});
                }
            }
        }
    }

}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m;

    a.resize(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
    }

    memset(b, -1, sizeof b);
    bfs();

    if(b[n - 1][0][0].x == -1) {
        cout << "-1\n"; return 0;
    }

    vi alex, bob;

    Data c = {n - 1, 0, 0};

    while(c.x != -1) {
        if(c.z == 0) {
            alex.push_back(c.x);
            bob.push_back(c.y);
        }
        c = b[c.x][c.y][c.z];
    }

    reverse(alex.begin(), alex.end());
    reverse(bob.begin(), bob.end());

    cout << alex.size() - 1 << "\n";
    for(auto el: alex) cout << el + 1 << " "; cout << "\n";
    for(auto el: bob) cout << el + 1 << " "; cout << "\n";

}