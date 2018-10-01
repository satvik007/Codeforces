// lose small or win big.
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
    int w, h, id;
    bool operator < (Data x) {
        return w != x.w ? w < x.w : h != x.h ? h < x.h : id < x.id;
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, w, h;
    cin >> n >> w >> h;

    vector <Data> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].h;
        a[i].id = i;
    }

    sort(a.begin(), a.end());
//    vector <vi> b(n);
//
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            if(i == j) continue;
//            if(a[i].w <= w or a[i].h <= h) continue;
//            if(a[i].w < a[j].w and a[i].h < a[j].h) {
//                b[i].push_back(j);
//            }
//        }
//    }

    vi s;
    for(int i = 0; i < n; i++) {
        if(a[i].w > w and a[i].h > h) {
            s.push_back(i);
        }
    }

    if(s.empty()) {
        cout << "0";
        return 0;
    }

    vi nex(n, -1);
    vi val(n, -1);

    function <int(int)> dfs = [&](int u) {
        if(val[u] != -1) {
            return val[u];
        }
        int m = 0, id = -1;
        for(int i = 0; i < n; i++) {
            if (i == u or a[i].w <= a[u].w or a[i].h <= a[u].h) continue;
            int c = dfs(i);
            if (c > m) {
                m = c;
                id = i;
            }
        }
        nex[u] = id;
        return val[u] = m + 1;
    };

    int m = 0;
    int id = -1;

    for(int i = 0; i < s.size(); i++) {
        int c = dfs(s[i]);
        if(c > m) {
            m = c;
            id = s[i];
        }
    }

    vi ans;
    ans.push_back(id);
    while(nex[id] != -1) {
        ans.push_back(nex[id]);
        id = nex[id];
    }

    cout << ans.size() << "\n";
    for(auto el: ans) {
        cout << a[el].id + 1 << " ";
    } cout << "\n";


}