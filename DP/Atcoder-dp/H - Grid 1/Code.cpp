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

int h,w;
char g[1003][1003];

ll dp[1002][1002];


void solve(){ 
   cin>>h>>w;
   //cout<<h<<" "<<w;
   for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
         cin>>g[i][j];
        // cout<<g[i][j];
      }
   }

   dp[0][0]=1;
   for(int i=1;i<w;i++){
      if(g[0][i]=='#')  dp[0][i]=0;
      else dp[0][i]=dp[0][i-1];
   }
   for(int i=1;i<h;i++){
      if(g[i][0]=='#')  dp[i][0]=0;
      else dp[i][0]=dp[i-1][0];
   }

   for(int i=1;i<h;i++){
      for(int j=1;j<w;j++){
         if(g[i][j]=='#')  dp[i][j]=0;
         else (dp[i][j]=dp[i-1][j]+dp[i][j-1])%=mod;
      }
   }

   cout<<dp[h-1][w-1];
   
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
