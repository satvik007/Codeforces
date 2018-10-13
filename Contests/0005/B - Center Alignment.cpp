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

    vector <string> a;
    string u;
    int k = 0;
    while(getline(cin, u)) {
        a.push_back(u);
        k = max(k, (int)u.size());
    }

    int f = 1;

    cout << string(k + 2, '*') << "\n";

    for(int i = 0; i < a.size(); i++) {
        cout << "*";
        if((a[i].size() % 2) ^ (k % 2)) {
            int v = (k - (int)a[i].size()) / 2;
            if(f)
                cout << string (v, ' ') << a[i] << string (v + 1, ' ');
            else
                cout << string (v + 1, ' ') << a[i] << string (v, ' ');
            f = !f;
        } else {
            int v = (k - (int)a[i].size()) / 2;
            cout << string (v, ' ') << a[i] << string (v, ' ');
        }
        cout << "*\n";
    }

    cout << string(k + 2, '*');

}