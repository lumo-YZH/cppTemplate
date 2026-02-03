#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

class Point
{
    public:
        double x,y;
        Point(double x = 0,double y = 0):x(x),y(y) {}
        Point operator + (Point a)
        {
            return Point(x + a.x, y + a.y);
        }
        Point operator - (Point a)
        {
            return Point(x - a.x, y - a.y);
        }
        bool operator < (const Point &a) const
        {
            if(x == a.x) return y < a.y;
            return x < a.x;
        }
};

typedef vector<Point> Polygom;
typedef Point Vector;

double cross(Vector a,Vector b)
{
    return a.x*b.y - a.y*b.x;
}

bool isclock(Point p0,Point p1,Point p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b)< 0) return true;
    return false;
}

double getArea(Polygom a)//求凸包面积
{
    double ans = 0;
    for(int i = 1 ; i < a.size() - 1 ; i++)
    {
        Vector x1 = a[i] - a[0];
        Vector x2 = a[i+1] - a[0];
        ans+=abs(cross(x1,x2));
    }
    return ans;
}

Polygom andrewScan(Polygom s)//创建凸包
{
    Polygom u,l;
    if(s.size() < 3) return s;
    sort(s.begin(),s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);

    for(int i = 2 ; i < s.size() ; i++)
    {
        for(int n = u.size() ; n >= 2 && isclock(u[n-2],u[n-1],s[i])!=true ; n--)
            u.pop_back();
        u.push_back(s[i]);
    }

    for( int i = s.size() - 3 ; i >= 0 ; i--)
    {
        for(int n = l.size() ; n >= 2 && isclock(l[n-2],l[n-1],s[i])!= true ;n--)
            l.pop_back();
        l.push_back(s[i]);
    }

    for(int i = 1 ; i < l.size() - 1 ; i++) u.push_back(l[i]);
    return u;
}

void solve(void)
{
    int n;
    Polygom a;
    scanf("%d",&n);
    while(n--)
    {
        Point q;
        scanf("%lf%lf",&q.x,&q.y);
        a.push_back(q);
    }
    a = andrewScan(a);
    printf("%d",(int)getArea(a)/100);
}


int main(void)
{
    solve();
    return 0;
}