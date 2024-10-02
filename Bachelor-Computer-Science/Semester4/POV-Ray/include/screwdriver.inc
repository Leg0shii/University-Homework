/////////////////////////////////////////////
// screwdriver.pov
// Dan Connelly
// djconnel@flash.net
// 23 Sep 1998
//
// units are all in centimeters
//
// #declare IncludeFlag=1 before including this file
// to suppress rendering
//

#version 3.1;

#ifndef (RenderFlag)
  #local RenderFlag = 1;
#end
#ifdef (IncludeFlag)
#if (IncludeFlag)
  #local RenderFlag = 0;
#end
#end

#local Inch = 2.54;

/////////////////////////////////////////////
// texture definitions
//

#declare Steel_Texture  =
  texture {
    pigment { color rgb 0.6 }
      finish {
      metallic
      ambient 0.4
      diffuse 0.6
      specular 0.6
      roughness 0.01
      brilliance 2
    }
    normal {
      average
      normal_map {
       [1 granite 0.04]
       [1 dents 0.1]
      }
      scale 0.5
    }
  }
      
    
#declare Steel_Dirt_Texture =
  texture {
    pigment { 
      bozo
      turbulence 0.1
      scale 0.75
      color_map {
        [0    rgbt <0.510,0.482,0.435,0.5>]
        [0.25 rgbt <0.510,0.482,0.435,1>] 
      }
    }
    finish { diffuse 0.5 ambient 0.5 }
      normal {
      average
      normal_map {
        [1 granite 0.4 scale 0.05]
        [1 dents 0.1]
      }
    }
  }
   
#declare Dirty_Steel_Texture =
  texture { Steel_Texture }
  texture { Steel_Dirt_Texture }

#declare ToolHandle_Texture_Orange =
  texture {
    pigment {
      color rgbt <0.988,0.565,0.000,0.5>
    }
    finish {
      ambient 0.5
      diffuse 0.5
      specular 0.5
      roughness 0.01
    }
    normal {
      granite 0.005
    }
  }

#declare ToolHandle_Material_Orange =
  material {
    texture { ToolHandle_Texture_Orange }
    interior { ior 1.2 }
  }

////////////////////////////////////////////
// parameter definitions
//

#declare ScrewdriverHandle_R0 = Inch/2;       // outer radius of handle
#declare ScrewdriverHandle_R1 = Inch/16;      // depth of handle cutouts
#declare ScrewdriverHandle_R4 = Inch/8;       // depth of lower handle cutout
#declare ScrewdriverHandle_R5 = 0.45 * Inch;  // half-height of lower handle cutoff
#declare ScrewdriverHandle_L  = 9;            // metal piece exposed length
#declare ScrewdriverHandle_T1 = 40;           // degrees of handle cutouts
#declare Screwdriver_R        = 0.25;         // metal piece radius
#declare Screwdriver_L        = 9;            // metal piece radius
#declare ScrewdriverTip_L     = 1.5;          // length of beveled tip
#declare ScrewdriverTip_X     = 0.1;          // half-thickness at beveled tip

/////////////////////////////////////////////
// screwdriver
// this macro defines two objects : 
// a standard scredriver and a phillips head.
// The latter is requested via a flag.
//


#macro Screwdriver(PhillipsFlag)
  #local A  = ScrewdriverHandle_R0 / ScrewdriverHandle_R1;
  #local R2 = (1 + pow(A * sin(radians(ScrewdriverHandle_T1 / 2)), 2)) * ScrewdriverHandle_R1;
  #local R3 = R2 + ScrewdriverHandle_R0 - ScrewdriverHandle_R1;
  #local R6 = (pow(ScrewdriverHandle_R5, 2) + pow(ScrewdriverHandle_R4, 2)) / (2 * ScrewdriverHandle_R4);
  #local R7 = R6 + ScrewdriverHandle_R0 - ScrewdriverHandle_R1 - ScrewdriverHandle_R4;
  union {
    difference {
      superellipsoid {
        <1, 0.3>
        rotate 90 * x
        translate y
        scale <ScrewdriverHandle_R0, ScrewdriverHandle_L / 2, ScrewdriverHandle_R0>
      }
      #local N = 0;
      #while (N < 6)
        cylinder {
          <R3, 0, 0>,
          <R3, ScrewdriverHandle_L, 0>,
          R2
          rotate 60 * N * y
        }
        #declare N = N + 1;
      #end
      torus {
        R7, R6
        translate 0.98 * ScrewdriverHandle_R4 * y
      }
      material { ToolHandle_Material_Orange }
    } 
    difference {
      union {
        cylinder {
          0,
          ScrewdriverHandle_L / 2 * y
          Screwdriver_R
        }
        cylinder {
          0,
          -Screwdriver_L * y
          Screwdriver_R
        }
      }
      #local X = Screwdriver_R - ScrewdriverTip_X;
      union {
        #if (PhillipsFlag)
          #local N = 0;
          #while (N < 4)
            sphere {
              0,
              1
              scale <Screwdriver_R, ScrewdriverTip_L , Screwdriver_R>
              translate <Screwdriver_R, 0, Screwdriver_R>
              rotate 90 * N * y
            }
            #declare N = N + 1;
          #end
          cone {
            0,
            ScrewdriverTip_X / 2,
            <0, 1.1 * Screwdriver_L, 0>
            Screwdriver_L / 2
            inverse
          }
        #else
          #local R = (pow(X, 2) + pow(ScrewdriverTip_L, 2)) / (2 * X);
          #local X0 = ScrewdriverTip_X + R;
          cylinder {
            <X0, 0, -Screwdriver_R>,
            <X0, 0, Screwdriver_R>,
            R
          }
          cylinder {
            <-X0, 0, -Screwdriver_R>,
            <-X0, 0, Screwdriver_R>,
            R
          }
        #end

        translate -Screwdriver_L * y
      }
      texture { Dirty_Steel_Texture }
    }
       
  }
#end