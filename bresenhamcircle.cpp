#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int main(){
    int gd=DETECT,gm;
    int x,y,xc,yc,r,d;
    printf("Enterr the center of circle: ");
    scanf("%d%d",&xc,&yc);
    printf("Enter the radius of circle: ");
    scanf("%d",&r);
    initgraph(&gd,&gm,"C:\\MinGW\\lib\\libbgi.a");
    d=3-2*r;
    x=0;y=r;
    while(x<=y){
    putpixel(x+xc,y+yc,WHITE);
    putpixel(x+xc,-y+yc,WHITE);
    putpixel(-x+xc,-y+yc,WHITE);
    putpixel(-x+xc,y+yc,WHITE);
    putpixel(y+xc,x+yc,WHITE);
    putpixel(y+xc,-x+yc,WHITE);
    putpixel(-y+xc,-x+yc,WHITE);
    putpixel(-y+xc,x+yc,WHITE);

    if(d<=0){
        x=x+1;
        d=d+4*x+6;
    }
    else{
        x=x+1;
        y=y-1;
        d=d+4*(x-y)+10;
    }
}
getch();
closegraph();
}