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

    string s[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

    string a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    do {
        int x, y, z;

        for(int i = 0; i < 12; i++) {
            if(a[0] == s[i]) {
                x = i;
            } if(a[1] == s[i]) {
                y = i;
            } if(a[2] == s[i]) {
                z = i;
            }
        }

        int fi = (y - x + 12) % 12;
        int se = (z - y + 12) % 12;

        if(fi == 4 and se == 3) {
            cout << "major\n";
            return 0;
        } else if(fi == 3 and se == 4) {
            cout << "minor\n";
            return 0;
        }
    } while(next_permutation(a, a + 3));

    cout << "strange\n";
    
}