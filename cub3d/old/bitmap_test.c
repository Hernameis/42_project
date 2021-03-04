/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:39:06 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/04 15:27:22 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma pack(push, 1)

typedef struct _BITMAPFILEHEADER     // BMP 비트맵 파일 헤더 구조체
{
    unsigned short bfType;           // BMP 파일 매직 넘버
    unsigned int   bfSize;           // 파일 크기
    unsigned short bfReserved1;      // 예약
    unsigned short bfReserved2;      // 예약
    unsigned int   bfOffBits;        // 비트맵 데이터의 시작 위치
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
    unsigned int   biSize;           // 현재 구조체의 크기
    int            biWidth;          // 비트맵 이미지의 가로 크기
    int            biHeight;         // 비트맵 이미지의 세로 크기
    unsigned short biPlanes;         // 사용하는 색상판의 수
    unsigned short biBitCount;       // 픽셀 하나를 표현하는 비트 수
    unsigned int   biCompression;    // 압축 방식
    unsigned int   biSizeImage;      // 비트맵 이미지의 픽셀 데이터 크기
    int            biXPelsPerMeter;  // 그림의 가로 해상도(미터당 픽셀)
    int            biYPelsPerMeter;  // 그림의 세로 해상도(미터당 픽셀)
    unsigned int   biClrUsed;        // 색상 테이블에서 실제 사용되는 색상 수
    unsigned int   biClrImportant;   // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE            // 24비트 비트맵 이미지의 픽셀 구조체
{
    unsigned char rgbtBlue;          // 파랑
    unsigned char rgbtGreen;         // 초록
    unsigned char rgbtRed;           // 빨강
} RGBTRIPLE;

#pragma pack(pop)

int		main(void)
{
	FILE *fpBmp;							// 비트맵 파일 포인터
	FILE *fpTxt;							// 텍스트 파일 포인터
	BITMAPFILEHEADER	fileHeader;			// 비트맵 파일 헤더 구조체 변수
	BITMAPINFOHEADER	infoHeader;			// 비트맵 정보 헤더 구조체 변수

	unsigned char		*image;				// 픽셀 데이터 포인터
	int					size;				// 픽셀 데이터 크기
	int					width;	비트맵			// 비트맵 이미지의 가로
	int					height;				// 비트맵 이미지의 세로
	int					padding;			// 픽셀 데이터의 가로 크기가 4의 배수가 아닐 때 남는 공간의 크기

	fbBmp = fopen("peppers80x80.bmp", "rb");
	if (fbBmp == NULL)
		return (0);

	if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1)
	{
		fclose(fpBmp);
		return (0);
	}
	if (fileHeader.bfType != 'MB')
	{		
		fclose(fpBmp);
		return (0);
	}

	if	(fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1)
	{
		fclose(fpBmp);
		return (0);
	}
	if (infoHeader.biBitCount != 24)
	{
		fclose(fpBmp);
		return (0);
	}

	size = infoHeader.biSizeImage;
	width = infoHeader.biWidth;
	height = infoHeader.biHeight;

	padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;
	
	if (size == 0)
	{
		size = (width * PIXEL_SIZE + padding) * height;
	}
	image = malloc(size);
	fseek(fpBmp, fileHeader, bf0ffBits, SEEK_SET);

	if (fread(image, size, 1, fpBmp) < 1)
	{
		fclose(fpBmp);
		return (0);
	}
	fclose(fpBmp);
	fpTxt = fopen("ascii.txt", "w");
	if (fpTxt == NULL)
	{
		free(image);
		return (0);
	}
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			int index = 
	return (0);
}
