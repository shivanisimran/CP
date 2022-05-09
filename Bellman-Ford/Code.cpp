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
 
struct edge{
   int a,b,cost;
};
 
void solve(){
   int n,m;
   cin>>n>>m;
 
   vector<edge> edges(m);
   int x,y,z;
 
   for(int i=0;i<m;i++){
      cin>>x>>y>>z;
      edges[i].a=x;
      edges[i].b=y;
      edges[i].cost=z;
 
   }
   vector<ll>d(n+1,INT_MAX);
   vector<int>p(n+1,-1);
 
   d[1]=0;
 
   for(int i=0;i<n-1;i++){
      for(edge e: edges){
         if(d[e.b]>d[e.a]+e.cost){
            d[e.b]=d[e.a]+e.cost;
            p[e.b]=e.a;
         }
      }
   }
   
   
  
   x=-1;
   for(edge e: edges){
      if(d[e.b]>d[e.a]+e.cost){
         d[e.b]=d[e.a]+e.cost;
         p[e.b]=e.a;
         x=e.b;
      }
   }
   
   
 
   if(x!=-1){
      cout<<"YES\n";
      for(int i=1;i<=n;i++) x=p[x];
      
      vector<int> c;
      int v=x;
      while(1){
 
         c.pb(v);
         if(v==x && c.size()>1)  break;
         v=p[v];
      }
      
      reverse(c.begin(),c.end());
      for(int i: c)  cout<<i<<" ";
      cout<<endl;
   }
   else cout<<"NO\n";
 
   
 
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
