#include "physics.h"
namespace physics {
    double calculateKineticEnergy(double mass, double velocity){
        return 0.5*mass*velocity*velocity;
    }
    double calculateForce(double mass, double acceleration){
        return mass*acceleration;
    }
    double calculatePotentialEnergy(double mass, double gravity, double height){
        return mass*gravity*height;
    }
}