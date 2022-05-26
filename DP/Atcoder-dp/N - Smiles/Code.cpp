#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define endl '\n' 

#define INF 100000000000000
//1<<X means 2^X 
  
//void precision(int n){cout<<fixed<<setprecision(n);}

ll a[404];
ll dp[404][404];
ll p[404][404];

ll mcm(int i,int j){
   if(i==j)  return dp[i][j]=0;
   if(dp[i][j]!=-1)  return dp[i][j];

   ll m=INF;
   for(int k=i;k<j;k++){
      m=min(m,p[i][k]+p[k+1][j]
              +mcm(i,k)
              +mcm(k+1,j));
   }

   return dp[i][j]=m;
}

void solve(){
   int n;
   cin>>n;

   for(int i=0;i<n;i++)  cin>>a[i];

   for(int i=0;i<n;i++){
      ll s=0;
      for(int j=i;j<n;j++){
         s+=a[j];
         //p[i][j] stores prefix sum from index 'i' to 'j'
         p[i][j]=s;
      }
   }

   memset(dp,-1,sizeof dp);
   cout<<mcm(0,n-1);

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
