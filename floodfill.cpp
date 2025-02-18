#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void floodFill(int x, int y, int fill, int oldColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, fill);
        delay(5);

        floodFill(x + 1, y, fill, oldColor);
        floodFill(x - 1, y, fill, oldColor);
        floodFill(x, y + 1, fill, oldColor);
        floodFill(x, y - 1, fill, oldColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");

    setcolor(WHITE);
    rectangle(150, 100, 450, 300);

    int oldColor = getpixel(151, 101);  // Color inside the rectangle
    floodFill(200, 150, RED, oldColor); // Fill starting from (200, 150)

    getch();
    closegraph();
    return 0;
}
