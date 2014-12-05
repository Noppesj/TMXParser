#ifndef TMX_MAP_H_
#define TMX_MAP_H_

#include "AnimatedTile.h"
#include <string>

class TMX_Map
{
	private:
		std::string m_MapName;
		unsigned int m_MapWidth;
		unsigned int m_MapHeight;

		unsigned int m_TileWidth;
		unsigned int m_TileHeight;
		std::string m_TileSetName;
		
		std::string m_ImageName;
		unsigned int m_ImageWidth;
		unsigned int m_ImageHeight;

		std::vector<TMX_Tile> mTiles;
		std::vector<TMX_AnimatedTile> mAnimatedTiles;

		TMX_Map();
	public:
		TMX_Map(unsigned int mapWidth, unsigned int mapHeight, std::string mapName,
				std::string tileSetName, std::string imageName, 
				unsigned int imageWidth, unsigned int imageHeight);

		void addTile(const TMX_Tile& tile);
		void addAnimatedTile(const TMX_AnimatedTile& tile);

};

#endif