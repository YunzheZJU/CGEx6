#include "head.h"

#pragma warning(disable:4996)

void drawDesktopSuper() {
	// 复合纹理
	glScalef(5, 4, 1);
	openMultitexture();

	glColor3f(1.0f, 1.0f, 1.0f);
	drawCubeSuper();

	closeMultitexture();
}

void drawCubeSuper() {
	glScalef(0.5, 0.5, 0.5);
	// 指定多重纹理坐标的绘制

	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 1);
	glVertex3i(1, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 1);
	glVertex3i(-1, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 0);
	glVertex3i(-1, -1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 0);
	glVertex3i(1, -1, 1);

	glNormal3f(0, 1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 1);
	glVertex3i(1, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 1);
	glVertex3i(1, 1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 0);
	glVertex3i(-1, 1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 0);
	glVertex3i(-1, 1, 1);

	glNormal3f(1, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 1);
	glVertex3i(1, -1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 1);
	glVertex3i(1, -1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 0);
	glVertex3i(1, 1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 0);
	glVertex3i(1, 1, 1);

	glNormal3f(-1, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 1);
	glVertex3i(-1, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 1);
	glVertex3i(-1, 1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 0);
	glVertex3i(-1, -1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 0);
	glVertex3i(-1, -1, 1);

	glNormal3f(0, -1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 1);
	glVertex3i(-1, -1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 1);
	glVertex3i(-1, -1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 0);
	glVertex3i(1, -1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 0);
	glVertex3i(1, -1, 1);

	glNormal3f(0, 0, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 1);
	glVertex3i(-1, 1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 1);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 1);
	glVertex3i(1, 1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 0);
	glVertex3i(1, -1, -1);
	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 0);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 0);
	glVertex3i(-1, -1, -1);
	glEnd();
}

void drawCube() {
	glScalef(0.5, 0.5, 0.5);

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
}

void drawLeg() {
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, scene.texture[1]);			// 选择纹理texture[1]
		glScalef(1, 1, 3);
		drawCube();
	glDisable(GL_TEXTURE_2D);
}

void drawDesktop() {
	if (scene.bSuper) {
		drawDesktopSuper();
		return;
	}
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, scene.texture[1]);			//选择纹理texture[1]
		glScalef(5, 4, 1);
		drawCube();
	glDisable(GL_TEXTURE_2D);
}

void drawTeapot() {
	glEnable(GL_TEXTURE_2D);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, scene.white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, scene.white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scene.white);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 99);
	if (scene.bSuper) {
		glBindTexture(GL_TEXTURE_2D, scene.texture[3]);			// 选择纹理texture[3]
	}
	else {
		glBindTexture(GL_TEXTURE_2D, scene.texture[0]);			// 选择纹理texture[0]
	}
	//glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidTeapot(1);

	glDisable(GL_TEXTURE_2D);
}

void drawObject() {
	// 横x深y纵z
	// teapot
	glPushMatrix();
		glTranslatef(scene.teapot[X], scene.teapot[Y], scene.teapot[Z]);
		glPushMatrix();
			glTranslatef(0, 0, 4.75);
			glRotatef(90, 1, 0, 0);
			// 横x纵y深z
			glRotatef(scene.fTpRtt, 0, 1, 0);
			drawTeapot();
		glPopMatrix();
	glPopMatrix();

	// table
	glPushMatrix();
		glTranslatef(0, 0, 3.5);
		drawDesktop();
	glPopMatrix();

	// leg1
	glPushMatrix();
		glTranslatef(1.5, 1, 1.5);
		drawLeg();
	glPopMatrix();

	// leg2
	glPushMatrix();
		glTranslatef(-1.5, 1, 1.5);
		drawLeg();
	glPopMatrix();

	// leg3
	glPushMatrix();
		glTranslatef(1.5, -1, 1.5);
		drawLeg();
	glPopMatrix();

	// leg4
	glPushMatrix();
		glTranslatef(-1.5, -1, 1.5);
		drawLeg();
	glPopMatrix();
}

GLint genTableList() {
	GLint lid = glGenLists(1);

	glNewList(lid, GL_COMPILE);
		drawObject();
	glEndList();

	return lid;
}

void drawLight(GLfloat* center, GLfloat radius) {
	glDisable(GL_LIGHTING);
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
	glEnable(GL_LIGHTING);
}
