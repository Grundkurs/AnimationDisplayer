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

	element = xmlDoc.FirstChildElement("SpritesInRow");
	err = element->QueryIntText(&mSpritesInRow);
	if (!IsNoError(err)) return false;

	element = xmlDoc.FirstChildElement("SpritesInColumn");
	err = element->QueryIntText(&mSpritesInColumn);
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
int	ConfigLoader::GetSpritesInRow() const{ return mSpritesInRow; }
int	ConfigLoader::GetSpritesInColumn() const{ return mSpritesInColumn;  }

bool ConfigLoader::WriteToXML(std::string fileName, int width, int height, int spritesInRow, int spritesInColumn)
{	
	XMLDocument doc;
	std::string xmlText("<?xml version=\"1.0\"?>\n");
	xmlText += "<TexturePath>";
	xmlText += fileName;
	xmlText += "</TexturePath>";
	xmlText += "<WindowWidth>";
	xmlText += std::to_string(width);
	xmlText += "</WindowWidth>";
	xmlText += "<WindowHeight>";
	xmlText += std::to_string(height);
	xmlText += "</WindowHeight>";
	xmlText += "<SpritesInRow>";
	xmlText += std::to_string(spritesInRow);
	xmlText += "</SpritesInRow>";
	xmlText += "<SpritesInColumn>";
	xmlText += std::to_string(spritesInColumn);
	xmlText += "</SpritesInColumn>";
	doc.Parse(xmlText.c_str());

	doc.SaveFile("..//Resources//ConfigFile.xml");
	return true;

}

std::string	ConfigLoader::GetTexturePath() const{ return mTexturePathString; }