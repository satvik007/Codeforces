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


int m, n, k;
int a[210][210];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

set <ii> set1;

int flood(int x, int y) {

    if(x < 0 || y < 0 || x >= 2 * n || y >= 2 * m || a[x][y] == 1) return 0;

    a[x][y] = 1;

    int ans = (!set1.count({x / 2, y / 2}));
    set1.insert({x / 2, y / 2});

    for(int k = 0; k < 4; k++) {
        ans += flood(x + dr[k], y + dc[k]);
    }
    return ans;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m >> k;

    memset(a, 0, sizeof a);

    for(int i = 0; i < k; i++) {
        int u1, v1, u2, v2;
        cin >> u1 >> v1 >> u2 >> v2;
        if(u1 == u2) {
            v1 *= 2; v2 = v2 * 2 - 1;
            u1 *= 2;
            for(int j = v1; j <= v2; j++) {
                a[u1][j] = 1;
            }
        } else {
            v1 *= 2;
            u1 *= 2; u2 = u2 * 2 - 1;
            for(int j = u1; j <= u2; j++) {
                a[j][v1] = 1;
            }
        }
    }

    vi ans;
    for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j < 2 * m; j++) {
            if(a[i][j] == 0) {
                ans.push_back(flood(i, j));
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(auto el: ans) cout << el << " "; cout << "\n";


}