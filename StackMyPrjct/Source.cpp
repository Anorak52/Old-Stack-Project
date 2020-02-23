
#include <iostream>
#include "TFormula.h"
#include "TStack.h"
using namespace std;

int Check(string str, int matr[], int &k)
{
	TStack <int> st(10);
	int a = 0;

	k = 0;
	int err = 0;
	for (int i = 0; i < str.length(); i++)
	{


		if (str[i] == '(')
		{
			a++;
			st.Push(a);
		}

		else if (str[i] == ')')
		{
			a++;

			if (st.IsEmpty())
			{
				matr[k++] = 0;
				err++;
			}
			else
			{

				matr[k++] = st.Pop();
			}
			matr[k++] = a;

		}
	}
	while (!st.IsEmpty())
	{
		matr[k++] = st.Pop();
		matr[k++] = 0;
		err++;
	}
	//k--;
	return err;
}

void main()
{
	TStack <char> st(10);

	TCalc tcal;
	string exp;
	int flag = 1;
	while (flag)
	{
		cout << "Input ";
		cin >> exp;
		int len = 2 * exp.length();

		int *braket;
		braket = new int[len];
		int err, size;

		err = Check(exp, braket, size);
		cout << "\n___Error___\n" << err;
		cout << "\n";

		int m = 0;
		cout << "\n___Brackets___\n";
		for (int i = 0; i < size; i++)
		{
			cout << braket[i] << " ";
			m++;
			if (m % 2 == 0)
				cout << "\n";
		}

		cout << "\n___Stack___\n";

		if (err)
			cout << "Error\n";
		else {
			tcal.SetInfix(exp);
			cout << tcal.GetPostfix() << endl;
			cout << "\n___Answer___\n";
			cout << tcal.Calc();
		}

		cout << "\n\n1 to continue 0 to exit ";
		cin >> flag;
	}
}
