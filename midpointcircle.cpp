#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main(){
    int gd=DETECT,gm;
    initgraph(&gm,&gd,"C:\\MinGW\\lib\\libbgi.a");
    int xc,yc,x,y,r,p;
    printf("Enter the center: ");
    scanf("%d%d",&xc,&yc);
    printf("Enter the radius: ");
    scanf("%d",&r);
    p=1-r;
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
        if(p<0){
            x=x+1;
            p=p+2*x+3;
        }
        else{
            x=x+1;
            y=y-1;
            p=p+2*(x-y)+5;
        }
    }
    getch();
    closegraph();
}