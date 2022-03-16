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
ll dp[105][100005];
 
 
//'x' indicates the current index we are at.
ll knp(ll x, ll w){
   if(dp[x][w]!=-1)  return dp[x][w];
   if(x==n-1){
      if(wt[x]<=w)  return dp[x][w] = val[x];
      else return dp[x][w] = 0;
   }
   if(wt[x]<=w){
      return dp[x][w] = max(val[x]+knp(x+1,w-wt[x]), knp(x+1,w));
   }
   else return dp[x][w] =  knp(x+1,w);
}

void solve(){ 
   cin>>n>>w;
   for(int i=0;i<n;i++){
      cin>>wt[i]>>val[i];
   }
   memset(dp,-1,sizeof dp);
   cout<<knp(0,w);
   
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
