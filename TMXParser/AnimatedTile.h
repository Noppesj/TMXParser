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
	public:
		TMX_AnimatedTile();
		TMX_AnimatedTile(unsigned int tileID, unsigned int height, unsigned int width);
		virtual ~TMX_AnimatedTile();

		void addAnimationData(unsigned int tileID, unsigned int duration);
		void setAttributes(unsigned int tileID, unsigned width, unsigned int height);
};
#endif