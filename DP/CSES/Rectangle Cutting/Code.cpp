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
int dp[501][501];
 
int fun(int a,int b){
  
   if(dp[a][b]!=-1)  return dp[a][b];
  
   if(a==b)  return dp[a][b]=0;
   if(a==1 || b==1)   return dp[a][b]=max(a,b)-1;
  
 
   
   int c=INT_MAX,d=INT_MAX;
 
   for(int x=1;x<a;x++){
      c=min(c,1+fun(a-x,b)+fun(x,b));
   }
   for(int x=1;x<b;x++){
      d=min(d,1+fun(a,b-x)+fun(a,x));
   }
   
   return dp[a][b]=min(c,d);
}
 
void solve(){ 
   int a,b;
   cin>>a>>b;
   memset(dp,-1,sizeof dp);
   cout<<fun(a,b);
   
   
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
