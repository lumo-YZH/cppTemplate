#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
float area(db x1,db x2,db x3,db y1,db y2,db y3) 
{
    float a,b,c,p,area;
    a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
    b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)); 
    c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)); 
    p=(a+b+c)/2;
    area=sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}
float point[1000][2];         
float point2[1000][2];       
int main()
 {
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;                    
    ll locat;                    
    float x1, x2, x3, y1, y2, y3; 
    float k1, k2,comp;                 
 	while(cin>>n)
 	{
 		float S = 0; 
 		if(n==0)
 			break;
	    for (ll i =n-1; i>=0;--i) 
		{
	        for (ll j = 0; j < 2; j++) 
			{
	            cin>>point[i][j]; 
	        }
	    }
	    comp=point[0][1]; 
	    locat=0;      
	    for (ll k = 1; k <n; k++) 
		{
	        if (point[k][1]<comp) 
	            locat=k;
	    }
	    for (ll s=0;s<(n- locat);s++) 
		{ 
	        for (ll t = 0; t < 2; t++) 
	            point2[s][t] = point[s + locat][t];
	    }
	    for (ll p = 0; p < locat; p++) 
		{ 
	        for (ll q = 0; q < 2; q++) 
	            point2[n- locat + p][q] = point[p][q];
	    }
	    x1 = point2[0][0]; 
	    y1 = point2[0][1]; 
	    for (ll u = 0; u < (n- 2);u++) 
		{ 
	        x2 = point2[u + 1][0]; 
	        y2 = point2[u + 1][1]; 
	        x3 = point2[u + 2][0]; 
	        y3 = point2[u + 2][1]; 
	        if ((x1 == x2) &&(x1 == x3)) 
	            continue;                   
	        else if (x1 == x2) 
			{          
	            k2 = (y3 - y1) / (x3 - x1); 
	            if (k2 <0) 
				{ 
	                S-=area(x1, x2, x3, y1, y2, y3); 
	            } else 
				{                                              
	                S+=area(x1, x2, x3, y1, y2, y3); 
	            }
	        } else if (x1 == x3) 
			{         
	            k1 = (y2 - y1) / (x2 - x1); 
	            if (k1 >0) 
				{ 
	                S-=area(x1, x2, x3, y1, y2, y3); 
	            } else {                                              
	                S+=area(x1, x2, x3, y1, y2, y3); 
	            }
	        } 
			else 
			{                       
	            k1=(y2 - y1)/(x2 - x1); 
	            k2=(y3 - y1)/(x3 - x1); 
	            if (k1 > 0 && k2 < 0) 
				{    
	                S-=area(x1,x2,x3,y1,y2,y3); 
	            } else if (k1 < 0 && k2 < 0) 
				{ 
	                if (k1 < k2) 
	                    S-=area(x1, x2, x3, y1, y2,y3);
	                else 
	                    S+=area(x1, x2, x3, y1, y2,y3); 
	            } 
				else if (k1 > 0 && k2 > 0) 
				{ 
	                if (k1 < k2) 
	                    S-=area(x1, x2, x3, y1, y2,y3); 
	                else 
	                    S+=area(x1, x2, x3, y1, y2,y3); 
	       		}
	            else 
	                S+=area(x1, x2, x3, y1, y2, y3); 
	        }
	    }
	    cout<<fixed<<setprecision(1)<<S<<'\n';
	}
    return 0;
}

