#include "DetectorConstruction.hh"

#include "G4SystemOfUnits.hh"

#include "G4NistManager.hh"
#include "G4VisAttributes.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume *DetectorConstruction ::Construct()
{
    DefineMaterial();
    return ConstructVolume();
}

void DetectorConstruction::DefineMaterial()
{
    G4NistManager *nist = G4NistManager::Instance();
    Air = nist->FindOrBuildMaterial("G4_AIR");
}

G4VPhysicalVolume *DetectorConstruction::ConstructVolume()
{
    G4Box *solidWorld = new G4Box("solidWorld", 500. * cm, 500. * cm, 500. * cm);
    logicWorld = new G4LogicalVolume(solidWorld, Air, "logicWorld");
    physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "physWorld", 0, false, 0, true);

    return physWorld;
}