#include "AnimatedTile.h"

TMX_AnimatedTile::TMX_AnimatedTile() : TMX_Tile()
{
}

TMX_AnimatedTile::TMX_AnimatedTile(unsigned int tileID, unsigned int height, unsigned int width) : 
	TMX_Tile(tileID, height, width, TILE_TYPE::ANIMATED)
{	
}

TMX_AnimatedTile::~TMX_AnimatedTile()
{
}

void TMX_AnimatedTile::addAnimationData(unsigned int tileID, unsigned int duration)
{
	AnimationData data;
	data.tileID = tileID;
	data.duration = duration;
	m_AnimationData.push_back(data);
}

void TMX_AnimatedTile::setAttributes(unsigned int tileID, unsigned width, unsigned int height)
{
	m_TileID = tileID;
	m_TileWidth = width;
	m_TileHeight = height;
}