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
       
 		string line;
		while (getline(file, line))
		{
			int index = 0;
			sSoftwareName[index] = line;
			printf("sSoftwareName %s\n", sSoftwareName[index].c_str());
			index++;
		}
       
		file.close();

    }

	file.clear();

	//Grab descriptions
	sSoftwareDesc = new string[iTotal_Software_Indexs];
	file.open("/tmp/dietpi-software/weblist_export/software_desc");
    if(file.is_open())
    {

		string line;
		while (getline(file, line))
		{
			int index = 0;
			sSoftwareDesc[index] = line;
			printf("sSoftwareDesc %s\n", sSoftwareDesc[index].c_str());
			index++;
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
			printf("iSoftwareInstalledState %i\n", iSoftwareInstalledState[i]);

        }

 		file.close();

   }

	file.clear();

	//Grab url links for online docs
	sSoftwareUrlDocs = new string[iTotal_Software_Indexs];
	file.open("/tmp/dietpi-software/weblist_export/software_urldocs");
    if(file.is_open())
    {
       
 		string line;
		while (getline(file, line))
		{
			int index = 0;
			sSoftwareUrlDocs[index] = "http://dietpi.com/phpbb/viewtopic.php?";
			sSoftwareUrlDocs[index] += line;
			printf("sSoftwareUrlDocs %s\n", sSoftwareUrlDocs[index].c_str());
			index++;
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
	delete [] sSoftwareUrlDocs;
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