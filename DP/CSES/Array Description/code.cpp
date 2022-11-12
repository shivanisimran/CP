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
int n,m;
int a[100001];
 
int dp[101][100001];
 
int fun(int p,int x){
   if(x==n)  return 1;
 
   if(dp[p][x]!=-1)  return dp[p][x];
 
   ll ans=0;
   if(a[x]!=0){
      if(abs(a[x]-p)>1)  return 0;
      else return dp[p][x]=fun(a[x],x+1)%mod;
   }  
   else{
      for(int i:{p-1,p,p+1}){
         if(i>=1 && i<=m)  (ans+=fun(i,x+1))%=mod; 
      }
   }
 
   return dp[p][x]=ans;
 
}
 
void solve(){
   cin>>n>>m;
 
   for(int i=0;i<n;i++)  cin>>a[i];
 
   memset(dp,-1,sizeof dp);
   
   ll ans=0;
   if(a[0]==0){
      for(int i=1;i<=m;i++)  (ans+=fun(i,1))%=mod;
   }
 
   else ans = fun(a[0],1);
 
   cout<<ans;
 
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
      //cout<<"Case #"<<k++<<": ";
      solve();
   } 
   
   return 0;
}
