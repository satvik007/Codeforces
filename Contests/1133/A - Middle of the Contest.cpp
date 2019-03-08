#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

    string a;
    string b;
    cin >> a >> b;

    int h1 = stoi (a.substr (0, 2));
    int h2 = stoi (b.substr (0, 2));

    int m1 = stoi (a.substr (3));
    int m2 = stoi (b.substr (3));

    int m = h1 * 60 + m1 + h2 * 60 + m2;

    m = m / 2;

    int h = m / 60;
    m = m % 60;

    cout << setfill ('0') << setw(2) << h << ":" << setw(2) << m << "\n";

}