// FileHandling1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<string>
#include<vector>
#include<windows.h>


void createCSV(const std::string& compName, std::vector<std::string>& headers) {
	std::string fileName = compName + ".csv";
	std::ofstream file(fileName);
	if (!file.is_open())
	{
		std::cerr << "Not Created";
	}
	else
	{
		file << "Component - "<<compName<<",";
		file << "No of Faces\n";
		for (int i = 0; i < headers.size(); i++)
		{
			file << headers[i];
			if (i<headers.size()-1)
			{
				file << ",";
			}
		}
		file << "\n";

		file.close();
		std::cout << "Created";
	}
}

void addRecord(const std::string& compName,const std::vector<std::string>& data) {
	std::string fileName = compName + ".csv";

	std::ofstream file(fileName,std::ios::app);
	if (!file.is_open())
	{
		std::cerr << "unable";
	}
	else
	{
		for (int i = 0; i < data.size(); i++)
		{
			file << data[i];
			if (i < data.size() - 1)
			{
				file << ",";
			}
		}
		file << "\n";
		file.close();
		std::cout << "Rec added";
	}
}

int main()
{

	std::string compName = "Component1";
	std::vector<std::string> headers = { "1","2","3","4","5" };
	std::vector<std::string> data = { "A","B","C","D","E" };
	createCSV(compName,headers);
	addRecord(compName, data);

	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
