#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define endl '\n' 
//1<<X means 2^X 
  
//void precision(int n){cout<<fixed<<setprecision(n);}

ll mul(ll x, ll y){ll res=x*y; return res%mod;} 
ll p(ll x, ll y){ll res=1;x%=mod;while(y){if(y&1){res = mul(res,x);}y>>=1;x=mul(x,x);}return res;}

int n;
int ran[400001],par[400001];

int findpr(int x){
   if(par[x]==x)  return x;
   return par[x]=findpr(par[x]);
}

void uni(int a,int b){
   a=findpr(a);
   b=findpr(b);

   if(a!=b){
      if(ran[a]<ran[b])  swap(a,b);
      par[b]=a;
      if(ran[a]==ran[b])  ran[a]++;
   }


}

void solve(){  
   cin>>n;

   for(int i=1;i<=n;i++){
      par[i]=i;
      ran[i]=0;
   }

   int a[n],b[n];

   for(int i=0;i<n;i++)  cin>>a[i];
   for(int i=0;i<n;i++)  cin>>b[i];

   int c=0;
   for(int i=0;i<n;i++){
      int x=a[i],y=b[i];
      if(findpr(x)==findpr(y))  c++;
      else uni(x,y);
   }
   
  // cout<<c<<" ";
   cout<<p(2ll,c) <<endl;

}
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;    //t=1;
   cin>>t;
 
   while(t--) solve();
   
   return 0;
} 
