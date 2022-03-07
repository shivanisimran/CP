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
char g[1001][1001];
int vis[1001][1001];
int row[4] = {0, 0, -1, 1};
int col[4] = {-1, 1, 0, 0};
int c;
 
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);   
}
void dfs(ll x,ll y,ll &c){
   if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='~' || vis[x][y])  return;
   vis[x][y]=1;
   
   c++;
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
 
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++) {
         if(g[i][j]!='~'){
            ll c=0;
            dfs(i,j,c);
            //cout<<i<<"-"<<j<<" "<<c<<endl;
            s+=(c*c);
         }
      }
   }
   
   ll k=gcd(s,n*m);
   cout<<s/k;
   if((n*m)/k != 1){
      cout<<" / "<<((n*m)/k);
   }
   cout<<endl;
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
