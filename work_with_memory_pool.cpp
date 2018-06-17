#include <iostream>
#include <cstring>
#include "windows.h"
#include <conio.h>

using namespace std;

int size1, size2;
int tmp, temp;
HANDLE heap, hp, hStandartHeap;
char slovo1[] = "";
char *range = NULL;
char x;
void main()
{

	hStandartHeap = GetProcessHeap(); //идентификатор стандартного пула
	cout << "IDENTIFIER STANDART HEAP -----> " << hStandartHeap << endl;

	for (int i = 0;; i++)
	{
		size2 = size2 + 1000;
		int *chr = NULL;
		chr = (int*)HeapAlloc(hStandartHeap, NULL, size2); //выделение блока памяти в стандартном пуле
		tmp = HeapSize(hStandartHeap, 0, chr);
		if (tmp == -1)
			break;
	}

	cout << "MAX SIZE STORAGE STANDART HEAP -----> " << hStandartHeap << endl;

	hp = HeapCreate(0, 0, 40);
	for (int i = 0;; i++)
	{
		size1 = size1 + 100000;
		range = (char*)HeapAlloc(hp, NULL, size1);
		temp = HeapSize(hp, 0, range);
		if (temp == -1)
			break;
	}
	cout << "MAX SIZE STORAGE STANDART HEAP -----> " << hStandartHeap << endl;
	

	cout << "ENTER STRING --->" << endl;
	cin >> slovo1;
	char *chr = NULL;
	chr = (char*)HeapAlloc(hStandartHeap, HEAP_NO_SERIALIZE, 100);
	int MAX = strlen(chr);
	int e = MAX;
	cout << "GO --->" << endl;
	for (int i = strlen(chr); i >= 0; i--)
	{
		range = &chr[i];
		x = *range;
		cout << x;
	}
	_getch();
}
