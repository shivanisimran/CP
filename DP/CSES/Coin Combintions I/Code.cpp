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
   ll n,x;
   cin>>n>>x;
   int a[n];
   
   for(int i=0;i<n;i++) cin>>a[i];
 
   ll dp[x+1]={0};
   dp[0]=1;
 
   for(int i=0;i<=x;i++){
       for(int j=0;j<n;j++){
         if(i-a[j] >= 0)  (dp[i]+=dp[i-a[j]])%=mod;
       }
   }
 
   cout<<dp[x];
   
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
