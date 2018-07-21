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

int dp1[1 << 18];
int dp2[1 << 18];
int path[1 << 18];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    string el[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"};

    map <string, int> map1;

    for(int i = 0; i < 100; i++) {
        map1[el[i]] = i + 1;
    }

    int n, m;
    cin >> n >> m;

    vi a(n), b(m);

    for(int i = 0; i < n; i++) {
        string u;
        cin >> u;
        a[i] = map1[u];
    }
    for(int i = 0; i < m; i++) {
        string u;
        cin >> u;
        b[i] = map1[u];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < (1 << n); i++) {
        int val = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) val += a[j];
        }
        dp1[i] = val;
    }

    for(int i = 0; i < (1 << n); i++) {
        if(dp1[i] == b[0]) {
            dp2[i] = 1;
            path[i] = i;
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        for(int j = i; j; --j &= i) {
            if(dp2[j] == 0) continue;
            int mask = j ^ i;
            if(dp1[mask] == b[dp2[j]] && dp2[i] < dp2[j] + 1) {
                dp2[i] = dp2[j] + 1;
                path[i] = mask;
            }
        }
    }


    for(int i = 0; i < (1 << n); i++) {
        if(dp2[i] == m) {
            cout << "YES\n";
            int x = i;
            vi an;
            while(x != 0) {
                an.push_back(path[x]);
                x = x ^ path[x];
            }
            reverse(an.begin(), an.end());
            int c;
            for(int k = 0; k < an.size(); k++) {
                int e = an[k];
                c = 0;
                for(int j = 0; j < n; j++) {
                    if(e & (1 << j)) {
                        if(c) cout << "+";
                        cout << el[a[j] - 1];
                        c++;
                    }
                }
                cout << "->" << el[b[k] - 1] << "\n";
            }
            return 0;
        }
    }

    cout << "NO\n";


}