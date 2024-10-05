//========================COPYRIGHT ISSUES============================
//   You can use it without prior asking, but you MUST tell me
//   that you used it (if you publish online, offline,...).
//   You must also mention my name somewhere in the sources...
//   Author: Ferdinand  (Ferdinan@cybercable.fr)
//
//   Vous pouvez utiliser ce modèle sans me le demander mais il
//   serrait aimable de votre part de me prévenir dans le cas
//   contraire (si vous le publiez online, offline, ...).
//   Il serrait sympa aussi de mentionner mon nom quelquepart
//   dans le source.
//   Auteur: Ferdinand (Ferdinan@cybercable.fr)
//====================================================================

//==============================Scie=Handsaw==========================
//   This is a CSG model of a handsaw.
//   The handsaw stands along the X axis, from 0 cm to 43 cm.
//   The handsaw stands along the Y axis, from 0 cm to 12.4 cm.
//   The handsaw stands along the Z axis, from 0 cm to 2 cm.
//====================================================================

#include "colors.inc"
#include "textures.inc"
#include "metals.inc"
#include "woods.inc"

//###########
//###########    EVIDEMENT POIGNEE
//###########    

#local R2=0.5;             // R2: valeur du rayon de tout le pourtour

#local Xc=4.8;             // Xc: demie longueur du cylindre Bord_Gauche
#local fact1=0.3;          // fact1: valeur du facteur d'échelle du petit bord

#local Rx1=0.9;            // Rx1: valeur du grand rayon du tore "ToreCoin_Gauche"

#local R1=2.8;             // R1: valeur du grand rayon du tore "ToreCoin_Droite"
#local Delta=0.95;         // Delta: donne l'arc de tore suplémentaire au 1/4

#local Ry1=5.05;           // Ry1: valeur du grand rayon du tore "Bord_Droite"
#local Deltay=1.9;         // Deltay: donne le demi arc de tore
#local Taton=1.765;        // Comme son nom l'indique pour placer le Bord_Droite à taton
#local fact2=1.08;         // fact2: valeur du facteur d'échelle du bord droite

#local Bord=1;             // Bord: Largeur du bord autour de la forme arrondie

#local Ech=0.3;            // Ech: facteur d'echelle appliqué à "sphere" pour le bombé de la tête

#declare Cylindre =
        cylinder { < R2 , R2 , 0 > , < R2 , R2 , Xc > , R2 }

#declare Bord_Gauche =                         // origine en bas à gauche du prisme (plan x,y) conscrit à l'objet Bord_Gauche
            #union {    
                object { Cylindre
                   translate < 0,2*R2,0 >
                       }
                object { Cylindre }
                box { < 0,R2,0 >,< 2*R2,3*R2,Xc> }
                   }

#declare ToreCoin_Gauche=
  #difference {
    #union {
        #intersection {
            torus { Rx1 , R2 }                                   // Tracé du torre
            box { < -(Rx1+R2), -R2, -(Rx1+R2) >,< 0, R2, 0 > }   // On ne garde que le 1/4 inf.gauche          
                      }
        #intersection {
            box { < -(Rx1+R2), 0, -(Rx1+R2) >,< 0, R2, 0 > }     // Pour combler le vide
            cylinder { < 0, 0, 0 >,< 0, R2, 0 >,Rx1+R2 }
                      }                     
           }
    cylinder { < 0, -0.01, 0 >,< 0, R2+0.01, 0 >,Rx1-R2 }
              }

#declare Coin_Gauche =
   #union {
     object { ToreCoin_Gauche
        translate < 0,-R2+0.001,0 >
            }
     object { ToreCoin_Gauche
        translate < 0,-R2+0.001,0 >            // pour avoir la partie supérieure à 0, (+0.001 pour éviter les résidus)
        scale < 1,-1,1 >                       // Symétrie par rapport au plan X, Z
            }
     translate < (Rx1+R2) , 2*R2 , (Rx1+R2) >  // origine en bas à gauche du prisme (plan x,y) conscrit à l'objet Coin_Gauche
          }

#declare ToreCoin_Droite =
  #difference {
    #union {
        #intersection {
            torus { R1 , R2 }                                          // Tracé du torre
            box { < 0, -R2, -(R1+R2) >,< (R1+R2), R2, Delta > }        // on ne garde que le 1/4 inf.droit 
                     }
        #intersection {       
            cylinder { < 0, 0, 0 >,< 0, R2, 0 >,(R1+R2) }              // Pour combler le vide entre les 2 torres
            box { < 0, -0.01, -(R1+R2) >,< (R1+R2), R2+0.01, Delta > }
                   }                     
           }
     cylinder { < 0, -0.01, 0 >,< 0, R2+0.01, 0 >,R1-R2 }
              }
#declare Coin_Droite =
   #union {
     object { ToreCoin_Droite
        translate < 0,-R2+0.001,0 >
            }
     object { ToreCoin_Droite
        translate < 0,-R2+0.001,0 >      // pour avoir la partie supérieure à 0, (+0.001 pour éviter les résidus)
        scale < 1,-1,1 >                 // Symétrie par rapport au plan X, Z
            }
     translate < 0 , 2*R2 , (R1+R2) >    // origine en bas à gauche du prisme (plan x,y) conscrit à l'objet Coin_Droite
          }

#declare Tore_Droite =
  #difference {
    #union {
        #intersection {
            torus { Ry1 , R2 }
            box { < -(Ry1+R2), -R2, -Deltay >,< 0, R2, 0 > }
                     }
        #intersection {        
            box { < -(Ry1+R2), 0, -Deltay >,< 0, R2, 0 > }
            cylinder { < 0, -0.01 ,0 >,< 0, R2+0.01, 0 >,Ry1+R2 }                     
                   }
           }
    cylinder { < 0, -0.01 ,0 >,< 0, R2+0.01, 0 >,Ry1-R2 }
                }
#declare Bord_Droite =
   #union {
     object { Tore_Droite
        translate < 0,-R2+0.001,0 >
            }
     object { Tore_Droite
        translate < 0,-R2+0.001,0 >         // pour avoir la partie supérieure à 0, (+0.001 pour éviter les résidus)
        scale < 1,-1,1 >                    // Symétrie par rapport au plan X, Z
            }
     translate < (Ry1+R2) , 2*R2 , Deltay > // origine en bas à gauche du prisme (plan x,y) conscrit à l'objet Bord_Droite
          }

#declare Demi_Retrait0 =
  #union {                                              // début: "Demi_Retrait1"
     object { Bord_Gauche
        translate < 0, 0, (Rx1+R2)-0.01 >
            }

     object { Bord_Gauche                               // début: Bord_Bas
        rotate 90*y 
        scale < fact1,1,1 >
        translate < (Rx1+R2)-0.01 ,0 ,2*R2 >            // -0.01 pour qu'il n'y ait pas de discontinuité
            }                                           // fin: Bord_Bas

     object { Coin_Gauche
            }

     object { Coin_Droite
        translate < (Rx1+R2)+fact1*Xc-0.02, 0, 0 >      // -0.02 pour qu'il n'y ait pas de discontinuité
            }

     object { Bord_Droite                               // début: Bord_Droite
        scale < 1,1,fact2 >
        translate < (Rx1+R2)+fact1*Xc+Taton-0.02, 0 , (R1+R2+Delta)-0.01 >
            }                                           // fin: Bord_Droite

//++++++++++++++++++++++++++++++++++++++//
//     Afin d'avoir un volume plein     //
//++++++++++++++++++++++++++++++++++++++//

     box { < -Bord, 0, (Rx1+R2)-0.01 >,< R2, 4*R2, (Rx1+R2)+Xc+0.01 > }         // Bord_Gauche
     box { < (Rx1+R2)-0.01, 0, R2 >,< (Rx1+R2)+fact1*Xc-0.01, 4*R2, -Bord > }   // Bord_Bas
     #intersection {                                                            // début: Coin_Gauche
        #difference {
          cylinder { < 0, -2*R2, 0 >,< 0, 2*R2, 0 >,(Rx1+R2)+Bord }
          cylinder { < 0, -2*R2-0.01, 0 >,< 0, 2*R2+0.01, 0 >,Rx1 }
                    }
        box { < -(Rx1+R2)-Bord, -2*R2-0.01, -(Rx1+R2)-Bord >,< 0, 2*R2+0.01, 0 > }
        translate < (Rx1+R2) , 2*R2 , (Rx1+R2) >
                   }                                                            // fin: Coin_Gauche
     #intersection {                                                            // début: Coin_Droite
        #difference {
          cylinder { < 0, -2*R2, 0 >,< 0, 2*R2, 0 >,(R1+R2)+Bord }
          cylinder { < 0, -2*R2-0.01, 0 >,< 0, 2*R2+0.01, 0 >,R1 }
                    }
        box { < 0, -2*R2-0.01, -(R1+R2)-Bord >,< (R1+R2)+Bord, 2*R2+0.01, Delta > }
        translate < (Rx1+R2)+fact1*Xc-0.02 , 2*R2 , (R1+R2) >
                   }                                                            // fin: Coin_Droite
     #intersection {                                                            // début: Bord_Droite
        #difference {                                                              
          cylinder { < 0, -2*R2, 0 >,< 0, 2*R2, 0 >,(Ry1+R2) }
          cylinder { < 0, -2*R2-0.01, 0 >,< 0, 2*R2+0.01, 0 >,(Ry1-Bord) }
                    }
        box { < -(Ry1+R2), -2*R2-0.01, -Deltay >,< 0, 2*R2+0.01, 0 > }
        translate < (Rx1+R2)+fact1*Xc+Taton-0.02+(Ry1+R2)+R2, 2*R2 , (R1+R2+Delta)+Deltay >                 
                   }                                                            // fin: Bord_Droite  
         }                                              // fin: "Demi_Retrait1"

#declare Demi_Retrait1 =
   #difference {
       object { Demi_Retrait0
       translate < 0, 0, -((Rx1+R2)+Xc-0.01) >
              }
       box { < -Bord, -0.01, -0.01 >,< (Rx1+R2)+fact1*Xc+(R1+R2)+Bord, 4*R2+0.01, (Rx1+R2)+Xc > }
       translate < 0, 0, 0.02 >
               }
#declare Retrait1 =
   #intersection {
      #union {
         object { Demi_Retrait1 }
         object { Demi_Retrait1 scale < 1,1,-1 > }     // Symétrie par rapport au plan X, y
         translate < 0, 0, ((Rx1+R2)+Xc-0.01) >            
         rotate -90*x
         translate < 0, 0, 4*R2 >                      // afin d'avoir l'origine en bas à gauche du prisme (vue plan x,y) conscrit à l'objet              
             }
      box { < 0, 0, -0.01 >,< (Rx1+R2)+fact1*Xc+(R1+R2), ((Rx1+R2)+Xc)*2, 4*R2+0.01 > }
                 }

#declare Retrait2 =
   #difference {
      box { < R2, R2, 0.01 >,< Rx1+fact1*Xc+(R1+R2), (Rx1+R2+Xc)*2-0.1, 4*R2-0.01 > }
      object { Retrait1 }
      translate < -R2, -R2, 0 >                        // afin d'avoir l'origine en bas à gauche du prisme (vue plan x,y) conscrit à l'objet      
               }

//###########
//###########    LAME
//###########

#local Angle = atan2 ( 9/38.5 , 1 );    // Angle en radian
#local XLong = 38.5/cos (Angle);        // Angle est en radian, OK pour cos. HLong=longueur de la lame
#local NbDent = int(XLong/0.4);         // NbDent = nombre de dent
#local X = 0;

#declare Dent =                 // début "dent"
    prism {                     // début prism
        linear_sweep                    // extrusion normale le long de l'axe Z
        linear_spline                   //
        0.11,                           // extrémité sur -Z
        0,                              // base sur -Z
        4                               // Nombre total de points
        <0,0>, <0.3,0.2>, <0.4,0>, <0,0>
        rotate x*-90                    // correction de l'orientation du prisme (-90) 
          }                     // fin de prism, "dent"

#declare Lame =
#difference {                   // début de "lame de scie"
    prism {                     // début "lame nue"
        linear_sweep                    // extrusion normale le long de l'axe Z
        linear_spline                   // les cotés du prism sont plans
        0.1,                            // extrémité sur -Z
        0.01,                           // base sur -Z
        7                               // Nombre total de points
        <0.08,0>, <35,0>, <35,-7>, <39,-12>, <0.5,-3>, <0.02,-0.05>, <0.08,0>
        texture {T_Chrome_4D}
        rotate x*-90                    // correction de l'orientation du prisme (-90)
        translate <-0.5,3,0>            // l'angle en bas à gauche de la lame est en <0,0,0>
        rotate z*degrees(Angle)         // rotation de Angle converti en degré
          }                     // fin de "lame nue"

    #union {                    // début de CSG
        #while (NbDent != 0)
            object { Dent
                translate < X , -0.01 , 0 >
                   }
            #local X = X+0.4;
            #local NbDent = NbDent-1;
        #end                                         
        cylinder { <0,0,0>,<0,0,-0.11>,0.5
            translate <1.2,1.8,0>
                 }
           }                    // fin de CSG
    rotate z*degrees(-Angle)            // rotation de Angle converti en degré
    translate < 0.5, 9, 0.1 >           // le point en bas à gauche du rectangle conscrit à la lame est en <0,0,0>
            }                   // fin de "lame de scie"

//###########
//###########    POIGNEE
//###########

#declare Trou_Borgne = cylinder { <0,0,0>,<0,0,1>,0.6 }

#declare Brut =
   #difference {                // début "poignée"                               
      box { < -11, 5.01, -0.98 >,< 3, 17.4, 0.98 > }         // poignée brute, dim: 14x12.4x1.98

      #difference {             // début "retA"  
           box { < 0, 5,-1.1>,< 5,17.5,1.1> }
           lathe {                     
              cubic_spline                      // le bord de l'objet de révolution est arrondi
              11                                // Nombre total de points
              <0,17.8>, <0,0>, <1.5,2>, <0.5,4>, <2.5,8>, <1,15.5>,
              <2.1,17>, <0.1,17.5>, <0,17.8>, <0,0>, <1.5,2>        
                }
                  }             // fin de "retA"                     
      #difference {             // début "retB"
             box { < -11, 5, -1.1 >,< 3, 17.49, 1.1 > }
             cylinder { < -5.5, 24.2, 1.2 >,< -5.5, 24.2, -1.2 >,19 }                               
                  }             // fin de "retB"
      prism {                   // début "chanfrein"
                linear_sweep                    // extrusion normale le long de l'axe Z
                linear_spline                   // les cotés du prism sont plans
                2.1,                            // extrémité sur -Z
                0,                              // origine sur -Z
                4                               // Nombre total de points
                <0,-0.1>, <5,-0.1>, <0,5>, <0,-0.1>
                rotate x*-90                    // correction de l'orientation du prisme (-90)
                translate <-11.01,5.01,1.05>
            }                   // fin de "chanfrein"
      translate < 11, -5.01, 1 >    // afin d'avoir l'origine en bas à gauche du prisme (vue plan x,y) conscrit à l'objet                     
               }                // fin de "poignée"

#declare Tete_Vis =
#union {
   #difference {                    
      sphere { < 0,0,0 >,0.5 
        scale < 1,1,Ech >
             }
      box { < -0.51, -0.1, 0 >, < 0.51, 0.1, -0.5*Ech > }
               }
   cylinder { < 0,0,0 >, < 0,0,0.3 >, 0.5 }
   translate < 0,0,0.5*Ech >
   texture { Chrome_Metal}
       }

#declare Poignee =
#union {
   #difference {
      object { Brut } 
      object { Trou_Borgne
         translate < 1, 9.5, 0 >
             }
      object { Trou_Borgne
         translate < 1, 5.5, 0 >
             }           
      object { Trou_Borgne
         translate < 4, 3, 0 >
             }
      object { Retrait2
         rotate 14*z
         translate < 6, 0, 0 >
             }
      texture {T_Wood7 scale 3}
               }
   object { Tete_Vis
      rotate < 0,0,60 >
      translate < 1, 9.5, 0 >
          }
   object { Tete_Vis
      rotate < 0,0,115 >
      translate < 1, 5.5, 0 >
          }
   object { Tete_Vis
      rotate < 0,0,20 >
      translate < 4, 3, 0 >
          }
   translate < 34, 0, -1 >
       }

declare Scie =
   #union {
      object { Lame }
      object { Poignee }
          }