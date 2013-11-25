#include "ConfigLoader.h"
#include <iostream>

ConfigLoader::ConfigLoader()
	{
	}


ConfigLoader::~ConfigLoader()
	{
	}


bool ConfigLoader::Initialize(std::string fileName)
	{
	using namespace tinyxml2;
	XMLDocument xmlDoc; 
	XMLError err = xmlDoc.LoadFile(fileName.c_str());
	switch (err)
		{
		case (XMLError::XML_SUCCESS):
			{
			std::cout << "xml loaded successfully\n"; 
			break; 
			}
		case (XMLError::XML_ERROR_EMPTY_DOCUMENT) :
			{
			std::cout << "Error. XML-File is empty\n"; 
			return false;
			}
		case (XMLError::XML_ERROR_FILE_NOT_FOUND) :
			{
			std::cout << "Error. XML-File not found\n"; 
			return false; 
			}
		case (XMLError::XML_ERROR_FILE_READ_ERROR):
			{
			std::cout << "Error. Could not read XML-File\n"; 
			return false; 
			}
		
		default:
			{
			std::cout << "Unknown Error\n";
			return false;
			}
			
		}//end of switch-statement
	return true;
	}
int ConfigLoader::GetWindowWidth(){ return mWindowWidth; }
int ConfigLoader::GetWindowHeight(){ return mWindowHeight; }
