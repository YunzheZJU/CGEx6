// main.cpp : 定义控制台应用程序的入口点。
//

#include "head.h"

#pragma warning(disable:4996)
#pragma comment (lib, "glew32.lib")

Myscene scene;

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_MULTISAMPLE);
	glutInitWindowSize(480, 480);
	int windowHandle = glutCreateWindow("Ex 6");

	init();

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);
	glutMouseFunc(processMouse);
	glutKeyboardFunc(processNormalKey);
	glutSpecialFunc(processSpecialKey);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}