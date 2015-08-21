#include "TStarJetPicoTowerCuts.h"
#include "TStarJetPicoTower.h"
#include "TStarJetPicoPrimaryTrack.h"
#include "TStarJetPicoEvent.h"
#include "TStarJetPicoUtils.h"
#include "TStarJetPicoEventHeader.h"
#include "TStarJetPicoTrackCuts.h"
#include "TStarJetPicoDefinitions.h"
#include <TString.h>
#include <TMath.h>

/////////////////////////////////////////////////////////////////////////
//                                                                     //
// TStarJetPicoTowerCuts                                               //
//                                                                     //
// Default cuts implemented.                                           //
// Lots of virtual functions... so overload in derived classes and     //
// pass to TStarJetPicoReader via TStarJetPicoReader::SetTrackCuts     //
// TStarJetPicoReader::LoadTowers() calls ::IsTowerOK method.          //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

ClassImp(TStarJetPicoTowerCuts)

TStarJetPicoTowerCuts::TStarJetPicoTowerCuts()
  : TObject()
  , fMaxEt(1000.)// by default, no cut effectively
  , fMaxPhi(0.0)
  , fMinPhi(0.0)
  , y8PythiaCut(kFALSE)
{
  __DEBUG(2, "Creating tower cuts with default values.");
}

TStarJetPicoTowerCuts::TStarJetPicoTowerCuts(const TStarJetPicoTowerCuts &t)
  : TObject(t)
  , fMaxEt(t.fMaxEt)
  , fMaxPhi(t.fMaxPhi)
  , fMinPhi(t.fMinPhi)
  , y8PythiaCut(t.y8PythiaCut)
{
  __DEBUG(2, "Copy tower cuts.");  
}

Bool_t TStarJetPicoTowerCuts::IsTowerOK(Int_t mTowId, Int_t mTrigId)
{
  if (mTrigId == 200001 || mTrigId == 200003 || mTrigId == 200013)
    {
      if( mTowId ==    6 || mTowId ==   46 || mTowId ==  124 || mTowId ==  181 || 
	  mTowId ==  201 || mTowId ==  301 || mTowId ==  304 || mTowId ==  324 || 
	  mTowId ==  403 || mTowId ==  428 || mTowId ==  582 || mTowId ==  585 || 
	  mTowId ==  783 || mTowId ==  948 || mTowId == 1041 || mTowId == 1042 || 
	  mTowId == 1469 || mTowId == 1569 || mTowId == 1722 || mTowId == 1749 || 
	  mTowId == 1827 || mTowId == 1864 || mTowId == 2004 || mTowId == 2031 ||
	  mTowId == 2255 || mTowId == 2483 || mTowId == 2505 || mTowId == 2667 || 
	  mTowId == 2681 || mTowId == 2781 || mTowId == 2783 || mTowId == 2861 ||
	  mTowId == 2883 || mTowId == 2902 || mTowId == 3083 || mTowId == 3105 || 
	  mTowId == 3283 || mTowId == 3407 || mTowId == 3671 || mTowId == 3763 ||
	  mTowId == 3842 || mTowId == 3902 || mTowId == 3963 || mTowId == 4070 || 
	  mTowId == 4264 || mTowId == 4364 || mTowId == 4483 || mTowId == 4562 ||
	  mTowId == 4606 || mTowId ==   80 || mTowId ==   95 || mTowId ==  180 || 
	  mTowId ==  200 || mTowId ==  308 || mTowId ==  359 || mTowId ==  439 ||
	  mTowId ==  509 || mTowId ==  520 || mTowId ==  580 || mTowId ==  591 || 
	  mTowId ==  600 || mTowId ==  636 || mTowId ==  640 || mTowId ==  680 ||
	  mTowId ==  714 || mTowId ==  740 || mTowId ==  775 || mTowId ==  779 || 
	  mTowId ==  800 || mTowId ==  899 || mTowId ==  915 || mTowId ==  920 ||
	  mTowId == 1020 || mTowId == 1040 || mTowId == 1130 || mTowId == 1132 || 
	  mTowId == 1197 || mTowId == 1257 || mTowId == 1294 || mTowId == 1300 ||
	  mTowId == 1319 || mTowId == 1320 || mTowId == 1340 || mTowId == 1348 || 
	  mTowId == 1380 || mTowId == 1400 || mTowId == 1460 || mTowId == 1480 ||
	  mTowId == 1500 || mTowId == 1537 || mTowId == 1600 || mTowId == 1620 || 
	  mTowId == 1760 || mTowId == 1780 || mTowId == 1800 || mTowId == 1820 ||
	  mTowId == 1860 || mTowId == 1871 || mTowId == 1899 || mTowId == 1909 || 
	  mTowId == 2060 || mTowId == 2079 || mTowId == 2200 || mTowId == 2240 ||
	  mTowId == 2294 || mTowId == 2296 || mTowId == 2398 || mTowId == 2420 || 
	  mTowId == 2520 || mTowId == 2559 || mTowId == 2560 || mTowId == 2600 ||
	  mTowId == 2640 || mTowId == 2740 || mTowId == 2760 || mTowId == 2880 || 
	  mTowId == 2980 || mTowId == 3000 || mTowId == 3180 || mTowId == 3200 ||
	  mTowId == 3240 || mTowId == 3280 || mTowId == 3359 || mTowId == 3360 || 
	  mTowId == 3420 || mTowId == 3460 || mTowId == 3480 || mTowId == 3518 ||
	  mTowId == 3540 || mTowId == 3559 || mTowId == 3560 || mTowId == 3711 || 
	  mTowId == 3720 || mTowId == 3759 || mTowId == 3760 || mTowId == 3780 ||
	  mTowId == 3800 || mTowId == 3840 || mTowId == 3880 || mTowId == 4039 || 
	  mTowId == 4119 || mTowId == 4200 || mTowId == 4220 || mTowId == 4260 ||
	  mTowId == 4280 || mTowId == 4340 || mTowId == 4380 || mTowId == 4400 || 
	  mTowId == 4420 || mTowId == 4460 || mTowId == 4480 || mTowId == 4498 ||
	  mTowId == 4500 || mTowId == 4539 || mTowId == 4540 || mTowId == 4600 || 
	  mTowId == 4640 || mTowId == 4740)
	{ 
	  __DEBUG(9, Form("Reject. Tower ID: %d", mTowId));	    
	  return kFALSE;
	}
      else 
	{
	  __DEBUG(9, Form("Accept. Tower ID: %d", mTowId));	    
	  return kTRUE;
	}
    }
  //dAu & pp year8, cuts for new calibration, eta rings 1-19
  else if ( mTrigId==210020 || mTrigId==210500 || mTrigId==210501 || mTrigId==210510 || mTrigId==210511 || mTrigId==210520 || mTrigId==210521 || mTrigId==210541 || mTrigId==220500 || mTrigId==220510 || mTrigId==220520) {
    
    if ( mTowId==66 || mTowId==104 || mTowId==224 || mTowId==269 || mTowId==371 || mTowId==579 || mTowId==636 || mTowId==751 || mTowId==758 || mTowId==759 || mTowId==801 || mTowId==830 || mTowId==835 || mTowId==897 || mTowId==899 || mTowId==972 || mTowId==1045 || mTowId==1075 || mTowId==1130 || mTowId==1131 || mTowId==1132 || mTowId==1144 || mTowId==1156 || mTowId==1173 || mTowId==1179 || mTowId==1187 || mTowId==1197 || mTowId==1204 || mTowId==1233 || mTowId==1274 || mTowId==1306 || mTowId==1310 || mTowId==1312 || mTowId==1387 || mTowId==1388 || mTowId==1394 || mTowId==1510 || mTowId==1524 || mTowId==1721 || mTowId==1748 || mTowId==1759 || mTowId==1871 || mTowId==1904 || mTowId==1984 || mTowId==2037 || mTowId==2063 || mTowId==2066 || mTowId==2103 || mTowId==2162 || mTowId==2171 || mTowId==2192 || mTowId==2290 || mTowId==2299 || mTowId==2366 || mTowId==2459 || mTowId==2512 || mTowId==3094 || mTowId==3407 || mTowId==3423 || mTowId==3692 || mTowId==3838 || mTowId==3861 || mTowId==4013 || mTowId==4047 || mTowId==4273 || mTowId==4364 || mTowId==4422 || mTowId==4498 ) 
    
      {
        __DEBUG(9, Form("Reject. Tower ID: %d", mTowId));
        return kFALSE;
      }
    else
      {
        __DEBUG(9, Form("Accept. Tower ID: %d", mTowId));
        return kTRUE;
      }
  }
  else 
    {
      __DEBUG(9, Form("Accept. Tower ID: %d. TriggerID %d is OK.", mTowId, mTrigId));	    
      return kTRUE;
    }
}

Bool_t TStarJetPicoTowerCuts::IsTowerOK(TStarJetPicoTower *tw, TStarJetPicoEvent *mEv)
{
  Bool_t retval = kTRUE;
  Int_t towerId = tw->GetId();
    
  if (y8PythiaCut) {
    if (fabs(tw->GetEta())>0.95) {
      retval = kFALSE;
      __DEBUG(9, Form("Reject. In the outermost eta ring!"));
    }
    
    // Pythia "hot" towers
    if ( towerId==774 || towerId==2433 || towerId==4351 ) {
      retval = kFALSE;
      __DEBUG(9, Form("Reject. Tower ID: %d", towerId));
    }
    
    //data hot towers; 68 of them 
    if ( towerId==66 || towerId==104 || towerId==224 || towerId==269 || towerId==371 || towerId==579 || towerId==636 || towerId==751 || towerId==758 || towerId==759 || towerId==801 || towerId==830 || towerId==835 || towerId==897 || towerId==899 || towerId==972 || towerId==1045 || towerId==1075 || towerId==1130 || towerId==1131 || towerId==1132 || towerId==1144 || towerId==1156 || towerId==1173 || towerId==1179 || towerId==1187 || towerId==1197 || towerId==1204 || towerId==1233 || towerId==1274 || towerId==1306 || towerId==1310 || towerId==1312 || towerId==1387 || towerId==1388 || towerId==1394 || towerId==1510 || towerId==1524 || towerId==1721 || towerId==1748 || towerId==1759 || towerId==1871 || towerId==1904 || towerId==1984 || towerId==2037 || towerId==2063 || towerId==2066 || towerId==2103 || towerId==2162 || towerId==2171 || towerId==2192 || towerId==2290 || towerId==2299 || towerId==2366 || towerId==2459 || towerId==2512 || towerId==3094 || towerId==3407 || towerId==3423 || towerId==3692 || towerId==3838 || towerId==3861 || towerId==4013 || towerId==4047 || towerId==4273 || towerId==4364 || towerId==4422 || towerId==4498 ) {     
      retval = kFALSE;
      __DEBUG(9, Form("Reject. Tower ID: %d", towerId));      
    }

    //data dead towers - determined from dAu ht2, but almost the same for pp & other triggers; 341 out of 19/20 * 4800 = 4560
    if ( towerId==31 || towerId==34 || towerId==35 || towerId==50 || towerId==106 || towerId==114 || towerId==139 || towerId==148 || towerId==208 || towerId==251 || towerId==265 || towerId==266 || towerId==267 || towerId==283 || towerId==286 || towerId==287 || towerId==319 || towerId==341 || towerId==368 || towerId==389 || towerId==390 || towerId==391 || towerId==392 || towerId==409 || towerId==410 || towerId==411 || towerId==412 || towerId==426 || towerId==446 || towerId==485 || towerId==492 || towerId==504 || towerId==509 || towerId==533 || towerId==541 || towerId==554 || towerId==561 || towerId==562 || towerId==579 || towerId==594 || towerId==615 || towerId==616 || towerId==629 || towerId==633 || towerId==637 || towerId==638 || towerId==639 || towerId==647 || towerId==649 || towerId==650 || towerId==653 || towerId==657 || towerId==671 || towerId==673 || towerId==674 || towerId==681 || towerId==691 || towerId==695 || towerId==734 || towerId==749 || towerId==762 || towerId==790 || towerId==795 || towerId==812 || towerId==813 || towerId==814 || towerId==817 || towerId==818 || towerId==837 || towerId==839 || towerId==844 || towerId==846 || towerId==855 || towerId==857 || towerId==859 || towerId==873 || towerId==875 || towerId==899 || towerId==901 || towerId==916 || towerId==933 || towerId==939 || towerId==953 || towerId==954 || towerId==974 || towerId==1018 || towerId==1019 || towerId==1026 || towerId==1028 || towerId==1044 || towerId==1046 || towerId==1048 || towerId==1063 || towerId==1078 || towerId==1125 || towerId==1141 || towerId==1142 || towerId==1143 || towerId==1154 || towerId==1158 || towerId==1159 || towerId==1161 || towerId==1162 || towerId==1163 || towerId==1164 || towerId==1171 || towerId==1174 || towerId==1176 || towerId==1198 || towerId==1199 || towerId==1217 || towerId==1224 || towerId==1225 || towerId==1237 || towerId==1238 || towerId==1244 || towerId==1250 || towerId==1301 || towerId==1319 || towerId==1321 || towerId==1341 || towerId==1342 || towerId==1348 || towerId==1353 || towerId==1354 || towerId==1375 || towerId==1381 || towerId==1397 || towerId==1401 || towerId==1405 || towerId==1422 || towerId==1433 || towerId==1434 || towerId==1441 || towerId==1486 || towerId==1507 || towerId==1574 || towerId==1575 || towerId==1588 || towerId==1608 || towerId==1612 || towerId==1654 || towerId==1668 || towerId==1713 || towerId==1732 || towerId==1753 || towerId==1765 || towerId==1766 || towerId==1773 || towerId==1779 || towerId==1838 || towerId==1850 || towerId==1856 || towerId==1877 || towerId==1878 || towerId==1879 || towerId==1892 || towerId==1893 || towerId==1949 || towerId==1985 || towerId==2005 || towerId==2021 || towerId==2025 || towerId==2032 || towerId==2041 || towerId==2053 || towerId==2070 || towerId==2073 || towerId==2074 || towerId==2075 || towerId==2077 || towerId==2079 || towerId==2085 || towerId==2092 || towerId==2093 || towerId==2094 || towerId==2095 || towerId==2097 || towerId==2101 || towerId==2105 || towerId==2108 || towerId==2116 || towerId==2168 || towerId==2177 || towerId==2188 || towerId==2196 || towerId==2206 || towerId==2222 || towerId==2257 || towerId==2262 || towerId==2301 || towerId==2304 || towerId==2305 || towerId==2337 || towerId==2394 || towerId==2403 || towerId==2409 || towerId==2414 || towerId==2453 || towerId==2458 || towerId==2470 || towerId==2504 || towerId==2527 || towerId==2529 || towerId==2589 || towerId==2590 || towerId==2610 || towerId==2633 || towerId==2652 || towerId==2658 || towerId==2727 || towerId==2745 || towerId==2746 || towerId==2747 || towerId==2748 || towerId==2765 || towerId==2766 || towerId==2767 || towerId==2768 || towerId==2785 || towerId==2786 || towerId==2787 || towerId==2788 || towerId==2794 || towerId==2805 || towerId==2806 || towerId==2807 || towerId==2808 || towerId==2826 || towerId==2827 || towerId==2828 || towerId==2834 || towerId==2865 || towerId==2897 || towerId==2961 || towerId==2969 || towerId==2972 || towerId==3005 || towerId==3007 || towerId==3017 || towerId==3061 || towerId==3063 || towerId==3070 || towerId==3071 || towerId==3097 || towerId==3104 || towerId==3154 || towerId==3159 || towerId==3171 || towerId==3184 || towerId==3188 || towerId==3231 || towerId==3255 || towerId==3287 || towerId==3289 || towerId==3290 || towerId==3296 || towerId==3328 || towerId==3333 || towerId==3372 || towerId==3468 || towerId==3473 || towerId==3493 || towerId==3494 || towerId==3495 || towerId==3508 || towerId==3515 || towerId==3544 || towerId==3557 || towerId==3588 || towerId==3604 || towerId==3611 || towerId==3653 || towerId==3678 || towerId==3679 || towerId==3690 || towerId==3709 || towerId==3715 || towerId==3718 || towerId==3727 || towerId==3738 || towerId==3745 || towerId==3746 || towerId==3761 || towerId==3769 || towerId==3795 || towerId==3803 || towerId==3948 || towerId==3986 || towerId==4014 || towerId==4015 || towerId==4016 || towerId==4017 || towerId==4018 || towerId==4019 || towerId==4053 || towerId==4054 || towerId==4055 || towerId==4056 || towerId==4057 || towerId==4075 || towerId==4077 || towerId==4078 || towerId==4105 || towerId==4107 || towerId==4119 || towerId==4130 || towerId==4171 || towerId==4174 || towerId==4217 || towerId==4257 || towerId==4299 || towerId==4326 || towerId==4357 || towerId==4377 || towerId==4388 || towerId==4453 || towerId==4459 || towerId==4464 || towerId==4505 || towerId==4506 || towerId==4507 || towerId==4508 || towerId==4514 || towerId==4534 || towerId==4543 || towerId==4549 || towerId==4569 || towerId==4584 || towerId==4585 || towerId==4595 || towerId==4596 || towerId==4671 || towerId==4672 || towerId==4677 || towerId==4678 || towerId==4684 || towerId==4765 || towerId==4766 || towerId==4768 || towerId==4792) {
      
      retval = kFALSE;
      __DEBUG(9, Form("Reject. Tower ID: %d", towerId));      
    } // data dead towers
  }

  // Check against standard list
  for (Int_t id = 0; id < mEv->GetHeader()->GetNOfTriggerIds(); id++){
    Int_t TrigId = mEv->GetHeader()->GetTriggerId(id);
    if ( IsTowerOK(towerId, TrigId) == kFALSE ) {
      retval = kFALSE;
      break;
    }
      
    //cut out two outermost eta rings for dAu 2009, as suggested in emc2 discussion-february 2009
    //and also for p+p year 8!
    if ( TrigId==210020 || TrigId==210500 || TrigId==210501 || 
	 TrigId==210510 || TrigId==210511 || TrigId==210520 || 
	 TrigId==210521 || TrigId==210541 ||
	 TrigId==220500 || TrigId==220510 || TrigId==220520)  {
	if (TMath::Abs(tw->GetEta())>0.95) {
	  retval = kFALSE;
	  __DEBUG(9, Form("Reject. In the outermost eta ring!"));
	}
    }
  }

  Double_t et = tw->GetEnergy()/TMath::CosH(tw->GetEtaCorrected());
  if (et < fMaxEt) {
    __DEBUG(9, Form("Accept. %f < %f", et, fMaxEt));
  } 
  else {
    __DEBUG(9, Form("Reject. ! %f < %f", et, fMaxEt));
    retval = kFALSE;
  }

  return retval;
}

Bool_t TStarJetPicoTowerCuts::CheckTowerQA(TStarJetPicoTower *tw, TStarJetPicoEvent *mEv)
{
  return IsTowerOK(tw, mEv);
}

//nick elsey: rejects towers based on lists of towers given at initialization
Bool_t TStarJetPicoTowerCuts::CheckTowerAgainstLists(TStarJetPicoTower *tw)
{
    if (std::find(hotTowers.begin(), hotTowers.end(), tw->GetId() ) != hotTowers.end() )
        return kFALSE;
    if (std::find(deadTowers.begin(), deadTowers.end(), tw->GetId() ) != deadTowers.end() )
        return kFALSE;
    return kTRUE;
}

Bool_t TStarJetPicoTowerCuts::AddHotTower(Int_t Id)
{
    if ( Id > 4800 || Id < 1 ) {
        __ERROR(Form("%d is out of range",Id));
        return kFALSE;
    }
    hotTowers.insert(Id);
    return kTRUE;
}

Bool_t TStarJetPicoTowerCuts::AddDeadTower(Int_t Id)
{
    if ( Id > 4800 || Id < 1 ) {
        __ERROR(Form("%d is out of range",Id));
        return kFALSE;
    }
    deadTowers.insert(Id);
    return kTRUE;
}

Bool_t TStarJetPicoTowerCuts::AddHotTowers(std::vector<Int_t> Ids)
{
    for (unsigned i = 0; i < Ids.size(); ++i)
        if ( Ids[i] > 4800 || Ids[i] < 1 ) {
            __ERROR(Form("%d is out of range",Ids[i]));
            return kFALSE;
        }

    for (unsigned i = 0; i < Ids.size(); ++i)
        hotTowers.insert(Ids[i]);
    return kTRUE;
}

Bool_t TStarJetPicoTowerCuts::AddDeadTowers(std::vector<Int_t> Ids)
{
    for (unsigned i = 0; i < Ids.size(); ++i)
        if ( Ids[i] > 4800 || Ids[i] < 1 ) {
            __ERROR(Form("%d is out of range",Ids[i]));
            return kFALSE;
        }
    
    for (unsigned i = 0; i < Ids.size(); ++i)
        deadTowers.insert(Ids[i]);
    return kTRUE;
}


// From Mark based on SPIN pp jet-finder !!!
Double_t TStarJetPicoTowerCuts::TowerEnergyMipCorr(TStarJetPicoTower *mTower)
{
  Double_t mTowE = mTower->GetEnergy();

   // MIP corr see SPIN !!!
  Double_t theta = 2.*atan(exp(mTower->GetEta()));
  Double_t MipE  = 0.261*(1.+0.056*mTower->GetEta()*mTower->GetEta())/sin(theta); //GeV
  Int_t    nTr   = mTower->GetNAssocTracks();
  Double_t Ecorr = mTowE - nTr * MipE;

  return Ecorr;
}

Double_t TStarJetPicoTowerCuts::HadronicCorrection(TStarJetPicoTower *mTower,
						   TStarJetPicoEvent *mEvent,
						   TStarJetPicoTrackCuts *trackQA,
						   Double_t frac)
{
  Double_t Ecorr = mTower->GetEnergy();
  // check the associated tracks
  for (Int_t ntrack = 0; ntrack < mTower->GetNAssocTracks(); ntrack++)
    {
      Int_t idx = mTower->GetMatchedTrackIndex(ntrack);
      TStarJetPicoPrimaryTrack *ptrack = mEvent->GetPrimaryTrack(idx);
      if (trackQA->IsTrackOK(ptrack) == kTRUE)
	{
	  Double_t pel2 = 
	    ptrack->GetPx() * ptrack->GetPx() + 
	    ptrack->GetPy() * ptrack->GetPy() + 
	    ptrack->GetPz() * ptrack->GetPz();
	  
	  if (TStarJetPicoUtils::IsElectron(mTower, ptrack) == kTRUE)
	    {
	      Double_t mel2 = __STARJETPICO_MASS_ELECTRON * __STARJETPICO_MASS_ELECTRON;
	      Double_t Eel = TMath::Sqrt(pel2 + mel2);
	      Ecorr -= Eel; 
	    } // is electron

	  else Ecorr -= frac * TMath::Sqrt(pel2);
	} // track is OK
    } // loop over associated tracks
  
  return Ecorr;
}

Bool_t TStarJetPicoTowerCuts::SetPhiCut(Double_t min, Double_t max)
{
    Bool_t retval = kTRUE;
    if ( min > TMath::Pi() || min < (-1.0)*TMath::Pi() ) {
        __ERROR("Phi minimum cut out of bounds [-Pi,Pi]. Using Defaults.");
        retval = kFALSE;
    }
    if ( max > TMath::Pi() || max < (-1.0)*TMath::Pi() ) {
        __ERROR("Phi maximum cut out of bounds [-Pi,Pi]. Using Defaults.");
        retval = kFALSE;
    }
    if (!retval)  return kFALSE;
    
    fMinPhi = min;
    fMaxPhi = max;
    return kTRUE;
}
