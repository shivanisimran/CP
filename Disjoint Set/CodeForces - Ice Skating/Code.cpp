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
   for(int i=1;i<=1000;i++){
      par[i]=i;ran[i]=0;
   }
   
   unordered_map<int,vector<int>> x1,y1;
   
   vector<vector<int>> v;
   int x,y,c=0;

   for(int i=0;i<n;i++){
      cin>>x>>y;
      v.pb({x,y});
      
      if(x1[x].size()!=0)  uni(x1[x][0],i);
      if(y1[y].size()!=0)  uni(y1[y][0],i);



      x1[x].pb(i);
      y1[y].pb(i);

   }

   for(int i=0;i<n;i++)  if(par[i]==i)  c++;

   

   cout<<c-1<<endl;

}
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;    t=1;
   //cin>>t;
 
   while(t--) solve();
   
   return 0;
} 
