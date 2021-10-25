#define _CRT_SECURE_NO_WARNINGS

#define MAX(a,b)(((a)>(b))?(a):(b))
#include <stdio.h>
#include<stdlib.h>

int main()
{
	transposeMat();
}
int transposeMat()
{
	int m; //height
	int n; //width
	printf("input m: ");
	scanf("%d", &m);
	printf("input n: ");
	scanf("%d", &n);

	printf("m=%d, n=%d. \n", m, n);

	int** matA;//행렬A 생성
	matA = (int**)malloc(sizeof(int*) * MAX(m,n));
	matA[0] = (int*)malloc(sizeof(int) * MAX(m, n)^2);
	for (int i = 1; i < m; i++) {
		matA[i] = matA[i - 1] + n;
	}

	int** matAt;//행렬A transpose 선언 및 할당
	matAt = (int**)malloc(sizeof(int*) * MAX(m, n));
	matAt[0] = (int*)malloc(sizeof(int) * MAX(m, n)^2);
	for (int i = 1; i < n; i++) {
		matAt[i] = matAt[i - 1] + m;
	}


	for (int j = 0; j < m; j++) {//행렬A 값 입력
		for (int i = 0; i < n; i++)
		{
			printf("matA[%d][%d] : ", j+1, i+1);
			scanf("%d", &matA[j][i]);
		}
	}


	for (int k = 0; k < m; k++) {//행렬A 출력
		for (int l = 0; l < n; l++)
		{
			printf("%d ", matA[k][l]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			matAt[i][j] = matA[j][i];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", matAt[i][j]);
		printf("\n");
	}
	free(matA[0]);
	free(matA);
	return 0;
			
}