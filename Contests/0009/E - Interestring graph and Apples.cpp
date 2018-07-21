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
int d[60];
vi a[60];
int visited[60];

class UnionFind {
public:
    vi p, rank;
    int cnt;
    UnionFind(int n) {
        rank.assign(n, 1);
        p.resize(n);
        cnt = n;
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int i) {
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if(i != j) {
            cnt--;
            if(rank[i] < rank[j]) p[i] = j;
            else {
                p[j] = i;
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m;

    int u, v;
    memset(d, 0, sizeof d);
    bool ok = true;
    UnionFind cur(n);

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        d[u]++;
        d[v]++;
        a[u].push_back(v);
        a[v].push_back(u);
        if(d[u] > 2 || d[v] > 2) ok = false;
        cur.unionSet(u, v);
    }

    bool a1 = true;
    for(int i = 0; i < n; i++) {
        if(d[i] != 2) a1 = false;
    }
    bool a2 = (cur.cnt == 1);

    if(a1 && a2) {
        cout << "YES\n0\n"; return 0;
    }

    bool b1 = m < n;
    bool b2 = true;
    bool b3 = ok;

    function <void(int, int)> dfs = [&](int f, int s) {
        visited[f] = 1;
        for(auto el: a[f]) {
            if(el == s) continue;
            if(visited[el]) b2 = false;
            else dfs(el, f);
        }
    };

    memset(visited, 0, sizeof visited);

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            dfs(i, -1);
    }

    if(!(b1 && b2 && b3)) {
        cout << "NO\n"; return 0;
    }

    cout << "YES\n";
    cout << n - m << "\n";

    if(n == 1) {
        int edge = n - m;
        for(int i = 0; i < edge; i++) {
            cout << "1 1\n";
        }
    } else {
        for(int i = 0; i < n; i++) {
            repeat:
            if(d[i] < 2) {
                for (int j = i + 1; j < n; j++) {
                    if (d[j] < 2 && (!cur.isSameSet(i, j) || cur.cnt == 1)) {
                        cur.unionSet(i, j);
                        cout << i + 1 << " " << j + 1 << "\n";
                        d[j]++;
                        break;
                    }
                }
                d[i]++;
                goto repeat;
            }
        }
    }


}