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

    int n;
    cin >> n;

    map <string, int> map1;

    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if(map1.count(a)) {
            int k = map1[a];
            for(int j = k + 1; ; j++) {
                string b = a + to_string(j);
                if(!map1.count(b)) {
                    map1[a] = j;
                    map1[b] = 0;
                    cout << b << "\n";
                    break;
                }
            }
        } else {
            map1[a] = 0;
            cout << "OK\n";
        }
    }







}