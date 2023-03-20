#include "pch.h"
#include "../Lab7/Header1.h"
#include "../Lab7/Header2.h"
#include "../Lab7/Header3.h"
#include "../Lab7/Header4.h"

TEST(Task_1, TestCase1) {
	Laptop obj;
	obj.setMacAddress("123.465.789");
	obj.setCompanyName("Dell");
	obj.setModel("Inspiron");

	EXPECT_EQ("123.465.789", obj.getMacAddress());
	EXPECT_EQ("Dell", obj.getName());
	EXPECT_EQ("Inspiron", obj.getModel());

}

TEST(Task_1, TestCase2) {
	Laptop obj("Inspiron", "123.456.789", "Dell");
	EXPECT_EQ("123.456.789", obj.getMacAddress());
	EXPECT_EQ("Dell", obj.getName());
	EXPECT_EQ("Inspiron", obj.getModel());
}

TEST(Task_2, TestCase1) {
	Course obj("CS250", "Fundamental Programming", 3, 'A', 2), obj2(obj);
	EXPECT_EQ("CS250", obj.getCourseCode());
	EXPECT_EQ("Fundamental Programming", obj.getCourseTitle());
	EXPECT_EQ(3, obj.getCreditHours());
	EXPECT_EQ('A', obj.getSection());
	EXPECT_EQ(2, obj.getRepeatCount());

	obj.setCourseTitle("Object Oriented Lab");
	EXPECT_EQ("Object Oriented Lab", obj.getCourseTitle());
}

TEST(Task_2, TestCase2) {
	Course obj("CS250", "Fundamental Programming", 3, 'A', 2), obj2(obj);
	obj2.setCourseTitle("Object Oriented Programming");
	EXPECT_EQ("Object Oriented Programming", obj2.getCourseTitle());
}

TEST(Task_2, TestCase3) {
	Course course1("CS250", "Fundamental Programming", 3, 'A', 2);
	Course course2("CS251", "Object Oriented Programming", 3, 'A', 1);
	Course course3("CS252", "Data Structures", 3, 'A', 2);
	Course course4("CS253", "Database Lab", 3, 'A', 2);
	Course course5("CS254", "Design and Algorithms", 3, 'A', 2);

	Course courses[5] = {
		course1,
		course2,
		course3,
		course4,
		course5
	};

	Semester semester;
	semester.setCourseCount(5);
	semester.setCourses(courses);
	semester.setSemesterCode("Spring 2023");

	EXPECT_EQ(15, getCreditHoursCount(semester));
	EXPECT_EQ(true, findCourseInSemesterRegistration(semester, "CS251"));
}

TEST(Task_3, TestCase1) {
	Account account;
	account.deposit(2000);
	EXPECT_EQ(1, account.getAccountID());
}

TEST(Task_3, TestCase2) {
	Account account;
	account.deposit(5000);
	EXPECT_EQ(2, account.getAccountID());
	EXPECT_EQ(5000, account.getBalance());
	account.withdraw(2000);
	EXPECT_EQ(3000, account.getBalance());
}

//TEST(Task_4, TestCase1) {
//	Circle circle;
//	circle.setRadius(2);
//	EXPECT_EQ(2, circle.getRadius());
//	EXPECT_EQ(12.56, circle.getArea());
//}
//
//TEST(Task_4, TestCase2) {
//	Circle circle(2), circle2(circle);
//	EXPECT_EQ(2, circle2.getRadius());
//	EXPECT_DOUBLE_EQ(12.56, circle2.getArea());
//}
