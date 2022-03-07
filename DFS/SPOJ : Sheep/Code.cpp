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
int n,m;
char g[251][251];
int vis[251][251];
int row[4] = {0, 0, -1, 1};
int col[4] = {-1, 1, 0, 0};
int c;
 
void dfs(int x,int y,int &k,int &v){
   if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='#' || vis[x][y])  return;
   vis[x][y]=1;
   if(x==0 || x==n-1 || y==0 || y==m-1) {
      k=0;
      v=0;
      return;
   }
   if(g[x][y]=='k') k++;
   else if(g[x][y]=='v')  v++;
 
   for(int i=0;i<4;i++){
      int x1=x+row[i], y1=y+col[i];
      dfs(x1,y1,k,v);
   }
 
 // cout<<k<<" "<<v<<endl;
}
 
void solve(){ 
   int sheep=0,wolf=0;
   cin>>n>>m;
   
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)  cin>>g[i][j];
   }
   memset(vis,0,sizeof(vis));
 
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++) {
         if(g[i][j]!='#'){
            int v=0,k=0;
            dfs(i,j,k,v);
            //cout<<i<<" "<<j<<" "<<k<<" "<<v<<endl;
            if(k>v)  sheep+=k;
            else wolf+=v;
         }
      }
   }
   cout<<sheep<<" "<<wolf;
 
   
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
 
   while(t--)   solve();
   
   return 0;
}  
