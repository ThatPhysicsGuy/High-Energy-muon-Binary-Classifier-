#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction ::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()

{
    G4NistManager *nist = G4NistManager:: Instance();
    
    G4Material *H2O = new G4Material("H2O",1.000*g/cm3,2);
    H2O -> AddElement(nist-> FindOrBuildElement("H"),2);
    H2O -> AddElement(nist-> FindOrBuildElement("O"),1);
    
    G4double energy[2] = {1.239841939*eV/0.2,1.239841939*eV/0.9};
    G4double rindexH2O[2] = {1.333,1.333};
    
    G4MaterialPropertiesTable *mptH2O = new G4MaterialPropertiesTable();
    mptH2O -> AddProperty("RINDEX", energy, rindexH2O,2);
    
    H2O -> SetMaterialPropertiesTable(mptH2O);
    
    G4double rindexWorld[2] = {1.000,1.000};
    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld -> AddProperty("RINDEX", energy, rindexWorld,2);
    
    G4Material *worldMat = nist -> FindOrBuildMaterial("G4_AIR");
    worldMat -> SetMaterialPropertiesTable(mptWorld);
    
    G4Box*solidWorld  = new G4Box("World",21*m,21*m,21*m);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld,"physWorld",0, false, 0, true);
    
 
    G4Tubs *SuperK = new G4Tubs("SuperK",0.,20*m,20*m,0.*deg,360.*deg);
    
    G4LogicalVolume *logicSuperK = new G4LogicalVolume(SuperK, H2O, "logicSuperK");
    
    G4VPhysicalVolume *physSuperK = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.*m), logicSuperK,"physSuperK",logicWorld, false, 0, true);
    
    return physWorld;

}

