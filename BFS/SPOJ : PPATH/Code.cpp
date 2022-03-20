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

int prime[100000];
vector<int> v;
vector<int> adj[100000]; 


bool connected(string a,string b){
   int c=0;
   for(int i=0;i<=3;i++)  if(a[i]==b[i])  c++;

   return (c==3);
}


void solve(){ 

   int src,dst;
   cin>>src>>dst;

   if(src > dst)  swap(src,dst);
   
   int dist[100000];
   memset(dist,-1,sizeof dist);  
   
   queue<int> q;
   q.push(src);
   dist[src]=0;
   
   while(!q.empty()){
      int n=q.size();

      while(n--){
         int k=q.front();
         //cout<<k<<" ";
         q.pop();
         for(int j: adj[k]){
            //cout<<j<<" ";
           if(dist[j]==-1) {
              dist[j]=dist[k]+1;
              q.push(j);
           }
         }
      }
   }

   if(dist[dst]==-1){
      cout<<"Impossible"<<endl;
      return;
   }

   cout<<dist[dst]<<endl;

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

   memset(prime,1,sizeof prime);

   for(int i=2;i*i<=9999;i++){
      if(prime[i])   for(int j=i*i;j<=9999;j+=i)  prime[j]=0;    
   }

   for(int i=1000;i<=9999;i++)  {
      if(prime[i]) {
        v.push_back(i);
      }
   }

   for(int i=0;i<v.size()-1;i++){
      for(int j=i+1;j<v.size();j++){
         if(connected(to_string(v[i]),to_string(v[j]))) {
               adj[v[i]].pb(v[j]);
               adj[v[j]].pb(v[i]);
         } 
      }
   }

   while(t--) solve();
   
   return 0;
} 
