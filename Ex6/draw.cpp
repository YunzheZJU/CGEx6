#include "head.h"

#pragma warning(disable:4996)

void drawCube() {
	glScalef(0.5, 0.5, 0.5);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, scene.texture[1]);  //选择纹理texture[1]

	glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2i(1, 1); glVertex3i(1, 1, 1);
		glTexCoord2i(0, 1); glVertex3i(-1, 1, 1);
		glTexCoord2i(0, 0); glVertex3i(-1, -1, 1);
		glTexCoord2i(1, 0); glVertex3i(1, -1, 1);

		glNormal3f(0, 1, 0);
		glTexCoord2i(1, 1); glVertex3i(1, 1, 1);
		glTexCoord2i(0, 1); glVertex3i(1, 1, -1);
		glTexCoord2i(0, 0); glVertex3i(-1, 1, -1);
		glTexCoord2i(1, 0); glVertex3i(-1, 1, 1);

		glNormal3f(1, 0, 0);
		glTexCoord2i(1, 1); glVertex3i(1, -1, 1);
		glTexCoord2i(0, 1); glVertex3i(1, -1, -1);
		glTexCoord2i(0, 0); glVertex3i(1, 1, -1);
		glTexCoord2i(1, 0); glVertex3i(1, 1, 1);

		glNormal3f(-1, 0, 0);
		glTexCoord2i(1, 1); glVertex3i(-1, 1, 1);
		glTexCoord2i(0, 1); glVertex3i(-1, 1, -1);
		glTexCoord2i(0, 0); glVertex3i(-1, -1, -1);
		glTexCoord2i(1, 0); glVertex3i(-1, -1, 1);

		glNormal3f(0, -1, 0);
		glTexCoord2i(1, 1); glVertex3i(-1, -1, 1);
		glTexCoord2i(0, 1); glVertex3i(-1, -1, -1);
		glTexCoord2i(0, 0); glVertex3i(1, -1, -1);
		glTexCoord2i(1, 0); glVertex3i(1, -1, 1);

		glNormal3f(0, 0, -1);
		glTexCoord2i(1, 1); glVertex3i(-1, 1, -1);
		glTexCoord2i(0, 1); glVertex3i(1, 1, -1);
		glTexCoord2i(0, 0); glVertex3i(1, -1, -1);
		glTexCoord2i(1, 0); glVertex3i(-1, -1, -1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawLeg() {
	glScalef(1, 1, 3);
	drawCube();
}

void drawDesktop() {
	glScalef(5, 4, 1);
	drawCube();
}

void drawScene() {
	// 这时横x深y纵z
	glPushAttrib(GL_LIGHTING_BIT);
		// teapot
		glPushMatrix();
			glTranslatef(scene.teapot[X], scene.teapot[Y], scene.teapot[Z]);
			glPushMatrix();
				glTranslatef(0, 0, 4.75);
				glRotatef(90, 1, 0, 0);
				// 从此横x纵y深z
				glRotatef(scene.fTpRtt, 0, 1, 0);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, scene.black);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.golden);
				//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.white);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scene.white);
				glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 80);

				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, scene.texture[0]);  //选择纹理texture[0]
				//glColor3f(1.0f, 0.0f, 0.0f);

				glutSolidTeapot(1);

				glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		glPopMatrix();

		// table
		glPushMatrix();
			glTranslatef(0, 0, 3.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.red);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scene.black);
			drawDesktop();
		glPopMatrix();

		// leg1
		glPushMatrix();
			glTranslatef(1.5, 1, 1.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.green);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scene.black);
			drawLeg();
		glPopMatrix();

		// leg2
		glPushMatrix();
			glTranslatef(-1.5, 1, 1.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.yellow);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scene.black);
			drawLeg();
		glPopMatrix();

		// leg3
		glPushMatrix();
			glTranslatef(1.5, -1, 1.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.turquoise);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scene.black);
			drawLeg();
		glPopMatrix();

		// leg4
		glPushMatrix();
			glTranslatef(-1.5, -1, 1.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.blue);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scene.black);
			drawLeg();
		glPopMatrix();
	glPopAttrib();
}

GLint genTableList() {
	GLint lid = glGenLists(1);

	glNewList(lid, GL_COMPILE);
		drawScene();
	glEndList();

	return lid;
}

void drawLight(GLfloat* center, GLfloat radius) {
	glPushAttrib(GL_LIGHTING_BIT);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, scene.white);
		glPushMatrix();
			glTranslatef(center[X], center[Y], center[Z]);
			glScalef(0.2, 0.2, 0.2);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 20; i++) {
					glVertex3f(2 * radius * cos(2 * PI / 20 * i), radius * sin(2 * PI / 20 * i), 0);
				}
			glEnd();
			glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 20; i++) {
					glVertex3f(2 * radius * cos(2 * PI / 20 * i), 0, radius * sin(2 * PI / 20 * i));
				}
			glEnd();
			glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 20; i++) {
					glVertex3f(0, radius * sin(2 * PI / 20 * i), radius * cos(2 * PI / 20 * i));
				}
			glEnd();
		glPopMatrix();
	glPopAttrib();
}
