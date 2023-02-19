//

//
//  Created by Дмитрий on 22.12.2022.
//
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
bool gameOver;
const int WIDTH = 40;  
const int HEIGHT = 30; 
int carx[16], cary[16], plx[8], ply[8];
int car1x=5, car1y=-10,  car2x=WIDTH-5, car2y=-10, playerX, playerY;
int score=5;  
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; 
eDirection dir;
void setup() {
    gameOver=false;
    dir = STOP;
   playerX = WIDTH/2+3;
   playerY = HEIGHT/2;    
}
 

void draw() {
    system("cls");
    int n=0, m=0, p=8, c=8, k=0, t=0;
    for (int i=0;  i<WIDTH; i++)
        cout<<"#";
        cout<<endl;

    for (int i=0; i<HEIGHT; i++){
        for (int j=0; j<WIDTH; j++){
		    if (i%2==0 && j==WIDTH/2){
		    	cout<<"|";
			}
              else if (j==0 || j==WIDTH-1 ){
                cout<<"#";
            } else if ((i==car1y && j==car1x)||(i==car1y && j==car1x+1)||(i==car1y && j==car1x-1)||
			(i==car1y+1 && j==car1x)||(i==car1y+2 && j==car1x)||(i==car1y+2 && j==car1x+1)||(i==car1y+2 && j==car1x-1)||(i==car1y+3 && j==car1x)){
				cout<<0;
				carx[n]=j;
				cary[m]=i;
				n++;
				m++;
            } else if ((i==car2y && j==car2x)||(i==car2y && j==car2x+1)||(i==car2y && j==car2x-1)||(i==car2y+1 && j==car2x)||(i==car2y+2 && j==car2x)||
			(i==car2y+2 && j==car2x+1)||(i==car2y+2 && j==car2x-1)||(i==car2y+3 && j==car2x)){    
        		 cout<<"0";
        		 carx[p]=j;
        	   	cary[c]=i;
        		 p++;
        		 c++;
            } else if ((i==playerY && j==playerX)||(i==playerY+1 && j==playerX)||(i==playerY+1 && j==playerX+1)||(i==playerY+1 && j==playerX-1)||(i==playerY+2 && j==playerX)||
			(i==playerY+3 && j==playerX)||(i==playerY+3 && j==playerX+1)||(i==playerY+3 && j==playerX-1)){

				cout<<"0";
		 		plx[k]=j;
				ply[t]=i;
				k++;
				t++;	
	    	}  
			else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for (int i=0;  i<WIDTH; i++)
        cout<<"#";
        cout<<endl;
    cout<<"SCORE :  "<<score<<endl;
}

void input() {
    if (_kbhit ()){
        switch (_getch ())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
               gameOver = true;
                break;
            case 'q':
            	dir = STOP;
            	break;
        }
    } 
    
}
   
void logic() {
    switch (dir)
    {
        case LEFT:
            playerX--;
            break;
        case RIGHT:
            playerX++;
            break;
        case UP:
            playerY--;
            break;
        case DOWN:
            playerY++;
            break;
    }
   
    for (int i=0; i<16; i++){
    
		for (int j=0; j<8; j++){
			if (carx[i]==plx[j] && cary[i]==ply[j]){
				score--;		
			}
		}
	}
				
    if (playerX > WIDTH-2 || playerX<1 || playerY+4 > HEIGHT || playerY<0 || score < 0){
	    gameOver = true;
		}

        car1y++;
        car2y++;
     if (car1y==HEIGHT){
		score++;;
        car1y=-12;
        car1x=rand()%HEIGHT-1;
        	if (car1x<2){
        		car1x=2;
			}
       
    } 
    if (car2y==HEIGHT){
		score++;
        car2y=-5;
        car2x=rand()%HEIGHT-1;
        	if (car2x<2){
        		car2x=2;
			}
    } 
	
}
 

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        }   
}
