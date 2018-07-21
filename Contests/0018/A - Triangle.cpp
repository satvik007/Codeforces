// Warten auf das Licht, das nie kommt.
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

struct pt {
    int x, y;
    double dot(pt a) {
        return x * a.x + y * a.y;
    }
    pt operator - (pt a) {
        return {x - a.x, y - a.y};
    }
    pt operator + (pt a) {
        return {x + a.x, y + a.y};
    }
    bool operator == (pt a) {
        return x == a.x && y == a.y;
    }
};

istream& operator >> (istream &in, pt &a) {
    in >> a.x >> a.y;
    return in;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    vector <pt> a(3);

    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    function <bool()> is_right = [&] () {
        for(int i = 0; i < 3; i++) {
            for(int j = i + 1; j < 3; j++) {
                if(a[i] == a[j]) return false;
            }
        }
        for(int i = 0; i < 3; i++) {
            double cur = (a[i] - a[(i + 1) % 3]).dot(a[i] - a[(i + 2) % 3]);
            if(abs(cur) < 1e-9) return true;
        }
        return false;
    };

    if(is_right()) {
        cout << "RIGHT\n"; return 0;
    }

    bool flag = false;
    for(int i = 0; i < 3; i++) {
        a[i].x += 1;
        if(is_right()) flag = true;
        a[i].x -= 2;
        if(is_right()) flag = true;
        a[i].x += 1;
        if(is_right()) flag = true;
        a[i].y += 1;
        if(is_right()) flag = true;
        a[i].y -= 2;
        if(is_right()) flag = true;
        a[i].y += 1;
        if(is_right()) flag = true;
    }

    if(flag) cout << "ALMOST\n";
    else cout << "NEITHER\n";

}