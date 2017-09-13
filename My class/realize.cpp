#include<iostream>
#include<windows.h>
#include"Homeworck class.h"
using namespace std;

namespace homework
{
	CRectangle::CRectangle()
	{
		left = 5;
		right = 10;
		top = 5;
		bottom = 10;
	}
	CRectangle::CRectangle(const unsigned int l, const unsigned int t, const unsigned int r, const unsigned int b)
	{
		left = l;
		right = r;
		top = t;
		bottom = b;
	}

	int CRectangle::Height()
	{
		return bottom - top;
	}
	int CRectangle::Width()
	{
		return right - left;
	}
	bool CRectangle::IsRectNull()
	{
		if (left == right == top == bottom == 0)
			return true;
		else
			return false;
	}
	bool CRectangle::PtInRect(const int x, const int y)
	{
		if (x > left && y > top && x < right && y < bottom)
			return true;
		else
			return false;
	}

	void CRectangle::SetRect(const int x1, const int y1, const int x2, const int y2)
	{
		SetRectEmpty();
		
			left += x1;
			right += x2;
			top += y1;
			bottom += y2;

		NormalizeRect();
	}
	void CRectangle::SetRectEmpty()
	{
		left = 0;
		right = 0;
		top = 0;
		bottom = 0;
	}
	void CRectangle::InflateRect(const unsigned int height, const unsigned int width)
	{
		int h_left = (width - (right - left)) / 2;
		left -= h_left;
		right += h_left;

		int h_top = (height - (bottom - top)) / 2;
		top -= h_top;
		bottom += h_top;

		if (left < 0)
		{
			right -= left;
			left = 0;
		}
		if (top < 0)
		{
			bottom -= top;
			top = 0;
		}

	}
	void CRectangle::InflateRect(const unsigned int l, const unsigned int t, const unsigned int r, const unsigned int b)
	{
		int diff_h, diff_w;
		diff_h = (b - t) - (bottom - top);
		diff_w = (r - l) - (right - left);

		int half_top = diff_h / 2;
		top -= half_top;
		bottom += half_top;

		int half_left = diff_w / 2;
		left -= half_left;
		right += half_left;

		if (left < 0)
		{
			right -= left;
			left = 0;
		}
		if (top < 0)
		{
			bottom -= top;
			top = 0;
		}

	}

	void CRectangle::DeflateRect(const unsigned int height, const unsigned int width)
	{
		int h_left = ((right - left) - width) / 2;
		left += h_left;
		right -= h_left;

		int h_top = ((bottom - top) - height) / 2;
		top += h_top;
		bottom -= h_top;

	}
	void CRectangle::DeflateRect(const unsigned int l, const unsigned int t, const unsigned int r, const unsigned int b)
	{
		int diff_h, diff_w;
		diff_h = (bottom - top) - (b - t);
		diff_w = (right - left) - (r - l);

		int half_top = diff_h / 2;
		top += half_top;
		bottom -= half_top;

		int half_left = diff_w / 2;
		left += half_left;
		right -= half_left;
	}


	void CRectangle::OffsetRect(const unsigned int x, const unsigned int y)
	{
			left += x;
			right += x;
			top += y;
			bottom += y;	
	}

	void CRectangle::NormalizeRect()
	{
		if (left > right)
		{
			int t_x = left;
			left = right;
			right = t_x;
		}
		if (top > bottom)
		{
			int t_y = top;
			top = bottom;
			bottom = t_y;
		}
	}

	void CRectangle::Print()
	{
		NormalizeRect();
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		char s = '*';
		for (int y = top; y < bottom; y++)
		{
			for (int x = left; x < right; x++)
			{
				SetConsoleCursorPosition(handle, {SHORT( x + 12),SHORT( y) });
				cout << s;
			}
			cout << endl;
		}
	}




	Fraction :: Fraction()
	{
		numerator = 1;
		denominator = 1;
	}
	Fraction::Fraction(const int num, const int denom)
	{
		numerator = num;
		if (denom == 0)
			denominator = 1;
		else
			denominator = denom;
	}

	void Fraction::SetNum(const int num)
	{
		numerator = num;
	}
	void Fraction::SetDenom(const int denom)
	{
		if (denom == 0)
			denominator = 1;
		else
			denominator = denom;
	}

	int Fraction::GetNum()
	{
		return numerator;
	}
	int Fraction::GetDenom()
	{
		return denominator;
	}

	Fraction Fraction::Add(const Fraction & fr_send  )
	{
		Fraction fr_temp;

		if (denominator == fr_send.denominator)
		{
			fr_temp.numerator = numerator + fr_send.numerator;
		}
		else
		{
			fr_temp.denominator = denominator * fr_send.denominator;
			fr_temp.numerator = numerator * fr_send.denominator + fr_send.numerator * denominator ;
		}
		return fr_temp;
	}
	Fraction Fraction::Sub(const Fraction & fr_send )
	{
		Fraction fr_temp;

		if (denominator == fr_send.denominator)
		{
			fr_temp.numerator = numerator + fr_send.numerator;
		}
		else
		{
			fr_temp.denominator = denominator * fr_send.denominator;
			fr_temp.numerator = numerator * fr_send.denominator - fr_send.numerator * denominator;
		}
		return fr_temp;
	}
	Fraction Fraction::Multi(const Fraction & fr_send)
	{
		Fraction fr_temp;

		fr_temp.denominator = denominator * fr_send.denominator;
		fr_temp.numerator = numerator * fr_send.numerator;
		return fr_temp;

	}
	Fraction Fraction::Div(const Fraction & fr_send)
	{
		Fraction fr_temp;
		
		fr_temp.denominator = denominator * fr_send.numerator;
		fr_temp.numerator = numerator * fr_send.denominator;
		return fr_temp;
	}
	int Fraction::IntegerOfFrac()
	{
		int integer = numerator / denominator;
		return integer;
	}
	double Fraction::GetDecimal()
	{
		double temp = double(numerator) / double(denominator);
		return temp;
	}
}




