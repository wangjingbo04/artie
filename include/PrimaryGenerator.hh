#ifndef PrimaryGenerator_h
#define PrimaryGenerator_h 1

#include "globals.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4VUserActionInitialization.hh"
#include "G4ParticleGun.hh"
#include "G4GenericMessenger.hh"
#include "TFile.h"
#include "TH1D.h"


class G4Event;

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
  class Init : public G4VUserActionInitialization
  {
  public:
    Init();
    virtual ~Init();
    virtual void BuildForMaster() const;
    virtual void Build() const;
  };

  PrimaryGenerator();    
  ~PrimaryGenerator();
  void UseRealisticEnergy();
  virtual void GeneratePrimaries(G4Event*);
  const G4ParticleGun* GetParticleGun() const {return fParticleGun;};

private:
  G4ParticleGun*  fParticleGun;        //pointer a to G4 service class
  TFile* fNeutronFile; 
  TH1D* fNeutronEnergy;
  G4GenericMessenger* fMessenger;      //pinter to generic messanger class
  G4bool fUseRealisticEnergy = false;  // neutron energy option
};

#endif

