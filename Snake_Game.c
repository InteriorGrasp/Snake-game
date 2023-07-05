#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, g, height = 12, width = 50;
int gameover, score;
int x, y, fruitx, fruity, flag, bonusx, bonusy;

void program()
{
	gameover=0;

	x=width/2;
	y=height/2;

	label1:
	fruitx=rand() % 50;
	if(fruitx==0)
	goto label1;

	label2:
	fruity=rand() %12;
	if(fruity == 0)
	goto label2;

	bonus1:
	bonusx=rand() % 50;
	if(bonusx == 0)
		goto bonus1;

	bonus2:
	bonusy=rand() % 12;
	if(bonusy == 0)
		goto bonus2;

	score = 0;
}

void screen()
{
	int ch=0;
	system("cls");
    for(i=0;i<=height;i++){
        for(j=0;j<=width;j++){
            if(i==0 || i == height||j==0||j == width){
                printf("I");
            }else{
				if(i == fruity && j == fruitx){
					printf("*");
				}else if(i == y && j == x){
					printf("O");
				}else if(i == bonusy && j == bonusx){
					if(score % 30 ==0){
					printf("o");
					}else{
						printf(" ");
											
					}
				}else{
					printf(" ");
				}                
            }
        }
        printf("\n");
    }
	
	printf("score = %d\n", score);
	printf("press X to quit the game");
}

void control()
{
	if(kbhit()){
		switch(getch()){
			case 'a':
				flag = 1;
				break;
			case 's':
				flag = 2;
				break;
			case 'd':
				flag = 3;
				break;
			case 'w':
				flag = 4;
				break;
			case 'x':
				gameover=1;
				break;
		}
	}
}

void logic()
{
	switch (flag){
	case 1:
		x--;
		break;
	case 2:
		y++;
		break;
	case 3:
		x++;
		break;
	case 4:		
		y--;
		break;
	default:
		break;
	}

	if (x <= 0 || y >= height || y <= 0 || x >= width)
		gameover = 1;

	if (x == fruitx && y == fruity){
	label3:
		fruitx = rand() % 50;
		if (fruitx == 0)
			goto label3;

	label4:
		fruity = rand() % 12;
		if (fruity == 0)
			goto label4;
		score += 5;
	}
	if(x == bonusx && y == bonusy){	
		bonus3:
			bonusx = rand() % 50;
			if(bonusx == 0 || bonusx == fruitx)
				goto bonus3;

		bonus4:
			bonusy = rand() % 12;
			if(bonusy == 0 || bonusy == fruity)
				goto bonus4;
			score+=10;
	}
}

void main()
{
	program();

	while (!gameover) {
		screen();
		control();
		logic();
	}
}