void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//keyboard interactions(WHY IS THIS IN THE DISPLAY FUNCTION? don't ask!)
	if (Keys.w==1){
		playerPos[0] += sin(playerRot[0])*playerSpeed;
		//playerPos[1] += cos(playerRot[1])*playerSpeed;
		playerPos[2] += cos(playerRot[0])*playerSpeed;
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
		playerPos[1]++;
	}
	if (Keys.q==1){
		playerPos[1]--;
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

	float angleToPoint[2];
	float angleDifference[2];
	for(int i=0;i<std::size(square);i++){
		//calculate the angle to a square verticy
		if(square[i][2]-playerPos[2]>=0){
			angleToPoint[0] = atan((square[i][0]-playerPos[0])/(square[i][2]-playerPos[2]));
		}
		else{
			angleToPoint[0] = atan((square[i][0]-playerPos[0])/(square[i][2]-playerPos[2]))+PI;
		}

        if(square[i][1]-playerPos[1]>=0){
            angleToPoint[1] = atan((square[i][0]-playerPos[0])/(square[i][1]-playerPos[1]));
        }
        else{
            angleToPoint[1] = atan((square[i][0]-playerPos[0])/(square[i][1]-playerPos[1]))+PI;
        }
		//std::cout<<angleToPoint[1]<<std::endl;

		while(playerRot[0]>PI){
			playerRot[0] -= 2*PI;
		}
		while(playerRot[0]<-PI){
			playerRot[0] += 2*PI;
		}
		while(angleToPoint[0]>PI){
			angleToPoint[0] -= 2*PI;
		}
		while(angleToPoint[0]<-PI){
			angleToPoint[0] += 2*PI;
		}
		angleDifference[0] = playerRot[0]-angleToPoint[0];
		while(angleDifference[0]>PI){
			angleDifference[0] -= 2*PI;
		}
		while(angleDifference[0]<-PI){
			angleDifference[0] += 2*PI;
		}

	
		//std::cout << "x= " << playerPos[0] << " y= " << playerPos[2]<< " rotation = " << playerRot[0] << std::endl;
		
		if(i==8){
			std::cout<< "playerRot  " << playerRot[0] << " angle = " << angleToPoint[0] << std::endl;
			std::cout<< "rotation difference = " << angleDifference[0] << std::endl;
		}
		
		//complicated projection math
		drawPolygons(
			SCREEN_SIZE_X/2 + (angleDifference[0])*SCREEN_SIZE_X,
			SCREEN_SIZE_Y/2// - (angleToPoint[1]-playerRot[1])*SCREEN_SIZE_Y
		);
	}
	//exit(0);
	glutPostRedisplay();
	glutSwapBuffers();
}