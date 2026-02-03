#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll md=1e9+7;
string addStrings(string num1, string num2) 
{
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    std::string retstr;
    int carry = 0;
    retstr.reserve(end1 > end2 ? end1 : end2);
    while( end1 >= 0 || end2 >= 0)
    {
        int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
        int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
        int ret = val1 + val2 + carry;
        carry = ret / 10;
        ret = ret % 10;
        retstr += ('0' + ret);

        --end1;
        --end2;
    }
    if(carry != 0 )
        retstr += '1';
    reverse( retstr.begin(),  retstr.end());
    return retstr;
}
string bigMultiply(string a,string b){
	//开辟数组value
	vector<int> value(a.size()+ b.size(),0);
	//b取出1位分别与a的每一位相乘 
	for(int bIndex = b.size() - 1;bIndex >= 0;bIndex--){
		int curB = b[bIndex] - '0';
		int valueIndex = value.size() - (b.size() - bIndex); //从b这一位开始填充 
		for(int aIndex = a.size() - 1;aIndex >= 0;aIndex--){
			int curA = a[aIndex] - '0';
			value[valueIndex] += curA * curB;
			valueIndex--;
		}
	}
	//处理进位 
	int jinWei = 0;
	for(int i = value.size() - 1;i >= 0;i--){
		int curValue =(value[i] + jinWei) % 10;
		jinWei = (value[i] + jinWei) / 10;
		value[i] = curValue;
	}
	string ans = "";
	bool isZero = true;
	for(int i = 0;i < value.size();i++){
		if(value[i] != 0){
			isZero = false;
		}
		if(isZero == false){
			ans = ans + to_string(value[i]);
		}
	}
	return ans;
	
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,n;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        cout<<addStrings(a,b)<<'\n';
    }
}