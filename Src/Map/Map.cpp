#include "Map.hpp"
#include "MapTextures.hpp"
#include <algorithm>
#include <cstdint>
#include <raylib.h>
#include <math.h>

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
    delete[] Tiles;
}

void Map::Draw() {
    for(int y = 0; y < MapHeight; y++) {
        for(int x = 0; x < MapWidth; x++) {
            Vector2 Pos = Map2Screen(x,y);
            DrawTexture(MapTextures_.Textures[Tiles[y * MapWidth + x]], Pos.x + 0.5, Pos.y + 0.5, Color(255,255,255,255));
        }
    }
}

Vector2 Map::Map2Screen(int x, int y)
{
    constexpr float halfW = 32.0f;
    constexpr float halfH = 16.0f;

    return Vector2{
        (x - y) * halfW + halfW,
        (x + y) * halfH
    };
}

Vector2 Map::Screen2Map(int screenX, int screenY)
{
    constexpr float halfW = 32.0f;
    constexpr float halfH = 16.0f;

    // Translate relative to origin (top of map)
    float localX = screenX - halfW;
    float localY = screenY;

    float fx = (localX / halfW + localY / halfH) * 0.5f;
    float fy = (localY / halfH - localX / halfW) * 0.5f;

    int tx = (int)std::floor(fx);
    int ty = (int)std::floor(fy);

    // Optional: clamp to map bounds
    tx = std::clamp(tx, 0, MapWidth-1);
    ty = std::clamp(ty, 0, MapHeight-1);

    return Vector2{ (float)tx, (float)ty };
}
