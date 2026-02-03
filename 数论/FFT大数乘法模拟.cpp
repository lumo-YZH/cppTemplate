#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
const double PI = acos(-1.0);

void fft(vector<complex<double>>& a, bool inv) {
    ll n = a.size();
    if (n == 1) {
        return;
    }
    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (ll i = 0, j = 0; i < n; i += 2, j++) {
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }
    fft(a0, inv);
    fft(a1, inv);
    
    double angle = 2 * PI / n * (inv ? -1 : 1);
    complex<double> w(1), wn(cos(angle), sin(angle));
    for (ll i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        w *= wn;
    }
}

vector<ll> multiply(vector<ll> a, vector<ll> b) {
    ll n = 1;
    while (n < a.size() + b.size()) {
        n *= 2;
    }
    a.resize(n), b.resize(n);
    
    vector<complex<double>> c(n), d(n);
    for (ll i = 0; i < n; i++) {
        c[i] = complex<double>(a[i], 0);
        d[i] = complex<double>(b[i], 0);
    }
    
    fft(c, false), fft(d, false);
    for (ll i = 0; i < n; i++) {
        c[i] *= d[i];
    }
    fft(c, true);
    vector<ll> res(n);
    for (ll i = 0; i < n; i++) 
    {
        res[i] = (ll)(c[i].real() / n + 0.5);
    }
    ll carry = 0;
    for (ll i = 0; i< n; i++) 
    {
    	res[i] += carry;
    	carry = res[i] / 10;
    	res[i] %= 10;
	}
	while (res.size() > 1 && res.back() == 0) 
    {
    	res.pop_back();
	}
	return res;
}
vector<ll> to_vector(string s) 
{
	vector<ll> res;
	for (ll i = s.size() - 1; i >= 0; i--) {
		res.push_back(s[i] - '0');
	}
	return res;
}
string to_string(vector<ll> a) {
	string res;
	for (ll i = a.size() - 1; i >= 0; i--) {
		res += to_string(a[i]);
	}
	return res;
}

int main() 
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s1, s2;
    ll t;
    cin>>t;
    while(t--)
    {
        cin >> s1 >> s2;
        vector<ll> a = to_vector(s1), b = to_vector(s2);
        vector<ll> c = multiply(a, b);
        cout << to_string(c) << '\n';
    }
	return 0;
}