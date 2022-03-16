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
   vector<ll>h(n),dp(n);
   for(int i=0;i<n;i++)    cin>>h[i];
   
   dp[0]=0;
   dp[1]=abs(h[1]-h[0]);
 
   for(int i=2;i<n;i++){
      dp[i]=min(dp[i-2]+abs(h[i]-h[i-2]), dp[i-1]+abs(h[i]-h[i-1]));
     // cout<<dp[i]<<" ";
   }
 
   cout<<dp[n-1];
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
