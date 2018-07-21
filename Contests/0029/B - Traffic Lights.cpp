/*
So wake me up when it's all over
When I'm wiser and I'm older
All this time I was finding myself
And I didn't know﻿ I was lost
So wake me up when it's all over
When I'm wiser and I'm older
All this time I was finding myself
And I didn't know ﻿I was lost

I tried carrying the weight of the world
But I only have two hands
I hope I get the chance to travel the world
But I don't have any plans
I wish that I could stay forever this young
Not afraid to close my eyes
Life's a game﻿ made for everyone
And love is the prize
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(8);

    double l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;

    double ans = 0;
    double t1 = d / v;
    double f = ((int) t1 / (int)(r + g)) * (r + g);
    if(t1 - f < g) {
        ans = l / v;
    } else {
        ans = f + g + r + (l - d) / v;
    }

    cout << ans << "\n";

}