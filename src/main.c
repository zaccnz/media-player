#include "raylib.h"

void rl_text_right(char *text, Font font, float x, float y, float font_size)
{
    Vector2 size = MeasureTextEx(font, text, font_size, 1.0);
    DrawTextEx(font, text, (Vector2){x - size.x, y}, font_size, 1.0f, BLACK);
}

void rl_box(float x, float y, float width, float height)
{
    const float RADIUS = 6.0;
    float roundness = (width > height) ? (2 * RADIUS) / height : (2 * RADIUS) / width;

    Rectangle controls = (Rectangle){x, y, width, height};
    DrawRectangleRounded(controls, roundness, 10, (Color){176, 190, 197, 255});
}

int main(void)
{
    InitWindow(1024, 576, "zac's media player");
    Font font_heading = LoadFontEx("resources/Helvetica-Bold.ttf", 32.0f, NULL, 0);
    Font font_text = LoadFontEx("resources/Helvetica-Bold.ttf", 16.0f, NULL, 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        rl_box(10, 10, 1004, 44);

        rl_box(10, 74, 400, 80);
        rl_box(10, 164, 400, 402);

        rl_box(420, 74, 594, 492);

        DrawTextEx(font_heading, "zac's media player", (Vector2){16.0f, 16.0f}, 32.0f, 1.0f, BLACK);
        DrawTextEx(font_text, "v0.1.0", (Vector2){300.0f, 24.0f}, 16.0f, 1.0f, BLACK);
        rl_text_right("6:05pm", font_heading, 1008, 16, 32.0f);

        DrawTextEx(font_text, "Zac's iPhone 11 Pro Max", (Vector2){10.0f, 200.0f}, 16.0f, 1.0, BLACK);
        EndDrawing();
    }

    UnloadFont(font_heading);

    CloseWindow();

    return 0;
}