#include "global.h"

//------------------------------------------------------
//Classes
//------------------------------------------------------
Dietpi_Core cDietPi_Core;
Dietpi_Software cDietPi_Software;
Web_Dash cWeb_Dash;

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
            {
                result += buffer;
            }
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);

    //Remove new lines from end of string
    if ( ! result.empty() && result[result.length()-1] == '\n') 
    {
        result.erase(result.length()-1);
    }
    return result;

}
