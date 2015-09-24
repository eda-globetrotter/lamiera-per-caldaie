# Graph package

## Directed graph

### Data structures for directed graphs
+ AND-inverter graphs, AIGs
+ binary decision diagrams, BDDs
+ binary search trees
+ trees
+ directed acyclic graphs, DAGs




### Algorithms for directed graphs
+ topological sort
+ reverse topological sort
+ A*







## Undirected graph

### Data structures for undirected graphs


### Algorithms for undirected graphs
+ minimum spanning trees: Prim-Jarnik algorithm, and Kruskal's algorithm
+ longest increasing subsequence problem
+ shortest common subsequence problem; see common subexpression elimination











## From the sandbox, the following shortcuts are being used.
+ int_set
+ pair_intboolp_bool
+ node_set
+ pair_nodesetp_bool
+ node_set_p





## Data Structure Representations for Graphs

The adjacency list is recommended for representing sparse graphs, while the adjacency matrix is recommended for representing dense graphs. The former requires *\Theta(V + E)* memory space, while the latter requires *\Theta(V^{2})* memory space \\cite{Cormen2009}.

### Operations that I care about:
+ add()
+ remove()
+ search()
+ size()
+ empty()
+ begin()
+ end()

See Tables 14.1 of \\cite{Goodrich2013} (Python version) for the computational time complexities of these operations.





### Adjacency List

See \\cite[Figure 14.5, pp. 630]{Goodrich2013} (Python version) for a more intuitive representation/diagram of the adjacency list structure.

Compared to the edge list, the adjacency list adds extra information to enable edges incident on a given node to be found. Consequently, the neigboring nodes of the given node can also be found via the edges. This implies that functions that depending on finding edges incident on a node can be executed faster \\cite[pp. 603]{Goodrich2011}.

One way to store the extra information is: each node stores a collection of adjacent nodes, via its incident edges; and each node also stores a reference to each of its incident edges. Another way to store the information is: each node stores a reference to each of its incident edges. These references can be used to determine the adjacent nodes of the given node \\cite[pp. 603]{Goodrich2011}.

The main advantage of the adjacency list is that it provides nodes (direct) access to its incident edges and it also provides edges (direct) access to its end nodes \\cite[pp. 603]{Goodrich2011}.

It enables operations to be performed faster on the adjacency list representation than on the edge list representation \\cite[pp. 603]{Goodrich2011}.

Computational space complexity: **O(|V| + |E|)** \\cite[pp. 604]{Goodrich2011}.


### Adjacency Matrix

See \\cite[Figure 14.7, pp. 633]{Goodrich2013} (Python version) for a more intuitive representation/diagram of the adjacency list structure.

Adjacency matrix: for sparse graphs, it takes up a lot of space. For undirected graphs, the upper and lower triangular matrices are symmetrical with respect to each other along the diagonal. For directed graphs, the upper and lower triangular matrices differ (i.e., not symmetrical about any axis).

With regards to implementation, if the edge weight can be treated as a number, and the nodes do not contain any unique/special element or set of elements, a 2-D matrix of numbers (e.g., int[][], double[][], or bool[][]) can be used to represent the 2-D array/matrix of nodes in the graph/network/circuit. Each entry in this 2-D array/matrix would be the weight of the edge connecting the row-indexed node with the column-indexed node. If a pair of nodes (i, j) (indicated as an entry array[i][j] in the 2-D array/matrix) is not connected by an edge, the entry shall be filled with the maximum value for the chosen number-based data type, such as ULLONG_MAX. Here, ULLONG_MAX is analogous to infinity, which means that no connections exists between node *i* and node *j*.

Another implementation style: If the node does not contain specific information, but the edge contains various information, the node's ID needs to be uniquely mapped into [1, n]; uniquely map the node's ID into the range 1 to *n*, inclusive, without conflicts (i.e., mapping multiple nodes' IDs into the same integer between 1 and *n* is forbidden). This mapping, via the dictionary ADT, allows edges (or references to edge objects) to be stored in a 2-D matrix of edges (or references to edge objects). Here, if no edge connects a given pair of nodes *i* and *j*, the entry array[i][j] shall point to *NULL*.

Yet another implementation style: If the node and the edge contain various information each, a separate container of node objects is needed to augment information stored in a 2-D matrix of edge objects.

Compared to the edge list, and just like the adjacency list, the adjacency matrix adds extra information to enable adjacent nodes (connected by an edge, between pairs of nodes) to be found in constant time
\\cite[pp. 605]{Goodrich2011}















Computational space complexity: **O(|V| + |E|)** \\cite[pp. 60?]{Goodrich2011}.


### Edge List

+ Keep an unordered list of all edges.
+ Difficult to find a given edge, *(u,v)*
+ Difficult to find a set of all edges incident to a node *v*, which is important for deletion or modification of the node *v*
+ *|E| \approx |V|^{2}*
+ Number of edges in a directed graph: *n(n - 1)*.
+ Number of edges in a undirected graph: *\frac{n(n - 1)}{2}*.
+ *|E| \subseteq V \times V \dots* list of lists 

See \\cite[Figure 14.4, pp. 628]{Goodrich2013} (Python version) for a more intuitive representation/diagram of the edge list structure.

It is simple to implement, but is not an efficient representation of graphs \\cite[pp. 600-601]{Goodrich2011}.

Computational space complexity: **O(|V| + |E|)** \\cite[pp. 602]{Goodrich2011}.

The container for nodes *V* can be implemented with a dictionary \\cite[pp. 601]{Goodrich2011}. The container for edges *E* can be implemented with a list or dictionary (or associative array, map, symbol table, or associative container) [https://en.wikipedia.org/wiki/Associative_array], using the element as the key and edge as the value \\cite[pp. 601]{Goodrich2011}. Here, a dictionary is a set/collection of (key,value) pairs; or rather, it is an abstract data type (ADT) that maps keys to values. Dictionary implementations of the containers for *V* and *E* allow searching for specific elements to be more convenient \\cite[pp. 601]{Goodrich2011}.

The main feature of this data structure is that a given edge allows direct access to vertices that it is incident on/upon \\cite[pp. 601]{Goodrich2011}. However, for a given node, it is difficult to determine which edges are incident upon it; this requires enumerating all the edges in *E*. This requires all other functions depending on this "function"/event to on in *O(|E|)*. This is because the container for storing edges is unordered \\cite[pp. 602]{Goodrich2011}.

Note that in *C++*, class templates in the *C++ STL* refer to a group of class templates for the ordered associative containers: set, map, multiset, and multimap [https://en.wikipedia.org/wiki/Associative_containers].


### Edge map

List/vector of maps


### Hash maps
+ unordered associative containers
+ associative containers (ordered by keys) tend to be ordered

Value and key comparison: in maps are complicated.

Accessing elements of a map is more complicated than that of a set. Go to key, then value.

## Additional Information About Data Structures

sets and maps in the C++ STL are typically implemented as binary search trees (BSTs)\...


## Design of Node class and Edge class for Directed Graph



#### Node class
+ Fields
	+ int node_id
	+ elem store in the node (object???/class)
	+ set\<edge> outgoing_edges
	+ set\<edge> incoming_edges
	+ \<set> outgoing_edges and \<set> incoming_edges avoids multigraphs with the set container. This is implies that there are no parallel edges between *u* and *v*.
		
		Enable implementation of hypergraphs, where an edge can connect any number of nodes.

			position in *V*.
+ Functions
	+ set\<edge> get_incident_edges()
		
		Return incoming_edges *\cup* outgoing_edges.
	+ set\<edge> get_incoming_edges()
	+ set\<edge> get_outgoing_edges()
	+ bool is_adjacent_to(node v)
	
		Return true iff *u* and *v* are adjacent.
	+ elem get_element()




#### Edge class
+ Fields
	+ values stored in the interconnect, which can be an object or a set of fields.

			position in *E*.

+ Functions
	+ set\<node> get_destination_nodes()
	
		Return set of destination node(s)\.
	+ set\<node> get_source_nodes()
	
		Return set of source node(s)\.
	+ set\<node> get_opposite_node(node v)
	
		If (v = source node),

			return destination node.

		Else If (v = destination node),

			return source node.

		Else,

			node is neither a source nor destination node.

			throw an error/exception.
	+ bool is_adjacent_to(edge f)

		Return true if this/current edge *e* is adjacent to edge *f*.
	+ bool is_incident_on(node v)
	
		Return true if current edge is incident on *v*.
	+ erase_node(v)
	
		Remove node v and all its incident edges.

+ If I do not use an edge class, I cannot represent information about an edge without using a pair or a struct. Hence, I used a class for representing the edges.





#### Graph class
+ Fields
	+ set\<node> nodes
	+ set\<edge> edges
+ Functions
	+ set\<node> get_nodes()
	+ set\<edge> get_edges()
	+ node insert_node(elem x);
	
		Return node storing element *x*.
	+ edge insert_edge(node v, node w, elem x)
	
		If (*v = w*),
		
			return NULL (because self-loops are not allowed).

		Else,

			return new directed edge from node *v* to node *w*, storing element *x*.

	+ bool erase_node(node v)

		Remove node *v* and all its incident edges.
		
	+ bool erase_edge(edge e)
	
		Remove edge *e*.
		
	+ unsigned long long int node_count()
	+ unsigned long long int edge_count()
	+ edge get_edge(node u, node v)
	
		Return edge *(u,v)* if edge from node *u* to node *v* exists. Else, return null.
	+ unsigned long long int out_degree(v)
	+ unsigned long long int in_degree(v)
	+ set\<edge> outgoing_edges(node v)
	+ set\<edge> incoming_edges(node v)






















