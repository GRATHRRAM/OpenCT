#include <cstddef>
#include <cstdint>
#include <iostream>
#include <raylib.h>

#define MapWidth 16
#define MapHeight 16
#define TilesSize MapHeight * MapWidth

#define TileWidth 64
#define TileHeight 32

Vector2 Map2Screen(int x, int y) {
    return Vector2(
        (x - y) * (TileWidth / 2.f) + TileWidth,
        (x + y) * (TileHeight / 2.f) + TileHeight
    );
}

int main() {
    std::cout << "Wellcome To OpenCT!\nBooting...\n";

    InitWindow(800, 600, TextFormat("OpenCT - Build: %s", __DATE__));
    SetTargetFPS(60);

    Camera2D Camera = {};
    Camera.zoom = 1.f;

    Texture Text = LoadTexture("Assets/Textures/test.png");
    if(!IsTextureValid(Text)) std::cout << "invalid texture\n";

    uint8_t Tiles[TilesSize] = {};

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        if (IsKeyDown(KEY_A)) Camera.offset.x += 400 * dt;
        if (IsKeyDown(KEY_D)) Camera.offset.x -= 400 * dt;
        if (IsKeyDown(KEY_W)) Camera.offset.y += 400 * dt;
        if (IsKeyDown(KEY_S)) Camera.offset.y -= 400 * dt;

        Camera.zoom += GetMouseWheelMove() * 0.15f;
        if (Camera.zoom < 0.25f) Camera.zoom = 0.25f;
        if (Camera.zoom > 4.0f)  Camera.zoom = 4.0f;

        BeginDrawing();
        ClearBackground(SKYBLUE);
            BeginMode2D(Camera);
            DrawCircle(0, 0, 200, WHITE);
            DrawTexture(Text, 0, 0, Color(255,255,255,255));

            for(int y = 0; y < MapHeight; y++) {
                for(int x = 0; x < MapWidth; x++) {
                    Vector2 Pos = Map2Screen(x,y);
                    DrawTexture(Text, Pos.x + 0.5, Pos.y + 0.5, Color(255,255,255,255));
                }
            }

            EndMode2D();
        DrawText("WASD move | Mouse wheel zoom", 20, 20, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}