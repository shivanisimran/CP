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
 
int n;
int dp[1000001];
 
vector<int> digits(int n){
   vector<int> v;
   while(n){
      v.push_back(n%10);
      n/=10;
   }
   return v;
}
int fun(int n){
    if(dp[n]!=-1) return dp[n];
    if(n==0)   return dp[n]=0;
    if(n<10)   return dp[n]=1;
    
    int c=INT_MAX;
    for(int i:digits(n)){
 
      if(i!=0) c=min(c,1+fun(n-i));
    }
   
    
    return dp[n]=c;
}
 
 
void solve(){
   
   cin>>n; 
   memset(dp,-1,sizeof dp);
   cout<<fun(n);
 
   
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
