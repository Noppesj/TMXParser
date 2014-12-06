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

TMX_Map::~TMX_Map()
{
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

void TMX_Map::addTilesData(int data)
{
	m_TilesData.push_back(data);
}