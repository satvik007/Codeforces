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

struct St {
    int a, b, c, add;
    St () : a(0), b(0), c(0), add(0) {}
    St (int _a, int _b, int _c, int _add) : a(_a), b(_b), c(_c), add(_add) {}
};

bool eq(int d, const string &s, int pos) {
    if(pos >= s.length() + 1) {
        if(d != -1) throw 0;
        return false;
    }
    if(pos == s.length()) return (d == -1);
    if(d < 0) throw 0;
    return d == s[pos] - '0';
}

const int MAXL = 7;
char buf[1024];
int d[MAXL + 2][MAXL + 2][MAXL + 2][2];
vector <string> ans[MAXL + 2][MAXL + 2][MAXL + 2][2];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    cin >> buf;
    string s1, s2, s3;
    int mode = 2;
    for(int i = strlen(buf) - 1; i >= 0; i--) {
        if(buf[i] == '+' || buf[i] == '=') mode--;
        else {
            switch(mode) {
                case 0: s1 += buf[i]; break;
                case 1: s2 += buf[i]; break;
                case 2: s3 += buf[i]; break;
            }
        }
    }

    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();

    deque <St> q;
    memset(d, 0x3F, sizeof d);
    d[0][0][0][0] = 0;
    ans[0][0][0][0] = vector <string> (3);
    q.push_back(St(0, 0, 0, 0));

    while(!q.empty()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        int add = q.front().add;
        int v = d[a][b][c][add];

        bool pr = (a == 1 && b == 1 && c == 0 && add == 0);
        q.pop_front();

        for(int d1 = -1; d1 < 10; d1++) {
            for(int d2 = -1; d2 < 10; d2++) {
                int res = max(d1, 0) + max(d2, 0) + add;
                int cd3 = res % 10;
                int nadd = res / 10;

                vi d3s(1, cd3);

                if(d1 < 0 && d2 < 0 && !cd3) {
                    d3s.push_back(-1);
                }

                for(int i = 0; i < d3s.size(); i++) {
                    int d3 = d3s[i];
                    try {
                        int na = a + eq(d1, s1, a);
                        int nb = b + eq(d2, s2, b);
                        int nc = c + eq(d3, s3, c);
                        int nv = v + 3 - (d1 == -1) - (d2 == -1) - (d3 == -1);

                        if(d[na][nb][nc][nadd] > nv) {
                            d[na][nb][nc][nadd] = nv;
                            vector <string> &cans = ans[na][nb][nc][nadd] = ans[a][b][c][add];
                            if(d1 != -1) cans[0] = string(1, '0' + d1) + cans[0];
                            if(d2 != -1) cans[1] = string(1, '0' + d2) + cans[1];
                            if(d3 != -1) cans[2] = string(1, '0' + d3) + cans[2];
                            q.push_back(St(na, nb, nc, nadd));

                        }
                    } catch(...) {}
                }
            }
        }
    }

    vector <string> cans = ans[l1 + 1][l2 + 1][l3 + 1][0];
    cout << cans[0].c_str() << "+" << cans[1].c_str() << "=" << cans[2].c_str() << "\n";
}