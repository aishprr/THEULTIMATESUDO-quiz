#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
int a=9,b=2;
struct linesettingstype l;
void windowset()
{
	window(20,5,40,30);

}
setline()
{
	getlinesettings(&l);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);

}

void rectangles()
{

	setcolor(4);
	rectangle(150,65,420,335);
	int a,b,c,d;
	a=150;
	b=65;
	c=180;
	d=95;
	while(c<=435)
	{       d=95;
		while(d<=335)
		{
			rectangle(a,b,c,d);
			d=d+30;
		}
		c=c+30;
	}

	a=150;
	b=65;
	c=240;d=155;
	setline();
	rectangle(a,b,c,d);
	while(c<=435)
	{       d=155;
		while(d<=335)
		{
			rectangle(a,b,c,d);
			d=d+90;
		}
		c=c+90;
	}
}
void bkcolor()
{

	//int p=0;
	//while(p<=20)
	{
		delay(500);
		setbkcolor(2);
	       //	p++;
	}

}
void extrafittings()
{        int j=280,k=200,p[8];
		setcolor(14);
		setfillstyle(1,12);
		rectangle(0,0,800,2500);
		floodfill(1,1,14);//filling indirect bg
	/*	setcolor(WHITE);
		setfillstyle(1,WHITE);
		fillellipse(j,k,150,150);  // yin white part
		setcolor(BLACK);
		setfillstyle(1,0);
		sector(j,k,0,180,150,150);// yang black part
		setfillstyle(1,WHITE);
		sector(j-75,k,0,180,75,75);//semi circle
		setfillstyle(1,0);
		sector(j+75,k,180,360,75,75); //semi circle
		fillellipse(j-75,k,30,30);  //circles
		setfillstyle(1,WHITE);
		fillellipse(j+75,k,30,30); //circles */
}
void doll(int j, int k)
{

	for(int i=0,l=0;i<=360;i=i+30,l++)
	{       int p=i+30;
		setcolor(8);
		if(l%2==0)setfillstyle(6,10);
		else setfillstyle(1,13);
		sector(j+40,k-40,i,p,60,60);
	}//umbErella
	{
		setcolor(0);
		setfillstyle(1,0);
		sector(j,k,0,180,35,35);
	} //fringe
	{
		setfillstyle(1,0);
		rectangle(j-35,k,j+35,k+45);// hair
		floodfill(530,160,0);
	}
	{
		setcolor(15);
		setfillstyle(1,15);
		sector(j,k,180,360,25,25);//face
	}
	{
		setcolor(4);
		setfillstyle(1,4);
		sector(j,k+15,180,360,5,5);//mouth
	}
	{
		setcolor(0);
		ellipse(j-12,k+5,0,180,3,3);
		ellipse(j+12,k+5,0,180,3,3);//eyes
	}
	{
		setcolor(13);
		setfillstyle(1,13);
		fillellipse(j-13,k+12,3,3);
		fillellipse(j+13,k+12,3,3);//cheeks
	}
	{	setcolor(1);
		ellipse(j,k+100,0,180,30,k-76);//upper body
		rectangle(j-30,k+100,j+30,k+200);//lowerbody
		setfillstyle(1,9);
		floodfill(500,k+110,1);
		floodfill(500,k+90,1);
		setfillstyle(9,5);
		setcolor(12);
	}
	{
		rectangle(j-30,k+80,j+30,k+120);//stomach thing
		floodfill(j,k+100,12);
	}

	{
		setcolor(4);
		line(j-30,k+80,j+12,k+33);
		line(j-28,k+80,j+14,k+34);
		line(j-27,k+80,j+14,k+35);//sash thing
		line(j-10,k+33,j+3,k+50);//other sash thing
		setcolor(1);
		line(j+10,k+120,j+10,k+200);//flap thing
	}
	{

		setfillstyle(1,1); //left arm
		rectangle(j-40,k+60,j-8,k+110);
		floodfill(j-30,k+80,1);
		ellipse(j,k+60,90,180,40,35);
		floodfill(j-30,k+55,1);//left arm
		ellipse(j,k+100,0,180,30,k-76);
		rectangle(j+8,k+60,j+40,k+110);//right arm
		floodfill(j+13,k+65,1);
		ellipse(j,k+60,0,90,40,35);
		floodfill(j+25,k+45,1);//right arm
	}
	{
		setcolor(12);
		fillellipse(j-23,k-10,2,2);
		fillellipse(j-18,k-10,2,2);
		fillellipse(j-18,k-7,2,2); //flower
		setcolor(14);
		fillellipse(j-20,k-8,1,1);
	}
	{
		setcolor(8);
		line(j,k+60,j+40,k-40);
		setcolor(15);
		setfillstyle(1,15);
		fillellipse(j,k+60,4,4);//hand
	}
}
void otherdoll()
{
	int j=70,k=150;
	{
		setcolor(0);
		setfillstyle(1,0);
		sector(j,k,0,180,30,30);
	} //fringe
	{
		setcolor(8);
		line(j,k-29,j+26,k-40);
		setcolor(0);
		ellipse(j+8,k-35,0,360,6,6);
		floodfill(j+8,k-35,0);//konda

	}
	{
		setcolor(0);
		setfillstyle(1,0);
		sector(j,k,180,360,35,20);   //bob
	}
	{
		setcolor(15);
		setfillstyle(1,15);
		sector(j,k,180,360,22,22);//face
	}
	{
		setcolor(4);
		setfillstyle(1,4);
		ellipse(j,k+15,180,0,4,3);//mouth
	}
	{
		setcolor(0);
		ellipse(j-12,k+5,0,180,3,3);
		ellipse(j+12,k+5,0,180,3,3);//eyes
	}
	{
		setcolor(13);
		setfillstyle(1,13);
		fillellipse(j-13,k+12,3,3);
		fillellipse(j+13,k+12,3,3);//cheeks
	}
	{	setcolor(4);
		ellipse(j,k+100,0,180,30,k-76);//upper body
		setcolor(4);
		rectangle(j-30,k+100,j+30,k+200);//lowerbody
		setfillstyle(1,2);
		floodfill(j,k+110,4);
		setcolor(2);
		line(j-30,k+98,j+30,k+98);
		floodfill(j,k+90,4);
	}
	{       setcolor(4);
		rectangle(j-30,k+80,j+30,k+120);//stomach thing
		setfillstyle(8,4);
		floodfill(j,k+96,4);
		floodfill(j,k+118,4);
		line(j+9,k+120,j-30,k+160);
		line(j+9,k+120,j+30,k+165);
		setfillstyle(1,4);
		floodfill(j-5,k+122,4);
		setfillstyle(1,4);
		floodfill(j+12,k+122,4);
	}
	{
		setcolor(4);
		line(j-30,k+80,j+12,k+33);
		line(j-28,k+80,j+14,k+34);
		line(j-27,k+80,j+14,k+35);//sash thing
		line(j-10,k+33,j+3,k+50);//other sash thing
		setcolor(1);
	}

	{	setcolor(4);
		setfillstyle(1,4); //left arm
		rectangle(j-40,k+60,j-8,k+110);
		int a=j-40,b=k+60,c=j-8,d=k+110;
		for(;d>=b;d--)
		{
			line(a,d,c,d);
		}
		floodfill(j-30,k+80,4);
		ellipse(j,k+60,90,180,40,35);
		floodfill(j-30,k+55,4);//left arm
		ellipse(j,k+100,0,180,30,k-76);
	}
	{       setcolor(4);
		ellipse(j,k+120,0,90,j-25,k-51);
		line(j+20,k+120,j+45,k+120);
		floodfill(j+40,k+117,4);
		setcolor(15);
		setfillstyle(1,15);
		fillellipse(j+40,k+125,4,4);
	}
	{
		setcolor(0);setfillstyle(9,14);
		for(int i=0;i<=120;i=i+20)
		{
			sector(j,k+60,i,i+20,40,40); //fan
		}
	}
	{

		setcolor(15);
		setfillstyle(1,15);
		fillellipse(j,k+60,4,4);//hand
	}
		{
		setcolor(12);
		fillellipse(j-23,k-10,2,2);
		fillellipse(j-18,k-10,2,2);
		fillellipse(j-18,k-7,2,2); //flower
		setcolor(14);
		fillellipse(j-20,k-8,1,1);
	}
	{
		setcolor(4);
		fillellipse(j-13,k-10,2,2);
		fillellipse(j-8,k-10,2,2);
		fillellipse(j-8,k-7,2,2); //flower
		setcolor(14);
		fillellipse(j-10,k-8,1,1);
	}
		{
		setcolor(13);
		fillellipse(j-23,k-16,2,2);
		fillellipse(j-18,k-16,2,2);
		fillellipse(j-18,k-13,2,2); //flower
		setcolor(14);
		fillellipse(j-20,k-14,1,1);
	}
}
/*
void entrypage()
{
	 int j=280,k=200,p[8];
		setcolor(2);

		setfillstyle(1,2);
		rectangle(0,0,800,2500);
		floodfill(1,1,14);//filling indirect bg
		setcolor(4);
		outtextxy(170,50,"GET READY TO SQUEEZE YOUR BRAIN!");
		outtextxy(200,80,"THE ULTIMATE SUDOKU IS HERE!!");
		setcolor(1);
		setfillstyle(1,1);
		int a=200,b=100;
		rectangle(a,b,a+200,b+50);
		floodfill(a+10,b+10,1);
		setcolor(WHITE);
		outtextxy(a+65,b+15,"ENTER GAME");
		outtextxy(a+10,b+26,"(click outside this box");
		outtextxy(a+20,b+40,"if you don't dare to)");
		

		 if(cx>a&&cx<a+200&&cy>b&&cy<b+50)
		{ b=b+500;
		 int m=175,n=a,p=0;
		 for(;m<=235;m=m+30,p++)
		{ setcolor(4);
		 setfillstyle(1,14);
		 rectangle(n,m,n+200,m+30);
		 floodfill(n+10,m+10,4);
		 setcolor(4);
		 if (p==0)outtextxy(n+65,m+20,"LEVEL 1");
		 else if (p==1)outtextxy(n+65,m+20,"LEVEL 2");
		 else if (p==2)outtextxy(n+65,m+20,"LEVEL 3");
		 }
		 }

	       else
	       {	setcolor(1);
		b=b+100;
		rectangle(a,b,a+200,b+50);
		floodfill(a+10,b+10,1);
		setcolor(WHITE);
		outtextxy(a+65,b+20,"LEAVE GAME") ;    }
		get coord again and put clrscr()

}
void main()
{
	clrscr();

	initgraph(&a,&b,"C:\\TC\BIN\BGI");
	entrypage();
	getch();
	extrafittings();
       //	bkcolor();
	//windowset();

	rectangles();
	int j,k;
	j=520;k=150;
	doll(j,k);
	otherdoll();
	getch();

}*/
