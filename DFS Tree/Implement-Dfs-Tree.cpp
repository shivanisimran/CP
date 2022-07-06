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
int mat[101][101];
vector<int> adj[101];
int vis[101];
 
void dfs(int x,int par){
   vis[x]=1;
   for(int j: adj[x]){
      if(j==par)  continue;
      if(vis[j]){
         mat[x][j]=-1;
         mat[j][x]=-1;
      }
      else{
         dfs(j,x);
      }
   }
}
 
void solve(){
   int n,m;
   cin>>n>>m;

   memset(adj,0,sizeof adj);

   int a,b;
   while(m--){
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);

      mat[a][b]=1;
      mat[b][a]=1;
   }
   
   memset(vis,0,sizeof vis);
   dfs(1,-1);

   int x,y;
   cin>>x>>y;

   if(mat[x][y]==0)  cout<<"Edge doesn't exist\n";
   else if(mat[x][y]==-1)  cout<<"Back Edge\n";
   else cout<<"Tree Edge\n";

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


/*
Input:
12
16
1 3
3 5
5 7
3 6
1 9
9 11
11 12
6 2
2 8
2 4
4 10
5 1
7 3
1 6
9 12
3 8
1 5

Output:
Back Edge
*/
