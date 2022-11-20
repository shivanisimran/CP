#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
 
 
void solve(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)  cin>>a[i];
 
   vector<int> dp(n+1,mod); //dp[i]=element at which subsequence of length i terminates.
   dp[0]=-mod;
 
   for(int i=0;i<n;i++){
      // for(int j=1;j<=n;j++){ 
      //    if(dp[j-1]<a[i]) dp[j]=min(dp[j],a[i]);
      // }
      int j=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
      if(dp[j-1]<a[i])  dp[j]=a[i];
   }
 
   int ans=0;
 
   for(int i=1;i<=n;i++){
      ///cout<<dp[i]<<" ";
      if(dp[i] < mod)  ans=i;
   }
 
   cout<<ans<<endl;
 
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
   
   while(t--){
      solve();
   } 
   
   return 0;
}
