#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "functions.hpp"
#include "graph.hpp"


int main(int argc, char* argv[]){
  
  std::fstream file; file.open(argv[2]);
  
  if(file.is_open() == false){
    std::cout << "O programa não conseguiu ler o arquivo de entrada" << std::endl;
    return 0;
  }
  else if(argc != 3){
    std::cout << "Número de argumentos inválidos" << std::endl;
    return 0;
  }

  std::string task(argv[1]);

  Functions o1; Graph map;
  int answer = 0;
  if(task.compare("tarefa1") == 0){
    o1.readInput(map, file, true);
    answer = map.minNumVill();
    std::cout << answer << std::endl;
  }
  else if(task.compare("tarefa2") == 0){
    o1.readInput(map, file, false);
    std::vector<int> copy = map.vertexApprox();
    for (auto item: copy)
    {
      std::cout << item << std::endl; 
    }
    
  }else{
    std::cout << "Número da tarefa passado é inválido. Favor conferir." << std::endl;
  }
  return 0;
}