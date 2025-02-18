#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if ((currentColor != boundaryColor) && (currentColor != fillColor)) {
        putpixel(x, y, fillColor);
        delay(5);

        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
        boundaryFill(x + 1, y+1, fillColor, boundaryColor);
        boundaryFill(x - 1, y+1, fillColor, boundaryColor);
        boundaryFill(x+1, y - 1, fillColor, boundaryColor);
        boundaryFill(x-1, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");

    setcolor(WHITE);
    rectangle(150, 100, 450, 300);  // Draw a rectangle as the boundary

    int boundaryColor = WHITE;
    int fillColor = YELLOW;
    boundaryFill(200, 150, fillColor, boundaryColor);  // Call boundary fill

    getch();
    closegraph();
    return 0;
}
