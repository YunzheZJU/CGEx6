#include "head.h"

#pragma warning(disable:4018)
#pragma warning(disable:4996)

void initTexture() {
	glGenTextures(4, scene.texture);
	texload(0, "Monet.bmp");
	texload(1, "Crack.bmp");
	texload(2, "Spot.bmp");
	// 加载自定义纹理
	generateTex();
	glBindTexture(GL_TEXTURE_2D, scene.texture[3]);
	// 设置像素存储模式控制所读取的图像数据的行对齐方式
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, TEX_WIDTH, TEX_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, scene.image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// 加载复合纹理
	glActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
	glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
	glClientActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");
}

// 读纹理
unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader) {
	FILE *filePtr;													// 文件指针
	BITMAPFILEHEADER bitmapFileHeader;								// bitmap文件头
	unsigned char *bitmapImage;										// bitmap图像数据
	int	imageIdx = 0;												// 图像位置索引
	unsigned char tempRGB;											// 交换变量

	// 以“二进制+读”模式打开文件filename 
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL) return NULL;
	// 读入bitmap文件图
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
	// 验证是否为bitmap文件
	if (bitmapFileHeader.bfType != BITMAP_ID) {
		fprintf(stderr, "Error in LoadBitmapFile: the file is not a bitmap file\n");
		return NULL;
	}

	// 读入bitmap信息头
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
	// 将文件指针移至bitmap数据
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
	// 为装载图像数据创建足够的内存
	bitmapImage = new unsigned char[bitmapInfoHeader->biSizeImage];
	// 验证内存是否创建成功
	if (!bitmapImage) {
		fprintf(stderr, "Error in LoadBitmapFile: memory error\n");
		return NULL;
	}

	// 读入bitmap图像数据
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
	// 确认读入成功
	if (bitmapImage == NULL) {
		fprintf(stderr, "Error in LoadBitmapFile: memory error\n");
		return NULL;
	}

	// 由于bitmap中保存的格式是BGR，下面交换R和B的值，得到RGB格式
	for (imageIdx = 0;
		imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3) {
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}
	// 关闭bitmap图像文件
	fclose(filePtr);
	return bitmapImage;
}

// 加载纹理
void texload(int i, char *filename) {
	BITMAPINFOHEADER bitmapInfoHeader;									// bitmap信息头
	unsigned char*   bitmapData;										// 纹理数据

	bitmapData = LoadBitmapFile(filename, &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, scene.texture[i]);						// 指定当前纹理的放大/缩小过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D,
		0,																// mipmap层次(通常为，表示最上层) 
		GL_RGB,															// 我们希望该纹理有红、绿、蓝数据
		bitmapInfoHeader.biWidth,										// 纹理宽带，必须是n，若有边框+2 
		bitmapInfoHeader.biHeight,										// 纹理高度，必须是n，若有边框+2 
		0,																// 边框(0=无边框, 1=有边框) 
		GL_RGB,															// bitmap数据的格式
		GL_UNSIGNED_BYTE,												// 每个颜色数据的类型
		bitmapData);													// bitmap数据指针  
}

// 生成自定义纹理
void generateTex() {
	for (int i = 0; i < TEX_HEIGHT; i++) {
		for (int j = 0; j < TEX_WIDTH; j++) {
			if ((i % 64 - 31.5) * (j % 64 - 31.5) <= 0) {
				scene.image[i][j][0] = 255;
			}
			else {
				scene.image[i][j][0] = 0;
			}
			scene.image[i][j][1] = 0;
			scene.image[i][j][2] = 0;
		}
	}
}

// 启用复合纹理
void openMultitexture() {
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, scene.texture[2]);

	glActiveTextureARB(GL_TEXTURE1_ARB);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, scene.texture[1]);
}

// 关闭复合纹理
void closeMultitexture() {
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glDisable(GL_TEXTURE_2D);
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glDisable(GL_TEXTURE_2D);
}