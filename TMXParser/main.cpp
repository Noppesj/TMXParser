#include "Map.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

const char* file_path = "..//Files//test2.tmx";

std::string getString(const std::string& line)
{
	std::string temp = line.substr(line.find("\""), line.length());
	std::string result = temp.substr(1,( temp.find("\"", 1) - 1));
	return result;
}

int getInt(const std::string& line)
{
	std::string temp = line.substr(line.find("\""), line.length());
	temp = temp.substr(1, (temp.find("\"", 1) - 1) );
	return (int)atof(temp.c_str());
}

void readData(std::ifstream &reader, TMX_Map &map)
{
	std::string line;
	char currentChar;
	std::string data = "";
	while (getline(reader, line, '\n'))
	{

		for (unsigned int i = 0; i < line.length(); i++)
		{
			currentChar = line[i];
			if (currentChar == ',')
			{
				map.addTilesData((int)atof(data.c_str()));
				data.clear();
			}
			else if (currentChar == '<')
			{
				return;
			}
			else
			{
				data += currentChar;
			}
		}
	}
}

void test2()
{
	FILE *file;
	TMX_Map map;
	unsigned long fileLen;

	fopen_s(&file,"..//Files//test2.bin", "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s", "..//Files//test2.bin");
		return;
	}

	fseek(file, 0, SEEK_END);
	fileLen = ftell(file);
	fseek(file, 0, SEEK_SET);


	fread(&map, fileLen, 1, file);
	fclose(file);
}

void writeBin(TMX_Map &map)
{
	FILE *fp;
	fopen_s(&fp, "..//Files//test2.bin", "wb");

	fwrite(&map, sizeof(map), 1, fp);

	fclose(fp);
	test2();
}



void read1()
{
	std::ifstream reader(file_path, std::ios_base::in);
	std::string word;
	std::string line;

	TMX_Map map;
	TMX_AnimatedTile animationTile;

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
					map.setMapWidth( getInt(word) );
				}
				else if (strstr(word.c_str(), "height=") != nullptr)
				{
					map.setMapHeight( getInt(word) );
					break;
				}
			}
		}
		else if (strstr(line.c_str(), "<tileset") != nullptr)
		{
			std::stringstream ss(line);
			while (ss >> word)
			{
				if (strstr(word.c_str(), "name=\"") != nullptr)
				{
					std::string temp = getString(word);
					map.setTileSetName(getString(word));
				}
				else if (strstr(word.c_str(), "tilewidth=") != nullptr)
				{
					map.setTileWidth(getInt(word));
				}
				else if (strstr(word.c_str(), "tileheight=") != nullptr)
				{
					map.setTileHeight(getInt(word));
				}
			}
		}
		else if (strstr(line.c_str(), "<image source=") != nullptr)
		{
			std::stringstream ss(line);
			while (ss >> word)
			{
				if (strstr(word.c_str(), "source=") != nullptr)
				{
					map.setImageName(getString(word));
				}
				else if (strstr(word.c_str(), "width=") != nullptr)
				{
					map.setImageWidth(getInt(word));
				}
				else if (strstr(word.c_str(), "height=") != nullptr)
				{
					map.setImageHeight(getInt(word));
				}
			}
		}
		else if (strstr(line.c_str(), "<tile id=") != nullptr)
		{
			unsigned int tileID = getInt(line);
			if ( !map.isAnimatedTileLoaded(tileID) )
			{
				while (getline(reader, line, '\n'))
				{
					if (strstr(line.c_str(), "<animation>") != nullptr)
					{
						animationTile.setAttributes(tileID, map.getTileWidth(), map.getTileHeight());
					}
					else if (strstr(line.c_str(), " <frame tileid=") != nullptr)
					{
						std::stringstream ss(line);
						unsigned int tileID;
						unsigned int duration;
						while (ss >> word)
						{
							if (strstr(word.c_str(), "tileid=") != nullptr)
							{
								tileID = getInt(word);
							}
							else if (strstr(word.c_str(), "duration=") != nullptr)
							{
								duration = getInt(word);
							}
						}
						animationTile.addAnimationData(tileID, duration);
					}
					else if (strstr(line.c_str(), "</tile>") != nullptr)
					{
						break;
					}
				}
			}
		}
		else if (strstr(line.c_str(), "<data encoding=") != nullptr)
		{
			readData(reader, map);
		}
	}

	reader.close();
	writeBin(map);
}


int main()
{
	read1();
	//read2();
	
	
	std::string temp = "KALLE=\"213\"";
	std::cout << getString(temp) << std::endl;
	std::cout << getInt(temp) << std::endl;
	return 0;
}