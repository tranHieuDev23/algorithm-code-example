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
class SuffixAutomaton
{
    private:
        class SAState
        {
            public:
                int length;
                SAState *link, *next[26];

                SAState(int length = 0, SAState *link = NULL): length(length), link(link)
                {
                    FOR(i, 0, 25)
                        next[i] = NULL;
                }
        };

        SAState *root, *last;

    public:
        SuffixAutomaton()
        {
            last = root = new SAState(0, NULL);
        }

        void insert(char c)
        {
            c -= 'a';
            SAState* newState = new SAState(last->length + 1);
            while (last != NULL && last->next[c] == NULL)
            {
                last->next[c] = newState;
                last = last->link;
            }
            if (last == NULL)
                newState->link = root;
            else
            {
                SAState* stateC = last->next[c];
                if (stateC->length == last->length + 1)
                    newState->link = stateC;
                else
                {
                    SAState* cloneState = new SAState(last->length + 1, stateC->link);
                    FOR(i, 0, 25)
                        cloneState->next[i] = stateC->next[i];
                    while (last != NULL && last->next[c] == stateC)
                    {
                        last->next[c] = cloneState;
                        last = last->link;
                    }
                    newState->link = stateC->link = cloneState;
                }
            }
            last = newState;
        }

        bool checkSubstring(string& s)
        {
            SAState* state = root;
            FOR(i, 0, int(s.size()) - 1)
            {
                if (state->next[s[i] - 'a'] == NULL)
                    return false;
                state = state->next[s[i] - 'a'];
            }
            return true;
        }
} sAuto;

void setup()
{

}

void xuly()
{

}

int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup ();
    xuly ();
    return 0;
}
