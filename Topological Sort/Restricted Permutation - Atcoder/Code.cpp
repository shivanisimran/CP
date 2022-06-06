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
unordered_map<int,set<int>> adj;
int vis[200004];
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
   vis[x]=2;
   return false;
}



void solve(){
   int n,m;
   cin>>n>>m;
   vector<int> in(n+1,0);


   int a,b;
   while(m--){
      cin>>a>>b;
      if(adj[a].find(b)==adj[a].end()){
         adj[a].insert(b);
         in[b]++;
      }
      
   }

   memset(vis,0,sizeof vis);

   for(int i=1;i<=n;i++){
      if(cycle(i)){
         cout<<"-1";
         return;
      }
    
   }

   priority_queue<int, vector<int>, greater<int>> q;

   for(int i=1;i<=n;i++){
      if(in[i]==0) {
         q.push(i);
      } 
   }

   while(!q.empty()){
      int k=q.top();
      ans.pb(k);
      q.pop();
      
      for(int j: adj[k]){
         in[j]--;
         if(in[j]==0) q.push(j);
      }


   } 

   for(int j: ans)  cout<<j<<" ";
   
   
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
