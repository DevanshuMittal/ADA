'''
input adjacency matrix
select first as source
copy the edges for source
select min dist 
print min dist and node
check if adjacency matrix has lesser value then take that
else previous row value
select that node
'''
num=5
li=['A','B','C','D','E']
adj_mat=[[0,1,5,4,3],
         [9,0,3,1,6],
         [2,3,0,7,2],
         [1,2,9,0,4],
         [7,7,4,8,0]]
























adj_mat=[[0,1,5,4,3],[9,0,3,1,6],[2,3,0,7,2],[1,2,9,0,4],[7,7,4,8,0]]
li=['A','B','C','D','E']
def min(node):
    min_index=0
    for i in range(len(li)-1):
        if(adj_mat[node][i+1]<adj_mat[node][min_index] and adj_mat[node][i+1]!=0):
            min_index=i+1
    return min_index
dist=0
for i in range(len(li)):
    min_index=min(i)
    dist+=adj_mat[i][min_index]
    print("Vertex: ",min_index)
    print("Weight of vertex",adj_mat[i][min_index])
    for j in range(len(li)-i):
        adj_mat[j][min_index]=99999
    print("Total cost is ",dist)


# Prim's Algorithm in Python


INF = 9999999
# number of vertices in graph
V = 5
# create a 2d array of size 5x5
# for adjacency matrix to represent graph
G = [[0,1,5,4,3],[9,0,3,1,6],[2,3,0,7,2],[1,2,9,0,4],[7,7,4,8,0]]
# create a array to track selected vertex
# selected will become true otherwise false
selected = [0, 0, 0, 0, 0]
# set number of edge to 0
no_edge = 0
# the number of egde in minimum spanning tree will be
# always less than(V - 1), where V is number of vertices in
# graph
# choose 0th vertex and make it true
selected[0] = True
# print for edge and weight
print("Edge : Weight\n")
while (no_edge < V - 1):
    # For every vertex in the set S, find the all adjacent vertices
    #, calculate the distance from the vertex selected at step 1.
    # if the vertex is already in the set S, discard it otherwise
    # choose another vertex nearest to selected vertex  at step 1.
    minimum = INF
    x = 0
    y = 0
    for i in range(V):
        if selected[i]:
            for j in range(V):
                if ((not selected[j]) and G[i][j]):  
                    # not in selected and there is an edge
                    if minimum > G[i][j]:
                        minimum = G[i][j]
                        x = i
                        y = j
    print(str(x) + "-" + str(y) + ":" + str(G[x][y]))
    selected[y] = True
    no_edge += 1