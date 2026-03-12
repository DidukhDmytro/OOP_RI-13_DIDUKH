#include "pch.h"
#include "CppUnitTest.h"
#include "Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTests
{
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(TestMatrixAddition)
		{
			Matrix A(2, 2);
			Matrix B(2, 2);

			A.setElement(0, 0, 1);
			A.setElement(0, 1, 2);
			A.setElement(1, 0, 3);
			A.setElement(1, 1, 4);

			B.setElement(0, 0, 5);
			B.setElement(0, 1, 6);
			B.setElement(1, 0, 7);
			B.setElement(1, 1, 8);

			Matrix C = A + B;

			Assert::AreEqual(6, C.getElement(0, 0));
			Assert::AreEqual(8, C.getElement(0, 1));
			Assert::AreEqual(10, C.getElement(1, 0));
			Assert::AreEqual(12, C.getElement(1, 1));
		}
	};
}