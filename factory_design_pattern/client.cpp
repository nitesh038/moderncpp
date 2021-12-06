#include "vehicle.h"
#include "bike.h"
#include "car.h"
#include <string>

int main()
{
    std::string type_of_vehicle;
    std::cout << "Please input type of vehicle: " ;
    std::cin >> type_of_vehicle;
    std::cout<<"\n";

    Vehicle* vehicle = nullptr;
    if(type_of_vehicle == "bike")
    {
        vehicle = new Bike();
    }
    else if(type_of_vehicle == "car")
    {
        vehicle = new Car();
    }
    else
    {
        std::cout << "Wrong_input\n";
        delete vehicle;
    }
    vehicle->CreateVehicle();
    delete vehicle;
    return 0;
}