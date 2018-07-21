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

ii a[110];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    cin >> n;

    set <int> set1;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i].first + a[i].second == a[j].first && a[i].first == a[j].first + a[j].second) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

}