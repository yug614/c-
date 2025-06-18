#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int number, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void setTrainNumber(int number) { trainNumber = number; }
    void setTrainName(const char* name) { strcpy(trainName, name); }
    void setSource(const char* src) { strcpy(source, src); }
    void setDestination(const char* dest) { strcpy(destination, dest); }
    void setTrainTime(const char* time) { strcpy(trainTime, time); }

    int getTrainNumber() const { return trainNumber; }
    const char* getTrainName() const { return trainName; }
    const char* getSource() const { return source; }
    const char* getDestination() const { return destination; }
    const char* getTrainTime() const { return trainTime; }

    static int getTrainCount() { return trainCount; }

    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const {
        cout << "Train Number   : " << trainNumber << endl;
        cout << "Train Name     : " << trainName << endl;
        cout << "Source         : " << source << endl;
        cout << "Destination    : " << destination << endl;
        cout << "Departure Time : " << trainTime << endl;
        cout << "--------------------------------------\n";
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;

        trains[0] = Train(101, "Rajdhani Express", "Delhi", "Mumbai", "06:00AM");
        trains[1] = Train(102, "Shatabdi Express", "Ahmedabad", "Delhi", "07:30AM");
        trains[2] = Train(103, "Garib Rath", "Surat", "Pune", "08:45PM");
        totalTrains = 3;
    }

    void addTrain() {
        if (totalTrains < 100) {
            cout << "\nEnter details for new train:\n";
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train limit reached!\n";
        }
    }

    void displayAllTrains() const {
        cout << "\n=== Train List ===\n";
        for (int i = 0; i < totalTrains; i++) {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) const {
        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain Found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found.\n";
        }
    }
};
int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n===== Railway System Menu =====";
        cout << "\n1. Add Train";
        cout << "\n2. Display All Trains";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Show Train Count";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3: {
                int number;
                cout << "Enter Train Number to Search: ";
                cin >> number;
                system.searchTrainByNumber(number);
                break;
            }
            case 4:
                cout << "Total Train Records: " << Train::getTrainCount() << endl;
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    
}

/*

Output:
--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit

Enter your choice: 1
Enter Train Number: 101
Enter Train Name: Okha Express
Enter Source: Surat
Enter Destination: Mumbai
Enter Train Time: 10 AM

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit

Enter your choice: 2
Train 1 details:
Train Number: 101
Train Name: Okha Express
Source: Surat
Destination: Mumbai
Train Time: 10 AM

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit

Enter your choice: 3
Enter Train Number to search: 104
Train with number 104 not found!

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit

Enter your choice: 4
Exiting the system. Goodbye!
*/