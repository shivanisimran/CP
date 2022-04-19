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
   string s1,s2;
   cin>>s1>>s2;
   
  // dp[0][0]=0;
   int n1=s1.length(),n2=s2.length();
 
   int dp[n1+1][n2+1];
 
   for(int i=0;i<=n1;i++){
      for(int j=0;j<=n2;j++){
         if(j==0)  dp[i][j]=i;
         else if(i==0)  dp[i][j]=j;
         else if(s1[i-1]==s2[j-1])   dp[i][j]=dp[i-1][j-1];
         else  dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
      }
      
   }
   cout<<dp[n1][n2];
 
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
