// lose small or win big.
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

    string a, b;
    cin >> a >> b;

    vector <string> ans;

    while (a != b) {
        string c;

        if(a[0] < b[0]) {
            c += 'R';
            a[0]++;
        } else if(a[0] > b[0]) {
            c += 'L';
            a[0]--;
        }

        if(a[1] < b[1]) {
            c += 'U';
            a[01]++;
        } else if(a[1] > b[1]) {
            c += 'D';
            a[1]--;
        }

        ans.push_back(c);
    }

    cout << ans.size() << "\n";
    for(auto el: ans) {
        cout << el << "\n";
    }

}