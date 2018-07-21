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

int dp[1010][1010];
ii p[1010][1010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; i++) {
        dp[i][0] = i; p[i][0].first = i - 1; p[i][0].second = 0;
    }
    for(int i = 1; i <= m; i++){
        dp[0][i] = i; p[0][i].first = 0; p[0][i].second = i - 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1);
            p[i][j].first = i - 1; p[i][j].second = j - 1;
            int c1 = dp[i - 1][j] + 1, c2 = dp[i][j - 1] + 1;
            if(dp[i][j] > c1){
                dp[i][j] = c1; p[i][j].second = j;
            }
            if(dp[i][j] > c2){
                dp[i][j] = c2; p[i][j].first = i; p[i][j].second = j - 1;
            }
        }
    }

    cout << dp[n][m] << "\n";

    vector <ii> ans;
    int x = n, y = m, tx, ty;
    ans.push_back({n, m});

    while(x | y){
        tx = p[x][y].first, ty = p[x][y].second;
        x = tx, y = ty;
        ans.push_back({x, y});
    }
    reverse(ans.begin(), ans.end());

    int cnt = 1;
    tx = ty = 0;

    for(int i = 1; i < ans.size(); i++){
        x = (ans[i].first - ans[i - 1].first);
        y = (ans[i].second - ans[i - 1].second);
        if(x == 1 && y == 0){
            cout << "DELETE " << ty + 1 << "\n"; tx++;
        }else if(x == 0 && y == 1){
            cout << "INSERT " << ty + 1 << " " << b[ty] << "\n"; ty++;
        }else if(x == 1 && y == 1){
            if(a[tx] == b[ty]) ;
            else cout << "REPLACE " << ty + 1 << " " << b[ty] << "\n";
            tx++; ty++;
        }
    }

}