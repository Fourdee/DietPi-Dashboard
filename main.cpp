
//Includes
#include "main.h"
#include "global.h"

//apt-get install -y g++ build-essential libboost-dev libboost-system-dev
//g++ -std=c++11 -lboost_system -lpthread *.cpp -o dietpi-dashboard
//g++ -std=c++11 *.cpp -o dietpi-dashboard
//chmod +x dietpi-dashboard
//./dietpi-dashboard

//VS CODE keybinds
//ctrl+k ctrl+c = Comment
//ctrl+k ctrl+u = Uncomment

int main (int argc, char ** argv)
{

    //Grab core DietPi and System data
    cDietPi_Core.Update();

    //init DietPi-Software vars
    cDietPi_Software.Create();

    // //Install/remove software test
    // cDietPi_Software.Install_Software(3);
    // cDietPi_Software.Remove_Software(3);

    // //Software installed test
    // if ( cDietPi_Software.Software_Installed(103) )
    // {
    //     cout << "yes";
    // }
    // else
    // {
    //     cout << "no";
    // }

    cDietPi_Software.Update();

    cDietPi_Software.Destroy();

    cWeb_Dash.Update();

    return 0;

}
