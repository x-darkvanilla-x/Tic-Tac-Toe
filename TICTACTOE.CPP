#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>

int gdriver = DETECT,gmode;

char arr[] = {'0','1','2','3','4','5','6','7','8','9'};
char ch;
int n,player=1,key=1;

char a= '1', b, temp;
int set= 1;

void loading();
void multiplay();

void wincase()
{
	setfillstyle(1,11);

	int x = 1;

	for(x = 1;x<=300;x++)
	{
		if(arr[1] == arr[2] && arr[1] == arr[3])
			bar(130,100,180+x,103);
		else if(arr[4] == arr[5] && arr[5] == arr[6])
			bar(130,200,180+x,203);
		else if(arr[7] == arr[8] && arr[8] == arr[9])
			bar(130,300,180+x,303);
		else if(arr[1] == arr[4] && arr[7] == arr[4])
			bar(197,30,200,80+x);
		else if(arr[2] == arr[5] && arr[8] == arr[5])
			bar(297,30,300,80+x);
		else if(arr[3] == arr[6] && arr[3] == arr[9])
			bar(397,30,400,80+x);
		else if(arr[1] == arr[5] && arr[5] == arr[9])
			bar(147+x,50+x,153+x,50+x);
		else if(arr[3] == arr[5] && arr[5] == arr[7])
			bar(453-x,50+x,447-x,50+x);
		delay(3);
	}
}

void refresh()
{
		arr[0] = '0';
		arr[1] = '1';
		arr[2] = '2';
		arr[3] = '3';
		arr[4] = '4';
		arr[5] = '5';
		arr[6] = '6';
		arr[7] = '7';
		arr[8] = '8';
		arr[9] = '9';
}

void board()
{
	if(set%2 == 1)
		setbkcolor(5);
	else if(set%2 == 0)
		setbkcolor(0);

	settextstyle(0,0,1);
	outtextxy(240,140,"1           2            3");
	outtextxy(240,240,"4           5            6");
	outtextxy(240,340,"7           8            9");

	settextstyle(0,0,8);

	setcolor(15);
	line(250,50,250,350);
	line(350,50,350,350);
	line(150,150,450,150);
	line(150,250,450,250);

}

void singleplay()
{
	cleardevice();
	refresh();

	board();

	do
	{
		if((arr[1] == 'O' && arr[2] == 'O' && arr[3] == 'O') || (arr[4] == 'O' && arr[5] == 'O' && arr[6] == 'O') || (arr[7] == 'O' && arr[8] == 'O' && arr[9] == 'O') || (arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O') || (arr[5] == 'O' && arr[2] == 'O' && arr[8] == 'O') || (arr[9] == 'O' && arr[6] == 'O' && arr[3] == 'O') || (arr[1] == 'O' && arr[5] == 'O' && arr[9] == 'O') || (arr[3] == 'O' && arr[5] == 'O' && arr[7] == 'O'))
		{
			outtextxy(70,380,"You Lose");
			wincase();
			sleep(2);
			loading();
		}


		again3:
		ch = getch();

		setcolor(10);
		if(ch=='1' && arr[1] == '1')
		{
			outtextxy(170,70,"X");
			arr[1] = 'X';
		}
		else if(ch=='2' && arr[2] == '2')
		{
			outtextxy(270,70,"X");
			arr[2] = 'X';
		}
		else if(ch=='3' && arr[3] == '3')
		{
			outtextxy(370,70,"X");
			arr[3] = 'X';
		}
		else if(ch=='4' && arr[4] == '4')
		{
			outtextxy(170,170,"X");
			arr[4] = 'X';
		}
		else if(ch=='5' && arr[5] == '5')
		{
			outtextxy(270,170,"X");
			arr[5] = 'X';
		}
		else if(ch=='6' && arr[6] == '6')
		{
			outtextxy(370,170,"X");
			arr[6] = 'X';
		}
		else if(ch=='7' && arr[7] == '7')
		{
			outtextxy(170,270,"X");
			arr[7] = 'X';
		}
		else if(ch=='8' && arr[8] == '8')
		{
			outtextxy(270,270,"X");
			arr[8] = 'X';
		}
		else if(ch=='9' && arr[9] == '9')
		{
			outtextxy(370,270,"X");
			arr[9] = 'X';
		}
		else if(ch == 'r' || ch == 'R')
			singleplay();
		else if(ch == 27)
			loading();
		else
			goto again3;

		delay(200);
		setcolor(4);

		if((arr[1] == 'X' && arr[2] == 'X' && arr[3] == 'X') || (arr[4] == 'X' && arr[5] == 'X' && arr[6] == 'X') || (arr[7] == 'X' && arr[8] == 'X' && arr[9] == 'X') || (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X') || (arr[5] == 'X' && arr[2] == 'X' && arr[8] == 'X') || (arr[9] == 'X' && arr[6] == 'X' && arr[3] == 'X') || (arr[1] == 'X' && arr[5] == 'X' && arr[9] == 'X') || (arr[3] == 'X' && arr[5] == 'X' && arr[7] == 'X'))
		{
			outtextxy(100,380,"You Win");
			wincase();
			sleep(2);
			loading();
		}
		else if(arr[1] != '1' && arr[2] != '2' &&  arr[3] != '3' &&  arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' &&  arr[8] != '8' && arr[9] != '9')
		{
			outtextxy(180,380,"Draw");
			sleep(2);
			loading();
		}
		else
		 if((arr[1] == 'O' && arr[2] == 'O' && arr[3] == '3') || (arr[6] == 'O' && arr[9] == 'O' && arr[3] == '3') || (arr[5] == 'O' && arr[7] == 'O' && arr[3] == '3'))
		{
			outtextxy(370,70,"O");
			arr[3] = 'O';
		}
		else if((arr[3] == 'O' && arr[2] == 'O' && arr[1] == '1') || (arr[4] == 'O' && arr[7] == 'O' && arr[1] == '1') || (arr[5] == 'O' && arr[9] == 'O' && arr[1] == '1'))
		{
			outtextxy(170,70,"O");
			arr[1] = 'O';
		}
		else if((arr[1] == 'O' && arr[3] == 'O' && arr[2] == '2') || (arr[5] == 'O' && arr[8] == 'O' && arr[2] == '2'))
		{
			outtextxy(270,70,"O");
			arr[2] = 'O';
		}
		else if((arr[4] == 'O' && arr[5] == 'O' && arr[6] == '6') || (arr[9] == 'O' && arr[3] == 'O' && arr[6] == '6'))
		{
			outtextxy(370,170,"O");
			arr[6] = 'O';
		}
		else if((arr[5] == 'O' && arr[6] == 'O' && arr[4] == '4') || (arr[1] == 'O' && arr[7] == 'O' && arr[4] == '4'))
		{
			outtextxy(170,170,"O");
			arr[4] = 'O';
		}
		else if((arr[4] == 'O' && arr[6] == 'O' && arr[5] == '5') || (arr[2] == 'O' && arr[8] == 'O' && arr[5] == '5') || (arr[1] == 'O' && arr[9] == 'O' && arr[5] == '5') || (arr[3] == 'O' && arr[7] == 'O' && arr[5] == '5'))
		{
			outtextxy(270,170,"O");
			arr[5] = 'O';
		}
		else if((arr[7] == 'O' && arr[8] == 'O' && arr[9] == '9') || (arr[3] == 'O' && arr[6] == 'O' && arr[9] == '9') || (arr[1] == 'O' && arr[5] == 'O' && arr[9] == '9'))
		{
			outtextxy(370,270,"O");
			arr[9] = 'O';
		}
		else if((arr[7] == 'O' && arr[9] == 'O' && arr[8] == '8') || (arr[2] == 'O' && arr[5] == 'O' && arr[8] == '8'))
		{
			outtextxy(270,270,"O");
			arr[8] = 'O';
		}
		else if((arr[9] == 'O' && arr[8] == 'O' && arr[7] == '7') || (arr[1] == 'O' && arr[4] == 'O' && arr[7] == '7') || (arr[3] == 'O' && arr[5] == 'O' && arr[7] == '7'))
		{
			outtextxy(170,270,"O");
			arr[7] = 'O';
		}
		else if((arr[1] == 'X' && arr[2] == 'X' && arr[3] == '3') || (arr[6] == 'X' && arr[9] == 'X' && arr[3] == '3') || (arr[5] == 'X' && arr[7] == 'X' && arr[3] == '3'))
		{
			outtextxy(370,70,"O");
			arr[3] = 'O';
		}
		else if((arr[3] == 'X' && arr[2] == 'X' && arr[1] == '1') || (arr[4] == 'X' && arr[7] == 'X' && arr[1] == '1') || (arr[5] == 'X' && arr[9] == 'X' && arr[1] == '1'))
		{
			outtextxy(170,70,"O");
			arr[1] = 'O';
		}
		else if((arr[1] == 'X' && arr[3] == 'X' && arr[2] == '2') || (arr[5] == 'X' && arr[8] == 'X' && arr[2] == '2'))
		{
			outtextxy(270,70,"O");
			arr[2] = 'O';
		}
		else if((arr[4] == 'X' && arr[5] == 'X' && arr[6] == '6') || (arr[9] == 'X' && arr[3] == 'X' && arr[6] == '6'))
		{
			outtextxy(370,170,"O");
			arr[6] = 'O';
		}
		else if((arr[5] == 'X' && arr[6] == 'X' && arr[4] == '4') || (arr[1] == 'X' && arr[7] == 'X' && arr[4] == '4'))
		{
			outtextxy(170,170,"O");
			arr[4] = 'O';
		}
		else if((arr[4] == 'X' && arr[6] == 'X' && arr[5] == '5') || (arr[2] == 'X' && arr[8] == 'X' && arr[5] == '5') || (arr[1] == 'X' && arr[9] == 'X' && arr[5] == '5') || (arr[3] == 'X' && arr[7] == 'X' && arr[5] == '5'))
		{
			outtextxy(270,170,"O");
			arr[5] = 'O';
		}
		else if((arr[7] == 'X' && arr[8] == 'X' && arr[9] == '9') || (arr[3] == 'X' && arr[6] == 'X' && arr[9] == '9') || (arr[1] == 'X' && arr[5] == 'X' && arr[9] == '9'))
		{
			outtextxy(370,270,"O");
			arr[9] = 'O';
		}
		else if((arr[7] == 'X' && arr[9] == 'X' && arr[8] == '8') || (arr[2] == 'X' && arr[5] == 'X' && arr[8] == '8'))
		{
			outtextxy(270,270,"O");
			arr[8] = 'O';
		}
		else if((arr[9] == 'X' && arr[8] == 'X' && arr[7] == '7') || (arr[1] == 'X' && arr[4] == 'X' && arr[7] == '7') || (arr[3] == 'X' && arr[5] == 'X' && arr[7] == '7'))
		{
			outtextxy(170,270,"O");
			arr[7] = 'O';
		}
		else
		{
			again5:

			srand(time(0));
			n = (rand()%(9-1+1)) + 1;

			if(arr[n] == '1' || arr[n] == '2' || arr[n] == '3' || arr[n] == '4' || arr[n] == '5' || arr[n] == '6' || arr[n] == '7' || arr[n] == '8' || arr[n] == '9')
			{
				arr[n] = 'O';

				if(n == 1)
					outtextxy(170,70,"O");
				else if(n == 2)
					outtextxy(270,70,"O");
				else if(n == 3)
					outtextxy(370,70,"O");
				else if(n == 4)
					outtextxy(170,170,"O");
				else if(n == 5)
					outtextxy(270,170,"O");
				else if(n == 6)
					outtextxy(370,170,"O");
				else if(n == 7)
					outtextxy(170,270,"O");
				else if(n == 8)
					outtextxy(270,270,"O");
				else if(n == 9)
					outtextxy(370,270,"O");

				}
				else
					goto again5;
		}

	}while(1);

	getch();
}

void controls()
{
	cleardevice();

	if(set%2 == 1)
		setbkcolor(1);
	else
		setbkcolor(0);

	settextstyle(0,0,5);

	setcolor(15);
	outtextxy(100,70,"Tic Tac Toe");

	rectangle(70,135,575,450);

	setcolor(6);
	settextstyle(0,0,2);
	outtextxy(190,200,"1,2,3,4,5,6,7,8,9");
	outtextxy(190,310,"Esc :- Go back/Exit");
	outtextxy(190,340,"Enter :- Select");
	outtextxy(190,370,"R :- Restart");
	outtextxy(190,400,"S :- Change GUI");

	setcolor(10);
	settextstyle(0,0,3);
	outtextxy(100,150,"Game Controls");
	outtextxy(100,250,"Other Contols");

   temp = getch();

   if(temp == 's' || temp == 'S')
		set++;
}

void multiplay()
{
	cleardevice();

	refresh();
	board();

	do
	{
	   player = (player%2)?1:2;

	   ch = getch();

	   if(player == 1)
			 setcolor(10);
	   else
			 setcolor(4);

	   if(ch=='1' && arr[1] == '1')
	   {
			(player == 1)? outtextxy(170,70,"X"): outtextxy(170,70,"O");
			arr[1] = (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='2' && arr[2] == '2')
	   {
			(player == 1)?  outtextxy(270,70,"X"): outtextxy(270,70,"O");
			arr[2] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='3' && arr[3] == '3')
	   {
			(player == 1)? outtextxy(370,70,"X"):outtextxy(370,70,"O");
			arr[3] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='4' && arr[4] == '4')
	   {
			(player == 1)? 	outtextxy(170,170,"X"):outtextxy(170,170,"O");
			arr[4] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='5' && arr[5] == '5')
	   {
			(player == 1)? outtextxy(270,170,"X"):outtextxy(270,170,"O");
			arr[5] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='6' && arr[6] == '6')
	   {
			(player == 1)? outtextxy(370,170,"X"):outtextxy(370,170,"O");
			arr[6] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='7' && arr[7] == '7')
	   {
			(player == 1)? outtextxy(170,270,"X"):outtextxy(170,270,"O");
			arr[7] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='8' && arr[8] == '8')
	   {
			(player == 1)? outtextxy(270,270,"X"):outtextxy(270,270,"O");
			arr[8] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch=='9' && arr[9] == '9')
	   {
			(player == 1)? outtextxy(370,270,"X"):outtextxy(370,270,"O");
			arr[9] =  (player == 1)? 'X' : 'O';
	   }
	   else if(ch == 27)
			loading();
	   else if(ch == 'R' || ch == 'r')
			multiplay();
	   else
			player--;

	   setcolor(10);
	   if((arr[1] == arr[2]  && arr[2] == arr[3]) || (arr[4] == arr[5] && arr[5] == arr[6]) || (arr[7] == arr[8] && arr[8] == arr[9]) || (arr[1] == arr[4] && arr[4] == arr[7]) || (arr[5] == arr[2] && arr[2] == arr[8]) || (arr[9] == arr[6] && arr[6] == arr[3]) || (arr[1] == arr[5] && arr[5] == arr[9]) || (arr[3] == arr[5] && arr[5] == arr[7]))
	   {
			(player == 1)? outtextxy(130,380,"X Wins"):outtextxy(130,380,"O wins");
			wincase();
			sleep(2);
			loading();
	   }
	   else if(arr[1] != '1' && arr[2] != '2' &&  arr[3] != '3' &&  arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' &&  arr[8] != '8' && arr[9] != '9')
	   {
			outtextxy(180,380,"Draw");
			sleep(2);
			loading();
	   }

	   player ++;
	}
	while(1);

	getch();
}

void about()
{
	cleardevice();
	setbkcolor(0);

	setcolor(15);
	for(int i=1;i<=700;i=i+2)
	{
		cleardevice();
		settextstyle(0,0,5);
		outtextxy(100,750-i,"Tic Tac Toe");
		settextstyle(0,0,2);
		outtextxy(50,830-i,"Graphic & Animation : Sahil Barke");
		outtextxy(50,870-i,"Music & Colors : Tanmay Ahvad");
		outtextxy(50,910-i,"Design & Layout : Snehal Chougule");
		outtextxy(340,940-i,"Soni Sharma");
		outtextxy(50,980-i,"Functioning : Dipesh Adelkar");
		outtextxy(50,1030-i,"Game Logic : Kashish Chaturvedi");
		outtextxy(50,1080-i,"Code Source :");
		outtextxy(110,1130-i,"github.com/x-darkvanilla-x");
		delay(10);
	}

	getch();
}

void mainmenu()
{
		a = '1';
		again3:
		 cleardevice();

		if(set%2 == 1)
			setbkcolor(1);
		else
			setbkcolor(0);

		 setcolor(14);
		 settextstyle(0,0,3);

		 if(a== '1'){
				outtextxy(120,150,">");
				outtextxy(510,150,"<");
		 }
		 else if(a == '2'){
				outtextxy(130,215,">");
				outtextxy(500,215,"<");
		 }
		 else if(a == '3'){
				outtextxy(150,280,">");
				outtextxy(470,280,"<");
		 }
		 else if(a == '4'){
				outtextxy(170,345,">");
				outtextxy(450,345,"<");
		 }
		 else if(a == '5'){
				outtextxy(210,410,">");
				outtextxy(400,410,"<");
		 }

		 setcolor(15);
		 settextstyle(0,0,5);
		 outtextxy(100,70,"Tic Tac Toe");

		 setcolor(10);
		 settextstyle(0,0,3);
		 outtextxy(170,150,"Single Player");

		 setcolor(4);
		 outtextxy(180,215,"Multi-player");

		 setcolor(6);
		 outtextxy(200,280,"About game");

		 setcolor(3);
		 outtextxy(225,345,"Settings");

		 setcolor(13);
		 outtextxy(270,410,"Exit");

		 a = getch();

		 if(a == 80)
			key++;
		 else if(a == 72)
			key--;
		 else if(a == 27)
			exit(0);
		 else if(a == 13)
		 {
			if(key == 1)
				singleplay();
			else if(key == 2)
				multiplay();
			else if(key == 3)
				about();
			else if (key == 4)
				controls();
			else if(key == 5)
				exit(0);
		 }

			if(key == 1)
				a = '1';
			else if(key == 2)
				a = '2';
			else if(key == 3)
				a = '3';
			else if (key == 4)
				a = '4';
			else if(key == 5)
				a = '5';
			else if(key > 5)
			{
				a = '5';
				key = 5;
			}
			else if(key < 1)
			{
				a = '1';
				key = 1;
			}

		 goto again3;
}

void loading()
{
	cleardevice();

	setbkcolor(0);

	setcolor(15);
	outtextxy(170,420,"This game is only played with keyboard");

	for(int i=0;i<=300;i++)
	{
		rectangle(170+i,390,170+i,400);
		delay(5);
	}
	mainmenu();
}

int main()
{
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	loading();
	getch();
}
