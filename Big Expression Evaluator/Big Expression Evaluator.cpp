#include<iostream>
#include"HugeInteger.h"
#include"Equations.h"
using namespace std;
int main()
{
	char ch;
	do
	{
		system("cls");
		Equations Q1;
		Q1.InputString();
		cout << endl;
		Q1.InFixToPostNotation();
		cout << endl << endl;
		Q1.PrintNumberStack();
		cout << "Do you want to continue...";
		cin >> ch;
	} while (ch == 'y');
}