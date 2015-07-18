
// Divya Bathey
// CSCI 303 Project 03
// April 12, 2015

# include "graph.hpp"
# include "union_find.hpp"

# include <queue>			// for the STL priority queue (PQ)
using namespace std;

// -----------------------------------------------------------------------------------------------


// struct called by STL PQ: creates a PQ that runs max to min, such that
// popping off yields the smallest element from the end of the queue
struct Comparison {
	bool operator () (const Edge& e1, const Edge& e2) const {
		if (e1.weight() > e2.weight())
			return true;
		else
			return false;
	}
};


// initialize a new Weighted_Graph object
Weighted_Graph::Weighted_Graph(string name) {
	
	// has no edges and vertices to begin with
	E = 0;
	V = 0;

	// arbitrary size of adj, use push_back later on
	adj.resize(8);

}



// add an edge by adding it to edges and updating adj[], resizing either as necessary
void Weighted_Graph::add_edge(const Edge &e) {

	Vertex v = e.either();
	Vertex w = e.other(v);

	// add the new edge to edges and update E
	edges.push_back(e);
	E++;

	// resize the adjacency vector's lists as necessary
	// push_back only extends the lists within the vector, NOT the vector
	if(v > V-1 or w > V-1) {
		if ((v > w) && (adj.size()/2 < v)) {
			adj.resize(v + adj.size());
		}
		if ((w > v) && (adj.size()/2 < w)) {
			adj.resize(w + adj.size());
		}
	}

	// if new vertex is being considered
	if (adj[v].empty())
		V++;
	if (adj[w].empty())
		V++;

	// add to list regardless
	adj[v].push_back(w);
	adj[w].push_back(v);
}


// implementation of kruskal's algorithm, uses a PQ to maintain order 
MST Weighted_Graph::kruskal(string name) const {

	MST T;	// to be returned

	// priority queue uses the struct Comparison for its operator
	std::priority_queue<Edge, vector<Edge>, Comparison> myQueue;

	for (unsigned long int temp = 0; temp < edges.size(); temp++) {
		myQueue.push(edges[temp]);
	}

	// for(auto e:edges) {myQueue.push(e);}

	// V = N arg
	Union_Find UF = Union_Find(V);

	while (!myQueue.empty() && T.size() < V-1) {
		Edge e = myQueue.top();
		myQueue.pop();
		Vertex v = e.either();
		Vertex w = e.other(v);
		// if connected already, ignore 
		if (UF.connected(v,w)) 
			continue;
		UF.onion(v,w);
		// else union, and add edge
		T.add_edge(e);
	}

	return T;

}

