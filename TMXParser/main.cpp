#include "Map.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

const char* file_path = "..//Files//test2.tmx";

std::string getString(const std::string& line)
{
	std::string temp = line.substr(line.find("\""), line.length());
	return temp.substr(1, (line.find("\"") - 1) );
}

int getInt(const std::string& line)
{
	std::string temp = line.substr(line.find("\""), line.length());
	temp = temp.substr(1, (line.find("\"") - 1) );
	return (int)atof(temp.c_str());
}

void read1()
{
	std::ifstream reader(file_path, std::ios_base::in);
	std::string word;
	std::string line;
	unsigned int mapWidth;
	unsigned int mapHeight;
	unsigned int tileWidth;
	unsigned int tileHeight;
	unsigned int imageWidth;
	unsigned int imageHeight;
	std::string tileSetName;
	std::string imageName;

	if ( !reader.is_open() )
	{
		std::cout << "Failed to open file..\n";
		return;
	}

	while (getline(reader, line, '\n'))
	{
		//std::cout << line << std::endl;
		
		if (strstr(line.c_str(), "<map version=") != nullptr)
		{
			std::stringstream ss(line);
			while (ss >> word)
			{
				//std::cout << word << std::endl;
				if (strstr(word.c_str(), "width=") != nullptr)
				{
					mapWidth = getInt(word);
				}
				else if (strstr(word.c_str(), "height=") != nullptr)
				{
					mapHeight = getInt(word);
				}
				else if (strstr(word.c_str(), "tilewidth=") != nullptr)
				{
					tileWidth = getInt(word);
				}
				else if (strstr(word.c_str(), "tileheight=") != nullptr)
				{
					tileHeight = getInt(word);
				}
			}
		}
		else if (strstr(line.c_str(), "<tileset") != nullptr)
		{
			if (strstr(word.c_str(), "name=\"") != nullptr)
			{
				tileSetName = getString(word);
			}
		}
		else if (strstr(line.c_str(), "<image source=") != nullptr)
		{
			if (strstr(word.c_str(), "name=\"") != nullptr)
			{
				imageName = getString(word);
			}
			else if (strstr(word.c_str(), "width=") != nullptr)
			{
				imageWidth = getInt(word);
			}
			else if (strstr(word.c_str(), "height=") != nullptr)
			{
				imageHeight = getInt(word);
			}
		}
	}
}

void read2()
{
	FILE *file;
	fopen_s(&file, file_path, "r");
	
	if (file == NULL)
	{
		std::cout << "Failed to open file..\n";
		return;
	}
	char line[125];
	while ((fgets(line, 125, file)) != NULL)
	{
		//std::cout << line << std::endl;
		//std::cin.get();
	}

}

int main()
{
	read1();
	read2();
	
	
	std::string temp = "KALLE=\"213\"";
	std::cout << getString(temp) << std::endl;
	std::cout << getInt(temp) << std::endl;
	return 0;
}