#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 300
#define maxC 1000007
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define C(x, y) (c[x][y] - fx[x] - fy[y])

using namespace std;
int n, c[mn][mn], fx[mn], fy[mn];
int matchX[mn], matchY[mn], Queue[mn];
int reachX[mn], reachY[mn], inReachY[mn];
int trace[mn], numX, numY, co;

void setup()
{
    cin >> n;
    FOR(u, 1, n)
    FOR(v, 1, n)
        c[u][v] = maxC;
    int u, v;
    while(cin >> u)
    {
        cin >> v;
        cin >> c[u][v];
    }
}

int findArgumentPath(int s)
{
    co ++;
    numX = numY = 0;
    int l = 1, r = 1;
    Queue[1] = s;
    while(l <= r)
    {
        int u = Queue[l ++];
        reachX[++ numX] = u;
        FOR(v, 1, n)
        if (inReachY[v] != co && C(u, v) == 0)
        {
            inReachY[v] = co;
            reachY[++ numY] = v;
            trace[v] = u;
            if (!matchY[v])
                return v;
            Queue[++ r] = matchY[v];
        }
    }
    return 0;
}

void changeEdge()
{
    int delta = maxC;
    FOR(i, 1, numX)
    {
        int u = reachX[i];
        FOR(v, 1, n)
        if (inReachY[v] != co)
            delta = min(delta, C(u, v));
    }

    FOR(i, 1, numX)
        fx[reachX[i]] += delta;
    FOR(i, 1, numY)
        fy[reachY[i]] -= delta;
}

void argumenting(int y)
{
    while(inReachY[y] == co)
    {
        int x = trace[y];
        int nex = matchX[x];
        matchX[x] = y;
        matchY[y] = x;
        y = nex;
    }
}

void xuly()
{
    FOR(x, 1, n)
    while(true)
    {
        int y = findArgumentPath(x);
        if (y)
        {
            argumenting(y);
            break;
        }
        changeEdge();
    }
    int ans = 0;
    FOR(x, 1, n)
        ans += c[x][matchX[x]];
    cout << ans << '\n';
    FOR(x, 1, n)
        cout << x << ' ' << matchX[x] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("HUNGARIAN.INP", "r", stdin);
    freopen("HUNGARIAN.OUT", "w", stdout);
    setup ();
    xuly ();
    return 0;
}
