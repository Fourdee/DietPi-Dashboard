#include "global.h"

Dietpi_Software::Dietpi_Software(void)
{
	//-------------------------------------------------------------
	ZeroData();
	//-------------------------------------------------------------
}

Dietpi_Software::~Dietpi_Software(void)
{
	//-------------------------------------------------------------
	//-------------------------------------------------------------
}

void Dietpi_Software::Create(void)
{
	//-------------------------------------------------------------
	//Export list from dietpi-software
	exec("/DietPi/dietpi/dietpi-software weblist_export");

	//Total number of installation options
	iTotal_Software_Indexs = stoi ( exec("cat /tmp/dietpi-software/weblist_export/total_software_index") );

	//filestream
	ifstream file;

	//Grab Names
	sSoftwareName = new string[iTotal_Software_Indexs];
	file.open("/tmp/dietpi-software/weblist_export/software_name");
    if(file.is_open())
    {
       
        for(int i = 0; i < iTotal_Software_Indexs; ++i)
        {
            file >> sSoftwareName[i];
			printf("%s\n", sSoftwareName[i].c_str());

        }

		file.close();

    }

	file.clear();

	//Grab descriptions
	sSoftwareDesc = new string[iTotal_Software_Indexs];
	file.open("/tmp/dietpi-software/weblist_export/software_desc");
    if(file.is_open())
    {
       
        for(int i = 0; i < iTotal_Software_Indexs; ++i)
        {
			file >> sSoftwareDesc[i];
			printf("%s\n", sSoftwareDesc[i].c_str());

        }

 		file.close();

   }

	file.clear();

	//Grab installed state
	iSoftwareInstalledState = new int[iTotal_Software_Indexs];
	file.open("/tmp/dietpi-software/weblist_export/software_installed_state");
    if(file.is_open())
    {
       
        for(int i = 0; i < iTotal_Software_Indexs; ++i)
        {
            file >> iSoftwareInstalledState[i];
			printf("%i\n", iSoftwareInstalledState[i]);

        }

 		file.close();

   }

	file.clear();
	
	//-------------------------------------------------------------
}

void Dietpi_Software::Destroy(void)
{
	//-------------------------------------------------------------
	delete [] sSoftwareName;
	delete [] sSoftwareDesc;
	delete [] iSoftwareInstalledState;
	//-------------------------------------------------------------
}

void Dietpi_Software::ZeroData(void)
{
	//-------------------------------------------------------------
	//-------------------------------------------------------------
}

void Dietpi_Software::Update(void)
{
	//-------------------------------------------------------------
	//-------------------------------------------------------------
}