#include "car.h"

Car::Car(std::string name, int count, float cost, std::string make, std::string model) : Item(name, count, cost), make(make), model(model) {} //Why do I not need Item::Item here?
