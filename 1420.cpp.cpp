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
#define mod         1000000007
#define ull         unsigned long long int
#define f(i,k,n)    for(ll i=k;i<n;i++)
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
int dr[]={2, 2, -2, -2, 1, -1, 1, -1};
int dc[]={1,-1,  1, -1, 2,  2,-2, -2};
int dr1[]={0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[]={-1,0, 1,-1, 0, 1, -1, 0,   1};
int dr2[]={0, 0, 1, -1};
int dc2[]={1,-1, 0,  0};
////////////////////////////
using namespace std;

#define ma 30000002
ll dp[102][102][102];
string t,t1,t2;

vector<ll>adj[30],adj1[30];

ll sub(ll x,ll x1,ll x2)
{
if(x2==t2.sz)return 1;
if(x>t.sz&&x1>t1.sz)return 0;

ll &r=dp[x][x1][x2];
if(r!=-1)return r;

ll p=t2[x2]-'a';

r=0;
ll i,t=-1,t1=-1;
if(adj[p].sz>0)
{
for(i=0;i<adj[p].sz;i++)
{
 ll p1=adj[p][i];
 if(p1>x)
 {
  t=p1;
  break;
 }
}
}
if(adj1[p].sz>0)
{
for(i=0;i<adj1[p].sz;i++)
{
 ll p1=adj1[p][i];
 if(p1>x1)
 {
  t1=p1;
  break;

 }

}
}
r=0;
//cout<<t<<" "<<t1<<endl;

if(t!=-1)r=sub(t,x1,x2+1)+sub(t,x1,x2);
r%=mod;
if(t1!=-1)r+=sub(x,t1,x2+1)+sub(x,t1,x2);
r%=mod;
if(t!=-1&&t1!=-1)
{
 r=(r-(2*sub(t,t1,x2+1))%mod-sub(t,t1,x2)+2*mod)%mod;
}



return r;

}



int main()
{
 ll tc,cas=0;
 ent(tc);

 while(tc--)
 {
  cin>>t>>t1>>t2;

  f(i,0,t.sz)
  {
   adj[t[i]-'a'].pb(i+1);
  }

  f(i,0,t1.sz)adj1[t1[i]-'a'].pb(i+1);
  memset(dp,-1,sizeof(dp));

  ll ans=sub(0,0,0);

  f(i,0,26)
  {
   adj[i].clr;
   adj1[i].clr;
  }


  pf("Case %lld: %lld\n",++cas,ans);

 }


 return 0;

}
