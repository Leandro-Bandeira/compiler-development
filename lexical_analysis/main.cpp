#include <iostream>
#include <sstream>
#include <string>

#include "Tokens.hpp"

Type getType(std::string& token){
  if(token == "int") return Type::INT;
  if(token == "float") return Type::FLOAT;
  return Type::UNKNOWN;
  
}
Tokens* analyseCode(std::string& code){
  Tokens *tokens = new Tokens();
  std::istringstream codeStream(code);
  std::string world;
  
  
  int i = 0;
  Type type;
  
  while(codeStream >> world){
    switch(i){
      case 0:
        tokens->type = world;
        type = getType(world);
        break;
      case 1:
        tokens->name = world;
        break;
      case 2:
        tokens->operation = world;
        break;
      case 3:
        
        if (type == Type::INT) tokens->value = std::atoi(world.c_str());
        else if(type == Type::FLOAT) tokens->value  = std::stof(world);
        break;
    }
    i++;    
  }

  return tokens;
}











int main(){

  
  std::string code = "int a = 0";

  Tokens* tokens = analyseCode(code);
  std::cout << "Type: " << tokens->type << "\n";
  std::cout << "Name: " << tokens->name << "\n";
  tokens->printValue();
  
  return 0;
}
