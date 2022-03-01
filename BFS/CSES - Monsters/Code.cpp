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
//vector<string> g;
int n,m;
int d[1001][1001];
int d1[1001][1001];
int row[4] = {0, 0, -1, 1};
int col[4] = {-1, 1, 0, 0};
//char dir[] = {'U','D','R','L'}
 
void solve(){ 
  // cout<<" Hello";
   for(int i=0;i<1001;i++){
      for(int j=0;j<1001;j++){
          d[i][j]=-1;
      }
   }
   cin>>n>>m;
   vector<vector<char>> g(n+1,vector<char>(m+1));
   queue<vector<int>> q;
   
   int x,y,xa,ya;
 
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>g[i][j];
         if(g[i][j]=='M')  q.push({i,j,0});
         if(g[i][j]=='A') {
            xa=i,ya=j;
         }
      }
   }
   x=xa,y=ya;
   while(!q.empty()){
      auto k=q.front();
    //  cout<<k[0]<<" ";
      q.pop();
      int a=k[0],b=k[1],c=k[2];
      if(a<0 || a>n-1 || b<0 || b>m-1 || g[a][b]=='#' || d[a][b]!=-1)  continue;
      d[a][b]=c;
 
     // int a1,b1;
      for(int i=0;i<4;i++){
         int a1=a+row[i],b1=b+col[i];
         q.push({a1,b1,c+1});
      }
   }
 
  // int x=xa,y=ya;
   string ans;
   while(!q.empty())  q.pop();
   q.push({x,y,0,0});
   
   for(int i=0;i<1001;i++){
      for(int j=0;j<1001;j++){
          d1[i][j]=-1;
      }
   }
 
   bool f=false;
   int p[n+1][m+1];
   memset(p,0,sizeof(p));
   
   while(!q.empty()){
      auto k=q.front();
      q.pop();
      int x=k[0],y=k[1],c=k[2],dd=k[3];
      if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='#' || d1[x][y]!=-1 || (d[x][y]>=0 && d[x][y]<=c))   continue;
 
      if(x==n-1 || x==0 || y==m-1 || y==0){
         p[x][y]=dd;
         
         while(x!=xa || y!=ya){
            if(p[x][y]==0)  ans+='L',y++;
            else if(p[x][y]==1)  ans+='R',y--;
            else if(p[x][y]==2)  ans+='U',x++;
            else  ans+='D',x--;
         }
 
         reverse(ans.begin(),ans.end());
         f=true;
         break;
      }
      d1[x][y]=c;
      p[x][y]=dd;
 
      for(int i=0;i<4;i++){
         int m1=x+row[i],m2=y+col[i];
         q.push({m1,m2,c+1,i});
      }
 
   }
 
   if(f){
      cout<<"YES"<<endl;
      cout<<ans.size()<<endl<<ans;
   } 
   else   cout<<"NO"<<endl;
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
