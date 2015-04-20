#include "drawHouses.h"

void drawCylinder(GLuint texSet[], float r, float length) {
	int M_PI = 3.14159;
	//float length = 4.0;
	//float r = 0.8;
	float n= 10.0;
	float count = 0;
	float x = 0;

	glBindTexture(GL_TEXTURE_2D, texSet[2]);
	for(int i = 0; i <= 2*n; i++) {
		glBegin(GL_POLYGON);
			//glNormal3d(cos((i+0.5)*M_PI/n), sin((i+0.5)*M_PI/n), 0);
			
			glTexCoord2d(count, x);
			glVertex3d(r*cos(i*M_PI/n), r*sin(i*M_PI/n), 0);
			glTexCoord2d(count, x+1/n);
			glVertex3d(r*cos((i+1)*M_PI/n), r*sin((i+1)*M_PI/n), 0);

			glTexCoord2d(count +1, x+1/n);
			glVertex3d(r*cos((i+1)*M_PI/n), r*sin((i+1)*M_PI/n), length);
			glTexCoord2d(count +1, x);
			glVertex3d(r*cos(i*M_PI/n), r*sin(i*M_PI/n), length);
		glEnd();
		x += 1/n;
	}
}

void drawTallCuboid(GLuint texSet[], float length, float height) {
	glBindTexture(GL_TEXTURE_2D, texSet[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-length, 0, -length);
	glVertex3f( length, 0, -length);
	glVertex3f( length, 0,  length);
	glVertex3f(-length, 0,  length);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2d(0,0);
	glVertex3f(-length, height, -length);
	glTexCoord2d(1,0);
	glVertex3f( length, height, -length);
	glTexCoord2d(1,1);
	glVertex3f( length, height,  length);
	glTexCoord2d(0,1);
	glVertex3f(-length, height,  length);
	glEnd();

	glPushMatrix();
	for(int i = 0; i < 4 ; i++) {
		glRotatef(90, 0, 1, 0);
		glBegin(GL_POLYGON);
		glTexCoord2d(0,0);
		glVertex3f(-length, 0, -length);
		glTexCoord2d(1,0);
		glVertex3f(length, 0, -length);
		glTexCoord2d(1,1);
		glVertex3f(length, height, -length);
		glTexCoord2d(0,1);
		glVertex3f(-length, height, -length);
		glEnd();
	}
	glPopMatrix();
}

void drawLongCuboid(GLuint texSet[], int set, float length, float width, float height) {
	glBindTexture(GL_TEXTURE_2D, texSet[set]);
	glBegin(GL_POLYGON);
	glVertex3f(-length/2, 0, -width/2);
	glVertex3f( length/2, 0, -width/2);
	glVertex3f( length/2, 0,  width/2);
	glVertex3f(-length/2, 0,  width/2);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2d(0,0);
	glVertex3f(-length/2, height, -width/2);
	glTexCoord2d(1,0);
	glVertex3f( length/2, height, -width/2);
	glTexCoord2d(1,1);
	glVertex3f( length/2, height,  width/2);
	glTexCoord2d(0,1);
	glVertex3f(-length/2, height,  width/2);
	glEnd();

	glPushMatrix();
	for(int i = 0; i < 2 ; i++) {
		glRotatef(180, 0, 1, 0);
		glBegin(GL_POLYGON);
		glTexCoord2d(0,0);
		glVertex3f(-length/2, 0, -width/2);
		glTexCoord2d(1,0);
		glVertex3f(length/2, 0, -width/2);
		glTexCoord2d(1,1);
		glVertex3f(length/2, height, -width/2);
		glTexCoord2d(0,1);
		glVertex3f(-length/2, height, -width/2);
		glEnd();
	}
	glPopMatrix();
	glPushMatrix();
	for(int i = 0; i < 2 ; i++) {
		glRotatef(180, 0, 1, 0);
		glBegin(GL_POLYGON);
		glTexCoord2d(0,0);
		glVertex3f(-length/2, 0, width/2);
		glTexCoord2d(1,0);
		glVertex3f(-length/2, 0, -width/2);
		glTexCoord2d(1,1);
		glVertex3f(-length/2, height, -width/2);
		glTexCoord2d(0,1);
		glVertex3f(-length/2, height, width/2);
		glEnd();
	}
	glPopMatrix();
}

void drawRectangle(GLuint texSet[], int set, float width, float height) {
	glBindTexture(GL_TEXTURE_2D, texSet[set]);
	glPushMatrix();
	glBegin(GL_POLYGON);
		glTexCoord2d(0,1);
		glVertex3f(-width/2,0,0);
		glTexCoord2d(0,0);
		glVertex3f(width/2,0,0);
		glTexCoord2d(1,0);
		glVertex3f(width/2,height,0);
		glTexCoord2d(1,1);
		glVertex3f(-width/2,height,0);
	glEnd();

	glPopMatrix();

}

void drawWindow(GLuint texSet[], int set, float width, float height) {
	glBindTexture(GL_TEXTURE_2D, texSet[set]);
	glPushMatrix();
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);
		glVertex3f(-width/2,0,0);
		glTexCoord2d(1,0);
		glVertex3f(width/2,0,0);
		glTexCoord2d(1,1);
		glVertex3f(width/2,height,0);
		glTexCoord2d(0,1);
		glVertex3f(-width/2,height,0);
	glEnd();

	glPopMatrix();

}

void drawRoof(GLuint texSet[]) {
	//main tower
	glPushMatrix();
	glTranslatef(2,0,-1.5);
	drawLongCuboid(texSet,2, 3.4, 3, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,8,-1.5);
	drawLongCuboid(texSet,2, 4.0, 3.5, 0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,8.5,-0.15);
		drawTallCuboid(texSet, 0.45, 0.8);
		glTranslatef(1.55,0,0);
		drawTallCuboid(texSet, 0.45, 0.8);
		glTranslatef(-3.1,0,0);
		drawTallCuboid(texSet, 0.45, 0.8);
		glTranslatef(0,0,-1.3);
		drawTallCuboid(texSet, 0.45, 0.8);
		glTranslatef(0,0,-1.3);
		drawTallCuboid(texSet, 0.45, 0.8);
		glTranslatef(1.55,0,0);
		drawTallCuboid(texSet, 0.45, 0.8);
		glTranslatef(1.55,0,0);
		drawTallCuboid(texSet, 0.45, 0.8);
		glTranslatef(0,0,1.3);
		drawTallCuboid(texSet, 0.45, 0.8);
	glPopMatrix();
	
	/*
	glPushMatrix();
		glTranslatef(1.7,0,0.1);
		drawLongCuboid(texSet, 1, 0.5, 0.5, 8);
		glTranslatef(-3.4,0,0);
		drawLongCuboid(texSet, 1, 0.5, 0.5, 8);
		glTranslatef(0.1,0,-3.2);
		drawLongCuboid(texSet, 1, 0.5, 0.5, 8);
		glTranslatef(3.2,0,0);
		drawLongCuboid(texSet, 1, 0.5, 0.5, 8);
	glPopMatrix();
	*/
	glPushMatrix();
	glTranslatef(-0.10,5,0.1);
	drawWindow(texSet, 28,3,2);
	glPopMatrix();

	//walls
	glPushMatrix();
	glTranslatef(0,0,2.5);
	drawLongCuboid(texSet,2, 5, 1, 3);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0,1,0);
	glTranslatef(0,0,2.5);
	drawLongCuboid(texSet,2, 5, 1, 2.5);
	glPopMatrix();
	glPushMatrix();
	glRotatef(270, 0,1,0);
	glTranslatef(0,0,2.5);
	drawLongCuboid(texSet,2, 5, 1, 2.5);
	glPopMatrix();

	//mini towers
	glPushMatrix();
	glTranslatef(-2.5, 0, 2.5);
	drawTallCuboid(texSet, 0.8,4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5, 0, 2.5);
	drawTallCuboid(texSet, 0.8,4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5, 0, -2.5);
	drawTallCuboid(texSet, 0.8,4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.5, 0, -2.5);
	drawTallCuboid(texSet, 0.8,4);
	glPopMatrix();

	//columns
	glPushMatrix();
	for(int j = 0; j < 4; j++) {
		glRotatef(90,0,1,0);
		glPushMatrix();
		glTranslatef(-3.4, 0, 3.4);
		drawLongCuboid(texSet, 1, 0.2, 0.2, 4);
		glTranslatef(1.8,0,0);
		drawLongCuboid(texSet, 1, 0.2, 0.2, 4);
		glTranslatef(-1.8,0,-1.8);
		drawLongCuboid(texSet, 1, 0.2, 0.2, 4);
		glTranslatef(1.8,0,0);
		drawLongCuboid(texSet, 1, 0.2, 0.2, 4);
		glPopMatrix();
	}
	glPopMatrix();

	//platforms
	glPushMatrix();
	glTranslatef(-2.5, 4, 2.5);
	drawTallCuboid(texSet, 1, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5, 4, 2.5);
	drawTallCuboid(texSet, 1, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.5, 4, -2.5);
	drawTallCuboid(texSet, 1, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5, 4, -2.5);
	drawTallCuboid(texSet, 1, 0.5);
	glPopMatrix();

	//top
	glPushMatrix();
	for(int i = 0; i < 4; i++){
		glRotatef(90, 0,1,0);
		glPushMatrix();
		glTranslatef(-2.5, 4.4, 3.25);
		drawTallCuboid(texSet, 0.2, 0.4);
		glTranslatef(-0.75,0,0);
		drawTallCuboid(texSet, 0.2, 0.4);
		glTranslatef(1.5,0,0);
		drawTallCuboid(texSet, 0.2, 0.4);
		glTranslatef(0,0,-0.75);
		drawTallCuboid(texSet, 0.2, 0.4);
		glTranslatef(0,0,-0.75);
		drawTallCuboid(texSet, 0.2, 0.4);
		glTranslatef(-0.75,0,0);
		drawTallCuboid(texSet, 0.2, 0.4);
		glTranslatef(-0.75,0,0);
		drawTallCuboid(texSet, 0.2, 0.4);
		glTranslatef(0,0,0.75);
		drawTallCuboid(texSet, 0.2, 0.4);
		glPopMatrix();
	}
	glPopMatrix();

	//gate
	glPushMatrix();
	glTranslatef(0,0,3.1);
	drawRectangle(texSet,4, 2, 2);
	glPopMatrix();

	//windows
	glPushMatrix();
	for(int i = 0; i < 4; i++) {
		glRotatef(90, 0,1,0);
		glPushMatrix();
			glTranslatef(-2.5, 2, 3.4);
			drawWindow(texSet, 28, 0.5, 1);
			glTranslatef(-0.85,0,-0.8);
			glRotatef(90,0,1,0);
			drawWindow(texSet, 28, 0.5, 1);
		glPopMatrix();
	}
	glPopMatrix();

}


void drawGround(GLuint texSet[]) {
	glBindTexture(GL_TEXTURE_2D, texSet[9]);
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);
		glVertex3f(-4,0,-4);
		glTexCoord2d(1,0);
		glVertex3f(4,0,-4);
		glTexCoord2d(1,1);
		glVertex3f(4,0,4);
		glTexCoord2d(0,1);
		glVertex3f(-4,0,4);
	glEnd();
}

void drawMyHouse(GLuint texSet[])
{
	//plot dimension
	//x: -4:4
	//y: 0:12
	//z: -4:4

	glEnable(GL_TEXTURE_2D);

	
	
	drawGround(texSet);
	drawRoof(texSet);

	

	glDisable(GL_TEXTURE_2D);



	//bounding volume
	glPushMatrix();
	glTranslatef(0, 6, 0);
	glScalef(8, 12, 8);	
	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(1);
	glPopMatrix();
	
	
}