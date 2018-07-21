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

int cnt[110];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    string user;
    cin >> user;

    int n;
    cin >> n;
    cin.ignore();

    map <string, int> map1;
    int k = 0;
    map1[user] = k++;

    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream sin(s);
        string u, v, a, b, c;
        sin >> u;
        sin >> a;
        if(a != "likes") sin >> b;
        sin.ignore();
        getline(sin, v, '\'');
        if(!map1.count(u)) {
            map1[u] = k++;
        }
        if(!map1.count(v)) {
            map1[v] = k++;
        }
        if(a == "posted") {
            if(u == user) {
                cnt[map1[v]] += 15;
            } else if(v == user) {
                cnt[map1[u]] += 15;
            }
        } else if(a == "commented") {
            if(u == user) {
                cnt[map1[v]] += 10;
            } else if(v == user) {
                cnt[map1[u]] += 10;
            }
        } else if(a == "likes") {
            if(u == user) {
                cnt[map1[v]] += 5;
            } else if(v == user) {
                cnt[map1[u]] += 5;
            }
        }
    }

    vector <pair <int, string> > s;

    for(auto el: map1) {
        if(el.first != user)
            s.push_back({cnt[el.second], el.first});
    }

    sort(s.begin(), s.end(), [&](pair <int, string> f, pair <int, string> s) {
        if(f.first != s.first) return f.first > s.first;
        return f.second < s.second;
    });

    for(auto el: s) cout << el.second << "\n";
}