#ifndef VEHICLE_FACTORY_H // include guard
#define VEHICLE_FACTORY_H
#include "bike.h"
#include "car.h"

class VehicleFactory 
{
    public:
        static Vehicle* GetVehicle(std::string vehicle);
};
#endif