#include <iostream>

using namespace std;

class Library{
private:
    char *bookTitle;
    char *author;
    int bookID;
    int quantity;
    float price;
    static int totalBooks;
public:
    char *getBookTitle(){
        return bookTitle;
    }
    char *getAuthor(){
        return author;
    }
    int getBookID(){
        return bookID;
    }
    int getQuantity(){
        return quantity;
    }
    float getPrice(){
        return price;
    }
    void setBookTitle(char *title){
        for(int i = 0; i < totalBooks; i++){
            if(title == bookTitle){
                cout << "This book already exists" << endl;
                return;
            }
        }
        bookTitle = title;
    }
    void setAuthor(char *auth){
        author = auth;
    }
    void setBookID(int id){
        bookID = id;
    }
    void setQuantity(int q){
        if(q < 0){
            cout << "Invalid quantity" << endl;
            return;
        }
        quantity = q;
    }
    void setPrice(float p){
        if(p < 0){
            cout << "Invalid price" << endl;
            return;
        }
        price = p;
    }
    static void setTotalBooks(int totalBooks){
        if(totalBooks < 0){
            cout << "Invalid total books" << endl;
            return;
        }
        totalBooks = totalBooks;
    }
    void calcTotalPrice(int totalBooks){
        float totalPrice = quantity * price;
    }
    static int getTotalBooks(){
        return totalBooks;
    }

};
int Library::totalBooks = 0;

Library getBook_at(Library books[], int index){
    return books[index];
}
void addBook(Library books[], Library newBook){
    books[newBook.getTotalBooks()] = newBook;
    newBook.setTotalBooks(newBook.getTotalBooks() + 1);
}
void removeBook(Library books[], int bookID){//recheck this <<<<<<<<<<-----------------------
    for(int i = bookID; i < books[0].getTotalBooks(); i++){
        books[i] = books[i + 1];
    }
    books[0].setTotalBooks(books[0].getTotalBooks() - 1);
}
void sortByTitle(Library books[]){
    for(int i = 0; i < books[0].getTotalBooks(); i++){
        for(int j = i + 1; j < books[0].getTotalBooks(); j++){
            if(int(books[i].getBookTitle()) > int(books[j].getBookTitle())){
                Library temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
void sortByAuthor(Library books[]){
    for(int i = 0; i < books[0].getTotalBooks(); i++){
        for(int j = i + 1; j < books[0].getTotalBooks(); j++){
            if(int(books[i].getAuthor()) > int(books[j].getAuthor())){
                Library temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
void sortByPrice(Library books[]){
    for(int i = 0; i < books[0].getTotalBooks(); i++){
        for(int j = i + 1; j < books[0].getTotalBooks(); j++){
            if(books[i].getPrice() > books[j].getPrice()){
                Library temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
bool searchByTittle(Library books[], char *titlename){
    for(int i = 0; i < books[0].getTotalBooks(); i++){
        if(books[i].getBookTitle() == titlename){
            return true;
        }
    }
    return false;
}
Library mostExpensiveBook(Library  books[10]){
    Library exp = books[0];
    for(int i = 0; i < books[0].getTotalBooks(); i++){
        if(books[i].getPrice() > exp.getPrice()){
            exp = books[i];
        }
    }
    return exp;
}

int main() {
    Library books[10];

    //books[1].setBookTitle("Stillness is the Key");
    //books[1].setAuthor("Ryan Holiday");
    books[1].setBookID(1);
    books[1].setQuantity(10);
    books[1].setPrice(100);

    //cout << books[1].getBookTitle() << endl;
    //cout << books[1].getAuthor() << end
    cout << books[1].getBookID() << endl;
    cout << books[1].getQuantity() << endl;
    cout << books[1].getPrice() << endl;
    cout << books[1].getTotalBooks() << endl;


}


