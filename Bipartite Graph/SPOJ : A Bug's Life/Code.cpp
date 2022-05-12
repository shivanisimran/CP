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
 
vector<int> adj[100005];
int c=1;
void solve(){
   int n,m;  
   cin>>n>>m;
 
   for(int i=0;i<=n;i++)  adj[i].clear();
 
   int u,v;
   while(m--){
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }
 
   vector<int>team(n+1,-1);
   
   queue<int> q;
   
   int x;
 
   for(int i=1;i<=n;i++){
      if(team[i]==-1)  {
         q.push(i);
         team[i]=1;
      }
      while(!q.empty()){
         int k=q.front();
         q.pop();
         x=team[k];
         
         for(int j: adj[k]){
            if(team[j]==x) {
               cout<<"Scenario #"<<c<<":\nSuspicious bugs found!\n";
               c++;
               return;
            }
            if(team[j]==-1)  q.push(j);
            team[j]=(3-x);
         }
         
      }
   }
   
 
   cout<<"Scenario #"<<c<<":\nNo suspicious bugs found!\n";
   c++;
 
}
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;    //t=1;
   cin>>t;
 
   while(t--) solve();
   
   return 0;
} 
