/*
  kruskal 
  disjoint set
  minimal spanning tree
*/
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

struct Point
{
    double x;
    double y;
};



Point points[110];
double w[10010];
int u[10010],v[10010]; // we have 100 vetice
int r[10010],p[10010]; // so we may have over 10000 edge 


double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


bool cmp(const int i, const int j)// very tricky comparison
{
    return w[i]<w[j];
}


int find(int x)
{
    if(p[x]==x)
	return x;
    else
    {
	p[x] = find(p[x]);
	return p[x];
    }
}

double kruskal(int num)
{
    double ans = 0;

    for(int i = 0;i<num;++i)
    {
	p[i] = i;
    }


    // initialize and sort the list
    for(int i = 0;i<num;++i)
    {
	r[i] = i;
    }
    
    sort(r, r+num, cmp);

    for(int i = 0;i<num;++i)
    {
	int index = r[i];
	int x = find(u[index]);
	int y = find(v[index]);
	
	if(x!=y)
	{
	    ans += w[index];
	    p[y] = x;
	}
    }
    
    return ans;
}


int main()
{
    int n;
    scanf("%d",&n);

    // read in all point
    for(int i = 0;i<n;++i)
    {
	scanf("%lf %lf",&points[i].x,&points[i].y);
    }

    int k = 0;
    // compute the edge
    for(int i = 0;i<n;++i)
    {
	for(int j = 0;j<n;++j)
	{
	    u[k] = i;
	    v[k] = j;
	    w[k] = dist(points[i],points[j]);
	    k++;
	}
    }

    printf("%.2lf\n",kruskal(n*n));
}
