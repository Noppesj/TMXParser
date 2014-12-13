#include "Map.h"
#include <iostream>

const char* tmx_path = "..//Files//test2.tmx";
const char* binfile_path = "..//Files//test3.bin";

struct map
{
	std::string m_MapName;
	unsigned int m_Size;
	unsigned int m_MapWidth;
	unsigned int m_MapHeight;

	unsigned int m_TileWidth;
	unsigned int m_TileHeight;
	std::string m_TileSetName;

	std::string m_ImageName;
	unsigned int m_ImageWidth;
	unsigned int m_ImageHeight;

	int *m_TilesData;
};

void readBin()
{
	map map;
	FILE *file;
	fopen_s(&file, binfile_path, "rb");
	
	if (!file)
	{
		std::cout << "Could not open binaryfile: " << binfile_path << ".\n";
		return;
	}

	fread(&map, sizeof(struct map), 1, file);
	map.m_TilesData = new int[map.m_Size];
	fread(&map.m_TilesData[0], sizeof(int), map.m_Size, file);

	for (unsigned int i = 0; i < map.m_Size; i++)
	{
		std::cout << map.m_TilesData[i] << "\n";
	}

	fclose(file);
}

int main()
{
	TMX_Map map;
	//map.parse(tmx_path);
	//map.printTilesData();
	//map.write(binfile_path);
	
	readBin();
	return 0;
}