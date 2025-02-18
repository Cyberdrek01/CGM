#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawMidpointEllipse(int xc, int yc, int a, int b) {
    int x = 0, y = b;
    float a2 = a * a, b2 = b * b;
    float p1 = b2 - (a2 * b) + (0.25 * a2);
    while (2 * b2 * x <= 2 * a2 * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        x++;
        p1 = (p1 < 0) ? p1 + b2 * (2 * x + 1) : p1 + b2 * (2 * x + 1) - 2 * a2 * (--y);
    }

    float p2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        y--;
        p2 = (p2 > 0) ? p2 + a2 * (1 - 2 * y) : p2 + b2 * (2 * (++x) + 2) + a2 * (1 - 2 * y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");
    drawMidpointEllipse(250, 250, 100, 50); 
    getch();
    closegraph();
    return 0;
}
