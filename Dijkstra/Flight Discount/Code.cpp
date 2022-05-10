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
 
vector<pair<ll,ll>> adj[100005];
vector<pair<ll,ll>> inv[100005];
 
void dijkstra(int n,int src,vector<ll>& dist,vector<pair<ll,ll>>adj[]){
 
   dist[src]=0;
  
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
   pq.push({0,src});
 
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
}
 
void solve(){
   ll n,m;
   cin>>n>>m;
 
   ll a,b,c;
   
   while(m--){
      cin>>a>>b>>c;
      adj[a].pb({b,c});
      inv[b].pb({a,c});
   }
 
   vector<ll>dist1(n+1,1e14+5);
   vector<ll>dist2(n+1,1e14+5);
 
   dijkstra(n,1,dist1,adj);
   dijkstra(n,n,dist2,inv);
  
   
   //for(int i=1;i<=n;i++)  cout<<dist1[i]<<" ";
   ll ans=1e14+5;
 
   for(int i=1;i<=n;i++){
      for(auto j:adj[i]){
         int x=i,y=j.first,w=j.second;
         ans=min(ans, dist1[x]+w/2+dist2[y]);
      }
   }
 
   cout<<ans;
 
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
