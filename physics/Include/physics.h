#ifndef PHYSICS_FUNCTIONS_H
#define PHYSICS_FUNCTIONS_H
namespace physics {
    #if defined(_WIN32) || defined(_WIN64)
        #ifdef PHYSICS_EXPORT 
            #define PHYSICS_API  __declspec(dllexport)
        #else 
            #define PHYSICS_API  __declspec(dllimport)
    #endif
    #elif defined(__linux__) || defined(__APPLE__)
        #define PHYSICS_API  __attribute__((visibility("default")))
    #endif

    PHYSICS_API double calculateForce(double mass, double acceleration);
    PHYSICS_API double calculateKineticEnergy(double mass, double velocity);
  // __attribute__((visibility("default"))) double calculateForce(double mass, double acceleration); //on linux if you want to expose an api on shared library
    PHYSICS_API double calculatePotentialEnergy(double mass, double gravity, double height);
}
#endif
