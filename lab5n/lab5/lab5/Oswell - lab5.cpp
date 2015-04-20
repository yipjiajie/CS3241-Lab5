#include "drawHouses.h"
#include "math.h"
#define M_PI 3.141592654

void A0096724drawSphereStrip(double r, float red, float g, float b, float a, float limit, float limit2, GLuint texSet[], int index)
{
	glPushMatrix();
	
    float i,j;
	float t = 0;
	float s = 0; 
	float k = 0.05;
	float n = 10;
	float m = 2*n*limit;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(red, g, b, a);

    for(i=0;i<n;i++) {
		
		s += k;
		if (i/n >= limit2) {
			break;
		}
		for(j=0;j<m;j++) {
			t += k;
			if (index != -1) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, texSet[index]);

				const float DEG2RAD = 3.14159/180;
				float degInRad = i*DEG2RAD;

				glBegin(GL_POLYGON);
					glTexCoord2d(s, t);glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
					glTexCoord2d(s + k, t);glVertex3d(r*sin((i+1)*M_PI/n)*cos(j*M_PI/n),r*cos((i+1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
					glTexCoord2d(s + k, t + k);glVertex3d(r*sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
					glTexCoord2d(s, t + k);glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
 				glEnd();


				if (limit != 1 && limit2 != 1) { 
					glBegin(GL_POLYGON);
						glTexCoord2d(s, t);glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glTexCoord2d(s + k, t);glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n) - 0.05,r*sin((j+1)*M_PI/n));
						glTexCoord2d(s + k, t + k);glVertex3d(r*sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n) - 0.051,r*sin((j+1)*M_PI/n));
						glTexCoord2d(s, t + k);glVertex3d(r*sin((i+1)*M_PI/n)*cos(j*M_PI/n),r*cos((i+1)*M_PI/n)*cos(j*M_PI/n) - 0.05,r*sin(j*M_PI/n));
 					glEnd();

					glBegin(GL_POLYGON);
						glTexCoord2d(s, t);glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
						glTexCoord2d(s + k, t);glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glTexCoord2d(s + k, t + k);glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n) - 0.05,r*sin((j+1)*M_PI/n));
						glTexCoord2d(s, t + k);glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
					glEnd();

					glBegin(GL_POLYGON);
						glTexCoord2d(s, t);glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
						glTexCoord2d(s + k, t);glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glTexCoord2d(s + k, t + k);glVertex3d(r*sin((i + 1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i + 1)*M_PI/n)*cos((j+1)*M_PI/n) - 0.05,r*sin((j+1)*M_PI/n));
						glTexCoord2d(s, t + k);glVertex3d(r*sin((i + 1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i + 1)*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
					glEnd();

					glBegin(GL_POLYGON);
						glTexCoord2d(s, t);glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
						glTexCoord2d(s + k, t);glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glTexCoord2d(s + k, t + k);glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n) - 0.05,r*sin(j*M_PI/n));
						glTexCoord2d(s, t + k);glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
					glEnd();
				}
				glDisable(GL_TEXTURE_2D);
			} else {
				glColor4f(red, g, b, a);

				glBegin(GL_POLYGON);
					glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
					glVertex3d(r*sin((i+1)*M_PI/n)*cos(j*M_PI/n),r*cos((i+1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
					glVertex3d(r*sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
					glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
 				glEnd();

				if (limit != 1 && limit2 != 1) { 
					glBegin(GL_POLYGON);
						glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glVertex3d(r*sin((i+1)*M_PI/n)*cos(j*M_PI/n),r*cos((i+1)*M_PI/n)*cos(j*M_PI/n) - 0.05,r*sin(j*M_PI/n));
						glVertex3d(r*sin((i+1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i+1)*M_PI/n)*cos((j+1)*M_PI/n) - 0.051,r*sin((j+1)*M_PI/n));
						glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n) - 0.05,r*sin((j+1)*M_PI/n));
 					glEnd();

					glBegin(GL_POLYGON);
						glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
						glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n) - 0.05,r*sin((j+1)*M_PI/n));
						glVertex3d(r*sin(i*M_PI/n)*cos((j+1)*M_PI/n),r*cos(i*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
					glEnd();

					glBegin(GL_POLYGON);
						glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
						glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glVertex3d(r*sin((i + 1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i + 1)*M_PI/n)*cos((j+1)*M_PI/n) - 0.05,r*sin((j+1)*M_PI/n));
						glVertex3d(r*sin((i + 1)*M_PI/n)*cos((j+1)*M_PI/n),r*cos((i + 1)*M_PI/n)*cos((j+1)*M_PI/n),r*sin((j+1)*M_PI/n));
					glEnd();

					glBegin(GL_POLYGON);
						glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
						glVertex3d(r*sin(i*M_PI/n)*cos(j*M_PI/n),r*cos(i*M_PI/n)*cos(j*M_PI/n)- 0.05,r*sin(j*M_PI/n));
						glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n) - 0.05,r*sin(j*M_PI/n));
						glVertex3d(r*sin((i + 1)*M_PI/n)*cos(j*M_PI/n),r*cos((i + 1)*M_PI/n)*cos(j*M_PI/n),r*sin(j*M_PI/n));
					glEnd();
				}
			}
		}
	}
		glDisable(GL_BLEND);
		glPopMatrix();
}

void A0096724drawCircle(float radius, float red, float g, float b, float a, GLuint texSet[], int index) {
	const float DEG2RAD = 3.14159/180;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texSet[index]);
	glBegin(GL_TRIANGLE_FAN);
		for(float i = 0; i < 40; i++) {
			float degInRad = i/40.0*360*DEG2RAD;
			glColor4f(red, g, b, a);
			glTexCoord2d(cos(degInRad)/2, sin(degInRad)/2);
			glVertex3d(radius*sin(i*2*M_PI/40), 0, radius*cos(i*2*M_PI/40)); 
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void A0096724drawCylinder(double r, double h, float red, float g, float b, float a, float limit, GLuint texSet[], int index)
{
	glPushMatrix();
	int n = 10;
	float t = 0;
	float s = 0; 
	float k = 0.05;
	float k2 = 0.05;
	
	if (r > 0.6) {
		k = 0.025;
		k2 = 0.09;
	}

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texSet[index]);
	glColor4f(red, g, b, a);

	for (float i = 0; i < n; i++) {
		s += k;
		for (float j = 0; j < n; j++) {
			t += k;
			if (j/n >= limit) {
				break;
			}

			float radius = r;
			glBegin(GL_POLYGON);
				glTexCoord2d(s, t);glVertex3d(r*cos(j*2*M_PI/n), h*(i/n), r*sin(j*2*M_PI/n));
				glTexCoord2d(s + k, t);glVertex3d(r*cos(j*2*M_PI/n), h*(i + 1)/n, r*sin(j*2*M_PI/n));
				glTexCoord2d(s + k, t + k2);glVertex3d(r*cos((j + 1)*2*M_PI/n), h*(i + 1)/n, r*sin((j + 1)*2*M_PI/n));
				glTexCoord2d(s, t + k2);glVertex3d(r*cos((j + 1)*2*M_PI/n), h*(i/n), r*sin((j + 1)*2*M_PI/n));
			glEnd();
			
		}
	}
	glTranslatef(0, h, 0);
	A0096724drawCircle(r, red, g, b, a, texSet, index);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void A0096724drawCone(double r, double h, float red, float g, float b, float a, float limit, GLuint texSet[], int index)
{
	int n = 10;
	float t = 0;
	float s = 0; 
	float k = 0.05;

	if (a != 1) {
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
	}

	glColor4f(red, g, b, a);

	if (index != -1) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texSet[index]);

		for (float i = 0; i < n; i++) {
			s += k;
			if (h*(i/n) > limit) {
				break;
			}
			for (float j = 0; j < n; j++) {
				t += k;
				glBegin(GL_POLYGON);

				float radius = r*(n - i)/n;
				glTexCoord2d(s, t);glVertex3d(radius*cos(j*2*M_PI/n), h*(i/n), radius*sin(j*2*M_PI/n));

				radius = r*(n - (i + 1))/n;
				glTexCoord2d(s + k, t);glVertex3d(radius*cos(j*2*M_PI/n), h*(i + 1)/n, radius*sin(j*2*M_PI/n));
				glTexCoord2d(s + k, t + k);glVertex3d(radius*cos((j + 1)*2*M_PI/n), h*(i + 1)/n, radius*sin((j + 1)*2*M_PI/n));

				radius = r*(n - i)/n;
				glTexCoord2d(s, t + k);glVertex3d(radius*cos((j + 1)*2*M_PI/n), h*(i/n), radius*sin((j + 1)*2*M_PI/n));
				glEnd();
			}
		}
	} else {
		for (float i = 0; i < n; i++) {
		s += k;
		if (h*(i/n) > limit) {
			break;
		}
		for (float j = 0; j < n; j++) {
			t += k;
			glBegin(GL_POLYGON);

			float radius = r*(n - i)/n;
			glVertex3d(radius*cos(j*2*M_PI/n), h*(i/n), radius*sin(j*2*M_PI/n));

			radius = r*(n - (i + 1))/n;
			glVertex3d(radius*cos(j*2*M_PI/n), h*(i + 1)/n, radius*sin(j*2*M_PI/n));
			glVertex3d(radius*cos((j + 1)*2*M_PI/n), h*(i + 1)/n, radius*sin((j + 1)*2*M_PI/n));

			radius = r*(n - i)/n;
			glVertex3d(radius*cos((j + 1)*2*M_PI/n), h*(i/n), radius*sin((j + 1)*2*M_PI/n));
			glEnd();
		}
	}
	}

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	if (a != 1) {
		glDisable(GL_BLEND);
	}
}

void A0096724drawTorus(double bigR, double r, float red, float g, float b, float a)
{
	float n = 10;
	float t = 0;
	float s = 0; 
	float k = 0.05;

	glColor4f(red, g, b, a);

		for (float i = 0; i < n; i++) {
			float theta = i/n*2*M_PI;
			for (float j = 0; j < n; j++) {
				glBegin(GL_POLYGON);
				float alpha = j/n*2*M_PI;
				glVertex3d((bigR + r*cos(j/n*2*M_PI))*cos(i/n*2*M_PI), (bigR + r*cos(j/n*2*M_PI))*sin(i/n*2*M_PI), r*sin(j/n*2*M_PI));
				glVertex3d((bigR + r*cos((j + 1)/n*2*M_PI))*cos(i/n*2*M_PI), (bigR + r*cos((j + 1)/n*2*M_PI))*sin(i/n*2*M_PI), r*sin((j + 1)/n*2*M_PI));
				glVertex3d((bigR + r*cos((j + 1)/n*2*M_PI))*cos((i + 1)/n*2*M_PI), (bigR + r*cos((j + 1)/n*2*M_PI))*sin((i + 1)/n*2*M_PI), r*sin((j + 1)/n*2*M_PI));
				glVertex3d((bigR + r*cos(j/n*2*M_PI))*cos((i + 1)/n*2*M_PI), (bigR + r*cos(j/n*2*M_PI))*sin((i + 1)/n*2*M_PI), r*sin(j/n*2*M_PI));
				glEnd();
			}
	} 

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void A0096724drawSauronTop(GLuint texSet[]) {
	glPushMatrix();
		//Sauron twin thingy
		glPushMatrix();
			glRotatef(90, 0, 1, 0);

			glPushMatrix();
				glPushMatrix();
					glTranslatef(0, 1, 0);
					glScalef(2, -3, 1.5);
					glRotatef(25, 0, 0, 1);
					A0096724drawSphereStrip(1, 116/255.0, 51/255.0, 49/255.0, 1, 0.25, 0.25, texSet, 20);
				glPopMatrix();

				glScalef(1, 1, -1);

				glPushMatrix();
					glTranslatef(0, 1, 0);
					glScalef(2, -3, 1.5);
					glRotatef(25, 0, 0, 1);
					A0096724drawSphereStrip(1, 116/255.0, 51/255.0, 49/255.0, 1, 0.25, 0.25, texSet, 20);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		//Eye
		glPushMatrix();

			glPushMatrix();
				glScalef(1.4, 0.7, 0.25);
				A0096724drawSphereStrip(1, 1, 1, 1, 0.8, 1, 1, texSet, 11);
			glPopMatrix();


			glPushMatrix();
				glScalef(0.8, 0.68, 0.3);
				A0096724drawSphereStrip(1, 1, 1, 1, 1, 1, 1, texSet, 12);
			glPopMatrix();

			glPushMatrix();
				glScalef(0.2, 0.60, 0.35);
				A0096724drawSphereStrip(1, 0, 0, 0, 1, 1, 1, texSet, -1);
			glPopMatrix();


	glPopMatrix();


	glPopMatrix();
}

void A0096724drawSauronMid(GLuint texSet[]) {
	glPushMatrix();
		A0096724drawCylinder(0.4, 2.1, 116/255.0, 51/255.0, 49/255.0, 1, 1, texSet, 20);
	glPopMatrix();
}

void A0096724drawSauronMid2(GLuint texSet[]) {
	glPushMatrix();
		A0096724drawCylinder(0.6, 2.3, 116/255.0, 51/255.0, 49/255.0, 1, 1, texSet, 20);
	glPopMatrix();
}

void A0096724drawSauronCone(GLuint texSet[]) {
	glPushMatrix();
		A0096724drawCone(1.2, 4.6, 116/255.0, 51/255.0, 49/255.0, 1, 2.3, texSet, 20);
	glPopMatrix();
}

void A0096724drawSauronBase1(GLuint texSet[]) {
	glPushMatrix();
		A0096724drawCylinder(1.2, 1.15, 116/255.0, 51/255.0, 49/255.0, 1, 1, texSet, 20);
	glPopMatrix();
}

void A0096724drawSauronBase2(GLuint texSet[]) {
	glPushMatrix();
		A0096724drawCylinder(1.8, 1.725, 116/255.0, 51/255.0, 49/255.0, 1, 1, texSet, 20);
		glPushMatrix();
			for (int i = 0; i < 24; i++) {
				glRotatef(15, 0, 1, 0);
				glPushMatrix();
					glTranslatef(0, 0, 1.8);
					glScalef(1, 1, 2);
					if (i%3 == 1) {
						A0096724drawCylinder(0.1, 1.725, 82/255.0, 42/255.0, 41/255.0, 1, 1, texSet, 13);
					} else  if (i%4 == 2){
						A0096724drawCylinder(0.1, 1.725, 116/255.0, 51/255.0, 49/255.0, 1, 1, texSet, 13);
					} else {
						A0096724drawCylinder(0.1, 1.725, 100/255.0, 48/255.0, 49/255.0, 1, 1, texSet, 13);
					}
				glPopMatrix();
			}
		glPopMatrix();
	glPopMatrix();
}

void A0096724drawFloor(float red, float g, float b, float a, float limit, GLuint texSet[], int index) {
	glPushMatrix();
		float t = 0;
		float s = 0; 

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texSet[index]);
		glColor4f(red, g, b, a);

		glBegin(GL_POLYGON);
			glTexCoord2d(s, t);glVertex3d(-4, 0, -4);
			glTexCoord2d(s + 1, t);glVertex3d(-4, 0, 4);
			glTexCoord2d(s + 1, t + 1);glVertex3d(4, 0, 4);
			glTexCoord2d(s, t + 1);glVertex3d(4, 0, -4);
		glEnd();
	glPopMatrix();
}

void A0096724DrawMyHouse(GLuint texSet[])
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
		glTranslatef(0, 0.05, 0);
		A0096724drawFloor(252/255.0, 125/255.0, 56/255.0, 1, 0, texSet, 12);
	glPopMatrix();
	
	glTranslatef(0, 0, -1.5);

	glPushMatrix();
		glPushMatrix();
			glTranslatef(0, 11, 0);
			glScalef(0.8, 0.8, 0.8);
			A0096724drawSauronTop(texSet);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 7.45, 0);
			A0096724drawSauronMid(texSet);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 5.15, 0);
			A0096724drawSauronMid2(texSet);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 2.85, 0);
			A0096724drawSauronCone(texSet);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 1.75, 0);
			A0096724drawSauronBase1(texSet);
		glPopMatrix();

		glPushMatrix();
			A0096724drawSauronBase2(texSet);
		glPopMatrix();

	glPopMatrix();

	glTranslatef(0, 0, 3);
	glTranslatef(0, 0.06, 0);

	glPushMatrix();
		glPushMatrix();
			glTranslatef(0, 0.06, 1);
			glRotatef(90, 1, 0, 0);
			A0096724drawTorus(0.2, 0.05, 1, 187/255.0, 23/255.0, 1);
		glPopMatrix();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glBegin(GL_TRIANGLE_FAN);
			glColor4f(243/255.0, 242/255.0, 155/255.0, 0.2);
			glVertex3f(0, 10.7, -2.75);
			for (int i = 0; i <= 12; i++) {
				float degInRad = i*30*M_PI/180.0;
				glVertex3f(cos(degInRad), 0, sin(degInRad) + 1);
			}
		glEnd();

	
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(0, 0, 0);
			for (int i = 0; i <= 12; i++) {
				float degInRad = i*30*M_PI/180.0;
				glVertex3f(cos(degInRad), 0, sin(degInRad) + 1);
			}
		glEnd();

		
	glPopMatrix();

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}