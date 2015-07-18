
// Divya Bathey
// CSCI 303 Project 03
// April 12, 2015

# include "edge.hpp"

// -----------------------------------------------------------------------------------------------

// returns the endpoint other than the given vertex
Vertex Edge::other(const Vertex vertex) const {
	
	// assumes no errors are possible (?)
	if (vertex == v) 
		return w;
	else
		return v;	
}
