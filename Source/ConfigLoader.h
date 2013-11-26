#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H
#include "tinyxml2.h"
#include <string>
class ConfigLoader
{
private:
		int				mWindowWidth; 
		int				mWindowHeight; 
		int				mSpriteWidth;
		int				mSpriteHeight; 
public:
	ConfigLoader();
	~ConfigLoader();

		bool			Initialize(std::string fileName);
		int				GetWindowHeight() const;
		int				GetWindowWidth() const; 
		int				GetSpriteWidth() const; 
		int				GetSpriteHeight() const; 
};

#endif CONFIG_LOADER_H