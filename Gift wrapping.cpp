#include<bits/stdc++.h>
using namespace std;
#define INF 10000
 struct Point
{
        int x;
        int y;
};
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}
void convexHull(Point points[], int n)
{
    if (n < 3)
        return;
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
next[p] = q;
        p = q;
    }
    while (p != l);

    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
            }
}
int main()
{
Point *points;
int N;
cout << "Enter no of points N "<<endl;
cin>>N;
points=new Point[N];
for (int i = 0; i < N; i++)
{
  cin>>points[i].x>>points[i].y;
}
clock_t start;
double duration;
start = clock();
cout << "The points in the convex hull are: "<<endl;
convexHull(points, N);
duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
cout<<"time: "<<duration <<" seconds"<<endl;
return 0;
}
