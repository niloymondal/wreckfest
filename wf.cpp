# include "iGraphics.h"
# include "myheader.h"

int image1, image2, image3,image4, image5, image6, image7, image8, image9, image10, image11,image12,image13,image14,image15,image16,image17,image18,image19,image20,image21,image22,image23,image24,image25,image26,image27,image28,image29;
bool musicOn=true;
char str[100], str2[100],strshow1[100], strshow2[100], strshow3[100], strshow4[100], strshow5[100];
int len,mx,my;
int mode;
int flag = 0;
bool isNamePlateActive = true;
//Extra 
int kpdx=395,kpdy=10;
int point =0;
int healthX=150;
int healthX2=150;
bool crash=true;
char score[20];

//structure for inputing score and name
struct game
{
	int score;
	char name[50];
}play[50],t;



//For Showing the starting page of the game  
void PageOfstart()
{
	iShowImage(0, 0, 1200, 600, image1);
	iSetColor(255, 255, 255);
	iText(100, 100, "Press k for going to the next page");
}



//For Showing the Start menu page 
void MenuPage()
{
iShowImage(0, 0, 1200, 600, image2);
iShowImage(950, 550, 200, 50, image14);
iShowImage(950, 500, 200, 50, image15);
iShowImage(950, 450, 200, 50, image16);
iShowImage(950, 400, 200, 50, image17);

	
}

//details
int Rcar_x=420;
int Rcar_y=0;
int Rcar_width=130;
int Rcar_height=180;
void RedCar()
{
	iShowImage(Rcar_x,Rcar_y,Rcar_width,Rcar_height,image8);
}
int Bcar_x=700;
int Bcar_y=0;
int Bcar_width=130;
int Bcar_height=180;
bool isBluCarActive=true;



void BlueCar()
{
	if(isBluCarActive)
	{
	iShowImage(Bcar_x,Bcar_y,Bcar_width,Bcar_height, image9);
	if(Bcar_y<(Bcar_height/2)+100)
	Bcar_y+=5;
	
	}
	
	if(Bcar_y!=0&&Bcar_y==Rcar_y)
	{
		//Bcar_y-=190;

	}
	
	

}



//Bullet Firing

struct bullet{
	int x,y;
	bool fire;
}bullet[1000000],bullet2[10000];
int shoot=0;

void bulletshow()
{
	for(int i=0;i<shoot;i++)
	{
		if(bullet[i].fire==true)
		{
			iShowImage(bullet[i].x,bullet[i].y,40,20,image28);
			bullet[i].x+=4;
		}
	}
}
void bulletshow2(){
	for (int i = 0,y1=100 ; i < 10 ; i++,y1+=100)
	{
		bullet2[i].x -=1;
		if(bullet2[i].x<0)
		{	
			bullet2[i].x =Bcar_x ;
			bullet2[i].y = Bcar_y+50;
			bullet2[i].fire = true;
		}
	}
	

}
void enemybullet(){
	for (int i = 0 ; i <10 ; i++)
		{
			if (bullet2[i].fire)
				{
					iShowImage(bullet2[i].x,bullet2[i].y,40,20,image29);
				}
		}

	

}




//Enemy movement
int enemyX = 300,enemyY = 600,enemy_Speed = 1;


struct Enemy{
	int x,y;
	bool active;

}enemy[10];

void Enemy()
{

	for (int i = 0,y1=100 ; i < 5 ; i++,y1+=100)
	{
		enemy[i].y -= enemy_Speed+3;
		if(enemy[i].y<0)
		{	
			enemy[i].y =enemyY + y1;
			enemy[i].x = (enemyX-100)+ rand() % 800;
			enemy[i].active = true;
		}
	}
}

//showing  enemy
int Enemy_width=100;

void showEnemy()
{
	for (int i = 0 ; i < 5 ; i++)
		{
			if (enemy[i].active)
				{
					iShowImage(enemy[i].x,enemy[i].y,Enemy_width,130,image12);
				}
		}
}

//Background Movement

int road_height=600,road_width=1200;
int road_x=0;int road_y=0;
int roadSpeed = 1;


struct Background
{
	int ax,by;
	bool moving;
}roadDivision[15];

void Movement()
{
	for(int i=0,ay1=0;i<15;i++,ay1+=40)
	{
		roadDivision[i].by-=roadSpeed;
		if(roadDivision[i].by<0)
		{
			roadDivision[i].by=road_y+ay1;
			roadDivision[i].moving=true;
		}

	}

}
void road_Moving()
{
	for(int i=0;i<15;i++)
	{
		if(roadDivision[i].moving)
		{
			iShowImage(roadDivision[i].ax+road_x,roadDivision[i].by,road_width,road_height,image6);

		}
	}
}

//kill an enemy
void killEnemy()
{
	for (int i = 0; i < shoot ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if( enemy[j].active && bullet[i].fire == true)
						{
							if (bullet[i].x+15 >= enemy[j].x && bullet[i].x+15 <= enemy[j].x +66)
								{
									if (bullet[i].y+100 >= enemy[j].y && bullet[i].y+ 50 <= enemy[j].y + 97)
											{
												enemy[j].active = false;
												bullet[i].fire = false;
												
													point+=5;
													itoa(point,score,10);
												
												
											}
								}
						}
				}
		}

	

	
	
}

//collision between car and enemy
void collision()
{
	for (int j = 0 ; j < 6 ; j++)
				{
					if( enemy[j].active && crash == true)

						{
							if ((Rcar_x+Rcar_width >= enemy[j].x&& Rcar_x <= enemy[j].x)||(Rcar_x+Rcar_width >= enemy[j].x+Enemy_width &&  Rcar_x<= enemy[j].x+Enemy_width))
							{
								if (Rcar_y+Rcar_height-40>= enemy[j].y && Rcar_y<=enemy[j].y)
								{
									
									enemy[j].active = false;
									if(healthX>0)
									{
										healthX-=15;
									}
									
								}
							}
					}
	}

}


void killEnemy2()
{
	for (int i = 0; i < shoot ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if(bullet2[i].fire == true)
						{
							if (bullet2[i].x+12 >= Rcar_x && bullet2[i].x+12 <= Rcar_x +66)
								{
									if (bullet2[i].y+21 >= Rcar_y && bullet2[i].y+21 <= Rcar_y + 97)
											{
												
												bullet2[i].fire = false;
												
													if(healthX>0)
									{
										healthX-=15;
									}
												
												
											}
								}
						}
				}
		}

	

	
	
}
void collision2()
{
	for (int j = 0 ; j < 6 ; j++)
				{
					if(bullet2[ j].fire && crash == true)

						{
							if ((Rcar_x+Rcar_width >= bullet2[j].x&& Rcar_x <= bullet2[j].x)||(Rcar_x+Rcar_width >=bullet2[j].x+12 &&  Rcar_x<= bullet2[j].x+12))
							{
								if (Rcar_y+Rcar_height>= bullet2[j].y && Rcar_y<=bullet2[j].y)
								{
									
									bullet2[j].fire = false;
									
									
								}
							}
					}
	}

}


void killEnemy3()
{
	for (int i = 0; i < shoot ; i++)
		{
			for (int j = 0 ; j < 6 ; j++)
				{
					if(bullet[i].fire == true)
						{
							if (bullet[i].x+12 >= Bcar_x && bullet[i].x+12 <= Bcar_x +66)
								{
									if (bullet[i].y+21 >= Bcar_y && bullet[i].y+21 <= Bcar_y + 97)
											{
											
												bullet[i].fire = false;
												point+=5;
													itoa(point,score,10);
												
												if(healthX2>0)
									{
										healthX2-=3;
									}
												
												
											}
								}
						}
				}
		}

	

	
	
}	

	
void collision3()
{
	for (int j = 0 ; j < 6 ; j++)
				{
					if( enemy[j].active && crash == true)

						{
							if ((Bcar_x+Bcar_width >= enemy[j].x && Bcar_x <= enemy[j].x)||(Bcar_x+Bcar_width >= enemy[j].x+Enemy_width &&  Bcar_x<= enemy[j].x+Enemy_width))
							{
								if (Bcar_y+Bcar_height-40>= enemy[j].y && Bcar_y<=enemy[j].y)
								{
									
									enemy[j].active = false;
									if(healthX2>0)
									{
										healthX2-=3;
									}
									
								}
							}
					}
	}

}



//For showing that Game is Over
void GameOver()
{
	iShowImage(0, 0, 1200, 600, image4);
	

}
void GameOver2(){
	iShowImage(0, 0, 1200, 600, image5);
}

void GamePage()
{

	//lawn1Moving();
	//lawn2Moving();
	//iShowImage(0, 0, 150, 600, image5);
	//iShowImage(1050, 0, 150, 600, image7);
	//BackgroundMoving();
	Movement();
	road_Moving();
	Enemy();
	showEnemy();
	killEnemy();
	killEnemy2();
    bulletshow();
	bulletshow2();
	enemybullet();
	collision();
	collision2();
	collision3();
	killEnemy3();
	iSetColor(255, 255, 255);
	iText(1100,400,score,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1020,400,"score : ",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,255);
	iRectangle(100,500,150,20);
	iSetColor(0,0,255);
	iFilledRectangle(100,500,healthX,20);
	///
	iSetColor(255,255,255);
	iRectangle(1000,500,150,20);
	iSetColor(0,0,255);
	iFilledRectangle(1000,500,healthX2,20);
	
	 
	RedCar();
	
	

    BlueCar();
	if(healthX==0){
		GameOver2();
	}
	else if(healthX2==0){
		GameOver();
	}
	
	//iShowImage(1030,550, 160, 40, image10);
	//iShowImage(10, 550, 160, 40, image11);
	//iShowImage(150, 550, 900, 50, image13);
	iShowImage(150,600, 150, 600, image19);

	iSetColor(255, 255, 255);
	iText(950, 100, "Press k to switch input page");
	

}
void RecordInfo()
{
	iShowImage(0,0, 1200, 600, image18);
	//iShowImage(600,400, 200, 50, image19);
//iShowImage(850, 350, 150, 50, image21);
//iShowImage(600, 200, 200, 50, image20);
//iRectangle(450, 350, 350, 50);
//iRectangle(600, 150, 100, 50);
}

//Page after the game is over
void GameEndingPage()
{
	iShowImage(0, 0, 1200, 600, image3);

}

//Game instructions
void Instruction()
{
	iShowImage(0, 0, 1200, 600, image22);

}
//Game Pause Option
void Pause()
{
	iShowImage(0, 0, 1200, 600, image23);
    iShowImage(700, 400, 200, 50, image24);
    iShowImage(700, 350, 200, 50, image25);
    iShowImage(700, 300, 200, 50, image26);

}
//For showing Highscore
void Highscore()
{
	iShowImage(0, 0, 1200, 600, image27);
	    sprintf(strshow1,"1.\t %s                                \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t%d",play[0].name,play[0].score);
		sprintf(strshow2,"2.\t %s                                \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t%d",play[1].name,play[1].score);
		sprintf(strshow3,"3.\t %s                                  \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t%d",play[2].name,play[2].score);
		sprintf(strshow4,"4.\t %s                                  \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t%d",play[3].name,play[3].score);
		sprintf(strshow5,"5.\t %s                                \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t%d",play[4].name,play[4].score);
		iSetColor(255, 255, 255);
		iText(300,280,strshow1,GLUT_BITMAP_HELVETICA_18);
		iText(300,230,strshow2,GLUT_BITMAP_HELVETICA_18);
		iText(300,170,strshow3,GLUT_BITMAP_HELVETICA_18);	
		iText(300,120,strshow4,GLUT_BITMAP_HELVETICA_18);	
		iText(300,60,strshow5,GLUT_BITMAP_HELVETICA_18);
}
//For returning to homepage
void Quit(){
	PageOfstart();

}
//For resuming the game after being paused
void Resume()
{
	GamePage();

}

//Function for loading all the required pictures
void LoadImage()
{
	image3 = iLoadImage("images\\Highscor.jpg");
	image2 = iLoadImage("images\\Main menu.jpg");
	image1 = iLoadImage("images\\StartPage1.jpg");
	image4 = iLoadImage("images\\GameOver1.jpg");

	
	image5 = iLoadImage("images\\GameOver2.jpg");
	image6 = iLoadImage("images\\Roadlawn.jpg");
	//image7 = iLoadImage("images\\Lawn3.png");
	image8 = iLoadImage("images\\Car R.png");
	image9 = iLoadImage("images\\Car B.png");
	//image10 = iLoadImage("images\\LifeBarBlue.png");
	//image11 = iLoadImage("images\\LifeBarRed.png");
	image12 = iLoadImage("images\\Man1.png");
	image28 = iLoadImage("images\\bullet (2).png");
	image29 = iLoadImage("images\\bulet2.png");
	//image13 = iLoadImage("images\\Finish3.png");
	image18 = iLoadImage("images\\High score bck.jpg");
	//image19 = iLoadImage("images\\Name.png");
	//image20 = iLoadImage("images\\High score.png");
	//image21 = iLoadImage("images\\Submit.png");
	
	image14 = iLoadImage("images\\Start.png");
	image15 = iLoadImage("images\\Ins (Start).png");
	image16 = iLoadImage("images\\High score (start).png");
	image17 = iLoadImage("images\\Quit (Start).png");

	image22 = iLoadImage("images\\Instructions2.jpg");
	image23=iLoadImage("images\\Pause bck.png");

	image24=iLoadImage("images\\resume.png");
	image25=iLoadImage("images\\Ins.png");
	image26=iLoadImage("images\\Quit.png");
	image27=iLoadImage("images\\Highscor.jpg");
}

//For accessing all the Menu Options
int Option;
void MenuLoading()
{
	MenuPage();
	if(Option==1){
		GamePage();
	}

	else if(Option==2)
	{
		Instruction();
	}
	else if(Option==3)
	{
		Highscore();

	}
	else if(Option==4)
	{
		Quit();

     }


}

//For accessing the pause options
int a;
void PauseOptions()
{
	Pause();

	if(a==1)
	{
		Resume();

	}
	else if(a==2)
	{
		Instruction();
	}
	else if(a==3)
	{
		Quit();
	}

}


//For loading different pages of the game
int loadshow=1;
void LoadingPage()
{

	loadshow++;

}

void BackButton()
{
	loadshow--;
}

//for drawing text bar
void drawTextBox()
{
	
	iSetColor(220, 20, 60);
	iText(530, 585, "Input your name: ");
	iRectangle(530, 550, 250, 30);

}

//iDraw function
/*
function iDraw() is called again and again by the system.
*/


void iDraw()
{
	//place your drawing codes here

	iClear();

	/* iShowImage():
	Here, first 2 parameters are the lower left
	corner position of image you want to put.
	3rd and 4th parameters are the widht and the height
	of the image.
	Last parameter is the id of the image you want to put.
	*/

	
	if(loadshow==1)
	{
		PageOfstart();
	}
	else if(loadshow==2)
	{
		MenuLoading();
	}
	
	//else if(loadshow==3)
	//{
	//PauseOptions();
	//}
		
	else if(loadshow==4)
	{
		GameEndingPage();
	}
	//else if(loadshow==5)
	//{
	//	GameOver();
	//}
	else if(loadshow==3)
	{
		RecordInfo();
        drawTextBox();

	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(531, 558, str);
	}
		

	}
	
}



/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}
/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}


/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 

		printf("\n%d \t %d\n", mx, my);
		
		
		if (isNamePlateActive == true)
		{
			if (mx >= 850 && mx <= 950 && my >= 350 && my <= 400)
			{
				flag = 1;
			}
		}
		if(mx >=950 && mx<=950+200 && my>=550 && my<=550+50)
		{
			Option=1;

		}
		if(mx >=950 && mx<=950+200 && my>=500 && my<=500+50)
		{
			Option=2;

		}
		if(mx >=950 && mx<=950+200 && my>=450 && my<=450+50)
		{
			Option=3;

		}
		if(mx >=950 && mx<=950+200 && my>=400 && my<=400+50)
		{
			Option=4;

		}
		if(mx >=700 && mx<=700+200 && my>=400 && my<=400+50)
		{
			a=1;

		}
		if(mx >=700 && mx<=700+200 && my>=350 && my<=350+50)
		{
			a=2;

		}
		if(mx >=700 && mx<=700+200 && my>=300 && my<=300+50)
		{
			a=3;

		}
		//clicking the left mouse button to the name taking box to input the name
	//clicking the left mouse button to the name taking box to input the name
	else if(mx > 529 && mx < 778 && my > 554 && my < 580)
		{
			mode = 1;
		}
		else if(mx > 529 && mx < 778 && my > 501 && my < 530)
		{
			mode = 2;
		}

		
		
		

		//place your codes here
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	FILE *fp=fopen("HighScore.txt","a");
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			fprintf(fp,"%s\t\t", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}
	
	
        if(key =='k')
	{
		LoadingPage();
	}
 else if (key =='b')
 {
 BackButton();
 }
 else if(key=='p')
 {
 Pause();
 }
  else if(key=='d')
 {
	 
	 
	 if(Rcar_x+Rcar_width<250+700-70)
	 {
		 Rcar_x+=10;
		
		  
			
	 }
	
	 

	 
	 
	 

 }
  else if(key=='w')
 {
	 if(Rcar_y+Rcar_height<(road_height/2)+100)
	 {
		 Rcar_y+=10;
	 }

 }
  else if(key=='a')
 {
	 if(Rcar_x>250+70)
	 {
		 Rcar_x-=10;
	 }
 }

 else if(key=='s')
 {
	 if(Rcar_y>road_y)
	 {
		 Rcar_y-=10;
	 }
 }
 else if(key==32)
 {
	 if(shoot<100)
		 shoot++;
	 
	 bullet[shoot-1].fire=true;
	 bullet[shoot-1].x=Rcar_x+20;
	 bullet[shoot-1].y=Rcar_y+20;

 }
	
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if (key == GLUT_KEY_HOME)
	{
		//playing music condition

			if(!musicOn)
			{
			musicOn=false;
			PlaySound(0,0,0);

			}

			else
			{
			musicOn=true;
			//playing music non-stop
			PlaySound("music\\Destruction.wav", NULL, SND_LOOP | SND_ASYNC);
			}

	}

	//place your codes for other keys here
}


int main()
{
	//place your own initialization codes here.

	//reading and show in console
	//sorting score

	FILE *fp=fopen("HighScore.txt","r");
	int i,j;
	//sorting
			for(i = 0; i < 6; i++)
			{
				fscanf(fp,"%s %d",play[i].name,&play[i].score); 
			}
			len = 0;
			for(i=0;i<6;i++)
			{
				for(j=0;j<5;j++)
				{
					if(play[j].score<play[j+1].score)
					{
						t=play[j];
						play[j]=play[j+1];
						play[j+1]=t;
			}
		}
	}
			for(i=0;i<play[i].score;i++)
    {
        printf("%s\t\t\t",play[i].name);
		 printf("%d\t\t\t\n",play[i].score);
    }


    iSetTimer(10000,BlueCar);
	iInitialize(1200, 600, "WreckFest");
	
	
	//playing music
	if(musicOn)
		PlaySound("music\\Destruction.wav", NULL, SND_LOOP | SND_ASYNC);

	// loading images.
	/* iLoadImage() will return an interger type id
	   for each image you load.
	*/
	 LoadImage();

	iStart(); // it will start drawing

	return 0;
}
