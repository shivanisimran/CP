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
vector<int> adj[10004];
int vis[10004],par[10004];
vector<int> ans;
 
bool cycle(int x){
   vis[x]=1;
   for(int j:adj[x]){
      if(j==x) continue;
      if(vis[j]==1)  return true;
      else if(!vis[j]){
         if(cycle(j))  return true;
      }  
   }
   ans.pb(x);
   vis[x]=2;
   return false;
}
 
 
void solve(){
   int n,m;
   cin>>n>>m;
 
   int a,b;
   while(m--){
      cin>>a>>b;
      adj[a].pb(b);
   }
 
   memset(vis,0,sizeof vis);
 
   for(int i=1;i<=n;i++){
      sort(adj[i].begin(),adj[i].end());
      reverse(adj[i].begin(),adj[i].end());
   }
 
   for(int i=n;i>=1;i--){
      if(!vis[i] && cycle(i)){
         cout<<"Sandro fails.";
         return;
      }
    
   }
   
   
   reverse(ans.begin(),ans.end());
   for(int i: ans)  cout<<i<<" ";
   
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
