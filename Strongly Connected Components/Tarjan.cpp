/*
Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.

*/

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> ans;
    int tin[100006],low[100006],onstack[100006];
    int timer;
    stack<int> st;
    
    void dfs(int node, vector<int> adj[]){
        st.push(node);
        onstack[node]=1;
        tin[node]=low[node]=timer++;
        
        for(int j: adj[node]){
            
            if(onstack[j] && tin[j]!=-1){
                low[node]=min(low[node],tin[j]);
            }
            
            else if(tin[j]==-1){
               dfs(j,adj);
               low[node]=min(low[node],low[j]);
            }
        }
        
        if(tin[node]==low[node]){
            vector<int> v;
            while(st.top()!=node){
                int u=st.top();
                v.push_back(u);
                st.pop();
                onstack[u]=0;
                
            }
            v.push_back(node);
            onstack[node]=0;
            st.pop();
            
            if(!v.empty()){
                sort(v.begin(),v.end());
                  ans.push_back(v) ;
            } 
        }
        
       
    }
    
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        //code here
        memset(tin,-1,sizeof tin);
        memset(low,-1,sizeof low);
        memset(onstack,0,sizeof onstack);
        while(!st.empty())  st.pop();
        
        timer=0;
        
        for(int i=0;i<n;i++){
            if(tin[i]==-1)  dfs(i,adj);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
