#include <bits/stdc++.h>
#include <boost/variant.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <cstring>

#define COMPILER_ID "ward-lang-compiler"
#define COMPILER_TITLE "WARD LANGUAGE COMPILER"
#define COMPILER_VERSION "BETA-0.1"
#define CODE_EXTENSION "WARD"
#define BASIC_LIBRARY ".DEF LIB _WARD"

class BasicCompiler {
  protected:
    std::string code_path_;
  public:
    void RunCode(){
      std::ifstream file(this->code_path_);
      std::string str, file_content;
      while (getline(file, str)){
	file_content = file_content + str;
	file_content.push_back('\n');
      }
      std::cout << "code is: " << std::endl << "---------" << std::endl;
      if (boost::algorithm::starts_with(file_content, BASIC_LIBRARY) == true){
	std::cout << file_content << std::endl;
      } else {
	std::cout << "did you define basic lib of ward?" << std::endl;
      }
    }
    int CheckPath(){
      if (boost::filesystem::exists(this->code_path_) == true){
	std::vector<std::string> split_code_path;
	boost::split(split_code_path, this->code_path_, [](char c){return c == '.';});
	std::cout << "0: " << split_code_path[0] << std::endl;
	std::cout << "1: " << split_code_path[1] << std::endl;
	if (split_code_path[1] == CODE_EXTENSION){ // extension of code = test.cai
	  return 0;
	} else {
	  std::cout << "unsupported extension!" << std::endl;
	  return 1;
	}
	return 0;
      } else { return 1; }
    }
    BasicCompiler(char *path){
      this->code_path_ = std::string(reinterpret_cast<char *>(path));
      if (this->CheckPath() == 0){
	this->RunCode();
      } else {
	std::cout << "error! couldn't find" << std::endl;
      }
    }
};

int main(int c, char *v[]){
  std::cout << COMPILER_TITLE << " " << COMPILER_VERSION << std::endl; 
  if (c > 1){
    std::unique_ptr<BasicCompiler> basic_compiler = std::make_unique<BasicCompiler>(v[1]);
  } else {
    std::cout << "no args!" << std::endl;
  }
  return 0;
}
