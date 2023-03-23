#pragma once
#include <iostream>

using namespace std;

class Course
{
private:
	string courseCode;
	string courseTitle;
	int creditHours;
	char section;
	int repeatCourse;
public:
	Course()
	{
		courseCode = "CS 105";
		courseTitle = "Computer Programming";
		creditHours = 3;
		section = 'A';
		repeatCourse = 0;
	}
	Course(string cc, string ct, int ch, char s, int rc)
	{
		this->courseCode = cc;
		this->courseTitle = ct;
		this->creditHours = ch;
		this->section = s;
		this->repeatCourse = rc;
	}
	Course(Course& c)
	{
		courseCode = c.courseCode;
		courseTitle = c.courseTitle;
		creditHours = c.creditHours;
		section = c.section;
		repeatCourse = c.repeatCourse;
	}
	void setCourseCode(string courseCode)
	{
		this->courseCode = courseCode;
	}
	void setCourseTitle(string courseTitle)
	{
		this->courseTitle = courseTitle;
	}
	void setCreditHours(int creditHours)
	{
		this->creditHours = creditHours;
	}
	void setSection(char section)
	{
		this->section = section;
	}
	void setRepeatCourse(int repeatCourse)
	{
		this->repeatCourse = repeatCourse;
	}
	string getCourseCode()
	{
		return courseCode;
	}
	string getCourseTitle()
	{
		return courseTitle;
	}
	int getCreditHours()
	{
		return creditHours;
	}
	char getSection()
	{
		return section;
	}
	int getRepeatCount()
	{
		return repeatCourse;
	}

};

class Semester
{
private:
	string semesterCode;
	int courseCount;
	Course* courseArr = new Course[courseCount];
public:
	Semester()
	{
		semesterCode = 1;
		courseCount = 0;
	}
	Semester(int sc, int cc, Course* courseArr)
	{
		this->semesterCode = sc;
		this->courseCount = cc;
		this->courseArr = courseArr;
	}
	Semester(Semester& s)
	{
		semesterCode = s.semesterCode;
		courseCount = s.courseCount;
	}
	void setSemesterCode(string semesterCode)
	{
		this->semesterCode = semesterCode;
	}
	void setCourseCount(int courseCount)
	{
		this->courseCount = courseCount;
	}
	string getSemesterCode()
	{
		return semesterCode;
	}
	int getCourseCount()
	{
		return courseCount;
	}
	void setCourses(Course* courses)
	{
		for (int i = 0; i < courseCount; i++)
		{
			this->courseArr[i] = courses[i];
		}
	}
	Course* getCourseArr()
	{
		return courseArr;
	}
};

int getCreditHoursCount(Semester sem)
{
	int creditHourCount = 0;
	for (int i = 0; i < sem.getCourseCount(); i++)
	{
		creditHourCount += sem.getCourseArr()[i].getCreditHours();
	}
	return creditHourCount;
}

bool findCourseInSemesterRegistration(Semester sem, string courseCode)
{
	for (int i = 0; i < sem.getCourseCount(); i++)
	{
		if (sem.getCourseArr()[i].getCourseCode() == courseCode)
			return true;
	}
	return false;
}
