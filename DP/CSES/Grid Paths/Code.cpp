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
 
 
void solve(){
   ll n;
   cin>>n;
   char g[n][n];
 
   ll dp[n][n]={0};
 
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)  cin>>g[i][j];
   }
   if(g[0][0]=='*')   dp[0][0]=0;
   else  dp[0][0]=1;
 
   for(int i=1;i<n;i++) { 
      if(g[0][i]=='*')  dp[0][i]=0;
      else  dp[0][i]=dp[0][i-1];
   }
 
   for(int i=1;i<n;i++)  {
      if(g[i][0]=='*')  dp[i][0]=0;
      else  dp[i][0]=dp[i-1][0];
   }
 
   for(int i=1;i<n;i++){
      for(int j=1;j<n;j++){
         if(g[i][j]=='*')  dp[i][j]=0;
         else  (dp[i][j]=dp[i-1][j]+dp[i][j-1])%=mod;
      }
   }
   // for(int i=0;i<n;i++){
   //    for(int j=0;j<n;j++){
   //        cout<<dp[i][j]<<" ";  
   //    }
   //    cout<<endl;
   // }
      
   cout<<dp[n-1][n-1];
   
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
