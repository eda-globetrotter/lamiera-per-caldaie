# Graph package

## Directed graph

### Data structures for directed graphs
AND-inverter graphs, AIGs
binary decision diagrams, BDDs
binary search trees
trees
directed acyclic graphs, DAGs




### Algorithms for directed graphs
topological sort
reverse topological sort
A*







## Undirected graph

### Data structures for undirected graphs


### Algorithms for undirected graphs
minimum spanning trees: Prim-Jarnik algorithm, and Kruskal's algorithm
longest increasing subsequence problem
shortest common subsequence problem; see common subexpression elimination











## From the sandbox, the following shortcuts are being used.
int_set
pair_intboolp_bool
node_set
pair_nodesetp_bool
node_set_p





## Data Structure Representations for Graphs

### Operations that I care about:
+ add()
+ remove()
+ search()
+ size()
+ empty()
+ begin()
+ end()






### Adjacency List



### Adjacency Matrix

Adjacency matrix: for sparse graphs, it takes up a lot of space


### Edge List

Keep an unordered list of all edges.
+ different to find a given edge, (u,v)
+ different to find a set of all edges incident to a vertex v, which is important for deletion or modification of the vertex v
+ $|E| \approx |V|^{2}$
+ Number of edges in a directed graph: $n(n - 1)$.
+ Number of edges in a undirected graph: $\frac{n(n - 1)}{2}$.
+ $|E| \subseteq V \times V \dots$ list of lists 


### Edge map

List/vector of maps


### Hash maps
+ unordered associative containers
+ associative containers (ordered by keys) tend to be ordered

Value and key comparison: in maps are complicated.

Accessing elements of a map is more complicated than that of a set. Go to key, then value.

sets and maps in the C++ STL are typically implemented as BSTs...






































