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

struct Data {
    int v;
    vector <ii> arr;
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int k, n, m, q;
    cin >> k >> n >> m >> q;

    map <string, int> map1;
    vector <string> names;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        string u;
        cin >> u;
        map1[u] = cnt++;
        names.push_back(u);
    }

    vector <Data> b(m);
    cin.ignore();
    for(int i = 0; i < m; i++) {
        string s;
        getline(cin, s, ':');
        map1[s] = cnt++;
        names.push_back(s);
        getline(cin, s);
        stringstream sin(s);
        int u;
        b[i].v = map1[s];
        while(sin >> s >> u) {
            char null;
            sin >> null;
            b[i].arr.push_back({map1[s], u});
        }
    }

    vector <vi> al(k + 1, vi (n + m));

    for(int i = 0; i < q; i++) {
        int u; string s;
        cin >> u >> s;
        al[u][map1[s]]++;
        for(int j = 0; j < m; j++) {
            bool flag = true;
            for(int p = 0; p < b[j].arr.size(); p++) {
                if(al[u][b[j].arr[p].first] < b[j].arr[p].second) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(int p = 0; p < b[j].arr.size(); p++) {
                    al[u][b[j].arr[p].first] -= b[j].arr[p].second;
                }
                al[u][n + j]++;
                break;
            }
        }
    }

    vector <pair<string, int>> ans;
    for(int i = 1; i <= k; i++) {
        ans.clear();
        for(int j = 0; j < n + m; j++) {
            if(al[i][j]) {
                ans.push_back({names[j], al[i][j]});
            }
        }
        sort(ans.begin(), ans.end());

        cout << ans.size() << "\n";
        for(auto el: ans) {
            cout << el.first << " " << el.second << "\n";
        }

    }



}