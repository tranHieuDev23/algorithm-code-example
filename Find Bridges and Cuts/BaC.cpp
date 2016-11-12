#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 100005
#define maxC 1000000007
#define pb push_back
#define F first
#define S second
#define mp make_pair

using namespace std;
int n, m, num[mn], low[mn], p[mn];
int child[mn], rig = 0;
bool isCut[mn];
vector<int> g[mn], Cut;
vector< pair<int, int> > Bridge;

void setup()
{
    cin >> n >> m;
    int u, v;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u)
{
    num[u] = low[u] = ++ rig;
    FOR(i, 0, int(g[u].size()) - 1)
    {
        int v = g[u][i];
        if (v == p[u])
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            p[v] = u;
            child[u] ++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u])
                Bridge.pb(mp(u, v));
        }
    }
}

void xuly()
{
    FOR(i, 1, n)
    if (!num[i])
        dfs(i);
    FOR(i, 2, n)
    if (p[i])
    {
        int u = p[i];
        if (low[i] >= num[u])
            isCut[u] |= p[u] || child[u] >= 2;
    }
    FOR(i, 1, n)
    if (isCut[i])
        Cut.pb(i);
    cout << Bridge.size() << '\n';
    FOR(i, 0, int(Bridge.size()) - 1)
        cout << Bridge[i].F << ' ' << Bridge[i].S << '\n';
    cout << Cut.size() << '\n';
    FOR(i, 0, int(Cut.size()) - 1)
        cout << Cut[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("BaC.INP", "r", stdin);
    freopen("BaC.OUT", "w", stdout);
    setup ();
    xuly ();
    return 0;
}
