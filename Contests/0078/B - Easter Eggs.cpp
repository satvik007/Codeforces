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

    string s = "VIBGYOR";

    if(n <= 7) {
        cout << s.substr(0, n) << "\n";
        return 0;
    }

    string a;
    for(int i = 0; i < n - 4; i++) {
        a += s[i % 7];
    }

    for(int i = 0; i < 4; i++) {
        string c = a.substr(a.size() - 3);
        for(int j = 6; j >= 0; j--) {
            if(c.find(s[j]) == string::npos) {
                a += s[j];
                break;
            }
        }
    }

    cout << a << "\n";


}