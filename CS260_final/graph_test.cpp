#include <iostream>
#include "graph.h"

void testAddVertex() {
    std::cout << "Testing adding vertices to the graph:" << std::endl;
    Graph graph;

    // Add vertices
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');

    // Display the structure of the graph
    graph.displayStructure();
}

void testAddEdge() {
    std::cout << "\nTesting adding edges to the graph:" << std::endl;
    Graph graph;

    // Add vertices
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');

    // Add edges
    graph.addEdgeBetweenVertices('A', 'B', 7);
    graph.addEdgeBetweenVertices('A', 'C', 9);
    graph.addEdgeBetweenVertices('B', 'C', 10);

    // Display the structure of the graph
    graph.displayStructure();
}

void testShortestPath() {
    std::cout << "\nTesting finding the shortest path:" << std::endl;
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

    // Find and display the shortest path between two vertices
    std::cout << "Shortest path from A to E:" << std::endl;
    std::vector<GraphNode*> shortestPathAE = graph.shortestPath('A', 'E');
    for (auto node : shortestPathAE) {
        std::cout << node->name << " ";
    }
    std::cout << std::endl;
}

void testMinimumSpanningTree() {
    std::cout << "\nTesting finding the minimum spanning tree:" << std::endl;
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

    // Find and display the minimum spanning tree
    std::cout << "Minimum spanning tree:" << std::endl;
    std::vector<Edge> minSpanningTree = graph.minSpanningTree();
    for (auto edge : minSpanningTree) {
        std::cout << edge.source->name << " - " << edge.destination->name << " (Weight: " << edge.weight << ")" << std::endl;
    }
}

int main() {
    testAddVertex();
    testAddEdge();
    testShortestPath();
    testMinimumSpanningTree();

    return 0;
}
