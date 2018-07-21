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

    int n, m, q;

    cin >> n >> m >> q;

    vector <string> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <vector<ii> > ans;
    vector <ii> cur(5);

    int cnt = 1;
    for(int k = 1; k <= 150; k++) {
        for(int i = 0; i + k < n; i++) {
            for(int j = 0; j + k < m; j++) {
                if(i - k < 0 || j - k < 0) continue;
                if(a[i][j] == '*' && a[i + k][j] == '*' && a[i - k][j] == '*' && a[i][j + k] == '*' && a[i][j - k] == '*') {
                    cur[0] = {i, j};
                    cur[1] = {i - k, j};
                    cur[2] = {i + k, j};
                    cur[3] = {i, j - k};
                    cur[4] = {i, j + k};
                    if(q == cnt) {
                        for(auto el: cur) {
                            cout << el.first + 1 << " " << el.second + 1 << "\n";
                        }
                        return 0;
                    }
                    cnt++;
                }
            }
        }
    }

    cout << "-1\n";

}