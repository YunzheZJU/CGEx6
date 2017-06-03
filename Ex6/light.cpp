#include "head.h"

#pragma warning(disable:4996)

void initLight() {
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	// 在纹理贴图之后再应用镜面反射
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL_EXT, GL_SEPARATE_SPECULAR_COLOR_EXT);
}

void initPoint() {
	glLightfv(GL_LIGHT0, GL_POSITION, scene.point);
	glLightfv(GL_LIGHT0, GL_AMBIENT, scene.black);	// 防止环境色影响光照与纹理的混合
	glLightfv(GL_LIGHT0, GL_DIFFUSE, scene.point_color);
	glLightfv(GL_LIGHT0, GL_SPECULAR, scene.white);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);
	glEnable(GL_LIGHT0);
}

void updatePoint() {
	glLightfv(GL_LIGHT0, GL_POSITION, scene.point);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, scene.point_color);
	glEnable(GL_LIGHT0);
}

void initSpot() {
	GLfloat direction[] = { scene.spot_target[X] - scene.spot[X],
		scene.spot_target[Y] - scene.spot[Y], scene.spot_target[Z] - scene.spot[Z] };
	glLightfv(GL_LIGHT1, GL_POSITION, scene.spot);
	//glLightfv(GL_LIGHT1, GL_AMBIENT, scene.white);	// 防止环境色影响光照与纹理的混合
	glLightfv(GL_LIGHT1, GL_DIFFUSE, scene.white);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, scene.spot_cutoff);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 30.0f);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5f);
	glEnable(GL_LIGHT1);
}

void updateSpot() {
	GLfloat direction[] = { scene.spot_target[X] - scene.spot[X],
		scene.spot_target[Y] - scene.spot[Y], scene.spot_target[Z] - scene.spot[Z] };
	glLightfv(GL_LIGHT1, GL_POSITION, scene.spot);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, scene.spot_cutoff);
	glEnable(GL_LIGHT1);
}
