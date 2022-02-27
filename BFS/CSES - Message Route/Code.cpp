#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define endl '\n' 
 
ll add(ll x, ll y){ll res=x+y; return res % mod;}
ll mul(ll x, ll y){ll res=x*y; return res%mod;}
ll p(ll x, ll y){ll res=1;x%=mod;while(y){if(y&1){res = mul(res,x);}y>>=1;x=mul(x,x);}return res;}
void precision(int n){cout<<fixed<<setprecision(n);}
//1<<X means 2^X
 
 
vector<int>adj[100001];
vector<int>d(100001,INT_MAX);
vector<int>vis(100001,0);
unordered_map<int,int>mp;
int n,m;
 
void bfs(int& l){
   d[0]=0;
   d[1]=1;
   queue<int>q;
   q.push(1);
   vis[1]=1;
   mp[1]=-1;
   while(!q.empty()){
      int k=q.front();
      q.pop();
      for(int x: adj[k]){
         if(!vis[x]){
            vis[x]=1;
            q.push(x);
            if(d[k]+1 < d[x]){
               mp[x]=k;
               d[x]=d[k]+1;
            }
         } 
      }
   }
   l=d[n];
}
 
void solve(){   
   cin>>n>>m;
   for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   int l;
   bfs(l);
   if(!vis[n]){
      cout<<"IMPOSSIBLE";
      return;
   }
   else{
      cout<<l<<endl;
      vector<int>path;
      int x=n;
      path.push_back(x);
      while(x!=1){
         path.push_back(mp[x]);
         x=mp[x];
      }
     for(int i=path.size()-1;i>=0;i--)    cout<<path[i]<<" ";
   }
   
}
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;     t=1;
   //cin>>t;
   while(t--)  solve();
 
   return 0;
}
