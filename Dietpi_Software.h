#pragma once
//-----------------------------------------------------------------
//-----------------------------------------------------------------
class Dietpi_Software
{
	//-------------------------------------------------------------
	public:
		//---------------------------------------------------------
		//data
		int iTotal_Software_Indexs;
		string* sSoftwareName;
		string* sSoftwareDesc;
		int* iSoftwareInstalledState;
		//---------------------------------------------------------
		//functions
		void Create(void);
		void Destroy(void);
		void Update(void);
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