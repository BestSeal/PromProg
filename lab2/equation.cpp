#include "pch.h"
#include "equation.h"
#include <iostream>
#include <cmath>
#include "equation.h"

using namespace std;

namespace equation
{

	std::tuple<int, double, double, string> solve(double a, double b, double c, double d, double e, double f)
	{

		if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))

		{

			return { 5, 0, 0, "" };

		}

		else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))

		{

			double y = (a * f - c * e) / (a * d - c * b);

			double x = (d * e - b * f) / (d * a - b * c);

			return { 2, x, y , "" };

		}

		else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) ||

			(a == 0 && c == 0 && e / b != f / d) ||

			(b == 0 && d == 0 && e / a != f / c) ||

			(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))

		{

			if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||

				(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))

			{

				double y;

				if (b == 0)

					y = f / d;

				else if (d == 0)

					y = e / b;

				else if (e == 0 || f == 0)

					y = 0;

				return { 4, 0, y, "" };

			}

			else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||

				(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))

			{
				  

				double x;

				if (a == 0)

					x = f / c;

				else if (c == 0)

					x = e / a;

				else if (e == 0 || f == 0)

					x = 0;

				return { 3, x, 0 , "" };

			}

			else

				return { 0, 0, 0, "" };

		}

		else if (a == 0 && c == 0)

		{

			double y;

			if (e == 0)

				y = f / d;

			else if (f == 0)

				y = e / b;

			else

				y = e / b;

			return { 4, 0, y, "" };

		}

		else if (b == 0 && d == 0)

		{

			double x;

			if (e == 0)

				x = f / c;

			else if (f == 0)

				x = e / a;

			else

				x = e / a;

			return { 3, x, 0 , "" };

		}

		else if (b == 0 && e == 0)

		{

			double k, n;

			k = -c / d;

			n = f / d;

			return  { 1, k, n , "" };

		}

		else if (d == 0 && f == 0)

		{

			double k, n;

			k = -a / b;

			n = e / b;

			return { 1, k, n , "" };

		}

		else if (a == 0 && e == 0)

		{

			double k, n;

			k = -d / c;

			n = f / c;

			return { 1, k, n, "" };

		}

		else if (c == 0 && f == 0)

		{

			double k, n;

			k = -b / a;

			n = e / a;

			return { 1, k, n , "" };

		}

		else if ((a / b == c / d))

		{

			double k, n;

			k = -c / d;

			n = f / d;

			return  { 1, k, n , "" };

		}

		else

		{

			return { 0,0,0 , "Are you kidding me?" };

		}
	}
}