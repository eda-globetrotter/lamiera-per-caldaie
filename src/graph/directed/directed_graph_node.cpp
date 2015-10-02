/**
 * Graph package:
 * Module to implement graphs and networks.
 *
 * directed_graph_node class:
 * Class to represent node of basic directed graph.
 *
 * IMPORTANT NOTES:
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
set<directed_graph_edge*> directed_graph_node::get_incoming_edges() {
	return incoming_edges;
}


/**
 * Function to get the outgoing edges from this node.
 * @param - None.
 * @return - The set of outgoing edges from this node.
 */
//set<pair<unsigned long long,bool> > directed_graph_node::get_outgoing_edges() {
set<directed_graph_edge*> directed_graph_node::get_outgoing_edges() {
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
 * Function to add a set of incoming edges to the current
 *	set of incoming edges.
 * @param set_incoming_links: A set of incoming edges to be added to
 *		the current set of incoming edges.
 * @post		Ensure that the difference in the size of
 *					incoming links is the size of the set of
 *					added incoming links.
 * @return - Nothing.
 */
//void directed_graph_node::add_set_of_incoming_edges(const set<pair<unsigned long long,bool> > &set_incoming_links) {
void directed_graph_node::add_set_of_incoming_edges(const set<directed_graph_edge*> &set_incoming_links) {

	// Set up checkers for testing postconditions.
	// Current number of incoming edges.
	int current_incoming_links_size = incoming_edges.size();
	
	// Add the incoming edges.
	incoming_edges.insert(set_incoming_links.begin(), set_incoming_links.end());
	
	// Final number of incoming edges.
	int final_incoming_links_size = incoming_edges.size();
	// Difference due to addition of set of incoming edges.
	final_incoming_links_size = final_incoming_links_size - current_incoming_links_size;
	
	// Postcondition: Is (difference due to addition) = size of added set?
	if(final_incoming_links_size != set_incoming_links.size()) {
		throw new violated_postcondition("=	Error in adding incoming links !!!!");
	}
}


/**
 * Function to add a set of outgoing edges to the current
 *	set of outgoing edges.
 * @return - Nothing.
 */
//void directed_graph_node::add_set_of_outgoing_edges(const set<pair<unsigned long long,bool> > &set_outgoing_links) {
void directed_graph_node::add_set_of_outgoing_edges(const set<directed_graph_edge*> &set_outgoing_links) {

	// Set up checkers for testing postconditions.
	// Current number of incoming edges.
	int current_incoming_links_size = incoming_edges.size();
	
	// Add the incoming edges.
	outgoing_edges.insert(set_outgoing_links.begin(), set_outgoing_links.end());
}


/**
 * Function to add an incoming edge to the current set of
 *	incoming edges.
 * @return - Nothing.
 */
void directed_graph_node::add_incoming_edge(const directed_graph_edge &incoming_link) {
	// Is there an edge in the set of incoming edges with given ID?
/*
	if() {
	}else{
	}
*/
}

/**
 * Function to add an outgoing edge to the current set of
 *	outgoing edges.
 * @return - Nothing.
 */
void directed_graph_node::add_outgoing_edge(const directed_graph_edge &outgoing_link) {
}

/**
 * Function to remove an incoming edge from the current set of
 *	incoming edges.
 * @return - Nothing.
 */
void directed_graph_node::remove_incoming_edge(const unsigned long long &node_ID_removal) {
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
void directed_graph_node::remove_outgoing_edge(const unsigned long long &node_ID_removal) {
}


/**
 * Function to remove an outgoing edge from the current set of
 *	outgoing edges.
 * @param outgoing_edge_rm:		Outgoing edge to be removed.
 * @return - Nothing.
 */
void directed_graph_node::remove_outgoing_edge(const directed_graph_edge &outgoing_edge_rm) {
}


