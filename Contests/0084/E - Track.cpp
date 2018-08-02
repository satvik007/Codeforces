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

typedef pair <pair <int, string>, ii> dt;

int n, m, K, S, T;
string s[60];
int dis(int a, int b) {
    return abs(a / m - b / m) + abs(a % m - b % m);
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> n >> m >> K;

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'S') S = i * m + j;
            else if(s[i][j] == 'T') T = i * m + j;
        }
    }

    priority_queue <dt, vector <dt>, greater <dt> > pq;

    pq.push({{dis(S, T), ""}, {0, S}});
    set <ii> set1;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!pq.empty()) {
        dt t = pq.top();
        pq.pop();

        string ss = t.first.second;
        int mask = t.second.first;
        int id = t.second.second;

        if(set1.count({mask, id})) continue;
        set1.insert({mask, id});

        int x = id / m;
        int y = id % m;

        for(int i = 0; i < 4; i++) {
            int dx = x + dr[i];
            int dy = y + dc[i];
            if(dx < 0 or dy < 0 or dx >= n or dy >= m) continue;
            if(dx * m + dy == T) {
                cout << ss << "\n";
                return 0;
            }
            string nss = ss + s[dx][dy];
            int nmask = mask | (1 << (s[dx][dy] - 'a'));
            if(__builtin_popcount(nmask) <= K)
                pq.push({{dis(dx * m + dy, T) + (int)nss.size(), nss}, {nmask, dx * m + dy}});
        }
    }

    cout << -1 << "\n";
}