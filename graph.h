// ---------------------------------------------------------------------------
// Authors: Agampaul Singh & Sarah Grossheim
// Course-Section: CS-355-01
// Assignment: Final Project 
// Date due: 11/28/2023
// Description: Implement data structures and algorithms to demonstrate the
//				shortest path problem.
// ---------------------------------------------------------------------------

// Back End Code by Paul
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int INF = 100000;

// Class representing a node in the graph
// Author: Paul
class Node {
	public:
		int index;               // Index of the node in the graph
  		string name;             // Name of the node
  		vector<Node> adjacentNodes; // List of adjacent nodes
};

// Class representing a graph
// Author: Paul
class Graph {
	private:
  		vector<Node> Nodes;       // List of nodes in the graph

	public:
  		// Constructor to initialize the graph from input files
  		Graph(const string nameFile, const string matrixFile);

  		// Function to find the shortest path using Dijkstra's algorithm
  		int dijkstra(const string& startLocation, const string& endLocation);
};

// Implementation of the graph constructor
// Author: Paul
Graph::Graph(const string nameFile, const string matrixFile)
{
  	// Attempt to open the files
  	ifstream inName(nameFile);
  	ifstream inMatrix(matrixFile);

  	// Determine if the files can be successfully opened
  	if (inName.fail() || inMatrix.fail()){
    	cout << "Couldn't open one of the files. " << endl;
    	exit(1);
	}
	else{
    	// Variables
    	string inputName;
    	int count = 0;

    	// Inputting the building names from the input files 
    	while (getline(inName, inputName)) {
      		Node tempNode;
      		tempNode.name = inputName;
      		tempNode.index = count;
      		Nodes.push_back(tempNode);
      		count++;
    	}

    	int input;
    	for (int i = 0; i < Nodes.size(); i++) {
      		for (int j = 0; j < Nodes.size(); j++) {
        		inMatrix >> input;
        		if (input == 1) {
          			Nodes[i].adjacentNodes.push_back(Nodes[j]);
        		}
      		}
    	}
  	}
}

// Implementation of Dijkstra's algorithm to find the shortest path
// Returns the distance between start and end nodes
// Author: Paul
int Graph::dijkstra(const string& startLocation, const string& endLocation) {
  	int startIndex = -1;
 	int endIndex = -1;
 	 
  	// Find the indices of the start and end nodes
  	for (int i = 0; i < Nodes.size(); i++) {
    	if (Nodes[i].name == startLocation)
      		startIndex = i;
    	if (Nodes[i].name == endLocation)
      		endIndex = i;
  	}

  	// Check if the start or end node is not found
  	if (startIndex == -1 || endIndex == -1) {
    	cout << "Start or end node not found." << endl;
    	return -1; // Indicate failure
  	}

  	// Initialize distance, visited, and previous arrays
  	vector<int> distance(Nodes.size(), INF);
  	vector<bool> visited(Nodes.size(), false);
  	vector<int> previous(Nodes.size(), -1); // To store previous node in the path

  	distance[startIndex] = 0;

  	// Main loop of Dijkstra's algorithm
  	for (int i = 0; i < Nodes.size(); i++) {
    	int minDist = INF;
    	int minIndex = -1;

    	// Find the unvisited node with the smallest distance
    	for (int j = 0; j < Nodes.size(); j++) {
      		if (!visited[j] && distance[j] < minDist) {
        		minDist = distance[j];
        		minIndex = j;
      		}	
   		}

    	// Break if no more reachable nodes or destination reached
    	if (minIndex == -1 || minIndex == endIndex)
      		break;

    	visited[minIndex] = true;

    	// Update distances and previous nodes for adjacent nodes
    	for (const Node& neighborNode : Nodes[minIndex].adjacentNodes) {
      		int neighborIndex = neighborNode.index;
      		int newDist = distance[minIndex] + 1; // Assuming unweighted graph

      		if (newDist < distance[neighborIndex]) {
        		distance[neighborIndex] = newDist;
        		previous[neighborIndex] = minIndex; // Update previous node in the path
      		}
    	}
  	}

  	// Reconstruct the path
  	vector<string> path;
  	int current = endIndex;
  	while (current != -1) {
    	path.push_back(Nodes[current].name);
    	current = previous[current];
  	}

  	// Print the path
  	cout << endl << "Shortest path: ";
  	for (int i = path.size() - 1; i >= 0; i--) {
    	cout << path[i];
    	if (i > 0) 
			cout << " -> ";
  	}
  	cout << endl << endl;

  	// Return the distance between start and end nodes
  	return distance[endIndex];
}
