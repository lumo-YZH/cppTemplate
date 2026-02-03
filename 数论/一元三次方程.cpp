#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
void root(const float a,const float b,const float c,const float d,float x){
	
	float num=x,x0,f,f1;
	do
	{
	x0=x;
	f=((a*x0+b)*x0+c)*x0+d;
	f1=(3*a*x0+2*b)*x0+c;
	x=x0-f/f1;
	if(fabs(f1)<1e-6)
	{
		break;
	}	
	}while(fabs(x-x0)>1e-6);
	
	cout<<fixed << setprecision(2)<<x<<"\n";
	 
}
int main(){
	
	float a,b,c,d;
	while(cin>>a>>b>>c>>d)
    {
        for(int i=-100;i<=100;i++)
        {
            if((a*pow(i,3)+b*pow(i,2)+c*i+d)==0.00)
                cout<<fixed << setprecision(2)<<i*1.00<<"\n";
            else if((a*pow(i,3)+b*pow(i,2)+c*i+d)>0&&(a*pow(i+1,3)+b*pow(i+1,2)+c*(i+1)+d)<0)
                root( a,b,c, d, i);	
            else if((a*pow(i,3)+b*pow(i,2)+c*i+d)<0&&(a*pow(i+1,3)+b*pow(i+1,2)+c*(i+1)+d)>0)
                root( a,b,c, d, i);	
        }
    }
	return 0;
}
 
