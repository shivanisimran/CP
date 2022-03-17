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
ll a[100005][5];
ll dp[100005][5];
ll s=0,ans,n;
 
//'row' indicates the current row we are at.
ll fn(ll row, ll p){
     if(dp[row][p]!=-1) return dp[row][p];
     if(row==n-1){
        if(p==0)  return dp[row][p] = max(a[row][1], a[row][2]);
        else if(p==1) return dp[row][p] = max(a[row][0], a[row][2]);
        else if(p==2) return dp[row][p] = max(a[row][0], a[row][1]);
        else  return dp[row][p] = max({a[row][1], a[row][0],a[row][2]});
     }
 
     if(row==0){
        return dp[row][p] = max({a[row][0]+fn(row+1,0), a[row][1]+fn(row+1,1), a[row][2]+fn(row+1,2)});
     }
     else{
        ll ans;
        if(p==0){
           ans=max(a[row][1]+fn(row+1,1),a[row][2]+fn(row+1,2));
        }else if(p==1){
           ans=max(a[row][0]+fn(row+1,0),a[row][2]+fn(row+1,2));
        }else{
          ans=max(a[row][1]+fn(row+1,1),a[row][0]+fn(row+1,0));
        }
        return dp[row][p]=ans;
     }
 
}
void solve(){ 
   cin>>n;
  
   for(int i=0;i<n;i++){
      cin>>a[i][0]>>a[i][1]>>a[i][2];
   }
   memset(dp,-1,sizeof dp);
   cout<<fn(0,4);
   
}
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int t;    t=1;
   //cin>>t;
   
   while(t--) solve();
   
   return 0;
} 
