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

    string dr[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE",
                   "TEQUILA", "VODKA", "WHISKEY", "WINE"};

    int n;
    string s;

    cin >> n;

    int ans = 0;

    while(n--) {
        cin >> s;
        if(s[0] <= '9') {
            if(stoi(s) < 18) ans++;
        } else {
            if(find(dr, dr + 11, s) != dr + 11) ans++;
        }
    }

    cout << ans << "\n";

}