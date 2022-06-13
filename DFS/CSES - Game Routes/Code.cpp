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
vector<int> adj[100004];
ll dp[100004];
 
 
int dfs(int x,int n) {
   if(x==n)  return 1;
   if(dp[x]!=-1)  return dp[x];
 
   ll ans=0;
   for(int j: adj[x])  (ans+=dfs(j,n))%=mod;
 
   return dp[x] = ans;
}
 
void solve(){
   int n,m;
   cin>>n>>m;
 
   memset(dp,-1,sizeof dp);
 
   int a,b;
   while(m--){
      cin>>a>>b;
      adj[a].pb(b);
   }
 
   cout<<dfs(1,n); 
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
