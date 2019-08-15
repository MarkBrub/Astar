#include <vector>
#include "node.hpp"
#include "graph.hpp"

Graph::Graph() {}

Graph::Graph(std::vector<std::vector<Node>> m_graph) {
	graph = m_graph;
}

std::vector<Node>& Graph::operator [] (int x) {
	return graph[x];
}

int Graph::size() {
	return graph.size();
}

Node* Graph::getNode(Position position) {
	for (int x = 0; x < graph.size(); x++)
	{
		for (int y = 0; y < graph[0].size(); y++)
		{
			if (graph[x][y].position == position) return &graph[x][y];
		}
	}
	//returns when the position is not found
	//could mean that the position was of a neighbor off the edge of the graph
	return &graph[0][0];
}