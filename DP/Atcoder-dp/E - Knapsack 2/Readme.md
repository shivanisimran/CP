Problem link : [https://atcoder.jp/contests/dp/tasks/dp_e]

Approach :  In this problem, we have to change the states of DP, which we use in usual knapsack problem.

The usual knapsack DP has the following state :
DP[i][j] = v

This means that v is the maximum value we can get using the first i items, having total weight j.

In the problem, although the weights are huge, the values and number of items is small. So, we can base our DP state on that. Then, 
DP [i][j] = w

This means that w is the minimum weight with which we can get total value j using first i items.

To find the maximum value for a given weight W, you would iterate over DP [n][j] and take the maximum j for which DP [n][j] is less than W.
