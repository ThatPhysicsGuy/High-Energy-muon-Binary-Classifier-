#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4MuIonisation.hh"
#include "G4MuMultipleScattering.hh"
#include "FTFP_BERT.hh"
#include "QBBC.hh" 


class MyPhysicsList : public G4VModularPhysicsList
{
public:
    MyPhysicsList();
    ~MyPhysicsList();


};


#endif
