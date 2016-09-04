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
	MAX_SOFTWARE_INDEX = stoi ( exec("cat /tmp/dietpi-software/weblist_export/total_software_index") );

	//filestream
	ifstream file;

	//Grab Names
	sSoftwareName = new string[MAX_SOFTWARE_INDEX]{"NULL"};
	file.open("/tmp/dietpi-software/weblist_export/software_name");
    if(file.is_open())
    {
       
 		string line;
		while (getline(file, line))
		{
			int index = 0;
			if ( ! line.empty() )
			{
				sSoftwareName[index] = line;
			}
			printf("sSoftwareName %s\n", sSoftwareName[index].c_str());
			index++;
		}
       
		file.close();

    }

	file.clear();

	//Grab descriptions
	sSoftwareDesc = new string[MAX_SOFTWARE_INDEX]{"NULL"};
	file.open("/tmp/dietpi-software/weblist_export/software_desc");
    if(file.is_open())
    {

		string line;
		while (getline(file, line))
		{
			int index = 0;
			if ( ! line.empty() )
			{
				sSoftwareDesc[index] = line;
			}	
			printf("sSoftwareDesc %s\n", sSoftwareDesc[index].c_str());
			index++;
		}
       
 		file.close();

   }

	file.clear();

	//Grab installed state
	iSoftwareInstalledState = new signed short[MAX_SOFTWARE_INDEX]{0};
	file.open("/tmp/dietpi-software/weblist_export/software_installed_state");
    if(file.is_open())
    {
       
	    for(int i = 0; i < MAX_SOFTWARE_INDEX; ++i)
        {
            file >> iSoftwareInstalledState[i];
			printf("iSoftwareInstalledState %i\n", iSoftwareInstalledState[i]);

        }

 		file.close();

   }

	file.clear();

	//Grab url links for online docs
	sSoftwareUrlDocs = new string[MAX_SOFTWARE_INDEX]{"NULL"};
	file.open("/tmp/dietpi-software/weblist_export/software_urldocs");
    if(file.is_open())
    {
       
 		string line;
		while (getline(file, line))
		{
			int index = 0;
			if ( ! line.empty() )
			{
				sSoftwareUrlDocs[index] = "http://dietpi.com/phpbb/viewtopic.php?";
				sSoftwareUrlDocs[index] += line;
			}
			printf("sSoftwareUrlDocs %s\n", sSoftwareUrlDocs[index].c_str());
			index++;
		}
       
		file.close();

    }

	file.clear();

	//Grab cat index
	iSoftwareCategoryIndex = new signed short[MAX_SOFTWARE_INDEX]{0};
	file.open("/tmp/dietpi-software/weblist_export/category_index");
    if(file.is_open())
    {
       
	    for(int i = 0; i < MAX_SOFTWARE_INDEX; ++i)
        {
            file >> iSoftwareCategoryIndex[i];
			printf("iSoftwareCategoryIndex %i\n", iSoftwareCategoryIndex[i]);

        }

 		file.close();

   }

	file.clear();

	//Grab available for HW_MODEL
	iSoftwareAvailableForHwModel = new signed short[MAX_SOFTWARE_INDEX]{0};
	file.open("/tmp/dietpi-software/weblist_export/software_available_hw_model");
    if(file.is_open())
    {
       
	    for(int i = 0; i < MAX_SOFTWARE_INDEX; ++i)
        {
            file >> iSoftwareAvailableForHwModel[i];
			printf("iSoftwareAvailableForHwModel %i\n", iSoftwareAvailableForHwModel[i]);

        }

 		file.close();

   }

	//Grab available for HW_ARCH
	iSoftwareAvailableForHwArch = new signed short[MAX_SOFTWARE_INDEX]{0};
	file.open("/tmp/dietpi-software/weblist_export/software_available_hw_arch");
    if(file.is_open())
    {
       
	    for(int i = 0; i < MAX_SOFTWARE_INDEX; ++i)
        {
			file >> iSoftwareAvailableForHwArch[i];
			printf("iSoftwareAvailableForHwArch %i\n", iSoftwareAvailableForHwArch[i]);

        }

 		file.close();

   }

   	//Category
	MAX_CATEGORY_INDEX_DIETPI = stoi ( exec("cat /tmp/dietpi-software/weblist_export/category_dietpi_total") );
	MAX_CATEGORY_INDEX_LINUX = stoi ( exec("cat /tmp/dietpi-software/weblist_export/category_linux_total") );

	sCategoryDesc_DietPi = new string[MAX_CATEGORY_INDEX_DIETPI]{"NULL"};
	file.open("/tmp/dietpi-software/weblist_export/category_dietpi_desc");
    if(file.is_open())
    {
       
 		string line;
		while (getline(file, line))
		{
			int index = 0;
			if ( ! line.empty() )
			{
				sCategoryDesc_DietPi[index] = line;
			}
			printf("sCategoryDesc_DietPi %s\n", sCategoryDesc_DietPi[index].c_str());
			index++;
		}
       
		file.close();

    }

	file.clear();

	sCategoryDesc_Linux = new string[MAX_CATEGORY_INDEX_LINUX]{"NULL"};
	file.open("/tmp/dietpi-software/weblist_export/category_linux_desc");
    if(file.is_open())
    {
       
 		string line;
		while (getline(file, line))
		{
			int index = 0;
			if ( ! line.empty() )
			{
				sCategoryDesc_Linux[index] = line;
			}
			printf("sCategoryDesc_Linux %s\n", sCategoryDesc_Linux[index].c_str());
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
	//General
	delete [] sSoftwareName;
	delete [] sSoftwareDesc;
	delete [] sSoftwareUrlDocs;
	delete [] iSoftwareInstalledState;
	delete [] iSoftwareCategoryIndex;
	delete [] iSoftwareAvailableForHwModel;
	delete [] iSoftwareAvailableForHwArch;

	//Categories
	delete [] sCategoryDesc_DietPi;
	delete [] sCategoryDesc_Linux;
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

bool Dietpi_Software::Install_Software(signed short index)
{
	//-------------------------------------------------------------
	string command="/DietPi/dietpi/dietpi-software install ";
	command += to_string(index);
	string result = exec(command.c_str());
	//TODO: Return success
	//-------------------------------------------------------------
}

bool Dietpi_Software::Remove_Software(signed short index)
{
	//-------------------------------------------------------------
	string command="/DietPi/dietpi/dietpi-software uninstall ";
	command += to_string(index);
	string result = exec(command.c_str());
	//TODO: Return success
	//-------------------------------------------------------------
}

bool Dietpi_Software::Software_Installed(signed short index)
{
	//-------------------------------------------------------------
	bool bReturn = false;
	if ( iSoftwareInstalledState[index] == 2 )
	{
		 bReturn = true;
	}
	return bReturn;
	//-------------------------------------------------------------
}
