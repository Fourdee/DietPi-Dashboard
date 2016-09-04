#pragma once
//-----------------------------------------------------------------
//-----------------------------------------------------------------
class Dietpi_Software
{
	//-------------------------------------------------------------
	public:
		//---------------------------------------------------------
		//General
		int MAX_SOFTWARE_INDEX;
		string* sSoftwareName;
		string* sSoftwareDesc;
		string* sSoftwareUrlDocs;
		signed short* iSoftwareInstalledState;
		signed short* iSoftwareCategoryIndex;
		signed short* iSoftwareAvailableForHwModel;
		signed short* iSoftwareAvailableForHwArch;
		
		//Categories
		int MAX_CATEGORY_INDEX_DIETPI;
		int MAX_CATEGORY_INDEX_LINUX;
		string* sCategoryDesc_DietPi;
		string* sCategoryDesc_Linux;
		//---------------------------------------------------------
		//functions
		void Create(void);
		void Destroy(void);
		void Update(void);
		bool Install_Software(signed short index); //returns 1=success
		bool Remove_Software(signed short index); //returns 1=success
		bool Software_Installed(signed short index); //returns 1=yes
		//---------------------------------------------------------
		//constructors
		Dietpi_Software(void);
		~Dietpi_Software(void);
		//---------------------------------------------------------

	//-------------------------------------------------------------
	private:
		//---------------------------------------------------------
		//functions
		void ZeroData(void);
		//---------------------------------------------------------
	//-------------------------------------------------------------
};
