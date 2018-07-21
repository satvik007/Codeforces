#define BZ
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



int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m, k;
    cin >> n >> m >> k;

    map <string, ii> map1;
    vector <vi> a(n + 1, vi (m + 1, 0));


    for(int i = 0; i < k; i++) {
        int u, v, w;
        string s;
        cin >> u;
        if(u == 1) {
            cin >> v >> w >> s;
            bool flag = true;
            for(int j = v; j <= n && flag; j++) {
                int p = 1;
                if(j == v) p = w;
                for(;p <= m; p++) {
                    if(a[j][p] == 0) {
                        map1[s] = {j, p};
                        a[j][p] = 1;
                        flag = false;
                        break;
                    }
                }
            }
        } else {
            cin >> s;
            if(map1.count(s)) {
                ii temp = map1[s];
                cout << temp.first << " " << temp.second << "\n";
                a[temp.first][temp.second] = 0;
                map1.erase(s);
            }
            else cout << "-1 -1" << "\n";
        }
    }








}