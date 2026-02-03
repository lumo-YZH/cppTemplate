string s, t, ss;
#define MAXN 2000005
ll dp[MAXN * 2 + 5]; // 注意数组大小
char str[MAXN * 2 + 5];
ll Manacher()
{
    for (ll i = 0; i <= 2 * n + 5; i++)
    {
        dp[i] = 0;
        str[i] = ' ';
    }
    ll N = 0, len = ss.size() - 1;
    str[0] = '$'; // 防止越界
    for (ll i = 1; i <= len; i++)
    {
        str[++N] = '#';
        str[++N] = ss[i];
    }
    str[++N] = '#', str[++N] = '@'; // 最后再加一个@
    ll right = 0, pos = 0;

    for (ll i = 1; i <= N; i++)
    {
        if (i < right)
            dp[i] = min(dp[2 * pos - i], right - i);
        else
            dp[right = i] = 1;
        while (str[i - dp[i]] == str[i + dp[i]])
            dp[i]++;
        if (i + dp[i] > right)
            right = i + dp[i], pos = i;
    }
    ll ret = 0;
    for (ll i = 1; i <= N; i++)
        ret = max(res, dp[i] - 1) // 找最长回文
                                  // for(ll i=1;i<=N;i++)
                                  // ret+=dp[i]/2; //回文子串的个数
            return ret;
}
