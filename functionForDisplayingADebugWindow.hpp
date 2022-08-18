
void displayDebugWindow(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for(int i=0;i<std::size(square);i++){
		drawPolygons(SCREEN_SIZE_X/2 + square[i][0],SCREEN_SIZE_Y/2 + square[i][1]);
	}
	drawPolygons(SCREEN_SIZE_X/2 + playerPos[0],SCREEN_SIZE_Y/2 +playerPos[1]);

	//draw the line of sight
	glBegin(GL_LINES);
	glVertex2f(SCREEN_SIZE_X/2+playerPos[0],SCREEN_SIZE_Y/2+playerPos[1]);
	glVertex2f(SCREEN_SIZE_X/2+playerPos[0]+sin(playerRot[0])*20,SCREEN_SIZE_Y/2+playerPos[1]+cos(playerRot[1])*20);
	glEnd();
	
	
	float angleToPoint;
	if(square[8][1]-playerPos[1]>=0){
		angleToPoint = atan((square[8][0]-playerPos[0])/(square[8][1]-playerPos[1]));
	}
	else{
		angleToPoint = atan((square[8][0]-playerPos[0])/(square[8][1]-playerPos[1]))+PI;
	}
	//draw a debug line
	glBegin(GL_LINES);
	glVertex2f(SCREEN_SIZE_X/2+playerPos[0],SCREEN_SIZE_Y/2+playerPos[1]);
	glVertex2f(SCREEN_SIZE_X/2+playerPos[0]+sin(angleToPoint)*30,SCREEN_SIZE_Y/2+playerPos[1]+cos(angleToPoint)*30);
	glEnd();

	glutPostRedisplay();
	glutSwapBuffers();
}