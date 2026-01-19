#pragma once
#include <raylib.h>
#include <vector>

struct Tile {
    Color color;
};

class TileRenderer {
public:
    TileRenderer(int MapWidth, int MapHeight, int TileWidth, int TileHeight);

    void SetTileColor(int x, int y, Color color);

    void UpdateCamera(Vector2 Move, float ZoomDelta);
    void Draw();

private:
    // Map
    int MapWidth;
    int MapHeight;

    // Base tile size (unscaled)
    int BaseTileWidth;
    int BaseTileHeight;

    // Camera
    Vector2 CameraPos;
    float Zoom;

    std::vector<Tile> Tiles;

    Vector2 WorldToScreen(int x, int y) const;
    bool IsOnScreen(const Vector2& pos) const;
};
