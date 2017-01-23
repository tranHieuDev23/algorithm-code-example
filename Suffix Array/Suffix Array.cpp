#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
#define FORD(i, j, k) for(int i = j; i >= k; i --)
#define maxC 1000000007
#define mn 100005
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
string s;
pair< pair<int, int> , int > suf[mn];
int arr[mn], group[mn][18];

void buildSA(string& s)
{
    int n = s.size();
    FOR(i, 0, n - 1)
        group[i][0] = s[i];
    for(int cnt = 1, step = 1; (cnt >> 1) < n; cnt <<= 1, step ++)
    {
        FOR(i, 0, n - 1)
        {
            suf[i].F.F = group[i][step - 1];
            suf[i].F.S = i + cnt < n? group[i + cnt][step - 1] : -1;
            suf[i].S = i;
        }
        sort(suf, suf + n);
        FOR(i, 0, n - 1)
        {
            if (i && suf[i].F == suf[i - 1].F)
                group[suf[i].S][step] = group[suf[i - 1].S][step];
            else
                group[suf[i].S][step] = i;
        }
    }

    FOR(i, 0, n - 1)
        arr[i] = suf[i].S;
}

void setup()
{
    cin >> s;
    buildSA(s);
    FOR(i, 0, int(s.size()) - 1)
        cout << arr[i] << ' ';
    cout << '\n';
    FOR(i, 0, int(s.size()) - 1)
        cout << s.substr(arr[i], s.size() - arr[i]) << '\n';
}

void xuly()
{

}

int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup();
    xuly();
    return 0;
}
