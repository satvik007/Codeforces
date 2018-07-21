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

string AtoR(int A) {
    string ans;
    map<int, string> cvt;
    cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
    cvt[100] = "C"; cvt[90] = "XC"; cvt[50] = "L"; cvt[40] = "XL";
    cvt[10] = "X"; cvt[9] = "IX"; cvt[5] = "V"; cvt[4] = "IV";
    cvt[1] = "I";
// process from larger values to smaller values
    for (map<int, string>::reverse_iterator i = cvt.rbegin();
         i != cvt.rend(); i++)
        while (A >= i->first) {
            ans += ((string)i->second).c_str();
            A -= i->first;
        }
    return ans;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    string a, b, c;

    cin >> a >> b >> c;

    map <char, int> map1, rev;

    for(int i = 0; i <= 9; i++) {
        map1[i + '0'] = i;
        rev[i] = i + '0';
    }

    for(int i = 0; i < 26; i++) {
        map1[i + 'A'] = 10 + i;
        rev[10 + i] = i + 'A';
    }

    ll v = 0;
    ll base = 1;
    ll av = stoll(a);
    for(int i = c.size() - 1; i >= 0; i--) {
        v += base * map1[c[i]];
        base *= av;
    }

    if(b == "R") {
        cout << AtoR(v) << "\n";
    } else {
        string ans;
        ll bv = stoll(b);
        while(v) {
            ans += rev[v % bv];
            v /= bv;
        }
        reverse(ans.begin(), ans.end());
        if(ans.empty()) ans += '0';
        cout << ans << "\n";
    }

}