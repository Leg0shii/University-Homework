// PoVRay 3.7 Scene File "AirFilter.pov"
// author:  BM
// date:    27.04.2021
//--------------------------------------------------------------------------
#version 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
#include "shapes3.inc"

// ------------------- QUELLEN -----------------
// ---------------------------------------------                                       
#include "chair3.inc"
// Stuhl: von Lance Purple (1997)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?ws_chair.pov
  
#include "table5.inc"
// Tisch: von Manfred Agne (1998)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?table.zip


#include "screwdriver.inc"
// Schraubenzieher: von Dan Connelly (1998)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?screwdri.pov

#include "scie.inc"
// S�ge: von Ferdinand
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?scie.pov

#include "knife.inc"
// Taschenmesser: Bonsai (2002)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?pocketknife.zip

#include "lighter.inc"
// Feuerzeug: von Yoko Jens (2004)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?lighter.zip

#include "hatholder.inc"
// Hut und Huthalter: von Ken Tyler (1998)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?hatrack.pov}             
       
#include "desklamp.inc" 
// Tischlampe: von Ian Shumsky (2000)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?desklamp.zip

#include "window.inc"  
// Fenster: von Fabien Mosen (2000)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?windows2.zip            
            

#include "PENCIL.inc"
// Stifte: von Norm Krumpe (1998)
// Link: http://objects.povworld.org/objects/cgi-bin/dl.cgi?pencil.zip            
 

  
//--------------------------------------------------------------------------
// Kamera ------------------------------------------------------------------
//--------------------------------------------------------------------------
// Die �bersicht Ansicht                            
#declare Ueberblick = camera { angle 90
                               location  <3.0, 4.9 ,-7.0>
                               right     x*image_width/image_height
                               look_at   <-0.0 , 0.0 , 0.0>}
                            

// Die interessante Ansicht                            
#declare Interessant = camera { angle 90
                                location  <2.4, 1.6 ,-3.3>
                                right     x*image_width/image_height
                                look_at   <3.0 , 1.0 , -3.0>}
                            

// Die Nahaufnahme                            
#declare Nahaufnahme = camera { angle 90     
                                location  <0.0 , 0.3 ,4.8>
                                right     x*image_width/image_height
                                look_at   <-0.5, 0.5, 5.5>}                            
camera{Ueberblick}



//--------------------------------------------------------------------------
// Licht ------------------------------------------------------------------
//--------------------------------------------------------------------------    
// Sonne die scheint  
light_source{<-1500,8000,-2500> color White} 

// LEDs im 'Steinschrank'
light_source{ <-0.5, 1, 5.5> color rgb<1,1,1>*0.2 fade_distance 0.02 }
light_source{ <0.5, 1, 5.5> color rgb<1,1,1>*0.2 fade_distance 0.02 }


// Himmel -------------------------------------------------------------- 
plane{<0,1,0>,1 hollow  
       texture{ pigment{ bozo turbulence 0.92
                         color_map { [0.00 rgb <0.20, 0.20, 1.0>*0.9]
                                     [0.50 rgb <0.20, 0.20, 1.0>*0.9]
                                     [0.70 rgb <1,1,1>]
                                     [0.85 rgb <0.25,0.25,0.25>]
                                     [1.0 rgb <0.5,0.5,0.5>]}
                        scale<1,1,1.5>*2.5  translate< 0,0,0>
                       }
                finish {ambient 1 diffuse 0} }      
       scale 10000}         


 
//--------------------------------------------------------------------------
//---------------------------- Luftfilter in der Szene ----------------------------
//--------------------------------------------------------------------------
// Mittelst�ck des Luftfilters
#declare Mittelbox = 
box { <-0.19,0,-0.205>,< 0.19, 0.47, 0.205>                                   
      texture { pigment{ color rgb<1.00, 1.00, 1.00>*1.1}  
                finish { phong 1 reflection{ 0.10 metallic 0.00} } 
              } // end of texture
    } // end of box --------------------------------------


    
// Seitenbox die benutzt wird um die Kanten der Mittelbox abzuschneiden    
#declare Seitenbox =
box { <-0.05,0,-0.05>,< 0.05, 0.7, 0.05>   
      texture { pigment{ color rgb<1.00, 1.00, 1.00>*1.1}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture
    } // end of box --------------------------------------

 
 
// Differenz aus Mittelbox und den vier Seitenboxen um ein 8-eck zu erhalten
#declare Mittelbox_mit_abgeschnittenen_ecken =
difference {
             object { Mittelbox translate<0.19,0.18,0.205>}
             object { Seitenbox rotate<0,45,0> translate<0,0.1,0> }
             object { Seitenbox rotate<0,45,0> translate<0.38,0.1,0> } 
             object { Seitenbox rotate<0,45,0> translate<0.38,0.1,0.41> }
             object { Seitenbox rotate<0,45,0> translate<0,0.1,0.41> } 
           }



// Erzeugt Objekt f�r die Ripperlung im Luftfilter
#declare Optische_Platten_Differenz_Mittelbox =
difference { 
             object { Mittelbox_mit_abgeschnittenen_ecken scale<1.5,0.015,1.5> translate<-0.1,0.0,-0.1> }                                
             object { Mittelbox_mit_abgeschnittenen_ecken scale<0.9,0.04,0.9> translate<0.02,-0.01,0.02> } 
           }

                       
                       
// F�nf dieser Objekte vereint
#declare Optische_Platten_Differenz_Mittelbox_3 =
union { 
        object { Optische_Platten_Differenz_Mittelbox scale<1.01, 1, 1.01> translate<0,0.3,0> }
        object { Optische_Platten_Differenz_Mittelbox scale<1.01, 1, 1.01> translate<0,0.415,0> }
        object { Optische_Platten_Differenz_Mittelbox scale<1.01, 1, 1.01> translate<0,0.53,0> }
      }

      
      
// Differenz von Rippeln mit der Mittelbox 
#declare Mittelbox_mit_Ripple = 
difference {
             object { Mittelbox_mit_abgeschnittenen_ecken }
             object { Optische_Platten_Differenz_Mittelbox_3 } 
}



// Kopf des Knaufes
#declare Knaufkopf =
intersection {
               sphere { <0,0,0>, 0.1 
                        texture { pigment{ color rgb<0.5, 0.5, 0.5>*1.1}
                                  finish { phong 1.0 reflection 0.50}
                                } // end of texture  
                      }  // end of sphere ----------------------------------- 
               sphere { <0,0,0>, 0.1 
                        texture { pigment{ color rgb<0.5, 0.5, 0.5>*1.1}
                                  finish { phong 1.0 reflection 0.50}
                                } // end of texture
                         translate<0,0.1,0>  
                      }  // end of sphere -----------------------------------
             }



// Hals des Knaufes
#declare Knaufhals =
cylinder { <0,0,0>,<0,0,0.1>,0.03 
           texture { pigment { color rgb<0.5, 0.5, 0.5>*1.1}
                   //normal  { bumps 0.5 scale 0.005}  
                     finish  { phong 0.5 reflection{ 0.50 metallic 0.50} } 
                   } // end of texture
         } // end of cylinder  ------------------------------------




// Knauf der an der Seite der Mittelbox angebracht ist und dazu dient den Airfilter seitlich �ffnen und s�ubern zu k�nnen
#declare Knauf = 
union { 
        object { Knaufkopf scale<0.6,0.6,0.6> rotate<90,0,0> translate<0,0.1,0> }
        object { Knaufhals scale<0.6,0.6,0.6> translate<0,0.1,0.05> }
      }




#declare Mittelbox_mit_Knauf =
union {
        object { Mittelbox_mit_Ripple }
        object { Knauf translate<0.2,0.39,-0.11>}
       
      }
              
         

// Grundbox f�r den Standfu�
#declare Standbox = 
box { <-0.22,0,-0.22>,< 0.22, 0.2, 0.22>   
      texture { pigment{ color rgb<0.1, 0.1, 0.1>*1.1}  
                finish { phong 1 reflection{ 0.05 metallic 0.50} } 
              } // end of texture
        
      scale <1,1,1> rotate<0,0,0> translate<0,0,0>                                           
    } // end of box --------------------------------------
                                            
                                            

// Der Zylinder schneidet sp�ter F��e in die Standbox
#declare Zylinder =
cylinder { <0,0,-0.25>,<0,0,0.25>, 0.16 
           texture { pigment { color rgb<0.1, 0.1, 0.1>*1.1}
                     finish  { phong 0.5 reflection{ 0.05 metallic 0.50} } 
                   } // end of texture
         } // end of cylinder  ------------------------------------                                                    
   
   

// Der Fu� aufdem der Luffilter steht
#declare Standfuss =
difference {
             object { Standbox translate<0.19,0,0.19> }
             object { Zylinder translate<0.18,0,0.20> }
             object { Zylinder rotate<0,90,0> translate<0.18,0,0.20> }
           }


// Oberer Grund Box des Luftfilters
#declare Obere_Grund_Box = 
box { <-0.20,0,-0.215>,< 0.20, 0.12, 0.215>                                   
      texture { pigment{ color rgb<0.2, 0.2, 0.2>*1.1}  
                finish { phong 1 reflection{ 0.05 metallic 0.50} } 
              } // end of texture 
    } // end of box --------------------------------------



// Box die zum abschneiden der Kanten der oberen Box verwendet wird
#declare Obere_Seitenbox =
box { <-0.06,0,-0.03>,< 0.06, 0.2, 0.03>   
      texture { pigment{ color rgb<0.2, 0.2, 0.2>*1.1}  
                finish { phong 1 reflection{ 0.05 metallic 0.50} } 
              } // end of texture
    } // end of box --------------------------------------



// Kugel die f�r die Aush�lung am oberen Teil des Luftfilters benutzt wird
#declare Sphere =
sphere { <0,0,0>, 0.1 
         texture { pigment{ color rgb<0.2, 0.2, 0.2>*1.1}
                   finish { phong 2.0 reflection 0.05}
                 } // end of texture
       }  // end of sphere -----------------------------------



// Obere Box mit 8-Ecken
#declare Obere_AchtEck_Box =
difference {
             object { Obere_Grund_Box translate<0.19,0.65,0.205> }
             object { Obere_Seitenbox rotate<0,45,0> translate<0,0.6,0> }
             object { Obere_Seitenbox rotate<0,135,0> translate<0.38,0.6,0> }
             object { Obere_Seitenbox rotate<0,45,0> translate<0.38,0.6,0.41> }         
             object { Obere_Seitenbox rotate<0,135,0> translate<0,0.6,0.41> }
           }


// Erzeugt das Grundobjekt f�r die L�cher durch die "gefiltert" wird
#declare Optische_Platten_Differenz_ObereBox =
difference { 
        object { Obere_AchtEck_Box scale<1,0.07,1> translate<0,0.0,0> }                                
        object { Obere_AchtEck_Box scale<0.7,0,0.7> translate<0.06,-0.7,0.05> } 
      }



#declare Optische_Platten_Differenz_ObereBox_4 = 
union {
        object{ Optische_Platten_Differenz_ObereBox scale<1.1, 1, 1.1> translate<0,0,0> }
        object{ Optische_Platten_Differenz_ObereBox scale<1.1, 1, 1.1> translate<0,0.03,0> }
        object{ Optische_Platten_Differenz_ObereBox scale<1.1, 1, 1.1> translate<0,0.06,0> } 
        object{ Optische_Platten_Differenz_ObereBox scale<1.1, 1, 1.1> translate<0,0.09,0> } 
      }                                                      
   
               

// Obere Box mit 8-Ecken und Griffloch
#declare Obere_AchtEck_Box_Mit_Loch =
difference {
             object { Obere_AchtEck_Box }
             object { Sphere translate<0.19,0.75,0.205>} 
             object { Optische_Platten_Differenz_ObereBox_4 scale<1, 1, 1> translate<-0.02,0.6,-0.02> }
           }

    

// Der Griff des Luftfilters auf dem Objekt
#declare Griff = 
object { Round_N_Tube_Polygon (8, 0.015, 0.09, 0.1, 0, 0) 
         texture { finish { phong 1} } // end of texture
         rotate<0,0,0> translate<0,0,0>
       } // end of object -----------------------------------------------------------



// vereinigt die einzelnen vorhandenen Teile zum Luftfilter
#declare Luftfilter =
union {
        object { Standfuss  translate< 0,0,0.001> }
        object { Mittelbox_mit_Knauf }
        object { Obere_AchtEck_Box_Mit_Loch }
        object { Griff translate< 0.19,0.77,0.205>}               
     }



//--------------------------------------------------------------------------
//---------------------------- REGAL in der Szene ----------------------------
//--------------------------------------------------------------------------

// Erzeugt die Seitenplatten des Regals (Oben und Unten)
#declare OberUnterPlatte =
box { <-1.00, 0.00, -0.50>,< 1.00, 0.05, 0.50>   

      texture { T_Grnt5
                 //normal { agate 0.15 scale 0.15}
                   finish { phong 0.5 } 
                   scale 1 
                 } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
    } // end of box --------------------------------------
    


// Erzeugt die Seitenplatten des Regals (Links und Rechts)
#declare SeitenPlatte =
box { <-0.025, 0.00, -0.50>,< 0.025, 1.10, 0.50>   

      texture { T_Grnt5
                 //normal { agate 0.15 scale 0.15}
                   finish { phong 0.5 } 
                   scale 1 
                 } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
    } // end of box --------------------------------------
 


// Erzeugt die hintere Platte des Regals
#declare HinterPlatte =
box { <-1.0, 0.00, -0.025>,< 1.0, 1.10, 0.025>   

      texture { T_Grnt5
                 //normal { agate 0.15 scale 0.15}
                   finish { phong 0.5 } 
                   scale 1 
                 } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
    } // end of box --------------------------------------
    


// Regal wird zusammengesetzt    
declare Regal =
union {
        object { OberUnterPlatte translate<0,1.05,0> }
        object { OberUnterPlatte translate<0,0.05,0> scale<0.95,1,1>}
        object { SeitenPlatte translate<-0.95,0,0> }
        object { SeitenPlatte translate<0.95,0,0> }
        object { HinterPlatte translate<0,0,0.25> }
      }


   
//--------------------------------------------------------------------------
//---------------------------- RAUM in der Szene ----------------------------
//--------------------------------------------------------------------------
// Boden des Raumes     
#declare Boden = 
box { <-3.75, 0.00, -6.50>,< 3.75, 0.001, 6.50>   
      texture { pigment { 
                wood color_map { [0 rgb <.9,.7,.3>][1 rgb <.8,.5,.2>] }
                turbulence .5
                scale <1, 1, 20>
                        }
                finish { specular 1 }
                normal { 
                         gradient x 1
                         slope_map { [0 <0, 1>] // 0 height, strong slope up
                                     [.05 <1, 0>] // maximum height, horizontal
                                     [.95 <1, 0>] // maximum height, horizontal
                                     [1 <0, -1>] // 0 height, strong slope down
                                   }
                       }
              scale<0.3,0.3,0.3>  rotate<0,90,0> }
    } // end of box --------------------------------------



// Seiten Wand des Raumes
#declare Seiten_Wand =
box { <-0.15, 0.00, -6.50>,< 0.15, 3.00, 6.50>   
      texture { pigment{ color rgb<1.00, 1.00, 1.00>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture
    } // end of box --------------------------------------



// Hintere Wand des Raumes
#declare Front_Wand =
box { <-3.75, 0.00, -0.15>,< 3.75, 3.00, 0.15>   
      texture { pigment{ color rgb<1.00, 1.00, 1.00>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

    } // end of box --------------------------------------
    


// Loch in deer Wand f�r die Fenster   
#declare Wall_Hole =
box { <-0.8, 0.00, -0.45>,< 0.8, 1.40, 0.45>   
      texture { pigment{ color rgb<1.00, 1.00, 1.00>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

    } // end of box --------------------------------------
    

 
// Der Raum selber  
#declare Raum =
union {
        object { Boden } 

        difference {    
                     object { Seiten_Wand translate<-3.75,0,0> texture { pigment { color rgb<0.30, 0.30, 0.30>*1.1} } }
                     object { Wall_Hole translate<-3.4,1.2,-2.8> rotate<0,0,0> }
                     object { Wall_Hole translate<-3.4,1.2,1.86> rotate<0,0,0> }
                   }
        
        difference {
                     object { Seiten_Wand translate<3.75,0,0> texture { pigment { color rgb<0.30, 0.30, 0.30>*1.1} } }
                     object { Wall_Hole translate<3.4,1.2,-2.8> rotate<0,0,0> }
                     object { Wall_Hole translate<3.4,1.2,1.86> rotate<0,0,0> }
                   } 
        object { Front_Wand translate<0,0,6.50> texture { pigment{ color rgb<0.30, 0.30, 0.30>*1.1} } }    
      }
 
 
 
//--------------------------------------------------------------------------
//---------------------------- FENSTER in der Szene ----------------------------
//--------------------------------------------------------------------------     
#declare Glass1 =
material {
           texture {pigment {LightBlue filter .95} finish {reflection .4} normal
           {wrinkles .1}}
           interior {ior 1.5}
         }                     
                          

#declare Window = 
object {
         Dbl_Open_Window_1_1 (80,120,  4,5,1,5,1.2,.8,.4,  2,3,texture {T_Wood23
         scale 5},Glass1, 150,30,sphere {<2,0,0>,2}) 
         translate y*-15 
       }



//--------------------------------------------------------------------------
//---------------------------- TEXT in der Szene ----------------------------
//--------------------------------------------------------------------------
#declare textfeld = 
text { ttf "arial.ttf", "Airfilter INC", 0.1, 0.0 // thickness, offset

       texture{ Chrome_Metal
                  // normal { bumps 0.5 scale 0.05 } 
                  // finish { phong 1 }
                } // end of texture ---------------------------

       scale<1,1.25,1>*0.8
       translate<-2.10,0.10,0.00 >
      } // end of text object ---------------------------------------------



// -----------------------------------------------------------------------
// --------------- Das Papier was sich auf den Tischen befindet ---------- 
// -----------------------------------------------------------------------    
#declare paper1 =
box { <-0.00, 0.00, 0.00>,<0.728, 0.512, 0.001>*2   

      texture { pigment { image_map { png "P1.PNG" map_type 0 once } } 
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0>        
    } // end of box -------------------------------------- 


#declare paper2 =
box { <-0.15, 0.00, 0.00>,<0.724, 0.524, 0.001>*2  

      texture { pigment { image_map { png "P2.PNG" map_type 0 once } }  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
    } // end of box --------------------------------------



#declare paper3 =
box {<-0.00, 0.00, 0.00>,<0.724, 0.524, 0.001>*2   
                                                              
      texture { pigment { image_map { png "P3.PNG" map_type 0 once } }  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
    } // end of box --------------------------------------
    



// Das Poster an der Wand    
#declare paper4 =
box {<0, 0.00, 0.00>,<1.28, 0.96, 0.001>   
                                                              
      texture { pigment { image_map { png "R1.PNG" map_type 0 once } }  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
    } // end of box --------------------------------------        
    



// Die LEDs im Schrank
#declare Lichtquelle =
sphere { <0,0,0>, 0.03 

        texture { pigment{ color rgb<1.00, 1.00, 1.00>}
                  finish { phong 1.0 reflection 0.70}
                } // end of texture

          scale<1,1,1>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere ----------------------------------- 


     
// -----------------------------------------------------------------------
// --------------- Anordnen aller vorher erstellter Elemente ------------- 
// ----------------------------------------------------------------------- 
object { Raum }
 
object { Luftfilter rotate<92,10,0> translate< -2.70,1.467,0.30>}
object { Luftfilter rotate<0,5,0> translate<0.3,0.05,5.2>}
object { Luftfilter rotate<0,-10,0> translate<-0.6,0.05,5.2>} 


object { BUEROTISCH2 scale <0.00165,0.00130,0.00165> rotate<0,90,0> translate< -2.70,0,1.30 > }
object { BUEROTISCH2 scale <0.00165,0.00130,0.00165> rotate<0,90,0> translate< -2.70,0,-2.50 > }
object { BUEROTISCH2 scale <0.00165,0.00130,0.00165> rotate<0,90,0> translate< 2.80,0,1.50 > }  // 0.2
object { BUEROTISCH2 scale <0.00165,0.00130,0.00165> rotate<0,90,0> translate< 2.80,0,-3.00 > } // 0.5

object { Screwdriver(0) scale <0.01,0.01,0.01> rotate<90,-60,0> translate< -2.70,1.05,0.80 > }
object { Screwdriver(1) scale <0.02,0.02,0.02> rotate<90,-100,0> translate< -2.70,1.05,1.80 > }
object { Screwdriver(2) scale <0.014,0.014,0.014> rotate<90,10,0> translate< -2.70,1.05,1.50 > }

object { Scie scale <0.013,0.013,0.013> rotate<90,55,0> translate< -2.60,1.07,-2.80> }

object { Mittelbox_mit_abgeschnittenen_ecken rotate<0,30,0> translate< -2.70,0.857,-3.60> }
object { Mittelbox_mit_Ripple rotate<90,45,0> translate< -2.90,1.44,-2.30> }

object { Knauf rotate<23,130,0> translate< -2.90,1.0 ,-1.20> }
object { Knauf rotate<23,190,0> translate< -2.80,1.0 ,-1.30> }
object { Knauf rotate<23,20,0> translate< -2.70,1.0,-1.40> }

object { Griff rotate<90,20,0> translate< -2.50,1.05,1.60> } 
object { Knife scale <0.013,0.013,0.013> rotate<0,20,0> translate< -2.70,1.035,2.60> }
    
object { Lighter scale <0.01,0.01,0.01> }

object { Hat scale <0.4,0.4,0.4> translate< 3.00,0.00,-5.50> }
object { Hat_Rack scale <0.4,0.4,0.4> translate< 3.00,0.00,-5.50> }

object { Window scale<0.012, 0.012, 0.012> rotate<0,180,0> translate< -3.65,1.38,-2.3> }
object { Window scale<0.012, 0.012, 0.012> rotate<0,180,0> translate< -3.65,1.38,2.33> }
object { Window scale<0.012, 0.012, 0.012> rotate<0,0,0> translate< 3.65,1.38,-3.26> }
object { Window scale<0.012, 0.012, 0.012> rotate<0,0,0> translate< 3.65,1.38,1.43> }

object { WindsorChair scale<0.032, 0.032 0.032> rotate<0,90,0> translate<-2,0,1.3> }
object { WindsorChair scale<0.032, 0.032 0.032> rotate<0,90,0> translate<-2,0,-2.7> }
object { WindsorChair scale<0.032, 0.032 0.032> rotate<0,270,0> translate<2,0,1.3> }
object { WindsorChair scale<0.032, 0.032 0.032> rotate<0,270,0> translate<2,0,-2.9> }

object { desk_lamp scale<0.012,0.012,0.012> rotate<0,190,0> translate<-3,1.03,-2.5>}
object { desk_lamp scale<0.012,0.012,0.012> rotate<0,170,0> translate<-3,1.03,2.5>}
object { desk_lamp scale<0.012,0.012,0.012> rotate<0,10,0> translate<3.3,1.03,-2.5>}
object { desk_lamp scale<0.012,0.012,0.012> rotate<0,-10,0> translate<3.3,1.03,2.5>} 


object { pencil rotate<90,30,0> scale<0.05, 0.05, 0.05> translate<3.2,1.05,2.4> }
object { pencil rotate<90,100,0> scale<0.05, 0.05, 0.05> translate<3.2,1.05,-2.51> }
object { pencil rotate<90,20,0> scale<0.05, 0.05, 0.05> translate<3.0,1.05,-3.0> }

object { textfeld translate<0,1.7, 6.3> }                           
                               
object { paper1 scale<0.5,0.5,0.5> rotate<90,20,0> translate<2.8,1.045,0.7> }
object { paper2 scale<0.5,0.5,0.5> rotate<90,10,0> translate<2.7,1.045,-2.5> }
object { paper3 scale<0.5,0.5,0.5> rotate<90,25,0> translate<2.8,1.045,-3.5> }
object { paper4 scale<1,1,1> rotate<0,90,0> translate<-3.6,1.5,0> }

object { Regal translate<0,0,5.6> }

object { Lichtquelle translate<-0.5,0.55,5.5> }
object { Lichtquelle translate<0.5,0.55,5.5> }














