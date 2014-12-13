#include "Map.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

TMX_Map::TMX_Map()
{
	m_TilesData = nullptr;
}


TMX_Map::~TMX_Map()
{
	delete [] m_TilesData;
}

void TMX_Map::addStaticTile(TMX_Tile& tile)
{
	unsigned int tileID = tile.getTileID();
	if (m_StaticTiles.count(tileID) == 0)
	{
		m_StaticTiles.emplace(tileID, tile);
	}
}

void TMX_Map::addAnimatedTile(TMX_AnimatedTile& tile)
{
	unsigned int tileID = tile.getTileID();
	if ( m_AnimatedTiles.count(tileID) == 0)
	{
		m_AnimatedTiles.emplace(tileID, tile);
	}
}

bool TMX_Map::isAnimatedTileLoaded(unsigned int tileID)
{
	if (m_AnimatedTiles.count(tileID) == 0)
	{
		return false;
	}
	return true;
}

bool TMX_Map::isStaticTileLoaded(unsigned int tileID)
{
	if (m_StaticTiles.count(tileID) == 0)
	{
		return false;
	}
	return true;
}

std::string TMX_Map::getString(const std::string &line)
{
	std::string temp = line.substr(line.find("\""), line.length());
	std::string result = temp.substr(1, (temp.find("\"", 1) - 1));
	return result;
}

int TMX_Map::getInt(const std::string &line)
{
	std::string temp = line.substr(line.find("\""), line.length());
	temp = temp.substr(1, (temp.find("\"", 1) - 1));
	return (int)atof(temp.c_str());
}

void TMX_Map::addTilesData(int data, unsigned int index)
{
	m_TilesData[index] = data;
}

void TMX_Map::printTilesData()
{
	for (unsigned int i = 0; i < m_Size; i++)
	{
		std::cout << m_TilesData[i] << "\n";
	}
}

void TMX_Map::readData(std::ifstream &reader)
{
	std::string line;
	char currentChar;
	std::string data = "";
	int dataInt = 0;
	int index = 0;
	m_Size = m_MapWidth * m_MapHeight;
	m_TilesData = new int[m_Size];
	while (getline(reader, line, '\n'))
	{

		for (unsigned int i = 0; i < line.length(); i++)
		{
			currentChar = line[i];
			if (currentChar == ',')
			{
				dataInt = (int)atof(data.c_str());
				m_TilesData[index] = dataInt;
				data.clear();
				index++;
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

bool TMX_Map::parse(const char *tmxFile_path)
{
	std::ifstream reader(tmxFile_path, std::ios_base::in);
	std::string word;
	std::string line;

	if (!reader.is_open())
	{
		std::cout << "Failed to open TMX-file..\n";
		return false;
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
					m_MapWidth = getInt(word);
				}
				else if (strstr(word.c_str(), "height=") != nullptr)
				{
					m_MapHeight = getInt(word);
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
					m_TileSetName = getString(word);
				}
				else if (strstr(word.c_str(), "tilewidth=") != nullptr)
				{
					m_TileWidth = getInt(word);
				}
				else if (strstr(word.c_str(), "tileheight=") != nullptr)
				{
					m_TileHeight = getInt(word);
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
					m_ImageName = getString(word);
				}
				else if (strstr(word.c_str(), "width=") != nullptr)
				{
					m_ImageWidth = getInt(word);
				}
				else if (strstr(word.c_str(), "height=") != nullptr)
				{
					m_ImageHeight = getInt(word);
				}
			}
		}
		else if (strstr(line.c_str(), "<tile id=") != nullptr)
		{
			unsigned int tileID = getInt(line);
			if (!isAnimatedTileLoaded(tileID))
			{
				while (getline(reader, line, '\n'))
				{
					if (strstr(line.c_str(), "<animation>") != nullptr)
					{
						//animationTile.setAttributes(tileID, map.m_TileWidth, map.m_TileHeight);
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
						//animationTile.addAnimationData(tileID, duration);
					}
					else if (strstr(line.c_str(), "</tile>") != nullptr)
					{
						break;
					}
				}
			}
		}
		if (strstr(line.c_str(), "<data encoding=") != nullptr)
		{
			readData(reader);
		}
	}
	reader.close();
	return true;
}

bool TMX_Map::write(const char *bin_path)
{
	FILE *file;
	fopen_s(&file, bin_path, "wb");
	
	if (!file)
	{
		std::cout << "Could not open binary file: " << bin_path << ".\n";
		return false;
	}
	else
	{
		fwrite(&m_MapName, sizeof(std::string), 1, file);
		fwrite(&m_Size, sizeof(unsigned int), 1, file);
		fwrite(&m_MapWidth, sizeof(unsigned int), 1, file);
		fwrite(&m_MapHeight, sizeof(unsigned int), 1, file);
		fwrite(&m_TileWidth, sizeof(unsigned int), 1, file);
		fwrite(&m_TileHeight, sizeof(unsigned int), 1, file);
		fwrite(&m_TileSetName, sizeof(std::string), 1, file);
		fwrite(&m_ImageName, sizeof(std::string), 1, file);
		fwrite(&m_ImageWidth, sizeof(unsigned int), 1, file);
		fwrite(&m_ImageHeight, sizeof(unsigned int), 1, file);

		for (unsigned int i = 0; i < m_Size; i++)
		{
			fwrite(&m_TilesData[i], sizeof(int), 1, file);
		}
	}
	
	fclose(file);
}