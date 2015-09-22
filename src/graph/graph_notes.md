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

+ Keep an unordered list of all edges.
+ Different to find a given edge, *(u,v)*
+ Different to find a set of all edges incident to a node *v*, which is important for deletion or modification of the node *v*
+ *|E| \approx |V|^{2}*
+ Number of edges in a directed graph: *n(n - 1)*.
+ Number of edges in a undirected graph: *\frac{n(n - 1)}{2}*.
+ *|E| \subseteq V \times V \dots* list of lists 


### Edge map

List/vector of maps


### Hash maps
+ unordered associative containers
+ associative containers (ordered by keys) tend to be ordered

Value and key comparison: in maps are complicated.

Accessing elements of a map is more complicated than that of a set. Go to key, then value.

## Additional Information About Data Structures

sets and maps in the C++ STL are typically implemented as binary search trees (BSTs)...


## Design of Node class and Edge class



#### Node class
+ Fields
	+ int node_id
	+ elem store in the node (object???/class)
	+ set\<edge> outgoing_edges
	+ set\<edge> incoming_edges
	+ \<set> outgoing_edges and \<set> incoming_edges avoids multigraphs with the set container. This is implies that there are no parallel edges between *u* and *v*.
		
		Enable implementation of hypergraphs, where an edge can connect any number of nodes.
+ Functions
	+ set\<edge> get_incident_edges()
		
		Return incoming_edges *\cup* outgoing_edges
	+ set\<edge> get_incoming_edges()
	+ set\<edge> get_outgoing_edges()
	+ bool is_adjacent_to(node v)
	
		Return true iff *u* and *v* are adjacent
	+ elem get_element()




#### Edge class
+ Fields
	+ values stored in the interconnect, which can be an object or a set of fields
+ Functions
	+ set\<node> get_destination_nodes()
	
		Return set of destination node(s)
	+ set\<node> get_source_nodes()
	
		Return set of source node(s)
	+ set\<node> get_opposite_node(node v)
	
		If (v = source node),

			return destination node.

		Else If (v = destination node),

			return source node.

		Else

			node is neither a source nor destination node

			throw an error/exception
	+ bool is_adjacent_to(edge f)

		Return true if this/current edge *e* is adjacent to edge *f*.
	+ bool is_incident_on(node v)
	
		Return true if current edge is incident on *v*
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























