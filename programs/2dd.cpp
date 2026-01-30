#include <iostream> 
#include <graphics.h> 
#include <stdio.h> 
#include <math.h> 
using namespace std; 
typedef struct{ 
int x,y; 
}point; 
typedef struct{ 
point p1, p2,p3; 
} triangle; 
void dda(int x1, int y1, int x2, int y2, int color) { 
int dx = x2 - x1; 
int dy = y2 - y1; 
int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
float incX = float(dx) / steps; 
float incY = float(dy) / steps; 
float x = x1, y = y1; 
for (int i = 0; i <= steps; i++) { 
putpixel(int(x + 0.5), int(y + 0.5), color); 
x += incX; 
y += incY; 
} 
} 
void drawAxis(){ 
dda(300, 0, 300, 500, WHITE); 
dda(0, 220, 800, 220, WHITE); 
} 
void drawTriangle(triangle t, int color) { 
dda(t.p1.x, t.p1.y, t.p2.x, t.p2.y, color); 
dda(t.p2.x, t.p2.y, t.p3.x, t.p3.y, color); 
dda(t.p3.x, t.p3.y, t.p1.x, t.p1.y, color); 
} 
void reflectYAxis(triangle& t) { 
t.p1.x = 300+300-t.p1.x; 
t.p2.x = 300+300-t.p2.x; 
t.p3.x = 300+300-t.p3.x; 
} 
void reflectXAxis(triangle& t) { 
t.p1.y = 220+220-t.p1.y; 
t.p2.y = 220+220-t.p2.y; 
t.p3.y = 220+220-t.p3.y; 
} 
void rotateTriangle(triangle& t, double angle) { 
double cosVal = cos(angle); 
double sinVal = sin(angle); 
int centerX = (t.p1.x + t.p2.x + t.p3.x) / 3; 
int centerY = (t.p1.y + t.p2.y + t.p3.y) / 3; 
int newX, newY; 
newX = round(centerX + (t.p1.x - centerX) * cosVal - (t.p1.y - centerY) * sinVal); 
newY = round(centerY + (t.p1.x - centerX) * sinVal + (t.p1.y - centerY) * cosVal); 
t.p1.x = newX; 
t.p1.y = newY; 
newX = round(centerX + (t.p2.x - centerX) * cosVal - (t.p2.y - centerY) * sinVal); 
newY = round(centerY + (t.p2.x - centerX) * sinVal + (t.p2.y - centerY) * cosVal); 
t.p2.x = newX; 
t.p2.y = newY; 
newX = round(centerX + (t.p3.x - centerX) * cosVal - (t.p3.y - centerY) * sinVal); 
newY = round(centerY + (t.p3.x - centerX) * sinVal + (t.p3.y - centerY) * cosVal); 
t.p3.x = newX; 
t.p3.y = newY; 
} 
int main() 
{ 
int gd = DETECT, gm; 
initgraph(&gd, &gm, ""); 
drawAxis(); 
triangle t1 = {180,90, 120,160, 77, 88}; 
drawTriangle(t1, YELLOW); 
reflectYAxis(t1); 
drawTriangle(t1, GREEN); 
triangle t2 = {180,90, 120,160, 77, 88}; 
reflectXAxis(t2); 
drawTriangle(t2, CYAN); 
triangle t3 = {180,90, 120,160, 77, 88}; 
rotateTriangle(t3, 3.141592/3); 
drawTriangle(t3, BLUE); 
setcolor(WHITE); 
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2); 
outtextxy(27, 180, "Rotation"); 
outtextxy(320, 170, "Reflection in"); 
outtextxy(327, 190, "Y-axis"); 
outtextxy(12, 420, "\nReflection in"); 
outtextxy(15, 440, "X-axis"); 
getchar(); 
closegraph(); 
}