#include "ConfigLoader.h"
#include <iostream>
using namespace tinyxml2;
ConfigLoader::ConfigLoader()
	{
	}


ConfigLoader::~ConfigLoader()
	{
	}


bool ConfigLoader::Initialize(std::string fileName)
	{
	
	XMLDocument xmlDoc; 
	XMLError err = xmlDoc.LoadFile(fileName.c_str());
	if (!IsNoError(err)) return false; 

	XMLElement* element = xmlDoc.FirstChildElement("WindowWidth");
	err = element->QueryIntText(&mWindowWidth);
	if (!IsNoError(err))return false; 
		

	element = xmlDoc.FirstChildElement("WindowHeight");
	err = element->QueryIntText(&mWindowHeight);
	if (!IsNoError(err)) return false;
	element = xmlDoc.FirstChildElement("TexturePath");
	mTexturePathString = element->GetText();
	
	return true;
	}


bool ConfigLoader::IsNoError(const tinyxml2::XMLError& err)
{
	switch (err)
	{
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
	case (XMLError::XML_ERROR_FILE_READ_ERROR) :
		{
		std::cout << "Error. Could not read XML-File\n";
		return false;
		}
	case(XMLError::XML_NO_ATTRIBUTE) :
		{
		std::cout << "Error. No Attribute\n";
		return false;
		}
	case(XMLError::XML_ERROR_PARSING_ATTRIBUTE) :
		{
		std::cout << "Error parsing Attribute\n";
		return false;
		}
	case (XMLError::XML_SUCCESS):
		{
		return true;
		}
	default:
		{
		std::cout << "Unknown Error\n";
		return false;
		}

	}//end of switch-statement
}



int ConfigLoader::GetWindowWidth()const { return mWindowWidth; }
int ConfigLoader::GetWindowHeight()const { return mWindowHeight; }
int	ConfigLoader::GetSpriteWidth() const{ return mSpriteWidth; }
int	ConfigLoader::GetSpriteHeight() const{ return mSpriteHeight;  }

bool ConfigLoader::WriteToXML(std::string fileName)
{	
	XMLPrinter* printer = nullptr;
	return false;
}

std::string		ConfigLoader::GetTexturePath() const{ return mTexturePathString; }