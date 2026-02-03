#include <bits/stdc++.h>
using namespace std;
#define eps 0.000001
class Point
{
    public:
        double x, y;
        Point(double x = 0, double y = 0):x(x),y(y) {}
        Point operator + (Point a)
        {
            return Point(a.x + x,a.y + y);
        }
        Point operator - (Point a)
        {
            return Point(x - a.x, y - a.y);
        }
        bool operator < (const Point &a) const
        {
            if(x ==a.x)
                return y < a.y;
            return x < a.x;
        }
};

typedef Point Vector;

double cross(Vector a,Vector b)//  叉积
{
    return a.x*b.y - a.y*b.x;
}

double dot(Vector a,Vector b) // 点积 
{
    return a.x* b.x + a.y*b.y;
}

bool isclock(Point p0,Point p1,Point p2) //是不是凸多边形,顺时针
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b) < -eps) return true;
    return false;
}

double getDistance(Point a,Point b)
{
    return sqrt(pow(a.x-b.x,2)+pow(a.y - b.y,2));
}

typedef vector<Point> Polygon;
Polygon andrewScan(Polygon s)
{
    Polygon u,l;
    if(s.size()<3) return s;
    sort(s.begin(),s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);
    printf("l[n-2]:%.2f %.2f\nl[n-1]:%.2f %.2f\n",l[l.size()-2].x,l[l.size()-2].y,l[l.size()-1].x,l[l.size()-1].y);
    for(int i = 2 ; i < s.size() ; i++) //创建凸包上部
    {
        for(int n = u.size() ; n >= 2 && isclock(u[n-2],u[n-1],s[i])!=true; n--)
        {
            cout<<u[n-2].x<<' '<<u[n-2].y<<'\n'<<u[n-1].x<<u[n-1].y<<endl;
            u.pop_back();
        }
        u.push_back(s[i]);
    }
    for(int i = s.size() - 3 ; i >= 0 ; i--) //创建凸包下部
    {
        cout<<i<<endl;
        for(int n = l.size() ; n >=2 && isclock(l[n-2],l[n-1],s[i])!=true ; n--)
        {
            cout<<i<<endl;
            printf("del:\nl[n-2]:%.2f %.2f\nl[n-1]:%.2f %.2f\n",l[n-2].x,l[n-2].y,l[n-1].x,l[n-1].y);

            l.pop_back();
        }

        l.push_back(s[i]);
    }
//    for(auto &p : u) printf("%.2f %.2f\n",p.x,p.y);
//    printf("yes\n");
//    for(auto &p : l) printf("%.2f %.2f\n",p.x,p.y);

    for(int i = 1 ; i < u.size() - 1 ; i++) l.push_back(u[i]);//连接凸包上部和下部，得到凸包点集
    return l;
}
