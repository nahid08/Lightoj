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
#define ma 100005

ll tree[ma*3];

ll a[ma],dp[ma],dp1[ma],b[ma];
ll ans[ma];
void update(ll n,ll b,ll e,ll x, ll val)
{
 if(b==e)
 {
  tree[n]=max(tree[n],val);
  return ;
 }
 ll mid=(b+e)>>1,l=n*2,r=l+1;
 if(x<=mid)update(l,b,mid,x,val);
 else update(r,mid+1,e,x,val);
 tree[n]=max(tree[l],tree[r]);
}

ll query(ll n,ll b,ll e,ll x,ll y)
{
 if(e<x||b>y)return 0;

 if(b>=x&&e<=y)return tree[n];
 ll mid=(b+e)>>1,l=n*2,r=l+1;
 ll p=query(l,b,mid,x,y);
 ll p1=query(r,mid+1,e,x,y);
 return max(p,p1);
}



int main()
{
 ll tc,n,q,i,j,m,cas=0;
/* ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);*/
 cin>>tc;

 while(tc--)
 {
  ll cn=0;
  cin>>n>>q;

  vector<ll>v;

  map<ll,ll>mp;

  for(i=1;i<=n;i++)
  {
   cin>>a[i];
   v.pb(a[i]);
  }
  sort(v.begin(),v.end());

  for(i=0;i<v.sz;i++)if(mp[v[i]]==0)mp[v[i]]=++cn;

  for(i=1;i<=n;i++)
  {
   ll p=mp[a[i]];
   b[i]=a[i];
   a[i]=p;
  }
  mem(tree);

  ll max1=0;

  for(i=1;i<=n;i++)
  {
   ll p=query(1,1,cn,1,a[i]-1);
   dp[i]=p+1;
   max1=max(max1,dp[i]);
   update(1,1,cn,a[i],p+1);
  }
  mem(tree);
  for(i=n;i>=1;i--)
  {
   ll p=query(1,1,cn,a[i]+1,cn);
   dp1[i]=p+1;
   update(1,1,cn,a[i],p+1);

  }

  //for(i=1;i<=n;i++)cout<<dp[i]<<" "<<dp1[i]<<endl;
  cout<<"Case "<<++cas<<":"<<endl;

  while(q--)
  {
   cin>>m;

   if(m>max1)
   {
    cout<<"Impossible"<<endl;
    continue;
   }

   ll pre=0,cnt=m;

   for(i=1;i<=n;i++)
   {
    if(cnt>m)break;
    if(dp1[i]>=cnt&&a[i]>pre)
    {
     ans[m-cnt+1]=b[i];
     pre=a[i];
     cnt--;

    }

   }

   for(i=1;i<=m;i++)
   {
    cout<<ans[i];
    if(i<m)cout<<" ";
   }
   cout<<endl;
  }













 }

 return 0;
}
