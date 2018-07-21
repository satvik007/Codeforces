/*
When my time comes
Forget the wrong that I've done
Help me leave behind some reasons to be missed
And don't resent me
And when you're feeling empty
Keep me in your memory
Leave out all the rest
Leave out all the rest
 */

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

ii a[maxn];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    map <int, int> map1, map2, map3;

    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if(map1.count(u)) map1[u]++;
        else map1[u] = 1;
        if(map1.count(v)) map1[v]++;
        else map1[v] = 1;
        if(map2.count(u)) {
            map3[u] = i;
        } else {
            map2[u] = i;
        }
        if(map2.count(v)) {
            map3[v] = i;
        } else {
            map2[v] = i;
        }
        a[i] = {u, v};
    }

    int f = -1, s = -1;

    for(auto el: map1) {
        if(el.second == 1) {
            if(f == -1) f = el.first;
            else s = el.first;
        }
    }

    cout << f << " ";

    int c = map2[f];

    //int cnt = 0;
    while(true) {
        //cout << c << " " << f << "\n";
        //cnt++;
        //cout << a[c].first << " " << a[c].second << " " << c << " " << f << "\n";
        if(a[c].first == f) {
            if(map1[a[c].second] == 1) {
                cout << a[c].second << "\n";
                break;
            }
            f = a[c].second;
            if(map2[a[c].second] == c) c = map3[a[c].second];
            else c = map2[a[c].second];
            cout << f << " ";
        } else {
            if(map1[a[c].first] == 1) {
                cout << a[c].first << "\n";
                break;
            }
            f = a[c].first;
            if(map2[a[c].first] == c) c = map3[a[c].first];
            else c = map2[a[c].first];
            cout << f << " ";
        }
    }

}