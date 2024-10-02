//****************************************************************************
// Two office tables of similar design, but different width.
// They combine well with the office containers 1 and 2.
// ***************************************************************************
// Objects provided by this file are:
//	BUEROTISCH1
//	BUEROTISCH2
// Textures provided by this file are:
//	- none -
// ***************************************************************************
// Scale: 1 millimeter per POV unit.
// ***************************************************************************
// *               Manfred.Agne@munich.netsurf.de  (1998)                    *
// *                     Feel free to use this file.                         *
// ***************************************************************************
#declare table = version
#version 1.0

#include "woods.inc"
#include "metals.inc"

//############################################################################
// BÅrotisch: 800mm tief (z), 1200mm lang (x), OberflÑche 800mm hoch (y).
// Mitte der Tischplatte ist (0,800,0), Beine auf dem Boden (y=0).
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#declare BUEROTISCH1 =
union {
  box {<-600,764,-400>,<600,790,400> texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  box {<-600,790,-390>,<600,800,390> texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  cylinder{<-600,790, 390>,<600,790, 390>,10 texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  cylinder{<-600,790,-390>,<600,790,-390>,10 texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  //---Rahmen und Beine:---
  box {<-590,764,-390>,< 590,700,-370> texture {T_Chrome_1A}}
  box {<-590,764, 390>,< 590,700, 370> texture {T_Chrome_1A}}
  box {<-590,764,-390>,<-570,700, 370> texture {T_Chrome_1A}}
  box {< 590,764,-390>,< 570,700, 370> texture {T_Chrome_1A}}
  box {<-590,764,-390>,<-570,  0,-324> texture {T_Chrome_1A}}
  box {< 590,764,-390>,< 570,  0,-324> texture {T_Chrome_1A}}
  box {<-590,764, 390>,<-570,  0, 324> texture {T_Chrome_1A}}
  box {< 590,764, 390>,< 570,  0, 324> texture {T_Chrome_1A}}
}
//############################################################################
// BÅrotisch: 800mm tief (z), 1800mm lang (x), OberflÑche 800mm hoch (y).
// Mitte der Tischplatte ist (0,800,0), Beine auf dem Boden (y=0).
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#declare BUEROTISCH2 =
union {
  box {<-900,764,-400>,<900,790,400> texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  box {<-900,790,-390>,<900,800,390> texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  cylinder{<-900,790, 390>,<900,790, 390>,10 texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  cylinder{<-900,790,-390>,<900,790,-390>,10 texture {T_Wood7 rotate<0,90,0> scale <30,30,30>}}
  //---Rahmen und Beine:---
  box {<-890,764,-390>,< 890,700,-370> texture {T_Chrome_1A}}
  box {<-890,764, 390>,< 890,700, 370> texture {T_Chrome_1A}}
  box {<-890,764,-390>,<-870,700, 370> texture {T_Chrome_1A}}
  box {< 890,764,-390>,< 870,700, 370> texture {T_Chrome_1A}}
  box {<-890,764,-390>,<-870,  0,-324> texture {T_Chrome_1A}}
  box {< 890,764,-390>,< 870,  0,-324> texture {T_Chrome_1A}}
  box {<-890,764, 390>,<-870,  0, 324> texture {T_Chrome_1A}}
  box {< 890,764, 390>,< 870,  0, 324> texture {T_Chrome_1A}}
}
//**************************************************************************
//*** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF **
//**************************************************************************
