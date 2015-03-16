#ifndef __TSTARJETPICOEVENTCUTS__HH
#define __TSTARJETPICOEVENTCUTS__HH

#include <TObject.h>
#include <TString.h>

class TStarJetPicoEvent;

class TStarJetPicoEventCuts : public TObject
{
 public:
  TStarJetPicoEventCuts();
  TStarJetPicoEventCuts(const TStarJetPicoEventCuts &t);
  virtual ~TStarJetPicoEventCuts() {;} //nothing to delete here

  virtual Bool_t IsEventOK(TStarJetPicoEvent *mEv);  // kTRUE if OK; kFALSE otherwise
  virtual Bool_t CheckEvent(TStarJetPicoEvent *mEv); // kTRUE if OK; kFALSE otherwise

  virtual Bool_t IsTriggerIdOK(Int_t mTrigId);
  virtual Bool_t IsTriggerIdOK(TStarJetPicoEvent *mEv);
  virtual Bool_t IsRefMultOK(TStarJetPicoEvent *mEv);
  virtual Bool_t IsVertexZOK(TStarJetPicoEvent *mEv);
  virtual Bool_t IsVertexZDiffOK(TStarJetPicoEvent *mEv);
  virtual Bool_t IsPVRankingOK(TStarJetPicoEvent *mEv);
  
  //the following are added (by Jan Kapitan) for dAu (run8) and are only checked for corresponding run numbers (backward compatibility)
  virtual Bool_t IsBbceOK(TStarJetPicoEvent *mEv);
  virtual Bool_t IsScalersOK(TStarJetPicoEvent *mEv);

  virtual void   SetTriggerSelection(const char *str) {fTrigSel = str;}
  virtual void   SetVertexZCut(Float_t val) {fVzCut = val;}
  virtual void   SetVertexZDiffCut(Float_t val) {fVzDiffCut = val;}
  virtual void   SetRefMultCut(Int_t valmin, Int_t valmax = 99999) 
  {
    fRefMultCutMin = valmin; 
    fRefMultCutMax = valmax;
  }
  virtual void   SetBbceCut(Int_t valmin, Int_t valmax = 99999) 
  {
    fBbceCutMin = valmin; 
    fBbceCutMax = valmax;
  }
  virtual void   SetPVRankingCut(Float_t val) {fFlagPVRankingCut=kTRUE; fPVRankingCut = val;}
  virtual void   SetPVRankingCutOff() {fFlagPVRankingCut=kFALSE;}

  virtual Int_t  GetReferenceMultiplicity(TStarJetPicoEvent *mEv);

  TString GetTriggerSelection() {return fTrigSel;}
  Float_t GetVertexZCut()       {return fVzCut;}
  Float_t GetVertexZDiffCut()   {return fVzDiffCut;}
  Int_t   GetRefMultCutMin()    {return fRefMultCutMin;}
  Int_t   GetRefMultCutMax()    {return fRefMultCutMax;}
  Int_t   GetBbceCutMin() {return fBbceCutMin;}
  Int_t   GetBbceCutMax() {return fBbceCutMax;}
  Float_t GetPVRankingCut() {return fPVRankingCut;}

 private:

  TString fTrigSel; // All,HT,MB,pp,dAu_mb,dAu_ht_all,dAu_ht0,dAu_ht1,dAu_ht2,dAu_ht4, y8p+p_ht0,y8p+p_ht1,y8p+p_ht2  
  Float_t fVzCut; // accept all events with vz: Abs(vz) < fVzCut - // Default STAR high-pt cuts == 50.
  Float_t fVzDiffCut; // accept all events with Abs(vzTPC - vzVPD) <  fVzDiffCut. Mainly for good TOF PID purposes

  Int_t   fRefMultCutMin; // accept all events with refmult: refmult > fRefMultCutMin && refmult < fRefMultCutMax
  Int_t   fRefMultCutMax;  // accept all events with refmult: refmult > fRefMultCutMin && refmult < fRefMultCutMax
  Int_t   fBbceCutMin;
  Int_t   fBbceCutMax;
  Float_t fPVRankingCut;
  Bool_t  fFlagPVRankingCut;
  

  ClassDef(TStarJetPicoEventCuts, 3)
};

#endif
