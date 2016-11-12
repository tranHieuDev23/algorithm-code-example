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
int n, m, num[mn], low[mn], rig = 0, numTplt = 0;
vector<int> g[mn], tplt[mn];
stack<int> Stack;

void setup()
{
    cin >> n >> m;
    int u, v;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        g[u].pb(v);
    }
}

void dfs(int u, int p)
{
    num[u] = low[u] = ++ rig;
    Stack.push(u);
    FOR(i, 0, int(g[u].size()) - 1)
    {
        int v = g[u][i];
        if (v == p)
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u])
    {
        numTplt ++;
        while(true)
        {
            int v = Stack.top();
            Stack.pop();
            num[v] = maxC;
            tplt[numTplt].pb(v);
            if (v == u)
                break;
        }
    }
}

void xuly()
{
    FOR(i, 1, n)
    if (!num[i])
        dfs(i, -1);
    cout << numTplt << '\n';
    FOR(i, 1, numTplt)
    {
        FOR(j, 0, int(tplt[i].size()) - 1)
            cout << tplt[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("TARJAN.INP", "r", stdin);
    freopen("TARJAN.OUT", "w", stdout);
    setup ();
    xuly ();
    return 0;
}
