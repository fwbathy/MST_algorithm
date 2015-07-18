
// Divya Bathey
// CSCI 303 Project 03
// April 12, 2015

# include "union_find.hpp"

// -----------------------------------------------------------------------------------------------


// initialize a union-find object for N items
Union_Find::Union_Find (unsigned long int N) {

	// there are as many components as there are vertices
	num_components = N;

	// resize these arrays to be appropriate size for number of given components
	id.resize(N);
	sz.resize(N);

	// set everyone's id to be itself, as they start as separate components 
	for (unsigned long int i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
}


// determine component identifier for given site p
// Component is an unsigned long int
Component Union_Find::find (const Site p) {
	// from his powerpoint slide
	if (p == id[p])
		return p;				// stop at the root if we're already there
	else
		id[p] = find(id[p]);		// otherwise link visited nodes to the root
	return id[p];
} 


// adds a connection between the sites p and q
void Union_Find::onion (const Site p, const Site q) {

	// determine roots of both sites
	Component i = find(p);
	Component j = find(q);

	if (i == j) 
		return;		// already in the same group, do nothing

	num_components--;

	// make the smaller root point to the larger one
	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
	}
	else {
		id[j] = i;
		sz[i] += sz[j];
	}

	// weighted qu in the textbook
}  

