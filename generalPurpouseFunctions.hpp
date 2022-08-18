void drawPolygons(float positionOnScreen[2]){
	glBegin(GL_POLYGON);
	glVertex2f(positionOnScreen[0]-POINT_SIZE/2,positionOnScreen[1]-POINT_SIZE/2);
	glVertex2f(positionOnScreen[0]+POINT_SIZE/2,positionOnScreen[1]-POINT_SIZE/2);
	glVertex2f(positionOnScreen[0]+POINT_SIZE/2,positionOnScreen[1]+POINT_SIZE/2);
	glVertex2f(positionOnScreen[0]-POINT_SIZE/2,positionOnScreen[1]+POINT_SIZE/2);
	glEnd();
}

void drawPolygons(float x,float y){
	glBegin(GL_POLYGON);
	glVertex2f(x-POINT_SIZE/2,y-POINT_SIZE/2);
	glVertex2f(x+POINT_SIZE/2,y-POINT_SIZE/2);
	glVertex2f(x+POINT_SIZE/2,y+POINT_SIZE/2);
	glVertex2f(x-POINT_SIZE/2,y+POINT_SIZE/2);
	glEnd();
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