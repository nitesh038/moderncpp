#ifndef BIKE_H // include guard
#define BIKE_H

#include "vehicle.h"

class Bike : public Vehicle
{
    public:
    void CreateVehicle() override;
};

#endif