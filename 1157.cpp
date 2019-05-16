/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define pf          printf
#define sf          scanf
#define ff          first
#define ss          second
#define clr         clear()
#define sz          size()
#define pb          push_back
#define mk          make_pair
#define pi          acos(-1)
#define inf         9999999999999999
#define mod         1000007
#define ull         unsigned long long int
#define f(i,k,n)    for(i=k;i<n;i++)
#define fr(i,n,k)   for(i=n;i>=k;i--)
#define ent(a)      scanf("%lld",&a)
#define ent2(a,b)   scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a)      memset(a,0,sizeof(a))
#define vec(v,s)    vector<ll>v[s]
#define arr(a,s)    ll a[s];
//#define check(n,pos) (n&(1<<pos))
//#define set(n,pos)  (n|(1<<pos))
//knight and king//
int dr[]={2,2,-2,-2,1,-1,1,-1};
int dc[]={1,-1,1,-1,2,2,-2,-2};
int dr1[]={0,0,1,1,1,-1,-1,-1};
int dc1[]={1,-1,1,0,-1,0,1,-1};
int dr2[]={0,0,1,-1};
int dc2[]={1,-1,0,0};
////////////////////////////
using namespace std;
#define ma 1005

vector<ll>adj[30],adj1[30];

ll dp[ma][ma],dp1[ma][ma],dp2[ma][ma];

ll pos[27][ma],pos1[27][ma];

ll get(ll x,ll y)
{
 ll i;
 if(dp[x][y]==dp1[1][1])return 1;

 ll &r=dp2[x][y];
 if(r!=-1)return r;
 r=0;

 for(i=0;i<26;i++)
 {
  ll p=pos[i][x+1];
  ll p1=pos1[i][y+1];
  if(p==0||p1==0)continue;
  ll k=dp[x][y]+dp1[p][p1];
  if(k==dp1[1][1])r+=get(p,p1);
  r%=mod;

 }
 return r;



}

int main()
{
 ll tc,i,j,cas=0;
 string t,t1;
 cin>>tc;

 while(tc--)
 {
  cin>>t>>t1;
  ll st=t.sz;
  ll st1=t1.sz;

  mem(dp);
  mem(dp1);
  mem(pos);
  mem(pos1);

  for(i=0;i<t.sz;i++)
  {
   for(j=0;j<t1.sz;j++)
   {
    if(t[i]==t1[j])dp[i+1][j+1]=dp[i][j]+1;
    else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
   }
  }

  for(i=t.sz-1;i>=0;i--)
  {
   for(j=t1.sz-1;j>=0;j--)
   {
    if(t[i]==t1[j])dp1[i+1][j+1]=1+dp1[i+2][j+2];
    else dp1[i+1][j+1]=max(dp1[i+1][j+2],dp1[i+2][j+1]);
   }
  }

  for(i=0;i<st;i++)
  {
   ll p=t[i]-'a';
   pos[p][i+1]=i+1;
  }

  for(i=0;i<st1;i++)
  {
   ll p=t1[i]-'a';
   pos1[p][i+1]=i+1;
  }

  for(i=0;i<26;i++)
  {
   for(j=st;j>=1;j--)
   {
    if(pos[i][j]==0)pos[i][j]=pos[i][j+1];
   }
   for(j=st1;j>=1;j--)
   {
    if(pos1[i][j]==0)pos1[i][j]=pos1[i][j+1];
   }
  }
  memset(dp2,-1,sizeof(dp2));

  ll ans=get(0,0);

  pf("Case %lld: %lld\n",++cas,ans);








 }

 return 0;
}

