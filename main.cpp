// ---------------------------------------------------------------------------
// Authors: Sarah Grossheim & Agampaul Singh
// Course-Section: CS-355-01
// Assignment: Final Project 
// Date due: 11/28/2023
// Description: Implement data structures and algorithms to demonstrate the
//				shortest path problem.
// ---------------------------------------------------------------------------

// Front End Code by Sarah 
#include <iostream>
#include <cctype>
#include <string>
#include "graph.h"

using namespace std;

// Displays welcome message to user
// Author: Sarah
void welcomeMessage();

// Verifies if user is a UNA student
// Author: Sarah
void verifyUNAStudent();

// Displays a menu of categories & asks 
// user what location they want to go
// Returns an integer of their choice
// Author: Sarah
int displayMenu();

// Displays a menu of choices from the chosen category 
// Returns a string of the current node
// Author: Sarah
string chooseLocation(int userChoice, const Graph inputGraph, string currentNode);

int main() 
{
  	// Create variables
  	int choice;
  	string current = "Home (UNA)";
  
  	// Create the graph
  	Graph inGraph("Names.txt","adjacencyMatrix.txt");
  
  	// Display welcome message 
  	welcomeMessage();

  	// Verify if UNA student
  	verifyUNAStudent();

  	// Display a menu of categories and ask user where they would like to go
  	choice = displayMenu();

  	// Display different locations for selected category
  	current = chooseLocation(choice, inGraph, current);
  	
  	// Loop until user is ready to exit
  	while(current != "Done"){
  		
  		// Display a menu of categories and ask user where they would like to go
  		choice = displayMenu();

  		// Display different locations for selected category
  		current = chooseLocation(choice, inGraph, current);
	}
	  
	return 0;
}

void welcomeMessage(){
  	// Display welcome message
  	cout << "--------------------Welcome to Fluber!!!--------------------" << endl  << endl;
  	cout << "      We are the new Uber service in Florence, Alabama." << endl << endl;
  	cout << "  The purpose of this new service is to find the shortest" << endl;
  	cout << "     path that takes students where they need to go!" << endl << endl;
  	cout << "            However, there is one condition..." << endl;
  	cout << "      To use this program, you must be a UNA student." << endl;
  	cout << "------------------------------------------------------------" << endl;
}

void verifyUNAStudent(){
  	// Declare variable
  	char student;

  	cout << "Are you a UNA student? (y/n)" << endl << endl;
  	cout << "Please make your selection: ";
  	cin >> student;

  	// Verify if they are a UNA student 
  	switch(toupper(student)){
    	// If yes, keep going
    	case 'Y':
      		cout << endl << "Perfect! We are happy to assist you..." << endl;
      		cout << "------------------------------------------------------------" << endl;
      		break;
      		
    	// If no, then terminate program
    	case 'N':
      		cout << endl << "Sorry, we are unable to help you. Bye!" << endl;
      		cout << "------------------------------------------------------------" << endl;
      		exit(1);
      		break;
      		
    	// Verify choice if not Y or N
    	default:
      		cout << endl << "Invalid choice. Try again." << endl << endl;
      		verifyUNAStudent();
      		break;
    }
}

int displayMenu(){
  	// Choice variable
  	int userChoice;

  	// Menu
  	cout << "What category would you like to visit?" << endl;
  	cout << "1. Restaraunts" << endl;
  	cout << "2. Gyms" << endl;
  	cout << "3. Libraries" << endl;
  	cout << "4. Grocery Stores" << endl;
  	cout << "5. Entertainment Places" << endl;
  	cout << "6. Health Services" << endl;
  	cout << "7. Home" << endl;
  	cout << "8. Exit" << endl;
  	cout << "Please make your selection: ";
  	cin >> userChoice;

  	// Verify user's choice
  	while(userChoice > 8 || userChoice < 1 ){
    	cout << endl << "Invalid choice. Try again." << endl << endl;
    	cout << "Please make your selection: ";
    	cin >> userChoice;
  	}
  	cout << endl;
  
  	return userChoice;
}

string chooseLocation(int userChoice, Graph inGraph, string currentNode){
  	// Create variables
  	int choice;
  	int dist;
   
  	// Based on what category the user selected, show the different places
  	switch(userChoice){
    	// List restaurants if user chose 1
    	case 1:
      		// Ask user where they want to go
  	  		cout << "Where would you like to go? " << endl;
      		cout << "1. Mcdonald's" << endl;
      		cout << "2. Zaxby's" << endl;
      		cout << "3. Cookout" << endl;
      		cout << "4. Back to Category Menu" << endl;
      		cout << "Please make your selection: ";
      		cin >> choice;
      		cout << "------------------------------------------------------------" << endl;

      		// Validate answer
      		while(choice > 4 || choice < 1){
        		cout << endl << "Invalid choice." << endl << endl;
        		cout << "Please make your selection: ";
        		cin >> choice;
      		}
      
      		// Call shortest path algorithm based on selection 
	  		// and show the total distance between the nodes
	  		// Then set the current node equal to selection
      		switch(choice){
      			case 1:
      				cout << endl << "Traveling from " << currentNode << " to Mcdonald's" << endl;
      				dist = inGraph.dijkstra(currentNode, "Mcdonald's");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Mcdonald's";
  					break;
  				case 2: 
  					cout << endl << "Traveling from " << currentNode << " to Zaxby's" << endl;
  					dist = inGraph.dijkstra(currentNode, "Zaxby's");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Zaxby's";
  					break;
  				case 3:
  					cout << endl << "Traveling from " << currentNode << " to Cookout" << endl;
  					dist = inGraph.dijkstra(currentNode, "Cookout");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Cookout";
  					break;
  				case 4:
  					displayMenu();
  					break;
	  		}
      		break; // end of case 1
      	
    	// List gym if user chose 2
    	case 2:
      		// Ask user where they want to go
      		cout << "Where would you like to go? " << endl;
      		cout << "1. Planet Fitness" << endl;
      		cout << "2. Workout Anytime" << endl;
      		cout << "3. Crunch Fitness" << endl;
      		cout << "4. Back to Category Menu" << endl;
      		cout << "Please make your selection: "; 
      		cin >> choice;
      		cout << "------------------------------------------------------------" << endl;

      		// Validate answer
      		while(choice > 4 || choice < 1){
        		cout << endl << "Invalid choice." << endl << endl;
        		cout << "Please make your selection: ";
        		cin >> choice;
      		}
      	
       		// Call shortest path algorithm based on selection
	   		// and show the total distance between the nodes
	   		// Then set the current node equal to selection
      		switch(choice){
      			case 1:
      				cout << endl << "Traveling from " << currentNode << " to Planet Fitness" << endl;
      				dist = inGraph.dijkstra(currentNode, "Planet Fitness");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Planet Fitness";
  					break;
  				case 2: 
  					cout << endl << "Traveling from " << currentNode << " to Workout Anytime" << endl;
  					dist = inGraph.dijkstra(currentNode, "Workout Anytime");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Workout Anytime";
  					break;
  				case 3:
  					cout << endl << "Traveling from " << currentNode << " to Crunch Fitness" << endl;
  					dist = inGraph.dijkstra(currentNode, "Crunch Fitness");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Crunch Fitness";
  					break;
  				case 4:
  					displayMenu();
  					break;
	  		}
      		break; // end of case 2
      	
    	// List libraries if user chose 3
    	case 3:
	  		// Ask user where they want to go
  	  		cout << "Where would you like to go? " << endl;
      		cout << "1. Collier Library" << endl;
      		cout << "2. Florence Public Library" << endl;
      		cout << "3. Back to Category Menu" << endl;
      		cout << "Please make your selection: ";
      		cin >> choice;
	  		cout << "------------------------------------------------------------" << endl;

      		// Validate answer
      		while(choice > 3 || choice < 1){
        		cout << endl << "Invalid choice." << endl << endl;
       		 	cout << "Please make your selection: ";
       		 	cin >> choice;
      		}
      
      		// Call shortest path algorithm based on selection
	   		// and show the total distance between the nodes
	   		// Then set the current node equal to selection
      		switch(choice){
      			case 1:
      				cout << endl << "Traveling from " << currentNode << " to Collier Library" << endl;
      				dist = inGraph.dijkstra(currentNode, "Collier Library");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Collier Library";
  					break;
  				case 2: 
  					cout << endl << "Traveling from " << currentNode << " to Florence Public Library" << endl;
  					dist = inGraph.dijkstra(currentNode, "Florence Public Library");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Florence Public Library";
  					break;
  				case 3:
  					displayMenu();
  					break;
	  		}
      		break; // end of case 3
      	
    	// List grocery stores if user chose 4
    	case 4:
      		// Ask user where they want to go
  	  		cout << "Where would you like to go? " << endl;
      		cout << "1. Walmart" << endl;
      		cout << "2. Target" << endl;
      		cout << "3. Aldi's" << endl;
      		cout << "4. Back to Category Menu" << endl;
      		cout << "Please make your selection: ";
      		cin >> choice;
      		cout << "------------------------------------------------------------" << endl;

      		// Validate answer
      		while(choice > 4 || choice < 1){
        		cout << endl << "Invalid choice." << endl << endl;
        		cout << "Please make your selection: ";
       		 	cin >> choice;
      		}
      	
      		// Call shortest path algorithm based on selection
	  		// and show the total distance between the nodes
	  		// Then set the current node equal to selection
      		switch(choice){
      			case 1:
      				cout << endl << "Traveling from " << currentNode << " to Walmart" << endl;
      				dist = inGraph.dijkstra(currentNode, "Walmart");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Walmart";
  					break;
  				case 2: 
  					cout << endl << "Traveling from " << currentNode << " to Target" << endl;
  					dist = inGraph.dijkstra(currentNode, "Target");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Target";
  					break;
  				case 3:
  					cout << endl << "Traveling from " << currentNode << " to Aldi's" << endl;
  					dist = inGraph.dijkstra(currentNode, "Aldi's");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Aldi's";
  					break;
  				case 4:
  					displayMenu();
  					break;
	  		}
      		break; // end of case 4

    	// List entertainment if user chose 5
   		case 5:
      		// Ask user where they want to go
      		cout << "Where would you like to go? " << endl;
      		cout << "1. Lauderdale Lanes" << endl;
      		cout << "2. AMC Theaters" << endl;
      		cout << "3. Skate Center" << endl;
      		cout << "4. Back to Category Menu" << endl;
      		cout << "Please make your selection: ";
      		cin >> choice;
      		cout << "------------------------------------------------------------" << endl;

      		// Validate answer
      		while(choice > 4 || choice < 1){
        		cout << endl << "Invalid choice." << endl << endl;
        		cout << "Please make your selection: ";
        		cin >> choice;
      		}
      	
      		// Call shortest path algorithm based on selection
	  		// and show the total distance between the nodes
	  		// Then set the current node equal to selection
      		switch(choice){
      			case 1:
      				cout << endl << "Traveling from " << currentNode << " to Lauderdale Lanes" << endl;
      				dist = inGraph.dijkstra(currentNode, "Lauderdale Lanes");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Lauderdale Lanes";
  					break;
  				case 2: 
  					cout << endl << "Traveling from " << currentNode << " to AMC Theaters" << endl;
  					dist = inGraph.dijkstra(currentNode, "AMC Theaters");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "AMC Theaters";
  					break;
  				case 3:
  					cout << endl << "Traveling from " << currentNode << " to Skate Center" << endl;
  					dist = inGraph.dijkstra(currentNode, "Skate Center");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "Skate Center";
  					break;
  				case 4:
  					displayMenu();
  					break;
	  		}
      		break; // end of case 5

    	// List health services if user chose 6
    	case 6:
      		// Ask user where they want to go
  	  		cout << "Where would you like to go? " << endl;
      		cout << "1. North Alabama Medical Center" << endl;
      		cout << "2. UNA Health Services" << endl;
      		cout << "3. Back to Category Menu" << endl;
      		cout << "Please make your selection: ";
      		cin >> choice;
      		cout << "------------------------------------------------------------" << endl;

      		// Validate answer
      		while(choice > 3 || choice < 1){
        		cout << endl << "Invalid choice." << endl << endl;
        		cout << "Please make your selection: ";
        		cin >> choice;
      		}
      	
      		// Call shortest path algorithm based on selection
	  		// and show the total distance between the nodes
	  		// Then set the current node equal to selection
      		switch(choice){
      			case 1:
      				cout << endl << "Traveling from " << currentNode << " to North Alabama Medical Center" << endl;
      				dist = inGraph.dijkstra(currentNode, "North Alabama Medical Center");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "North Alabama Medical Center";
  					break;
  				case 2: 
  					cout << endl << "Traveling from " << currentNode <<  " to UNA Health Services" << endl;
  					dist = inGraph.dijkstra(currentNode, "UNA Health Services");
  					cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  					cout << "------------------------------------------------------------" << endl;
  					currentNode = "UNA Health Services";
  					break;
  				case 3:
  					displayMenu();
  					break;
	  		}
      		break; // end of case 6
      		
    	// Take user home if user chose 7
    	case 7:
    		cout << "------------------------------------------------------------" << endl;
    		cout << endl << "Traveling from " << currentNode << " to Home (UNA)" << endl;
      		dist = inGraph.dijkstra(currentNode, "Home (UNA)");
  			cout << "Distance Traveled: " << dist << " nodes" << endl << endl;
  			cout << "------------------------------------------------------------" << endl;
  			currentNode = "Home (UNA)";
  			break; // end of case 7
      
  		// User wants to exit the program
  		case 8:
  			cout << "------------------------------------------------------------" << endl;
  			cout << "Thank you for using Fluber. Goodbye!" << endl;
  			cout << "------------------------------------------------------------" << endl;
  			currentNode = "Done";
  			break; // end of case 8
  	}
  	return currentNode;
}



