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
const int N=1e5;
const int mod=1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    stack<int> st;
    vi l(n,-1),r(n,n),ans(n+1,0);

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            l[i]=st.top();
        }
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            r[i]=st.top();
        }
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=0;i<n;i++)
    {
        int len=r[i]-l[i]-1;
        ans[len]=max(ans[len],a[i]);
    }

    for(int i=n-1;i>=1;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }

    for(int i=1;i<=n;cout<<" ",i++) 
    {
        cout<<ans[i];
    }

    return 0;
}