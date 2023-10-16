#include <stdio.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>

#define X_MAX 50
#define Y_MAX 50
wchar_t display[Y_MAX][X_MAX];

wchar_t empty = 0x1F7E5;    //
wchar_t full = 0x2B1B;
typedef struct Point{
   int x;
   int y;
}point;

void drawPoint(point p, char on) {
   display[Y_MAX-p.y][p.x] = empty;
}

void drawLine(point p1, point p2, char on) {
   float m;
   float b;
   m = (float) (p2.y  - p1.y ) / (p2.x - p1.x);
   b = (float)(p1.y - (m*p1.x));
   printf("slope = %f\n", m);
   printf("B = %f\n", b);

   int current_y = 0;
   for (int current_x = p1.x + 1; current_x <= p2.x ; current_x++)
   {
      drawPoint(p1, 0);
      current_y = m*(current_x) + b;
      p1.x++;
      p1.y = round(current_y);
      
      printf("y = %i\n", current_y);
   }
   drawPoint(p1, 0);
}

int main()
{
   setlocale(LC_CTYPE, "");
   float m;


   for (int y = 0; y < Y_MAX; y++)
   {
      for (int x = 0; x < Y_MAX; x++)
      {
         display[y][x] = full;
      }
   }
   //Given 2 points create line
   point p1;
   p1.x = 3;
   p1.y = 3;

   point p2;
   p2.x = 35;
   p2.y = 28;

   drawLine(p1, p2, 0);


   for (int y = 0; y < Y_MAX; y++)
   {
      for (int x = 0; x < Y_MAX; x++)
      {
         printf("%lc", display[y][x]);
      }
      printf("\n");
   }

   return 0;
}

