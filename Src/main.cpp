#include <iostream>
#include <raylib.h>

#include "Rendering/TileRenderer.hpp"

int main() {
    std::cout << "Wellcome To OpenCT!\nBooting...\n";

    InitWindow(800, 600, TextFormat("OpenCT - Build: %s", __DATE__));
    SetTargetFPS(60);

    TileRenderer renderer(200, 200, 64, 32);

    renderer.SetTileColor(10, 10, RED);
    renderer.SetTileColor(11, 10, BLUE);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        Vector2 move = {0, 0};

        if (IsKeyDown(KEY_A)) move.x -= 400 * dt;
        if (IsKeyDown(KEY_D)) move.x += 400 * dt;
        if (IsKeyDown(KEY_W)) move.y -= 400 * dt;
        if (IsKeyDown(KEY_S)) move.y += 400 * dt;

        float zoomDelta = GetMouseWheelMove() * 0.15f;

        renderer.UpdateCamera(move, zoomDelta);

        BeginDrawing();
        ClearBackground(SKYBLUE);

        renderer.Draw();

        DrawText("WASD move | Mouse wheel zoom", 20, 20, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}