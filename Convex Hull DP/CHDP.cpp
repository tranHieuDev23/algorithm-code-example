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
struct line
{
    long long a, b;

    bool operator < (const line& x)
    {
        if (a != x.a)
            return a > x.a;
        return b < x.b;
    }

    line(long long a = 0, long long b = 0): a(a), b(b) {};

    long long val(long long x) {return a * x + b;}
};
int n, m, r;
vector<line> allLine;
line Stack[mn];
double rLim[mn];

void setup()
{
    cin >> n >> m;
    long long a, b;
    FOR(i, 1, n)
    {
        cin >> a >> b;
        allLine.pb(line(a, b));
    }
}

double intersect(line a, line b)
{
    return 1.0 * (b.b - a.b) / (a.a - b.a);
}

void prepare()
{
    sort(allLine.begin(), allLine.end());
    Stack[r = 1] = allLine[0];
    rLim[0] = - maxC;
    rLim[1] = maxC;
    FOR(i, 1, n - 1)
    if (allLine[i].a != allLine[i - 1].a)
    {
        double x = intersect(Stack[r], allLine[i]);
        while(x < rLim[r - 1])
            x = intersect(Stack[-- r], allLine[i]);
        Stack[++ r] = allLine[i];
        rLim[r - 1] = x;
        rLim[r] = maxC;
    }
}

long long getMin(long long x)
{
    int lef = 0, rig = r;
    while(rig - lef > 1)
    {
        int mid = ((rig + lef) >> 1);
        if (x <= rLim[mid])
            rig = mid;
        else
            lef = mid;
    }
    return Stack[rig].val(x);
}

void xuly()
{
    prepare();
    int x;
    FOR(i, 1, m)
    {
        cin >> x;
        cout << getMin(x) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("CHDP.INP", "r", stdin);
    freopen("CHDP.OUT", "w", stdout);
    setup ();
    xuly ();
    return 0;
}
