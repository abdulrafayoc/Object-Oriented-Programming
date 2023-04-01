//Question 1
int main()
{
    Image img(3, 3, 3);
    Pixel p(255, 255, 255);
    img.fill(p);
    cout << img.getAverageBrightness() << endl;
    cout << img.getMaximumBrightness(0) << endl;
    cout << img.countBrightPixel() << endl;
    img.transposePixel(0);
    img.clear();
    return 0;
}
//Question 2

int main()
{
    char* topping = new char[7];
    cin >> topping;
    char* name = new char[12];
    cin >> name;
    char* size = new char[6];
    cin >> size;
    Pizza pizza1;
    Pizza pizza2(topping, 100);
    Pizza pizza3(topping, 100, name, size, false);
    Pizza pizza4(pizza3);
    pizza4.setTopping(topping);
    pizza4.setPrice(200);
    pizza4.setName(name);
    pizza4.setSize(size);
    pizza4.makePizza();
    cout << "Pizza 1 Topping: " << pizza1.getTopping() << endl;
    cout << "Pizza 1 Price: " << pizza1.getPrice() << endl;
    cout << "Pizza 1 Name: " << pizza1.getName() << endl;
    cout << "Pizza 1 Size: " << pizza1.getSize() << endl;
    cout << "Pizza 1 Status: " << pizza1.check_status() << endl;
    cout << "Pizza 2 Topping: " << pizza2.getTopping() << endl;
    cout << "Pizza 2 Price: " << pizza2.getPrice() << endl;
    cout << "Pizza 2 Name: " << pizza2.getName() << endl;
    cout << "Pizza 2 Size: " << pizza2.getSize() << endl;
    cout << "Pizza 2 Status: " << pizza2.check_status() << endl;
    cout << "Pizza 3 Topping: " << pizza3.getTopping() << endl;
    cout << "Pizza 3 Price: " << pizza3.getPrice() << endl;
    cout << "Pizza 3 Name: " << pizza3.getName() << endl;
    cout << "Pizza 3 Size: " << pizza3.getSize() << endl;
    cout << "Pizza 3 Status: " << pizza3.check_status() << endl;
    cout << "Pizza 4 Topping: " << pizza4.getTopping() << endl;
    cout << "Pizza 4 Price: " << pizza4.getPrice() << endl;
    cout << "Pizza 4 Name: " << pizza4.getName() << endl;
    cout << "Pizza 4 Size: " << pizza4.getSize() << endl;
    cout << "Pizza 4 Status: " << pizza4.check_status() << endl;
    return 0;
}




//Question 3

int main() {
    char* str = new char[7];
    cin >> str;
    String s1(str);
    s1.Print();
    cout << s1.charAt('l') << endl;
    cout << s1.stringLength() << endl;
    cout << "get data : " << s1.getData() << endl;
    cout << "is EMpty : " << s1.isEmpty() << endl;
    cout << "is Equal" << s1.isEqual(str) << endl;
    cout << s1.equalsIgnoreCase(str) << endl;
    char* strr = new char[10];
    cin >> strr;
    cout << s1.substring(strr, 0) << endl;
    cout << s1.substring(strr, 0, 10) << endl;
    cout << s1.equalsIgnoreCase(str) << endl;
    s1.clear();
}

//Question 4


int main() {
    SavingAccount* savers[100];
    int accountsOpen = 0;
    char* accountNum = new char[5];

    accountNum[0] = 'S';
    accountNum[1] = 'A';
    accountNum[2] = '0';
    accountNum[3] = '0';
    
    OpenCustomerAccount(savers, accountsOpen, accountNum, 1000);

    modifyInterestRate(savers[0], 0.05);
    modifyInterestRate(savers[1], 0.05);
    
    cout << calculateMonthlyInterest(savers[0]) << endl;
    cout << calculateMonthlyInterest(savers[1]) << endl;

    cout << searchCustomer(savers, accountsOpen, accountNum) << endl;

    cout << UpdateAccountBalance(savers, accountsOpen, accountNum, 1500) << endl;
}


//Question 5

int main() {
    Integer i1(10);
    Integer i2(20);
	cout << i1.plus(i2) << endl;//output 30
	cout << i1.minus(i2) << endl;//output -10
	cout << i1.multiple(i2) << endl;//output 200
	cout << i1.divide(i2) << endl;//output 0
	cout << i1.compareTo(i2) << endl;//output 0
	cout << i1.doubleValue() << endl;//output 10.0
	cout << i1.floatValue() << endl;//output 10.0
	cout << i1.bitCount() << endl;//output 2
	cout << Integer::numberOfLeadingZeros(10) << endl;//output 28
	cout << Integer::numberOfTrailongZeros(10) << endl;//output 1
	cout << Integer::toBinaryString(10) << endl;//output 1010
	cout << Integer::toHexString(10) << endl;//output A
    return 0;
}

//Question 6

int main() {
    Library books[10];
    char* book = new char[5];
    book[0] = 'b';
    book[1] = 'o';
    book[2] = 'k';
    book[3] = '1';

    char* author = new char[5];
    author[0] = 'm';
    author[1] = 'a';
    author[2] = 'n';
    author[3] = '1';
    
    books[1].setBookTitle(book);
    books[1].setAuthor(author);
    books[1].setBookID(1);
    books[1].setQuantity(10);
    books[1].setPrice(100);
    
    cout << books[1].getBookTitle() << endl;
    cout << books[1].getAuthor() << endl;
    cout << books[1].getBookID() << endl;
    cout << books[1].getQuantity() << endl;
    cout << books[1].getPrice() << endl;
    cout << books[1].getTotalBooks() << endl;
}

//Question 7

int main() {
    Student student;
        student.setStdID(1);
        student.setName("Student");
        student.addCourse("CS101", 90);
        student.addCourse("CS102", 80);
        student.addCourse("CS103", 70);
        //cout << student.getCourseGrade(0);

        student.calcGPA();
    cout << student.getNumCourses();
	printStudentRecord(student);
    /*cout << "Class GPA: " << calcClassGPA(student, 5) << endl;
    cout << "Max GPA: " << getMaxGPA(student, 5) << endl;
    cout << "Min GPA: " << getMinGPA(student, 5) << endl;*/
    return 0;
}