#pragma once
#include <cstdint>
#include <raylib.h>
#include <sys/types.h>
#include "MapTextures.hpp"

class Map {
    public:
    Map(int MapWidth, int MapHeight, int TileWidth, int TileHeight);
    ~Map();

    void Draw(); 
    Vector2 Map2Screen(int x, int y);
    Vector2 Screen2Map(int x, int y);

    void SetTileTexture(Vector2 GridPos, uint8_t id);

    MapTextures MapTextures_;

    private:
    int MapWidth = 16;
    int MapHeight = 16;
    int TileWidth = 64;
    int TileHeight = 32;

    int ArraySize = 0;

    float INV_HALF_W = 1.0f / (TileWidth / 2.f); // 1 / (TileWidth / 2)
    float INV_HALF_H = 1.0f / (TileHeight / 2.f); // 1 / (TileHeight / 2)

    uint8_t *Tiles = nullptr;
};