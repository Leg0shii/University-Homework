// Persistence of Vision Ray Tracer Scene Description File
// File: ws_chair.pov
// Vers: 3
// Desc: Basic Scene Example
// Date: 08/01/97
// Auth: Lance Purple

// This file is hereby placed in the public domain

#version 3

#include "COLORS.INC"
#include "WOODMAPS.INC"
#include "WOODS.INC"

#declare INCHES = 1.0
#declare FEET   = 12*INCHES

// ----------------------------------------

#declare chair_wood_z    = texture { T_Wood13 finish { phong 0.8 } }
#declare chair_wood_y    = texture { chair_wood_z rotate 90*x }
#declare chair_wood_x    = texture { chair_wood_z rotate 90*y }

// Windsor chair

#declare WindsorChair = union {

  // left front leg
  intersection {
    sphere { < 0, 0, 0 > 1
             scale < 11/16*INCHES, 16*INCHES, 11/16*INCHES>
             texture { chair_wood_y }
             rotate 14*x
             rotate -9*z
           }
    box    { < -4*INCHES, -8.0*INCHES, -3*INCHES >
             <  4*INCHES,  8.4*INCHES,  3*INCHES > }
    translate <-7*INCHES, 8*INCHES, -(6+3/4)*INCHES>
  }

  // right front leg
  intersection {
    sphere { < 0, 0, 0 > 1
             scale < 11/16*INCHES, 16*INCHES, 11/16*INCHES>
             texture { chair_wood_y }
             rotate 14*x
             rotate  9*z
           }
    box    { < -4*INCHES, -8.0*INCHES, -3*INCHES >
             <  4*INCHES,  8.4*INCHES,  3*INCHES > }
    translate < 7*INCHES, 8*INCHES, -(6+3/4)*INCHES>
  }

  // left back leg
  intersection {
    sphere { < 0, 0, 0 > 1
             scale < 11/16*INCHES, 16*INCHES, 11/16*INCHES>
             texture { chair_wood_y }
             rotate -17*x
             rotate -17*z
           }
    box    { < -3*INCHES, -8.0*INCHES, -3*INCHES >
             <  3*INCHES,  7.5*INCHES,  3*INCHES > }
    translate <-7*INCHES, 8*INCHES, (7+1/4)*INCHES>
  }

  // right back leg
  intersection {
    sphere { < 0, 0, 0 > 1
             scale < 11/16*INCHES, 16*INCHES, 11/16*INCHES>
             texture { chair_wood_y }
             rotate -17*x
             rotate  17*z
           }
    box    { < -3*INCHES, -8.0*INCHES, -3*INCHES >
             <  3*INCHES,  7.5*INCHES,  3*INCHES > }
    translate <7*INCHES, 8*INCHES, (7+1/4)*INCHES>
  }

  // left outer leg crossbar
  union {
    cone      { < -7*INCHES, 0, -(6+3/4)*INCHES > (3/16)*INCHES
                < -7*INCHES, 0, -(4+3/4)*INCHES > (1/ 2)*INCHES }
    cylinder  { < -7*INCHES, 0, -(4+3/4)*INCHES >
                < -7*INCHES, 0,  (5+1/4)*INCHES > (1/ 2)*INCHES }
    cone      { < -7*INCHES, 0,  (5+1/4)*INCHES > (1/ 2)*INCHES
                < -7*INCHES, 0,  (7+1/4)*INCHES > (3/16)*INCHES }
    texture   { chair_wood_z }
    translate 8*INCHES*y
  }

  // right outer leg crossbar
  union {
    cone      { <  7*INCHES, 0, -(6+3/4)*INCHES > (3/16)*INCHES
                <  7*INCHES, 0, -(4+3/4)*INCHES > (1/ 2)*INCHES }
    cylinder  { <  7*INCHES, 0, -(4+3/4)*INCHES >
                <  7*INCHES, 0,  (5+1/4)*INCHES > (1/ 2)*INCHES }
    cone      { <  7*INCHES, 0,  (5+1/4)*INCHES > (1/ 2)*INCHES
                <  7*INCHES, 0,  (7+1/4)*INCHES > (3/16)*INCHES }
    texture   { chair_wood_z }
    translate 8*INCHES*y
  }

  // front inner leg crossbar
  union {
    cone      { < -7*INCHES, 0, -(2+1/4)*INCHES > (3/16)*INCHES
                < -5*INCHES, 0, -(2+1/4)*INCHES > (1/ 2)*INCHES }
    cylinder  { < -5*INCHES, 0, -(2+1/4)*INCHES >
                <  5*INCHES, 0, -(2+1/4)*INCHES > (1/2)*INCHES }
    cone      { <  5*INCHES, 0, -(2+1/4)*INCHES > (1/ 2)*INCHES
                <  7*INCHES, 0, -(2+1/4)*INCHES > (3/16)*INCHES }
    texture   { chair_wood_x }
    translate 8*INCHES*y
  }

  // back inner leg crossbar
  union {
    cone      { < -7*INCHES, 0, (2+1/4)*INCHES > (3/16)*INCHES
                < -5*INCHES, 0, (2+1/4)*INCHES > (1/ 2)*INCHES }
    cylinder  { < -5*INCHES, 0, (2+1/4)*INCHES >
                <  5*INCHES, 0, (2+1/4)*INCHES > (1/2)*INCHES }
    cone      { <  5*INCHES, 0, (2+1/4)*INCHES > (1/ 2)*INCHES
                <  7*INCHES, 0, (2+1/4)*INCHES > (3/16)*INCHES }
    texture   { chair_wood_x }
    translate 8*INCHES*y
  }

  // seat
  difference {
    union {
      intersection {
        prism { linear_sweep cubic_spline
               -(1/2)*INCHES, (1/2)*INCHES,
               15,
               <        5*INCHES,       -8*INCHES >,
               <        0*INCHES, -(8+1/2)*INCHES >,
               <       -5*INCHES,       -8*INCHES >,
               < -(7+7/8)*INCHES,       -5*INCHES >,
               < -(8+5/8)*INCHES,    (1/2)*INCHES >,
               < -(8+1/2)*INCHES,  (3+1/2)*INCHES >,
               < -(6+5/8)*INCHES,  (6+5/8)*INCHES >,
               <        0*INCHES,  (9+1/4)*INCHES >,
               <  (6+5/8)*INCHES,  (6+5/8)*INCHES >,
               <  (8+1/2)*INCHES,  (3+1/2)*INCHES >,
               <  (8+5/8)*INCHES,    (1/2)*INCHES >,
               <  (7+7/8)*INCHES,       -5*INCHES >,
               <        5*INCHES,       -8*INCHES >,
               <        0*INCHES, -(8+1/2)*INCHES >,
               <       -5*INCHES,       -8*INCHES >
        }
        box   { < -9*INCHES, -3/4*INCHES,       -9*INCHES >
                <  9*INCHES,  3/4*INCHES,  (3+1/2)*INCHES >
        }
      }
      intersection {
        cylinder { < 0, -1/2*INCHES, 0 >
                   < 0,  1/2*INCHES, 0 > (9+3/8)*INCHES }
        box      { < -9*INCHES, -3/4*INCHES,  (3+1/2)*INCHES >
                   <  9*INCHES,  3/4*INCHES,        9*INCHES >
        }
      }
    }
    sphere   { < 0, (71+7/8)*INCHES, 0 > (72+1/8)*INCHES }
    texture  { chair_wood_z }
    rotate 5*x
    translate < 0, 16*INCHES, 0 >
  }

  // chair back rail

  union {
    difference {
      cylinder { <0, 11*INCHES, -(1/2)*INCHES>
                 <0, 11*INCHES,  (1/2)*INCHES> (9+1/4)*INCHES }
      cylinder { <0, 11*INCHES, -(5/8)*INCHES>
                 <0, 11*INCHES,  (5/8)*INCHES> (8+1/4)*INCHES }
      box      { <-10*INCHES,  (8+1/2)*INCHES, -1*INCHES>
                 < 10*INCHES,        0*INCHES,  1*INCHES> }
      texture { chair_wood_z translate 11*INCHES*y }
    }
    box { <-(1/2)*INCHES,    0*INCHES, -(1/2)*INCHES >
          < (1/2)*INCHES, -9.5*INCHES,  (1/2)*INCHES >
          texture { chair_wood_y }
          rotate  18*z     translate <-(8+2/4)*INCHES, (8+3/4)*INCHES, 0 >
    }
    box { <-(1/2)*INCHES,    0*INCHES, -(1/2)*INCHES >
          < (1/2)*INCHES, -9.5*INCHES,  (1/2)*INCHES >
          texture { chair_wood_y }
          rotate -18*z     translate < (8+2/4)*INCHES, (8+3/4)*INCHES, 0 >
    }

    rotate 20*x
    translate <0, 15*INCHES, (3+1/2)*INCHES>
  }

  // chair back rungs
  #declare rung_1_base = < -6.00*INCHES, 15.99*INCHES, 5.85*INCHES >
  #declare rung_2_base = < -4.50*INCHES, 15.90*INCHES, 6.85*INCHES >
  #declare rung_3_base = < -2.75*INCHES, 15.84*INCHES, 7.60*INCHES >
  #declare rung_4_base = < -0.88*INCHES, 15.80*INCHES, 7.97*INCHES >
  #declare rung_5_base = <  0.88*INCHES, 15.80*INCHES, 7.97*INCHES >
  #declare rung_6_base = <  2.75*INCHES, 15.84*INCHES, 7.60*INCHES >
  #declare rung_7_base = <  4.50*INCHES, 15.90*INCHES, 6.85*INCHES >
  #declare rung_8_base = <  6.00*INCHES, 15.99*INCHES, 5.85*INCHES >

  cylinder { <0, 0, 0> <0, 14.5*INCHES, 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate  12.26*x
             rotate   5.80*z
             translate rung_1_base }

  cylinder { <0, 0, 0> <0, (16.5*INCHES), 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate   9.60*x
             rotate   3.68*z
             translate rung_2_base }

  cylinder { <0, 0, 0> <0, (17.5*INCHES), 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate   7.84*x
             rotate   2.15*z
             translate rung_3_base }

  cylinder { <0, 0, 0> <0, (18.0*INCHES), 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate   7.16*x
             rotate   0.82*z
             translate rung_4_base }

  cylinder { <0, 0, 0> <0, (18.0*INCHES), 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate   7.16*x
             rotate  -0.82*z
             translate rung_5_base }

  cylinder { <0, 0, 0> <0, (17.5*INCHES), 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate   7.84*x
             rotate  -2.15*z
             translate rung_6_base }

  cylinder { <0, 0, 0> <0, (16.5*INCHES), 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate   9.60*x
             rotate  -3.68*z
             translate rung_7_base }

  cylinder { <0, 0, 0> <0, 14.5*INCHES, 0> (1/4*INCHES)
             texture { chair_wood_y }
             rotate  12.26*x
             rotate  -5.80*z
             translate rung_8_base }

  pigment { color Black } // shouldn't be used
 
}