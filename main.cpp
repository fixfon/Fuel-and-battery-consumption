#include <iostream>
using namespace std;

/*class polygon{ //  a class with at least one virtual func. is polymorphic class.
protected:
    int width;
    int height;

public:
    void setValues(int w, int h){
        width = w;
        height = h;
    }

    virtual int calculateArea(){
        return 0;
    }
};

class rectangle: public polygon{
public:
    int calculateArea(){
        return width * height;
    }
};

class triangle: public polygon{
public:
    int calculateArea(){
        return width * height / 2;
    }
};*/

class landVehicle{
protected:
    int topSpeed;

public:
    landVehicle(){
        topSpeed = 0;
    }

    landVehicle(int t){
        topSpeed = t;
    }

    virtual void travel(int distance, int speed) = 0; // pure virtual func. no more define an object from landvehicle. only can be created pointer objects.
    //
};

class iceVehicle: public landVehicle{
protected:
    double fuelLevel;
    double fuelConsumptionByHour;

public:
    iceVehicle(int t, int fuel, int cons): landVehicle(t), fuelLevel(fuel), fuelConsumptionByHour(cons){    }

    void travel(int Distance, int speed){
        if(speed > topSpeed) {
            speed = topSpeed;
        }
            double fuelReq = ((double)Distance / speed) * fuelConsumptionByHour;

            if (fuelLevel >= fuelReq) {
                cout << "Arrived at destination" << endl;
                fuelLevel -= fuelReq;
            } else {
                cout << "Not enough fuel" << endl;
            }

    }

};

class electricVehicle: public landVehicle{
protected:
    double batteryLevel;
    double batteryConsumptionByHour;

public:
    electricVehicle(int t, double battery, double cons): landVehicle(t), batteryLevel(battery), batteryConsumptionByHour(cons){    }

    void travel(int Distance, int speed){
        double  batteryReq;

        if(speed > topSpeed) {
            speed = topSpeed;
        }

        if(speed > topSpeed * 0.5){
            batteryReq = ((double)Distance / speed) * batteryConsumptionByHour;
        }
        else {
            batteryReq = ((double) Distance / speed) * batteryConsumptionByHour * 0.3;
        }

        if (batteryLevel >= batteryReq) {
             cout << "Arrived at destination" << endl;
             batteryLevel = batteryLevel - batteryReq;
        } else {
                cout << "Not enough fuel" << endl;
        }

    }

};

int main() {
    /*rectangle R;
    triangle T;
    polygon *pPoly1;
    polygon *pPoly2;

    pPoly1 = &R;
    pPoly2 = &T;

    pPoly1->setValues(5,6);
    pPoly2->setValues(5,6);

    cout << pPoly1->calculateArea() << endl;
    cout << pPoly2->calculateArea() << endl;*/

    iceVehicle carICE(240, 40.0, 3.0 );
    electricVehicle carEV(160, 50.0, 2.4);

    landVehicle *lVE1 = &carICE;
    landVehicle *lVE2 = &carEV;

    lVE1->travel(1000,200);
    lVE1->travel(800,100);

    cout << "Hello World!" << endl;


    return 0;
}
