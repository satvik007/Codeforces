/*
When my time comes
Forget the wrong that I've done
Help me leave behind some reasons to be missed
And don't resent me
And when you're feeling empty
Keep me in your memory
Leave out all the rest
Leave out all the rest
 */

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

    set <int> set1;
    string s;

    while(cin.peek() != EOF) {
        int u; cin >> u;
        set1.insert(u);
        char null;
        cin >> null;
    }

    vi a;

    for(auto el: set1) {
        a.push_back(el);
    }

    int n = a.size();

    int last = 0;
    for(int i = 1; i < n; i++) {
        if(a[last] + i - last != a[i]) {
            if(last == i - 1) {
                cout << a[last] << ",";
            } else {
                cout << a[last] << "-" << a[i - 1] << ",";
            }
            last = i;
        }
    }

    if(last == n - 1) {
        cout << a[last];
    } else {
        cout << a[last] << "-" << a[n - 1];
    }


}