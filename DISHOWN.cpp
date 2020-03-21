#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e4+1;
const int mod=1e9+7;

struct ds
{
    int id,val;
}parent[N];

int t,n,a,b,q,type;

int find(int u)
{
    if(u==parent[u].id) return u;
    return parent[u].id=find(parent[u].id);
}

void unioN(int x,int y)
{
    x=find(x);
    y=find(y);

    if(x==y) cout<<"Invalid query!\n";

    else 
    {
        if(parent[x].val<parent[y].val) parent[x].id=parent[y].id;
        else if(parent[x].val>parent[y].val) parent[y].id=parent[x].id;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            parent[i].id=i;
            cin>>parent[i].val;
        }

        cin>>q;

        for(int i=0;i<q;i++)
        {
            cin>>type;

            if(type==0)
            {
                cin>>a>>b;
                unioN(a,b);
            }
            else
            {
                cin>>a;
                cout<<find(a)<<"\n";
            }
        }
    }

    return 0;
}