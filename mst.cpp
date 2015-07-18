
// Divya Bathey
// CSCI 303 Project 03
// April 12, 2015

# include "mst.hpp"

// -----------------------------------------------------------------------------------------------

// adds an edge to the class member vector<Edge> edges and updates total wt
void MST::add_edge(const Edge &e) {
	push_back(e);
	wt += e.weight();
}

