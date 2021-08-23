#include "iGraphics.h"
#include "bitmap_loader.h"
//variables declaration
int Menu,Background,Back,Ins,Hero,Score,About,Credits,mx,my;
char str[100], str2[100];
int len;
int mode;
int flag = 0;
void drawTextBox()
{
	
	iSetColor(220, 20, 60);
	iText(530, 585, "Input your name: ");
	iRectangle(530, 550, 250, 30);

}
void drawTextBox2()
{
		iSetColor(255, 255, 255);
		iText(530, 535, "Input your Score: ");
	    iRectangle(530, 500, 250, 30);

}

//iDraw function
void iDraw()
{
	iClear();
	//input name in the scoreboard

	//Menu informations
    if(flag == 0){
	iShowImage(0, 0, 1280, 720, Menu);
	}
	else if (flag == 1)
	{
		iShowImage(0, 0, 1280, 720, Background);
		iShowImage(0, 50, 100, 200, Hero);
		iShowImage(1100, 50, 150, 150, Back);
		iShowImage(1100, 450, 150, 150, Back);
	}
	else if (flag == 2)
	{ 
		iShowImage(0, 0, 1280, 720, Ins);
		iShowImage(1100, 50, 150, 150, Back);
	}
	else if (flag == 3)
	{ 
		iShowImage(0, 0, 1280, 720, Score);
		iShowImage(1100, 50, 150, 150, Back);
			drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(531, 558, str);
	}
		drawTextBox2();
		if(mode == 2)
	{
		iSetColor(255, 255, 255);
		iText(531, 505, str);
	}

	}
		else if (flag == 4)
	{ 
		iShowImage(0, 0, 1280, 720, About);
		iShowImage(1100, 50, 150, 150, Back);
	}
			else if (flag == 5)
	{ 
		iShowImage(0, 0, 1280, 720, Credits);
		iShowImage(1100, 50, 150, 150, Back);
	}
	else if (flag == 6)
	{
		exit(0);
	}
}

void iPassiveMouse(int x, int y)
{
	;
}

void iMouseMove(int mx, int my)
{
	

}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("\n%d \t %d\n", mx, my);
		//Start button actions
		if(mx > 100 && mx < 310 && my > 310 && my < 350)
		{
			flag = 1;
		
	    }
		//Informations button actions
		else if( mx > 100 && mx < 460 && my > 230 &&  my < 250)
		{
			flag = 2;
		}
		//Score button actions
		else if( mx > 110 && mx < 277 && my > 122 &&  my < 173)
		{
			flag = 3;
		}
		//About button actions
		else if( mx > 1098 && mx < 1239 && my > 671 &&  my < 702)
		{
			flag = 4;
		}
		//Credits button actions
		else if( mx > 1093 && mx < 1262 && my > 614 &&  my < 645)
		{
			flag = 5;
		}
		//Exit button actions
		else if( mx > 100 && mx < 300 && my > 50 &&  my < 90)
		{
			flag = 6;
		}
		//Back button actions
	else if( mx > 1110 && mx < 1242 && my > 91 &&  my < 162)
		{
			flag = 0;
		}
		else if( mx > 1110 && mx < 1242 && my > 481 &&  my < 569)
		{
			flag = 3;
		}
	//clicking the left mouse button to the name taking box to input the name
	else if(mx > 529 && mx < 778 && my > 554 && my < 580)
		{
			mode = 1;
		}
		else if(mx > 529 && mx < 778 && my > 501 && my < 530)
		{
			mode = 2;
		}
	


		
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	
	}
}
}
void iKeyboard(unsigned char key)
{
	FILE *fp=fopen("data.txt","w");
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			fprintf(fp,"%s\n", str2);
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
	FILE *fp2=fopen("data.txt","a");
	if(mode == 2)
		
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			fprintf(fp2,"%s\n", str2);
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

}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}
//imain function
int main()
{
	len = 0;
	mode = 0;
	str[0]= 0;
	iInitialize(1280, 720, "Street Kombat");
	//Images implimantations
	Menu = iLoadImage("images\\1Menu.png");
	Background = iLoadImage("images\\1Background.jpg");
	Back = iLoadImage("images\\Back.png");
	Ins = iLoadImage("images\\3Instructions.png");
	Score = iLoadImage("images\\Scoreboard.png");
	Hero = iLoadImage("images\\0.png");
	About = iLoadImage("images\\About.png");
	Credits = iLoadImage("images\\Credits.png");
	iStart();

	return 0;
}

