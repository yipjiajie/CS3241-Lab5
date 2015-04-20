#include "drawHouses.h"

#define M_PI 3.141592654

void A0096677House(GLuint texSet[])
{
	//plot dimension
	//x: -4:4
	//y: 0:12
	//z: -4:4
	
	//bounding volume
	glPushMatrix();
	glTranslatef(0, 6, 0);
	glScalef(8, 12, 8);	
	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(1);
	glPopMatrix();
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,  GL_MODULATE);
	glPushMatrix();
	
		glEnable(GL_TEXTURE_2D);
		glBindTexture( GL_TEXTURE_2D, texSet[9] );
		glBegin(GL_POLYGON);
			glTexCoord2d(0,0); glVertex3d(-4,0,-4);
			glTexCoord2d(4,0); glVertex3d(4,0,-4);
			glTexCoord2d(4,4); glVertex3d(4,0,4);
			glTexCoord2d(0,4); glVertex3d(-4,0,4);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		glTranslatef(0,4.5,-1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture( GL_TEXTURE_2D, texSet[26] );
		glBegin(GL_QUADS); // round roof
			glColor3ub(255,50,50);
			for (float i=0; i <= M_PI*6/5; i += M_PI/5){
				glTexCoord2d(0,0.6);	glVertex3d(cos(i), sin(i), -2);
				glTexCoord2d(0.1,0.6);	glVertex3d(cos(i+M_PI/5), sin(i+M_PI/5), -2);
				glTexCoord2d(0.1,0.1);	glVertex3d(cos(i+M_PI/5), sin(i+M_PI/5), 2);
				glTexCoord2d(0,0.1);	glVertex3d(cos(i), sin(i), 2);
			}
		glEnd();
		glBegin(GL_POLYGON); // front semicircle
			for (float i=0; i <= M_PI*6/5; i += M_PI/5){
				glTexCoord2d(cos(i)/6, sin(i)/6+0.5);	glVertex3d(cos(i), sin(i), 2);
			}
		glEnd();

		glBegin(GL_POLYGON); // back semicircle
			for (float i=0; i <= M_PI*6/5; i += M_PI/5){
				glTexCoord2d(cos(i)/6, sin(i)/6+0.5);	glVertex3d(cos(i), sin(i), -2);
			}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,4.5,0);
		glBegin(GL_POLYGON); // roof
			glTexCoord2d(1/12.0,1.0);	glVertex3d(-2.5,0,-3);
			glTexCoord2d(0.0,0.9);		glVertex3d(-3,0,-2.5);
			glTexCoord2d(0.0,0.1);		glVertex3d(-3,0,1.5);
			glTexCoord2d(1/12.0,0.0);	glVertex3d(-2.5,0,2);
			glTexCoord2d(11/12.0,0.0);	glVertex3d(2.5,0,2);
			glTexCoord2d(1.0,0.1);		glVertex3d(3,0,1.5);
			glTexCoord2d(1.0,0.9);		glVertex3d(3,0,-2.5);
			glTexCoord2d(11/12.0,1.0);	glVertex3d(2.5,0,-3);
		glEnd();

		// front roof
		glBegin(GL_POLYGON); 
			glTexCoord2d(0,0.2);	glVertex3d(-2.5,0,2);
			glTexCoord2d(1,0.2);	glVertex3d(2.5,0,2);
			glTexCoord2d(1,0);		glVertex3d(2.5,-1.5,2.5);
			glTexCoord2d(0,0);	glVertex3d(-2.5,-1.5,2.5);
		glEnd();

		// back roof
		glPushMatrix();
			glScalef(1,1,-1);
			glTranslatef(0,0,1);

			glBegin(GL_POLYGON); 
				glTexCoord2d(0,0.2);	glVertex3d(-2.5,0,2);
				glTexCoord2d(1,0.2);	glVertex3d(2.5,0,2);
				glTexCoord2d(1,0);		glVertex3d(2.5,-1.5,2.5);
				glTexCoord2d(0,0);		glVertex3d(-2.5,-1.5,2.5);
			glEnd();
		glPopMatrix();

		//left roof
		glBegin(GL_POLYGON); 
			glTexCoord2d(0,0.2);	glVertex3d(-3,0,-2.5);
			glTexCoord2d(1,0.2);	glVertex3d(-3,0,1.5);
			glTexCoord2d(1,0);		glVertex3d(-3.5,-1.5,1.5);
			glTexCoord2d(0,0);		glVertex3d(-3.5,-1.5,-2.5);
		glEnd();

		// right roof
		glPushMatrix();
			glScalef(-1,1,1);

			glBegin(GL_POLYGON); 
				glTexCoord2d(0,0.2);	glVertex3d(-3,0,-2.5);
				glTexCoord2d(1,0.2);	glVertex3d(-3,0,1.5);
				glTexCoord2d(1,0);		glVertex3d(-3.5,-1.5,1.5);
				glTexCoord2d(0,0);		glVertex3d(-3.5,-1.5,-2.5);
			glEnd();
		glPopMatrix();


		//left front roof
		glBegin(GL_POLYGON); 
			glTexCoord2d(0.05,0.2);	glVertex3d(-3,0,1.5);
			glTexCoord2d(0.15,0.2);	glVertex3d(-2.5,0,2);
			glTexCoord2d(0.2,0.0);	glVertex3d(-2.5,-1.5,2.5);
			glTexCoord2d(0.0,0.0);	glVertex3d(-3.5,-1.5,1.5);
		glEnd();

		//right front roof
		glPushMatrix();
			glScalef(-1,1,1);
			glBegin(GL_POLYGON); 
				glTexCoord2d(0.05,0.2);	glVertex3d(-3,0,1.5);
				glTexCoord2d(0.15,0.2);	glVertex3d(-2.5,0,2);
				glTexCoord2d(0.2,0.0);	glVertex3d(-2.5,-1.5,2.5);
				glTexCoord2d(0.0,0.0);	glVertex3d(-3.5,-1.5,1.5);
			glEnd();
		glPopMatrix();

		//left back roof
		glPushMatrix();
			glScalef(1,1,-1);
			glTranslatef(0,0,1);
			glBegin(GL_POLYGON); 
				glTexCoord2d(0.05,0.2);	glVertex3d(-3,0,1.5);
				glTexCoord2d(0.15,0.2);	glVertex3d(-2.5,0,2);
				glTexCoord2d(0.2,0.0);	glVertex3d(-2.5,-1.5,2.5);
				glTexCoord2d(0.0,0.0);	glVertex3d(-3.5,-1.5,1.5);
			glEnd();

			//right back roof
			glPushMatrix();
				glScalef(-1,1,1);
				glBegin(GL_POLYGON); 
					glTexCoord2d(0.05,0.2);	glVertex3d(-3,0,1.5);
					glTexCoord2d(0.15,0.2);	glVertex3d(-2.5,0,2);
					glTexCoord2d(0.2,0.0);	glVertex3d(-2.5,-1.5,2.5);
					glTexCoord2d(0.0,0.0);	glVertex3d(-3.5,-1.5,1.5);
				glEnd();
			glPopMatrix();
		glPopMatrix();
		// shelter top
		glBegin(GL_POLYGON); 
			glTexCoord2d(0,0.1);		glVertex3d(-1.5,-1.5,2.5);
			glTexCoord2d(0.5,0.1);		glVertex3d(1.5,-1.5,2.5);
			glTexCoord2d(0.42,0.0);		glVertex3d(1,-1.5,3);
			glTexCoord2d(0.08,0.0);		glVertex3d(-1,-1.5,3);
		glEnd();

		// shelter front
		glBegin(GL_POLYGON); 
			glTexCoord2d(0,0.08);		glVertex3d(-1,-1.5,3);
			glTexCoord2d(0.34,0.08);	glVertex3d(1,-1.5,3);
			glTexCoord2d(0.34,0);		glVertex3d(1,-2,3);
			glTexCoord2d(0,0);			glVertex3d(-1,-2,3);
		glEnd();

		glBegin(GL_POLYGON); 
			glTexCoord2d(0,0.08);		glVertex3d(-2,-1.5,2);
			glTexCoord2d(0.34,0.08);	glVertex3d(-1,-1.5,3);
			glTexCoord2d(0.34,0);		glVertex3d(-1,-2,3);
			glTexCoord2d(0,0);			glVertex3d(-2,-2,2);
		glEnd();

		glBegin(GL_POLYGON); 
			glTexCoord2d(0,0.08);		glVertex3d(2,-1.5,2);
			glTexCoord2d(0.34,0.08);	glVertex3d(1,-1.5,3);
			glTexCoord2d(0.34,0);		glVertex3d(1,-2,3);
			glTexCoord2d(0,0);			glVertex3d(2,-2,2);
		glEnd();



		glDisable(GL_TEXTURE_2D);

	glPopMatrix();


	glColor3ub(255,255,255);
	//walls
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture( GL_TEXTURE_2D, texSet[31] );
	
		glTranslatef(0,0,-0.5);
		glBegin(GL_POLYGON); 
			glTexCoord2d(0.32,0.25);	glVertex3d(-3,3,1.5);
			glTexCoord2d(0.58,0.25);	glVertex3d(-2,3,2.5);
			glTexCoord2d(0.58,0.0);		glVertex3d(-2,0,2.5);
			glTexCoord2d(0.32,0.0);		glVertex3d(-3,0,1.5);
		glEnd();

		glBegin(GL_POLYGON); 
			glTexCoord2d(0.32,0.25);	glVertex3d(-2,3,2.5);
			glTexCoord2d(0.58,0.25);	glVertex3d(2,3,2.5);
			glTexCoord2d(0.58,0.0);		glVertex3d(2,0,2.5);
			glTexCoord2d(0.32,0.0);		glVertex3d(-2,0,2.5);
		glEnd();

		glBegin(GL_POLYGON); 
			glTexCoord2d(0.32,0.25);	glVertex3d(2,3,2.5);
			glTexCoord2d(0.58,0.25);	glVertex3d(3,3,1.5);
			glTexCoord2d(0.58,0.0);		glVertex3d(3,0,1.5);
			glTexCoord2d(0.32,0.0);		glVertex3d(2,0,2.5);
		glEnd();

		glBegin(GL_POLYGON); 
			glTexCoord2d(0.32,0.25);	glVertex3d(3,3,1.5);
			glTexCoord2d(0.58,0.25);	glVertex3d(3,3,-1.5);
			glTexCoord2d(0.58,0.0);		glVertex3d(3,0,-1.5);
			glTexCoord2d(0.32,0.0);		glVertex3d(3,0,1.5);
		glEnd();

		glPushMatrix();
			glRotatef(180,0,1,0);

			glBegin(GL_POLYGON); 
				glTexCoord2d(0.32,0.25);	glVertex3d(-3,3,1.5);
				glTexCoord2d(0.58,0.25);	glVertex3d(-2,3,2.5);
				glTexCoord2d(0.58,0.0);		glVertex3d(-2,0,2.5);
				glTexCoord2d(0.32,0.0);		glVertex3d(-3,0,1.5);
			glEnd();

			glBegin(GL_POLYGON); 
				glTexCoord2d(0.32,0.25);	glVertex3d(-2,3,2.5);
				glTexCoord2d(0.58,0.25);	glVertex3d(2,3,2.5);
				glTexCoord2d(0.58,0.0);		glVertex3d(2,0,2.5);
				glTexCoord2d(0.32,0.0);		glVertex3d(-2,0,2.5);
			glEnd();

			glBegin(GL_POLYGON); 
				glTexCoord2d(0.32,0.25);	glVertex3d(2,3,2.5);
				glTexCoord2d(0.58,0.25);	glVertex3d(3,3,1.5);
				glTexCoord2d(0.58,0.0);		glVertex3d(3,0,1.5);
				glTexCoord2d(0.32,0.0);		glVertex3d(2,0,2.5);
			glEnd();

			glBegin(GL_POLYGON); 
				glTexCoord2d(0.32,0.25);	glVertex3d(3,3,1.5);
				glTexCoord2d(0.58,0.25);	glVertex3d(3,3,-1.5);
				glTexCoord2d(0.58,0.0);		glVertex3d(3,0,-1.5);
				glTexCoord2d(0.32,0.0);		glVertex3d(3,0,1.5);
			glEnd();
		glPopMatrix();
	
		// right wall
		glBegin(GL_POLYGON); 
			glTexCoord2d(0.32,0.25);	glVertex3d(0.5,2.5,3.4);
			glTexCoord2d(0.58,0.25);	glVertex3d(0.9,2.5,3.4);
			glTexCoord2d(0.58,0.0);		glVertex3d(0.9,0,3.4);
			glTexCoord2d(0.32,0.0);		glVertex3d(0.5,0,3.4);
		glEnd();

		glBegin(GL_POLYGON); 
			glTexCoord2d(0.32,0.25);	glVertex3d(0.9,2.5,3.4);
			glTexCoord2d(0.58,0.25);	glVertex3d(0.9,2.5,2.5);
			glTexCoord2d(0.58,0.0);		glVertex3d(0.9,0,2.5);
			glTexCoord2d(0.32,0.0);		glVertex3d(0.9,0,3.4);
		glEnd();

		glBegin(GL_POLYGON); 
			glTexCoord2d(0.32,0.25);	glVertex3d(0.5,2.5,3.4);
			glTexCoord2d(0.58,0.25);	glVertex3d(0.5,2.5,2.5);
			glTexCoord2d(0.58,0.0);		glVertex3d(0.5,0,2.5);
			glTexCoord2d(0.32,0.0);		glVertex3d(0.5,0,3.4);
		glEnd();

		glPushMatrix(); // left wall
			glScalef(-1,1,1);
			glBegin(GL_POLYGON); 
				glTexCoord2d(0.32,0.25);	glVertex3d(0.5,2.5,3.4);
				glTexCoord2d(0.58,0.25);	glVertex3d(0.9,2.5,3.4);
				glTexCoord2d(0.58,0.0);		glVertex3d(0.9,0,3.4);
				glTexCoord2d(0.32,0.0);		glVertex3d(0.5,0,3.4);
			glEnd();

			glBegin(GL_POLYGON); 
				glTexCoord2d(0.32,0.25);	glVertex3d(0.9,2.5,3.4);
				glTexCoord2d(0.58,0.25);	glVertex3d(0.9,2.5,2.5);
				glTexCoord2d(0.58,0.0);		glVertex3d(0.9,0,2.5);
				glTexCoord2d(0.32,0.0);		glVertex3d(0.9,0,3.4);
			glEnd();

			glBegin(GL_POLYGON); 
				glTexCoord2d(0.32,0.25);	glVertex3d(0.5,2.5,3.4);
				glTexCoord2d(0.58,0.25);	glVertex3d(0.5,2.5,2.5);
				glTexCoord2d(0.58,0.0);		glVertex3d(0.5,0,2.5);
				glTexCoord2d(0.32,0.0);		glVertex3d(0.5,0,3.4);
			glEnd();
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture( GL_TEXTURE_2D, texSet[25] );

	
		glBegin(GL_POLYGON); 
			glColor3ub(100,200,255);
		
			glTexCoord2d(0.32,0.25);	glVertex3d(-0.5,2.5,3.3);
			glTexCoord2d(0.58,0.25);	glVertex3d(0.5,2.5,3.3);
			glTexCoord2d(0.58,0.0);		glVertex3d(0.5,0,3.3);
			glTexCoord2d(0.32,0.0);		glVertex3d(-0.5,0,3.3);
		glEnd();
	
	
		glBegin(GL_POLYGON); 
			glColor3ub(0,0,0);
		
			glTexCoord2d(0.32,0.25);	glVertex3d(-0.4,1.4,3.4);
			glTexCoord2d(0.58,0.25);	glVertex3d(-0.3,1.4,3.4);
			glTexCoord2d(0.58,0.0);		glVertex3d(-0.3,1.5,3.4);
			glTexCoord2d(0.32,0.0);		glVertex3d(-0.4,1.5,3.4);
		glEnd();
		glColor3ub(255,255,255);

		glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 3.7, 2.3);
		glScalef(0.6,0.6,0.6);
		glRotatef(-16,1,0,0);
		glBegin(GL_QUAD_STRIP);
			for (float i=0; i < M_PI*8/8; i += M_PI/8){
				glVertex3d(1.1*cos(i), sin(i)+0.1, 0);
				glVertex3d(0.6*cos(i), 0.5*sin(i)+0.1, 0);
			}
		glEnd();

		glBegin(GL_QUAD_STRIP);
			for (float i=0; i < M_PI*8/8; i += M_PI/8){
				glVertex3d(1.1*cos(i), -sin(i)-0.1, 0);
				glVertex3d(0.6*cos(i), -0.5*sin(i)-0.1, 0);
			}
		glEnd();

		glBegin(GL_POLYGON);
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(0.3*cos(i), 0.3*sin(i), 0);
			}
		glEnd();

		glBegin(GL_POLYGON);//right white line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(0.3*cos(i)+2, 0.3*sin(i), 0);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(2,0.3,0);
			glVertex3d(2,-0.3,0);
			glVertex3d(4.2,-0.3,0);
			glVertex3d(4.2,0.3,0);
		glEnd();

		glColor3f(1,0.3,0.3);
		glBegin(GL_POLYGON);//right red line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(0.15*cos(i)+2, 0.15*sin(i), 0.01);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(2,0.15,0.01);
			glVertex3d(2,-0.15,0.01);
			glVertex3d(4.2,-0.15,0.01);
			glVertex3d(4.2,0.15,0.01);
		glEnd();

		glColor3f(1,1,1);
		glBegin(GL_POLYGON);// left line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(0.3*cos(i)-2, 0.3*sin(i), 0);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(-2,0.3,0);
			glVertex3d(-2,-0.3,0);
			glVertex3d(-4.2,-0.3,0);
			glVertex3d(-4.2,0.3,0);
		glEnd();

		glColor3f(1,0.3,0.3);
		glBegin(GL_POLYGON);//left red line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(-0.15*cos(i)-2, 0.15*sin(i), 0.01);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(-2,0.15,0.01);
			glVertex3d(-2,-0.15,0.01);
			glVertex3d(-4.2,-0.15,0.01);
			glVertex3d(-4.2,0.15,0.01);
		glEnd();
	glPopMatrix();

	glPushMatrix(); // right side lines
		glColor3f(1,1,1);
		glTranslatef(3.3,3.7,0);
		glScalef(0.6,0.6,0.6);
		glRotatef(90,0,1,0);
		glRotatef(-16,1,0,0);
		glBegin(GL_POLYGON);//right white line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(0.3*cos(i)+2, 0.3*sin(i), 0);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(2,0.3,0);
			glVertex3d(2,-0.3,0);
			glVertex3d(-2.5,-0.3,0);
			glVertex3d(-2.5,0.3,0);
		glEnd();

		glColor3f(1,0.3,0.3);
		glBegin(GL_POLYGON);//right red line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(0.15*cos(i)+2, 0.15*sin(i), 0.01);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(2,0.15,0.01);
			glVertex3d(2,-0.15,0.01);
			glVertex3d(-2.5,-0.15,0.01);
			glVertex3d(-2.5,0.15,0.01);
		glEnd();

	glPopMatrix();

	glPushMatrix(); // left side lines
		glColor3f(1,1,1);
		glTranslatef(-3.3,3.7,0);
		glScalef(0.6,0.6,0.6);
		glRotatef(-90,0,1,0);
		glRotatef(-16,1,0,0);
		glBegin(GL_POLYGON);// left line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(0.3*cos(i)-2, 0.3*sin(i), 0);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(-2,0.3,0);
			glVertex3d(-2,-0.3,0);
			glVertex3d(2.5,-0.3,0);
			glVertex3d(2.5,0.3,0);
		glEnd();

		glColor3f(1,0.3,0.3);
		glBegin(GL_POLYGON);//left red line start
			for (float i=0; i < M_PI*2; i += M_PI/8){
				glVertex3d(-0.15*cos(i)-2, 0.15*sin(i), 0.01);
			}
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3d(-2,0.15,0.01);
			glVertex3d(-2,-0.15,0.01);
			glVertex3d(2.5,-0.15,0.01);
			glVertex3d(2.5,0.15,0.01);
		glEnd();

	glPopMatrix();

	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-2.89,3.7,1.89);
		glScalef(0.6,0.6,0.6);
		glRotatef(-45,0,1,0);
		glRotatef(-16,1,0,0);
		
		glBegin(GL_POLYGON);
			glVertex3d(-0.85,0.3,0);
			glVertex3d(-1,-0.3,0);
			glVertex3d(1,-0.3,0);
			glVertex3d(0.85,0.3,0);
		glEnd();

		glColor3f(1,0.3,0.3);
		glBegin(GL_POLYGON);
			glVertex3d(-0.9,0.15,0.01);
			glVertex3d(-1,-0.15,0.01);
			glVertex3d(1,-0.15,0.01);
			glVertex3d(0.9,0.15,0.01);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(2.89,3.7,1.89);
		glScalef(0.6,0.6,0.6);
		glRotatef(45,0,1,0);
		glRotatef(-16,1,0,0);
		
		glBegin(GL_POLYGON);
			glVertex3d(-0.85,0.3,0);
			glVertex3d(-1,-0.3,0);
			glVertex3d(1,-0.3,0);
			glVertex3d(0.85,0.3,0);
		glEnd();

		glColor3f(1,0.3,0.3);
		glBegin(GL_POLYGON);
			glVertex3d(-0.9,0.15,0.01);
			glVertex3d(-1,-0.15,0.01);
			glVertex3d(1,-0.15,0.01);
			glVertex3d(0.9,0.15,0.01);
		glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2,1,3.3);
	glRotatef(-20,0,1,0);
	glRotatef(-15,1,0,0);
	A0096677drawStarmie();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2,1,3);
	glRotatef(20,0,1,0);
	glRotatef(-15,1,0,0);
	A0096677drawOddish();
	glPopMatrix();

	glColor3f(1,1,1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}
void A0096677drawStarmie() {
	glPushMatrix();
		glScalef(0.5,0.5,0.5);
		glPushMatrix();
			glTranslatef(0,0,0.55);
			for (int i=0; i<8;i++) {
			glColor3f(0.8,0.8,0);
			A0096677drawCheeseShape();
			glRotatef(45,0,0,1);
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,0,0.55);
			glScalef(0.2,0.2,0.2);
			glColor3f(1,0,0);
			A0096677drawOctogonalGem();
			glColor3f(1,1,0);
			A0096677drawYellowThing();
		glPopMatrix();
		glPushMatrix();
		
			glColor3f(0.7,0,0.7);
			A0096677drawStar();
			glTranslatef(0,0,-0.3);
			glRotatef(36,0,0,1);
			
			glColor3f(0.6,0,0.6);
			A0096677drawStar();
		glPopMatrix();
	glPopMatrix();

}

void A0096677drawStar() {
	glPushMatrix();
	glScalef(1,1,0.5);
	for(int i=0;i<5;i++){
		A0096677drawCone(4);
		glRotatef(360/5,0,0,1);
	}
	glPopMatrix();
}

void A0096677drawCone(double n) {
	glPushMatrix();
		for(int i=0;i<n*2;i++) {
			glBegin(GL_POLYGON);
				glVertex3d(0,2,0);
				glVertex3d(cos(i*M_PI/n*2),0,sin(i*M_PI/n*2));
				glVertex3d(cos((i+1)*M_PI/n*2),0,sin((i+1)*M_PI/n*2));
 			glEnd();
		}	
	glPopMatrix();
}

void A0096677drawCheeseShape() {
	glPushMatrix();
	
	glTranslatef(0,0.35,-0.56);
	glScalef(1,0.8,0.5);
	
		glBegin(GL_POLYGON);//right
			glVertex3d(0.15,0,0.75);
			for (double i=0; i<M_PI/4; i= i+0.1){
				glVertex3d(0.05,sin(i),cos(i));
			}
		glEnd();

		glBegin(GL_POLYGON);//left
			glVertex3d(-0.15,0,0.75);
			for (double i=0; i<M_PI/4; i= i+0.1){
				glVertex3d(-0.05,sin(i),cos(i));
			}
		glEnd();

		glBegin(GL_QUAD_STRIP);
			for (double i=0; i<=M_PI/4; i= i+0.1){
				glVertex3d(0.05,sin(i),cos(i));
				glVertex3d(-0.05,sin(i),cos(i));
			}
		glEnd();

		glBegin(GL_POLYGON);//back
			glVertex3d(-0.15,0,0.75);
			glVertex3d(0.15,0,0.75);
			glVertex3d(0.05,sin(0.7),cos(0.7));
			glVertex3d(-0.05,sin(0.7),cos(0.7));
		glEnd();
	
	glPopMatrix();
}

void A0096677drawYellowThing()
{
	glPushMatrix();
	glRotatef(22.5,0,0,1);
	glTranslatef(0,0,-0.8);

		glBegin(GL_POLYGON);
			for(double i=0;i<2*M_PI;i=i+M_PI/4) {
				glVertex3d(sin(i)*2.1,cos(i)*2.1,0.5);
			}
		glEnd();

		for (int i=0; i<8; i++) {
		glBegin(GL_POLYGON);
			glVertex3d(sin(M_PI*0/4)*2.1,cos(M_PI*0/4)*2.1,0.5);
			glVertex3d(sin(M_PI*1/4)*2.1,cos(M_PI*1/4)*2.1,0.5);
			glVertex3d(sin(M_PI*1/4)*2.1*1.4,cos(M_PI*1/4)*2.1*1.4,0);
			glVertex3d(sin(M_PI*0/4)*2.1*1.4,cos(M_PI*0/4)*2.1*1.4,0);
		glEnd();

		glRotatef(45,0,0,1);
		}
		
		glBegin(GL_POLYGON);
			for(double i=0;i<2*M_PI;i=i+M_PI/4) {
				glVertex3d(sin(i)*2.1*1.4,cos(i)*2.1*1.4,0);
			}
		glEnd();
	
	glPopMatrix();
}

void A0096677drawOctogonalGem()
{
	glPushMatrix();
	glRotatef(22.5,0,0,1);
	glScalef(1,1,0.7);

		glBegin(GL_POLYGON);
			for(double i=0;i<2*M_PI;i=i+M_PI/4) {
				glVertex3d(sin(i),cos(i),0.5);
			}
		glEnd();
		glColor3f(0.8,0,0);
		for (int i=0; i<8; i++) {
		glBegin(GL_POLYGON);
			glVertex3d(sin(M_PI*0/4),cos(M_PI*0/4),0.5);
			glVertex3d(sin(M_PI*1/4),cos(M_PI*1/4),0.5);
			glVertex3d(sin(M_PI*1/4)*2,cos(M_PI*1/4)*2,-0.5);
			glVertex3d(sin(M_PI*0/4)*2,cos(M_PI*0/4)*2,-0.5);
		glEnd();

		glRotatef(45,0,0,1);
		}
	
	glPopMatrix();
}

void A0096677drawOddish(){
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glPushMatrix(); //body
		glColor3f(0,0.5,1);
		glTranslatef(0,-0.5,0);
		glScalef(1,0.8,1);
		A0096677drawSphereBlue(1);
	glPopMatrix();

	glPushMatrix(); //left eye
		glTranslatef(-0.3,-0.3,0.85);
		glColor3f(0.8,0,0);
		A0096677drawRedEye(0.1);
	glPopMatrix();

	glPushMatrix(); //right eye
		glTranslatef(0.3,-0.3,0.85);
		glColor3f(0.8,0,0);
		A0096677drawRedEye(0.1);
	glPopMatrix();

	glPushMatrix(); // mouth
		glTranslatef(0,-0.8,0.948);
		glRotatef(10,1,0,0);
		glScalef(0.1,0.1,1);
		glColor3f(0.8,0,0);
		A0096677drawMouth();
	glPopMatrix();

		

		glPushMatrix(); //left feet
		
		glColor3f(0,0.4,0.9);
			glTranslatef(-0.5,-1.5,0.3);
			glRotatef(20,-1,-1,0);
			glScalef(0.5,0.4,1);
			A0096677drawSphereBlue(0.6);
		glPopMatrix();

		glPushMatrix(); //right feet
		glColor3f(0,0.4,0.9);
			glTranslatef(0.5,-1.5,-0.3);
			glRotatef(-20,-1,-1,0);
			glScalef(0.5,0.4,1);
			A0096677drawSphereBlue(0.6);
		glPopMatrix();
	
			
	glPushMatrix(); //leaf 1
		glTranslatef(0,0.2,0.2);
		glRotatef(30,1,0,0);
		glScalef(2,1,2);
	
		glColor3f(0,1,0);
		A0096677drawLeaf();
	glPopMatrix();
			
	glPushMatrix(); //leaf 2
		glTranslatef(-0.2,0.3,0);
		glRotatef(70,0,0,1);
		glRotatef(40,1,0,0);
		glScalef(1.8,0.9,2);
		glColor3f(0,1,0);
		A0096677drawLeaf();
	glPopMatrix();
			
	glPushMatrix(); //leaf 3
		glTranslatef(0.2,0.3,0);
		glRotatef(-70,0,0,1);
		glRotatef(40,1,0,0);
		glScalef(1.8,0.9,2);
		glColor3f(0,1,0);
		A0096677drawLeaf();
	glPopMatrix();
			
	glPushMatrix(); //leaf 4
		glTranslatef(-0.15,0.25,-0.2);
		glRotatef(35,0,0,1);
		glRotatef(30,1,0,0);
		glScalef(2,0.7,2);
		glColor3f(0,0.8,0);
		A0096677drawLeaf();
	glPopMatrix();
			
	glPushMatrix(); //leaf 5
		glTranslatef(0.15,0.25,-0.2);
		glRotatef(-35,0,0,1);
		glRotatef(30,1,0,0);
		glScalef(2,0.7,2);
		glColor3f(0,0.8,0);
		A0096677drawLeaf();
	glPopMatrix();

	glPushMatrix(); //leaf 6
		glTranslatef(0,0.1,-0.3);
		glRotatef(20,1,0,0);
		glScalef(1.5,0.5,1.5);
		glColor3f(0,0.7,0);
		A0096677drawLeaf();
	glPopMatrix();
	glPopMatrix();
}

void A0096677drawLeaf()
{
	glPushMatrix();

	glRotatef(45,0,0,1);
		glBegin(GL_QUAD_STRIP);
			for(double x=0; x<=1 ; x=x+0.2) {
			glVertex3d(x, x*x, -x*x*x*x);
			glVertex3d(x*x, x, -x*x*x*x);
			}
		glEnd();
		glColor3f(0,0.6,0);
	A0096677drawLeafLine();
	glPopMatrix();
}

void A0096677drawLeafLine()
{
	glPushMatrix();
	
	glTranslatef(0,0,0.002);
	for (int i=0; i<400; i++){
		glTranslatef(-0.0001,-0.0001,0);
		
			glBegin(GL_QUAD_STRIP);
				for(double x=0; x<0.99 ; x=x+0.1) {
				glVertex3d(x, x+0.01, -x*x*x);
				glVertex3d(x+0.01, x, -x*x*x);
				}
			glEnd();
		
	}
	glPopMatrix();
}

void A0096677drawMouth()
{
	glPushMatrix();
	
	for(double i=-0.06; i<=0;i=i+0.01) {
		
			glBegin(GL_TRIANGLE_FAN);
				glVertex3d(0,2,i+0.05);
				glVertex3d(2,4,i);
				glVertex3d(-2,4,i);
				for(double x = -2; x<2.1; x=x+0.1){
					glVertex3d(x,x*x,i);
				}
			glEnd();
		
	}
	glPopMatrix();
}

void A0096677drawSphereBlue(double r)
{
	glPushMatrix();
	
    int i,j;
	int n = 4;
    for(i=0;i<n;i++){
		for(j=0;j<2*n;j++){
		
			glBegin(GL_POLYGON);
			    // Explanation: the normal of the whole polygon is the coordinate of the center of the polygon for a sphere
				glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
				glVertex3d(r*sin((i+1)*M_PI/n)*cos(j*M_PI/n),r*cos((i+1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
				glVertex3d(r*sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
				glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
 			glEnd();
		}
	}
	glPopMatrix();
}

void A0096677drawRedEye(double r)
{
	glPushMatrix();
	
    int i,j;
	int n = 4;
    for(i=0;i<n;i++){
		for(j=0;j<2*n;j++){
		
			glBegin(GL_POLYGON);
			    // Explanation: the normal of the whole polygon is the coordinate of the center of the polygon for a sphere
				glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
				glVertex3d(r*sin((i+1)*M_PI/n)*cos(j*M_PI/n),r*cos((i+1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
				glVertex3d(r*sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
				glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
 			glEnd();
		}
	}
	glPopMatrix();
}

