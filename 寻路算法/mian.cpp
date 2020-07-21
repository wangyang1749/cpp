#include<stdio.h> 
#include<stdlib.h> 
#include<graphics.h> 
//g++ mian.cpp -lgraph
//https://www.cnblogs.com/king-lps/p/7757919.html
//  g++ mian.cpp -L/usr/local/lib -lgraph
int main() 
{ 
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, NULL); 
    IMAGE s;
    circle(50, 50, 30); 
  
    delay(500000); 
    closegraph(); 
    return 0; 
} 