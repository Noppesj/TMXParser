#include "Tile.h"

TMX_Tile::TMX_Tile()
{
	m_TileID = 0;
	m_TileHeight = 0;
	m_TileWidth = 0;
	m_TileType = TILE_TYPE::UNKNOWN;
}

TMX_Tile::TMX_Tile(unsigned int tileID, unsigned int height, unsigned int width, TILE_TYPE) : 
m_TileID(tileID),
m_TileHeight(height),
m_TileWidth(width),
m_TileType(TILE_TYPE::STATIC)
{
}

TMX_Tile::~TMX_Tile()
{

}