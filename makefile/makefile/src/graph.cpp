#include "graph.hpp"

void Graph::createAdjList(int roc){
  adj_list.resize(roc);
}

void Graph::addEdge(int source, int target){
  this->adj_list[source].push_back(target);
}

void Graph::dfsUtil(std::vector<std::vector<int>> &aux_list, int num1, int num2){

  for(auto child_node: this->adj_list[num1]){
    if(child_node != num2 ){
      //Caminha na árvore. Entra na recursão na aresta caso não seja correspondente ao número do nó pai(num2).
      dfsUtil(aux_list, child_node, num1);
       //Calcula ambas as possibilidades (de inclusão e exclusão) pra cada nó.
      aux_list[num1][0] += aux_list[child_node][1];
      aux_list[num1][1] += std::min(aux_list[child_node][1], aux_list[child_node][0]);
    }
  }
}



int Graph::minNumVill(){
  int answer = 0, size = adj_list.size();
  std::vector<std::vector<int>> aux_list(size);
  for(int i = 0; i < size; i++){
    //Vetor auxiliar que guarda a solução para cada vértice e os subproblemas.
    //A posição [0] guarda caso um nó seja excluído da solução, e o 1 caso seja incluído.
    aux_list[i].push_back(0); aux_list[i].push_back(1);
  }
  //Inicia a recursão. Nota, não faz diferença qual nó começa.
  this->dfsUtil(aux_list, 0, -1);
  answer = std::min(aux_list[0][0], aux_list[0][1]);


  return answer;
}

std::vector<int> Graph::vertexApprox(){

  std::vector<bool> checked(this->adj_list.size(), 0);
  std::vector<int> vertices_and_size;
  int answer = 0; vertices_and_size.push_back(answer);
  
  for(long unsigned int i = 0; i < this->adj_list.size(); i++){ 
    if (checked[i]==false){
      
      for(auto item:adj_list[i]){
        //Só considera uma aresta caso ambos os vértices não estejam visitados. (Pois se algum tiver sido)
        //visitado, a aresta já teria sido excluída.      
        if(checked[item] == false){
          checked[i] = true;
          checked[item] = true;
          break;
        }        
      }
    }
  }
  //Passa as respostas para o vetor que será retornado.
  for(long unsigned int i = 0; i < checked.size(); i++){
    if(checked[i] == true){
      vertices_and_size.push_back(i);
      answer++;
    }
  }
  vertices_and_size[0] = answer;
  return vertices_and_size;
}
