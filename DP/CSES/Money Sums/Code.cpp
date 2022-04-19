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
ll a[105];
//vector<ll> ans;
//set<ll> st;
int mp[9000000];
int dp[1000001][101];
 
void fun(ll s,ll x){
   if(dp[s][x]!=-1)  return;
   dp[s][x]=1;
   for(int i=x;i<n;i++){
      if(s-a[i]>0 ) {
         mp[s-a[i]]++;
         fun(s-a[i],i+1);
      }
   }
}
 
void solve(){ 
   cin>>n;
   ll s=0,p;
 
   for(int i=0;i<n;i++) {
      cin>>a[i];
      s+=a[i];
   }
 
   memset(dp,-1,sizeof dp);
   memset(mp,0,sizeof mp);
   p=s;
   mp[p]=1;
   
   fun(s,0);
  // cout<<mp.length()<<endl;
   int c=0;
   for(int i=1;i<=p;i++)  if(mp[i]) c++;
 
   cout<<c<<endl;
   for(int i=1;i<=p;i++)  if(mp[i]) cout<<i<<" ";
 
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
