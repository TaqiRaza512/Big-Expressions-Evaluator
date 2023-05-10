#include "Equations.h"
#include<iostream>
#include<string>
void Equations::InputString()
{
	cout << "Please enter any string : ";
	cin >> Expression;
}
void Equations::PrintString()
{
	cout << Expression;
}
bool Equations::IsHigherPrecedence(char ch)
{
	if (ch == '(')
		return true;
	if ((ch == '*' or ch == '/') and (Signs.top() == '+' or Signs.top() == '-'))
		return true;
	return false;
}
bool Equations::IsLowerPrecedence(char ch)
{
	if (Signs.top() == '(')
		return true;
	if ((ch == '+' or ch == '-') and (Signs.top() == '/' or Signs.top() == '*') or (ch == '*' and Signs.top() == '/'))
		return true;
	return false;
}
bool Equations::IsEqualPrecedence(char ch)
{
	if (!IsHigherPrecedence(ch) and !IsLowerPrecedence(ch))
		return true;
	return false;
}
bool Equations::IsSign(char ch)
{
	if (ch == '+' or ch == '-' or ch == '/' or ch == '*' or ch == '(' or ch == ')')
		return true;
	return false;
}
bool Equations::FirstNegative()
{
	if (Number.size() == 0 and Signs.size() == 1 and Signs.top() == '-')
	{
		Signs.pop();
		return true;
	}
	return false;
}
void Equations::Calulating()
{
	if (Signs.top() == '(')
		return;
	HugeInt n2 = Number.top(); Number.pop();
	HugeInt n1 = Number.top(); Number.pop();

	switch (Signs.top())
	{
	case '-': Number.push(n1 - n2); break;
	case '+': Number.push(n1 + n2); break;
	case '*': Number.push(n1 * n2); break;
	case '/': Number.push(n1 / n2); break;
	}
	Signs.pop();
}
void Equations::CallingLowerFunction(char ch)
{
	if (Signs.size() == 0 or Signs.top() == '(')
		return;
	if (IsHigherPrecedence(ch))
		return;
	Calulating();
	CallingLowerFunction(ch);
}
void Equations::CalculationsAtLast()
{
	if (Signs.size() == 0)
		return;
	Calulating();
	CalculationsAtLast();
}
void Equations::InFixToPostNotation()
{
	string R;
	bool IsAssigned = false;
	for (int ri = 0; ri < Expression.size(); ri++)
	{
		if (ri != 0 and (FirstNegative() or ((Expression[ri] == '-' or Expression[ri] == '+') and Expression[ri - 1] == '(')))
		{
			R += Expression[ri - 1];
			IsAssigned = true;
		}
		if (isdigit(Expression[ri]))
		{
			while (isdigit(Expression[ri]))
			{
				R += Expression[ri];
				ri++;
			}
			ri--;
			Number.push(R);
			R.clear();
		}
		else if (IsSign(Expression[ri]) and IsAssigned == false)
		{
			if (Signs.size() == 0)
				Signs.push((Expression[ri]));
			else if (Expression[ri] == '(')
			{
				Signs.push((Expression[ri]));
			}
			else if (Expression[ri] == ')')
			{
				while (Signs.top() != '(')
				{
					Calulating();
				}
				Signs.pop();
			}
			else
			{
				if (IsHigherPrecedence(Expression[ri]))
					Signs.push((Expression[ri]));
				else if (IsLowerPrecedence(Expression[ri]))
				{
					CallingLowerFunction(Expression[ri]);
					Signs.push(Expression[ri]);
				}
				else if (IsEqualPrecedence(Expression[ri]))
				{
					CallingLowerFunction(Expression[ri]);
					Signs.push(Expression[ri]);
				}
			}
		}
		IsAssigned = false;
	}
	CalculationsAtLast();
}
void Equations::PrintNumberStack()
{
	if (Number.empty())
		return;
	HugeInt x = Number.top();
	Number.pop();
	cout << x << ' ';
	PrintNumberStack();
	Number.push(x);
}


