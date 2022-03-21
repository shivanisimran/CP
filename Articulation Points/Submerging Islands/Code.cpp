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
//vector<int> vis;
vector<int> tin, low;
int c;
int n,m;
set<int> st;
 
void dfs(int x,int p){
  // vis[x]=1;
   tin[x]=low[x]=c++;
   int child=0;
 
   for(int j: adj[x]){
      if(j==p)  continue;
      if(tin[j]!=-1)  low[x]=min(low[x],tin[j]);
      else{
         dfs(j,x);
         low[x]=min(low[x],low[j]);
         if(low[j]>=tin[x] && p!=-1)    st.insert(x);
            
         child++;
      }
   }
 
   if(p==-1 && child>1)    st.insert(x);
}
 
void solve(){ 
   for(int i=1;i<=n;i++) adj[i].clear();
   
   int x,y;
   while(m--){
      cin>>x>>y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   //vis=vector<int>(n+1,0);
   low=vector<int>(n+1,-1);
   tin=vector<int>(n+1,-1);
   
   c=0;
   st.clear();
   dfs(1,-1);
   cout<<st.size()<<endl;
   
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
   
   //int t;    t=1;
   //cin>>t;
   
   while(1) {
      cin>>n>>m;
      if(n==0 && m==0)  break;
      else  solve();
   } 
   
   return 0;
}  
