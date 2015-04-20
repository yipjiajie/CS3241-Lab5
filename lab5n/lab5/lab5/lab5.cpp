#include "drawHouses.h"
#define M_PI 3.141592654

void drawGroundTexture(GLuint texSet[], int index) {
	glBindTexture(GL_TEXTURE_2D, texSet[index]);
	glPushMatrix();
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
	glPopMatrix();
}

void drawCuboid(float length, float width, float height, GLuint texSet[], int index) {
	
	glBindTexture(GL_TEXTURE_2D, texSet[index]);
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


void drawCircle(float radius, float r, float g, float b, float a, GLuint texSet[], int index) {
	const float DEG2RAD = 3.14159/180;
	glBindTexture(GL_TEXTURE_2D, texSet[index]);
	glBegin(GL_TRIANGLE_FAN);
		for(float i = 0; i < 40; i++) {
			float degInRad = i/40.0*360*DEG2RAD;
			glColor4f(r, g, b, a);
			glTexCoord2d(cos(degInRad)/2, sin(degInRad)/2);
			glVertex3d(radius*sin(i*2*M_PI/40), 0, radius*cos(i*2*M_PI/40)); 
		}
	glEnd();
}

void drawCylinder(double radius, double h, float r, float g, float b, float a, float limit, GLuint texSet[], int index)
{
	glPushMatrix();
	int n = 10;
	float t = 0;
	float s = 0; 
	float k = 0.05;
	float k2 = 0.05;
	
	if (radius > 0.6) {
		k = 0.025;
		k2 = 0.09;
	}

	
	glBindTexture(GL_TEXTURE_2D, texSet[index]);
	glColor4f(r, g, b, a);

	for (float i = 0; i < n; i++) {
		s += k;
		for (float j = 0; j < n; j++) {
			t += k;
			if (j/n >= limit) {
				break;
			}

			//float radius1 = radius;
			glBegin(GL_POLYGON);
				glTexCoord2d(s, t);glVertex3d(radius*cos(j*2*M_PI/n), h*(i/n), radius*sin(j*2*M_PI/n));
				glTexCoord2d(s + k, t);glVertex3d(radius*cos(j*2*M_PI/n), h*(i + 1)/n, radius*sin(j*2*M_PI/n));
				glTexCoord2d(s + k, t + k2);glVertex3d(radius*cos((j + 1)*2*M_PI/n), h*(i + 1)/n, radius*sin((j + 1)*2*M_PI/n));
				glTexCoord2d(s, t + k2);glVertex3d(radius*cos((j + 1)*2*M_PI/n), h*(i/n), radius*sin((j + 1)*2*M_PI/n));
			glEnd();
			
		}
	}
	glTranslatef(0, h, 0);
	drawCircle(radius, r, g, b, a, texSet, index);
	glPopMatrix();
}

void drawRectangle(float width, float height, GLuint texSet[], int index) {
	glBindTexture(GL_TEXTURE_2D, texSet[index]);
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

void drawTriangle(float width, float height, GLuint texSet[], int index){

	glBindTexture(GL_TEXTURE_2D, texSet[index]);
	glPushMatrix();

	glBegin(GL_POLYGON);

	glTexCoord2d(0,0);
	glVertex3f(-width/2,0,0);
	glTexCoord2d(1,1);
	glVertex3f(width/2,0,0);
	glTexCoord2d(0,1);
	glVertex3f(0,height,0);
	glEnd();

	glPopMatrix();
} 

void A0101924House(GLuint texSet[])
{
	//plot dimension
	//x: -4:4
	//y: 0:12
	//z: -4:4
	glEnable(GL_TEXTURE_2D);

	
	// Floor
	glPushMatrix();
	glTranslatef(0,0.01,0);
	drawGroundTexture(texSet,10);
	glPopMatrix();

	// Walkway
	glPushMatrix();
	glTranslatef(2,0.02,-1);
	glRotatef(90,1,0,0);
	drawRectangle(1,5,texSet,3);
	glPopMatrix();

	// Mailbox
	glPushMatrix();
	glTranslatef(3.5,0,3.5);
	drawCylinder(0.1,1,1,0,0,0,3,texSet,12);
	glTranslatef(0,1,0);
	drawCuboid(0.5,0.4,0.2,texSet,34);
	glPopMatrix();

	// Horizontal house
	glPushMatrix();
	glTranslatef(1.5,0,-2.5);
	drawCuboid(5,3,4,texSet,39);
	glPopMatrix();

	// Roof
	glPushMatrix();
	glTranslatef(1.5,4,-4);
	glRotatef(30,1,0,0);
	drawRectangle(5,3,texSet,17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,4,-1);
	glRotatef(-30,1,0,0);
	drawRectangle(5,3,texSet,17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,4,-2.5);
	glRotatef(90,0,1,0);
	drawTriangle(3,2.7,texSet,17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,4,-2.5);
	glRotatef(90,0,1,0);
	drawTriangle(3,2.7,texSet,17);
	glPopMatrix();

	// Door
	glPushMatrix();
	glTranslatef(2,0,-0.95);
	drawRectangle(1,2,texSet,5);
	glPopMatrix();

	// Vertical house
	glPushMatrix();
	glTranslatef(-2.5,0,0);
	glRotatef(90,0,1,0);
	drawCuboid(8,3,4,texSet,39);
	glPopMatrix();

	// Roof
	glPushMatrix();
	glTranslatef(-4,4,0);
	glRotatef(90,0,1,0);
	glRotatef(30,1,0,0);
	drawRectangle(8,3,texSet,17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,4,0);
	glRotatef(90,0,1,0);
	glRotatef(-30,1,0,0);
	drawRectangle(8,3,texSet,17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5,4,-4);
	drawTriangle(3,2.7,texSet,17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5,4,4);
	drawTriangle(3,2.7,texSet,17);
	glPopMatrix();


	// Windows
	glPushMatrix();
	glTranslatef(-2.5,2,4.01);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.99,2,0);
	glRotatef(90,0,1,0);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.99,2,2);
	glRotatef(90,0,1,0);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.01,2,2);
	glRotatef(90,0,1,0);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.01,2,0);
	glRotatef(90,0,1,0);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.01,2,-2);
	glRotatef(90,0,1,0);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3,2,-4.01);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5,2,-4.01);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,2,-4.01);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,2,-4.01);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,2,-4.01);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,2,-0.95);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.01,2,-2.5);
	glRotatef(90,0,1,0);
	drawRectangle(1,1,texSet,27);
	glPopMatrix();
	

	glDisable(GL_TEXTURE_2D);

	//bounding volume
	glPushMatrix();
	glTranslatef(0, 6, 0);
	glScalef(8, 12, 8);	
	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(1);
	glPopMatrix();
		
}