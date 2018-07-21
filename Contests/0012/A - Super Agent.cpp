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

    vector <string> a(3);

    for(int i = 0; i < 3; i++) cin >> a[i];

    int cnt = 0;

    bool flag = true;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(a[i][j] == 'X') cnt++;
            if(a[i][j] == 'X' && a[2 - i][2 - j] != 'X') flag = false;
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";



}