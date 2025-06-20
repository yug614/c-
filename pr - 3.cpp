#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle() {}
    Vehicle(int id, string man, string mod, int yr)
        : vehicleID(id), manufacturer(man), model(mod), year(yr) {
        totalVehicles++;
    }
    virtual ~Vehicle() {
        totalVehicles--;
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    virtual void display() const {
        cout << "ID: " << vehicleID << ", Manufacturer: " << manufacturer
             << ", Model: " << model << ", Year: " << year << endl;
    }

    int getID() const { return vehicleID; }
};

int Vehicle::totalVehicles = 0;


class Car : public Vehicle {
protected:
    string fuelType;
public:
    Car() {}
    Car(int id, string man, string mod, int yr, string fuel)
        : Vehicle(id, man, mod, yr), fuelType(fuel) {}

    void display() const override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};


class ElectricCar : public Car {
protected:
    int batteryCapacity;
public:
    ElectricCar(int id, string man, string mod, int yr, string fuel, int battery)
        : Car(id, man, mod, yr, fuel), batteryCapacity(battery) {}

    void display() const override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};


class Aircraft {
protected:
    int flightRange;
public:
    Aircraft() {}
    Aircraft(int range) : flightRange(range) {}
    void displayAircraft() const {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string man, string mod, int yr, string fuel, int range)
        : Car(id, man, mod, yr, fuel), Aircraft(range) {}

    void display() const {
        Car::display();
        displayAircraft();
    }
};

class SportsCar : public ElectricCar {
    int topSpeed;
public:
    SportsCar(int id, string man, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, man, mod, yr, fuel, battery), topSpeed(speed) {}

    void display() const override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};


class Sedan : public Car {
public:
    Sedan(int id, string man, string mod, int yr, string fuel)
        : Car(id, man, mod, yr, fuel) {}
};

class SUV : public Car {
public:
    SUV(int id, string man, string mod, int yr, string fuel)
        : Car(id, man, mod, yr, fuel) {}
};

class VehicleRegistry {
    vector<Vehicle*> vehicles;
public:
    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }

    void displayAll() {
        for (auto v : vehicles) {
            v->display();
            cout << "-----------------------------\n";
        }
    }

    void searchById(int id) {
        for (auto v : vehicles) {
            if (v->getID() == id) {
                v->display();
                return;
            }
        }
        cout << "Vehicle not found.\n";
    }

    ~VehicleRegistry() {
        for (auto v : vehicles)
            delete v;
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\nVehicle Registry Menu:\n1. Add Vehicle\n2. View All Vehicles\n3. Search by ID\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "Choose Vehicle Type:\n1. Car\n2. Electric Car\n3. Flying Car\n4. Sports Car\n5. Sedan\n6. SUV\nEnter type: ";
            cin >> type;

            int id, year, battery, range, speed;
            string man, mod, fuel;

            cout << "Enter ID, Manufacturer, Model, Year: ";
            cin >> id >> man >> mod >> year;

            if (type == 1) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Car(id, man, mod, year, fuel));
            } else if (type == 2) {
                cout << "Enter Fuel Type and Battery Capacity: ";
                cin >> fuel >> battery;
                registry.addVehicle(new ElectricCar(id, man, mod, year, fuel, battery));
            } else if (type == 3) {
                cout << "Enter Fuel Type and Flight Range: ";
                cin >> fuel >> range;
                registry.addVehicle(new FlyingCar(id, man, mod, year, fuel, range));
            } else if (type == 4) {
                cout << "Enter Fuel Type, Battery Capacity, and Top Speed: ";
                cin >> fuel >> battery >> speed;
                registry.addVehicle(new SportsCar(id, man, mod, year, fuel, battery, speed));
            } else if (type == 5) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Sedan(id, man, mod, year, fuel));
            } else if (type == 6) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new SUV(id, man, mod, year, fuel));
            }
        } else if (choice == 2) {
            registry.displayAll();
        } else if (choice == 3) {
            int searchId;
            cout << "Enter Vehicle ID to search: ";
            cin >> searchId;
            registry.searchById(searchId);
        }

    } while (choice != 4);

    cout << "Total Vehicles Registered: " << Vehicle::getTotalVehicles() << endl;
    
}
/*
Vehicle Registry Menu:
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 1
Choose Vehicle Type:
1. Car
2. Electric Car
3. Flying Car
4. Sports Car
5. Sedan
6. SUV
Enter type: 1
Enter ID, Manufacturer, Model, Year: 101 Toyota Corolla 2020
Enter Fuel Type: Petrol

Vehicle Registry Menu:
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 1
Choose Vehicle Type:
1. Car
2. Electric Car
3. Flying Car
4. Sports Car
5. Sedan
6. SUV
Enter type: 2
Enter ID, Manufacturer, Model, Year: 102 Tesla Model3 2022
Enter Fuel Type and Battery Capacity: Electric 75

Vehicle Registry Menu:
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 2

ID: 101, Manufacturer: Toyota, Model: Corolla, Year: 2020
Fuel Type: Petrol
-----------------------------
ID: 102, Manufacturer: Tesla, Model: Model3, Year: 2022
Fuel Type: Electric
Battery Capacity: 75 kWh
-----------------------------

Vehicle Registry Menu:
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 3
Enter Vehicle ID to search: 102

ID: 102, Manufacturer: Tesla, Model: Model3, Year: 2022
Fuel Type: Electric
Battery Capacity: 75 kWh

Vehicle Registry Menu:
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 4

Total Vehicles Registered: 2
*/