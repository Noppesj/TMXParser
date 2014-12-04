#include "Map.h"


TMX_Map::TMX_Map()
{}

TMX_Map::TMX_Map(unsigned int mapWidth, unsigned int mapHeight, std::string mapName,
	std::string tileSetName, std::string imageName,
	unsigned int imageWidth, unsigned int imageHeight) :
	m_MapWidth(mapWidth),
	m_MapHeight(mapHeight),
	m_MapName(mapName),
	m_TileSetName(tileSetName),
	m_ImageName(imageName),
	m_ImageWidth(imageWidth),
	m_ImageHeight(imageHeight)
{
}

void TMX_Map::addTile(const TMX_Tile& tile)
{
	mTiles.push_back(tile);
}

void TMX_Map::addAnimatedTile(const TMX_AnimatedTile& tile)
{
	mAnimatedTiles.push_back(tile);
}