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

typedef int T;
struct pt {
    T x, y;
    pt (T x, T y) : x(x), y(y) {}
    pt () {}
    bool operator == (pt a) {
        return x == a.x && y == a.y;
    }
    bool operator != (pt a) {
        return !(*this == a);
    }
    pt operator - (pt a) {
        return {x - a.x, y - a.y};
    }
    pt operator + (pt a) {
        return {x + a.x, y + a.y};
    }
    double dot(pt a) {
        return (x * a.x + y * a.y);
    }
//    bool operator < (pt a) {
//        if(a.x != x) return x < a.x;
//        return y < a.y;
//    }
};

bool operator < (pt a, pt b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

ostream& operator << (ostream& out, pt a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    map <pt, int> map1;
    vector <pt> a(8), b;
    bool flag = true;

    for(int i = 0; i < 8; i++) {
        cin >> a[i].x >> a[i].y;
        if(map1.count(a[i])) map1[a[i]]++;
        else map1[a[i]] = 1;
    }

    flag = (map1.size() == 4);
    for(auto el: map1) {
        if(el.second != 2) flag = false;
    }

    b.push_back(a[0]);
    b.push_back(a[1]);

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 8; i++) {
            //cout << a[i] << " " << a[i ^ 1] << "\n";
            if(a[i] == b.back() && a[i ^ 1] != b[b.size() - 2]) {
                b.push_back(a[i ^ 1]);
                break;
            }
        }
    }

    //for(auto el: b) cout << el << "\n";

    flag = flag and b.size() == 4;

    for(int i = 0; i < 4 && flag; i++) {
        double cur = (b[(i + 3) % 4] - b[i]).dot(b[(i + 1) % 4] - b[i]);
        if(!(b[(i + 1) % 4].x == b[i].x || b[(i + 1) % 4].y == b[i].y)) flag = false;
        if(cur > 1e-9) flag = false;
    }

    cout << ((flag) ? "YES\n": "NO\n");



}