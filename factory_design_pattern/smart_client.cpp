#include "vehicle_factory.h"
#include "bike.h"
#include "car.h"
#include <string>

int main()
{
    std::string type_of_vehicle;
    std::cout << "Please input type of vehicle: " ;
    std::cin >> type_of_vehicle;
    std::cout<<"\n";

    Vehicle* vehicle = VehicleFactory::GetVehicle(type_of_vehicle);

    vehicle->CreateVehicle();
    delete vehicle;
    return 0;
}