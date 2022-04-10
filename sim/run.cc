#include "run.hh"

MyRunAction  :: MyRunAction()
{
    
}

MyRunAction :: ~MyRunAction()
{
    delete G4AnalysisManager::Instance();
}

void MyRunAction :: BeginOfRunAction(const G4Run* run)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
   
    
}

void MyRunAction :: EndOfRunAction(const G4Run* run)
{
    

}
