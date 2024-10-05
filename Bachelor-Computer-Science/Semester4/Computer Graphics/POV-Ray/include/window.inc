#include "colors.inc"
#include "woods.inc"         
//#include "mestex.inc"
//preliminary macro

#macro Cadre (Haut,Larg,Epaiss,Prof,Tex1) //tout en positif a partir de 0
 union {
 box {<0,0,0>,<Prof,Haut,Epaiss> texture {Tex1 rotate x*90}}
 box {<0,0,Larg>,<Prof,Haut,Larg-Epaiss> texture {Tex1 rotate x*90}}
 box {<0,0,Epaiss>,<Prof,Epaiss,Larg-Epaiss> texture {Tex1}}
 box {<0,Haut,Epaiss>,<Prof,Haut-Epaiss,Larg-Epaiss> texture {Tex1}}
 }
#end 

//====================================================================================================
//      the window macro itself
//====================================================================================================
   
#macro Dbl_Open_Window_1_1 (Bay_W,Bay_H,A,B,C,D,E,F,G,NbGlassW,NbGlassH,FenTex,GlassTex,LeftAngle,RightAngle,Handle)
union {
#declare X=((D/2)-C);  

#declare Ouvrant=union {   
object {Cadre (
                Bay_H-(2*A),
                (Bay_W-(2*A)-X)/2,
                B,
                -X,
                texture {FenTex}
                )
                }
object {Cadre (
              Bay_H-(2*A)-(2*X),
              ((Bay_W-(2*A)-X)/2)-(2*X),
              B-X,
              -X,
              texture {FenTex} 
              ) translate <-X,X,X>
              }

#declare Width_internal_frame=((Bay_W-(2*A)-X)/2)-(2*B);
#declare Height_internal_frame=Bay_H-(2*A)-(2*B);
#declare Profil1=prism {linear_spline 0,1,4,<0,0>,<-X+G,0>,<0,F>,<0,0>
pigment {Wheat}}

#declare BaguetteV=union {
 box {<0,0,0>,<E,Height_internal_frame,F> texture {FenTex rotate x*90}}
 object {Profil1 scale <1,Height_internal_frame,1> translate x*-G}
                          }
#declare BaguetteH=union {
 box {<0,0,0>,<E,Width_internal_frame,F> texture {FenTex rotate x*90}}
 object {Profil1 scale <1,Width_internal_frame,1> translate x*-G}
 rotate x*-90 translate z*Width_internal_frame
                          }

box {<-X,B,B>,<-X-G,Height_internal_frame+B,B+Width_internal_frame>
material {GlassTex}}

object {BaguetteV translate <-X,B,B>}
object {BaguetteV scale <1,1,-1> translate <-X,B,((Bay_W-(2*A)-X)/2)-B>}
object {BaguetteH translate <-X,B,B>}
object {BaguetteH scale <1,-1,1> translate
<-X,B+Height_internal_frame,B>}

#declare SeparV=union {
 box {<E,0,F/2>,<-X,Height_internal_frame,-F/2> texture {FenTex rotate
x*90}}
 object {BaguetteV translate <0,0,F/2>}
 object {BaguetteV scale <1,1,-1> translate <0,0,-F/2>}
}    

#declare SeparH=union {
 box {<E,F/2,0>,<-X,-F/2,Width_internal_frame> texture {FenTex}}
 object {BaguetteH translate <0,F/2,0>}
 object {BaguetteH scale <1,-1,1> translate <0,-F/2,0>}
 
}

#declare Boucle=1;
#while (Boucle < NbGlassW)                
 #declare Step=Width_internal_frame/NbGlassW;
 object {SeparV translate <-X,B,B+(Boucle*Step)>}
 #declare Boucle=Boucle+1;
 #end
 
#declare Boucle=1;
#while (Boucle < NbGlassH)
 #declare Step=Height_internal_frame/NbGlassH;
 object {SeparH translate <-X,B+(Boucle*Step),B>}
 #declare Boucle=Boucle+1;
 #end

}//fin de Ouvrant

#declare Ouvrant_Left=union {
 object {Ouvrant}
 box
{<-X,X,B+Width_internal_frame+B-X>,<-2*X,B+Height_internal_frame+B-X,B+Width_internal_frame+B+X>
texture {FenTex rotate x*90}}
 rotate y*LeftAngle
}

#declare Ouvrant_Right=union {
 object {Ouvrant}
 box
{<-X,X,B+Width_internal_frame+B-X>,<-2*X,B+Height_internal_frame+B-X,B+Width_internal_frame+B>
texture {FenTex rotate x*90}}
 box
{<-X,X,B+Width_internal_frame+B-X>,<0,B+Height_internal_frame+B,B+Width_internal_frame+B+X>
texture {FenTex rotate x*90}}
 box
{<C,0,B+Width_internal_frame+B-X>,<0,B+Height_internal_frame+B,B+Width_internal_frame+B+X>
texture {FenTex rotate x*90}}
 object {Handle translate
<C,B+(Height_internal_frame/2),B+Width_internal_frame+B>}
 scale <1,1,-1>
 rotate y*-RightAngle
}



 object {Cadre (Bay_H,Bay_W,A,-D/2,FenTex)}
 object {Cadre (Bay_H,Bay_W,A+X,-D/2,FenTex) translate x*-D/2}
 object {Ouvrant_Left translate <-C,A,A>}
 object {Ouvrant_Right translate <-C,A,Bay_W-A>}       

union {
cylinder {<-C/2,0,(A+C/2)>,<-C/2,B,(A+C/2)>,C/2 translate y*(A+B)
pigment {Gray50}}
cylinder {<-C/2,0,(A+C/2)>,<-C/2,B,(A+C/2)>,C/2 translate y*(Bay_H/2)
pigment {Gray50}}
cylinder {<-C/2,0,(A+C/2)>,<-C/2,B,(A+C/2)>,C/2 translate
y*(Bay_H-(A+B)) pigment {Gray50}}
}
union {
cylinder {<-C/2,0,(A+C/2)>,<-C/2,B,(A+C/2)>,C/2 translate y*(A+B)
pigment {Gray50}}
cylinder {<-C/2,0,(A+C/2)>,<-C/2,B,(A+C/2)>,C/2 translate y*(Bay_H/2)
pigment {Gray50}}
cylinder {<-C/2,0,(A+C/2)>,<-C/2,B,(A+C/2)>,C/2 translate
y*(Bay_H-(A+B)) pigment {Gray50}}
scale <1,1,-1> translate z*Bay_W
}

  
 }//fin de l'union de la macro
#end //
        //MACRO ENDS HERE