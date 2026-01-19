#include "TileRenderer.hpp"
#include <raylib.h>

TileRenderer::TileRenderer(int MapWidth, int MapHeight, int TileWidth, int TileHeight)
    : MapWidth(MapWidth),
      MapHeight(MapHeight),
      BaseTileWidth(TileWidth),
      BaseTileHeight(TileHeight),
      CameraPos{0, 0},
      Zoom(1.0f)
{
    Tiles.resize(MapWidth * MapHeight);

    for (int i = 0; i < int(Tiles.size()); i++) {
        Tiles[i].color = GREEN;
    }
}

void TileRenderer::SetTileColor(int x, int y, Color color) {
        if (x < 0 || y < 0 || x >= MapWidth || y >= MapHeight)
        return;

    Tiles[y * MapWidth + x].color = color;
}

void TileRenderer::UpdateCamera(Vector2 move, float ZoomDelta) {
    CameraPos.x += move.x / Zoom;
    CameraPos.y += move.y / Zoom;

    Zoom += ZoomDelta;
    if (Zoom < 0.25f) Zoom = 0.25f;
    if (Zoom > 4.0f)  Zoom = 4.0f;
}

Vector2 TileRenderer::WorldToScreen(int x, int y) const {
    float tileW = BaseTileWidth * Zoom;
    float tileH = BaseTileHeight * Zoom;

    Vector2 screen;
    screen.x = (x - y) * (tileW / 2.0f);
    screen.y = (x + y) * (tileH / 2.0f);

    screen.x -= CameraPos.x;
    screen.y -= CameraPos.y;

    screen.x += GetScreenWidth() / 2.0f;
    screen.y += GetScreenHeight() / 4.0f;

    return screen;
}

bool TileRenderer::IsOnScreen(const Vector2& pos) const {
    float tileW = BaseTileWidth * Zoom;
    float tileH = BaseTileHeight * Zoom;

    return !(pos.x + tileW < 0 ||
             pos.y + tileH < 0 ||
             pos.x > GetScreenWidth() ||
             pos.y > GetScreenHeight());
}

void TileRenderer::Draw()
{
    float tileW = BaseTileWidth * Zoom;
    float tileH = BaseTileHeight * Zoom;

    for (int y = 0; y < MapHeight; ++y)
    {
        for (int x = 0; x < MapWidth; ++x)
        {
            Vector2 pos = WorldToScreen(x, y);
            if (!IsOnScreen(pos))
                continue;

            Color c = Tiles[y * MapWidth + x].color;

            Vector2 diamond[4] = {
                { pos.x + tileW / 2.0f, pos.y },             // top
                { pos.x + tileW,       pos.y + tileH / 2.0f }, // right
                { pos.x + tileW / 2.0f, pos.y + tileH },    // bottom
                { pos.x,               pos.y + tileH / 2.0f }  // left
            };

            DrawLineV(diamond[0], diamond[1], BLACK);
            DrawLineV(diamond[1], diamond[2], BLACK);
            DrawLineV(diamond[2], diamond[3], BLACK);
            DrawLineV(diamond[3], diamond[0], BLACK);
        }
    }
}
