#include <bits/stdc++.h>
using namespace std;
#define eps 0.000001
class Point
{
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(Point a)
    {
        return Point(a.x + x, a.y + y);
    }
    Point operator-(Point a)
    {
        return Point(x - a.x, y - a.y);
    }
    bool operator<(const Point &a) const
    {
        if (x == a.x)
            return y < a.y;
        return x < a.x;
    }
};

typedef Point Vector;

double cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

bool isclock(Point p0, Point p1, Point p2)
{
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) < -eps)
        return true;
    return false;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

typedef vector<Point> Polygon;
Polygon andrewScan(Polygon s)
{
    Polygon u, l;
    if (s.size() < 3)
        return s;
    sort(s.begin(), s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);
    for (int i = 2; i < s.size(); i++)
    {
        for (int n = u.size(); n >= 2 && isclock(u[n - 2], u[n - 1], s[i]) != true; n--)
            u.pop_back();
        u.push_back(s[i]);
    }
    for (int i = s.size() - 3; i >= 0; i--)
    {
        for (int n = l.size(); n >= 2 && isclock(l[n - 2], l[n - 1], s[i]) != true; n--)
            l.pop_back();
        l.push_back(s[i]);
    }
    // printf("yes\n");
    reverse(l.begin(), l.end());
    // for(auto &p : u) printf("%.2f %.2f\n",p.x,p.y);
    // printf("down\n");
    // for(auto &p : l) printf("%.2f %.2f\n",p.x,p.y);
    for (int i = u.size() - 2; i >= 1; i--)
        l.push_back(u[i]);
    return l;
}

int main(void)
{
    int n;
    while (scanf("%d", &n), n)
    {
        Polygon a;
        for (int i = 0; i < n; i++)
        {
            Point t;
            scanf("%lf%lf", &t.x, &t.y);
            a.push_back(t);
        }
        a = andrewScan(a);
        // printf("yes\n");
        double ans = 0;
        ans += getDistance(a[1], a[0]);
        for (int i = 1; i < a.size() - 1; i++)
        {
            ans += getDistance(a[i + 1], a[i]);
        }
        ans += getDistance(a[0], a[a.size() - 1]);
        if (n != 2)
            printf("%.2f\n", ans);
        else
            printf("%.2f\n", ans / 2);
    }
    return 0;
}
