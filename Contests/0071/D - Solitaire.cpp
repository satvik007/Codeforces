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

ii x, y;
int n, m;
vector <vector <string> > a;

bool solve() {
    set <char> va;
    set <char> cl;
    int cnt = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < m - 2; j++) {
            va.clear();
            cl.clear();
            for(int p = 0; p < 3; p++) {
                for(int q = 0; q < 3; q++) {
                    va.insert(a[i + p][j + q][0]);
                    cl.insert(a[i + p][j + q][1]);
                }
            }
            if(va.size() == 9 || cl.size() == 1) {
                if(cnt == 0) {
                    x.first = i + 1;
                    x.second = j + 1;
                    cnt++;
                }  else if(cnt == 1 and (abs(x.first - i - 1) >= 3 || abs(x.second - j - 1) >= 3)) {
                    y.first = i + 1;
                    y.second = j + 1;
                    cnt++;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);


    cin >> n >> m;
    a.resize(n, vector <string> (m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ii j1, j2;

    bool f1 = false, f2 = false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j][1] == '1') {
                j1.first = i, j1.second = j;
                f1 = true;
            } else if(a[i][j][1] == '2'){
                j2.first = i, j2.second = j;
                f2 = true;
            }
        }
    }

    vector <string> nud;
    set <string> used;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            used.insert(a[i][j]);
        }
    }

    char va[15] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char cl[4] = {'C', 'D', 'H', 'S'};

    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 4; j++) {
            string c = string(1, va[i]) + cl[j];
            if(!used.count(c)) {
                nud.push_back(c);
            }
        }
    }

    int q = nud.size();

    if(!(f1 | f2)) {
        if(solve()) {
            cout << "Solution exists.\n" <<
                    "There are no jokers.\n" <<
                    "Put the first square to (" << x.first << ", " << x.second << ").\n" <<
                    "Put the second square to (" << y.first << ", " << y.second << ").\n";
        } else {
            cout << "No solution.\n";
        }
    } else if((f1 & !f2) | (f2 & !f1)) {
        if(f2) j1 = j2;
        for(int i =  0; i < q; i++) {
            a[j1.first][j1.second] = nud[i];
            if(solve()) {
                cout << "Solution exists.\n" <<
                    "Replace J";
                cout << ((f1) ? "1" : "2");
                cout << " with " << nud[i] << ".\n" <<
                    "Put the first square to (" << x.first << ", " << x.second << ").\n" <<
                    "Put the second square to (" << y.first << ", " << y.second << ").\n";
                return 0;
            }
        }
        cout << "No solution.\n";
    } else if(f1 && f2) {
        for(int i = 0; i < q; i++) {
            a[j1.first][j1.second] = nud[i];
            for(int j = 0; j < q; j++) {
                if(i == j) continue;
                a[j2.first][j2.second] = nud[j];
                if(solve()) {
                    cout << "Solution exists.\n" <<
                         "Replace J1 with " << nud[i] << " and J2 with " << nud[j] << ".\n" <<
                         "Put the first square to (" << x.first << ", " << x.second << ").\n" <<
                         "Put the second square to (" << y.first << ", " << y.second << ").\n";
                    return 0;
                }
            }
        }
        cout << "No solution.\n";
    }
}