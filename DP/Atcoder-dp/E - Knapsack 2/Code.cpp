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
ll n,w;
ll val[105], wt[105];
ll dp[100005][105];
//unordered_map<int, unordered_map<int,int>> dp;
 
 
//'i' indicates the current index we are at.
ll knp(ll v, ll i){
   if(v<=0)  return 0;
   if(i==n){
      return INT_MAX;
   }
   if(dp[v][i]!=-1)  return dp[v][i];
 
   return dp[v][i] = min(wt[i]+knp(v-val[i],i+1), knp(v,i+1)) ;
  
   
}
 

void solve(){ 
   cin>>n>>w;
   for(int i=0;i<n;i++){
      cin>>wt[i]>>val[i];
   }
   memset(dp,-1,sizeof(dp));
  
   for (int i = 100000; i >= 0; i--) {
      if (knp(i,0) <= w) {
         cout<<i;
         return;
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
   
   int t;    t=1;
   //cin>>t;
   
   while(t--) solve();
   
   return 0;
} 
