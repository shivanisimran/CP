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
ll a[105];
ll dp[100005];

int fun(int k){
  // cout<<k<<" ";
   if(dp[k]!=-1)  return dp[k];
 
   int f=0;
   for(int i=0;i<n;i++){
      if(k>=a[i] && !fun(k-a[i]))  f=1;
   }

   return dp[k]=f;
  
}

void solve(){
   cin>>n>>k;

   ll s=0;
   for(int i=0;i<n;i++){
       cin>>a[i];
       s+=a[i];
   }

   sort(a,a+n);

   memset(dp,-1,sizeof dp);

   if(fun(k))  cout<<"First";
   else cout<<"Second";

  
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
