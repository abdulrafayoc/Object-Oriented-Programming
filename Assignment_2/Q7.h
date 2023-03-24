#include <iostream>

using namespace std;

class Student {
private:
    int stdID;
    string Name;
    string* coursecodes;
    int numCourses;
    int* courseGrades;
    float gpa;
public:
    int getStdID() {
        return stdID;
    }
    void setStdID(int id) {
        stdID = id;
    }
    string getName() {
        return Name;
    }
    void setName(string firstName) {
        Name = firstName;
    }
    int  getNumCourses() {
        return numCourses;
    }
    void setNumCourses(int num) {
        numCourses = num;
		coursecodes = new string[numCourses];
        courseGrades = new int[numCourses];
    }
    string getCourseCodes(int i) {
        return coursecodes[i];
    }
    int getCourseGrade(int i) {
        return courseGrades[i];
    }
    void setCourseGrade(string courseCodes, int grades) {
        for (int i = 0; i < numCourses; i++) {
            if (courseCodes == coursecodes[i]) {
                courseGrades[i] = grades;
            }
        }
    }
    float getGPA() {
        return gpa;
    }
    void calcGPA() {
        int sum = 0;
        for (int i = 0; i < numCourses; i++) {
            sum += courseGrades[i];
        }
        gpa = ((sum / numCourses)/20)-1;
    }
    void addCourse(string courseCode, int grade) {
        string* temp = new string[numCourses + 1];
        int* temp2 = new int[numCourses + 1];
        for (int i = 0; i < numCourses; i++) {
            temp[i] = coursecodes[i];
            temp2[i] = courseGrades[i];
        }
        temp[numCourses] = courseCode;
        temp2[numCourses] = grade;
        delete[] coursecodes;
        delete[] courseGrades;
        coursecodes = temp;
        courseGrades = temp2;
        numCourses++;
    }
};

Student getStudentAt(Student students[], int index) {
    return students[index];
}
float calcClassGPA(Student students[], int numStudents) {
    float sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += students[i].getGPA();
    }
    return sum / numStudents;
}
float getMaxGPA(Student students[], int numStudents) {
    float max = students[0].getGPA();
    for (int i = 1; i < numStudents; i++) {
        if (students[i].getGPA() > max) {
            max = students[i].getGPA();
        }
    }
    return max;
}
int getMinGPA(Student students[], int numStudents) {
    float min = students[0].getGPA();
    for (int i = 1; i < numStudents; i++) {
        if (students[i].getGPA() < min) {
            min = students[i].getGPA();
        }
    }
    return min;
}
void printStudentRecord(Student student) {
    cout << "Student ID: " << student.getStdID() << endl;
    cout << "Student Name: " << student.getName() << endl;
    cout << "Student Courses: " << endl;
    for (int i = 0; i < student.getNumCourses(); i++) {
        cout << student.getCourseCodes(i) << " " << student.getCourseGrade(i) << endl;
    }
    cout << "Student GPA: " << student.getGPA() << endl;
}
void printAllStudentRecord(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Student ID: " << students[i].getStdID() << endl;
        cout << "Student Name: " << students[i].getName() << endl;
        cout << "Student Courses: " << endl;
        for (int j = 0; j < students[i].getNumCourses(); j++) {
            cout << students[i].getCourseCodes(j) << " " << students[i].getCourseGrade(j) << endl;
        }
        cout << "Student GPA: " << students[i].getGPA() << endl;
    }
}
