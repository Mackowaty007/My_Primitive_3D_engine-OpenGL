#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700
#define PI 3.1415926535
#define POINT_SIZE 3
#define LINE_WIDTH 4
//smaller number - more FOV
#define FOV 200
#define DRAWING_DISTANCE 100
//game constants
#define DEFAULT_PLAYER_SPEED 0.1
#define DEFAULT_RUNNING_SPEED 0.5

//#define DRAW_VERTECIES
//#define DRAW_LINES
//#define DRAW_FACES

//#define DRAW_VERTECIES_FIXED
//#define DRAW_LINES_FIXED
#define DRAW_FACES_FIXED

float playerPos[3] = {0,0,0};
float cameraPos[3] = {0,0,0};
float playerRot[2] = {0,PI/2};
float playerSpeed = DEFAULT_PLAYER_SPEED;
float rotSpeed = 0.1;

#include "shape.h"

typedef struct{
	int w,a,d,s,e,q,j,l,i,k;
}ButtonKeys; ButtonKeys Keys;

#include "generalPurpouseFunctions.hpp"
#include "functionForDIsplayingTheMainWindow.hpp"

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	glutInitWindowPosition( glutGet(GLUT_SCREEN_WIDTH)/2-SCREEN_WIDTH/2 ,glutGet(GLUT_SCREEN_HEIGHT)/2-SCREEN_HEIGHT/2 );
	int windowMain = glutCreateWindow("3d game");
	gluOrtho2D(0,SCREEN_WIDTH,SCREEN_HEIGHT,0);

	init();
	setTheObjectScale();
	decrementAllTheVerteciesValuesByOne();

	glutSetWindow(windowMain);
	glutDisplayFunc(display);
	//glutReshapeFunc(resize);
	glutKeyboardFunc(ButtonDown);
	glutKeyboardUpFunc(ButtonUp);
	//glutSpecialFunc(special);
	glutMainLoop();
}
