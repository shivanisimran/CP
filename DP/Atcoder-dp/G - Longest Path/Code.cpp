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
vector<int> adj[100005];
int n,m;
int dist[100005],dp[100005];

int dfs(int x){
   if(dp[x]!=-1)  return dp[x];
    if(adj[x].size()==0)  return dp[x]=0;

    for(int j: adj[x])  {
   
       dp[x]=max(dp[x],dfs(j)+1);
      // dfs(j);
    }
    return dp[x];
}

void solve(){ 
   cin>>n>>m;
   int x,y;
   while(m--){
      cin>>x>>y;
      adj[x].pb(y);
   }
   memset(dp, -1 ,sizeof dp);
   //for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
  
   for(int i=1;i<=n;i++)   dfs(i);
    
   int ans=0;
   for(int i=1;i<=n;i++) ans=max(ans,dp[i]);

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
   cout.tie(NULL);
   
   int t;    t=1;
   //cin>>t;
   
   while(t--) solve();
   
   return 0;
} 
