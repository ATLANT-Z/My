

namespace homework
{
	class CRectangle;
	class Fraction;

	class CRectangle
	{

	private:
		int left, right, top, bottom;

	public:
		CRectangle();
		CRectangle(const unsigned int l, const unsigned int t, const unsigned int r, const unsigned int b);

		int Height();
		int Width();
		bool IsRectNull();
		bool PtInRect(const int x, const int y);

		void SetRect(const int x1, const int y1, const int x2, const int y2);
		void SetRectEmpty();
		void InflateRect(const unsigned int l, const unsigned int t, const unsigned int r, const unsigned int b);
		void InflateRect(const unsigned int height, const unsigned int width);

		void DeflateRect(const unsigned int l, const unsigned int t, const unsigned int r, const unsigned int b);
		void DeflateRect(const unsigned int height, const unsigned int width);


		void OffsetRect(const unsigned int x, const unsigned int y);

		void NormalizeRect();

		void Print();
	};

	class Fraction
	{
	private:
		int denominator, numerator;
	public:
		Fraction();
		Fraction(const int num, const int denom);

		void SetNum(const int num);
		void SetDenom(const int denom);

		int GetNum();
		int GetDenom();
		Fraction Add(const Fraction & fr_send);
		Fraction Sub(const Fraction & fr_send);
		Fraction Multi(const Fraction & fr_send);
		Fraction Div(const Fraction & fr_send);
		int IntegerOfFrac();
		double GetDecimal();
	};

}



