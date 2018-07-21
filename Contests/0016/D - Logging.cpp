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

    int n;
    cin >> n;

    vector <string> a(n);
    string s;
    getline(cin, s);

    for(int i = 0; i < n; i++) {
        getline(cin, s);
        a[i] = s;
    }

    vi times;

    for(int i = 0; i < n; i++) {
        int u = stoi(a[i].substr(1, 2));
        int v = stoi(a[i].substr(4, 2));
        u = (u % 12) * 60 + v;
        if(a[i][7] == 'p') u += 12 * 60;
        times.push_back(u);
    }
    int cnt = 1;
    int last = -1;
    int ten = 1;
    for(auto el: times) {
        if(el < last) cnt++, ten = 1;
        else if(el == last){
            ten++;
            if(ten > 10) cnt++, ten = 1;
        } else {
            ten = 1;
        }
        last = el;
    }

    cout << cnt << "\n";

}