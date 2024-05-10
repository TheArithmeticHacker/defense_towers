#include "graph.h"

Graph::Graph() {}

void Graph::addCell(Cell *cell)
{
    adjList[cell] = vector<pair<Cell *, int>>();
}

void Graph::connectCells(Cell *source, Cell *destination)
{
    // Connect two cells with an edge
    // Assuming the cost between two connected cells is the Euclidean distance
    int distance = euclideanDistance(source, destination);
    adjList[source].push_back(make_pair(destination, distance));
    adjList[destination].push_back(make_pair(source, distance)); // Assuming undirected graph
}

void Graph::removeCell(Cell *cell)
{
    // Remove a cell and its connections from the graph
    adjList.erase(cell);
    // Remove connections to the removed cell
    for (auto &pair : adjList) {
        auto &edges = pair.second;
        edges.erase(remove_if(edges.begin(),
                              edges.end(),
                              [cell](const pair<Cell *, int> &edge) { return edge.first == cell; }),
                    edges.end());
    }
}

int Graph::euclideanDistance(Cell *source, Cell *destination)
{
    // Calculate the Euclidean distance between two cells
    int dx = source->getX() - destination->getX();
    int dy = source->getY() - destination->getY();
    return sqrt(dx * dx + dy * dy);
}

void Graph::editConnection(Cell *source, Cell *destination)
{
    // Edit the connection between two cells
    int distance = euclideanDistance(source, destination);
    for (auto &edge : adjList[source]) {
        if (edge.first == destination) {
            edge.second = distance;
            break;
        }
    }
}

Cell *Graph::findCell(int x, int y)
{
    for (auto &pair : adjList) {
        if (pair.first->getX() == x && pair.first->getY() == y) {
            return pair.first;
        }
    }
    return nullptr; // Cell not found
}

vector<Cell *> Graph::AStar(Cell *start, Cell *goal)
{
    // Implementing A* algorithm
}
