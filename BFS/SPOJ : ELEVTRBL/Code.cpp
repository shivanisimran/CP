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


vector<ll> adj[1000006];
ll dist[1000006];

void solve(){ 
   ll f,s,g,u,d;
   cin>>f>>s>>g>>u>>d;

   if(s==g) {
      cout<<"0";
      return;
   } 

   for(int i=1;i<=f;i++){
      if(i+u<=f)  adj[i].pb(i+u);
      if(i-d > 0)  adj[i].pb(i-d);
   }
   
   memset(dist, -1, sizeof dist);

   queue<ll> q;
   q.push(s);
   dist[s]=0;

   while(!q.empty()){
      ll n=q.size();
   
      while(n--){
         ll k=q.front();
         q.pop();

         for(int j: adj[k]){
            if(dist[j]==-1){
               dist[j]=dist[k]+1;
               if(j==g) {
                  cout<<dist[j];
                  return;
               }
               q.push(j);
            }
         }
      }
   }
   cout<<"use the stairs";

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
