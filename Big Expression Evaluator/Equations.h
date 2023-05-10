#pragma once
#include<iostream>
#include<string>
#include<stack>
#include "HugeInteger.h"
using namespace std;

class Equations
{
private:
	string Expression;
	stack<char>Signs;
	stack<HugeInt>Number;

public:
	void InputString();
	void PrintString();
	void InFixToPostNotation();
	void PrintNumberStack();
	bool IsHigherPrecedence(char ch);
	bool IsLowerPrecedence(char ch);
	bool IsEqualPrecedence(char ch);
	bool IsSign(char ch);
	void CallingLowerFunction(char ch);
	void CalculationsAtLast();
	void Calulating();
	bool FirstNegative();
};

