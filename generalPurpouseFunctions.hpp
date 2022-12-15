void init(){
	glClearColor(0.0,0.1,0.1,0);

	glEnable(GL_CULL_FACE);
  	glCullFace(GL_BACK);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2, 2, -1.5, 1.5, 1, 40);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, 0);
}

float cutANumber(float number,float max,float min){
	if (number>max){
		number=max;
	}
	if (number<min){
		number=min;
	}
	return number;
}

void drawSquare(float positionOnScreen[2]){
	glBegin(GL_POLYGON);
	glVertex2f(positionOnScreen[0]-POINT_SIZE/2,positionOnScreen[1]-POINT_SIZE/2);
	glVertex2f(positionOnScreen[0]+POINT_SIZE/2,positionOnScreen[1]-POINT_SIZE/2);
	glVertex2f(positionOnScreen[0]+POINT_SIZE/2,positionOnScreen[1]+POINT_SIZE/2);
	glVertex2f(positionOnScreen[0]-POINT_SIZE/2,positionOnScreen[1]+POINT_SIZE/2);
	glEnd();
}

void drawSquare(float x,float y){
	glBegin(GL_POLYGON);
	glVertex2f(x-POINT_SIZE/2,y-POINT_SIZE/2);
	glVertex2f(x+POINT_SIZE/2,y-POINT_SIZE/2);
	glVertex2f(x+POINT_SIZE/2,y+POINT_SIZE/2);
	glVertex2f(x-POINT_SIZE/2,y+POINT_SIZE/2);
	glEnd();
}

void drawLine(float x1,float y1,float x2,float y2){
	glBegin(GL_POLYGON);
	glVertex2f(x1-LINE_WIDTH/2,y1);
	glVertex2f(x1+LINE_WIDTH/2,y1);
	glVertex2f(x2-LINE_WIDTH/2,y2);
	glVertex2f(x2+LINE_WIDTH/2,y2);
	glEnd();
}

//polygon with 3 sides
void drawPolygon(float x1,float y1,float x2,float y2,float x3,float y3){
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glEnd();
}
//polygon with 4 sides
void drawPolygon(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
}

//polygon with 3 sides but in 3D
void drawPolygon3D(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3){
	glBegin(GL_POLYGON);
	glVertex3f(x1,y1,z1);
	glVertex3f(x2,y2,z2);
	glVertex3f(x3,y3,z3);
	glEnd();
}
//polygon with 4 sides but in 3D
void drawPolygon3D(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4){
	glBegin(GL_POLYGON);
	glVertex3f(x1,y1,z1);
	glVertex3f(x2,y2,z2);
	glVertex3f(x3,y3,z3);
	glVertex3f(x4,y4,z4);
	glEnd();
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
/*
void special(int,int ,int){
	if (Keys.w==1){
		playerPos[0] += sin(playerRot[0])*playerSpeed;
		//playerPos[1] += cos(playerRot[1])*playerSpeed;
		playerPos[2] += cos(playerRot[0])*playerSpeed;
		printf("works!");
	}
	if (Keys.s==1){
		playerPos[0] -= sin(playerRot[0])*playerSpeed;
		//playerPos[1] -= cos(playerRot[1])*playerSpeed;
		playerPos[2] -= cos(playerRot[0])*playerSpeed;
	}
	if (Keys.a==1){
		playerPos[0] += sin(playerRot[0]+PI/2)*playerSpeed;
		playerPos[2] += cos(playerRot[0]+PI/2)*playerSpeed;
	}
	if (Keys.d==1){
		playerPos[0] -= sin(playerRot[0]+PI/2)*playerSpeed;
		playerPos[2] -= cos(playerRot[0]+PI/2)*playerSpeed;
	}
	if (Keys.e==1){
		playerPos[1] += playerSpeed;
	}
	if (Keys.q==1){
		playerPos[1] -= playerSpeed;
	}
	if (Keys.j==1){
		playerRot[0]+=0.1f;
	}
	if (Keys.l==1){
		playerRot[0]-=0.1f;
	}
	if (Keys.i==1){
		playerRot[1]+=0.1f;
	}
	if (Keys.k==1){
		playerRot[1]-=0.1f;
	}
	playerRot[1] = cutANumber(playerRot[1],PI,0);

	if(playerRot[0]>PI){
		playerRot[0] -= 2*PI;
	}
	if(playerRot[0]<-PI){
		playerRot[0] += 2*PI;
	}
	if(playerRot[1]>PI){
		playerRot[1] -= 2*PI;
	}
	if(playerRot[1]<0){
		playerRot[1] += 2*PI;
	}
	glutPostRedisplay();
}*/

void setTheObjectScale(){
	for (int i=0;i<LEN(vertecies);i++){
		for (int c=0;c<LEN(vertecies[0]);c++){
			vertecies[i][c] *= -100;
		}
	}
}

//should have done this in the converter file but text operations are hard
void decrementAllTheVerteciesValuesByOne(){
	for (int i=0;i<LEN(polygons);i++){
		for (int c=0;c<LEN(polygons[0]);c++){
			polygons[i][c] --;
		}
	}
}