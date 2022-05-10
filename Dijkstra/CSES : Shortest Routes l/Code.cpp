#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1e9+7
#define pb push_back
#define pii pair<int,int>
#define endl '\n' 
//1<<X means 2^X 
  
//void precision(int n){cout<<fixed<<setprecision(n);} 
 
 
void solve(){
   ll n,m;
   cin>>n>>m;
 
   ll a,b,c;
   vector<pair<ll,ll>> adj[100005];
 
   while(m--){
      cin>>a>>b>>c;
      adj[a].pb({b,c});
   }
 
   vector<ll>dist(n+1,1e14+5);
   dist[1]=0;
  
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
   pq.push({0,1});
 
   vector<int> vis(n+1,0);
 
   while(!pq.empty()){
      auto k=pq.top();
      pq.pop();
 
      if(vis[k.second])  continue;
      vis[k.second]=1;
 
      for(auto i:adj[k.second]){
         ll w=i.second,j=i.first;
 
         if(dist[j]>k.first+w){
            dist[j]=k.first+w;
            pq.push({dist[j],j});
         }
      }
   }
 
   for(int i=1;i<=n;i++)  cout<<dist[i]<<" ";
 
 
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
