#include "commands.h"""

#include <string>
#include <iostream>



namespace seashell {

void help(const std::string &)
{
	std::cout<<"Yeehaw here is a list of commands: \n";
	std::cout<<"ls - displays files in directory\n";
	std::cout<<"cd <directory> - changes current directory to <directory>\n";
	std::cout<<"mkdir/rmdir <directory> - creates or deletes <directory>\n";
	std::cout<<"Telari - :)\n";

}
}


