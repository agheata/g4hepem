
#ifndef Declaration_HH
#define Declaration_HH

// G4 include (for types)
#include "globals.hh"


struct G4HepEmData;
struct G4HepEmElectronData;


// builds a fake Geant4 geometry just to be able to produce material-cuts couple
void FakeG4Setup ( G4double prodCutInLength,  G4int verbose=1 );


// checks the EnergyLoss related parts of the G4HepEmElectronData (host/device)
bool TestElossData ( const struct G4HepEmData* hepEmData, bool iselectron=true );


#ifdef G4HepEm_CUDA_BUILD

#include <device_launch_parameters.h>

  // Evaluates all test cases on the device for computing the range, dE/dx and inverse
  // range values on the device for all test cases.
  void TestElossDataOnDevice ( const struct G4HepEmData* hepEmData,
                               int* tsInImc_h, double* tsInEkin_h, double* tsInLogEkin_h,
                               double* tsOutResRange_h, double* tsOutResDEDX_h, double* tsOutResInvRange_h,
                               int numTestCases, bool iselectron );

  __global__
  void TestElossDataKernel ( struct G4HepEmElectronData* theElectronData_d,
                             int* tsInImc_d, double* tsInEkin_d, double* tsInLogEkin_d,
                             double* tsOutResRange_d, double* tsOutResDEDX_d, double* tsOutResInvRange_d,
                             int numTestCases );

#endif // G4HepEm_CUDA_BUILD


#endif // Declaration_HH
