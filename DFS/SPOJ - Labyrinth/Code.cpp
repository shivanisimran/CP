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
int n,m,ans,endx=-1,endy=-1;
char g[1000][1000];
int row[4]={1,-1,0,0};
int col[4]={0,0,1,-1};
int vis[1001][1001];
 
void dfs(int x,int y,int k){
   if(x<0 || x>=n || y<0 || y>=m  || vis[x][y] || g[x][y]=='#')  return;
  // int k=0;
   vis[x][y]=1;
   if(k>ans){
     // cout<<x<<"-"<<y<<endl;
      ans=k;
      endx=x;
      endy=y;
   }
   for(int i=0;i<4;i++){
      int x1=x+row[i],y1=y+col[i];
      dfs(x1,y1,k+1);
   }
   //ans=max(k,ans);
   
}
void solve(){  
   cin>>m>>n;
   ans=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>g[i][j];
      }
   }
   memset(vis,0,sizeof(vis));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(g[i][j]=='.')  dfs(i,j,0);
      }
   }
  // cout<<ans<<" ";
   memset(vis,0,sizeof(vis));
   if(endx!=-1 && endy!=-1)   dfs(endx,endy,0);
   cout<<"Maximum rope length is "+to_string(ans)+"."<<endl;
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
   
   int t;    //t=1;
   cin>>t;
 
   while(t--)   solve();
   
   return 0;
} 
