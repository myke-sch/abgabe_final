//
// Created by mikas on 10.03.2025.
//

#include "vehicle.h"
using namespace std;

Vehicle::Vehicle(long n, const string &prod)
        : nbr(n), producer(prod) {}

void Vehicle::display() const {
    cout << "\n---------------------------- "
         << "\nVehicle-Number: " << nbr
         << "\nProducer: " << producer
         << endl;
}

// Methods of derived Car class:
//------------------------------------------------------
Car::Car(const string &tp, bool sd, int n, const string &hs)
        : Vehicle(n, hs), carType(tp), sunroof(sd) {}

void Car::display(void) const {
    Vehicle::display();
    cout << "Type:" << carType << "\nSun Roof: ";
    if (sunroof)
        cout << "yes " << endl;
    else {
        cout << "no " <<
               endl;
    }
}



// Methods of derived Truck class:
//---------------------------------------------------
Truck::Truck(int a, double t, int n, const string &hs)
        : Vehicle(n, hs), axles(a), load(t) {}

void Truck::display() const {
    Vehicle::display();
    cout << "Axles:" << axles
         << "\nCapacity: " << load << " tons"
         << endl;
}

bool inspect(Car *),
        inspect(Truck *);


//Methods for City Car Class
CityCar::CityCar(int vectorLength, int n, const string &hs): Vehicle(n, hs), vectorLength(vectorLength) {}

bool CityCar::insert(const string& tp, bool sd, long n, const string& prod) {
    int vec_size = CityCar::vehicles.size();
    if (vec_size >= vectorLength) {
        return false;
    } else {
        CityCar::vehicles.push_back(new Car(tp,sd,n,prod));
        return true;
    }
}

bool CityCar::insert(int a, double t, long n, const std::string &prod) {
    int vec_size = CityCar::vehicles.size();
    if (vec_size >= vectorLength) {
        return false;
    } else {
        CityCar::vehicles.push_back(new Truck(a,t,n,prod));
        return true;
    }
}

// Inspection of different
// vehicle types.
bool distribute(Vehicle *vehiclePtr); // distribute vehicle for inspection
/*int main() {
    Vehicle *vehiclePtr = new Car("520i", true, 3265, "BMW");
    Car *carPtr = dynamic_cast<Car *>(vehiclePtr);
    if (carPtr != NULL) {
        // ok?
        cout << "\nAfter pointer Down-Cast: " << endl;
        carPtr->display();
    }
    Car cabrio("190 SL", true, 9154, "Mercedes Benz");
    Vehicle &r_vehicle = cabrio;
    Car &r_car = dynamic_cast<Car &>(r_vehicle);
    // ok? throws exception if not ok.
    cout << "\nAfter reference Down-Cast: " << endl;
    r_vehicle.display();
    cin.get();
    Truck *truckPtr = new Truck(8, 7.5, 5437, "Volvo");
    distribute(vehiclePtr);
    distribute(truckPtr);

    Vehicle *cityCarPtr = new CityCar(1, 1234, "CityCar");
    CityCar *cityCar = dynamic_cast<CityCar *>(cityCarPtr);
    cityCar->insert("520i", true, 3265, "BMW");
    cityCar->insert(8, 7.5, 5437, "Volvo");

    return 0;
}*/

bool distribute(Vehicle *vehiclePtr) {
    Car *carPtr = dynamic_cast<Car *>(vehiclePtr);
    if (carPtr != NULL)
        return inspect(carPtr);
    Truck *truckPtr = dynamic_cast<Truck *>(vehiclePtr);
    if (truckPtr != NULL)
        return inspect(truckPtr);
    return false;
}

bool inspect(Car *carPtr) {
    cout << "\nChecking car!" << endl;
    cout << "\nHere it comes:";
    carPtr->display();
    return true;
}

bool inspect(Truck *truckPtr) {
    cout << "\nChecking truck!" << endl;
    cout << "\nHere it comes:";
    truckPtr->display();
    return true;
}