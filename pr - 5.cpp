#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
using namespace std;


class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    
    LibraryItem(string title, string author, string dueDate)
        : title(title), author(author), dueDate(dueDate) {}

    virtual ~LibraryItem() {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem {
private:
    string ISBN;

public:
    Book(string title, string author, string dueDate, string isbn)
        : LibraryItem(title, author, dueDate), ISBN(isbn) {}

    void checkOut() override {
        cout << "Book \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "Book \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "Book - Title: " << getTitle()
             << ", Author: " << getAuthor()
             << ", Due Date: " << getDueDate()
             << ", ISBN: " << ISBN << "\n";
    }
};

class DVD : public LibraryItem {
private:
    int duration; 

public:
    DVD(string title, string author, string dueDate, int duration)
        : LibraryItem(title, author, dueDate), duration(duration) {}

    void checkOut() override {
        cout << "DVD \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "DVD \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "DVD - Title: " << getTitle()
             << ", Author: " << getAuthor()
             << ", Due Date: " << getDueDate()
             << ", Duration: " << duration << " mins\n";
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string title, string author, string dueDate, int issueNumber)
        : LibraryItem(title, author, dueDate), issueNumber(issueNumber) {}

    void checkOut() override {
        cout << "Magazine \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "Magazine \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "Magazine - Title: " << getTitle()
             << ", Author: " << getAuthor()
             << ", Due Date: " << getDueDate()
             << ", Issue Number: " << issueNumber << "\n";
    }
};

int getValidatedIntInput(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0)
            break;
        else {
            cout << "Invalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return value;
}

void showMenu() {
    cout << "\nLibrary Menu:\n";
    cout << "1. Add Book\n";
    cout << "2. Add DVD\n";
    cout << "3. Add Magazine\n";
    cout << "4. Display All Items\n";
    cout << "5. Check Out Item\n";
    cout << "6. Return Item\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    const int MAX_ITEMS = 100;
    vector<LibraryItem*> libraryItems;

    int choice;
    do {
        showMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    string title, author, dueDate, isbn;
                    cout << "Enter book title: "; cin.ignore(); getline(cin, title);
                    cout << "Enter author: "; getline(cin, author);
                    cout << "Enter due date: "; getline(cin, dueDate);
                    cout << "Enter ISBN (e.g., 13-digit): "; getline(cin, isbn);
                    if (isbn.length() != 13)
                        throw invalid_argument("ISBN must be 13 digits long.");
                    libraryItems.push_back(new Book(title, author, dueDate, isbn));
                    break;
                }
                case 2: {
                    string title, author, dueDate;
                    cout << "Enter DVD title: "; cin.ignore(); getline(cin, title);
                    cout << "Enter author: "; getline(cin, author);
                    cout << "Enter due date: "; getline(cin, dueDate);
                    int duration = getValidatedIntInput("Enter duration (minutes): ");
                    libraryItems.push_back(new DVD(title, author, dueDate, duration));
                    break;
                }
                case 3: {
                    string title, author, dueDate;
                    cout << "Enter magazine title: "; cin.ignore(); getline(cin, title);
                    cout << "Enter author: "; getline(cin, author);
                    cout << "Enter due date: "; getline(cin, dueDate);
                    int issue = getValidatedIntInput("Enter issue number: ");
                    libraryItems.push_back(new Magazine(title, author, dueDate, issue));
                    break;
                }
                case 4: {
                    for (LibraryItem* item : libraryItems) {
                        item->displayDetails();
                    }
                    break;
                }
                case 5: {
                    int idx = getValidatedIntInput("Enter item index to check out: ");
                    if (idx >= 0 && idx < libraryItems.size()) {
                        libraryItems[idx]->checkOut();
                    } else {
                        cout << "Invalid index.\n";
                    }
                    break;
                }
                case 6: {
                    int idx = getValidatedIntInput("Enter item index to return: ");
                    if (idx >= 0 && idx < libraryItems.size()) {
                        libraryItems[idx]->returnItem();
                    } else {
                        cout << "Invalid index.\n";
                    }
                    break;
                }
                case 7:
                    cout << "Exiting system...\n";
                    break;
                default:
                    cout << "Invalid option.\n";
            }
        } catch (exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (choice != 7);

    for (LibraryItem* item : libraryItems) {
        delete item;
    }

    
}
/*

Library Menu:
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Choose an option: 1
Enter book title: xyz
Enter author: yug
Enter due date: 29
Enter ISBN (e.g., 13-digit): 1234567123456
*/