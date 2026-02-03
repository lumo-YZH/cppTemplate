#include <bits/stdc++.h>
#define N 500010
using namespace std;
namespace AC
{
    int ch[N][26], num[N], fail[N], c;
    void init()
    {
        c = 0;
        memset(ch[c], 0, sizeof ch[c]);
        fail[c] = num[c] = 0;
    }
    void ins(char *s, int n)
    {
        int rt = 0;
        for (int i = 0; i < n; i++)
        {
            int v = s[i] - 'a';
            if (!ch[rt][v])
            {
                ch[rt][v] = ++c;
                memset(ch[c], 0, sizeof ch[c]);
                fail[c] = num[c] = 0;
            }
            rt = ch[rt][v];
        }
        num[rt]++;
    }
    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (ch[0][i])
            {
                fail[ch[0][i]] = 0, q.push(ch[0][i]);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                int v = ch[u][i];
                if (v)
                    fail[v] = ch[fail[u]][i], q.push(v);
                else
                    ch[u][i] = ch[fail[u]][i];
            }
        }
    }
    int query(char *s, int n)
    {
        int rt = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            rt = ch[rt][s[i] - 'a'];
            for (int j = rt; j && ~num[j]; j = fail[j])
            { // ·ÀÖ¹ÖØËÑ
                ans += num[j], num[j] = -1;
            }
        }
        return ans;
    }
};
using namespace AC;
int n;
char p[1000005];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", p);
        ins(p, strlen(p));
    }
    build();
    scanf("%s", p);
    printf("%d\n", query(p, strlen(p)));
    return 0;
}