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
   int n,x;
    cin>>n>>x; 
 
    vector<int> pages(n),price(n);
    int dp[1001][100001];
    memset(dp,0,sizeof dp);
 
 
  
   for(int i=0;i<n;i++)  cin>>price[i];
   for(int i=0;i<n;i++)  cin>>pages[i];
 
   for(int i=1;i<=n;i++){
 
      for(int j=0;j<=x;j++){
 
          if(j==0)  dp[i][j]=0;
          dp[i][j]=dp[i-1][j];
          if(price[i-1]<=j){
            dp[i][j]=max(pages[i-1]+dp[i-1][j-price[i-1]], dp[i][j]);
          }
            
          
      }
   }
   
   cout<<dp[n][x];
 
   
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
