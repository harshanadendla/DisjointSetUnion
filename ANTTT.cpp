// easyt sum ee....pattesa....kottaga nerchukundentante...to check if two line segments intersect

#include<bits/stdc++.h>
using namespace std;
#define int long long

struct point
{
    int x,y;
};

struct line
{
    point a,b;
};

struct node
{
    int id,rank;
};

line seg[1010];
node parent[1010];

bool onSegment(point p,point q,point r)
{
    if(q.x<=max(p.x,r.x) && q.x>=min(p.x,r.x) && q.y<=min(p.y,r.y) && q.y>=min(p.y,r.y)) return true;
    return false;
}

int orientation(point p,point q,point r)
{
    int val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
    return val==0 ? 0 : (val>0 ? 1 : 2);
}

bool intersect(point p1,point q1,point p2,point q2)
{
    int o1=orientation(p1,q1,p2);
    int o2=orientation(p1,q1,q2);
    int o3=orientation(p2,q2,p1);
    int o4=orientation(p2,q2,q1);

    if(o1!=o2 && o3!=o4) return true;

    if(o1==0 && onSegment(p1,p2,q1)) return true;
    if(o2==0 && onSegment(p1,q2,q1)) return true;
    if(o3==0 && onSegment(p2,p1,q2)) return true;
    if(o4==0 && onSegment(p2,q1,q2)) return true;

    return false;
}

int find(int n)
{
    while(n!=parent[n].id) n=parent[n].id;
    return n;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            parent[i].id=i;
            parent[i].rank=1;
            cin>>seg[i].a.x>>seg[i].a.y>>seg[i].b.x>>seg[i].b.y;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j && intersect(seg[i].a,seg[i].b,seg[j].a,seg[j].b))
                {
                    int x=find(i);
                    int y=find(j);
                    if(x!=y)
                    {
                        if(parent[x].rank<parent[y].rank)
                        {
                            parent[x].id=parent[y].id;
                            parent[y].rank+=parent[x].rank;
                            parent[x].rank=0;
                        }
                        else
                        {
                            parent[y].id=parent[x].id;
                            parent[x].rank+=parent[y].rank;
                            parent[y].rank=0;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            if(find(a)==find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
