#pragma once
#include <cstdint>
#include <raylib.h>

enum class TextureID : uint8_t {
    Test = 0,
    Select,
    Grass,
    Sand,
    Water
};

class MapTextures {
    public:
    MapTextures();
    ~MapTextures();

    Texture Textures[5] = {};
};