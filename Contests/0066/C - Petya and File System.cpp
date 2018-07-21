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

struct Node {
    int v, fi, sub;
    vector <Node*> ch;
    vi files;
    Node () : fi(0), sub(0), v(0) {}
};

void add(Node* cur, const vi &path, int ind, int fil) {
    if(ind == path.size()) {
        cur -> files.push_back(fil);
    } else {
        for(int i = 0; i < cur -> ch.size(); i++) {
            if(cur -> ch[i] -> v == path[ind]) {
                add(cur -> ch[i], path, ind + 1, fil);
                return;
            }
        }
        Node *n = new Node;
        n -> v = path[ind];
        cur -> ch.push_back(n);
        add(n, path, ind + 1, fil);
    }
}

ii show(Node* root) {
    int f = 0, s = 0;
    for(int i = 0; i < root -> ch.size(); i++) {
        ii t = show(root -> ch[i]);
        f += t.first;
        s += t.second;
    }
    f += root -> ch.size();
    s += root -> files.size();
    root -> sub = f;
    root -> fi = s;
    return {f, s};
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    string s;
    map <string, int> map1;
    vector <string> names;
    int n = 0;

    Node* root = new Node;

    while(getline(cin, s)) {
        string a;
        vi path;
        string f = string(1, s[0]);
        if(!map1.count(f)) {
            map1[f] = n++;
            names.push_back(f);
        }
        path.push_back(map1[f]);
        for(int i = 3; i < s.size(); i++) {
            if(s[i] == '\\') {
                if(!map1.count(a)) {
                    map1[a] = n++;
                    names.push_back(a);
                }
                path.push_back(map1[a]);
                a.clear();
            } else {
                a += s[i];
            }
        }
        if(!map1.count(a)) {
            map1[a] = n++;
            names.push_back(a);
        }
        add(root, path, 0, map1[a]);
    }
    show(root);
    int a1 = 0, a2 = 0;
    for(int i = 0; i < root -> ch.size(); i++) {
        for(int j = 0; j < root -> ch[i] -> ch.size(); j++) {
            a1 = max(a1, root -> ch[i] -> ch[j] -> fi);
            a2 = max(a2, root -> ch[i] -> ch[j] -> sub);
        }
    }
    cout << a2 << " " << a1 << "\n";
}