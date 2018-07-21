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

int dp[1 << 20];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int line[15][5] = {{0, 1, 2}, {3, 4, 5, 6}, {7, 8, 9, 10, 11}, {12, 13, 14, 15}, {16, 17, 18},
                     {0, 3, 7}, {1, 4, 8, 12}, {2, 5, 9, 13, 16}, {6, 10, 14, 17}, {11, 15, 18},
                     {2, 6, 11}, {1, 5, 10, 15}, {0, 4, 9, 14, 18}, {3, 8, 13, 17}, {7, 12, 16}};
    int size[15] = {3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3};
    vi moves;

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < size[i]; j++) {
            int v = 0;
            for(int k = j; k < size[i]; k++) {
                v |= (1 << line[i][k]);
                moves.push_back(v);
            }
        }
    };

    sort(moves.begin(), moves.end());
    moves.resize(unique(moves.begin(), moves.end()) - moves.begin());

    string s;
    int c = 0;
    for(int i = 0; i < 19; i++) {
        cin >> s;
        if(s == "O") c |= (1 << i);
    }
    dp[0] = 0;
    for(int i = 0; i <= c; i++) {
        for(int j = 0; j < moves.size(); j++) {
            if(moves[j] > i) break;
            if((i & moves[j]) == moves[j]) {
                dp[i] |= !dp[i ^ moves[j]];
            }
        }
    }

    if(dp[c]) {
        cout << "Karlsson\n";
    } else {
        cout << "Lillebror\n";
    }




}