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
 
vector<int>adj[100005];
vector<int>back[100005];
int vis[100004];
 
bool cycle(int x){
   vis[x]=1;
   for(int j:adj[x]){
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
 
   int in[n+1]={0};
   int dp[n+1]={0};
   int par[n+1];
 
   for(int i=1;i<=n;i++){
      in[i]=0;
      dp[i]=0;
      par[i]=-1;
   }
 
 
   int a,b;
   dp[1]=1;
 
   while(m--){
      cin>>a>>b;
      in[b]++;
      adj[a].pb(b);
      back[b].pb(a);
   }
 
   
 
   queue<int> q;
   
   for(int i=1;i<=n;i++)  if(in[i]==0)  q.push(i);
 
  // cout<<par[n];
 
   while(!q.empty()){
      int k=q.front();
      q.pop();
 
      for(int j: adj[k]){
         in[j]--;
         if(in[j]==0) {
            q.push(j);
         } 
      }
 
      int m=INT_MIN;
      
      for(int p: back[k]){
         if(m<dp[p]+1){
            m=dp[p]+1;
            par[k]=p;
         }
       
      }
 
      if(k!=1) dp[k]=m;
   }
 
 
   vector<int>v;
   int x=n,f=0;
 
   while(x!=-1){
      v.pb(x);
      x=par[x];
      if(x==1){
          f=1;
          break; 
      }
   }
   v.pb(1);
 
   if(f==0){
      cout<<"IMPOSSIBLE\n";
      return;
   }
 
   cout<<v.size()<<endl;
 
   reverse(v.begin(),v.end());
   for(int i: v)  cout<<i<<" ";
 
 
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
