#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>

class Graph{
  public:
    void createAdjList(int roc);
    
    void addEdge(int source, int target);

    int minNumVill();

    std::vector<int> vertexApprox();

  private:
    std::vector<std::vector<int>> adj_list;

    void dfsUtil(std::vector<std::vector<int>> &aux_list, int num1, int num2);
};

#endif