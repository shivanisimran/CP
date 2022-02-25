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
vector<int>vis;
vector<int> adj[1000001];
 
bool bfs(int x, int w,int i){
   int c=0;
   queue<int> q;
   q.push(x);
   //vis[x]=i;
   while(!q.empty() && c<=w){
      int n=q.size();
      
      while(n--){
         int k=q.front();
         if(vis[k]!=0 && vis[k]!=i) return false;
         q.pop();
         vis[k]=i;
         for(int l:adj[k]) q.push(l);
      }
      c++;
   }
   return true;
}
void solve(){ 
   int n,r,m;
   cin>>n>>r>>m;
   unordered_map<int,int> strength;
   for(int i=0;i<n;i++)  adj[i].clear();
   vis=vector<int>(n+1,0);
   while(r--){
      int a,b;
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
   }
  
   vector<int> pos;
   while(m--){
      int k,s;
      cin>>k>>s;
      pos.pb(k);
      strength[k]=s;
   }
   bool f=1;
   for(int i=0;i<pos.size();i++){
     f &= bfs(pos[i],strength[pos[i]],i+1);
 
   }
   for(int i=1;i<=n;i++)  if(!vis[i])  f=0;
   if(f)  cout<<"Yes"<<endl;
   else  cout<<"No"<<endl;
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
 
   while(t--)   solve();
 
   return 0;
} 
