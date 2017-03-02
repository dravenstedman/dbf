// DBF
// C++ implementation of DBF
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
int main(int argc, char * argv[]){
  int memory[65535];
  int datapointer = 0;
  std::vector<std::string> commands;
  int current_command = 0;
  std::string infile;
  if(argc > 1){
    std::string filename (argv[1]);
    std::ifstream filestream (filename);
    if(filestream.is_open()){
      std::stringstream buffer;
      buffer << filestream.rdbuf();
      infile = buffer.str();
    }
  }else{
    std::cout << "Usage: dbf [file]\n";
    return 1;
  }
  for(int i; i<=infile.length(); ++i){
    if(i%2==1){
      std::string x(infile,i-1,2);
      commands.push_back(x);
    }
  }
  std::cout << "\n";
  while(1){
    if(commands[current_command] == "FF"){
      datapointer += 1;
    }else if(commands[current_command] == "BB"){
      datapointer -= 1;
    }else if(commands[current_command] == "II"){
      memory[datapointer] += 1;
    }else if(commands[current_command] == "DD"){
      memory[datapointer] -= 1;
    }else if(commands[current_command] == "OO"){
      std::cout << char(memory[datapointer]);
    }else if(commands[current_command][0] == 'J'){
      // convert the second character of q to an int, then add that to current_command
      std::string q (commands[current_command], 1);
      int foo = std::stoi(q);
      current_command += foo;
    }else{}
    current_command += 1;
    if(current_command >= commands.size()){
      break;
    }
  }
  return 0;
}
