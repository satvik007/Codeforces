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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    string a;
    cin >> a;

    string s;
    cin >> s;

    sort(a.begin(), a.end());

    if(stoll(a) == 0) {
        if(a == s) cout << "OK\n";
        else cout << "WRONG_ANSWER\n";
        return 0;
    }

    if(s[0] == '0') {
        cout << "WRONG_ANSWER\n";
        return 0;
    }

    for(int i = 0; i < a.size(); i++) {
        if(a[i] != '0') {
            swap(a[i], a[0]);
            break;
        }
    }

    if(stoll(a) == stoll(s)) {
        cout << "OK\n";
    } else {
        cout << "WRONG_ANSWER\n";
    }


}