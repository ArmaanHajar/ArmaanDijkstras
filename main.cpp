/*
 * Author: Armaan Hajar
 * Program: A graph creator program that uses Dijkstra's algorithm to find the shortest path between nodes.
 * Date: 
 */

#include <iostream>

//node struct
struct Node{
    char* name;
    Node(char* newName) {
        name = newName;
    }
};

void addNode(Node** nodeList, int adjMatrix[21][21]);
void remNode(Node** nodeList, int adjMatrix[21][21]);
void addEdge(Node** nodeList, int adjMatrix[21][21]);
void remEdge(Node** nodeList, int adjMatrix[21][21]);
void printAdjMatrix(int adjMatrix[21][21]);
void findShortestPath(Node** nodeList, int adjMatrix[21][21]);

using namespace std;

int main() {
    int input;
    bool running = true;

    Node** nodeList = new Node*[21];
    int adjMatrix[21][21];
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            adjMatrix[i][j] = 0;
        }
    }


    while (running == true) { // loops until user quits the program
        cout << "-------------------------------------------------------" << endl;
        cout << "What Would You Like To Do? (Type a Number):" << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Remove Node" << endl;
        cout << "4. Remove Edge" << endl;
        cout << "5. Find Shortest Path" << endl;

        cin >> input;

        if (input == 1) { // add node
            addNode(nodeList, adjMatrix);
        }
        else if (input == 2) { // add edge
            addEdge(nodeList, adjMatrix);
        }
        else if (input == 3) { // remove node
            remNode(nodeList, adjMatrix);
        }
        else if (input == 4) { // remove edge
            remEdge(nodeList, adjMatrix);
        }
        else if (input == 5) { // find shortest path
            findShortestPath(nodeList, adjMatrix);
        }
        else {
            cout << "Sorry, Please Try Again" << endl;

        }
    }
}

void addNode(Node** nodeList, int adjMatrix[21][21]) {
    char* name = new char[4];
    cout << "What Is The Name of the Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name, 4);
    cin.ignore(1, '\n');

    for (int i = 0; i < 21; i++) {
        if (nodeList[i] == NULL) {
            nodeList[i] = new Node(name);
            break;
        }
    }
}

void remNode(Node** nodeList, int adjMatrix[21][21]) {
    char* name = new char[4];
    cout << "What Is The Name of the Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name, 4);
    cin.ignore(1, '\n');

    for (int i = 0; i < 21; i++) {
        if (nodeList[i] != NULL) {
            if (nodeList[i]->name == name) {
                nodeList[i] = NULL;
                break;
            }
        }
    }
}

void addEdge(Node** nodeList, int adjMatrix[21][21]) {
    char* name1 = new char[4];
    char* name2 = new char[4];
    int edgeWeight;
    cout << "What Is The Name of the First Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name1, 4);
    cin.ignore(1, '\n');
    cout << "What Is The Name of the Second Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name2, 4);
    cin.ignore(1, '\n');
    cout << "What Is The Weight of the Edge?" << endl;
    cin >> edgeWeight;

    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < 21; i++) {
        if (nodeList[i] != NULL) {
            if (nodeList[i]->name == name1) {
                index1 = i;
            }
            else if (nodeList[i]->name == name2) {
                index2 = i;
            }
        }
    }

    if (index1 != -1 && index2 != -1) {
        adjMatrix[index1][index2] = 1;
        adjMatrix[index2][index1] = 1;
    }
    else {
        cout << "Sorry, Please Try Again" << endl;
    }
}

void remEdge(Node** nodeList, int adjMatrix[21][21]) {
    char* name1 = new char[4];
    char* name2 = new char[4];
    cout << "What Is The Name of the First Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name1, 4);
    cin.ignore(1, '\n');
    cout << "What Is The Name of the Second Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name2, 4);
    cin.ignore(1, '\n');

    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < 21; i++) {
        if (nodeList[i] != NULL) {
            if (nodeList[i]->name == name1) {
                index1 = i;
            }
            else if (nodeList[i]->name == name2) {
                index2 = i;
            }
        }
    }

    if (index1 != -1 && index2 != -1) {
        adjMatrix[index1][index2] = 0;
        adjMatrix[index2][index1] = 0;
    }
    else {
        cout << "Sorry, Please Try Again" << endl;
    }
}