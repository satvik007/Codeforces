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

int n, T;
string a[20], b[20];
int d[20][20];
int sx, sy;
int dp[70][12][12][12][12];

int f, mf, s, t, res[220][220], total;
vi p;

void augment(int v, int minEdge){
    if(v == s) f = minEdge;
    else if (p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}
void EdmondKarp(){
    mf = 0;
    s = 0, t = 1;
    int mv = 2 + 2 * n * n;
    while(true){
        f = 0; queue <int> q; q.push(s);
        bitset<220> visited; visited.set(s);
        p.assign(220, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = 0; v <= mv; v++){
                if(res[u][v] > 0 && !visited.test(v)){
                    visited.set(v); q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, INF);
        if(!f) break;
        mf += f;
    }
}

void bfs() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
    }
    d[sx][sy] = 0;
    queue <ii> q;
    q.push({sx, sy});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = t.first + dr[i];
            int ty = t.second + dc[i];
            if(tx >= 0 and ty >= 0 and tx < n and ty < n and a[tx][ty] <= '9') {
                if(d[tx][ty] > d[t.first][t.second] + 1) {
                    d[tx][ty] = d[t.first][t.second] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] > '9') d[i][j] = -1;
        }
    }
}

void fill_dp() {

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[0][i][j][i][j] = 1;
        }
    }

    for(int ti = 0; ti < T; ti++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int x = 0; x < n; x++) {
                    for(int y = 0; y < n; y++) {
                        if(!dp[ti][i][j][x][y]) continue;

                        for(int k = 0; k < 4; k++) {
                            int tx = x + dr[k];
                            int ty = y + dc[k];
                            if(tx >= 0 and ty >= 0 and tx < n and ty < n and d[x][y] >= ti + 1 and d[tx][ty] >= ti + 1) {
                                dp[ti + 1][i][j][tx][ty] = 1;
                            }
                        }

                    }
                }
            }
        }
    }

}

void createGraph() {
    memset(res, 0, sizeof res);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int x = 0; x < n; x++) {
                for(int y = 0; y < n; y++) {
                    bool f = false;
                    for(int ti = 0; ti <= T; ti++) {
                        if(dp[ti][i][j][x][y]) {
                            res[2 + i * n + j][2 + n * n + x * n + y] = INF;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] <= '9') {
                res[0][2 + i * n + j] = a[i][j] - '0';
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(b[i][j] <= '9') {
                res[2 + n * n + i * n + j][1] = b[i][j] - '0';
            }
        }
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> T;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 'Z') {
                sx = i, sy = j;
            }
        }
    }

    bfs();
    fill_dp();
    createGraph();
    EdmondKarp();

    int final[20][20] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int x = 0; x < n; x++) {
                for(int y = 0; y < n; y++) {
                    if(res[2 + n * n + x * n + y][2 + i * n + j]) {
                        final[i][j] += res[2 + n * n + x * n + y][2 + i * n + j];
                    }
                }
            }
        }
    }
    cout << mf << "\n";
}