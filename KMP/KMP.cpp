#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 1000006
#define maxC 1000000007
#define pb push_back
#define F first
#define S second
#define mp make_pair

using namespace std;
string s, t;
int n, m, f[mn];

void setup()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();
}

void prepareKMP()
{
    f[0] = -1, f[1] = 0;
    int id = 0;
    FOR(i, 2, m)
    {
        while(id != -1 && t[id] != t[i - 1])
            id = f[id];
        f[i] = ++ id;
    }
}

void KMPing()
{
    int id = 0;
    FOR(i, 1, n)
    {
        while(id != -1 && t[id] != s[i - 1])
            id = f[id];
        if (++ id == m)
            cout << i - m + 1 << ' ', id = f[id];
    }
}

void xuly()
{
    prepareKMP();
    KMPing();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("KMP.INP", "r", stdin);
    freopen("KMP.OUT", "w", stdout);
    setup ();
    xuly ();
    return 0;
}
