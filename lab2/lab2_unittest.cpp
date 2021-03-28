#include "pch.h"
#include "CppUnitTest.h"
#include "equation.h"
#include <tuple>
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2unittest
{
	TEST_CLASS(lab2unittest)
	{
	public:
		
		TEST_METHOD(AnyNumbers)
		{
			double a = 0;
			double b = 0;
			double c = 0;
			double d = 0;
			double e = 0;
			double f = 0;
			std::tuple<int, double, double, std::string> result = equation::solve(a,b,c,d,e,f);
			std::tuple<int, double, double, std::string> expected = { 5, 0, 0, ""};
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(OneRoot)
		{
			double a = 2;
			double b = -4;
			double e = -6;

			double c = 2;
			double d = 1;
			double f = 4;
			std::tuple<int, double, double, std::string> result = equation::solve(a, b, c, d, e, f);
			std::tuple<int, double, double, std::string> expected = { 2, 1, 2, "" };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(NoRoots)
		{
			double a = 3;
			double b = -4;
			double e = 12;

			double c = 3;
			double d = -4;
			double f = 18;
			std::tuple<int, double, double, std::string> result = equation::solve(a, b, c, d, e, f);
			std::tuple<int, double, double, std::string> expected = { 0, 0, 0, "" };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(InfNumOfRoots)
		{
			double a = 7;
			double b = 6;
			double e = -42;

			double c = 3.5;
			double d = 3;
			double f = -21;
			std::tuple<int, double, double, std::string> result = equation::solve(a, b, c, d, e, f);
			std::tuple<int, double, double, std::string> expected = { 1, -c/d, f/d, "" };
			Assert::IsTrue(result == expected);
		}
	};
}
