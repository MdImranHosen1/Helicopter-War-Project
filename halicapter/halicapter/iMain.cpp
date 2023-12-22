#include "iGraphics.h"
#include<iostream>
#include<stdio.h>
using namespace std;

int mposx,  mposy;
//button
int gameState = -1;
struct buttonCordinate
{
	int BCx;
	int BCy;
}Buttoncordinate[4];
//point achive
int pointa = 10;
//point picture
char pointpic[15][20] = { "image\\0.bmp", "image\\1.bmp", "image\\2.bmp", "image\\3.bmp", "image\\4.bmp", "image\\5.bmp", "image\\6.bmp", "image\\7.bmp", "image\\8.bmp", "image\\9.bmp" };

//buttom
char button[15][20] = { "image\\button1.bmp", "image\\button2.bmp", "image\\button31.bmp", "image\\button4.bmp" };
char homePage[20] = { "image\\homeMenu.bmp" };


int mainPicX1 = 343, mainPicY = 0;
//my halicapter
char halicapter[4][20] = { "image\\h1.bmp", "image\\h2.bmp", "image\\h3.bmp", "image\\h4.bmp" };
int mh = 0,halicapterX=355,halicapterY=400;

//enemy halicapter
char Ehalicapter[4][20] = { "image\\eh1.bmp", "image\\eh2.bmp", "image\\eh3.bmp", "image\\eh4.bmp" };
int eh=0,EhalicapterX = 1520, EhalicapterY = 400;
bool distroy1 = false;
int distroytime = 5;


//boom part for halicapter
bool boomA = false,boomB=false;
int boomAX = halicapterX+100, boomAY = halicapterY,boomGOX,boomGOY;

bool boomA1 = false, boomB1 = false;
int boomAX1 = halicapterX + 100, boomAY1 = halicapterY, boomGOX1, boomGOY1;

bool boomA2 = false, boomB2 = false;
int boomAX2 = halicapterX + 100, boomAY2 = halicapterY, boomGOX2, boomGOY2;


//tank part
char tank[2][20] = { "image\\t1.bmp", "image\\t2.bmp" };
int tankAX = 1400, tankAY = 55;
int tankAX1 = 1400+527, tankAY1 = 55;


//boom part tank //clear
bool TboomA = false, TboomB = false;
int TboomAX = halicapterX, TboomAY = halicapterY;

bool TboomA1 = false, TboomB1 = false;
int TboomAX1 = halicapterX, TboomAY1 = halicapterY;

bool TboomA2 = false, TboomB2 = false;
int TboomAX2 = halicapterX, TboomAY2 = halicapterY;

bool Tdistroy1 = false, Tdistroy2 = false;

//My halicapter life
int MyHalicapterLife = 100;

//game over
bool gameover = false;


//replay
bool replay = false;
bool home = false;

//music
bool menuMusic = true;
bool gameMusic = true;
void musicChange();

//multiplayer start
int player1halicapterX = 10;
int player1halicapterY = 400;
int player2halicapterX =1270;
int player2halicapterY = 400;

//player 1 halicapter
char P1halicapter[4][20] = { "image\\P1h1.bmp", "image\\P1h2.bmp", "image\\P1h3.bmp", "image\\P1h4.bmp" };
int  p1hc = 0;
//player 1 distroy
bool P1distroy1 = false;
//boom part player 1
bool P1boomA = false, P1boomB = false;
int P1boomAX = player1halicapterX + 100, P1boomAY = player1halicapterY, P1boomGOX, P1boomGOY;

bool P1boomA1 = false, P1boomB1 = false;
int P1boomAX1 = player1halicapterX + 100, P1boomAY1 = player1halicapterY, P1boomGOX1, P1boomGOY1;

bool P1boomA2 = false, P1boomB2 = false;
int P1boomAX2 = player1halicapterX + 100, P1boomAY2 = player1halicapterY, P1boomGOX2, P1boomGOY2;

//player 2 halicapter
char P2halicapter[4][20] = { "image\\P2h1.bmp", "image\\P2h2.bmp", "image\\P2h3.bmp", "image\\P2h4.bmp" };
int p2hc = 0;

//player 1 distroy
bool P2distroy1 = false;

//boom part for  Player 2
bool P2boomA = false, P2boomB = false;
int P2boomAX = player2halicapterX + 100, P2boomAY = player2halicapterY, P2boomGOX, P2boomGOY;

bool P2boomA1 = false, P2boomB1 = false;
int P2boomAX1 = player2halicapterX + 100, P2boomAY1 = player2halicapterY, P2boomGOX1, P2boomGOY1;

bool P2boomA2 = false, P2boomB2 = false;
int P2boomAX2 = player2halicapterX + 100, P2boomAY2 = player2halicapterY, P2boomGOX2, P2boomGOY2;

//multiplayer music
int MPMenuSound = 0;
int MPhalicapterSound = 0;

//distroy music
bool distroymusicC = false;

//point show 
int point = 0;



//life show
int life = 100, lifegraph = 0;

//draw funtion
void iDraw()
{
	iClear();
	musicChange();
	//homemenu
	if (gameState == -1)
	{
		
		iShowBMP2(0, 0, homePage, 255);
		for (int i = 0; i < 4; i++)
		{
			iShowBMP2(Buttoncordinate[i].BCx, Buttoncordinate[i].BCy, button[i], 255);
		}
		
	}
	//single play
	else if (gameState == 0)
	{
		//back picture
		if (point < pointa)
		{
			iShowBMP(mainPicX1, mainPicY, "image\\sinary.bmp");
			mainPicX1--;
			if (mainPicX1 == 0)
			{
				mainPicX1 = 343 - 0.2;
			}
		}
		else
		{
			iShowBMP(mainPicX1, mainPicY, "image\\sinary2.bmp");
			mainPicX1--;
			if (mainPicX1 == 0)
			{
				mainPicX1 = 343 - 0.2;
			}

		}

		//halicapter
		//own
		iShowBMP2(halicapterX, halicapterY, halicapter[mh], 255);
		if (mh == 3)
		{
			mh = 0;
		}
		else
		{
			mh++;
		}
		//enemy
		if (!distroy1)
		{
			iShowBMP2(EhalicapterX, EhalicapterY, Ehalicapter[eh], 255);
			if (eh == 3)
			{
				eh = 0;
			}
			else
			{
				eh++;
			}
			EhalicapterX -= 2;
			distroytime = 5;
			if (EhalicapterX <= 250)
			{
				EhalicapterX = 1520;
				//random number
				EhalicapterY = rand() % 540;
				if (EhalicapterY<220)
				{
					EhalicapterY += 220;
				}
				//rendom number end
				//life 
				life -= 7;
				lifegraph++;
			}

		}
		else if (distroytime >= 0)
		{
			iShowBMP2(EhalicapterX, EhalicapterY, "image\\distroy.bmp", 255);
			EhalicapterX = 1520;
			//random number
			EhalicapterY = rand() % 540;
			if (EhalicapterY<220)
			{
				EhalicapterY += 220;
			}
			//rendom number end
			if (distroytime == 0)
			{
				distroy1 = false;

			}
			distroytime--;
		}

		//distroy halicapter
		if ((boomAX <= EhalicapterX + 130 && boomAX >= EhalicapterX) && (boomAY <= EhalicapterY + 31 && boomAY >= EhalicapterY))
		{
			distroy1 = true;
			point += 10;
		}
		else if ((boomAX1 <= EhalicapterX + 130 && boomAX1 >= EhalicapterX) && (boomAY1 <= EhalicapterY + 31 && boomAY1 >= EhalicapterY))
		{
			distroy1 = true;
			point += 10;
		}
		else if ((boomAX2 <= EhalicapterX + 130 && boomAX2 >= EhalicapterX) && (boomAY2 <= EhalicapterY + 31 && boomAY2 >= EhalicapterY))
		{
			distroy1 = true;
			point += 10;
		}

		//boom part for halicaptor start
		//boom 1
		if (boomA)
		{

			if (boomAX == 1400)
			{
				boomAX = halicapterX + 100, boomAY = halicapterY;
				boomA = false;
			}
			else if (!boomB)
			{
				if (distroy1)
				{
					boomAX = halicapterX - 100, boomAY = halicapterY;
					boomA = false;
					boomB = true;
				}
				iShowBMP2(boomAX, boomAY, "image\\boomA.bmp", 255);
				boomAX += 7, boomAY += 1;
			}
		}
		//boom 2
		if (boomA1)
		{

			if (boomAX1 == 1400)
			{
				boomAX1 = halicapterX + 100, boomAY1 = halicapterY;
				boomA1 = false;
			}
			else if (!boomB1)
			{
				if (distroy1)
				{
					boomAX1 = halicapterX - 100, boomAY1 = halicapterY;
					boomA1 = false;
					boomB1 = true;
				}
				iShowBMP2(boomAX1, boomAY1, "image\\boomA.bmp", 255);
				boomAX1 += 7;
			}
		}
		//boom 3
		if (boomA2)
		{

			if (boomAX2 == 1400)
			{
				boomAX2 = halicapterX + 100, boomAY2 = halicapterY;
				boomA2 = false;
			}
			else if (!boomB2)
			{
				if (distroy1)
				{
					boomAX2 = halicapterX - 100, boomAY2 = halicapterY;
					boomA2 = false;
					boomB2 = true;
				}
				iShowBMP2(boomAX2, boomAY2, "image\\boomA.bmp", 255);
				boomAX2 += 7, boomAY2 -= 1;
			}
		}

		//boom part for halicaptor end


		//tank part
		//tank 1
		if (!Tdistroy1)
		{
			if (point < pointa)
			{
				if (tankAX > 600)
				{
					iShowBMP2(tankAX, tankAY, tank[0], 255);
				}
				else if (tankAX < 600)
				{
					iShowBMP2(tankAX, tankAY, tank[1], 255);
				}
				tankAX -= 3;
				if (tankAX <= 343 - 105)
				{
					tankAX = 1400;
					//life 
					life -= 7;
					lifegraph++;
				}
				Tdistroy1 = false;
			}
			else
			{
				iShowBMP2(tankAX, tankAY, "image\\ship.bmp", 0);
				tankAX -= 3;
				if (tankAX <= 343 - 105)
				{
					tankAX = 1400;
					//life 
					life -= 7;
					lifegraph++;

				}
				Tdistroy1 = false;
			}
		}
		else if (Tdistroy1)
		{
			tankAX = 1400;
			Tdistroy1 = false;
		}

		//tank 2
		if (!Tdistroy2)
		{
			if (point < pointa)
			{
				if (tankAX1 < 600)
				{
					iShowBMP2(tankAX1, tankAY1, tank[1], 255);
				}
				else if (tankAX1 > 600)
				{
					iShowBMP2(tankAX1, tankAY1, tank[0], 255);
				}
				tankAX1 -= 3;
				if (tankAX1 <= 343 - 105)
				{
					tankAX1 = 1400;
					//life 
					life -= 7;
					lifegraph++;
				}
				Tdistroy2 = false;
			}
			else
			{
				iShowBMP2(tankAX1, tankAY1, "image\\ship.bmp", 0);
				tankAX1 -= 3;
				if (tankAX1 <= 343 - 105)
				{
					tankAX1 = 1400;
					//life 
					life -= 7; 
					lifegraph++;
				}
				Tdistroy2 = false;
			}
			
		}
		else if (Tdistroy2)
		{
			tankAX1 = 1400 + 200;
			Tdistroy2 = false;
		}

		//boom part for tanks start
		if (TboomA)
		{
			iShowBMP2(TboomAX, TboomAY, "image\\boomB.bmp", 255);
			TboomAX += 0, TboomAY -= 6;
			TboomB = true;
			if (TboomAY <= 55)
			{
				iShowBMP2(TboomAX, 55, "image\\distroy.bmp", 255);
				TboomAX = halicapterX, TboomAY = halicapterY;
				TboomB = false;
				TboomA = false;
			}
		}
		if (TboomA1)
		{
			iShowBMP2(TboomAX1, TboomAY1, "image\\boomB.bmp", 255);
			TboomAX1 += 6, TboomAY1 -= 4;
			TboomB1 = true;
			if (TboomAY1 <= 55)
			{
				iShowBMP2(TboomAX1, 55, "image\\distroy.bmp", 255);
				TboomAX1 = halicapterX, TboomAY1 = halicapterY;
				TboomB1 = false;
				TboomA1 = false;
			}
		}
		if (TboomA2)
		{
			iShowBMP2(TboomAX2, TboomAY2, "image\\boomB.bmp", 255);
			TboomAX2 += 8, TboomAY2 -= 3;
			TboomB2 = true;
			if (TboomAY2 <= 55)
			{
				iShowBMP2(TboomAX2, 55, "image\\distroy.bmp", 255);
				TboomAX2 = halicapterX, TboomAY2 = halicapterY;
				TboomB2 = false;
				TboomA2 = false;
			}
		}
		//boom part for tanks end

		//distroy tank start
		//tank===1
		if ((TboomAX <= tankAX + 120 && TboomAX >= tankAX - 30) && (TboomAY <= tankAY + 40 && TboomAY >= tankAY))
		{
			Tdistroy1 = true;
			point += 10;
		}
		else if ((TboomAX1 <= tankAX + 120 && TboomAX1 >= tankAX - 30) && (TboomAY1 <= tankAY + 40 && TboomAY1 >= tankAY))
		{
			Tdistroy1 = true;
			point += 10;
		}
		else if ((TboomAX2 <= tankAX + 120 && TboomAX2 >= tankAX - 30) && (TboomAY2 <= tankAY + 40 && TboomAY2 >= tankAY))
		{
			Tdistroy1 = true;
			point += 10;
		}
		//tank==2
		else if ((TboomAX <= tankAX1 + 120 && TboomAX >= tankAX1 - 30) && (TboomAY <= tankAY1 + 40 && TboomAY >= tankAY1))
		{
			Tdistroy2 = true;
			point += 10;
		}
		else if ((TboomAX1 <= tankAX1 + 120 && TboomAX1 >= tankAX1 - 30) && (TboomAY1 <= tankAY1 + 40 && TboomAY1 >= tankAY1))
		{
			Tdistroy2 = true;
			point += 10;
		}
		else if ((TboomAX2 <= tankAX1 + 120 && TboomAX2 >= tankAX1 - 30) && (TboomAY2 <= tankAY1 + 40 && TboomAY2 >= tankAY1))
		{
			Tdistroy2 = true;
			point += 10;
		}
		//distroy tank end

		//point show display
		iShowBMP(0, 0, "image\\back.bmp");
	
		if (point < 100)
		{
			int sum = 0;
			sum = point / 10;
			iShowBMP2(20, 520, pointpic[sum], 0);
			iShowBMP2(60, 520, pointpic[0], 0);
		}
		else if (point < 1000)
		{
			int sum = 0,sum2 = 0;
			sum = point / 10;
			sum2 = sum / 10;
			sum = sum  - sum2 * 10;
			iShowBMP2(20, 520, pointpic[sum2], 0);
			iShowBMP2(60, 520, pointpic[sum], 0);
			iShowBMP2(100, 520, pointpic[0], 0);
				
				
		}
		else if (point < 10000)
		{
			int sum = 0, sum2 = 0;
			sum = point / 10;
			sum2 = sum / 10;
			sum = sum - sum2 * 10;
			iShowBMP2(100, 520, pointpic[sum], 0);//3
			int sum3 = sum2 / 10;
			sum = sum2 - sum3 * 10;
			iShowBMP2(20, 520, pointpic[point/1000], 0);//1
			iShowBMP2(60, 520, pointpic[sum], 0);//2
			iShowBMP2(140, 520, pointpic[0], 0);//4
		}
	
		//life down process
		iShowBMP(177,335-12*lifegraph, "image\\lifed.bmp");


		//game over funtion
		if (halicapterX + 120 >= EhalicapterX && halicapterX <= EhalicapterX + 100 && halicapterY <= EhalicapterY + 34 && halicapterY + 51 >= EhalicapterY)
		{
			iShowBMP2(halicapterX, halicapterY, "image\\distroy.bmp", 255);
			iShowBMP2(EhalicapterX, EhalicapterY, "image\\distroy.bmp", 255);

			gameover = true;
			gameState = 5;
		}
		//life 
		if (life <= 0)
		{
			gameover = true;
			gameState = 5;
		}
		
	}
	//multiplayer
	else if (gameState == 1)
	{
		if (P2distroy1 || P1distroy1)
		{
			//win player 1
			if (P1distroy1)
			{
				iShowBMP(0, 0, "image\\winP1.bmp");
			}
			//win player 2
			else if (P2distroy1)
			{
				iShowBMP(0, 0, "image\\winP2.bmp");
			}
		}
		else
		{
			//multiplayer background
			iShowBMP(0, 0, "image\\MPbackground.bmp");

			//player 1
			iShowBMP2(player1halicapterX, player1halicapterY, P1halicapter[p1hc], 255);
			if (p1hc == 3)
			{
				p1hc = 0;
			}
			else
			{
				p1hc++;
			}
			//distroy player 1
			if ((P1boomAX >= player2halicapterX) && (P1boomAY <= player2halicapterY + 30 && P1boomAY >= player2halicapterY))
			{
				P1distroy1 = true;
			}
			else if ((P1boomAX1 >= player2halicapterX) && (P1boomAY1 <= player2halicapterY + 30 && P1boomAY1 >= player2halicapterY))
			{
				P1distroy1 = true;
			}
			else if ((P1boomAX2 >= player2halicapterX) && (P1boomAY2 <= player2halicapterY + 30 && P1boomAY2 >= player2halicapterY))
			{
				P1distroy1 = true;
			}
			//p1 boom 1
			if (P1boomA)
			{

				if (P1boomAX >= 1400)
				{
					P1boomAX = player1halicapterX + 100, P1boomAY = player1halicapterY;
					P1boomA = false;
				}
				else if (!P1boomB)
				{
					iShowBMP2(P1boomAX, P1boomAY, "image\\boomA.bmp", 255);
					P1boomAX += 10, P1boomAY += 1;
				}
			}
			//p1 boom 2
			if (P1boomA1)
			{

				if (P1boomAX1 >= 1400)
				{
					P1boomAX1 = player1halicapterX + 100, P1boomAY1 = player1halicapterY;
					P1boomA1 = false;
				}
				else if (!P1boomB1)
				{
					iShowBMP2(P1boomAX1, P1boomAY1, "image\\boomA.bmp", 255);
					P1boomAX1 += 10;
				}
			}
			//p1 boom 3
			if (P1boomA2)
			{

				if (P1boomAX2 >= 1400)
				{
					P1boomAX2 = player1halicapterX + 100, P1boomAY2 = player1halicapterY;
					P1boomA2 = false;
				}
				else if (!P1boomB2)
				{

					iShowBMP2(P1boomAX2, P1boomAY2, "image\\boomA.bmp", 255);
					P1boomAX2 += 10, P1boomAY2 -= 1;
				}
			}
			//player 2

			iShowBMP2(player2halicapterX, player2halicapterY, P2halicapter[p2hc], 0);
			if (p2hc == 3)
			{
				p2hc = 0;
			}
			else
			{
				p2hc++;
			}
			//distroy player 2
			if (( P2boomAX <= player1halicapterX) && (P2boomAY <= player1halicapterY + 30) && (P2boomAY >= player1halicapterY))
			{
				P2distroy1 = true;
			}
			else if (( P2boomAX1 <= player1halicapterX) && (P2boomAY1 <= player1halicapterY + 30) && (P2boomAY1 >= player1halicapterY))
			{
				P2distroy1 = true;
			}
			else if ((P2boomAX2 <= player1halicapterX) && (P2boomAY2 <= player1halicapterY + 30) && (P2boomAY2 >= player1halicapterY))
			{
				P2distroy1 = true;
			}
			//p2 boom 1
			if (P2boomA)
			{

				if (P2boomAX <= 0)
				{
					P2boomAX = player2halicapterX + 100, P2boomAY = player2halicapterY;
					P2boomA = false;
				}
				else if (!P2boomB)
				{
					iShowBMP2(P2boomAX, P2boomAY, "image\\boomA1.bmp", 255);
					P2boomAX -= 10, P2boomAY += 1;
				}
			}
			//p2 boom 2
			if (P2boomA1)
			{

				if (P2boomAX1 <= 0)
				{
					P2boomAX1 = player2halicapterX + 100, P2boomAY1 = player2halicapterY;
					P2boomA1 = false;
				}
				else if (!P2boomB1)
				{
					iShowBMP2(P2boomAX1, P2boomAY1, "image\\boomA1.bmp", 255);
					P2boomAX1 -= 10;
				}
			}
			//p2 boom 3
			if (P2boomA2)
			{

				if (P2boomAX2 <= 0)
				{
					P2boomAX2 = player2halicapterX + 100, P2boomAY2 = player2halicapterY;
					P2boomA2 = false;
				}
				else if (!P2boomB2)
				{
					iShowBMP2(P2boomAX2, P2boomAY2, "image\\boomA1.bmp", 255);
					P2boomAX2 -=10, P2boomAY2 -= 1;
				}
			}


		}
	}
	else if (gameState == 2)
	{
		iShowBMP(0, 0, "image\\instructions.bmp");
	}
	else if (gameState == 3)
	{
		iShowBMP(0,0,"image\\exit.bmp" );
	}
	else if (gameState == 4)
	{

	}
	else if (gameState == 5)
	{
		if (gameover)
		{
			iShowBMP(0, 0, "image\\gameover.bmp");
			if (distroymusicC == false)
			{
				distroymusicC = true;
				menuMusic = true;
			}

		}
	}
}
		
void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = 0; i < 4; i++)
		{
			if (mx >= Buttoncordinate[i].BCx && mx <= Buttoncordinate[i].BCx + 356 && my >= Buttoncordinate[i].BCy && my <= Buttoncordinate[i].BCy + 103)
			{
				gameState = i;
				if (gameState >= 0)
				{
					gameMusic = true;
				}
			}
		}
	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	mposx = mx;
	mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}

void iKeyboard(unsigned char key)
{
	
	//player 1
	if (key == 'w')//up1
	{
		if (player1halicapterY + 44 < 600)
		{
			player1halicapterY += 7;
		}
	}
	if (key == 's')//down1
	{
		if (player1halicapterY > 200)
		{
			player1halicapterY -= 7;
		}
	}
	if (key == 'd')//right
	{
		if (player1halicapterX < 500)
		{
			player1halicapterX += 7;
		}	
	}
	if (key == 'a')//left
	{
		if (player1halicapterX > 0)
		{
			player1halicapterX -= 7;
		}	
	}
	if (key == 'z')//fair
	{
		if (P1boomAX - 100 <= player1halicapterX)
		{
			P1boomAY = player1halicapterY;
			P1boomAX = player1halicapterX + 100;
			P1boomA = true, P1boomB = false;
		}
	}
	if (key == 'x')//boom
	{
		if (P1boomAX1 - 100 <= player1halicapterX)
		{
			P1boomAY1 = player1halicapterY;
			P1boomAX1 = player1halicapterX + 100;
			P1boomA1 = true, P1boomB1 = false;
		}
	}
	if (key == 'c')//boom
	{
		if (P1boomAX2 - 100 <= player1halicapterX)
		{
			P1boomAY2 = player1halicapterY;
			P1boomAX2 = player1halicapterX + 100;
			P1boomA2 = true, P1boomB2 = false;
		}
	}
	//player 2
	if (key == 'i')//up1
	{
		if (player2halicapterY + 44 < 600)
		{
			player2halicapterY += 7;
		}
	}
	if (key == 'k')//down1
	{
		if (player2halicapterY > 200)
		{
			player2halicapterY -= 7;
		}
	}
	if (key == 'j')//left
	{
		if (player2halicapterX > 800)
		{
			player2halicapterX -= 7;
		}
	}
	if (key == 'l')//right
	{
		if (player2halicapterX<1270)
		player2halicapterX += 7;
	}
	if (key == 'b')//fair
	{
		if (P2boomAX - 100 >= player2halicapterX)
		{
			P2boomAY = player2halicapterY;
			P2boomAX = player2halicapterX-10;
			P2boomA = true, P2boomB = false;
		}
	}
	if (key == 'n')//boom
	{
		if (P2boomAX1 - 100 >= player2halicapterX)
		{
			P2boomAY1 = player2halicapterY;
			P2boomAX1 = player2halicapterX-10;
			P2boomA1 = true, P2boomB1 = false;
		}
	}
	if (key == 'm')//boom
	{
		if (P2boomAX2 - 100 >= player2halicapterX)
		{
			P2boomAY2 = player2halicapterY;
			P2boomAX2 = player2halicapterX -10;
			P2boomA2 = true, P2boomB2 = false;
		}
	}
	//end
	//for halicapter
	if (key == '1')
	{
		if (boomAX - 100 <= halicapterX)
		{
			boomAY = halicapterY;
			boomAX = halicapterX + 100;
			boomA = true, boomB = false;
		}
	}
	if (key == '2')
	{
		if (boomAX1 - 100 <= halicapterX)
		{
			boomAY1 = halicapterY;
			boomAX1 = halicapterX + 100;
			boomA1 = true, boomB1 = false;
		}
	}
	if (key == '3')
	{
		if (boomAX2 - 100 <= halicapterX)
		{
			boomAY2 = halicapterY;
			boomAX2 = halicapterX + 100;
			boomA2 = true, boomB2 = false;
		}
	}
	//for trank
	if (key == '4')
	{
		TboomA = true;
		if (!TboomB)
		{
			TboomAX = halicapterX, TboomAY = halicapterY;
		}
	}
	if (key == '5')
	{
		TboomA1 = true;
		if (!TboomB1)
		{
			TboomAX1 = halicapterX, TboomAY1 = halicapterY;
		}
	}
	if (key == '6')//clear
	{
		TboomA2 = true;
		if (!TboomB2)
		{
			TboomAX2 = halicapterX, TboomAY2 = halicapterY;

		}
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_UP)
	{
		if (halicapterY < 540)
		{
			halicapterY += 10;
		    
		}
		
	}
	else if (key == GLUT_KEY_DOWN)
	{
		if (halicapterY > 240)
		{
			halicapterY -= 10;
			
		}
	}
	else if  (key == GLUT_KEY_RIGHT)
	{
		if (halicapterX + 180 < 1400)
		{
			halicapterX += 10;
			
		}
	}
	else if (key == GLUT_KEY_LEFT)
	{
		if (halicapterX > 355)
		{
			halicapterX -= 10;
		}
	}
	if (key == GLUT_KEY_INSERT)
	{
		gameover = false;
		//multiplayer
		P2distroy1 = false;
		P1distroy1 = false;
		player1halicapterX = 10;
		player1halicapterY = 400;
		player2halicapterX = 1270;
		player2halicapterY = 400;
		P1boomA = false, P1boomB = false;
		P1boomAX = player1halicapterX + 100, P1boomAY = player1halicapterY;
		P1boomA1 = false, P1boomB1 = false;
		P1boomAX1 = player1halicapterX + 100, P1boomAY1 = player1halicapterY;
		P1boomA2 = false, P1boomB2 = false;
		P1boomAX2 = player1halicapterX + 100, P1boomAY2 = player1halicapterY;
		P2boomA = false, P2boomB = false;
		P2boomAX = player2halicapterX-10 , P2boomAY = player2halicapterY;
		P2boomA1 = false, P2boomB1 = false;
		P2boomAX1 = player2halicapterX-10 , P2boomAY1 = player2halicapterY;
		P2boomA2 = false, P2boomB2 = false;
		P2boomAX2 = player2halicapterX-10 , P2boomAY2 = player2halicapterY;
		//single player
		gameState = 0, gameMusic = true, menuMusic = true, distroymusicC = false;
		halicapterX = 355, halicapterY = 400;
		EhalicapterX = 1520, EhalicapterY = 400;
		tankAX = 1400, tankAY = 55;
		tankAX1 = 1400, tankAY1 = 55;
		lifegraph = 0,life=100,point=0;
	}
	if (key == GLUT_KEY_HOME)
	{
		gameState=-1;
		menuMusic = true;
		gameMusic = false;
		gameover = false;
		lifegraph = 0, life = 100, point = 0;
		
		halicapterX = 355, halicapterY = 400;
		EhalicapterX = 1520, EhalicapterY = 400;
		tankAX = 1400, tankAY = 55;
		tankAX1 = 1400 + 527, tankAY1 = 55;

		//multiplayer
		P2distroy1 = false;
		P1distroy1 = false;
		player1halicapterX = 10;
		player1halicapterY = 400;
		player2halicapterX = 1270;
		player2halicapterY = 400;
		P1boomA = false, P1boomB = false;
		P1boomAX = player1halicapterX + 100, P1boomAY = player1halicapterY;
		P1boomA1 = false, P1boomB1 = false;
		P1boomAX1 = player1halicapterX + 100, P1boomAY1 = player1halicapterY;
		P1boomA2 = false, P1boomB2 = false;
		P1boomAX2 = player1halicapterX + 100, P1boomAY2 = player1halicapterY;
		P2boomA = false, P2boomB = false;
		P2boomAX = player2halicapterX - 10, P2boomAY = player2halicapterY;
		P2boomA1 = false, P2boomB1 = false;
		P2boomAX1 = player2halicapterX - 10, P2boomAY1 = player2halicapterY;
		P2boomA2 = false, P2boomB2 = false;
		P2boomAX2 = player2halicapterX - 10, P2boomAY2 = player2halicapterY;
		musicChange();
	}
}
void musicChange()
{

	 if (gameState == -1 )
	{
		if (menuMusic)
		{
			PlaySound("sound\\soundMenu1.wav", NULL, SND_LOOP | SND_ASYNC);
			menuMusic = false;
		}	
	}
	if (gameState == 0 )
	{
		if (gameMusic)
		{
			PlaySound("sound\\soundHF.wav", NULL, SND_LOOP | SND_ASYNC);
			gameMusic = false;

		}
	}
	if(gameState == 1)
	{
		if (gameMusic)
		{
			PlaySound("sound\\soundHF.wav", NULL, SND_LOOP | SND_ASYNC);
			gameMusic = false;
		}
	}
	if (gameState == 5)
	{
		if (menuMusic)
		{
			PlaySound("sound\\soundMenu1.wav", NULL, SND_LOOP | SND_ASYNC);
			menuMusic = false;
		}
	}
}
int main()
{
	//for button
	int sum = 50;
	for (int i = 3; i >= 0; i--)
	{
		Buttoncordinate[i].BCx = 50;
		Buttoncordinate[i].BCy = sum;
		sum += 130;
	}
	//for music
	//iSetTimer(100, musicChange);
	
	iInitialize(1400, 600, "Imran");
	
	return 0;
}
