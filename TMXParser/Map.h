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

		int *m_TilesData;
		unsigned int m_Size;

		void addStaticTile(TMX_Tile& tile);
		void addAnimatedTile(TMX_AnimatedTile& tile);
		bool isAnimatedTileLoaded(unsigned int tileID);
		bool isStaticTileLoaded(unsigned int tileID);
		void addTilesData(int data, unsigned int index);
		void init(unsigned int size);

		int getInt(const std::string &line);
		std::string getString(const std::string &line);
		void readData(std::ifstream &reader);

	public:
		TMX_Map();
		virtual ~TMX_Map();

		const unsigned int getMapWidth(){ return m_MapWidth; };
		const unsigned int getMapHeight(){ return m_MapHeight; };
		const std::string& getMapName(){ return m_MapName; };
		const unsigned int getTileWidth(){ return m_TileWidth; };
		const unsigned int getTileHeight(){ return m_TileHeight; };
		const std::string& getTileSetName(){ return m_TileSetName; };
		const std::string& getImageName(){ return m_ImageName; };
		const unsigned int getImageWidth(){ return m_ImageWidth; };
		const unsigned int getImageHeight(){ return m_ImageHeight; };

		void printTilesData();
		bool parse(const char *tmxFile_path);
		bool write(const char *bin_path);
};

#endif