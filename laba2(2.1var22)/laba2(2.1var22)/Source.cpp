#include <stdio.h>
#include <stdlib.h>

int m1 = 0, d1 = 0, m2 = 0, d2 = 0,s1,s2,msw=0,t1=0,t2=0;


void menu();
//void proverkapola1(int ss);

void space()
{
	char vv=' ', sp = 's';
	printf("enter a s to continue(go to menu)");
	scanf_s("%c", vv);
	if (vv==sp)
	{
		system("cls");
		menu();
	}
	else
	{
		printf("try again");
		space();
	}
}



void enter()
{
	
	printf("enter 1st partner date of birth & sex\n");
	printf("month\n");
	scanf_s("%i", &m1);
	printf("day\n");
	scanf_s("%i", &d1);
	printf("sex 1:male 2:female\n");
	
	scanf_s("%i", &s1);
	printf("enter the same to the 2nd\n");
	printf("month\n");
	scanf_s("%i", &m2);
	printf("day\n");
	scanf_s("%i", &d2);
	printf("sex 1:male 2:female\n");
	
	scanf_s("%i", &s2);
	printf("1st: birth %d/%d(m/d) sex", m1, d1);
	if (s1==1)
	{
		printf("  male\n");
	}
	else if(s1==2)
	{
		printf("  female\n");
	}
	else
	{
		printf("  %i\n", s1);
	}
	printf("2st: birth %d/%d(m/d) sex", m2, d2);
	if (s2 == 1)
	{
		printf("  male\n");
	}
	else if (s2 == 2)
	{
		printf("  female\n");
	}
	else
	{
		printf("  %i\n", s2);
	}
	menu();
}

void regis(int m, int d, int t )
{
	switch (m)
	{
	case 1:if (d >= 21)
	{
		
		printf("kozerog\n");
		t = 4;
	}
		  else if(d<=20)	
	{
		printf("vodoley\n");
		t = 1;
	}
		  else
	{
		printf("error\n");
	}
		break;
	case 2:
		if (d>=18)
		{
			printf("ryby(fish)\n");
			t = 3;
		}
		else if (d<=17)
		{
			printf("vodoley\n");
			t = 1;
		}
		else
		{
			printf("error\n");
		}
		break;
	case 3:
		if (d>=21)
		{
			printf("oven(not for baking)\n");
			t = 2;
		}
		else if (d<=20)
		{
			printf("ryby(fish)\n");
			t = 3;
		}
		else
		{
			printf("error\n");
		}
		break;
	case 4:
		if (d>=21)
		{
			printf("telets\n");
			t = 4;
		}
		else if (d<=20)
		{
			printf("oven(not for baking)\n");
			t = 2;
		}
		else
		{
			printf("error\n");
		}
		break;
	case 5:
		if (d>=21)
		{
			printf("blisnetsy\n");
			t = 1;
		}
		else if (d<=20)
		{
			printf("telets\n");
			t = 4;
		}
		else
		{
			printf("error\n");
		}
		break;
	case 6:
		if (d>=22)
		{
			printf("rak\n");
			t = 3;
		}
		else if(d<=21)
		{
			printf("blisnetsy\n");
			t = 1;
		}
		else
		{
			printf("error");
		}
		break;
	case 7:
		if (d>=23)
		{
			printf("lev");
			t = 2;
		}
		else if (d<=22)
		{
			printf("rak");
			t = 3;
		}
		break;
	case 8:
		if (d>=24)
		{
			printf("deva");
			t = 4;
		}
		else if (d<=23)
		{
			printf("lev");
			t = 2;
		}
		else
		{
			printf("error");
		}
		break;
	case 9:
		if (d>=24)
		{
			printf("vesy");
			t = 1;
		}
		else if(d<=23)
		{
			printf("deva");
			t = 4;
		}
		else
		{
			printf("error");
		}
		break;
	case 10:
		if (d>=24)
		{
			printf("skorpion");
			t = 3;
		}
		else if (d<=23)
		{
			printf("vesy");
			t = 1;
		}
		else
		{
			printf("error");
		}
		break;
	case 11:
		if (d>=23)
		{
			printf("strelets");
			t = 2;
		}
		else if (d<=22)
		{
			printf("skorpion");
			t = 3;
		}
		else
		{
			printf("error");
		}
		break;
	case 12:
		if (d>=22)
		{
			printf("kozerog");
			t = 4;
		}
		else if (d<=21)
		{
			printf("strelets");
			t = 2;
		}
		else
		{
			printf("error");
		}
		break;
	default:
		printf("try to input again");
		break;
	}
}

void menu( )
{
	
	printf("\t\tMENU\n");
	printf("enter what do you want to do\n");
	printf("1)enter partners\n");
	printf("2)find a zodiac of a partner\n");
	printf("3)friendship chance\n");
	printf("4)business chance\n");
	printf("5)marriage chance\n");
	printf("6)about authors\n");
	printf("7)exit\n");
	printf("8)clear partners\n");
	scanf_s("%i", &msw);
	switch (msw)
	{
	case 1:
		enter();
		break;
	case 2:
		printf("\n1st partner\n");
		regis(m1, d1, t1);
		printf("\n2nd partner\n");
		regis(m2, d2, t2);
		menu();
		break;
	case 3:
		if ((t1==3&&t2==1)||(t1==1&&t2==3)||(t1==2&&t2==4)||(t1==4&&t2==2))
		{
			printf("partners may have good friendship\n");
		}
		else
		{
			printf("partners may not have good friendship\n");
		}
		menu();
		break;
	case 4:
		if (t1==t2+1||t1==t2-1||(t1==1&&t2==4)||(t1==4&&t2==1))
		{
			printf("they are good business partners\n");
		}
		else
		{
			printf("they are not good business partners\n");
		}
		menu();
		break;
	case 5:
		if ((t1 == 3 && t2 == 1) || (t1 == 1 && t2 == 3) || (t1 == 2 && t2 == 4) || (t1 == 4 && t2 == 2)&&s1!=s2)
		{
			printf("they may have good marriage\n");
		}
		else
		{
			printf("they may not have good marriage\n");
		}
		menu();
		break;
	case 6:
		printf("Made by 95350011 inc\n");
		printf("thanks for using\n");
		menu();
		break;
	case 7:
		exit(0);
		break;
	case 8:
		m1 = 0, d1 = 0, m2 = 0, d2 = 0, s1, s2, msw = 0, t1 = 0, t2 = 0;
		printf("data cleared");
		system("cls");
		menu();
		break;
	default:
		printf("error, restarting");
		menu();
		break;
	}
	
}


int main()
{
	
	
	

	menu( );
}




//1)воздух=близнецы, весы, водолей
//2)огонь=овен,лев,стрелец
//3)вода=рак,скорпион,рыбы
//4)земля=телец,дева,козерог
//бизнес=смежные хороши либо одинаковые
//брак=если разного пола + если они 1и3 или 2и4
//дружба=если брак только без пола
