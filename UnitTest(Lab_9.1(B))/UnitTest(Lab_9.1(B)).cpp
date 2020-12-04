#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1(B)/Lab_9.1(B).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab91B
{
	TEST_CLASS(UnitTestLab91B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int kil_student = 2;
			student* s = new student[kil_student];
			s[0].prizv = "werwer";                  s[1].prizv = "qqwrq";
			s[0].kurs = 4;                        s[1].kurs = 4;
			s[0].specialization = (Special)0;     s[1].specialization = (Special)1;
			s[0].phisuka = 4;                     s[1].phisuka = 2;
			s[0].matematic = 4;                   s[1].matematic = 3;
			s[0].programing = 5;                  s[1].chuslo_metod = 5;

			double l = find_prozent(s, kil_student);

			Assert::AreEqual(l, 50.0);
		}
	};
}
