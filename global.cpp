#include "global.h"

//------------------------------------------------------
//Classes
//------------------------------------------------------
Dietpi_Software cDietPi_Software;
Web_Dash cWebDash;

//------------------------------------------------------
//Global functions
//------------------------------------------------------
string exec(const char* cmd) {
    
    int iBufferSize = 128;
    char buffer[iBufferSize];

    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, iBufferSize, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;

   // delete [] buffer;
}
