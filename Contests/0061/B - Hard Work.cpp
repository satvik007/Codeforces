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

    string a, b, c;
    string s;
    cin >> s;
    for(auto el: s) {
        if(el >= 'a' && el <= 'z') a += el;
        else if(el >= 'A' && el <= 'Z') a += (el - 'A' + 'a');
    }
    cin >> s;
    for(auto el: s) {
        if(el >= 'a' && el <= 'z') b += el;
        else if(el >= 'A' && el <= 'Z') b += (el - 'A' + 'a');
    }
    cin >> s;
    for(auto el: s) {
        if(el >= 'a' && el <= 'z') c += el;
        else if(el >= 'A' && el <= 'Z') c += (el - 'A' + 'a');
    }

    string m;

    vector <string> col(6);
    col[0] = a + b + c;
    col[1] = a + c + b;
    col[2] = b + a + c;
    col[3] = b + c + a;
    col[4] = c + a + b;
    col[5] = c + b + a;

    int k;
    cin >> k;
    while(k--) {
        cin >> s;
        m.clear();
        for(auto el: s) {
            if(el >= 'a' && el <= 'z') m += el;
            else if(el >= 'A' && el <= 'Z') m += (el - 'A' + 'a');
        }
        if(find(col.begin(), col.end(), m) != col.end()) {
            cout << "ACC\n";
        }  else {
            cout << "WA\n";
        }
    }


}