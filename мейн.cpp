#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include<math.h>
void free(float** A, int str, int stl) {
	for (int i = 0; i < str; i++)
		free(A[i]);
	free(A);
}
void inputMat(float** A,int str,int stl) {
	printf("���� �������\n");
	for (int i = 0; i < str; i++)
	{
		A[i] = (float*)malloc(stl * sizeof(float));
		for (int j = 0; j < stl; j++)
		{
			printf("���� �������� [%d][%d]: ", i, j);
			scanf("%f", &A[i][j]);
		}
	}
}
void outputMat(float** A, int str, int stl)
{
	printf("���������� �������:\n");
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stl; j++)
			printf("%f ", A[i][j]);
		printf("\n");
	}
}
void plusNum(float** A, int str, int stl, float num)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] += num;
}
void minusNum(float** A, int str, int stl, float num)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] -= num;
}
void starNum(float** A, int str, int stl, float num)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] *= num;
}
void plusMat(float** A, float** B, int str, int stl)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] += B[i][j];
}
void minusMat(float** A, float** B, int str, int stl)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] -= B[i][j];
}
void starMat(float** A, float** B, float** result, int strA, int stlA, int stlB)
{
	for (int i = 0; i < strA; i++)
	{
		result[i] = (float*)malloc(stlB * sizeof(float));
		for (int j = 0; j < stlB; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < stlA; k++)
				result[i][j] += A[i][k] * B[k][j];
		}
	}
}
void transMat(float** A, float** result, int str, int stl)
{
	for (int i = 0; i < stl; i++)
	{
		result[i] = (float*)malloc(str * sizeof(float));
		for (int j = 0; j < str; j++)
			result[i][j] = A[j][i];
	}
}
float deterMat(float** A, int str)
{
	float** minor;
	minor = (float**)malloc((str - 1) * sizeof(float*));
	int det = 0;
	if (str == 1)
		return A[0][0];
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < str - 1; j++)
		{
			minor[j] = (float*)malloc((str - 1) * sizeof(float));
			for (int k = 0; k < str; k++)
				if (k != i)
					if (k < i)
						minor[j][k] = A[j + 1][k];
					else
						minor[j][k - 1] = A[j + 1][k];
		}
		det += pow(-1, i) * deterMat(minor, str - 1) * A[0][i];
	}
	return det;
}
void algMat(float** A,float**result, int str)
{
	float** temp;
	temp = (float**)malloc((str - 1) * sizeof(float*));
	for (int i = 0; i < str - 1; i++)
		temp[i] = (float*)malloc((str - 1) * sizeof(float));
	for (int i = 0; i < str; i++)
	{
		result[i] = (float*)malloc(str * sizeof(float));
		for (int j = 0; j < str; j++)
		{
			for (int k = 0; k < str; k++)
				for (int p = 0; p < str; p++)
				{
					if (k != i && p != j)
					{
						if (k < i && p < j)
							temp[k][p] = A[k][p];
						if (k > i && p < j)
							temp[k - 1][p] = A[k][p];
						if (k<i && p>j)
							temp[k][p - 1] = A[k][p];
						if (k > i && p > j)
							temp[k - 1][p - 1] = A[k][p];
					}
				}
			result[i][j] = pow(-1, i + j) * deterMat(temp, str - 1);
		}
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	int choice;
	do {
		printf("\t+----------------------------------------------------------------------------------+\n");
		printf("\t|                                                                                  |\n");
		printf("\t|   ��������� �����������, ����� �������                                           |\n");
		printf("\t|                                                                                  |\n");
		printf("\t+----------------------------------------------------------------------------------+\n");
		printf("\t|                                                                                  |\n");
		printf("\t|    0 - �����                                                                     |\n");
		printf("\t|    1 - �������� ������.                                                          |\n");
		printf("\t|    2 - ��������� ������.                                                         |\n");
		printf("\t|    3 - ��������� ������.                                                         |\n");
		printf("\t|    4 - ��������� ������� �� �����.                                               |\n");
		printf("\t|    5 - �������� ������� � ������.                                                |\n");
		printf("\t|    6 - ��������� ������� � ������.                                               |\n");
		printf("\t|    7 - ���������������� �������.                                                 |\n");
		printf("\t|    8 - ���������� �������� �������.                                              |\n");
		printf("\t|    9 - ���������� ������������                                                   |\n");
		printf("\t|                                                                                  |\n");
		printf("\t+----------------------------------------------------------------------------------+\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:return 0;
		case 1:
		{
			float** A;
			float** B;
			int stlA, strA, stlB, strB;
			do {
				do {
					printf("���� ���������� ����� ������ ������� "); scanf("%d", &strA);
					if (strA < 1) printf("������ �����\n");
				} while (strA < 1);
				do {
					printf("���� ���������� �������� ������ ������� "); scanf("%d", &stlA);
					if (stlA < 1) printf("������ �����\n");
				} while (stlA < 1);
				do {
					printf("���� ���������� ����� ������ ������� "); scanf("%d", &strB);
					if (strB < 1) printf("������ �����\n");
				} while (strB < 1);
				do {
					printf("���� ���������� �������� ������ ������� "); scanf("%d", &stlB);
					if (stlB < 1) printf("������ �����\n");
				} while (stlB < 1);
				if (stlA != stlB || strA != strB)
					printf("������! ������� ������ ���� ������ �������\n");
			} while (stlA != stlB || strA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			printf("������ �������:\n");
			inputMat(A, strA, stlA);
			printf("������ �������:\n");
			inputMat(B, strB, stlB);
			plusMat(A,B,strA,stlA);
			outputMat(A,strA,stlA);
			free(A, strA, stlA);
			free(B,strB, stlB);
			break;
		}
		case 2:
		{
			float** A;
			float** B;
			int stlA, strA, stlB, strB;
			do {
				do {
					printf("���� ���������� ����� ������ ������� "); scanf("%d", &strA);
					if (strA < 1) printf("������ �����\n");
				} while (strA < 1);
				do {
					printf("���� ���������� �������� ������ ������� "); scanf("%d", &stlA);
					if (stlA < 1) printf("������ �����\n");
				} while (stlA < 1);
				do {
					printf("���� ���������� ����� ������ ������� "); scanf("%d", &strB);
					if (strB < 1) printf("������ �����\n");
				} while (strB < 1);
				do {
					printf("���� ���������� �������� ������ ������� "); scanf("%d", &stlB);
					if (stlB < 1) printf("������ �����\n");
				} while (stlB < 1);
				if (stlA != stlB || strA != strB)
					printf("������! ������� ������ ���� ������ �������\n");
			} while (stlA != stlB || strA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			printf("������ �������:\n");
			inputMat(A, strA, stlA);
			printf("������ �������:\n");
			inputMat(B, strB, stlB);
			minusMat(A, B, strA, stlA);
			outputMat(A, strA, stlA);
			free(A, strA, stlA);
			free(B, strB, stlB);
			break;
		}
		case 3:
		{
			float** A;
			float** B;
			float** result;
			int stlA, strA, stlB, strB;
			do {
				do {
					printf("���� ���������� ����� ������ ������� "); scanf("%d", &strA);
					if (strA < 1) printf("������ �����\n");
				} while (strA < 1);
				do {
					printf("���� ���������� �������� ������ ������� "); scanf("%d", &stlA);
					if (stlA < 1) printf("������ �����\n");
				} while (stlA < 1);
				do {
					printf("���� ���������� ����� ������ ������� "); scanf("%d", &strB);
					if (strB < 1) printf("������ �����\n");
				} while (strB < 1);
				do {
					printf("���� ���������� �������� ������ ������� "); scanf("%d", &stlB);
					if (stlB < 1) printf("������ �����\n");
				} while (stlB < 1);
				if (stlA != strB)
					printf("������! ����� �������� ������ ������� ������ ���� ����� ����� ����� ������ �������\n");
			} while (stlA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			result = (float**)malloc(strA * sizeof(float*));
			printf("������ �������:\n");
			inputMat(A, strA, stlA);
			printf("������ �������:\n");
			inputMat(B, strB, stlB);
			starMat(A, B, result, strA, stlA, stlB);
			outputMat(result, strA, stlB);
			free(A, strA, strA);
			free(B, strB, stlB);
			free(result, strA, stlB);
			break;
		}
		case 4: {
			float num;
			float** A;
			int stl, str;
			do {
				printf("���� ���������� ����� ������� "); scanf("%d", &str);
				if (str < 1) printf("������ �����\n");
			} while (str < 1);
			do {
				printf("���� ���������� �������� ������� "); scanf("%d", &stl);
				if (stl < 1) printf("������ �����\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf("���� ����� "); scanf("%f", &num);
			starNum(A, str, stl, num);
			outputMat(A, str, stl);
			free(A, str, stl);
			break;
		}
		case 5:
		{
			float num;
			float **A;
			int stl, str;
			do {
				printf("���� ���������� ����� ������� "); scanf("%d", &str);
				if (str < 1) printf("������ �����\n");
			} while (str < 1);
			do {
				printf("���� ���������� �������� ������� "); scanf("%d", &stl);
				if (stl < 1) printf("������ �����\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf("���� ����� "); scanf("%f", &num);
			plusNum(A, str, stl, num);
			outputMat(A, str, stl);
			free(A, str, stl);
			break;
		}
		case 6: {
			float num;
			float** A;
			int stl, str;
			do {
				printf("���� ���������� ����� ������� "); scanf("%d", &str);
				if (str < 1) printf("������ �����\n");
			} while (str < 1);
			do {
				printf("���� ���������� �������� ������� "); scanf("%d", &stl);
				if (stl < 1) printf("������ �����\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf("���� ����� "); scanf("%f", &num);
			minusNum(A, str, stl, num);
			outputMat(A, str, stl);
			free(A, str, stl);
			break;
		}
		case 7:
		{
			float** A;
			float** result;
			int stl, str;
			do {
				printf("���� ���������� ����� ������� "); scanf("%d", &str);
				if (str < 1) printf("������ �����\n");
			} while (str < 1);
			do {
				printf("���� ���������� �������� ������� "); scanf("%d", &stl);
				if (stl < 1) printf("������ �����\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			result = (float**)malloc(stl * sizeof(float*));
			inputMat(A, str, stl);
			transMat(A, result, str, stl);
			outputMat(result, stl, str);
			free(A, str, stl);
			free(result, stl, str);
			break;
		}
		case 8:
		{
			float** A;
			float** result;
			float det;
			int stl, str;
			do {
				do {
					printf("���� ���������� ����� ������� "); scanf("%d", &str);
					if (str < 1) printf("������ �����\n");
				} while (str < 1);
				do {
					printf("���� ���������� �������� ������� "); scanf("%d", &stl);
					if (stl < 1) printf("������ �����\n");
				} while (stl < 1);
				if (stl != str)
					printf("������! ������� ������ ���� ����������\n");
			} while (stl != str);
			A = (float**)malloc(str * sizeof(float*));
			result = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			det = deterMat(A, str);
			if (det == 0)
			{
				printf("������� �� ����� �������� �������, ��� ��� ��� �� ���������(�� ������������ ����� 0)\n");
				break;
			}
			algMat(A,result, str);
			transMat(result, A, str, stl);
			starNum(A, str, stl, 1 / det);
			outputMat(A, str, stl);
			free(A, str, stl);
			free(result, str, str);
			break;
		}
		case 9:
		{
			float** A;
			float result;
			int stl, str;
			do {
				do {
					printf("���� ���������� ����� ������� "); scanf("%d", &str);
					if (str < 1) printf("������ �����\n");
				} while (str < 1);
				do {
					printf("���� ���������� �������� ������� "); scanf("%d", &stl);
					if (stl < 1) printf("������ �����\n");
				} while (stl < 1);
				if (stl != str)
					printf("������! ������� ������ ���� ����������\n");
			} while (stl != str);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			result = deterMat(A, str);
			printf("%f\n", result);
			free(A, str, stl);
			break;
		}
		default:printf("������ �����\n"); break;
		}
	} while (choice != 0);
}