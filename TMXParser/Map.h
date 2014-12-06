#ifndef TMX_MAP_H_
#define TMX_MAP_H_

#include "AnimatedTile.h"
#include <string>
#include <unordered_map>

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

		std::unordered_map<unsigned int, TMX_Tile> m_StaticTiles;
		std::unordered_map<unsigned int, TMX_Tile> m_AnimatedTiles;

		std::vector<int> m_TilesData;
	public:
		TMX_Map();
		TMX_Map(unsigned int mapWidth, unsigned int mapHeight, std::string mapName,
				std::string tileSetName, std::string imageName, 
				unsigned int imageWidth, unsigned int imageHeight);

		virtual ~TMX_Map();

		void addStaticTile(TMX_Tile& tile);
		void addAnimatedTile(TMX_AnimatedTile& tile);
		bool isAnimatedTileLoaded(unsigned int tileID);
		bool isStaticTileLoaded(unsigned int tileID);
		void addTilesData(int data);

		void setMapWidth(const unsigned int width){ m_MapWidth = width; };
		void setMapHeight(const unsigned int height){ m_MapHeight = height; };
		void setMapName(const std::string &name){ m_MapName = name; };
		void setTileWidth(const unsigned int tileWidth){ m_TileWidth = tileWidth; };
		void setTileHeight(const unsigned int tileHeight){ m_TileHeight = tileHeight; };
		void setTileSetName(const std::string &tileSetName){ m_TileSetName = tileSetName; };
		void setImageName(const std::string &imageName){ m_ImageName = imageName; };
		void setImageWidth(const unsigned int imageWidth){ m_ImageWidth = imageWidth; };
		void setImageHeight(const unsigned int imageHeight){ m_ImageHeight = imageHeight; };

		const unsigned int getMapWidth(){ return m_MapWidth; };
		const unsigned int getMapHeight(){ return m_MapHeight; };
		const std::string& getMapName(){ return m_MapName; };
		const unsigned int getTileWidth(){ return m_TileWidth; };
		const unsigned int getTileHeight(){ return m_TileHeight; };
		const std::string& getTileSetName(){ return m_TileSetName; };
		const std::string& getImageName(){ return m_ImageName; };
		const unsigned int getImageWidth(){ return m_ImageWidth; };
		const unsigned int getImageHeight(){ return m_ImageHeight; };
};

#endif