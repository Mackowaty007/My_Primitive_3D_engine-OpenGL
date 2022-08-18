#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

#define SCREEN_SIZE_X 700
#define SCREEN_SIZE_Y 700
#define POINT_SIZE 4
#define PI 3.1415926535

float playerPos[3] = {0,0,0};
float playerRot[2] = {0,PI/2};
float playerSpeed = 1;

float square[9][3] = {{-10,-10,-10},{-10,-10,10},{-10,10,-10},{-10,10,10},{10,-10,-10},{10,-10,10},{10,10,-10},{10,10,10},{0,0,0}};

typedef struct{
	int w,a,d,s,e,q,j,l,i,k;
}ButtonKeys; ButtonKeys Keys;


#include "generalPurpouseFunctions.hpp"
#include "functionForDIsplayingTheMainWindow.hpp"
#include "functionForDisplayingADebugWindow.hpp"


void init(){
	glClearColor(0.3,0.5,0.4,0);
	glColor3f(0.6,1.0,0.0);
}


void ButtonDown(unsigned char key,int x,int y)
{
 if(key=='a'){ Keys.a=1;} 	
 if(key=='d'){ Keys.d=1;} 
 if(key=='w'){ Keys.w=1;}
 if(key=='s'){ Keys.s=1;}
 if(key=='e'){ Keys.e=1;}
 if(key=='q'){ Keys.q=1;}
 if(key=='j'){ Keys.j=1;}
 if(key=='l'){ Keys.l=1;}
 if(key=='i'){ Keys.i=1;}
 if(key=='k'){ Keys.k=1;}
 glutPostRedisplay();
}

void ButtonUp(unsigned char key,int x,int y)
{
 if(key=='a'){ Keys.a=0;} 	
 if(key=='d'){ Keys.d=0;} 
 if(key=='w'){ Keys.w=0;}
 if(key=='s'){ Keys.s=0;}
 if(key=='e'){ Keys.e=0;}
 if(key=='q'){ Keys.q=0;}
 if(key=='j'){ Keys.j=0;}
 if(key=='l'){ Keys.l=0;}
 if(key=='i'){ Keys.i=0;}
 if(key=='k'){ Keys.k=0;}
 glutPostRedisplay();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(SCREEN_SIZE_X,SCREEN_SIZE_Y);
	glutInitWindowPosition( glutGet(GLUT_SCREEN_WIDTH)/2-SCREEN_SIZE_X/2 ,glutGet(GLUT_SCREEN_HEIGHT)/2-SCREEN_SIZE_Y/2 );
	int windowMain = glutCreateWindow("platformer game");
	gluOrtho2D(0,SCREEN_SIZE_X,SCREEN_SIZE_Y,0);

	glutInitWindowSize(SCREEN_SIZE_X,SCREEN_SIZE_Y);
	glutInitWindowPosition( glutGet(GLUT_SCREEN_WIDTH)/2-SCREEN_SIZE_X/2 ,glutGet(GLUT_SCREEN_HEIGHT)/2-SCREEN_SIZE_Y/2 );
	int windowDebug = glutCreateWindow("debug Window");
	gluOrtho2D(0,SCREEN_SIZE_X,SCREEN_SIZE_Y,0);

	init();

	glutSetWindow(windowMain);
	glutDisplayFunc(display);
	glutSetWindow(windowDebug);
	glutDisplayFunc(displayDebugWindow);
	//glutReshapeFunc(resize);
	glutKeyboardFunc(ButtonDown);
	glutKeyboardUpFunc(ButtonUp);
	glutMainLoop();
}
