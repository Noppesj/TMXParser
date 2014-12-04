#ifndef ANIMATEDTILE_H_
#define ANIMATEDTILE_H_

#include "Tile.h"
#include <vector>

struct AnimationData
{
	unsigned int duration;
	unsigned int tileID;
};

class TMX_AnimatedTile : public TMX_Tile
{
	private:
		std::vector<AnimationData> m_AnimationData;

		TMX_AnimatedTile();
	public:
		TMX_AnimatedTile(unsigned int tileID, unsigned int height, unsigned int width, TILE_TYPE type);
		~TMX_AnimatedTile();
};
#endif