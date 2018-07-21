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

    int n, k;
    cin >> n >> k;

    vi a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set <int> s;
    map <int, int> map1;

    for(int i = 0; i < k; i++) {
        if(map1.count(a[i])) map1[a[i]]++;
        else if(s.count(a[i])) {
            map1[a[i]] = 2;
            s.erase(a[i]);
        } else {
            s.insert(a[i]);
        }
    }

    if(s.empty()) {
        cout << "Nothing\n";
    } else {
        cout << (*s.rbegin()) << "\n";
    }

    for(int i = k; i < n; i++) {
        if(map1.count(a[i - k])) {
            if(map1[a[i - k]] == 2) {
                s.insert(a[i - k]);
                map1.erase(a[i - k]);
            } else {
                map1[a[i - k]]--;
            }
        } else {
            s.erase(a[i - k]);
        }
        if(map1.count(a[i])) {
            map1[a[i]]++;
        } else if(s.count(a[i])) {
            s.erase(a[i]);
            map1[a[i]] = 2;
        } else {
            s.insert(a[i]);
        }
        if(s.empty()) {
            cout << "Nothing\n";
        } else {
            cout << *s.rbegin() << "\n";
        }
    }



}