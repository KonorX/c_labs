#include <stdio.h>
#include <cmath>
#include <locale.h>

int fakt(int a)
{
	int b=1,i;
	for (i = 1; i <= a; i++)
	{
		b = b * i;
	}
	return b;
}

int main()
{
	setlocale(LC_ALL, "RU");
	const float pi = 3.1415926;
	float a, b,x,sinish,e,vyrazh2,vyrazh=0;
	int n;
	printf("����� x (� ��������)\t\n");
	scanf_s("%f", &x);
	printf("����� n(�������������)\t\n");
	scanf_s("%i", &n);
	
	
	printf("����� e(�����������)\t\n");
	scanf_s("%f", &e);
	sinish = sin(x);
	printf("����� x = %.20f\n", sin(x));
	for (int i = 1; i <= n; i++)
	{
		
		vyrazh += pow(-1, i - 1) * (pow(x, 2 * i - 1) / fakt(2 * i - 1));
		
		
	}
	printf("��������� � � = %f\n", vyrazh);
	if (sinish-vyrazh<=e||vyrazh-sinish<=e)
	{
		printf("��������� � ��� �������� n ���������� ������ ���� �� e(�����������) \n");
	}
	else if(sinish>vyrazh+e)
	{
		int u = n + 1;
		while (vyrazh+e<sinish)
		{
			vyrazh+= pow(-1, u - 1) * (pow(x, 2 * u - 1) / fakt(2 * u - 1));
			u++;
		}
		printf("n ������ ���� ���� ������� %i ����� ���� ����� � sin(x) �� e\n", u);
	}
	else if (vyrazh>sinish+e)
	{
		vyrazh2 = vyrazh - sinish + e;
		printf("���������(%d) � ��� ������ ������(%d) ������ � ������������(%d) � �������� ����� %d \n", vyrazh, sinish, e,vyrazh2 );
	}
	return 0;
}