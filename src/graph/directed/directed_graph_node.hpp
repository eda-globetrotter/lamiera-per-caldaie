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
//	Importing from the Utility module.
#include "../../utilities/printer.hpp"
#include "../../utilities/violated_assertion.hpp"
#include "../../utilities/violated_precondition.hpp"
#include "../../utilities/violated_postcondition.hpp"
//	Importing from the Graph/Directed module
#include "directed_graph_edge.hpp"

// Import packages from the C++ STL
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <limits.h>			// For std::LONG_MIN
#include <set>

#ifndef __DIRECTED_GRAPH_NODE_H
#define __DIRECTED_GRAPH_NODE_H
using namespace std;

// =========================================================

// Shortcut to container of directed_graph_edge pointers.
typedef set<directed_graph_edge*> dg_edge_set;
/**
 * Shortcut to represent an iterator to the container of
 *	directed_graph_edge pointers.
 */w
typedef set<directed_graph_edge*>::iterator dg_edge_set_p;
/**
 * Shortcut to a pair representing an iterator to the
 *	container of directed_graph_edge pointers and a boolean
 *	flag representing the success of a set operation.
 */
typedef pair<dg_edge_set, bool> pair_dgedgesetp_bool;

// =========================================================

// Class definition of the directed_graph_node class
class directed_graph_node {
	// Publicly accessible data members, constructors, and functions
	public:
		// Default constructor.
		directed_graph_node();
		// Standard constructors.
		directed_graph_node(unsigned long long int node_id_num);
		// Default destructor.
		~directed_graph_node();

		// -----------------------------------------------------
		
		// Define enums for the software.
		
		/**
		 * Type of the logic cell (i.e., logic gate) that is used
		 *	in the AIG.
		 */
/*
		enum cell_type {
			AND_CONJUNCTION,
			INVERTER
		};
*/
		
		// -----------------------------------------------------
		
		// Define headers for functions...
	
		// Accessor functions.
		
		/**
		 * Function to get the incoming edges from this node.
		 */
		dg_edge_set get_incoming_edges();
		/**
		 * Function to get the outgoing edges from this node.
		 */
		dg_edge_set get_outgoing_edges();		
		// Function to get the ID of the node.
		unsigned long long int get_node_ID();

		// -----------------------------------------------------

		// Mutator functions.
		
		// Function to set the ID of the node.
		void set_node_ID(const unsigned long long int &temp_ID);
		
		/**
		 * Function to add a set of incoming edges to the current
		 *	set of incoming edges.
		 */
//		void add_set_of_incoming_edges(const set<pair<unsigned long long,bool> > &set_incoming_links);
		void add_set_of_incoming_edges(const dg_edge_set &set_incoming_links);
		/**
		 * Function to add a set of outgoing edges to the current
		 *	set of outgoing edges.
		 */
//		void add_set_of_outgoing_edges(const set<pair<unsigned long long,bool> > &set_outgoing_links);
		void add_set_of_outgoing_edges(const dg_edge_set &set_outgoing_links);
		/**
		 * Function to add an incoming edge to the current set of
		 *	incoming edges.
		 */
		void add_incoming_edge(const directed_graph_edge &incoming_link);
		/**
		 * Function to add an outgoing edge to the current set of
		 *	outgoing edges.
		 */
		void add_outgoing_edge(const directed_graph_edge &outgoing_link);
		/**
		 * Functions to remove an incoming edge to the current set of
		 *	incoming edges.
		 */
		void remove_incoming_edge(const unsigned long long int &node_ID_removal);
		void remove_incoming_edge(const directed_graph_edge &directed_graph_edge_rm);
		/**
		 * Functions to remove an outgoing edge to the current set of
		 *	outgoing edges.
		 */
		void remove_outgoing_edge(const unsigned long long int &node_ID_removal);
		void remove_outgoing_edge(const directed_graph_edge &directed_graph_edge_rm);
		

	// =========================================================
	
	// Privately accessible data members and functions.
	
	private:
		// Declare (and initialize) constants.
		
		// Types of file formats.
/*
		static const string VERILOG;
		static const string SPEF_IP;
		static const string SDC_IP;
		static const string IP_CELL_LIB;
		static const string TIMING;
		static const string SIZES;
		static const string INT_SIZES;
		static const string INTGR;
		static const string PERIOD;
		static const string SLASH;
		static const string TEXT;
*/
		// -----------------------------------------------------
	
		// Declaration of static variables...

		// Flag to indicate that the software is in logging mode
//		static bool is_logging;
		
		// -----------------------------------------------------
	
		// Declaration of instance variables...
		
		// Boolean function of the node
//		bool logic_function;
		// Index (as an integer) of the node.
		unsigned long long int node_ID;
		// Set of outgoing edges: pair(destination node, inverter flag).
//		set<pair<unsigned long long,bool> > outgoing_edges;
		dg_edge_set outgoing_edges;
		// Set of incoming edges: pair(source node, inverter flag).
//		set<pair<unsigned long long,bool> > incoming_edges;
		dg_edge_set incoming_edges;
		
		
		// -------------------------------------------------------
		
		// Define headers for private functions...
		
};
#endif
