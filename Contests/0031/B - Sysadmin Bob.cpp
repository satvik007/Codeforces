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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    string a;
    cin >> a;

    vector <string> b;
    string s;
    bool flag = (a.find('@') != string::npos);
    for(int i = 0; i < a.size(); i++) {
        s += a[i];
        if(a[i] == '@') {
            if(s.size() == 1) {
                flag = false;
                break;
            }
            if(i == a.size() - 1 || a[i + 1] == '@'){
                flag = false;
                break;
            } else {
                s += a[i + 1];
                b.push_back(s);
                i++;
                s.clear();
            }
        }
    }

    if(!flag) {
        cout << "No solution\n"; return 0;
    }

    b.back() += s;

    for(int i = 0; i < b.size(); i++) {
        if(i) cout << ",";
        cout << b[i];
    }



}