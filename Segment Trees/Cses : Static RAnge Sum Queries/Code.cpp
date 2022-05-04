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
ll n,q;
ll trr[800001],arr[200001];
 
void build(int v,int tl,int tr){
   if(tl==tr)  trr[v]=arr[tl];
   else{
      int m=tl+(tr-tl)/2;
      build(2*v,tl,m);
      build(2*v+1 ,m+1,tr);
 
      trr[v]=trr[2*v]+trr[2*v+1];
   }
}
 
ll sum(int v,int tl,int tr,int l,int r){
   //cout<<l<<" "<<r<<" | ";
   if(l>r)  return 0;
   if(tl==l && tr==r)  return trr[v];
 
   int m=tl+(tr-tl)/2;
   return sum(v*2,tl,m,l,min(m,r)) +  sum(v*2+1,m+1,tr,max(m+1,l),r);
 
}
 
void update(int v,int tl,int tr,int pos,int val){
   if(tl==tr)  trr[v]=val;
   else{
      int m=tl+(tr-tl)/2;
      if(pos<=m)  update(v*2,tl,m,pos,val);
      else  update(v*2+1,m+1,tr,pos,val);
 
      trr[v]=trr[2*v]+trr[2*v+1];
   }
}
 
void solve(){
   cin>>n>>q;
   for(int i=0;i<n;i++)  cin>>arr[i];
 
   build(1,0,n-1);
  // for(int i=1;i<2*n;i++)  cout<<trr[i]<<" ";  
   
   int l,r;
   while(q--){
      cin>>l>>r;
      cout<<sum(1,0,n-1,l-1,r-1)<<endl;
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
