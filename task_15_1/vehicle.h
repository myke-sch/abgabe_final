//
// Created by mikas on 10.03.2025.
//

#ifndef ABGABE_FINAL_VEHICLE_H
#define ABGABE_FINAL_VEHICLE_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Vehicle{
private:
    long nbr;
    string producer;
public:
    Vehicle( long n = 0L, const string& prod = "");
    virtual ~Vehicle() {}
    // access methods:
    long getNbr(void) const { return nbr; }
    void setNbr( long n ) { nbr = n; }
    const string& getPeoducer() const { return producer; }
    void setProducer(const string& h){ producer = h; }
    virtual void display() const; // show vehicle
};
class Car : public Vehicle {
private:
    string carType;
    bool sunroof;
public:

    Car(const string& tp, bool sd,
        int n = 0 , const string& h = "");
    // access methods:
    const string& getTyp( void ) const { return carType; }
    void setTyp( const string s ) { carType = s; }
    bool getSunRoof( void ) const { return sunroof; }
    void setSunRoof( bool d ) { sunroof = d; }
    void display( void ) const;
    Car* getCar(Vehicle* vehicle) {
        return dynamic_cast<Car*>(vehicle);
    }

};

class CityCar: public Vehicle {
private:
    int vectorLength;

public:
    CityCar(int vectorLength, int n, const string& hs);
    virtual ~CityCar() {}

    const std::vector<Vehicle*>& getVehicles() const { return vehicles; }

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
        return os;
    }

    //insert new car
    bool insert (const string& tp, bool sd, long n, const string& prod);
    // insert new truck
    bool insert (int a, double t, long n, const string& prod);


    vector<Vehicle *> vehicles;
};

class Truck : public Vehicle {
private:
    int axles;
    double load;
public:
    Truck( int a, double t, int n, const string& hs);
    void setAxles( int l){ axles = l;}
    int
    getAxles() const { return axles; }
    void setCapacity( double t) { load = t;}
    double getCapacity() const;
    void display() const;
    Truck* getTruck(Truck* truck) {
        return dynamic_cast<Truck*>(truck);
    }
};


#endif //ABGABE_FINAL_VEHICLE_H
