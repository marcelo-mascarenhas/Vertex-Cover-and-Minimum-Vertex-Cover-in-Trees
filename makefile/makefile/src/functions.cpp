#include "functions.hpp"



void Functions::readInput(Graph &grafo, std::fstream &file, bool tarefa){
  
  std::string aux_string; int airport_num, route_num, nd1, nd2;
  std::getline(file, aux_string);

  std::stringstream flow(aux_string);

  flow >> airport_num >> route_num;
  
  grafo.createAdjList(airport_num);
  

  for(int i = 0; i < route_num; i++){
    std::getline(file, aux_string);
    
    std::stringstream flow2(aux_string);

    flow2 >> nd1 >> nd2;
    //Cria arestas em duas direções, tendo em vista que o grafo é não-direcionado.
    grafo.addEdge(nd1, nd2); grafo.addEdge(nd2, nd1);

  }

}
