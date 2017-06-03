#include "head.h"

void initTexture() {
	glGenTextures(5, scene.texture);
	texload(0, "Monet.bmp");
	texload(1, "Crack.bmp");
	// �����Զ�������
	generateTex();
	glBindTexture(GL_TEXTURE_2D, scene.texture[2]);
	//�������ش洢ģʽ��������ȡ��ͼ�����ݵ��ж��뷽ʽ
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, TEX_WIDTH, TEX_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, scene.image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// TODO:���ظ�������
}

// ������
unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader) {
	FILE *filePtr;													// �ļ�ָ��
	BITMAPFILEHEADER bitmapFileHeader;								// bitmap�ļ�ͷ
	unsigned char *bitmapImage;										// bitmapͼ������
	int	imageIdx = 0;												// ͼ��λ������
	unsigned char tempRGB;											// ��������

	// �ԡ�������+����ģʽ���ļ�filename 
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL) return NULL;
	// ����bitmap�ļ�ͼ
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
	// ��֤�Ƿ�Ϊbitmap�ļ�
	if (bitmapFileHeader.bfType != BITMAP_ID) {
		fprintf(stderr, "Error in LoadBitmapFile: the file is not a bitmap file\n");
		return NULL;
	}

	// ����bitmap��Ϣͷ
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
	// ���ļ�ָ������bitmap����
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
	// Ϊװ��ͼ�����ݴ����㹻���ڴ�
	bitmapImage = new unsigned char[bitmapInfoHeader->biSizeImage];
	// ��֤�ڴ��Ƿ񴴽��ɹ�
	if (!bitmapImage) {
		fprintf(stderr, "Error in LoadBitmapFile: memory error\n");
		return NULL;
	}

	// ����bitmapͼ������
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
	// ȷ�϶���ɹ�
	if (bitmapImage == NULL) {
		fprintf(stderr, "Error in LoadBitmapFile: memory error\n");
		return NULL;
	}

	//����bitmap�б���ĸ�ʽ��BGR�����潻��R��B��ֵ���õ�RGB��ʽ
	for (imageIdx = 0;
		imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3) {
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}
	// �ر�bitmapͼ���ļ�
	fclose(filePtr);
	return bitmapImage;
}

// ��������
void texload(int i, char *filename) {
	BITMAPINFOHEADER bitmapInfoHeader;									// bitmap��Ϣͷ
	unsigned char*   bitmapData;										// ��������

	bitmapData = LoadBitmapFile(filename, &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, scene.texture[i]);						// ָ����ǰ����ķŴ�/��С���˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D,
		0,																//mipmap���(ͨ��Ϊ����ʾ���ϲ�) 
		GL_RGB,															//����ϣ���������к졢�̡�������
		bitmapInfoHeader.biWidth,										//��������������n�����б߿�+2 
		bitmapInfoHeader.biHeight,										//����߶ȣ�������n�����б߿�+2 
		0,																//�߿�(0=�ޱ߿�, 1=�б߿�) 
		GL_RGB,															//bitmap���ݵĸ�ʽ
		GL_UNSIGNED_BYTE,												//ÿ����ɫ���ݵ�����
		bitmapData);													//bitmap����ָ��  
}

// �����Զ�������
void generateTex() {
	for (int i = 0; i < TEX_HEIGHT; i++) {
		for (int j = 0; j < TEX_WIDTH; j++) {
			if ((i % 64 - 31.5) * (j % 64 - 31.5) <= 0) {
				scene.image[i][j][0] = 255;
				scene.image[i][j][1] = 0;
				scene.image[i][j][2] = 0;
			}
			else {
				scene.image[i][j][0] = 0;
				scene.image[i][j][1] = 0;
				scene.image[i][j][2] = 0;
			}
		}
	}
}

// ���ɸ�������