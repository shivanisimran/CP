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
// vector<int> adj[1000001];


void solve(){ 
   string s,d;
   cin>>s>>d;
   int x1,y1,x2,y2;
   x1=s[0]-'a'+1,y1=s[1]-'0';
   x2=d[0]-'a'+1,y2=d[1]-'0';
   queue<pair<int,int>>q;
   q.push({x1,y1});
   int c=0;
   while(!q.empty()){
      int n=q.size();
      while(n--){
         auto k=q.front();
         q.pop();
         int a=k.first,b=k.second;
         if(a==x2 && b==y2){
            cout<<c<<endl;
            return;
         }
         if((a+2)<=8 && (b+1)<=8){
               q.push({a+2,b+1});    
         }
         if((a+1)<=8 && (b+2)<=8){
               q.push({a+1,b+2});
         }
         if((a-2)>0 && (b+1)<=8){
               q.push({a-2,b+1});
         }
         if((a+2)<=8 && (b-1)>0){
               q.push({a+2,b-1});
         }
         if((a-1)>0 && (b+2)<=8){
               q.push({a-1,b+2});
         }
         if((a+1)<=8 && (b-2)>0){
               q.push({a+1,b-2});
         }
         if((a-1)>0 && (b-2)>0){
               q.push({a-1,b-2});
         }
         if((a-2)>0 && (b-1)>0){
               q.push({a-2,b-1});
         }

      }
      c++;
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
   
   int t;    //t=1;
   cin>>t;

   while(t--)   solve();
 
   return 0;
}
