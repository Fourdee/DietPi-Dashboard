#pragma once

using namespace std;

//------------------------------------------------------
//Global Includes
//------------------------------------------------------
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdexcept>
#include <string>

//------------------------------------------------------
//Classes
//------------------------------------------------------
#include "Dietpi_Software.h"
extern Dietpi_Software cDietPi_Software;

#include "Web_Dash.h"
extern Web_Dash cWebDash;

//------------------------------------------------------
//Global functions
//------------------------------------------------------
//Exec command and return output
extern string exec(const char* cmd);