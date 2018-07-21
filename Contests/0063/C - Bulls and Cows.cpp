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
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    string s[n];
    int u[n];
    int v[n];

    for(int i = 0; i < n; i++) {
        cin >> s[i] >> u[i] >> v[i];
    }

    vector <string> ans;

    for(int i = 0; i < 10000; i++) {
        string t = to_string(i);
        if(t.size() <= 2) continue;
        if(t.size() == 3) t = "0" + t;
        bool flag = false;
        for(int j = 0; j < 3; j++) {
            for(int k = j + 1; k < 4; k++) {
                if(t[j] == t[k]) flag = true;
            }
        }
        if(flag) continue;

        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                if(s[j][k] == t[k]) cnt++;
            }
            int an = 0;
            for(int k = 0; k < 4; k++) {
                for(int m = 0; m < 4; m++) {
                    if(s[j][k] == t[m]) an++;
                }
            }
            an -= cnt;
            if(cnt != u[j] || an != v[j]) {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        ans.push_back(t);
    }

    if(ans.size() > 1) cout << "Need more data\n";
    else if(ans.size() == 1) cout << ans[0] << "\n";
    else cout << "Incorrect data\n";


}