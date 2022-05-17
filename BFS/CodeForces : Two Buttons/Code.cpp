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
   ll n,m;
   cin>>n>>m;

   unordered_map<ll,ll> d;

   queue<ll> q;
   q.push(n);
   d[n]=0;

   while(!q.empty()){
      ll k=q.front();
      q.pop();
      if(k==m){
         cout<<d[k];
         return;
      }  

      if(!d[k-1] && k-1!=n){
         d[k-1]=d[k]+1;
         q.push(k-1);
      }
      if(k<=m){
         if(!d[k*2] && k*2!=n){
            d[k*2]=d[k]+1;
            q.push(k*2);
         }
      }
      

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
