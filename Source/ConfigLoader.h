#pragma once
#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H
#include "tinyxml2.h"
#include <string>
class ConfigLoader
{
private:
		int				mWindowWidth; 
		int				mWindowHeight; 
public:
	ConfigLoader();
	~ConfigLoader();

		bool			Initialize(std::string fileName);
		int				GetWindowHeight();
		int				GetWindowWidth(); 
};

#endif CONFIG_LOADER_H