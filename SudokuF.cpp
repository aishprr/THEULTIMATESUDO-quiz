#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<graph.cpp>
#include<stdlib.h>
#include<bios.h>
#include<string.h>
int d=9,e =2;
int che[9][9];
int cx,cy,q;
void quest1(int, int, int);
void quest2(int, int, int);
void quest3(int, int, int);
void quest4(int, int, int);
void generate(int a[9][9], int t);
class mouse									
{
		REGS regs;
		int no_buttons;
	public:
		void show_mouse();
		void get_status();
		void hide_mouse();
		mouse()
		{
			regs.x.ax=0;
			int86(0x33,&regs,&regs);
			if(regs.x.ax==0xfff)no_buttons=regs.x.bx;
			//cout<<"Error initializing mouse";
		}
}ms;

		void mouse::show_mouse()
		{
			regs.x.ax=0x01;
			int86(0x33,&regs,&regs);
		}
		void mouse::hide_mouse()
		{
			regs.x.ax=0x02;
			int86(0x33,&regs,&regs);
		}
		void mouse::get_status()
		{
			regs.x.ax=0x03;
			int86(0x33,&regs,&regs);
			while(q!=1)
			{

				regs.x.ax=0x03;
				int86(0x33,&regs,&regs);

				q=regs.x.bx;
				cx=regs.x.cx;
				cy=regs.x.dx;
			}
			q=0;

		}

class stopw
{
	public:
	int hr,min,sec;
	int ts;

	 stopw()
	{
		hr=min=sec=0;

	}
	void calcts()
	{
		ts= hr*3600+ min*60 + sec;
	}

}tmi,dur;               							//
void timedur(int s)
{
	dur.sec= s%60;
	dur.min= s/60;
	dur.hr= dur.min/60;
	dur.min= dur.min%60;
}
struct time t;
void timer(stopw tmf )
{
	struct time f;
	gettime(&f);
	tmf.hr = int(f.ti_hour);
	tmf.min=int(f.ti_min);
	tmf.sec=int(f.ti_sec);
	tmi.calcts(); tmf.calcts();
	int	seconds = tmf.ts-tmi.ts;
	timedur(seconds);
	setcolor(RED);
	setfillstyle(1,0);
	bar(250,370,360,390);
	char s[10]; char p[2]; p[0]=':'; p[1]='\0';
	itoa(dur.hr,s,10);
	outtextxy( 260,380, s);
	outtextxy( 280,380, p);
	itoa(dur.min,s,10);
	outtextxy( 300,380, s);
	outtextxy( 320,380, p);
	itoa(dur.sec,s,10);
	outtextxy( 340,380, s);
	setcolor(BLUE);

}

void extradeco()                  		
{
	setcolor(14);
	setfillstyle(1,12);
	rectangle(0,0,800,2500);
	floodfill(1,1,14);
	extrafittings();
	rectangles();
	int j,k;
	j=520;k=150;
	doll(j,k);
	otherdoll();

	rectangle(480,380,555,415);          	
	setfillstyle(5, 3);
	setcolor(RED);
	outtextxy(490,390,"I'M DONE!");
	outtextxy(490,400,"CHECK!");

	rectangle(480,420,555,455);         	
	setfillstyle(5, 3);
	setcolor(RED);
	outtextxy(490,430,"END GAME");


}
void userinput();
void questfile()
{
	ofstream f( "qfile.dat", ios::binary|ios::out);
	for( int i=0; i<=8; i++)
	{
		for( int j=0; j<=8; j++)
		{
			f.write((char*)&che[i][j],2);
		}
	}
}
void solnfile( int a[9][9])
{
	ofstream f( "solfile.dat", ios::binary|ios::out);
	for( int i=0; i<=8; i++)
	{
		for( int j=0; j<=8; j++)
		{
			f.write((char*)&a[i][j],2);
		}
	}
}
void question( int lno)
{


	randomize();
	int p= random(9) + 1;
	int q=random(9)+1;
	int qno = random(4)+1;
	switch(qno)
	{
	       case 1: quest1(p,q,lno);break;
	       case 2: quest2(p,q,lno);break;
	       case 3: quest3(p,q,lno);break;
	       case 4: quest4(p,q,lno);break;
	}

}
void selectsudo( int var, int &r, int &s)
{

	switch(var)
	{
		case 1: r=0; s=1; break;
		case 2: r=0; s=2; break;
		case 3: r=1; s=2; break;
		case 4: r=3; s=4; break;
		case 5: r=3; s=5; break;
		case 6: r=4; s=5; break;
		case 7: r=6; s=7; break;
		case 8: r=6; s=8; break;
		case 9: r=7; s=8; break;

	}
}

void swaprow( int a[9][9],int r,int s)
{
	for( int i=0; i<=8; i++)
		{
			int sw= a[r][i];
			a[r][i]= a[s][i];
			a[s][i]=sw;

		}
}
void swapcol( int a[9][9],int  r,int s)
{
	for( int j=0; j<=8; j++)
		{
			int sw= a[j][r];
			a[j][r]= a[j][s];
			a[j][s]=sw;
		}
}

void quest1( int p, int q, int lno)
{


	int a[9][9]= {{2,7,3,6,5,8,9,1,4},{8,9,4,7,3,1,6,2,5},{1,6,5,2,9,4,3,8,7},
		      {7,5,2,8,6,9,1,4,3},{6,3,9,1,4,2,5,7,8},{4,1,8,5,7,3,2,9,6},
		      {5,4,7,9,1,6,8,3,2},{3,2,1,4,8,5,7,6,9},{9,8,6,3,2,7,4,5,1}};
	int r,s;

	selectsudo(p,r,s);
	swaprow(a,r,s);
	selectsudo(q,r,s);
	swapcol(a,r,s);
	generate(a, lno);

}


void quest2( int p, int q, int lno)
{


	int a[9][9]= {{7,3,8,6,2,1,4,5,9},{9,2,4,5,3,8,7,1,6},{6,1,5,9,4,7,3,2,8},
		      {2,8,3,4,1,6,5,9,7},{1,5,6,8,7,9,2,3,4},{4,9,7,3,5,2,6,8,1},
		      {8,7,1,2,6,3,9,4,5},{5,6,2,1,9,4,8,7,3},{3,4,9,7,8,5,1,6,2}};
	int r,s;
	selectsudo(p,r,s);
	swaprow(a,r,s);
	selectsudo(q,r,s);
	swapcol(a,r,s);
	generate(a, lno);


}

void quest3( int p, int q,int lno)
{


	int a[9][9]= {{8,4,7,3,9,5,2,1,6},{3,9,5,6,1,2,4,7,8},{6,1,2,7,8,4,9,5,3},
		      {7,2,6,1,5,8,3,4,9},{4,8,3,9,7,6,1,2,5},{1,5,9,4,2,3,6,8,7},
		      {9,6,8,5,4,1,7,3,2},{2,3,4,8,6,7,5,9,1},{5,7,1,2,3,9,8,6,4}};
	int r,s;


	selectsudo(p,r,s);
	swaprow(a,r,s);
	selectsudo(q,r,s);
	swapcol(a,r,s);
	generate(a, lno);


}


void quest4( int p, int q,int lno)
{


	int a[9][9]= {{2,9,1,3,4,7,8,6,5},{8,6,7,1,5,9,2,3,4},{4,3,5,2,6,8,7,1,9},
		      {7,8,2,6,1,5,4,9,3},{6,1,4,7,9,3,5,8,2},{3,5,9,4,8,2,1,7,6},
		      {1,2,3,9,7,4,6,5,8},{5,4,6,8,3,1,9,2,7},{9,7,8,5,2,6,3,4,1}};
	int r,s;


	selectsudo(p,r,s);
	swaprow(a,r,s);
	selectsudo(q,r,s);
	swapcol(a,r,s);
	generate(a, lno);

}
int checkrow( int i, int j,int val)
{
	ifstream f("qfile.dat",ios::binary| ios::in);
	i++; j++;
	int no;
	f.seekg( ( i-1)*18, ios::beg);
	for( int cnt=1; cnt<=9; cnt++)
	{
		if( cnt==j)
		{
			f.read ((char*)&no, 2);
		}
		else
		{
			f.read((char*)&no, 2);
			if( no==val)
			{
				return 0;
			}
		}
	}
	
	return 1;
}
int checkcol( int i, int j,int val)
{
	ifstream f("qfile.dat",ios::binary| ios::in);
	i++; j++;
	int no;
	f.seekg( ( j-1)*2, ios::beg);
	for( int cnt=1; cnt<=9; cnt++)
	{
		if( cnt==i)
		{
			f.read ((char*)&no, 2);
			
		}
		else
		{
			f.read((char*)&no, 2);
			if( no==val)
			{
				return 0;
			}
			
		}
		f.seekg( 16, ios::cur);
	}
	return 1;
}
int checkbox( int i, int j,int val)
{
	ifstream f("qfile.dat",ios::binary|ios::in);
	i++; j++;
	int no;
	
	f.seekg( (( j-1)/3)*6 + ((i-1)/3 )* 54, ios::beg);
	for( int cnt=1; cnt<=9; cnt++)
	{
		int c=f.tellg();
		if( c==(i-1)*18 + (j-1)*2)
		{
			f.read ((char*)&no, 2);
			
		}
		else
		{
			f.read((char*)&no, 2);
			if( no==val)
			{
				return 0;		 
			}
			
		}
		if( cnt%3==0) {f.seekg( 6*2, ios::cur); }
	}
	return 1;
}
int checkans()
{
	ifstream f( "qfile.dat", ios::binary|ios::in);
	ifstream g( "solfile.dat",ios::binary| ios::in);
	int no1, no2;
	for( int i=1; i<=81; i++)
	{
		f.read((char*)&no1,2);
		g.read((char*)&no2,2);
		if( no1!=no2)
		return 0;
	}
	return 1;
}

void output(int a[9][9])
{
	for( int i=0; i<9; i++)
	{
		for( int j=0; j<9; j++)
		{
			char ch= a[i][j]+48;
			char str[2]; str[0]=ch; str[1]='\0';
			outtextxy( (j-1)*30 + 190, (i-1)*30 +105, str);
		}
	}
}

void end ( int a[9][9], int q)
{
	     
		void entrypage();
		initgraph(  &d, &e ,"C:\\tc\\bgi");
		extradeco();
		setcolor(12);                       
		rectangle(480,380,555,415);
		setfillstyle(5, 3);
		outtextxy(490,390,"I'M DONE!");
		outtextxy(490,400,"CHECK!");

		rectangle(480,420,555,455);
		setfillstyle(5, 3);
		outtextxy(490,430,"END GAME");


		setcolor(BLUE);
		if( q==1)
		{
			outtextxy(120,20,"Here's the solution to this cracker of a sudoku!");
			output(a);
		}



		rectangle(170,400,280,435);
		setfillstyle(5, 3);
		setcolor(RED);
		outtextxy(180,410,"PLAY AGAIN!");

		rectangle(300,400,410,435);
		setfillstyle(5, 3);
		setcolor(RED);
		outtextxy(310,410,"LEAVE GAME");


		ms.show_mouse();
		ms.get_status();
		ms.hide_mouse();
		if( cx>=170 && cx<=280 && cy>=400 && cy<=435)
		{
			entrypage();
		}
		else if ( cx>=300 && cx<=410 && cy>=400 && cy<=435)
		{

			exit(0);
		}
}
void userinput(int a[9][9])
{

		void entrypage();
		setcolor(BLUE);
		int p=0;
		ms.show_mouse();
		ms.get_status();
		stopw tmf;
  	 	gettime(&t);
   		tmi.hr= int(t.ti_hour);
   		tmi.min=int(t.ti_min);
   		tmi.sec= int(t.ti_sec);
		while( !( cx>=480 && cx<=555 && cy>=420 && cy<=455))
		{

			timer( tmf);
			if( cx>=480 && cx<=555 && cy>=380 && cy<=415)
			{
				if(checkans()==0)
				{
					setcolor(BLUE);
					outtextxy(150,5,"Sorry, It's incorrect!");
					delay(2000);
					closegraph();
					end(a,1);
				}
				else
				{
					setcolor(BLUE);
					outtextxy(150,5,"Bravo! It's Correct!");
					delay(2000);
					closegraph();
					end(a,0);
				}
			}
			timer(tmf);
			for( int i=0; i<=8; i++)
			{
				if( cy>= ( i-1)*30 + 65 && cy<= (i-1)*30 + 95)
				break;
			}
			for ( int j=0; j<=8; j++)
			{
				if( cx>=( j-1)*30 + 150 && cx<=(j-1)*30 + 180)
				break;
			}
			i--; j--;
			ms.hide_mouse();
			outtextxy(150,405, "Enter value for selected position");
			timer(tmf);

			int val; char ch;int w=0;
			ch=getch();
			val= ch-48;
			char str[2]; str[0]=ch; str[1]='\0';
			setfillstyle(1,12);
			floodfill( (j-1)*30 + 190, (i-1)*30 + 105,RED);
			setcolor( BLUE);
			outtextxy( (j-1)*30 + 190, (i-1)*30 + 105, str);                  
			if( checkrow(i,j,val)==0)
			{
					timer(tmf);
					setfillstyle(1,12);
					floodfill( (j-1)*30 + 190, (i-1)*30 + 105,RED);
					setcolor( BLUE);
					rectangle( 150,20,500,50);
					outtextxy(160,25, "Same numbers in the same row NOT ALLOWED!");
					delay(2000);
					setfillstyle( 1,12);
					floodfill( 160,30,BLUE);
					setcolor(12);
					rectangle( 150,20,500,50);
					outtextxy(160,25, "Same numbers in the same row NOT ALLOWED!");

			}
			if ( checkcol( i, j, val)==0)
			{
					timer(tmf);
					delay(500);
					timer(tmf);
					setfillstyle(1,12);
					floodfill( (j-1)*30 + 190, (i-1)*30 + 105,RED);
					setcolor( BLUE);
					rectangle( 150,20,520,50);
					outtextxy(160,25, "Same numbers in the same column NOT ALLOWED!");
					delay(2000);
					setfillstyle( 1,12);
					floodfill( 160,30,BLUE);
					setcolor(12);
					rectangle( 150,20,520,50);
					outtextxy(160,25, "Same numbers in the same column NOT ALLOWED!");
			}
			if ( checkbox( i, j, val)==0)
			{
					timer(tmf);
					delay(500);
					timer(tmf);
					setfillstyle(1,12);
					floodfill( (j-1)*30 + 190, (i-1)*30 + 105,RED);
					setcolor( BLUE);
					rectangle( 150,20,500,50);
					outtextxy(160,25, "Same numbers in the same box NOT ALLOWED!");
					delay(2000);
					setfillstyle( 1,12);
					floodfill( 160,30,BLUE);
					setcolor(12);
					rectangle( 150,20,500,50);
					outtextxy(160,25, "Same numbers in the same box NOT ALLOWED!");
			}
			if
			( checkrow(i,j,val)==1 && checkcol(i,j,val)==1 && checkbox( i, j,val)==1)
			{
				che[i][j]=val;
				questfile();
			}
			p++;
			if( p!=0)
			{
				mouse mp;
				mp.show_mouse();
				mp.get_status();
				mp.hide_mouse();
			}

		}
		closegraph();
		end(a,1);
}
void entrypage()
{
		initgraph(  &d, &e ,"C:\\tc\\bgi");
		int j=300,k=320,p[8];
		setcolor(2);
		setfillstyle(1,2);
		rectangle(0,0,800,2500);
		floodfill(1,1,14);//filling indirect bg

		{
			setcolor(WHITE);
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
			fillellipse(j+75,k,30,30); //circles
		}
			
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
		ms.show_mouse();
		ms.get_status();
		ms.hide_mouse();


		 if(cx>a&&cx<a+200&&cy>b&&cy<b+50)
		{
			b=b+500;
			int m=175,n=a,p=0;
			for(;m<=235;m=m+30,p++)
			{
				setcolor(4);
				setfillstyle(1,14);
				rectangle(n,m,n+200,m+30);
				floodfill(n+10,m+10,4);
				setcolor(4);
				if( p==0) outtextxy(n+65,m+20,"LEVEL 1");
				else if (p==1)outtextxy(n+65,m+20,"LEVEL 2");
				else if (p==2)outtextxy(n+65,m+20,"LEVEL 3");
			}
			delay(1000);
			ms.show_mouse();
			ms.get_status();
			ms.hide_mouse();

			if(cx>200 && cx<400 && cy>175 && cy<205)
			{
				clrscr();
				question(1);
			}
			if(cx>200 && cx<400 && cy>205 && cy<235)
			{
				clrscr();
				question(2);
			}
			if(cx>200 && cx<400 && cy>235 && cy<265)
			{
				clrscr();
				question(3);
			}


		 }

	       else
		{
			setcolor(1);
			b=b+100;
			rectangle(a,b,a+200,b+50);
			floodfill(a+10,b+10,1);
			setcolor(WHITE);
			outtextxy(a+65,b+20,"LEAVE GAME") ;
			delay(2000);
			exit(0);

		}


}

void generate(int a[9][9], int t)
{
	int i;
	for( int w=0; w<=8; w++)
	{
		for( int x=0; x<=8; x++)
		{
			che[w][x]=0;
		}
	}
	extradeco();
	randomize();
	setcolor(RED);
	for(int k=0;k<3;k++)
	{

		for(int j=0;j<9;j++)
		{

			i= 3*k + random(3);

			char str[2];
			str[0]=a[i][j]+48; str[1]='\0';
			if(t==1)
			{
				che[i][j]=a[i][j];
				outtextxy((j-1)*30+190, (i-1)*30+105,str);
			}
			else if(t==2)
			{
				if(j!=4)
				{
					che[i][j]=a[i][j];
					outtextxy((j-1)*30+190, (i-1)*30+105,str);
				}

			}

			else if(t==3)
			{
				if((j!=4)&&(j!=5))
				{
					che[i][j]=a[i][j];
					outtextxy((j-1)*30+190, (i-1)*30+105,str);
				}
			}

		}


	}

	questfile(); solnfile(a);
	userinput(a);

}

void main()
{

	clrscr();
	initgraph(  &d, &e ,"C:\\tc\\bgi");
	entrypage();
	getch();
}



