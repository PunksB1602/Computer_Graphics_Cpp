#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
int main()
{
int x,y,x_mid,y_mid,r,d;
int g_mode,g_driver=DETECT;
initgraph(&g_driver,&g_mode,NULL);
cout<<"*********** MID POINT Circle drawing algorithm ********\n\n";
cout<<"\nEnter the coordinates of centre: ";
cin>>x_mid>>y_mid;
cout<<"\nEnter the radius: ";
cin>>r;
x=0;
y=r;
d=1-r;
do
{
putpixel(x_mid+x,y_mid+y,1);
putpixel(x_mid+y,y_mid+x,1);
putpixel(x_mid-y,y_mid+x,1);
putpixel(x_mid-x,y_mid+y,1);
putpixel(x_mid-x,y_mid-y,1);
putpixel(x_mid-y,y_mid-x,1);
putpixel(x_mid+y,y_mid-x,1);
putpixel(x_mid+x,y_mid-y,1);
delay(1);
if(d<0)  {
d+=(2*x)+1;
}
else{
y=y-1;
d+=(2*x)-(2*y)+1;
}
x=x+1;
}while(y>x);
getch();
closegraph();
}