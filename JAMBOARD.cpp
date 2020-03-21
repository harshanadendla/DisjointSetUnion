#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=6500001;
const int mod=1e9+7;

unordered_map<char,int> val={

    {'A',0},{'B',1},{'C',2},{'D',3},{'E',4},{'F',5},{'G',6},{'H',7},{'I',8},{'J',9},
    {'K',10},{'L',11},{'M',12},{'N',13},{'O',14},{'P',15},{'Q',16},{'R',17},{'S',18},{'T',19},
    {'U',20},{'V',21},{'W',22},{'X',23},{'Y',24},{'Z',25},

    {'a',26},{'b',27},{'c',28},{'d',29},{'e',30},{'f',31},{'g',32},{'h',33},{'i',34},{'j',35},
    {'k',36},{'l',37},{'m',38},{'n',39},{'o',40},{'p',41},{'q',42},{'r',43},{'s',44},{'t',45},
    {'u',46},{'v',47},{'w',48},{'x',49},{'y',50},{'z',51}
};

struct ds
{
    int id,members,high;
}parent[N];

int find(int u)
{
    if(u==parent[u].id) return u;
    return parent[u].id=find(parent[u].id);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    int n,r,c;
    cin>>n>>r>>c;

    for(int i=1;i<=r*c;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
        parent[i].high=0;
    }

    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s[0]=='W')
        {
            int x1,x2,y1,y2;

            x1=52*val[s[1]]+val[s[2]];
            x2=52*val[s[3]]+val[s[4]];
            y1=52*val[s[5]]+val[s[6]];
            y2=52*val[s[7]]+val[s[8]];

            int u=x1+c*((x2-1)/5);
            int v=y1+c*((y2-1)/5);

            int xset=find(u);
            int yset=find(v);

            if(xset==yset) continue;

            if(parent[xset].members<parent[yset].members)
            {
                parent[xset].id=parent[yset].id;
                parent[yset].members+=parent[xset].members;
                parent[yset].high+=parent[xset].high;
            }
            else
            {
                parent[yset].id=parent[xset].id;
                parent[xset].members+=parent[yset].members;
                parent[xset].high+=parent[yset].high;
            }
        }
        else if(s[0]=='V')
        {
            int x1,x2;

            x1=52*val[s[1]]+val[s[2]];
            x2=52*val[s[3]]+val[s[4]];

            int u=x1+c*((x2-1)/5);

            u=find(u);

            parent[u].high++;
        }
        else if(s[0]=='L')
        {
            int x1,x2,y1,y2;

            x1=52*val[s[1]]+val[s[2]];
            x2=52*val[s[3]]+val[s[4]];
            y1=52*val[s[5]]+val[s[6]];
            y2=52*val[s[7]]+val[s[8]];

            int u=x1+c*((x2-1)/5);
            int v=y1+c*((y2-1)/5);
            
            u=find(u);
            v=find(v);

            if((parent[u].high>0 && parent[v].high==0) || (parent[v].high>0 && parent[u].high==0)) cout<<"ON\n";
            else cout<<"OFF\n";
        }
        else
        {
            int x1,x2;

            x1=52*val[s[1]]+val[s[2]];
            x2=52*val[s[3]]+val[s[4]];

            int u=x1+c*((x2-1)/5);

            u=find(u);

            if(parent[u].high>0) parent[u].high--;
        }
    }

    return 0;
}