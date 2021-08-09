#include "raylib.h"

int main(int argv, char **argc)
{

  // This is where the window dimensions begin
  int width = 1920;
  int height = 1080;

  // Circile coords
  int circle_x{960};
  int circle_y{540};
  int radius{25};

  // Circle Edges
  int l_circle_x{circle_x - radius};
  int r_circle_x{circle_x + radius};
  int u_circle_y{circle_y - radius};
  int b_circle_y{circle_y + radius};
  InitWindow(width, height, "Kairi Window");

  // axe coords
  int axe_x{960};
  int axe_y{0};
  int axe_direction{10};
  int axe_length{50};
  // Axe Edges
  int l_axe_x{axe_x};
  int r_axe_x{axe_x + axe_length};
  int u_axe_y{axe_y};
  int b_axe_y{axe_y + axe_length};

  bool collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);

  SetTargetFPS(60);
  while (WindowShouldClose() != true)
  {

    BeginDrawing();
    ClearBackground(WHITE);

    if (collision_with_axe)
    {
      DrawText("Game Over!!", 960, 300, 50, RED);
    }
    else
    {

      // update the edges
      l_circle_x = circle_x - radius;
      r_circle_x = circle_x + radius;
      u_circle_y = circle_y - radius;
      b_circle_y = circle_y + radius;

      l_axe_x = axe_x;
      r_axe_x = axe_x + axe_length;
      u_axe_y = axe_y;
      b_axe_y = axe_y + axe_length;

      collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);
      // game logic begins
      DrawCircle(circle_x, circle_y, radius, BLACK);
      // Draw the axe
      DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

      // move axe every frame
      axe_y += axe_direction;
      if (axe_y > height || axe_y < 0)
      {
        axe_direction = -axe_direction;
      }

      if (IsKeyDown(KEY_D) && (circle_x <= (width - radius)))
      {
        circle_x += 10;
      }
      else if (IsKeyDown(KEY_A) && (circle_x >= (0 + radius)))
      {
        circle_x -= 10;
      }
      else if (IsKeyDown(KEY_S) && (circle_y <= (height - radius)))
      {
        circle_y += 10;
      }
      else if (IsKeyDown(KEY_W) && (circle_y >= (0 + radius)))
      {
        circle_y -= 10;
      }

      // game logic ends
    }
    EndDrawing();
  }

  return 0;
}