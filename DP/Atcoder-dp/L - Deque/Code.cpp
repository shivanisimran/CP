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

ll n,k;
ll a[3001];
ll dp[3001][3001];

ll fun(int i, int j){
   if(dp[i][j]!=-1)  return dp[i][j];

   if(i>j)  return dp[i][j]=0;
   if(i==j)  return dp[i][j]=a[i];


   return dp[i][j]=max(a[i] + min(fun(i+2,j),fun(i+1,j-1)),
                       a[j] + min(fun(i+1,j-1),fun(i,j-2)) );
}

void solve(){
   cin>>n;

   ll s=0;
   for(int i=0;i<n;i++){
       cin>>a[i];
       s+=a[i];
   }

   memset(dp,-1,sizeof dp);

   ll x=fun(0,n-1);
   ll y=s-x;

   cout<<x-y;  

  
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
