#include "TFormula.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int TCalc::GetPriority(char m) {
	switch (m)
	{
	case '(':return 0;
	case '+':return 1;
	case '-':return 1;
	case '*':return 2;
	case '/':return 2;
	case '^':return 3;
	}
	throw - 1;
}

void TCalc::ToPostFix() {
	postfix = "";
	stop.clear();
	string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '(') stop.Push(tmp[i]);
		if (tmp[i] >= '0'&&tmp[i] <= '9') postfix += tmp[i];
		if (tmp[i] == ')') {
			while (stop.Top() != '(')postfix += stop.Pop();
			stop.Pop();
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^')
		{
			postfix += ' ';
			while (GetPriority(tmp[i]) <= GetPriority(stop.Top()))postfix += stop.Pop();
			stop.Push(tmp[i]);
		}
		if (tmp[i] == 's' || tmp[i] == 'c')
		{
			postfix += ' ';
			postfix += tmp[i];
			i += 2;
		}
	}
}

void TCalc::SetInfix(string inf) {
	infix = inf;
}

string TCalc::GetPostfix() {
	this->ToPostFix();
	return postfix;
}

double TCalc::Calc() {
	double num1, num2, res;
	stnum.clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^' || postfix[i] == 's' || postfix[i] == 'c') {
			num2 = stnum.Pop();
			num1 = stnum.Pop();
			switch (postfix[i])
			{
			case '+':res = num1 + num2;
				break;
			case '-':res = num1 - num2;
				break;
			case '*':res = num1 * num2;
				break;
			case '/':res = num1 / num2;
				break;
			case '^':res = pow(num1, num2);
				break;
			case 's':res = sin(num2);
				break;
			case 'c':res = cos(num2);
				break;
			}
			stnum.Push(res);
		}
		if (postfix[i] >= '0'&&postfix[i] <= '9') {
			char *p;
			double x;
			x = strtod(&postfix[i], &p);
			stnum.Push(x);
			int l = p - &postfix[i];
			i += l - 1;
		}
	}
	TStack<double> tmp(stnum);
	tmp.Pop();
	if (tmp.IsEmpty())
		return stnum.Top();
	else
		throw - 1;
}