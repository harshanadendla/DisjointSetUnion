//antha ok....idea..implementation...antha pattesa....chandalanga lastlo min span tree ani gurtu pattala...just 
//simple ga anni add chsi padesa. min span tree sum adigithe...sumOfAll+(numberOfNodes-2)*minV

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct node
{
    ll id,members,cost;
};

node parent[100000];

ll find(ll n)
{
    while(n!=parent[n].id) n=parent[n].id;
    return n;
}

ll min(ll a,ll b)
{
    return a<b ? a : b;
}

int main()
{
    ll n,m,a,b,x,y,fee;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
        parent[i].cost=-1;
    }
    while(m--)
    {
        cin>>a>>b;
        x=find(a);
        y=find(b);
        if(x!=y)
        {
            if(parent[x].members<parent[y].members)
            {
                parent[x].id=parent[y].id;
                parent[y].members+=parent[x].members;
                parent[x].members=0;
            }
            else
            {
                parent[y].id=parent[x].id;
                parent[x].members+=parent[y].members;
                parent[y].members=0;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>fee;
        if(fee<0) continue;
        x=find(i);
        if(parent[x].cost==-1)
        {
            parent[x].cost=fee;
        }
        else
        {
            if(parent[x].cost>fee) parent[x].cost=fee;   
        }
    }
    ll count=0;
    fee=0;
    bool flag=false;
    ll minC=LLONG_MAX;
    for(ll i=1;i<=n;i++)
    {
        if(i==parent[i].id) count++;
    }
    if(count==1) 
    {
        cout<<"0\n";
        goto there;
    }
    for(ll i=1;i<=n;i++)
    {
        if(i==parent[i].id)
        {
            if(parent[i].cost<0)
            {
                flag=true;
                break;
            }
            else
            {
                minC=min(minC,parent[i].cost);
                fee+=parent[i].cost;
            }
        }
    }
    if(flag) cout<<"-1\n";
    else cout<<(fee+(count-2)*minC)<<"\n";
    there:;
    return 0;
}
