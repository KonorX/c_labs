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
	printf("введи x (в радианах)\t\n");
	scanf_s("%f", &x);
	printf("введи n(целочисленное)\t\n");
	scanf_s("%i", &n);
	
	
	printf("введи e(погрешность)\t\n");
	scanf_s("%f", &e);
	sinish = sin(x);
	printf("синус x = %.20f\n", sin(x));
	for (int i = 1; i <= n; i++)
	{
		
		vyrazh += pow(-1, i - 1) * (pow(x, 2 * i - 1) / fakt(2 * i - 1));
		
		
	}
	printf("выражение с х = %f\n", vyrazh);
	if (sinish-vyrazh<=e||vyrazh-sinish<=e)
	{
		printf("выражения и при исходном n отличается меньше либо на e(погрешность) \n");
	}
	else if(sinish>vyrazh+e)
	{
		int u = n + 1;
		while (vyrazh+e<sinish)
		{
			vyrazh+= pow(-1, u - 1) * (pow(x, 2 * u - 1) / fakt(2 * u - 1));
			u++;
		}
		printf("n должно было быть равному %i чтобы быть ближе к sin(x) на e\n", u);
	}
	else if (vyrazh>sinish+e)
	{
		vyrazh2 = vyrazh - sinish + e;
		printf("Выражение(%d) и так больше синуса(%d) вместе с погрешностью(%d) и разгость равна %d \n", vyrazh, sinish, e,vyrazh2 );
	}
	return 0;
}