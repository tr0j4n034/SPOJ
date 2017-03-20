#include <bits/stdc++.h>
 
using namespace std;
 
#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>
 
const int me = 10025;
const int mod = 1.e9 + 7;
 
int t, n, m, q, A, B;
int dis[me];
string city, a, b;
vector<pii > edges[me];
map<string, int> pos;
set<pii > s;
 
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    scanf("%d", &t);
    for (int c = 0; c < t; c++) {
        scanf("%d", &n);
        pos.clear();
        for (int i = 1; i <= n; i++)
            edges[i].clear();
        for (int ct = 1; ct <= n; ct++) {
            cin >> city >> m;
            pos[city] = ct;
            for (int i = 0; i < m; i++) {
                int x, l;
                scanf("%d%d", &x, &l);
                edges[ct].push_back(make_pair(x, l));
            }
        }
        scanf("%d", &q);
        while (q--) {
            cin >> a >> b;
            A = pos[a], B = pos[b];
            for (int i = 1; i <= n; i++)
                dis[i] = INT32_MAX;
            dis[A] = 0;
            s.clear();
            s.insert(make_pair(0, A));
            while (!s.empty()) {
                pii cur = *(s.begin());
                s.erase(s.begin());
                if (cur.first > dis[cur.second])
                    continue;
                for (pii i : edges[cur.second])
                    if (dis[i.first] > cur.first + i.second) {
                        s.erase(make_pair(dis[i.first], i.first));
                        dis[i.first] = cur.first + i.second;
                        s.insert(make_pair(dis[i.first], i.first));
                    }
            }
            if (dis[B] == INT32_MAX)
                puts("NO");
            else printf("%d\n", dis[B]);
        }
 
    }
    return 0;
} 