#pragma once

#include <vector>
#include <unordered_map>
#include <queue>
#include <climits> // for INT_MAX
#include <iostream>
#include <utility> // for std::pair
#include <unordered_set> // for std::unordered_set
#include <limits> // for std::numeric_limits
#include "graph_node.h"
#include "edge.h"

class Graph {
private:
    std::vector<GraphNode> nodes;
    std::vector<Edge> edges;

public:
    void addNode(GraphNode node) {
        nodes.push_back(node);
    }

    void addEdge(Edge edge) {
        edges.push_back(edge);

        // Update neighbors of source and destination nodes
        nodes[edge.source->name - 'A'].neighbors.push_back(edges.size() - 1);
        nodes[edge.destination->name - 'A'].neighbors.push_back(edges.size() - 1);
    }

    // Function to add a new vertex to the graph
    void addVertex(char vertexName) {
        GraphNode newNode{vertexName};
        addNode(newNode);
    }

    // Function to add a new edge between two vertices of the graph
    void addEdgeBetweenVertices(char sourceName, char destinationName, int weight) {
        GraphNode* sourceNode = nullptr;
        GraphNode* destinationNode = nullptr;

        // Find source and destination nodes
        for (auto& node : nodes) {
            if (node.name == sourceName)
                sourceNode = &node;
            else if (node.name == destinationName)
                destinationNode = &node;
        }

        if (sourceNode && destinationNode) {
            Edge newEdge{weight, sourceNode, destinationNode};
            addEdge(newEdge);
        } else {
            std::cerr << "Error: Source or destination node not found." << std::endl;
        }
    }

    //Function to find the shortest path
    std::vector<GraphNode*> shortestPath(char sourceName, char destinationName) {
        std::unordered_map<char, int> distance;
        std::unordered_map<char, char> previous;
        std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<std::pair<int, char>>> pq;

        // Initialize distances
        for (auto& node : nodes) {
            distance[node.name] = (node.name == sourceName) ? 0 : INT_MAX;
        }

        pq.push({0, sourceName});

        while (!pq.empty()) {
            char currentName = pq.top().second;
            pq.pop();

            if (currentName == destinationName) {
                break; // Reached the destination, exit loop
            }

            for (size_t neighborIndex : nodes[currentName - 'A'].neighbors) {
                const Edge& edge = edges[neighborIndex];
                char neighborName = (edge.source->name == currentName) ? edge.destination->name : edge.source->name;
                int totalDistance = distance[currentName] + edge.weight;
                if (totalDistance < distance[neighborName]) {
                    distance[neighborName] = totalDistance;
                    previous[neighborName] = currentName;
                    pq.push({totalDistance, neighborName});
                }
            }
        }

        // Reconstruct path
        std::vector<GraphNode*> path;
        char currentName = destinationName;
        while (currentName != sourceName) {
            path.push_back(&nodes[currentName - 'A']);
            currentName = previous[currentName];
        }
        path.push_back(&nodes[sourceName - 'A']); // Add source node
        std::reverse(path.begin(), path.end());

        return path;
    }




    // Function for a minimum spanning tree algorithm (Prim's algorithm)
    std::vector<Edge> minSpanningTree() {
        std::vector<Edge> mst;
        std::unordered_set<char> visitedNodes; // Track visited nodes by their names
        std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<std::pair<int, char>>> pq;

        // Start from the first node
        visitedNodes.insert(nodes[0].name); // Assume nodes are added in the order of their names
        for (size_t neighborIndex : nodes[0].neighbors) {
            pq.push({edges[neighborIndex].weight, edges[neighborIndex].destination->name});
        }

        while (!pq.empty()) {
            char nodeName = pq.top().second;
            pq.pop();

            if (visitedNodes.find(nodeName) != visitedNodes.end()) {
                continue; // Skip if the node is already visited
            }

            visitedNodes.insert(nodeName);

            // Find the edge corresponding to the current node
            const Edge* edge = nullptr;
            for (const auto& e : edges) {
                if (e.source->name == nodeName || e.destination->name == nodeName) {
                    edge = &e;
                    break;
                }
            }

            if (edge) {
                mst.push_back(*edge); // Add edge to the spanning tree

                // Add edges incident to the current node to the priority queue
                for (size_t neighborIndex : nodes[nodeName - 'A'].neighbors) {
                    const Edge& neighborEdge = edges[neighborIndex];
                    char neighborName = (neighborEdge.source->name == nodeName) ? neighborEdge.destination->name : neighborEdge.source->name;
                    pq.push({neighborEdge.weight, neighborName});
                }
            }
        }

        return mst;
    }

    //Display Graph
    void displayStructure() {
        std::cout << "Graph Structure:" << std::endl;
        for (const auto& node : nodes) {
            std::cout << "Node " << node.name << " neighbors: ";
            if (node.neighbors.empty()) {
                std::cout << "No neighbors";
            } else {
                for (const auto& edgeIndex : node.neighbors) {
                    const Edge& edge = edges[edgeIndex];
                    std::cout << "(" << edge.source->name << " - " << edge.destination->name << " Weight: " << edge.weight << ") ";
                }
            }
            std::cout << std::endl;
        }
    }



};