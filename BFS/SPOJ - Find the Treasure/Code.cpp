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
// vector<int>vis;
//vector<int> adj[100001];
void solve(){ 
   int n;
   cin>>n;
   //for(int i=0;i<n;i++)  adj[i].clear();
   vector<int> adj[n+1];
    
   for(int i=1;i<=n-1;i++){
      int x;
      cin>>x;
      while(x--){
        int z;
        cin>>z;
        adj[i].pb(z);
      }
      sort(adj[i].begin(),adj[i].end());
   }
   
   queue<int> q;
   q.push(1);
   //vector<int> vis(n+1,0);
   vector<int> par(n+1,-1);
   par[1]=0;
   bool f=0;
 
   while(!q.empty()){
      int n1=q.size();
     
      while(n1--){
        int k=q.front();
        q.pop();
       // vis[k]=1;
       // cout<<k<<" ";
        for(int i: adj[k]){
            //cout<<i<<" ";
            if(par[i]==-1){
                par[i]=k;
                if(i==n) {
                    f=1; 
                    break;
                }
               q.push(i);  
            }   
        }
        
      }
       if(f) break;
   }
//   cout<<f<<"-";
   if(!f) {
       cout<<"-1\n\n";
       return;
   }
   vector<int> v;
 
   int x=n;
   while(par[x]!=0){
       v.push_back(par[x]);
       x=par[x];
   }
 
   cout<<v.size()<<endl;
   for(int i=v.size()-1;i>=0;i--)  cout<<v[i]<<" ";
   cout<<"\n\n";
 
 
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
 
   while(t--)   solve();
 
   return 0;
} 
