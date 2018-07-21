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

int n;
vi a[1010];

class UnionFind {
public:
    vi p, rank;
    UnionFind() {
        p.resize(n);
        rank.assign(n, 1);
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

    cin >> n;

    UnionFind cur;

    vector <ii> ans1, ans2;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
        if(cur.isSameSet(u - 1, v - 1)) {
            ans1.push_back({u - 1, v - 1});
        } else {
            cur.unionSet(u - 1, v - 1);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(!cur.isSameSet(i, j)) {
                cur.unionSet(i, j);
                ans2.push_back({i, j});
            }
        }
    }

    //cout << ans1.size() << " " << ans2.size() << "\n";
    assert(ans1.size() == ans2.size());

    cout << ans1.size() << "\n";
    for(int i = 0; i < ans1.size(); i++) {
        cout << ans1[i].first + 1 << " " << ans1[i].second + 1 << " "  << ans2[i].first + 1 << " " << ans2[i].second + 1 << "\n";
    }




}