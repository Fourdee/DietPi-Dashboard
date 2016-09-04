#include "global.h"

Dietpi_Core::Dietpi_Core(void)
{
	//-------------------------------------------------------------
	ZeroData();
	//-------------------------------------------------------------
}

Dietpi_Core::~Dietpi_Core(void)
{
	//-------------------------------------------------------------
	//-------------------------------------------------------------
}

void Dietpi_Core::Create(void)
{
	//-------------------------------------------------------------
	//-------------------------------------------------------------
}

void Dietpi_Core::Destroy(void)
{
	//-------------------------------------------------------------
	//-------------------------------------------------------------
}

void Dietpi_Core::ZeroData(void)
{
	//-------------------------------------------------------------
	//-------------------------------------------------------------
}

void Dietpi_Core::Update(void)
{
	//-------------------------------------------------------------
	//Update system file
	exec("/DietPi/dietpi/dietpi-obtain_hw_model");

	iHw_Model = stoi ( exec("sed -n 1p /DietPi/dietpi/.hw_model") );
	iHw_Arch = stoi ( exec("sed -n 6p /DietPi/dietpi/.hw_model") );
	iDistro = stoi ( exec("sed -n 3p /DietPi/dietpi/.hw_model") );
	sDeviceName = exec("sed -n 2p /DietPi/dietpi/.hw_model");
	sDeviceArch = exec("sed -n 7p /DietPi/dietpi/.hw_model");
	sDeviceUUID = exec("sed -n 5p /DietPi/dietpi/.hw_model");

	printf("iHw_Model %i\n", iHw_Model);
	printf("iHw_Arch %i\n", iHw_Arch);
	printf("iDistro %i\n", iDistro);
	printf("sDeviceName %s\n", sDeviceName.c_str());
	printf("sDeviceArch %s\n", sDeviceArch.c_str());
	printf("sDeviceUUID %s\n", sDeviceUUID.c_str());
	//-------------------------------------------------------------
}