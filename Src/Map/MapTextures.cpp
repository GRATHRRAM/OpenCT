#include "MapTextures.hpp"
#include <raylib.h>
#include <iostream>

MapTextures::MapTextures() {
    Textures[int(TextureID::Test)] = LoadTexture("Assets/Textures/Test.png");
    if(!IsTextureValid(Textures[int(TextureID::Test)])) 
        std::cout << "MapTextures -> Texture Assets/Textures/Test.png is not Valid!\n";

    Textures[int(TextureID::Select)] = LoadTexture("Assets/Textures/Select.png");
    if(!IsTextureValid(Textures[int(TextureID::Select)])) 
        std::cout << "MapTextures -> Texture Assets/Textures/Select.png is not Valid!\n";

    Textures[int(TextureID::Grass)] = LoadTexture("Assets/Textures/Grass.png");
    if(!IsTextureValid(Textures[int(TextureID::Grass)])) 
        std::cout << "MapTextures -> Texture Assets/Textures/Grass.png is not Valid!\n";

    Textures[int(TextureID::Sand)] = LoadTexture("Assets/Textures/Sand.png");
    if(!IsTextureValid(Textures[int(TextureID::Sand)])) 
        std::cout << "MapTextures -> Texture Assets/Textures/Sand.png is not Valid!\n";

    Textures[int(TextureID::Water)] = LoadTexture("Assets/Textures/Water.png");
    if(!IsTextureValid(Textures[int(TextureID::Water)])) 
        std::cout << "MapTextures -> Texture Assets/Textures/Water.png is not Valid!\n";
}

MapTextures::~MapTextures() {
    for(int i = 0; i < int(std::size(Textures)); i++) {
        UnloadTexture(Textures[i]);
    }
}