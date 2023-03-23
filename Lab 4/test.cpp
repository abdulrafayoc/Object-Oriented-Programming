#include "pch.h"
#include "../LabTask/Header.h"

//------------------------Problem 3--------------------------
TEST(Problem3_1, Palidrome) {
	EXPECT_EQ(false, isPalidrome("Don’tnod"));
}
TEST(Problem3_2, Palidrome) {
	char* c1 = "Aaibohphobia";
	EXPECT_EQ(false, isPalidrome(c1));
}
TEST(Problem3_3, Palidrome) {
	char* c1 = "ufotofu";
	EXPECT_EQ(true, isPalidrome(c1));
}
//------------------------Problem 4--------------------------
TEST(Problem4_1, Prime_Number) {
	EXPECT_EQ(true, PrimeNumber(967));
}
TEST(Problem4_2, Prime_Number) {
	EXPECT_EQ(false, PrimeNumber(267));
}
TEST(Problem4_3, Prime_Number) {
	EXPECT_EQ(false, PrimeNumber(702));
}