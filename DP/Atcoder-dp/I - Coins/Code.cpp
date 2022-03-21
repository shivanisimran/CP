#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define endl '\n' 
//1<<X means 2^X 
  
void precision(int n){cout<<fixed<<setprecision(n);}

int n;
ld p[3001];
ld dp[3001][3001];

//dp[i][j] indicates probability of getting 'j' heads from first 'i' elements.
ld fn(int n,int k){

  if(dp[n][k]!=-1)  return dp[n][k];

  if(n==1 && k==0)  return dp[n][k] = (1-p[0]);
  if(k==0)  return dp[n][k] = (1-p[n-1])*fn(n-1,0);
  if(k>n)  return dp[n][k] = 0;

  if(n==1)  return dp[n][k] = p[0];

  return dp[n][k] = p[n-1]*fn(n-1,k-1) + (1-p[n-1])*fn(n-1,k);
}

void solve(){ 
   cin>>n;
   for(int i=0;i<n;i++)  cin>>p[i];
    
   for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++)  dp[i][j]=-1;
   }
   precision(10);

   int k = n/2 + 1;
   ld s=0;
   for(int i=k;i<=n;i++){
       s += fn(n,i);
      // cout<<s<<" ";
   }
   cout<<s;

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
