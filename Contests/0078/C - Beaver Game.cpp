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

    ll n, m, k;
    cin >> n >> m >> k;

    if(!(n % 2)) {
        cout << "Marsel\n";
    } else {
        vi div;
        for(int i = 1; i * i <= m; i++) {
            if(m % i == 0) {
                div.push_back(i);
                div.push_back(m / i);
            }
        }
        sort(div.begin(), div.end());
        div.resize(unique(div.begin(), div.end()) - div.begin());
        bool flag = false;
        for(int i = 0; i < div.size(); i++) {
            if(div[i] >= k and div[i] < m) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout << "Timur\n";
        } else {
            cout << "Marsel\n";
        }
    }

}