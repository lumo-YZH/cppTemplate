#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second

typedef complex<double> cd;

void fft(vector<cd> &a, bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
    {
        for (cd &x : a)
            x /= n;
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)(a.size() + b.size()))
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve()
{
    string A, B;
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    vector<int> a, b;
    for (char c : A)
        a.push_back(c == '1');
    for (char c : B)
        b.push_back(c == '1');
    vector<int> c = multiply(a, b);

    unordered_set<int> s;
    int k = 0;
    while (k < c.size())
    {
        int x = c[k];
        if (x == 0)
        {
            k++;
            continue;
        }
        int q = x % 2;
        if (q < 0)
            q += 2;
        int w = (q - x) / 2;
        if (q == 1)
            s.insert(k);

        if (k + 2 >= c.size())
            c.resize(k + 3, 0);
        c[k + 2] += w;
        k++;
    }

    if (s.empty())
    {
        cout << 0 << '\n';
        return;
    }

    int z = *max_element(s.begin(), s.end());
    string res = "";
    for (int i = z; i >= 0; i--)
    {
        if (s.count(i))
            res += '1';
        else
            res += '0';
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}