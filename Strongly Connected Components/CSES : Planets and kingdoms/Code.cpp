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
vector<int>adj[200005];
vector<int> tin, low;
vector<int>onstack;
stack<int> st;
int c,timer;
int n,m;
vector<vector<int>> final;
 
void dfs(int x){
   tin[x]=low[x]=timer++;
   st.push(x);
   onstack[x]=1;
 
   for(int j: adj[x]){
      if(tin[j]!=-1 && onstack[j])  low[x]=min(low[x],tin[j]);
      else if(tin[j]==-1){
         dfs(j);
         low[x]=min(low[x],low[j]);
      }
   }
   if(tin[x]==low[x]){
      vector<int>v;
      while(st.top()!=x) {
         onstack[st.top()]=0;
         v.pb(st.top());
         st.pop() ; 
      }
      onstack[x]=0;
      v.pb(x);
      st.pop();
 
      if(!v.empty()){
         sort(v.begin(),v.end());
         final.pb(v);
      } 
   }
   
  
}
 
void solve(){ 
   cin>>n>>m;
   for(int i=1;i<=n;i++) adj[i].clear();
 
   int x,y;
   while(m--){
       cin>>x>>y;
       adj[x].pb(y);
   }
   
   
   onstack=vector<int>(n+1,0);
   low=vector<int>(n+1,-1);
   tin=vector<int>(n+1,-1);
   
   c=0,timer=0;
   while(!st.empty())   st.pop();
 
   for(int i=1;i<=n;i++){
      if(tin[i]==-1)   dfs(i);
   }
   cout<<final.size()<<endl;
   sort(final.begin(),final.end());
   vector<int> ans(n+1);
   int l=1;
 
   for(auto k: final){
      for(int i=0;i<k.size();i++){
         ans[k[i]]=l;
      }
      l++;
   }
 
   for(int i=1;i<=n;i++)  cout<<ans[i]<<" ";
  
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
