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

    int n, m;
    cin >> n >> m;

    if(n == 1) {
        if(m == 2) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
            cout << 1 << " " << m << " 1 1\n";
        }
        for(int i = 1; i <= m; i++) {
            cout << 1 << " " << i << "\n";
        }
        cout << "1 1\n";
    } else if(m == 1) {
        if(n == 2) {
            cout << "0\n";
        } else {
            cout << "1 \n";
            cout << n << " " << "1 1 1\n";
        }
        for(int i = 1; i <= n; i++) {
            cout << i << " " << 1 << "\n";
        }
        cout << "1 1\n";
    } else {
        if(!(n % 2) || !(m % 2)) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
            if(!(n % 2))
                cout << 1 << " " << m << " 1 1" << "\n";
            else
                cout << n << " " << 1 << " 1 1" << "\n";
        }
        if(!(n % 2)) {
            for(int i = 1; i <= n; i++) {
                cout << i << " " << 1 << "\n";
            }
            for(int i = n; i >= 1; i--) {
                if((n - i) % 2) {
                    for(int j = m; j >= 2; j--) {
                        cout << i << " " << j << "\n";
                    }
                } else {
                    for(int j = 2; j <= m; j++) {
                        cout << i << " " << j << "\n";
                    }
                }
            }
        } else {
            for(int i = 1; i <= m; i++) {
                cout << 1 << " " << i << "\n";
            }
            for(int i = m; i >= 1; i--) {
                if((m - i) % 2) {
                    for(int j = n; j >= 2; j--) {
                        cout << j << " " << i << "\n";
                    }
                } else {
                    for(int j = 2; j <= n; j++) {
                        cout << j << " " << i << "\n";
                    }
                }
            }
        }

        cout << "1 1\n";
    }


}