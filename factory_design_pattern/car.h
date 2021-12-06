#ifndef CAR_H // include guard
#define CAR_H
#include "vehicle.h"

class Car : public Vehicle
{
    public:
    void CreateVehicle() override;
};
#endif
