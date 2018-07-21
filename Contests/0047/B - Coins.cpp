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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    char f, sgn, s;

    map <char, int> first, second;

    for(int i = 0; i < 3; i++) {
        cin >> f >> sgn >> s;
        if(sgn == '>') swap(f, s);
        if(!first.count(f)) first[f] = 1;
        else first[f] ++;
        if(!second.count(s)) second[s] = 1;
        else second[s]++;
    }

    if(first.size() == 2 && second.size() == 2) {
        char v1, v2, v;
        for(auto el:first) {
            if(el.second == 2) v1 = el.first;
            else v = el.first;
        }
        for(auto el:second) {
            if(el.second == 2) v2 = el.first;
        }

        cout << v1 << v << v2 << "\n";

    } else {
        cout << "Impossible\n";
    }



}