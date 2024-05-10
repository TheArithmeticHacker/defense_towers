#ifndef GRAPH_H
#define GRAPH_H
#include <cell.h>
#include <map>
#include <vector>
using namespace std;
class Graph
{
private:
    map<Cell *, vector<pair<Cell *, int>>> adjList;

public:
    Graph();
    void addCell(Cell *);
    void connectCells(Cell *, Cell *);
    void removeCell(Cell *);
    void euclideanDistance(Cell *, Cell *);
    void editConnection(Cell *, Cell *);
    Cell *findCell(int, int);
    vector<Cell *> AStar(Cell *, Cell *);
};

#endif // GRAPH_H
