#include "TStarJetPicoEventHeader.h"

#include "TStarJetPicoDefinitions.h"
#include <TString.h>

ClassImp(TStarJetPicoEventHeader)

#define __INITIAL_NUMBER_OF_TID 1

TStarJetPicoEventHeader::TStarJetPicoEventHeader()
  : TObject()
  , fEventId(0)
  , fRunId(0)
  , fRefMult(0)
  , fGRefMult(0)
  , fNOfGlobalTracks(0)
  , fReactionPlaneAngle(0)
  , fNOfTriggerIds(0)
  , fTriggerIdArray(__INITIAL_NUMBER_OF_TID)
  , fNOfTowerTrackMatched(0)
  , fNOfTowers(0)
  , fNOfPrimaryTracks(0)
  , fNOfMatchedTracks(0)
  , fNOfFtpcPrimaryTracks(0)
  , fNOfV0s(0)
  , fNOfEMCPoints(0)
  , fPVx(0)
  , fPVy(0)
  , fPVz(0)
  , fvpdVz(0)
  , fCTBmult(0)
  , fMeanDip(0)
  , fRank(0)
  , fNOfVertices(0)   
  , fNOfTrigObjs(0) 
  , fDSMInput(0)
  , fTrigMask(0)
  , fZdcWestRate(0)
  , fZdcEastRate(0)
    , fZdcCoincidenceRate(0)
    , fBbcWestRate(0)
    , fBbcEastRate(0)
    , fBbcCoincidenceRate(0)
    , fBbcBlueBackgroundRate(0)
    , fBbcYellowBackgroundRate(0)
    , fBbcAdcSumEast(0)
    , fBbcOnlineVertex(0)
    , fBbcOfflineVertex(0)
    , fRefMultFTPCE(0)
    , fnumberOfVpdEastHits(0)
    , fnumberOfVpdWestHits(0)
{
  fTriggerIdArray.Reset(0);
}

TStarJetPicoEventHeader::TStarJetPicoEventHeader(const TStarJetPicoEventHeader &t)
  : TObject(t)
  , fEventId(t.fEventId)
  , fRunId(t.fRunId)
  , fRefMult(t.fRefMult)
  , fGRefMult(t.fGRefMult)
  , fNOfGlobalTracks(t.fNOfGlobalTracks)
  , fReactionPlaneAngle(t.fReactionPlaneAngle)
  , fNOfTriggerIds(t.fNOfTriggerIds)
  , fTriggerIdArray(t.fTriggerIdArray)
  , fNOfTowerTrackMatched(t.fNOfTowerTrackMatched)
  , fNOfTowers(t.fNOfTowers)
  , fNOfPrimaryTracks(t.fNOfPrimaryTracks)
  , fNOfMatchedTracks(t.fNOfMatchedTracks)
  , fNOfFtpcPrimaryTracks(t.fNOfFtpcPrimaryTracks)
  , fNOfV0s(t.fNOfV0s)
  , fNOfEMCPoints(t.fNOfEMCPoints)
  , fPVx(t.fPVx)
  , fPVy(t.fPVy)
  , fPVz(t.fPVz)
  , fvpdVz(t.fvpdVz)
  , fCTBmult(t.fCTBmult)
  , fMeanDip(t.fMeanDip)
  , fRank(t.fRank)
  , fNOfVertices(t.fNOfVertices) 
  , fNOfTrigObjs(t.fNOfTrigObjs)  
  , fDSMInput(t.fDSMInput)
  , fTrigMask(t.fTrigMask)
    , fZdcWestRate(t.fZdcWestRate)
    , fZdcEastRate(t.fZdcEastRate)
    , fZdcCoincidenceRate(t.fZdcCoincidenceRate)
    , fBbcWestRate(t.fBbcWestRate)
    , fBbcEastRate(t.fBbcEastRate)
    , fBbcCoincidenceRate(t.fBbcCoincidenceRate)
    , fBbcBlueBackgroundRate(t.fBbcBlueBackgroundRate)
    , fBbcYellowBackgroundRate(t.fBbcYellowBackgroundRate)
    , fBbcAdcSumEast(t.fBbcAdcSumEast)
    , fBbcOnlineVertex(t.fBbcOnlineVertex)
    , fBbcOfflineVertex(t.fBbcOfflineVertex)
    , fRefMultFTPCE(t.fRefMultFTPCE)
    , fnumberOfVpdEastHits(t.fnumberOfVpdEastHits)
    , fnumberOfVpdWestHits(t.fnumberOfVpdWestHits)
{
  ;
}

TStarJetPicoEventHeader::~TStarJetPicoEventHeader()
{
  ;
}

void TStarJetPicoEventHeader::Clear(Option_t */*Option*/)
{
  fEventId = 0;              
  fRunId = 0;                
  fRefMult = 0;
  fGRefMult = 0;
  fNOfGlobalTracks = 0;      
  fReactionPlaneAngle = 0;   
  fNOfTriggerIds = 0;            
  fTriggerIdArray.Set(__INITIAL_NUMBER_OF_TID);
  fTriggerIdArray.Reset(0);    
  fNOfTowerTrackMatched = 0; 
  fNOfTowers = 0;         
  
  fNOfPrimaryTracks = 0; 
  fNOfMatchedTracks = 0;  
  fNOfFtpcPrimaryTracks = 0;   
  fNOfV0s = 0;  
  fNOfEMCPoints = 0;         
  fPVx = 0;                  
  fPVy = 0;                  
  fPVz = 0;                  
  fvpdVz =0;
  fCTBmult = 0;              
  fMeanDip = 0;              
  fRank = 0;                 
  fNOfVertices = 0;          
  fNOfTrigObjs = 0;
  fDSMInput = 0;
  fTrigMask = 0;
  fZdcWestRate = 0;
  fZdcEastRate = 0;
  fZdcCoincidenceRate = 0;
  fBbcWestRate = 0;
  fBbcEastRate = 0;
  fBbcCoincidenceRate = 0;
  fBbcBlueBackgroundRate = 0;
  fBbcYellowBackgroundRate = 0;
  fBbcAdcSumEast = 0;
  fBbcOnlineVertex = 0;
  fBbcOfflineVertex = 0;
  fRefMultFTPCE = 0;
    
  fnumberOfVpdEastHits = 0;
  fnumberOfVpdWestHits = 0;
}

void TStarJetPicoEventHeader::AddTriggerId(Int_t id)
{
  //
  // Add new trigger id
  // Resize the array if necessary
  //
  if ( fNOfTriggerIds < fTriggerIdArray.GetSize() )
    {
      fTriggerIdArray[fNOfTriggerIds++] = id;      
    }
  else
    {
      Int_t newsize = fTriggerIdArray.GetSize() + 1;
      __DEBUG(3, Form("Resizing trigger ids array from %d to %d", 
		      fTriggerIdArray.GetSize(), newsize));
      fTriggerIdArray.Set(newsize);
      AddTriggerId(id);
    }
}
