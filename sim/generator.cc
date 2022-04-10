#include "generator.hh"
#include "G4INCLRandom.hh"

MyPrimaryGenerator :: MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
    G4ParticleTable *ParticleTable = G4ParticleTable::GetParticleTable();
    G4String particleName="mu-";
    G4ParticleDefinition *particle = ParticleTable -> FindParticle("mu-");
    
    G4double x = 0.;
    G4double y = 0.;
    G4double z = 20.;

    G4ThreeVector pos(x*m,y*m,z*m);

    G4ThreeVector mom(-x,-y,-z);

    fParticleGun -> SetParticlePosition(pos);
    fParticleGun -> SetParticleMomentumDirection(mom);
    fParticleGun -> SetParticleMomentum(15*GeV);
    fParticleGun -> SetParticleDefinition(particle);
}

MyPrimaryGenerator ::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator :: GeneratePrimaries(G4Event *anEvent)
{
    
    fParticleGun -> GeneratePrimaryVertex(anEvent);

}
