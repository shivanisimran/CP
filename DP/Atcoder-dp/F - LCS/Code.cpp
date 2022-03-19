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
string s1,s2;
int n,m;
//ll val[105], wt[105];
int  dp[3003][3003];



// dp[i][j] = length of lcs of (substring of s1 upto index 'i') and (substring of s2 upto index 'j').
int lcs(int i,int j){
   if(i<=0 || j<=0)  return 0;
   
   if(dp[i][j]!=-1)  return dp[i][j];
   
   if(s1[i-1]==s2[j-1])  return dp[i][j] = 1+lcs(i-1,j-1);
   else  return dp[i][j] =  max(lcs(i-1,j),lcs(i,j-1));
}

void solve(){ 
   cin>>s1>>s2;
   n=s1.length(),m=s2.length();

   memset(dp,-1,sizeof dp);
   lcs(n,m);
   string ans;

   while(n && m){
      if(s1[n-1]==s2[m-1]) {
         ans+=s1[n-1];
         n--;
         m--;
      }  
      else if(dp[n-1][m]>dp[n][m-1])  n--;
      else m--;
   }
   reverse(ans.begin(),ans.end());
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
   cout.tie(NULL);
   
   int t;    t=1;
   //cin>>t;
   
   while(t--) solve();
   
   return 0;
} 
