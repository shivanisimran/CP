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
 
void solve(){
   string mat[51];
   string s;
   cin>>s;
   int n=s.length();
 
   int d[n][n];
 
   mat[0]=s;
   for(int i=1;i<n;i++)  cin>>mat[i];
 
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         d[i][j]=0;
      }
   }
 
   int v[n];
   for(int i=0;i<n;i++)  v[i]=0;
   
   for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
           if(i!=j){
               if(mat[i][j]=='N' && (mat[i][k]=='Y' && mat[k][j]=='Y')) d[i][j]=1;
           } 
        
         }
      }
   }
 
   
 
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(d[i][j]==1)  v[i]++;
      }
   }
 
  // for(int i=0;i<n;i++)  cout<<v[i]<<" ";
   
   int m=INT_MIN,id=0;
 
   for(int i=0;i<n;i++){
      if(v[i]>m){
         m=v[i];
         id=i;
      }
   }
 
   cout<<id<<" "<<m<<endl;
 
}
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;    //t=1;
   cin>>t;
 
   while(t--) solve();
   
   return 0;
} 
