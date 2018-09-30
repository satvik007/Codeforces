// lose small or win big.
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
vector <string> a(3);

int first_won() {
    bool f[8];
    int k = 0;
    for(int i = 0; i < 3; i++) {
        int c1 = 0, c2 = 0;
        for(int j = 0; j < 3; j++) {
            c1 += (a[i][j] == 'X');
            c2 += (a[j][i] == 'X');
        }
        f[k++] = (c1 == 3);
        f[k++] = (c2 == 3);
    }
    int c1 = 0, c2 = 0;
    for(int i = 0; i < 3; i++) {
        c1 += (a[i][i] == 'X');
        c2 += (a[i][2 - i] == 'X');
    }
    f[k++] = (c1 == 3);
    f[k++] = (c2 == 3);
    c1 = f[0] + f[2] + f[4];
    c2 = f[1] + f[3] + f[5];
    if(c1 > 1 or c2 > 1) return -1;
    else {
        c1 = 0;
        for(int i = 0; i < 8; i++) {
            c1 |= f[i];
        }
        return c1;
    }
}

int second_won() {
    bool f[8];
    int k = 0;
    for(int i = 0; i < 3; i++) {
        int c1 = 0, c2 = 0;
        for(int j = 0; j < 3; j++) {
            c1 += (a[i][j] == '0');
            c2 += (a[j][i] == '0');
        }
        f[k++] = (c1 == 3);
        f[k++] = (c2 == 3);
    }
    int c1 = 0, c2 = 0;
    for(int i = 0; i < 3; i++) {
        c1 += (a[i][i] == '0');
        c2 += (a[i][2 - i] == '0');
    }
    f[k++] = (c1 == 3);
    f[k++] = (c2 == 3);

    c1 = f[0] + f[2] + f[4];
    c2 = f[1] + f[3] + f[5];
    if(c1 > 1 or c2 > 1) return -1;
    else {
        c1 = 0;
        for(int i = 0; i < 8; i++) {
            c1 |= f[i];
        }
        return c1;
    }
}


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    int c1 = 0, c2 = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            c1 += (a[i][j] == 'X');
            c2 += (a[i][j] == '0');
        }
    }

    int f = first_won();
    int s = second_won();

    //cout << f << " " << s << "\n";

    if (f == -1 or s == -1 or (f and s) or c2 > c1 or c1 - c2 > 1 or (c1 > c2 and s) or (f and c1 == c2)) {
        cout << "illegal";
    } else if (f) {
        cout << "the first player won";
    } else if (s) {
        cout << "the second player won";
    } else {
        if(c1 == c2) {
            cout << "first";
        } else if (c1 + c2 == 9) {
            cout << "draw";
        } else {
            cout << "second";
        }
    }


}