# Longest path
## DAG
Topo sort
# MIS and MVC
## V < 64
ll bitmask as adj matrix
## Bipartite graph
MCBM = MVC
### Weighted
#### Min-weight vertex cover
Cost of left set as capacity from source to left set
Cost of right set as capacity from right set to sink
MWVC = MF value
#### Max-weight independent set
Sum of vertex cost minus MWVC
## Tree
DP/ Greedy
### Weighted
DP
# Min path cover
## DAG
Bipartite graph, left set has positive out-deg, right set has positive in-deg \
Edge are same as original graph \
MPC = V - MBCM
# 2-SAT
a | b = !a -> b & !b -> a \
Satisfiable iff no variable is in the same SCC as its negation
# Steiner tree
Given k required vertices, find the minimum cost needed to connect them
## k = 2
SSSP
## k = N
MST
## k = 3
For k vertices, there will be at most k - 2 steiner vertices. \
For k = 3, run SSSP from all the required vertices, then try each vertex as the potential steiner vertex.
## Tree
Do DFS \
If we are at vertex u and edge u -> v and there is a required vertex in the subtree of v, we have to take the edge
## V < 15 ~ 20
Try all subsets of vertices that are not required, and find the MST
# Min clique cover
Partition the vertices into cliques such that every clique is a complete graph
## 2 cliques
Complement graph must be bipartite

# Stirling numbers
S(n,k) is the number of ways to partition a set of n items into k non-empty subsets \
S(n,k) = k*S(n-1,k)+S(n-1,k-1)
S(n,1) = S(n,n) = 1
S(n,0) = S(0,k) = 0
# Bell number
Summation of S(n,k) for k=1 to k=n