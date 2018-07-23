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

    string a;

    map <char, int> map1;
    map1['a'] = 1;
    map1['e'] = 1;
    map1['i'] = 1;
    map1['o'] = 1;
    map1['u'] = 1;

    bool flag = true;
    for(int i = 0; i < 3; i++) {
        int cnt = 0;
        getline(cin, a);
        for(auto el: a) {
            if(map1.count(el)) {
                cnt++;
            }
        }
        if(i == 1 and cnt != 7) {
            flag = false;
        }
        if((i == 0 || i == 2) and cnt != 5) {
            flag = false;
        }
    }

    cout << (flag ? "YES\n": "NO\n");

}