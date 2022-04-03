#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define endl '\n' 
 

//void precision(int n){cout<<fixed<<setprecision(n);}
//1<<X means 2^X
 
void solve(){
   ll n;
   cin>>n;
   vector<ll>dp(n+1,0);
   dp[0]=1;
   dp[1]=1;
   for(int i=2;i<=n;i++){
      for(int j=1;j<=6;j++){
         if(i-j>=0)   (dp[i]+=dp[i-j])%=mod;
        
      }
   }
   cout<<dp[n];
 
}
 
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;     t=1;
   //cin>>t;
   while(t--)  solve();
 
   return 0;
}
