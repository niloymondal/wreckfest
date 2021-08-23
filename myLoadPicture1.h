#ifndef myLoadPicture1_H_INCLUDED
#define myLoadPicture1_H_INCLUDED

int image1, image2, image3,image4, image5, image6, image7, image8, image9, image10, image11,image12,image13,image14,image15,image16,image17,image18,image19,image20,image21,image22,image23,image24,image25,image26,image27,image28;

void LoadImage()
{
	image3 = iLoadImage("images\\Highscore 3.jpg");
	image2 = iLoadImage("images\\Main menu.jpg");
	image1 = iLoadImage("images\\StartPage1.jpg");
	image4 = iLoadImage("images\\GameOver1.jpg");

	
	image5 = iLoadImage("images\\Lawn3.png");
	image6 = iLoadImage("images\\Road3.png");
	image7 = iLoadImage("images\\Lawn3.png");
	image8 = iLoadImage("images\\Car R.png");
	image9 = iLoadImage("images\\Car B.png");
	image10 = iLoadImage("images\\LifeBarBlue.png");
	image11 = iLoadImage("images\\LifeBarRed.png");
	image12 = iLoadImage("images\\Man1.png");
	image28 = iLoadImage("images\\Missile.png");
	image13 = iLoadImage("images\\Finish3.png");
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
	image27=iLoadImage("images\\Highscore 3.jpg");
}

#endif // myLoadPicture_H_INCLUDED