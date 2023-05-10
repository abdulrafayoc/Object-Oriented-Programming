#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
public:
    string regNumber;
    string arrivalTime;
    int slotNumber;
};

class ParkingSystem {
public:
    vector<Car> cars;
    void addCar(Car car) {
        cars.push_back(car);
    }

    void removeCar(int slotNumber) {
        if (slotNumber < 1 || slotNumber > cars.size()) {
            cout << "Slot number is invalid\n";
        }
        for (int i = 0; i < cars.size(); i++) {
            if (cars[i].slotNumber == slotNumber) {
                cars.erase(cars.begin() + i);
                break;
            }
        }
    }

    void updateSlotNumber(int oldSlotNumber, int newSlotNumber) {
        if (oldSlotNumber < 1 || newSlotNumber < 1) {
            cout << "Invalid slot number.\n";
        }
        if (oldSlotNumber == newSlotNumber) {
            return;
        }
        for (int i = 0; i < cars.size(); i++) {
            if (cars[i].slotNumber == oldSlotNumber) {
                cars[i].slotNumber = newSlotNumber;
                break;
            }
        }
    }

    void printTotalCars() {
        cout << "Total number of parked cars: " << cars.size() << endl;
    }

    void removeAllCars() {
        cars.clear();
    }

    void searchCar(string regNumber) {
        for(int i = 0; i < cars.size(); i++) {
            if (cars[i].regNumber == regNumber) {
                cout << "Car found at slot number " << cars[i].slotNumber << endl;
                return;
            }
        }
        cout << "Car not found" << endl;
        return;
    }
};

int main() {
    ParkingSystem parkingSystem;
    
    Car car1 = {"AUV123", "10:00", 1};
    Car car2 = {"DPX456", "11:00", 2};
    Car car3 = {"GSP789", "12:00", 3};
    parkingSystem.addCar(car1);
    parkingSystem.addCar(car2);
    parkingSystem.addCar(car3);

    parkingSystem.removeCar(2);

    parkingSystem.updateSlotNumber(3, 2);
    parkingSystem.printTotalCars();

    parkingSystem.searchCar("AUV123");
    parkingSystem.searchCar("DPX456");
    parkingSystem.removeAllCars();

    return 0;
}
