#include<iostream>
#include<windows.h>
#include"Homeworck class.h"
using namespace std;
using namespace homework;

void main()
{
	cout << "Select : Rectangle - 0 , Fraction - 1" << endl;
	int select;
	cin >> select;
	if (!select)
	{
		cout << "CRectangle __________________________________________________________" << endl;
		cout << endl;
		CRectangle r;
		int x1, y1, x2, y2;
		cout << "x1 y1" << endl;
		cin >> x1 >> y1;
		cout << "x2 y2" << endl;
		cin >> x2 >> y2;
		r.SetRect(x1, y1, x2, y2);
		r.Print();
		if (x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0)
		{
			cout << "\n\tThank you! \n\t When processing your request, we did not need protection from a fool.\n\t You are not a fool! =)\n\t Take this cookies " << char(15) << char(3) << char(15) << char(9) << endl;
		}
	}
	else
	{
		cout << endl;
		cout << endl;
		cout << "Fraction __________________________________________________________" << endl;
		cout << endl;
		Fraction fr1(5, 20);
		Fraction fr2(6, 30);
		Fraction frSum;
		cout << "Sum = ";
		frSum = fr1.Add(fr2);
		cout << frSum.GetNum() << "/" << frSum.GetDenom() << endl;
		cout << "Decimal : " << frSum.GetDecimal() << endl;
	}
}