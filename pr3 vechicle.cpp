#include <iostream>
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
    Vehicle() : vehicleID(0), manufacturer(""), model(""), year(0) {
        totalVehicles++;
    }

    Vehicle(int id, string mfr, string mdl, int yr) : vehicleID(id), manufacturer(mfr), model(mdl), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    virtual void display() {
        cout << "ID: " << vehicleID << ", Manufacturer: " << manufacturer << ", Model: " << model << ", Year: " << year << endl;
    }

    int getVehicleID() const { return vehicleID; }
    void setVehicleID(int id) { vehicleID = id; }
    string getManufacturer() const { return manufacturer; }
    void setManufacturer(string mfr) { manufacturer = mfr; }
    string getModel() const { return model; }
    void setModel(string mdl) { model = mdl; }
    int getYear() const { return year; }
    void setYear(int yr) { year = yr; }
};

int Vehicle::totalVehicles = 0;


class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : Vehicle(), fuelType("") {}
    Car(int id, string mfr, string mdl, int yr, string fuel) : Vehicle(id, mfr, mdl, yr), fuelType(fuel) {}

    void display() override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car(), batteryCapacity(0) {}
    ElectricCar(int id, string mfr, string mdl, int yr, string fuel, int battery) : Car(id, mfr, mdl, yr, fuel), batteryCapacity(battery) {}

    void display() override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class Aircraft {
protected:
    int flightRange;

public:
    Aircraft() : flightRange(0) {}
    Aircraft(int range) : flightRange(range) {}
    virtual void displayAircraft() {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() {}
    FlyingCar(int id, string mfr, string mdl, int yr, string fuel, int range) : Car(id, mfr, mdl, yr, fuel), Aircraft(range) {}

    void display() {
        Car::display();
        Aircraft::displayAircraft();
    }
};


class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    SportsCar() : ElectricCar(), topSpeed(0) {}
    SportsCar(int id, string mfr, string mdl, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, mfr, mdl, yr, fuel, battery), topSpeed(speed) {}

    void display() override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};


class Sedan : public Car {
public:
    Sedan(int id, string mfr, string mdl, int yr, string fuel) : Car(id, mfr, mdl, yr, fuel) {}
};

class SUV : public Car {
public:
    SUV(int id, string mfr, string mdl, int yr, string fuel) : Car(id, mfr, mdl, yr, fuel) {}
};


class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() : count(0) {}

    void addVehicle(Vehicle* v) {
        if (count < 100) {
            vehicles[count++] = v;
        } else {
            cout << "Registry Full!" << endl;
        }
    }

    void displayAll() {
        for (int i = 0; i < count; i++) {
            vehicles[i]->display();
            cout << "---------------------------" << endl;
        }
    }

    void searchById(int id) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                vehicles[i]->display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Vehicle not found." << endl;
        }
    }

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
        }
    }
};


int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\nVehicle Registry System" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicles" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "Select Vehicle Type:\n1. Car\n2. Electric Car\n3. Flying Car\n4. Sports Car\n5. Sedan\n6. SUV\nChoice: ";
            cin >> type;
            int id, yr, battery, range, speed;
            string mfr, mdl, fuel;

            cout << "Enter ID, Manufacturer, Model, Year: ";
            cin >> id >> mfr >> mdl >> yr;
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            switch (type) {
                case 1:
                    registry.addVehicle(new Car(id, mfr, mdl, yr, fuel));
                    break;
                case 2:
                    cout << "Enter Battery Capacity: ";
                    cin >> battery;
                    registry.addVehicle(new ElectricCar(id, mfr, mdl, yr, fuel, battery));
                    break;
                case 3:
                    cout << "Enter Flight Range: ";
                    cin >> range;
                    registry.addVehicle(new FlyingCar(id, mfr, mdl, yr, fuel, range));
                    break;
                case 4:
                    cout << "Enter Battery Capacity and Top Speed: ";
                    cin >> battery >> speed;
                    registry.addVehicle(new SportsCar(id, mfr, mdl, yr, fuel, battery, speed));
                    break;
                case 5:
                    registry.addVehicle(new Sedan(id, mfr, mdl, yr, fuel));
                    break;
                case 6:
                    registry.addVehicle(new SUV(id, mfr, mdl, yr, fuel));
                    break;
                default:
                    cout << "Invalid type." << endl;
                    break;
            }
        } else if (choice == 2) {
            registry.displayAll();
        } else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            registry.searchById(id);
        }

    } while (choice != 4);

    return 0;
}
/*OUTPUT:
Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 1
Select Vehicle Type:
1. Car
2. Electric Car
3. Flying Car
4. Sports Car
5. Sedan
6. SUV
Choice: 1
Enter ID, Manufacturer, Model, Year: 101
XUV
XUV 700
Enter Fuel Type: DIESEL

Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 2
ID: 101, Manufacturer: XUV, Model: XUV, Year: 700
Fuel Type: DIESEL
---------------------------

Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 3
Enter ID to search: 104
Vehicle not found.

Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter choice: 4
*/