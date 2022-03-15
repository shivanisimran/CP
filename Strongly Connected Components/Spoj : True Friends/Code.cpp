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
vector<int>adj[105];
vector<int> tin, low;
vector<int>onstack;
stack<int> st;
int c,timer;
int n,m;
 
 
void dfs(int x){
   tin[x]=low[x]=timer++;
   st.push(x);
   onstack[x]=1;
 
   for(int j: adj[x]){
      if(tin[j]!=-1 && onstack[j])  low[x]=min(low[x],tin[j]);
      else if(tin[j]==-1){
         dfs(j);
         low[x]=min(low[x],low[j]);
      }
   }
   if(tin[x]==low[x]){
      c++;
      while(st.top()!=x) {
        // cout<<st.top()<<" ";
         onstack[st.top()]=0;
         st.pop() ; 
      }
      //cout<<st.top()<<"."<<endl;
      onstack[x]=0;
      st.pop();
  
   }
 
  
}
 
void solve(){ 
   cin>>n;
   for(int i=0;i<n;i++) adj[i].clear();
   
   char a;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          cin>>a;
          //cout<<a<<"-"<<i<<j<<" ";
          if(a=='Y')  adj[i].pb(j);
      }
   }
   // for(int i=0;i<n;i++){
   //    cout<<i<<" : ";
   //    for(int j: adj[i])  cout<<j<<" ";
   //    cout<<endl;
   // }
   
   
   onstack=vector<int>(n+1,0);
   low=vector<int>(n+1,-1);
   tin=vector<int>(n+1,-1);
   
   c=0,timer=0;
   while(!st.empty())   st.pop();
 
   for(int i=0;i<n;i++){
      if(tin[i]==-1)   dfs(i);
   }
   cout<<c<<endl;
  // cout<<endl;
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
   
   while(t--) solve();
   
   return 0;
}  
