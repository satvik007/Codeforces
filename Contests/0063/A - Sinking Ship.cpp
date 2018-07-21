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

    map <string, vector <string>> map1;

    int n;
    cin >> n;

    vector <vector <string> > a(4);

    for(int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;
        if(v == "rat") a[0].push_back(u);
        else if(v == "man") a[2].push_back(u);
        else if(v == "captain") a[3].push_back(u);
        else a[1].push_back(u);
    }

    for(int i = 0; i < 4; i++) {
        for(auto el: a[i]) {
            cout << el << "\n";
        }
    }
}