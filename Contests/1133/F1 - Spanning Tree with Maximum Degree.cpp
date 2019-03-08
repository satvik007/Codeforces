#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;

#define maxn 100010

class UnionFind {
public:
    int n;
    vi p, rank;

    UnionFind (int _n) {
        n = _n + 1;
        p.resize (n);
        rank.assign (n, 1);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int findSet (int i) {
        while (i != p[i]) {
            p[i] = p[p[i]], i = p[i];
        }
        return i;
    }
    bool isSameSet (int i, int j) {
        return findSet (i) == findSet (j);
    }
    void unionSet (int i, int j) {
        i = findSet (i);
        j = findSet (j);
        if (rank[i] < rank[j]) {
            p[i] = j;
        } else {
            p[j] = i;
            if (rank[i] == rank[j]) rank[i]++;
        }
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m;
    cin >> n >> m;

    vi d (n + 1);
    vector <vi> a (n + 1);
    vector <ii> b (m);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
        a[u].push_back (v);
        a[v].push_back (u);
        b[i] = {u, v};
    }

    int max_i = max_element (d.begin() + 1, d.end()) - d.begin();

    UnionFind c (n);

    vector <ii> ans;

    for (int i = 0; i < a[max_i].size(); i++) {
        int u = max_i;
        int v = a[max_i][i];
        if (!c.isSameSet (u, v)) {
            ans.push_back ({u, v});
            c.unionSet (u, v);
        }
    }

    for (int i = 0; i < m; i++) {
        int u = b[i].first;
        int v = b[i].second;
        if (!c.isSameSet (u, v)) {
            ans.push_back ({u, v});
            c.unionSet (u, v);
        }
    }
    
    //cout << ans.size() << "\n";
    for (auto el: ans) cout << el.first << " " << el.second << "\n";

}