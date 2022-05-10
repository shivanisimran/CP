#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
#define INF 10000000000000
//1<<X means 2^X 
  
//void precision(int n){cout<<fixed<<setprecision(n);} 
 
 
void solve(){
   int n,m,q;
   cin>>n>>m>>q;
 
   ll d[n+1][n+1]={INF};
 
   for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
         if(i==j)  d[i][j]=0;
         else  d[i][j]=INF;
      }
   }
 
 
   // for(int i=0;i<=n;i++){
   //    for(int j=0;j<=n;j++){
   //       cout<<d[i][j]<<" ";
   //    }
   //    cout<<endl;
   // }
 
   
   while(m--){
      ll a,b,c;
      cin>>a>>b>>c;
 
      d[a][b]=min(d[a][b],c);
      d[b][a]=min(d[b][a],c);
 
      //cout<<d[a][b]<<endl;
 
   }
 
   for(int k=1;k<=n;k++){
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            if(d[i][k]<INF && d[k][j]<INF)
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
         }
      }
   }
 
   while(q--){
      int a,b;
      cin>>a>>b;
      if(d[a][b]==INF)  cout<<"-1\n";
      else cout<<d[a][b]<<endl;
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
   
   int t;    t=1;
   //cin>>t;
 
   while(t--) solve();
   
   return 0;
}
