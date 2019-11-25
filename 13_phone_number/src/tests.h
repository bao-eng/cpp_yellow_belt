#pragma once

#include "test_runner.h"
#include "phone_number.h"

void Test1() {
	{
    	PhoneNumber phone("+7-495-111-22-33");
		AssertEqual(phone.GetCountryCode(), "7","CountryCode");
		AssertEqual(phone.GetCityCode(), "495","CityCode");
		AssertEqual(phone.GetLocalNumber(), "111-22-33","LocalNumber");
		AssertEqual(phone.GetInternationalNumber(), "+7-495-111-22-33","InternationalNumber");
	}
}

void Test2() {
	{
    	PhoneNumber phone("+7-495-1112233");
		AssertEqual(phone.GetCountryCode(), "7","CountryCode");
		AssertEqual(phone.GetCityCode(), "495","CityCode");
		AssertEqual(phone.GetLocalNumber(), "1112233","LocalNumber");
		AssertEqual(phone.GetInternationalNumber(), "+7-495-1112233","InternationalNumber");
	}
}

void Test3() {
	{
    	PhoneNumber phone("+323-22-460002");
		AssertEqual(phone.GetCountryCode(), "323","CountryCode");
		AssertEqual(phone.GetCityCode(), "22","CityCode");
		AssertEqual(phone.GetLocalNumber(), "460002","LocalNumber");
		AssertEqual(phone.GetInternationalNumber(), "+323-22-460002","InternationalNumber");
	}
}

void Test4() {
	{
    	PhoneNumber phone("+1-2-coursera-cpp");
		AssertEqual(phone.GetCountryCode(), "1","CountryCode");
		AssertEqual(phone.GetCityCode(), "2","CityCode");
		AssertEqual(phone.GetLocalNumber(), "coursera-cpp","LocalNumber");
		AssertEqual(phone.GetInternationalNumber(), "+1-2-coursera-cpp","InternationalNumber");
	}
}

void Test5() {
		try{
			PhoneNumber phone("1-2-333");
		}catch (exception& ex) {
		}
}

void Test6() {
		try{
			PhoneNumber phone("+7-1233");
		}catch (exception& ex) {
		}
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(Test1, "Test1: +7-495-111-22-33");
	tr.RunTest(Test2, "Test2: +7-495-1112233");
	tr.RunTest(Test3, "Test3: +323-22-460002");
	tr.RunTest(Test4, "Test4: +1-2-coursera-cpp");

	tr.RunTest(Test5, "Test5: 1-2-333 (wrong)");
	tr.RunTest(Test6, "Test6: +7-1233 (wrong)");
}
