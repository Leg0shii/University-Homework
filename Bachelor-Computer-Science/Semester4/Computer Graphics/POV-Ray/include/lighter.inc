// PoVRay 3.5 INC File "lighter.inc"
// created by YOKOJENS
// Date:   06 Mar 2004
// Mail: yokopov@of-netz.de
// 1 unit circa 0.5cm
// 
//--------------------------------------------------------------------------
#version 3.5;
global_settings {  assumed_gamma 1.6}
include "textures.inc"
include "colors.inc"
//--------------------------------------------------------------------------

#macro Zackenrad (radius1, radius2, zdicke, tiefe, zanz)
         #declare strich2 = box {<(-zdicke/2),-0.0001,(radius2+(radius1-radius2)*0.66)><(zdicke/2),tiefe, radius1>}
         #local i = 0;
         #declare Zacken =
	     union {
                    #while (i < zanz)
                        object {strich2 rotate <0,i*360/zanz,0> translate <0,0,0>}
                        #local i = i+1;
            	    #end
		
             }
             #declare Z_out = union {
                                object {Zacken}
                                cylinder {<0,0,0><0,tiefe,0>,radius1-(radius1/5)}
                                }
        object {Z_out rotate <0,0,90>}
#end

#declare Feuerzeug_tmp =

                // KORPUS AUS PLASTIK
                #declare FZkorpus_out = 
                   merge { 
                        cylinder {<0, -0.65, 0><0, 0.65, 0>,0.1 translate <0, 0, -0.10>}
                        cylinder {<0, -0.65, 0><0, 0.65, 0>,0.1 translate <0, 0,  0.10>}
                        box      {<-0.10001, -0.65001, -0.10001><0.10001, 0.65001, 0.10001>}
                 }       
                        
                #declare FZkorpus_in =
                   merge { 
                        cylinder {<0, -0.58, 0><0, 0.66, 0>,0.08 translate <0, 0, -0.08>}
                        cylinder {<0, -0.58, 0><0, 0.66, 0>,0.08 translate <0, 0,  0.08>}
                        box      {<-0.08001, -0.58, -0.08001><0.08001, 0.66, 0.08001>}
                 }       
                 #declare FZkorpus_unten =
                   merge { 
                        cylinder {<0, -0.7, 0><0, -0.62, 0>,0.08 translate <0, 0, -0.08>}
                        cylinder {<0, -0.7, 0><0, -0.62, 0>,0.08 translate <0, 0,  0.08>}
                        box      {<-0.08001, -0.7, -0.08001><0.08001, -0.62, 0.08001>}
                 }       
                #declare FZ_korpus =                        
                         merge {
                              difference {
                                object {FZkorpus_out}
                                object {FZkorpus_in}
                                object {FZkorpus_unten}
                              }
                              merge {
                                box {<-0.0801001, -0.621, -0.025><0.0801001, 0.4, 0.025>}
                                cylinder {<-0.0801, 0.4, -0><0.0801, 0.4, 0>,0.025}
                              }
                         }

                // KORKEN UND INNENLEBEN
                // -----------------------------------                
                
                #declare FZ_Korken =
                        
                        #declare FZ_Korken_Deckel_s =
                             union  { 
                                cylinder {<0, 0.649, 0><0, 0.71, 0>,0.1 translate <0, 0, -0.10>}
                                cylinder {<0, 0.649, 0><0, 0.71 , 0>,0.1 translate <0, 0,  0.10>}
                                box      {<-0.10001, .64901, -0.10001><0.10001, 0.71, 0.10001>}
                             }       
                        #declare FZ_Korken_Deckel_w =
                            union {  
                                cylinder {<0, 0.65, 0><0, 0.52, 0>,0.08 translate <0, 0, -0.08>}
                                cylinder {<0, 0.65, 0><0, 0.52, 0>,0.08 translate <0, 0,  0.08>}
                                box      {<-0.08001, 0.65, -0.08001><0.08001, 0.52, 0.08001>}
                        
                                // Innenbau useless
                                cylinder {<0,0,0><0,-0.05,0>,0.07 translate <0,0.51,0.05>}
                                // Innenbau Gasaustritt
                                cylinder {<0,0,0><0,-0.05,0>,0.05 translate <0,0.51,-0.1>}
                                cylinder {<0,0,0><0,-0.05,0>,0.05 translate <0,0.51,-0.1>}
                                cylinder {<0,0,0><0,-0.05,0>,0.04 translate <0,0.47,-0.1> texture {Chrome_Metal finish{metallic 8 ambient 0.3 reflection .4 phong 1}}}
                                // Roehrchen
                                cylinder {<0,0,0><0, -1.1, 0>,0.023 translate <0,.6,-0.1>  texture {pigment {color White} finish{ambient 0.7 reflection .4 phong 1}}}
                            }       
                        union { 
                                object {FZ_Korken_Deckel_w texture {pigment {color White*1.1}}}
                                object {FZ_Korken_Deckel_s texture {pigment {color Black}} finish {reflection 0.1 phong .6 phong_size 111 }}
                        }
                // MECHANIK (AUFSATZ)
                // -----------------------------------
                
                #declare FZ_Mechanik =
                         #declare FZ_Mechanik_Blende_Rohling =
                             union {
                                cylinder {<0, -0, 0><0, 0.23, 0>,0.1 translate <0, 0, -0.10>}
                                cylinder {<0, -0, 0><0, 0.23, 0>,0.1 translate <0, 0,  0.10>}
                                box      {<-0.10001, -0.0001, -0.10001><0.10001, 0.2301, 0.10001>}
                             }       
                                                      
                         #declare FZ_MECHANIK_torhalb =
                                difference {
                                             torus {0.08, 0.007}
                                             box {<-1,-1,0> <1,1,0.4>}
                                }
                                                                           
                         #declare FZ_MECHANIK_Knopf =
                                union {
                                        cylinder {<0,0,0><0,0.1,0>,0.06}
                                        difference {
                                                cylinder {<0, 0.070, 0><0, 0.10, 0.0>,0.1}
                                                box      {<-0.5, 0.069, 0><0.5, 0.15, .5>}
                                        }
                                
                                }
                         
                         #declare  FZ_Mechanik_Aufsatz =
                                      merge {
                                              difference {
                                                    object {FZ_Mechanik_Blende_Rohling}
                                                    object {FZ_Mechanik_Blende_Rohling scale 0.90}
                                                    // Schnitt
                                                    box {<-0.5, -0.10, .075><0.5, 0.5,5>}
                                                    // Oeffnung fuers Rad
                                                    box {<-0.08, -0.10, -0.045><0.08, 0.3,0.5>}
                                                    // Schnitt verzierung1
                                                    box {<-0.0075, -0.10, -0.18><0.0075, 0.3,0.5>}
                                                    // Schnitt verzierung2
                                                    object {FZ_MECHANIK_torhalb scale <1,10,1> translate<0.0 ,0.23,-0.10> }
                                                    // Feueroeffnung
                                                    cylinder {<0, .1, 0><0, 0.3, 0>,0.04 translate <0, 0,  -0.115>}
                                                    // Gas-Regulierung
                                                    box {<-0.063, 0.0, 0><0.063, 0.085,-1.5>}                  
                                                    //Rundungen neben Rad
                                                    box {<-.2, 0.20 ,0.076  ><.2 , .25, 0.045>  translate <0,0,0 >}
                                              }
                                             
                                              // Gas-Schnuddel
                                                box {<-.02, 0.0 ,0 ><.02 , 0.025, -.04>  translate <0,0.06,-0.18 > texture {pigment {color Black}}}                  
                                              // KNOPF  
                                                object {FZ_MECHANIK_Knopf rotate<0,180,0> texture {pigment {color Black} finish{reflection 0.3}} translate <0,.01 ,0.1>}
                                               // Rundung neben Rad       
                                                cylinder {<0,0,0><0.019, 0, 0.0>,0.03  translate <0.08100001 , 0.20, 0.045  >}     
                                                cylinder {<0,0,0><0.019, 0, 0.0>,0.03  translate <-0.100001 , 0.20, 0.045  >}     
                                                      
                                                      
                                                      
                                                            
                                     
                                     }

                        #declare  FZ_Mechanik_Raedchen =   union {
                                        // Zackenrad (radius1, radius2, zdicke, tiefe, zanz)
                                        object {Zackenrad(0.08, 0, 0.005 ,0.04, 60) rotate <0,0,0>translate<-0.05, 0, 0.0> texture {Chrome_Metal} finish { reflection 0.3 phong .1 phong_size 1}}
                                        object {Zackenrad(0.07, 0, 0.001 ,0.08, 150) rotate <0,0,0>translate<0.01, 0, 0.0>  texture {Chrome_Metal} finish { reflection 0.0 phong .1 phong_size 1} }
                                        object {Zackenrad(0.08, 0, 0.005 ,0.04, 60) rotate <0,0,0>translate<0.05, 0, 0.0 > texture {Chrome_Metal} finish { reflection 0.3 phong .1 phong_size 1} }
                        
                        
                        }


                        union { 
                                object {FZ_Mechanik_Aufsatz texture {Chrome_Metal} finish {metallic 1 reflection 0.3 phong 1 phong_size 3}}
                                object {FZ_Mechanik_Raedchen scale <1.05,0.9,.9>translate <0.02,0.18,0.03>}
                        
                          
                        }

         //BAUE FZ ZUSEMMEN---------------------------------
         union {  object {FZ_korpus
                          texture {pigment {rgbf <.8,1,.8,0.98>}}                          
                          texture {pigment {rgbf <0.8,0.8,1,0.99>}}
                          finish {reflection 0.1 phong 1 phong_size 13 }
                          interior {ior 1.5 caustics 1}                                         
                  }
                  object {FZ_Korken scale 1.0000000001} 
                  object {FZ_Mechanik scale 0.999999 translate <0,.649,0>} 
         }

#declare Lighter =
        object {Feuerzeug_tmp rotate <0,0,0>translate <0,.649999,0>}
