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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    map <string, int> map1;

    map1["Anka"] = 0;
    map1["Chapay"] = 1;
    map1["Cleo"] = 2;
    map1["Troll"] = 3;
    map1["Dracul"] = 4;
    map1["Snowy"] = 5;
    map1["Hexadecimal"] = 6;

    int a[10][10];
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) {
        string u, v, w;
        cin >> u >> v >> w;
        a[map1[u]][map1[w]] = 1;
    }

    int x, y, z;
    cin >> x >> y >> z;

    vi c, v;
    vector <vi> ans;
    int min1 = INF;

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 6 - i; j++) {
            int k = 7 - (i + j);
            c.clear();
            c.push_back(i);
            c.push_back(i + j);
            c.push_back(i + j + k);

            v.clear();
            v.push_back(x / i);
            v.push_back(y / j);
            v.push_back(z / k);

            sort(v.begin(), v.end());

            if(v[2] - v[0] < min1) {
                min1 = v[2] - v[0];
                ans.clear();
                ans.push_back(c);
            } else if(v[2] - v[0] == min1) {
                ans.push_back(c);
            }
        }
    }

    vi val(7);
    for(int i = 0; i < 7; i++) {
        val[i] = i;
    }

    int m1 = 0;
    for(auto el: ans) {
        sort(val.begin(), val.end());
        int c1 = 0;
        do {
            c1 = 0;
            for(int i = 0; i < el.size(); i++) {
                for(int j = ((i >= 1) ? el[i - 1] : 0); j < el[i]; j++) {
                    for(int k = ((i >= 1) ? el[i - 1] : 0); k < el[i]; k++) {
                        if(a[val[j]][val[k]]) c1++;
                    }
                }
            }
            m1 = max(m1, c1);
        } while(next_permutation(val.begin(), val.end()));
    }

    cout << min1 << " " << m1 << "\n";



}