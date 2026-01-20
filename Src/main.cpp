#include "Map/Map.hpp"
#include "Map/MapTextures.hpp"
#include <iostream>
#include <raylib.h>

/*
    TODO ONLY DRAW Tiles that on the Screen!!!
*/

int main() {
    std::cout << "Wellcome To OpenCT!\nBooting...\n";

    InitWindow(800, 600, TextFormat("OpenCT - Build: %s", __DATE__));
    SetTargetFPS(60);

    Camera2D Camera = {};
    Camera.zoom = 1.f;

    Map _Map(32,32,64,32);

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

        Vector2 Mouse = Vector2(GetMouseX(),GetMouseY());
        Vector2 MouseWorld = GetScreenToWorld2D(Mouse, Camera);
        Vector2 TileSelected = _Map.Screen2Map(MouseWorld.x, MouseWorld.y);

        if(IsKeyDown(KEY_ZERO))  _Map.SetTileTexture(TileSelected, 0);
        if(IsKeyDown(KEY_ONE))   _Map.SetTileTexture(TileSelected, 1);
        if(IsKeyDown(KEY_TWO))   _Map.SetTileTexture(TileSelected, 2);
        if(IsKeyDown(KEY_THREE)) _Map.SetTileTexture(TileSelected, 3);
        if(IsKeyDown(KEY_FOUR))  _Map.SetTileTexture(TileSelected, 4);
        

        BeginDrawing();
        ClearBackground(BLACK);
            BeginMode2D(Camera);

            _Map.Draw();

            Vector2 SelectCords = _Map.Map2Screen(TileSelected.x, TileSelected.y);
            DrawTexture(_Map.MapTextures_.Textures[int(TextureID::Select)], SelectCords.x, SelectCords.y, WHITE);

            EndMode2D();
        DrawText("WASD move | Mouse wheel zoom", 20, 20, 20, LIGHTGRAY);
        DrawText(TextFormat("Tile Selected: X: %.0f Y: %.0f", TileSelected.x, TileSelected.y), 20, 50, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}