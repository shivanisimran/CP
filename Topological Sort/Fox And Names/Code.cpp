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
vector<int> adj[10004];
int vis[10004];
vector<int> ans;
 
bool cycle(int x){
   vis[x]=1;
   for(int j:adj[x]){
      if(j==x) continue;
      if(vis[j]==1)  return true;
      else if(!vis[j]){
         if(cycle(j))  return true;
      }  
   }
   ans.pb(x);
   vis[x]=2;
   return false;
}
 
void solve(){
   int n,f=0;
   cin>>n;
 
   vector<string>v(n);

   for(int i=0;i<n;i++)  cin>>v[i];

   for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
         string a=v[i],b=v[j];
         int m=min(a.length(),b.length());

         for(int k=0;k<m;k++){
            if(a[k]!=b[k]){
               adj[a[k]-'a'].pb(b[k]-'a');
               break;
            }
           // cout<<m-1<<" ";
            if(k==m-1 && a.length()>b.length()){
               cout<<"Impossible";
               return;
            }
         }
      }
   }
 
   memset(vis,0,sizeof vis);

 
   for(int i=0;i<26;i++){
      if(!vis[i] && cycle(i)){
         cout<<"Impossible";
         return;
      }
    
   }
   
   reverse(ans.begin(),ans.end());
   for(int i: ans)  cout<<(char)(i+'a');
   
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
