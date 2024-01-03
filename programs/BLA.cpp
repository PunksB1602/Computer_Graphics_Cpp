#include<iostream> 
#include<math.h> 
#include<graphics.h> 
#include<conio.h> 
using namespace std; 
int main() 
{ 
int gd=DETECT,gm; 
int x1,y1,x2,y2,dx,dy,m,p,i; 
initgraph(&gd,&gm,NULL); 
cout<<"Enter the initial points: "; 
cin>>x1>>y1; 
cout<<"Enter the final points: "; 
cin>>x2>>y2; 
putpixel(x1,y1,RED); 
dx=fabs(x2-x1); 
dy=fabs(y2-y1); 
m=dy/dx; 
if(m<=1) 
 { 
  p=2*dy-dx; 
  for(i=0;i<dx;i++) 
  { 
   if(p<0) 
   { 
    x1=x1+1; 
    putpixel(x1,y1,RED); 
    p=p+2*dy; 
   } 
   else 
   { 
    x1=x1+1; 
    y1=y1+1; 
    putpixel(x1,y1,RED); 
    p=p+2*dx-2*dy; 
   } 
  } 
 } 
 else 
 { 
  p=2*dx-dy; 
  if(p<0) 
  { 
   y1=y1+1; 
   putpixel(x1,y1,RED); 
   p=p+2*dx; 
  } 
  else 
  { 
   x1=x1+1; 
   y1=y1+1; 
   putpixel(x1,y1,RED); 
   p=p+2*dx-2*dy; 
  } 
 } 
 getch(); 
 closegraph(); 
 return 0; 
}