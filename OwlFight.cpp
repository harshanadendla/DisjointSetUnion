// manchi sum....logic pattesa....correct implementation pattesa....but....node pass chesi..rewrte chesesa....debugging konchem 
// exp vachindi...debugginh correct ga cheykapothe fasak...last lo queries kooda sarigga max value ni sustain chestamani marchipoya
// oka data strucutre anukunnappudu....danini ela enduku alagee anukunnamo...dani use eppudu vastundo gurtunchukovali...
// rethink every damn step if your code.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

struct node
{
    int id,str,members;
};

node parent[100000];

int find(int n)
{
    while(n!=parent[n].id) n=parent[n].id;
    return parent[n].id;
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int n,m,a,b,q,x,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
        parent[i].str=i;
    }
    while(m--)
    {
        cin>>a>>b;
        x=find(a);
        y=find(b);
        if(parent[x].id!=parent[y].id)
        {
            if(parent[x].members<parent[y].members)
            {
                parent[x].id=parent[y].id;
                parent[y].members+=parent[x].members;
                parent[x].members=0;
                parent[y].str=max(parent[y].str,parent[x].str);
            }
            else
            {
                parent[y].id=parent[x].id;
                parent[x].members+=parent[y].members;
                parent[y].members=0;
                parent[x].str=max(parent[x].str,parent[y].str);
            }
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        x=find(a);
        y=find(b);
        if(x==y) cout<<"TIE\n";
        else
        {
            if(parent[x].str<parent[y].str)
            {
                cout<<b<<"\n";
            }
            else
            {
                cout<<a<<"\n";
            }
        }
    }
    return 0;
}
