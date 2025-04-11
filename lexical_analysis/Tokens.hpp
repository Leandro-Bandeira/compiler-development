#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <variant>

enum class Type{
  INT,
  FLOAT,
  UNKNOWN
};

class Tokens{
  public:
    Tokens() = default;
    std::string type;
    std::string name;
    std::string operation;

    std::variant<int, float, double> value;

    void printValue(){
      std::visit([](auto&& val) {
          std::cout << "Value: " << val << "\n";
      }, value);
    }
};















#endif
