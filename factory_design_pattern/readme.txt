g++ -c vehicle_factory.cpp vehicle.cpp car.cpp bike.cpp 
ar ru vehicle_library.a bike.o car.o vehicle_factory.o
g++ -o smart_client  smart_client.cpp vehicle_library.a