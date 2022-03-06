Problem : [https://www.spoj.com/problems/LABYR1/] 

Approach : We have to perform dfs to find the longest path between any two nodes.
But here, we also need to keep track of the "coordinates" that the best DFS ends with because these are used for subsequent DFS calls.
