////////////////////////////////////////////////////////////
// Persistence of Vision Ray Tracer Scene Description File
// File:        knife.inc
// Version:     3.5
// Description: Include file for the knife definition
// Date:        2002
// Author:      Bonsai <bonsai@b0n541.net
// Copyright:   GPL - Gnu Public License
////////////////////////////////////////////////////////////

// Plastic texture
#declare Plastic = texture
	{
	pigment
		{
		color rgb <0.25, 0, 0>
		}
	finish
		{
		ambient 0
		diffuse 0.75
		specular 0.65
		roughness 0.008
		reflection {0.03,1 falloff 5}
		phong 0.5
		phong_size 30
		}
	}

#declare PlasticShell = difference
	{
	union
		{
		torus {1, 0.25}
		cylinder {<0, -0.25, 0>, <0, 0.25, 0>, 1}
		torus {1, 0.25 translate <8, 0, 0>}
		cylinder {<0, -0.25, 0>, <0, 0.25, 0>, 1 translate <8, 0, 0>}
		box {<0, -0.25, -1>, <8, 0.25, 1>}
		cylinder {<0, 0, 0>, <8, 0, 0>, 0.25 translate <0, 0, -1>}
		cylinder {<0, 0, 0>, <8, 0, 0>, 0.25 translate <0, 0, 1>}
		}
	box {<-2, 0, -2>, <10, -0.5, 2>}
	}

#declare MetalLayer = intersection
	{
	union
		{
		torus {1, 0.25}
		cylinder {<0, -0.25, 0>, <0, 0.25, 0>, 1}
		torus {1, 0.25 translate <8, 0, 0>}
		cylinder {<0, -0.25, 0>, <0, 0.25, 0>, 1 translate <8, 0, 0>}
		box {<0, -0.25, -1>, <8, 0.25, 1>}
		cylinder {<0, 0, 0>, <8, 0, 0>, 0.25 translate <0, 0, -1>}
		cylinder {<0, 0, 0>, <8, 0, 0>, 0.25 translate <0, 0, 1>}
		}
	box {<-2, -0.1, -2>, <10, 0.1, 2>}

	translate <0, 0.1, 0>

	material
		{
		texture
			{
			T_Chrome_3A
			}
		}
	}

#declare ToolMetal = T_Chrome_3E;

// Knife
#declare Knife = union
	{
	// upper plastic shell
	difference
		{
		object{PlasticShell}

		union
			{
			box {<1, -0.5, -2>,<4.5, 0.5, -0.5>}
			cylinder {<0, -0.5, 0>, <0, 0.5, 0>, 1.5 scale <0.5, 1, 2> translate <1, 0, -3.5>}
			}

		translate <0, 2.05, 0>

		material
			{
			texture
				{
				Plastic
				}
			}
		}

	// 5th metal layer
	difference
		{
		object {MetalLayer}

		union
			{
			box {<1, -0.5, -2>,<4.5, 0.5, -0.5>}
			cylinder {<0, -0.5, 0>, <0, 0.5, 0>, 1.5 scale <0.5, 1, 2> translate <1, 0, -3.5>}
			}

		translate <0, 1.85, 0>

		material
			{
			texture
				{
				T_Chrome_3A
				}
			}
		}

	// corkskrew
	#declare Steps = 100;
	#declare i = 0;
	#declare AngleValue = 0;

	union
		{
		sphere_sweep
			{
			cubic_spline
			Steps,

			#while (i < Steps)
				#if (i/Steps < 0.8)
					#declare x_val = cos(radians(AngleValue)) * 3;
					#declare z_val = sin(radians(AngleValue)) * 3;
					<x_val, i/Steps * 35, z_val>, 1.5
					#declare i = i + 1;
					#declare AngleValue = AngleValue + 20;
				#else
					#declare x_val = cos(radians(AngleValue)) * 3;
					#declare z_val = sin(radians(AngleValue)) * 3;
					<x_val, i/Steps * 35, z_val>, 7.5 * (1 - i/Steps)
					#declare i = i + 1;
					#declare AngleValue = AngleValue + 20;
				#end
			#end

			tolerance 0.1

			scale 0.1

			rotate <0, 190, 90>

			translate <4.3, 2.15, -0.95>
			}

		box {<4.1, 1.65, -1.25>, <4.9, 1.85, 0>}

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// distance holder
	cylinder
		{
		<0, 0, 0>, <0, -0.2, 0>, 1.25

		translate <0, 1.85, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	cylinder
		{
		<0, 0, 0>, <0, -0.2, 0>, 1.25

		translate <8, 1.85, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// gap filler
	union
		{
		box {<5, 1.65, -1.25>, <7.5, 1.85, -0.25>}
		box {<0.5, 1.65, -0.5>, <7.5, 1.85, 0>}


		material
			{
			texture
				{
				T_Chrome_4C
				}
			}
		}

	// 4th metal layer
	object
		{
		MetalLayer

		translate <0, 1.45, 0>
		}

	// screw driver and bottle opener
	union
		{
		difference
			{
			union
				{
				box {<0, 0, 0.25>, <4.5, 0.2, 1.25>}
				cylinder {<0, 0, 0>, <0, 0.2, 0>, 0.5 scale <1.5, 1, 1> rotate <0, 25, 0> translate <2, 0, 0.35>}
				}
			cylinder {<0, -0.1, 0>, <0, 0.3, 0>, 0.35 translate <2.5, 0, 0.35>}
			cylinder {<0, -0.1, 0>, <0, 0.3, 0>, 0.35 scale <2, 1, 1> rotate <0, 10, 0> translate <2.9, 0, 0.35>}
			box {<0, -0.1, 0>, <-2, 0.3, 1> rotate <0, 7, 0> translate <4.7, 0, 1.1>}
			box {<0, -0.1, 0>, <-2, 0.3, -1> rotate <0, -7, 0> translate <4.7, 0, 0.4>}
			box {<0, 0, 0>, <5, 0.5, 2> rotate <0, 0, -3> translate <3.75, 0.2, 0>}
			box {<0, 0, 0>, <5, -0.5, 2> rotate <0, 0, 3> translate <3.75, 0, 0>}
			cylinder {<0, 0, 0>, <0, 1, -1>, 3 translate <2.5, 2.23, 3.15>}
			scale <0.9, 1, 1>
			}

		cylinder {<0, 0, 0>, <0, 0.2, 0>, 1.25}


		// Angle of tool not in use
		rotate <0, -4, 0>

		// Angle of tool in use
		rotate <0, -75, 0>

		translate <0, 1.25, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// tin opener
	union
		{
		difference
			{
			union
				{
				box {<0, 0, 0.25>, <-3.5, 0.2, 1.25>}
				intersection
					{
					box {<-3.25, 0, -0.2>, <-4.5, 0.2, 2>}
					cylinder {<-3.25, -0.1, 0.5>, <-3.25, 0.3, 0.5>, 0.75}
					}
				box {<-3.4, 0, 0.4>, <-3.99, 0.2, 1.25>}
				cylinder {<0, 0, 0>, <0, 0.2, 0>, 0.5 scale <1.5, 1, 1> rotate <0, -25, 0> translate <-2, 0, 0.35>}
				}
			box {<-2.5, -0.1, 0.2>, <-3.25, 0.3, 0.7>}
			cylinder {<0, -0.1, 0>, <0, 0.3, 0>, 0.35 translate <-2.5, 0, 0.35>}
			box {<0, -0.1, 0>, <2, 0.3, 1> rotate <0, -15, 0> translate <-4.7, 0, 0.9>}
			difference
				{
				cylinder {<0, 0, 0>, <0, 0.5, 0>, 1.2}
				box {<2, -0.1, 0>, <-2, 0.6, 2>}
				rotate <0, 45, 0>
				rotate <-5, 0, 0>
				rotate <0, 0, 7>
				translate <-3.3, 0.25, 0.5>
				}
			difference
				{
				cylinder {<0, 0, 0>, <0, -0.5, 0>, 1.2}
				box {<2, -0.1, 0>, <-2, 0.6, 2>}
				rotate <0, 45, 0>
				rotate <5, 0, 0>
				rotate <0, 0, -7>
				translate <-3.3, -0.05, 0.5>
				}
			cylinder {<0, 0, 0>, <0, 1, -1>, 3 translate <-2.5, 2.23, 3.15>}

			scale <0.9, 1, 1>
			}

		cylinder {<0, 0, 0>, <0, 0.2, 0>, 1.25}

		// Angle of tool not in use
		rotate <0, 4, 0>

		// Angle of tool in use
		rotate <0, 140, 0>

		translate <8, 1.25, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// gap filler
	box
		{
		<0.5, 1.25, -1.25>, <7.5, 1.45, -0.25>


		material
			{
			texture
				{
				T_Chrome_4C
				}
			}
		}

	// 3rd metal layer
	object
		{
		MetalLayer

		translate <0, 1.05, 0>
		}

	// distance holder
	cylinder
		{
		<0, 0, 0>, <0, -0.2, 0>, 1.25

		rotate <0, -40, 0>

		translate <0, 1.05, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// Big knife
	union
		{
		difference
			{
			union
				{
				box {<0, 0, 0.25>, <-6.3, 0.2, 1.25>}
				intersection
					{
					cylinder {<0, 0.000000001, -1>, <0, 0.2000000001, -1>, 2}
					cylinder {<0, 0, 2>, <0, 0.2, 2>, 2}

					rotate <0, -3, 0>

					translate <-6.2, 0, 0.25>
					}
				}

			box {<-1.5, 0, -1>, <-8,  1, 2> rotate <-5, 0, 0> translate <0, 0.19, 1.2>}
			box {<-1.5, 0, -1>, <-8, -1, 2> rotate < 5, 0, 0> translate <0, 0, 1.2>}

			box {<0, -1, 0>, <1, 1, 1> rotate <0, 30, 0> translate <-2, 0, -0.55>}

			cylinder {<0, 0, 0>, <0, 1, -1>, 3 translate <-5, 2.23, 3.15>}
			}

		cylinder {<0, 0, 0>, <0, 0.2, 0>, 1.25}

		// Angle of tool not in use
		rotate <0, 4, 0>

		// Angel of tool in use
		rotate <0, 45, 0>

		translate <8, 0.85, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// gap filler
	box
		{
		<0.5, 0.85, -1.25>, <7.5, 1.05, -0.25>


		material
			{
			texture
				{
				T_Chrome_4C
				}
			}
		}

	// 2nd metal layer
	object
		{
		MetalLayer

		translate <0, 0.65, 0>
		}

	// distance holder
	cylinder
		{
		<0, 0, 0>, <0, 0.2, 0>, 1.25

		rotate <0, 0, 0>

		translate <0, 0.45, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// saw
	union
		{
		difference
			{
			union
				{
				box{<0,  0.0, 0.5>, <-7, 0.13, 1.25>}
				cylinder {<0, 0, 0>, <0, 0.13, 0>, 0.1 scale <1, 1, 2.5> translate <-7, 0, 0.75>}
				}
			box{<0, -0.1, 0.0>, <-7, 0.3, 1.25> rotate <0, -5, 0> translate <-3, 0, 1.3>}

			#declare Tooth = 1;
			#while (Tooth < 23)

				difference
					{
					box{<-0.25, -0.2, -0.25>, <0.25, 0.4, 0.25> rotate <0, 45, 0>}
					box{<0, -0.3, -0.5>, <-0.5, 0.5, 0.5>}
					rotate<0, 0, 45>
					translate <-1.2-Tooth*0.25, 0, 0.3>
					}

				difference
					{
					box{<-0.25, -0.2, -0.25>, <0.25, 0.4, 0.25> rotate <0, 45, 0>}
					box{<0, -0.3, -0.5>, <-0.5, 0.5, 0.5>}
					rotate<0, 0, -45>
					translate <-1.45-Tooth*0.25, 0, 0.3>
					}

				#declare Tooth = Tooth + 1;
			#end

			cylinder {<0, 0, 0>, <0, -1, -1>, 3 rotate<0, -5, 0> translate <-5, -2.07, 3.1>}

			translate <0, 0.035, 0>
			}

		box{<0, 0.0, 0.5>, <-1.2, 0.2, 1.25>}
		cylinder {<0, 0, 0>, <0, 0.2, 0>, 1.25}

		// Angle of tool not in use
		rotate <0, 4, 0>

		// Angle of tool in use
		rotate <0, 80, 0>

		translate <8, 0.45, 0>

		material
			{
			texture
				{
				ToolMetal
				}
			}
		}

	// gap filler
	box
		{
		<0.5, 0.45, -1.25>, <7.5, 0.65, -0.25>

		material
			{
			texture
				{
				T_Chrome_4C
				}
			}
		}

	// 1st metal layer
	object
		{
		MetalLayer

		translate <0, 0.25, 0>
		}

	// lower plastic shell
	object
		{
		PlasticShell

		rotate <180, 0, 0>

		translate <0, 0.25, 0>

		material
			{
			texture
				{
				Plastic
				}
			}
		}
	}

