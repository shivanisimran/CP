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
ll n,s,arr[505];
 
ll dp[505][100005];
int fun(int n,int t){
   if(n<0)  return 0;
 
   if(dp[n][t]!=-1)  return dp[n][t];
   if(t==0)  return dp[n][t]=1;
   
   if(arr[n-1]<=t)  return (dp[n][t]=fun(n-1,t-arr[n-1])+fun(n-1,t))%=mod;
   else return (dp[n][t]=fun(n-1,t))%=mod;
}
 
void solve(){
   cin>>n;
   s=n*(n+1)/2;
 
   memset(dp,-1,sizeof dp);
 
   for(int i=0;i<n;i++)  arr[i]=i+1;
 
   if(s&1){
     cout<<"0";
     return;
   }
   else cout<<fun(n-1,s/2);
 
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
