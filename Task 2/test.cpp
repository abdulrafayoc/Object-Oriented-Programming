#include "pch.h"
//#include "../Lab_Task/Task1.h"
#include "../Lab_Task/Task2.h"
#include "../Lab_Task/Task3.h"
#include "../Lab_Task/Task4.h"
#include "../Lab_Task/Task5.h"


//.............Problem 2.............
TEST(Problem2_1, AddNum) {
	int array[] = { 4,6,9,1,22,5,98,23,65,29 };
	int ret[] = { 98,71,65,29,23,22,9,6,5,4,3,1 };
	EXPECT_EQ(ret, addNum(array, 10, 71, 3));
}
TEST(Problem2_2, AddNum) {
	int array[] = { 56,9,12,35,0,1,24,38,41 };
	int ret[] = { 56,50,41,38,35,27,24,12,9,1,0 };
	EXPECT_EQ(ret, addNum(array, 9, 27, 50));
}
TEST(Problem2_3, AddNum) {
	int array[] = { 6,9,2,5,0,11,2,4,3 };
	int ret[] = { 23,11,9,6,5,4,3,2,2,1,0 };
	EXPECT_EQ(ret, addNum(array, 9, 1, 23));
}

//.............Problem 3.............
TEST(Problem3_1, SortAndReverse) {
	int array[] = { 4,6,9,1,22,5,98,23,65,29 };
	EXPECT_EQ(121, sortNreverse(array, 10));
}
TEST(Problem3_2, SortAndReverse) {
	int array[] = { 56,9,12,35,0,1,24,38,41 };
	EXPECT_EQ(80, sortNreverse(array, 9));
}
TEST(Problem3_3, SortAndReverse) {
	int array[] = { 6,9,2,5,0,11,2,4,3 };
	EXPECT_EQ(15, sortNreverse(array, 9));
}

//.............Problem 4.............
TEST(Problem4_1, combineArray) {
	char* c1 = "Lab tasks time";
	char* c2 = " is over";
	string c3 = "Lab tasks time is over";
	EXPECT_EQ(c3, combineArr(c1, c2));
}
TEST(Problem4_2, combineArray) {
	char* c1 = "Lets do it";
	char* c2 = "now ";
	char* c3 = "Lets do itnow ";
	EXPECT_EQ(c3, combineArr(c1, c2));
}
TEST(Problem4_3, combineArray) {
	char* c1 = "OOP lab is boring a";
	char* c2 = "nd difficult";
	char* c3 = "OOP lab is boring and difficult";
	EXPECT_EQ(c3, combineArr(c1, c2));
}

//.............Problem 5.............
TEST(Problem5_1, sameChars) {
	EXPECT_EQ(false, sameChar("debit card", "bad credit"));
}
TEST(Problem5_2, sameChars) {
	char* c1 = "Vacations time";
	char* c2 = "I am not active";
	EXPECT_EQ(false, sameChar(c1, c2));
}
TEST(Problem5_3, sameChars) {
	char* c1 = "dormitory";
	char* c2 = "dirty room";
	EXPECT_EQ(false, sameChar(c1, c2));
}
/*
//.............Problem 6.............
TEST(Problem6_1, ReturnSum) {
	int array[] = { 4,6,9,1,22,5,98,23,65,29 };
	EXPECT_EQ(19, returnSum(array, 10, 19));
}
TEST(Problem6_2, ReturnSum) {
	int array[] = { 56,9,12,35,0,1,24,38,41 };
	EXPECT_EQ(47, returnSum(array, 9, 47));
}
TEST(Problem6_3, ReturnSum) {
	int array[] = { 6,9,2,5,0,11,2,4,3 };
	EXPECT_EQ(-1, returnSum(array, 9, 24));
}


//.............Problem 7.............
TEST(Problem7_1, matchCharacters) {
	EXPECT_EQ(TRUE, matchChar("Don’t nod"));
}
TEST(Problem7_2, matchCharacters) {
	char* c1 = "Aibohphobiaa";
	EXPECT_EQ(FALSE, matchChar(c1));
}
TEST(Problem7_3, matchCharacters) {
	char* c1 = "UFO tofu";
	EXPECT_EQ(TRUE, matchChar(c1));
}

//.............Problem 8.............
TEST(Problem8_1, rearrangeArray) {
	int array[] = { 4,6,9,1,22,5,98,23,65,29 };
	int ret[] = { 29,6,9,1,22,5,65,23,98,4 };
	EXPECT_EQ(ret, rearrangeArr(array, 10));
}
TEST(Problem8_2, rearrangeArray) {
	int array[] = { 56,9,12,35,0,1,24,38,41 };
	int ret[] = { 38,9,12,35,0,41,24,56,1 };
	EXPECT_EQ(ret, rearrangeArr(array, 9));
}
TEST(Problem8_3, rearrangeArray) {
	int array[] = { 6,9,2,5,0,11,2,4,3 };
	int ret[] = { 6,9,3,5,0,4,2,11,2 };
	EXPECT_EQ(ret, rearrangeArr(array, 9));
}
*/