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

void solve(){
   int n,x1,y1,x2,y2;

   cin>>n>>x1>>y1>>x2>>y2;

   int d[n+1][n+1];
   int vis[n+1][n+1];
  
   memset(vis,0,sizeof vis);

   //cout<<d[x2][y2];

   for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
         d[i][j]=INT_MAX;
      }  
   }

   queue<pii> q;
   q.push({x1,y1});
   d[x1][y1]=0;
   vis[x1][y1]=1;

   while(!q.empty()){
      auto k=q.front();
      q.pop();

      int x=k.first,y=k.second;
      if(y==0 || y==n){
         if(x+1<=n && !vis[x+1][y]){
            vis[x+1][y]=1;
            d[x+1][y]=d[x][y]+1;
            q.push({x+1,y});
         }
         if(x-1>=0 && !vis[x-1][y]){
            vis[x-1][y]=1;
            d[x-1][y]=d[x][y]+1;
            q.push({x-1,y});
         }
      }

      if(x==0||x==n){
         if(y+1<=n && !vis[x][y+1]){
            vis[x][y+1]=1;
            d[x][y+1]=d[x][y]+1;
            q.push({x,y+1});
         }
         if(y-1>=0 && !vis[x][y-1]){
            vis[x][y-1]=1;
            d[x][y-1]=d[x][y]+1;
            q.push({x,y-1});
         }
      }
   }

   // for(int i=0;i<=n;i++){
   //    for(int j=0;j<=n;j++){
   //       cout<<"("<<i<<","<<j<<")";
   //       cout<<d[i][j]<<" ";
   //    }  
   //    cout<<endl;
   // }

   cout<<d[x2][y2];

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
