#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll parent[100000];
vector<ll> members(100000);

ll find_parent(ll n)
{
    while(n!=parent[n])
    {
        n=parent[n];
    }
    return n;
}

int main()
{
    ll n,m,a,b;
    cin>>n>>m;

    for(ll i=1;i<=n;i++) parent[i]=i,members[i]=1;
    members[0]=0;
    while(m--)
    {
        cin>>a>>b;
        ll x=find_parent(a);
        ll y=find_parent(b);
        if(x!=y) 
        {
            if(members[x]<members[y])
            {
                parent[x]=parent[y];
                members[y]+=members[x];
                members[x]=0;
            }
            else
            {
                parent[y]=parent[x];
                members[x]+=members[y];
                members[y]=0;
                
            }
        }
    }
    ll ans=1;
    for(ll i=1;i<=n;i++)
    {
        if(members[i]!=0) ans*=members[i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
