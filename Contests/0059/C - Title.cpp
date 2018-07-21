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

    int k;
    cin >> k;

    string a;
    cin >> a;

    int n = a.size();

    for(int i = 0; i < n; i++) {
        if(a[i] == '?' && a[n - i - 1] != '?') a[i] = a[n - i - 1];
        if(a[n - i - 1] == '?' && a[i] != '?') a[n - i - 1] = a[i];
    }

    set <char> set1;

    for(int i = 0; i < k; i++) {
        set1.insert('a' + i);
    }

    for(int i = 0; i < n; i++) {
        set1.erase(a[i]);
    }

    for(int i = n / 2; i >= 0; i--) {
        if(a[i] == '?') {
            if(set1.empty()) {
                a[i] = a[n - i - 1] = 'a';
            } else {
                a[i] = a[n - i - 1] = *set1.rbegin();
                set1.erase(--set1.end());
            }
        }
    }

    function <bool(string a)> is_pal = [&](string a) {
        for(int i = 0; i < n / 2; i++) {
            if(a[i] != a[n - i - 1]) return false;
        }
        return true;
    };

    if(set1.empty() && is_pal(a)) {
        cout << a << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

}