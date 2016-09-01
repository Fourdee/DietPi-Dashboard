
//Includes
#include "main.h"
#include "global.h"

//apt-get install -y g++ build-essential #libboost-dev
//g++ -std=c++11 *.cpp -o dietpi-dashboard
//chmod +x dietpi-dashboard
//./dietpi-dashboard

int main()
{

    cDietPi_Software.Create();

    cDietPi_Software.Update();

    cDietPi_Software.Destroy();
    
    return 0;

}
