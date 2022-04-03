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
 
int n,x;
int c[105];
int dp[1000005];
 
int fn(int x){
  // cout<<x<<" ";
     
   if(x==0)  return 0;
   if(dp[x]!=-1)  return dp[x];
 
   int m=1000001;
 
   for(int i=0;i<n;i++)  {
      if(c[i]<=x) m=min(fn(x-c[i])+1, m);
   }
   return dp[x] = m;
}
 
void solve(){
   cin>>n>>x;
   for(int i=0;i<n;i++)  cin>>c[i];
 
   memset(dp,-1, sizeof dp);
 
   if(fn(x)==1000001)  cout<<"-1";
   else cout<<fn(x);
 
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
