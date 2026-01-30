#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int gd=DETECT,gm,s;
    initgraph(&gd,&gm,(char*)"");
    cout<<"1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing   "<<endl;
    cout<<"Selection:";
    cin>>s;
    switch(s)
        {
        case 1:
            {   int x1=200,y1=150,x2=300,y2=250;
                int tx=50,ty=50;
                outtextxy(50,50,"Blue: Rectangle before translation");
                setcolor(3);
                rectangle(x1,y1,x2,y2);
                setcolor(4);
                outtextxy(50,80,"Red: Rectangle after translation");
                rectangle(x1+tx,y1+ty,x2+tx,y2+ty);
                getch();
                break;
            }
        case 2:
            {  long x1=200,y1=200,x2=300,y2=300;
                double a;
                cout<<"Rectangle with rotation"<<endl;
                setcolor(3);
                rectangle(x1,y1,x2,y2);
                cout<<"Angle of rotation:";
                cin>>a;
                a=(a*3.14)/180;
                long xr=x1+((x2-x1)*cos(a)-(y2-y1)*sin(a));
                long yr=y1+((x2-x1)*sin(a)+(y2-y1)*cos(a));
                setcolor(2);
                rectangle(x1,y1,xr,yr);
                getch();
                break;
}
        case 3:
            {
                int x1=30,y1=30,x2=70,y2=70,y=2,x=2;
                outtextxy(50,150,"Blue: Before scaling");
                setcolor(3);
                rectangle(x1,y1,x2,y2);
                outtextxy(50,160,"Green: After scaling");
                setcolor(10);
                rectangle(x1*x,y1*y,x2*x,y2*y);
                getch();
                break;
}
        case 4:
            {
                 int x1=200,y1=300,x2=500,y2=300,x3=350,y3=400;
                 outtextxy(50,60,"Purple: triangle before reflection");
                 setcolor(3);
                 line(x1,y1,x2,y2);
                 line(x1,y1,x3,y3);
                 line(x2,y2,x3,y3);
				 outtextxy(50,90,"Blue: triangle after reflection");
                 setcolor(5);
                 line(x1,-y1+500,x2,-y2+500);
                 line(x1,-y1+500,x3,-y3+500);
                 line(x2,-y2+500,x3,-y3+500);
                 getch();
                 break;
}
        case 5:
        {
  int x1=400,y1=100,x2=600,y2=100,x3=400,y3=200,x4=600,y4=200,shx=2;
             outtextxy(50,60,"Blue: Before shearing of rectangle");
             setcolor(3);
             line(x1,y1,x2,y2);
             line(x1,y1,x3,y3);
             line(x3,y3,x4,y4);
             line(x2,y2,x4,y4);
             outtextxy(50,70,"Purple: After shearing of rectangle");
             x1=x1+shx*y1;
             x2=x2+shx*y2;
             x3=x3+shx*y3;
             x4=x4+shx*y4;
             setcolor(13);
             line(x1,y1,x2,y2);
             line(x1,y1,x3,y3);
             line(x3,y3,x4,y4);
             line(x2,y2,x4,y4);
getch();
}
default:
          {
            cout<<"Invalid Selection"<<endl;
            break;
          }
        }
closegraph();
    return 0;
}