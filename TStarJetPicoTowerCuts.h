#ifndef __TSTARJETPICOTOWERCUTS_HH
#define __TSTARJETPICOTOWERCUTS_HH

#include <TObject.h>

class TStarJetPicoEvent;
class TStarJetPicoTower;
class TStarJetPicoTrackCuts;

class TStarJetPicoTowerCuts : public TObject
{
 public:
  TStarJetPicoTowerCuts();
  TStarJetPicoTowerCuts(const TStarJetPicoTowerCuts &t);
  virtual ~TStarJetPicoTowerCuts() {;} // nothing to delete

  virtual Bool_t IsTowerOK(Int_t mTowId, Int_t mTrigId);
  virtual Bool_t IsTowerOK(TStarJetPicoTower *tw, TStarJetPicoEvent *mEv);
  virtual Bool_t CheckTowerQA(TStarJetPicoTower *tw, TStarJetPicoEvent *mEv);

  virtual Double_t TowerEnergyMipCorr(TStarJetPicoTower *mTower);

  virtual Double_t HadronicCorrection(TStarJetPicoTower *mTower,
			      TStarJetPicoEvent *mEvent,
			      TStarJetPicoTrackCuts *trackQA,
			      Double_t frac);

  virtual Int_t    DoPID(TStarJetPicoTower */*tw*/) {return 0;}

  void SetMaxEtCut(Double_t val) {fMaxEt = val;}
  Double_t GetMaxEtCut() {return fMaxEt;}

  void Sety8PythiaCut(Bool_t val) {y8PythiaCut = val;}
  Bool_t Gety8PythiaCut() {return y8PythiaCut;}

 private:
  Double_t fMaxEt;
  
  Bool_t y8PythiaCut;

  ClassDef(TStarJetPicoTowerCuts, 3)
};

#endif
