#include "vehicle_factory.h"

Vehicle* VehicleFactory::GetVehicle(std::string type_of_vehicle)
{
    
    Vehicle* vehicle ;
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
        return nullptr;
        delete vehicle;
    }
    return vehicle;
}