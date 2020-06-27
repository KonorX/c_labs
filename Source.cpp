#include<iostream>
#include<stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <malloc.h>

//������� ������
typedef struct elementsOfList
{
	int data;
	struct elementsOfList *previous;
	struct elementsOfList *next;
};

//��������� ����������� ������� � ������
typedef struct List {
	elementsOfList *head;
	elementsOfList *tail;
	int n;
};



void Menu();
List CreateObject(char *initstr);
void AddData(List* element, int value);
//void PrintList(elementsOfList printedElement);
List EqualsCheck(List firstNumber, List secondNumber);
void PrintingResult(List thirdList);
List CreateObjectForFinal(std::string list);

char ac[9] = "87643211";
char bc[9] = "77633211";
int tothird[14] = { 0 };
List a;
List b;
List c;

//������� �������� ������� ������ List � ������ ���������� ��������� List ���������� elementsOfList 
List CreateObject(char *initStr)
{
	List element = { NULL, NULL, 0 };
	int n;
	for (n = strlen(initStr) - 1; n >= 0; n--)
		AddData(&element, initStr[n] - '0');
	return element;
}

//���� ����� ��� � CreateObject ������ ��� ���������� ��������� ��������� ������� � ����� ������
List CreateObjectForFinal(std::string list)
{
	List element = { NULL, NULL, 0 };
	int n;
	for (n = list.length() - 1; n >= 0; n--)
		AddData(&element, list[n] - '0');
	return element;
}

//���������� List ��������� �� elementsOfList � ��������� ����������� ������� ��� ���������� ��������� ���� �� ������ ��� ��� ������� ��������� ���������
void AddData(List* element, int digit)
{
	elementsOfList* newElement = (elementsOfList*)malloc(sizeof(elementsOfList));
	newElement->data = digit;
	newElement->next = newElement->previous = NULL;
	if (element->head == NULL)
		element->head = element->tail = newElement;
	else {
		element->tail->next = newElement;
		newElement->previous = element->tail;
		element->tail = newElement;
	}
}
	/* ����� ������� ����� �� � �� ������� ������ vs studio �� ����� ������� ������� � ������� � ������� ������ ���� �������, ������ ��� ������� ������ �� ����� ���, �������� ������� ������ Menu()
	void PrintMNumber(elementsOfList Element);
	{
		printf("\nList: ");
		while (printedElement) {
			printf("%d", Element->data);
			Element = Element->prev;
		}
	}*/
//�������� �� �������������� �������� ������� � ������� ������, � ����� �������� ������������� ������
List EqualsCheck(List firstNumber, List secondNumber) 
{
	//char ac[1] = "";
	//List Third= CreateObject(ac);
	std::string list = "";
	int from1st,from2nd,count=0,m=0;
	elementsOfList* first = firstNumber.head;
	elementsOfList* second = secondNumber.head;
	while (first || second)
	{
		if (first)
		{
			from1st = first->data;
			first = first->next;

		}
		if (second)
		{
			from2nd = second->data;
			second = second->next;

		}
		if (from1st != from2nd)
		{
			count += 2;
			list += std::to_string(from1st) + std::to_string(from2nd);
		}
	}
		List Third = CreateObjectForFinal(list);
		
		return Third;
		
	
}
//����� �������� ������
void PrintingResult(List thirdList) 
{
	elementsOfList* element = thirdList.tail;
	printf("\nResulting List:  ");
	while (element) {
		printf("%d", element->data);
		element = element->previous;
	}
	printf("\n");
}
//���� � ������� ��������
void Menu()
{
	int pointOfMenu;
	printf("\n\nMENU\n");
	printf("choose from the following: \n");
	printf("1)watch the 1st list\n");
	printf("2)watch the 2nd list\n");
	printf("3)make the third  list: combined but when the arguments are equal they delete\n");
	printf("4)exit\n");
	//��� �������� exe����� ����� ������ ����������, ��� �������� ������������ g++, �� �� ����� ��������� scanf_s, �� ������ scanf �� ������ � ������� �� �����
	scanf_s("%i",&pointOfMenu);
	elementsOfList* printedElementOfA = a.tail;
	elementsOfList* printedElementOfB = b.tail;
	switch (pointOfMenu)
	{
		case 1:
			
			printf("\nList:   ");
			while (printedElementOfA) {
				printf("%d", printedElementOfA->data);
				printedElementOfA = printedElementOfA->previous;
			}
			printf("\n");
			Menu();
		case 2:
			
			printf("\nList:   ");
			while (printedElementOfB) {
				printf("%d", printedElementOfB->data);
				printedElementOfB = printedElementOfB->previous;
			}
			printf("\n");
			Menu();
		case 3:
			c=EqualsCheck(a, b);
			PrintingResult(c);
			Menu();
			break;
		case 4:
			exit(0);
			break;
	default:
		printf("try again\n");
		Menu();
		
	}
}	






int main() 
{
	a= CreateObject(ac);
	b= CreateObject(bc);
	Menu();
}