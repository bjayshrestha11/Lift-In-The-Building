#include <iostream>
#include <iomanip>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

//Globals Variables-->
char quit;  //user input through keyboard
//for building and lift cl=current lift,df=destination lift,bp=building position
int bp=30,cl=bp+400,df=bp+400;
int msg=bp+350+50;    //Position for message box
//colors building,lift,window,current lift,next circle
int bcol=RED,lcol=YELLOW,wcol=GREEN,clcol=BLUE,nxcol=RED;
int i,d=10;  //for loop, delay

int clx=bp+350+40,cly=150; //mini current lift window position w.r.t bp
//Function Prototypes-->
//translate window a[] with left l,top t,right r and bottom b
void nextwindow (int a[],int l,int t,int r,int b);
void floor(int x,int n);    //floor x=position n=number
void Message(int x);    //Print Message
//Make Building at left x,and lf for lift position
void building (int x,int lf);
//To make lift at x, pos and line starting from ln
void lift(int x,int pos,int ln);
//draw current lift window or mini window to choose for users
void drawCL (int x,int y);
//draw next circle w.r.t a[] containing center of first circle
void nxtcircle(int a[2],int tx,int ty);
//main area for run a code
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    building(bp,cl);
    drawCL(clx,cly);
    while(1)
    {
        Message(msg);
        quit = getch();
        if(quit=='1' || quit=='a')
        {
            cleardevice();
            while(cl!=(df))
            {
                outtextxy(clx+115,cly+200,"1");
                building(bp,cl);
                delay(d);
                cleardevice();
                drawCL(clx,cly);
                if(cl>df)
                    cl--;
                else
                    cl++;
            }
            outtextxy(clx+115,cly+220,"1");
        }
        else if(quit=='2' || quit=='b')
        {
            cleardevice();
            while(cl!=(df-65))
            {
                outtextxy(clx+115,cly+200,"2");
                building(bp,cl);
                delay(d);
                cleardevice();
                drawCL(clx,cly);
                if(cl>df-65)
                    cl--;
                else
                    cl++;
            }
            outtextxy(clx+115,cly+220,"2");
        }
        else if(quit=='3' || quit=='c')
        {
            cleardevice();
            while(cl!=(df-2*65))
            {
                outtextxy(clx+115,cly+200,"3");
                building(bp,cl);
                delay(d);
                cleardevice();
                drawCL(clx,cly);
                if(cl>df-2*65)
                    cl--;
                else
                    cl++;
            }
            outtextxy(clx+115,cly+220,"3");
        }
        else if(quit=='4' || quit=='d')
        {
            cleardevice();
            while(cl!=(df-3*65))
            {
                outtextxy(clx+115,cly+200,"4");
                building(bp,cl);
                delay(d);
                cleardevice();
                drawCL(clx,cly);
                if(cl>df-3*65)
                    cl--;
                else
                    cl++;
            }
            outtextxy(clx+115,cly+220,"4");
        }
        else if(quit=='5' || quit=='e')
        {
            cleardevice();
            while(cl!=(df-4*65))
            {
                outtextxy(clx+115,cly+200,"5");
                building(bp,cl);
                delay(d);
                cleardevice();
                drawCL(clx,cly);
                if(cl>df-4*65)
                    cl--;
                else
                    cl++;
            }
            outtextxy(clx+115,cly+220,"5");
        }
        else if(quit=='6' || quit=='f')
        {
            cleardevice();
            while(cl!=(df-5*65))
            {
                outtextxy(clx+115,cly+200,"6");
                building(bp,cl);
                delay(d);
                cleardevice();
                drawCL(clx,cly);
                if(cl>df-5*65)
                    cl--;
                else
                    cl++;
            }
            outtextxy(clx+115,cly+220,"6");
        }
        else if(quit=='q' || quit=='Q')
        {
            exit(1);
        }
        else
        {
            continue;
        }
        building(bp,cl);//important
        drawCL(clx,cly);
    }
    closegraph();
    return 0;
}
//functions definitions
void building (int x,int lf)
{
    int l=x,t=l+10,r=l+350,b=t+390;
    rectangle(l,t,r,b);
    Message(msg);
    int m=(l+r)/2;
    line(m-20,t,m-20,b);
    line(m+20,t,m+20,b);
    lift(m,lf-30,t);
    floor(x,6);
    //drawCL(clx,cly);
}
void floor(int x,int n)
{
    int sz=0,fl[4],fx,fy;
   for(i=0;i<n;i++)
   {
      sz=sz+65;
      setfillstyle(SOLID_FILL,bcol);
      line(x,x+10+sz,x+350,x+10+sz);
      fx=x+10;
      fy=30+sz-10;
      floodfill(fx,fy,WHITE);
      fx=x+10+240;
      fy=30+sz-10;
      floodfill(fx,fy,WHITE);
      fl[0]=x+25;
      fl[1]=x+10+sz-50;
      fl[2]=x+55;
      fl[3]=x+10+sz-20;
      //rectangle(fl[0],fl[1],fl[2],fl[3]);
      nextwindow(fl,0,0,0,0);
      nextwindow(fl,80,0,80,0);
      nextwindow(fl,190,0,190,0);
      nextwindow(fl,255,0,255,0);
   }
}
void lift(int x,int pos,int ln)
{
  int l=x-10,t=pos,r=x+10,b=t+30,m=(l+r)/2;

  setfillstyle(SOLID_FILL,lcol);
  setcolor(BLUE);
  rectangle(l,t,r,b);
  floodfill(l+5,t+5,BLUE);
  setcolor(WHITE);
  line(m,ln,m,pos);

}
void Message (int x)
{
    setcolor(RED);
    outtextxy(x,30,"Press Q to quit");
    setcolor(BLUE);
    outtextxy(x,50,"Press 1-6 to Run a Lift");
    setcolor(WHITE);
}
void drawCL(int x,int y)
{
    setfillstyle(SOLID_FILL,clcol);
   rectangle(x+10,y,x+150,y+190);
   floodfill(x+10+5,y+5,WHITE);
   int a[2]={x+50,y+35};
   nxtcircle(a,0,0);
   outtextxy(a[0]-5,a[1]-9,"5");
   nxtcircle(a,60,0);
   outtextxy(a[0]-5+60,a[1]-9,"6");
   nxtcircle(a,0,60);
   outtextxy(a[0]-5,a[1]-9+60,"3");
   nxtcircle(a,60,60);
   outtextxy(a[0]-5+60,a[1]-9+60,"4");
   nxtcircle(a,0,2*60);
   outtextxy(a[0]-5,a[1]-9+2*60,"1");
   nxtcircle(a,60,2*60);
   outtextxy(a[0]-5+60,a[1]-9+2*60,"2");
   outtextxy(x+15,y+190+10,"Choose Lift: ");
   outtextxy(x+15,y+190+30,"Current Lift:");
}
void nextwindow (int a[],int l,int t,int r,int b)
{
    setcolor(BROWN);
    setfillstyle(7,wcol);
    rectangle(a[0]+l,a[1]+t,a[2]+r,a[3]+b);
    floodfill(a[0]+l+5,a[1]+t+5,BROWN);
    setcolor(WHITE);
}
void nxtcircle(int a[2],int tx,int ty)
{
    setcolor(GREEN);
    setfillstyle(9,nxcol);
    circle(a[0]+tx,a[1]+ty,20);
    floodfill(a[0]+tx,a[1]+ty,GREEN);
    setcolor(WHITE);
}


