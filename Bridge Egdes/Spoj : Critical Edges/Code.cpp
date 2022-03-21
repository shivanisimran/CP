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
vector<int>adj[701];
vector<int> vis;
vector<int> tin, low;
vector<pii>bridge;
int c,k=1;
 
void dfs(int x,int p){
   vis[x]=1;
   tin[x]=low[x]=c++;
   for(int j: adj[x]){
      if(j==p)  continue;
      if(vis[j])  low[x]=min(low[x],tin[j]);
      else{
         dfs(j,x);
         low[x]=min(low[x],low[j]);
         if(low[j]>tin[x]){
            bridge.pb({min(x,j),max(x,j)});
         }
      }
   }
}
void solve(){ 
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++) adj[i].clear();
   
   int x,y;
   while(m--){
      cin>>x>>y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   vis=vector<int>(n+1,0);
   low=vector<int>(n+1,-1);
   tin=vector<int>(n+1,-1);
   bridge.clear();
 
   cout<<"Caso #"+to_string(k++)<<endl;
   c=0;
   for(int i=1;i<=n;i++){
      if(!vis[i])  dfs(i,-1);
   }
   if(bridge.size()==0){
       cout<<"Sin bloqueos"<<endl;
   }
  
   else{
      cout<<bridge.size()<<endl;
       sort(bridge.begin(),bridge.end());
      for(auto i: bridge){
         cout<<i.first<<" "<<i.second<<endl;
      }
   }
   
 
}
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int t;    //t=1;
   cin>>t;
   
   while(t--)   solve();
   
   return 0;
}  
