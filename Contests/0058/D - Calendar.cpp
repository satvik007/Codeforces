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

    int n;
    cin >> n;

    set <string> set1;
    vector <set<string> > a(11);

    int cnt = 0;

    vector <string> b;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b.push_back(s);
        cnt += s.size();
    }

    cnt /= (n / 2);

    char sym;
    cin >> sym;

    for(int i = 0; i < n; i++) {
        set1.insert(b[i] + sym);
        a[b[i].size()].insert(b[i] + sym);
    }

    string u, v;

    for(int i = 0; i < n / 2; i++) {
        u = *set1.begin();
        set1.erase(set1.begin());
        a[u.size() - 1].erase(u);
        u.pop_back();
        v = *a[cnt - u.size()].begin();
        a[v.size() - 1].erase(v);
        set1.erase(v);
        v.pop_back();
        cout << u << sym << v << "\n";
    }

}