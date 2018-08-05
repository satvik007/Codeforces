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
    cin.ignore();
    map <string, int> map1;

    map1["void"] = 1;

    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        string a, b, c;
        stringstream sin(s);

        sin >> a;

        if(a == "typedef") {
            sin >> b >> c;
            string e;
            int u = 0, v = 0;
            for(auto el: b) {
                if(el != '*' and el != '&') e += el;
                if(el == '*') u++;
                if(el == '&') v++;
            }
            if(map1[e] == 0) {
                map1[c] = 0;
            } else {
                map1[c] = max(u + map1[e] - v, 0);
            }
        } else if(a == "typeof") {
            sin >> b;
            string e;
            int u = 0, v = 0;
            for(auto el: b) {
                if(el != '*' and el != '&') e += el;
                if(el == '*') u++;
                if(el == '&') v++;
            }

            if(map1[e] + u - v - 1 < 0 || map1[e] == 0) {
                cout << "errtype\n";
            } else {
                cout << "void" << string(map1[e] + u - v - 1, '*') << "\n";
            }
        }
    }

}