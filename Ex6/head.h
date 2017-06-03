#pragma once

// Include related head files and IO classes
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <iomanip>

// Include glew.h and glut.h
#include <gl/glew.h>
#include <gl/glut.h>
//#include <gl/glext.h>

// Using namespace std for cin and cout
using namespace std;

// Define shortcuts for coordinate in location array
#define X 0
#define Y 1
#define Z 2

// Define abbreviate for "radius" and "angle"
#define R 0
#define A 1

// Define Pi in math
#define PI 3.1415926

// Define BITMAP_ID
#define BITMAP_ID 0x4D42

// Define height and width for custom texture
#define TEX_HEIGHT 256 
#define TEX_WIDTH 256 

typedef struct {
	// �����ʾ�����飬����3������ı�ʾ��
	unsigned int texture[3];

	// Declare height and width variables for size of new window
	int wHeight = 0;							// Height of new window
	int wWidth = 0;								// Width of new window

	// Initiate message string to be shown
	char message[70] = "Welcome!";				// Message string to be shown

	// Initiate parameters for global and local rotating
	GLfloat fRotate = 0.0f;						// Global roatating
	GLfloat fTpRtt = 0.0f;						// Local rotating

	// Initiate switch of the scene
	GLboolean bPoint = GL_TRUE;					// Switch for point light
	GLboolean bSpot = GL_TRUE;					// Switch for spot light
	GLboolean bPersp = GL_TRUE;					// Switch for perspective mode
	GLboolean bMix = GL_TRUE;					// Switch for tex-env mix mode
	GLboolean bMsaa = GL_FALSE;					// Switch for perspective mode
	GLboolean bWire = GL_FALSE;					// Switch for line mode
	GLboolean bAnim = GL_FALSE;					// Switch for global rotating
	GLboolean bRtt = GL_FALSE;					// Switch for local rotating
	GLboolean bSuper = GL_FALSE;				// Switch for super texture mode

	// Initiate location of elements
	GLfloat teapot[3] = { 0, 0, 0 };			// Position of teapot
	GLfloat camera[3] = { 0, 1, 4 };			// Position of camera
	GLfloat camera_polar[2] = { 4, 0 };			// Polar coordinates of camera
	GLfloat camera_target[3] = { 0, 1, 0 };		// Position of target of camera
	GLfloat point[4] = { 1, 1.75, 1, 1 };		// Position of point light
	GLfloat spot[4] = { 0, 3, 0, 1 };			// Position of spot light
	GLfloat spot_target[3] = { 0, 0, 0 };		// Position of target of spot light

	// Initiate list num for display list
	GLint List = 0;								// List num of display list

	// Define colors for materials
	GLfloat red[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat green[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
	GLfloat blue[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat yellow[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat turquoise[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
	GLfloat golden[4] = { 1.0f, 0.843f, 0.0f, 1.0f };
	GLfloat white[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	// Initiate cut off degree for spot light
	GLfloat spot_cutoff = 8.6f;					// Cut off degree of spot light

	// Define colors for lights
	GLfloat point_white[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat point_red[4] = { 1.0f, 0.2f, 0.2f, 1.0f };
	GLfloat point_green[4] = { 0.2f, 1.0f, 0.2f, 1.0f };
	GLfloat point_blue[4] = { 0.2f, 0.2f, 1.0f, 1.0f };
	GLfloat point_yellow[4] = { 1.0f, 1.0f, 0.2f, 1.0f };

	// Initiate the color of point light
	GLfloat* point_color = point_white;

	// Initiate the container for custom texture
	GLubyte image[TEX_HEIGHT][TEX_WIDTH][3];
}Myscene;

extern Myscene scene;

// Define enum for menu items
enum {
	NOTHING,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	DEFAULT,
	DISABLE,
	EXIT
};

/*Draw.cpp*/
void drawTeapotSuper();
void drawLegSuper();
void drawDesktopSuper();
void drawCube();
void drawLeg();
void drawDesktop();
void drawTeapot();
void drawObject();
GLint genTableList();
void drawLight(GLfloat* center, GLfloat radius);

/*Texture.cpp*/
void initTexture();
unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
void texload(int i, char *filename);
void generateTex();

/*Light.cpp*/
void initLight();
void initPoint();
void updatePoint();
void initSpot();
void updateSpot();

/*Util.cpp*/
void callList();
void updateList();
void updateCamera();
void showSysStatus();

/*System.cpp*/
void idle();
void initMenu(void);
void processMenu(int value);
void redraw();
void reshape(int width, int height);
void updateView(int width, int height);
void processMouse(int button, int state, int x, int y);
void processNormalKey(unsigned char k, int x, int y);
void processSpecialKey(int k, int x, int y);