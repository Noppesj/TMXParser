#ifndef TILE_H_
#define TILE_H_

enum TILE_TYPE { UNKNOWN, STATIC, ANIMATED };

class TMX_Tile
{
	private:
	protected:
		unsigned int m_TileID;
		unsigned int m_TileHeight;
		unsigned int m_TileWidth;

		TILE_TYPE m_TileType;
	public:
		TMX_Tile();
		TMX_Tile(unsigned int tileID, unsigned int height, unsigned int width, TILE_TYPE type);
		virtual ~TMX_Tile();

		unsigned int getTileID(){ return m_TileID; }
};
#endif