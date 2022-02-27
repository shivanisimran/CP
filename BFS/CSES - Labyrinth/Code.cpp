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
   int n,m,a,b;
   cin>>n>>m;
   vector<vector<char>> g(n+1,vector<char>(m+1));

   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='A')  {
                a=i;
                b=j;
            }
       }
   }

    queue<pii>q;
    q.push({a,b});
    //int c=0;
    map<pii,pair<pii,char>>par;
    par[{a,b}]={{-1,-1},'0'};
    g[a][b]='#';

    int i,j,f=0;
    char p;
    while(!q.empty()){
        int l=q.size();
        
        while(l--){
            auto k=q.front();
            i=k.first,j=k.second;
            q.pop();

            if(j-1>=0  && g[i][j-1]!='#'){
                par[{i,j-1}]= {{i,j},'L'};
                if(g[i][j-1]=='B') {
                    f=1;
                    p='L';
                    break;
                }
                q.push({i,j-1}); 
                g[i][j-1]='#';
            }
            if(j+1<m  && g[i][j+1]!='#'){
                par[{i,j+1}]= {{i,j},'R'};
                if(g[i][j+1]=='B') {
                    f=1;
                    p='R';
                    break;
                }
                q.push({i,j+1}); 
                g[i][j+1]='#';
            }
            if(i-1>=0  && g[i-1][j]!='#'){
                par[{i-1,j}]= {{i,j},'U'};
                if(g[i-1][j]=='B') {
                    f=1;
                    p='U';
                    break;
                }
                q.push({i-1,j}); 
                g[i-1][j]='#';
            }
            if(i+1<n && g[i+1][j]!='#'){
                par[{i+1,j}]= {{i,j},'D'};
                if(g[i+1][j]=='B') {
                    f=1;
                    p='D';
                    break;
                }
                q.push({i+1,j});
                g[i+1][j]='#';
            }

        }
       // c++;
        if(f)  break;
    }
    if(f==0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    //cout<<c<<endl;
    string s;
    s+=p;
   
    int x,y;
    while(i!=a || j!=b){
     
        s+=par[{i,j}].second;
        x=par[{i,j}].first.first;
        y=par[{i,j}].first.second;
        i=x,j=y;
       
    }
    cout<<s.length()<<endl;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    
   
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

   while(t--)   solve();
 
   return 0;
}
