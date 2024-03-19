#include <iostream>
#include "graph_node.h"
#include "edge.h"
#include "graph.h"

int main() {
    // Create a graph object
    Graph graph;

    // Add vertices
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');
    graph.addVertex('F');

    // Add edges
    graph.addEdgeBetweenVertices('A', 'B', 7);
    graph.addEdgeBetweenVertices('A', 'C', 9);
    graph.addEdgeBetweenVertices('A', 'F', 14);
    graph.addEdgeBetweenVertices('B', 'C', 10);
    graph.addEdgeBetweenVertices('B', 'D', 15);
    graph.addEdgeBetweenVertices('C', 'D', 11);
    graph.addEdgeBetweenVertices('C', 'E', 2);
    graph.addEdgeBetweenVertices('D', 'E', 6);
    graph.addEdgeBetweenVertices('E', 'F', 9);

    // Display the structure of the graph
    graph.displayStructure();

    // Find and display the shortest path between two vertices
    std::cout << "Shortest path from A to E:" << std::endl;
    std::vector<GraphNode*> shortestPathAE = graph.shortestPath('A', 'E');
    if (shortestPathAE.empty()) {
        std::cout << "No path found." << std::endl;
    } else {
        for (auto node : shortestPathAE) {
            std::cout << node->name << " ";
        }
        std::cout << std::endl;
    }

    // Find and display the minimum spanning tree
    std::cout << "Minimum spanning tree:" << std::endl;
    std::vector<Edge> minSpanningTree = graph.minSpanningTree();
    if (minSpanningTree.empty()) {
        std::cout << "No spanning tree found." << std::endl;
    } else {
        for (auto edge : minSpanningTree) {
            std::cout << edge.source->name << " - " << edge.destination->name << " (Weight: " << edge.weight << ")" << std::endl;
        }
    }

    return 0;
}

