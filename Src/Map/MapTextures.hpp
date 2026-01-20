#pragma once
#include <cstdint>
#include <raylib.h>

enum class TextureID : uint8_t {
    Test = 0,
    Grass,
    Sand,
    Water
};

class MapTextures {
    public:
    MapTextures();
    ~MapTextures();

    Texture Textures[4] = {};
};