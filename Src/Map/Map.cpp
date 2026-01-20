#include "Map.hpp"
#include "MapTextures.hpp"
#include <cstdint>

Map::Map(int MapWidth, int MapHeight, int TileWidth, int TileHeight) :
    MapWidth(MapWidth),
    MapHeight(MapHeight),
    TileWidth(TileWidth),
    TileHeight(TileHeight)
{
    ArraySize = MapWidth * MapHeight;
    Tiles = new uint8_t[ArraySize];
    
    for(int i = 0; i < ArraySize; i++) {
        Tiles[i] = int(TextureID::Grass);
    }
}

Map::~Map() {
    delete Tiles;
}

void Map::Draw() {
    for(int y = 0; y < MapHeight; y++) {
        for(int x = 0; x < MapWidth; x++) {
            Vector2 Pos = Map2Screen(x,y);
            DrawTexture(MapTextures_.Textures[Tiles[y * MapWidth + x]], Pos.x + 0.5, Pos.y + 0.5, Color(255,255,255,255));
        }
    }
}

Vector2 Map::Map2Screen(int x, int y) {
        return Vector2(
        (x - y) * (TileWidth / 2.f) + TileWidth,
        (x + y) * (TileHeight / 2.f) + TileHeight
    );
}