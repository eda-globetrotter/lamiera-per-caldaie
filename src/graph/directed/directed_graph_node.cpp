/**
 * Graph package:
 * Module to implement graphs and networks.
 *
 * directed_graph_node class:
 * Class to represent node of basic directed graph.
 *
 * IMPORTANT NOTES:
 * This is for an adjacency list implementation of a graph.
 * Assume that the ID of each node is unique for all the nodes in
 *	the graph.
 * Hence, the node ID can be used to identify a given node.
 * The terms "node" and "vertex", of a graph, are used synonymously
 *	in our software AggieMC.
 * Enable support of multigraphs and hypergraphs.
 * Other boolean comparisons can be implemented by overloading the
 *	operator child class.
 * Definition of the class directed_graph_node depends on the
 *	definition of the class directed_graph_edge.
 *
 *
 *
 *
 *
 * @author Zhiyang Ong
 * @version 1.0.0
 * @since March 1, 2015
 *
 
 * The MIT License (MIT)
 *
 * Copyright	(C)	<2015>	<Zhiyang Ong>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * Email address: echo "cukj -wb- 23wU4X5M589 TROJANS cqkH wiuz2y 0f Mw Stanford" | awk '{ sub("23wU4X5M589","F.d_c_b. ") sub("Stanford","d0mA1n"); print $5, $2, $8; for (i=1; i<=1; i++) print "6\b"; print $9, $7, $6 }' | sed y/kqcbuHwM62z/gnotrzadqmC/ | tr 'q' ' ' | tr -d [:cntrl:] | tr -d 'ir' | tr y "\n"		Don't compromise my computing accounts. You have been warned.
 */

// Import packages from the software
#include "directed_graph_node.hpp"

// ==================================================================

/**
 * Default constructor.
 *
 * Values for private variables are set to invalid values.
 */
directed_graph_node::directed_graph_node() {
	/**
	 * Assign node ID to the maxium unsigned long long int value,
	 *	so that it represents an INVALID node ID.
	 */
	node_ID = ULLONG_MAX;
	// Assign private instance variables to NULL.
/*
	outgoing_edges = NULL;
	incoming_edges = NULL;
*/

/*
	string err_msg = "Default constructor should not be used!!!";
	throw new violated_assertion(err_msg);
*/
}

// -----------------------------------------------------------------
// Standard constructors.

/**
 * Standard constructor.
 * @param node_id_num:	The ID number of the node.
 */
directed_graph_node::directed_graph_node(unsigned long long int node_id_num) {
	// Assign the Node ID to be node_id_num.
	node_ID = node_id_num;
	// Assign other private instance variables to NULL.
/*	
	outgoing_edges = NULL;
	incoming_edges = NULL;
*/
}


// -----------------------------------------------------------------

/**
 * Default destructor.
 *	Carry out dynamic memory management.
 */
directed_graph_node::~directed_graph_node() {
}

// ==================================================================

// Accessor functions.

/**
 * Function to get the incoming edges from this node.
 * @param - None.
 * @return - The set of incoming edges from this node.
 */
//set<pair<unsigned long long,bool> > directed_graph_node::get_incoming_edges() {
dg_edge_set directed_graph_node::get_incoming_edges() {
	return incoming_edges;
}


/**
 * Function to get the outgoing edges from this node.
 * @param - None.
 * @return - The set of outgoing edges from this node.
 */
//set<pair<unsigned long long,bool> > directed_graph_node::get_outgoing_edges() {
dg_edge_set directed_graph_node::get_outgoing_edges() {
	return outgoing_edges;
}


/**
 * Function to get the ID of the node.
 * @param - None.
 * @return - The ID of this node.
 */
unsigned long long int directed_graph_node::get_node_ID() {
	return node_ID;
}

// ==================================================================

// Mutator functions.

/**
 * Function to set the ID of the node.
 * @param temp_ID:	The new ID to replace the current ID of the node.
 * @post			Ensure that the ID has been replaced.
 * @return - Nothing.
 */
void directed_graph_node::set_node_ID(const unsigned long long int &temp_ID) {
	// Modify the node ID to temp_ID.
	node_ID = temp_ID;
	
	// Postcondition. Node ID should be replaced and equal to temp_ID.
	if(node_ID != temp_ID) {
		throw new violated_postcondition("=	Node ID is not modified !!!!");
	}
}


/**
 * Function to add a set of incoming edges to the initial/current
 *	set of incoming edges.
 * @param set_incoming_links: A set of incoming edges to be added to
 *		the current set of incoming edges.
 * @post		Ensure that the difference in the size of
 *					incoming links is the size of the set of
 *					desired incoming links to be added.
 *					#actually added unique links = #desired added links
 * @return - Nothing.
 */
//void directed_graph_node::add_set_of_incoming_edges(const set<pair<unsigned long long,bool> > &set_incoming_links) {
void directed_graph_node::add_set_of_incoming_edges(const dg_edge_set &set_incoming_links) {

	// Set up checkers for testing postconditions.
	// Initial number of incoming edges.
	unsigned long long int initial_incoming_links_size = incoming_edges.size();
	
	// Add the incoming edges.
	incoming_edges.insert(set_incoming_links.begin(), set_incoming_links.end());
	
	// Final number of incoming edges.
	unsigned long long int final_incoming_links_size = incoming_edges.size();
	// Difference due to addition of set of incoming edges.
	final_incoming_links_size = final_incoming_links_size - initial_incoming_links_size;
	
	/**
	 * Postcondition:
	 * Is (difference due to addition) = size of added set?
	 */
	if(final_incoming_links_size = set_incoming_links.size()) {
		throw new violated_postcondition("=	Error in adding incoming links !!!!");
	}
}


/**
 * Function to add a set of outgoing edges to the initial/current
 *	set of outgoing edges.
 * @param set_outgoing_links: A set of outgoing edges to be added to
 *		the current set of outgoing edges.
 * @post		Ensure that the difference in the size of
 *					outgoing links is the size of the set of
 *					desired outgoing links to be added.
 *					#actually added unique links = #desired added links
 * @return - Nothing.
 */
//void directed_graph_node::add_set_of_outgoing_edges(const set<pair<unsigned long long,bool> > &set_outgoing_links) {
void directed_graph_node::add_set_of_outgoing_edges(const dg_edge_set &set_outgoing_links) {

	// Set up checkers for testing postconditions.
	// Initial number of outgoing edges.
	unsigned long long int initial_outgoing_links_size = outgoing_edges.size();
	
	// Add the outgoing edges.
	outgoing_edges.insert(set_outgoing_links.begin(), set_outgoing_links.end());
	
	// Final number of outgoing edges.
	unsigned long long int final_outgoing_links_size = outgoing_edges.size();
	// Difference due to addition of set of outgoing edges.
	final_outgoing_links_size = final_outgoing_links_size - initial_outgoing_links_size;
	
	/**
	 * Postcondition:
	 * Is (difference due to addition) = size of added set?
	 */
	if(final_outgoing_links_size = set_outgoing_links.size()) {
		throw new violated_postcondition("=	Error in adding outgoing links !!!!");
	}
}


/**
 * Function to add an incoming edge to the current set of
 *	incoming edges.
 * If an incoming edge is added, the size should increase by 1.
 * @param incoming_link:	An incoming edge to be added to the
 *								set of incoming links.
 * @post	If the edge is in the set of incoming edges, ignore it.
 *				Else, add it to the set of incoming edges.
 *				Require: change_in_num_incoming_edges <= 1
 * @return - Nothing.
 */
void directed_graph_node::add_incoming_edge(const directed_graph_edge &incoming_link) {
	// Intial number of incoming edges.
	unsigned long long int initial_num_incoming_edges = incoming_edges.size();
	
	// Add the incoming edge.
	incoming_edges.insert(incoming_link);

	// Final number of incoming edges.
	unsigned long long int final_num_incoming_edges = incoming_edges.size();
	// Difference due to addition of incoming edge.
	final_num_incoming_edges = final_num_incoming_edges - initial_num_incoming_edges;
	// Has number of incoming edges for this node increased by >1 ?
	if(1 < final_num_incoming_edges) {
		throw new violated_postcondition("=	Extra incoming edge(s) is/are added!!!!");
	}
}


/**
 * Function to add an outgoing edge to the current set of
 *	outgoing edges.
 * If an outgoing edge is added, the size should increase by 1.
 * @param outgoing_link:	An outgoing edge to be added to the
 *								set of outgoing links.
 * @post	If the edge is in the set of outgoing edges, ignore it.
 *				Else, add it to the set of outgoing edges.
 *				Require: change_in_num_outgoing_edges <= 1
 * @return - Nothing.
 */
void directed_graph_node::add_outgoing_edge(const directed_graph_edge &outgoing_link) {
	// Intial number of outgoing edges.
	unsigned long long int initial_num_outgoing_edges = outgoing_edges.size();
	
	// Add the outgoing edge.
	outgoing_edges.insert(outgoing_link);

	// Final number of outgoing edges.
	unsigned long long int final_num_outgoing_edges = outgoing_edges.size();
	// Difference due to addition of outgoing edge.
	final_num_outgoing_edges = final_num_outgoing_edges - initial_num_outgoing_edges;
	// Has number of outgoing edges for this node increased by >1 ?
	if(1 < final_num_outgoing_edges) {
		throw new violated_postcondition("=	Extra outgoing edge(s) is/are added!!!!");
	}
}


/**
 * Function to remove an incoming edge from the current set of
 *	incoming edges.
 * @param node_ID_removal:	The node ID of a node to be removed
 * @return - Nothing.
 */
void directed_graph_node::remove_incoming_edge(const
	unsigned long long int &node_ID_r]
	// Enumerate all source nodes in the set of incoming edges.
//	dg_edge_set_p desp = outgoing_edges.find(temp_node);
	for(dg_edge_set_p desp = outgoing_edges.begin(); desp != outgoing_edges.end(); ++desp) {
		// Check if its source node has the ID node_ID_r.
		// Call function from the edge class.
	}

	/**
	 * Remove node with the ID, node_ID_removal, if it is in
	 *	the aforementioned set (set of incoming edges).
	 */
	pair_dgedgesetp_bool = outgoing_edges.erase();
}


/**
 * Function to remove an incoming edge from the current set of
 *	incoming edges.
 * @param incoming_edge_rm:		Incoming edge to be removed.
 * @return - Nothing.
 */
void directed_graph_node::remove_incoming_edge(const directed_graph_edge &incoming_edge_rm) {
}


/**
 * Function to remove an outgoing edge from the current set of
 *	outgoing edges.
 * @param
 * @return - Nothing.
 */
void directed_graph_node::remove_outgoing_edge(const unsigned long long int &node_ID_removal) {
}


/**
 * Function to remove an outgoing edge from the current set of
 *	outgoing edges.
 * @param outgoing_edge_rm:		Outgoing edge to be removed.
 * @return - Nothing.
 */
void directed_graph_node::remove_outgoing_edge(const directed_graph_edge &outgoing_edge_rm) {
}


