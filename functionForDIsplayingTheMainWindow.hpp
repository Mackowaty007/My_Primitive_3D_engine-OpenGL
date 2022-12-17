void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Input();

	cameraPos[0] = playerPos[0];
	cameraPos[1] = playerPos[1];
	cameraPos[2] = playerPos[2];

	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2],
            cameraPos[0]+sin(playerRot[0]), cameraPos[1]-cos(playerRot[1]), cameraPos[2]+cos(playerRot[0]),
            0.0, 1.0, 0.0);

	//draw vertexes
    //declaring usefull variables (they calculate the angle from the players view to vertexes)
    float angleToPoint[4][2];
	float angleDifference[4][2];
    //do this for every vertex of the square

	//calculate all the angles
    //do this for every vertex of the square
	for(int i=0;i<LEN(polygons);i++){
		unsigned int currentVertecie;
		unsigned short int howManyPoinstToCalculate = 3;
		//check if you should calculate 4 or 3 vertecies
		if (polygons[i][3] != -1){
			howManyPoinstToCalculate = 4;
		}
		else{
			howManyPoinstToCalculate = 3;
		}
		//calculate the angle tocalculate the angle from the center of the screen to the vertex a vertecies verticy
		for(currentVertecie=0;currentVertecie<howManyPoinstToCalculate;currentVertecie++){
			if(vertecies[polygons[i][currentVertecie]][1]-cameraPos[1]>=0){
				angleToPoint[currentVertecie][1] = atan((sqrt(pow(vertecies[polygons[i][currentVertecie]][2]-cameraPos[2],2)+pow(vertecies[polygons[i][currentVertecie]][0]-cameraPos[0],2)))/(vertecies[polygons[i][currentVertecie]][1]-cameraPos[1]));
			}
			else{
				angleToPoint[currentVertecie][1] = atan((sqrt(pow(vertecies[polygons[i][currentVertecie]][2]-cameraPos[2],2)+pow(vertecies[polygons[i][currentVertecie]][0]-cameraPos[0],2)))/(vertecies[polygons[i][currentVertecie]][1]-cameraPos[1]))+PI;
			}
			if(vertecies[polygons[i][currentVertecie]][2]-cameraPos[2]>=0){
				angleToPoint[currentVertecie][0] = atan((vertecies[polygons[i][currentVertecie]][0]-cameraPos[0])/(vertecies[polygons[i][currentVertecie]][2]-cameraPos[2]));
			}
			else{
				angleToPoint[currentVertecie][0] = atan((vertecies[polygons[i][currentVertecie]][0]-cameraPos[0])/(vertecies[polygons[i][currentVertecie]][2]-cameraPos[2]))+PI;
			}

			if(angleToPoint[currentVertecie][0]>PI){
				angleToPoint[currentVertecie][0] -= 2*PI;
			}
			if(angleToPoint[currentVertecie][0]<-PI){
				angleToPoint[currentVertecie][0] += 2*PI;
			}
			if(angleToPoint[currentVertecie][1]>PI){
				angleToPoint[currentVertecie][1] -= 2*PI;
			}
			if(angleToPoint[currentVertecie][1]<-PI){
				angleToPoint[currentVertecie][1] += 2*PI;
			}
			angleDifference[currentVertecie][0] = playerRot[0]-angleToPoint[currentVertecie][0];
			if(angleDifference[currentVertecie][0]>PI){
				angleDifference[currentVertecie][0] -= 2*PI;
			}
			if(angleDifference[currentVertecie][0]<-PI){
				angleDifference[currentVertecie][0] += 2*PI;
			}
			angleDifference[currentVertecie][1] = playerRot[1]-angleToPoint[currentVertecie][1];
			if(angleDifference[currentVertecie][1]>PI){
				angleDifference[currentVertecie][1] -= 2*PI;
			}
			if(angleDifference[currentVertecie][1]<-PI){
				angleDifference[currentVertecie][1] += 2*PI;
			}
		}

		#ifdef DRAW_FACES_FIXED
		float distanceToPolygon = -sqrt(pow(cameraPos[0]-vertecies[polygons[i][currentVertecie]][0],2) + pow(cameraPos[1]-vertecies[polygons[i][currentVertecie]][1],2) + pow(cameraPos[2]-vertecies[polygons[i][currentVertecie]][2],2));
		//fun with colors
		//glColor3f(i/(float)LEN(polygons),i/(float)LEN(polygons),i/(float)LEN(polygons));
		glColor3f(1+distanceToPolygon/DRAWING_DISTANCE,1+distanceToPolygon/DRAWING_DISTANCE,1+distanceToPolygon/DRAWING_DISTANCE);
		//if the polygon has 4 sides draw another triangle
		if (polygons[i][3] != -1){
			drawPolygon3D(
				vertecies[polygons[i][0]][0],vertecies[polygons[i][0]][1],vertecies[polygons[i][0]][2],
				vertecies[polygons[i][1]][0],vertecies[polygons[i][1]][1],vertecies[polygons[i][1]][2],
				vertecies[polygons[i][2]][0],vertecies[polygons[i][2]][1],vertecies[polygons[i][2]][2],
				vertecies[polygons[i][3]][0],vertecies[polygons[i][3]][1],vertecies[polygons[i][3]][2]
			);
		}
		else{
			drawPolygon3D(
				vertecies[polygons[i][0]][0],vertecies[polygons[i][0]][1],vertecies[polygons[i][0]][2],
				vertecies[polygons[i][1]][0],vertecies[polygons[i][1]][1],vertecies[polygons[i][1]][2],
				vertecies[polygons[i][2]][0],vertecies[polygons[i][2]][1],vertecies[polygons[i][2]][2]
			);
		}
		#endif

		#ifdef DRAW_FACES
		//check if the face should be culled or not
		double result = atan2(angleDifference[2][1] - angleDifference[0][1], angleDifference[2][0] - angleDifference[0][0]) - atan2(angleDifference[1][1] - angleDifference[0][1], angleDifference[1][0] - angleDifference[0][0]);

		//makes it impossible for the result to be negative
		if (result < 0){
			result += 2*PI;
		}

		if(result < 0 || result > PI){
			//check the distance to a polygon
			float distanceToPolygon = -sqrt(pow(cameraPos[0]-vertecies[polygons[i][currentVertecie]][0],2) + pow(cameraPos[1]-vertecies[polygons[i][currentVertecie]][1],2) + pow(cameraPos[2]-vertecies[polygons[i][currentVertecie]][2],2));

			//fun with colors
			//glColor3f(i/(float)LEN(polygons),i/(float)LEN(polygons),i/(float)LEN(polygons));
			//glColor3f(1+distanceToPolygon/DRAWING_DISTANCE,1+distanceToPolygon/DRAWING_DISTANCE,1+distanceToPolygon/DRAWING_DISTANCE);

			//if the polygon has 4 sides draw another triangle
			if (polygons[i][3] != -1){
				drawPolygon(
					SCREEN_WIDTH /2 + (angleDifference[0][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_HEIGHT/2 + (angleDifference[0][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_WIDTH /2 + (angleDifference[1][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_HEIGHT/2 + (angleDifference[1][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_WIDTH /2 + (angleDifference[2][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_HEIGHT/2 + (angleDifference[2][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_WIDTH /2 + (angleDifference[3][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_HEIGHT/2 + (angleDifference[3][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV
				);
			}
			else{
				drawPolygon(
					SCREEN_WIDTH /2 + (angleDifference[0][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_HEIGHT/2 + (angleDifference[0][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_WIDTH /2 + (angleDifference[1][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_HEIGHT/2 + (angleDifference[1][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_WIDTH /2 + (angleDifference[2][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
					SCREEN_HEIGHT/2 + (angleDifference[2][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV
				);
			}
		}
		#endif

		#ifdef DRAW_LINES
		glColor3f(0.1,0.4,0.2);
		drawLine(
		SCREEN_WIDTH /2 + (angleDifference[0][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_HEIGHT/2 + (angleDifference[0][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_WIDTH /2 + (angleDifference[1][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_HEIGHT/2 + (angleDifference[1][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV);
		drawLine(
		SCREEN_WIDTH /2 + (angleDifference[2][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_HEIGHT/2 + (angleDifference[2][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_WIDTH /2 + (angleDifference[1][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_HEIGHT/2 + (angleDifference[1][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV);
		drawLine(
		SCREEN_WIDTH /2 + (angleDifference[0][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_HEIGHT/2 + (angleDifference[0][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_WIDTH /2 + (angleDifference[2][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
		SCREEN_HEIGHT/2 + (angleDifference[2][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV);
		//draw additional lines if a face has 4 corners
		if (polygons[i][3] != -1){
			drawLine(
			SCREEN_WIDTH /2 + (angleDifference[3][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
			SCREEN_HEIGHT/2 + (angleDifference[3][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
			SCREEN_WIDTH /2 + (angleDifference[2][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
			SCREEN_HEIGHT/2 + (angleDifference[2][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV);
		}
		#endif

		#ifdef DRAW_VERTECIES
		glColor3f(0.1,0.2,0.5);
		drawSquare(
			SCREEN_WIDTH/2  + (angleDifference[0][0])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV,
			SCREEN_HEIGHT/2 + (angleDifference[0][1])*(SCREEN_WIDTH/SCREEN_HEIGHT)*FOV);
		#endif
	}

	glutPostRedisplay();
	glutSwapBuffers();
}