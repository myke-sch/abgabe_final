//
// Created by mikas on 10.03.2025.
//
#include <iostream>
#include "vehicle.h"
#include "string"

void menu() {
    CityCar carPark(10, 0, "CarPark");
    char choice;

    do {
        cout << "\n****Car-Park-Management-System**********" << endl;
        cout << "C = add new car" << endl;
        cout << "T = add new truck" << endl;
        cout << "S = show car park" << endl;
        cout << "E = exit program" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (toupper(choice)) {
            case 'C': {
                string type, producer;
                bool sunroof;
                long number;
                cout << "Enter car type: ";
                cin >> type;
                cout << "Enter producer: ";
                cin >> producer;
                cout << "Enter vehicle number: ";
                cin >> number;
                cout << "Sunroof (1 for yes, 0 for no): ";
                cin >> sunroof;

                if (carPark.insert(type, sunroof, number, producer)) {
                    cout << "Car added successfully!" << endl;
                } else {
                    cout << "Car park is full!" << endl;
                }
                break;
            }

            case 'T': {
                int axles;
                double load;
                string producer;
                long number;
                cout << "Enter number of axles: ";
                cin >> axles;
                cout << "Enter load capacity (tons): ";
                cin >> load;
                cout << "Enter producer: ";
                cin >> producer;
                cout << "Enter vehicle number: ";
                cin >> number;

                if (carPark.insert(axles, load, number, producer)) {
                    cout << "Truck added successfully!" << endl;
                } else {
                    cout << "Car park is full!" << endl;
                }
                break;
            }

            case 'S': {
                cout << "\nDisplaying all vehicles in the car park:" << endl;
                for (auto vehicle : carPark.getVehicles()) {
                    vehicle->display();
                }
                break;
            }

            case 'E':
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (toupper(choice) != 'E');
}

int main() {
    cout << "Test";
    CityCar cityCar(10,0,"Park");
    if(cityCar.insert("E92", 1, 123, "BMW")) cout << "Success" << endl;
    if(cityCar.insert(2,30,1234, "MAN")) cout << "Success 2" << endl;
    menu();
    return 0;
}