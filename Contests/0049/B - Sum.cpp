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

    int big = 1;
    for(auto el: a) {
        if(el - '0' > big) big = el - '0';
    }

    for(auto el: b) {
        if(el - '0' > big) big = el - '0';
    }
    char buffer[33];
    int num = stoi(a, 0, big + 1) + stoi(b, 0, big + 1);
    string ans = itoa(num, buffer, big + 1);
    cout << ans.size() << "\n";

}