#include "commands.h"""

#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;


namespace seashell {

void ls(const std::string &)
{
	std::string path = fs::current_path();
    
	for (auto& entry : fs::directory_iterator(path))
    
	std::cout << entry.path() << std::endl;
	
}
}


