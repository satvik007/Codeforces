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

    int a, b, c, d, n;

    cin >> a >> b >> c >> d >> n;

    vector <string> ans(max(b, d), string(a + c, '.'));

    int x = 0, y = 0;
    if(a % 2) x = b - 1;

    function <void()> nex = [&]() {
        int l = (y < a) ? b - 1 : d - 1;
        if(a % 2) {
            if(y % 2) {
                if(x == l) y++;
                else x++;
            } else {
                if(x == 0) y++;
                else x--;
            }
        } else {
            if(y % 2) {
                if(x == 0) y++;
                else x--;
            } else {
                if(x == l) y++;
                else x++;
            }
        }
    };

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        while(k--) {
            ans[x][y] = (char)(i + 'a');
            nex();
        }
    }
    cout << "YES\n";
    for(auto row: ans) {
        cout << row << "\n";
    }

}