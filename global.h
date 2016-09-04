#pragma once

using namespace std;

//------------------------------------------------------
//Global Includes
//------------------------------------------------------
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdexcept>
#include <cstring>

//------------------------------------------------------
//Classes
//------------------------------------------------------
#include "Dietpi_Software.h"
extern Dietpi_Software cDietPi_Software;

#include "Dietpi_Core.h"
extern Dietpi_Core cDietPi_Core;

#include "Web_Dash.h"
extern Web_Dash cWebDash;

//------------------------------------------------------
//Global functions
//------------------------------------------------------
//Exec command and return output
extern string exec(const char* cmd);