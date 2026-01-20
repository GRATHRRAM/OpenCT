#pragma once
#include <cstdint>
#include <raylib.h>
#include "MapTextures.hpp"

class Map {
    public:
    Map(int MapWidth, int MapHeight, int TileWidth, int TileHeight);
    ~Map();

    void Draw(); 
    Vector2 Map2Screen(int x, int y);

    private:
    int MapWidth = 16;
    int MapHeight = 16;
    int TileWidth = 64;
    int TileHeight = 32;

    int ArraySize = 0;

    uint8_t *Tiles = nullptr;

    MapTextures MapTextures_;
};