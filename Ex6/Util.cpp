#include "head.h"

#pragma warning(disable:4996)

void callList() {
	glCallList(scene.List);
}

void updateList() {
	scene.List = genTableList();
}

void updateCamera() {
	scene.camera[X] = scene.camera_polar[R] * sin(scene.camera_polar[A]);
	scene.camera[Z] = scene.camera_polar[R] * cos(scene.camera_polar[A]);
}

void showSysStatus() {
	static int frame = 0, time, timebase = 0;
	static char fpstext[50];
	static char cameraposition[100];
	static char pointposition[100];
	static char spottarget[100];

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(fpstext, "FPS:%4.2f",
			frame * 1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
	sprintf(cameraposition, "camera position  %2.1f   %2.1f   %2.1f",
		scene.camera[X], scene.camera[Y], scene.camera[Z]);
	sprintf(pointposition, "point position     %2.1f   %2.1f   %2.1f",
		scene.point[X], scene.point[Y], scene.point[Z]);
	sprintf(spottarget, "spot target         %2.1f   %2.1f   %2.1f",
		scene.spot_target[X], scene.spot_target[Y], scene.spot_target[Z]);

	char *c;
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);			// ѡ��ͶӰ����
	glPushMatrix();							// ����ԭ����
		glLoadIdentity();						// װ�뵥λ����
		glOrtho(-480, 480, -480, 480, -1, 1);	// ���òü�����
		glMatrixMode(GL_MODELVIEW);				// ѡ��Modelview����
		glPushMatrix();							// ����ԭ����
			glLoadIdentity();						// װ�뵥λ����
			glPushAttrib(GL_LIGHTING_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, scene.white);
				glRasterPos2f(-460, 420);
				for (c = fpstext; *c != '\0'; c++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
				}
				glRasterPos2f(110, 440);
				for (c = cameraposition; *c != '\0'; c++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
				}
				glRasterPos2f(110, 390);
				for (c = pointposition; *c != '\0'; c++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
				}
				glRasterPos2f(110, 340);
				for (c = spottarget; *c != '\0'; c++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
				}
				glRasterPos2f(-460, -460);
				for (c = scene.message; *c != '\0'; c++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
				}
			glPopAttrib();
			glMatrixMode(GL_PROJECTION);			// ѡ��ͶӰ����
		glPopMatrix();							// ����Ϊԭ�������
		glMatrixMode(GL_MODELVIEW);				// ѡ��Modelview����
	glPopMatrix();							// ����Ϊԭ�������
	glEnable(GL_DEPTH_TEST);
}
