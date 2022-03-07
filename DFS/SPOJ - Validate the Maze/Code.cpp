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
ll n,m;
char g[21][21];
int vis[21][21];
int row[4] = {0, 0, -1, 1};
int col[4] = {-1, 1, 0, 0};
int c;
 
 
void dfs(ll x,ll y,ll &c){
   if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='#' || vis[x][y])  return;
   vis[x][y]=1;
   
   if(x==0 || y==0 || x==n-1 || y==m-1) c++;
   for(int i=0;i<4;i++){
      ll x1=x+row[i], y1=y+col[i];
      dfs(x1,y1,c);
   }
  
}
 
void solve(){ 
   ll s=0;
   cin>>n>>m;
   
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)  cin>>g[i][j];
   }
   memset(vis,0,sizeof(vis));
   vector<int> v;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++) {
         if(g[i][j]!='#'){
            ll c=0;
            dfs(i,j,c);
            if(c!=0) v.pb(c);
         }
      }
   }
  // for(int i: v)  cout<<i<<" ";
   if(v.size()!=1) {
      cout<<"invalid"<<endl;
      return;
   }
   if(v[0]!=2)  cout<<"invalid"<<endl;
   else cout<<"valid"<<endl;
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
