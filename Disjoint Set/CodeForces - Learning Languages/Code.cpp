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

 
int ran[101],par[101];

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
   int n,m,c=0,c1=0;  
   cin>>n>>m;

   set<int> s;
  
   for(int i=1;i<=m;i++) {
      ran[i]=0; par[i]=i;
   }

   vector<vector<int>> v(n+1);
   for(int i=0;i<n;i++){
      int k;
      cin>>k;
      int x;
      while(k--){
         cin>>x;
         v[i].pb(x);
         s.insert(x);
      }
   }

   for(int i=0;i<n;i++){
      if(v[i].size()==0)  c++;
      else{
         for(int j=1;j<v[i].size();j++) {
           //cout<<v[i][j]<<" ";
            uni(v[i][j-1],v[i][j]);
         } 
         //cout<<endl;
      }
   }
   
  // for(int i : s) cout<<i<<" "<<findpr(i)<<endl;
   for(int i : s)  if(findpr(i)==i)  c1++;
   if(c1>0)  c1--;

   cout<<c+c1;
   

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
