#include "AnimatedTile.h"

TMX_AnimatedTile::TMX_AnimatedTile() : TMX_Tile()
{
}

TMX_AnimatedTile::TMX_AnimatedTile(unsigned int tileID, unsigned int height, unsigned int width, TILE_TYPE type) : 
	TMX_Tile(tileID, height, width, TILE_TYPE::ANIMATED)
{	
}

TMX_AnimatedTile::~TMX_AnimatedTile()
{
}