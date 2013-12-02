#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H
#include "tinyxml2.h"
#include <string>
class ConfigLoader
{
private:
		int				mWindowWidth; 
		int				mWindowHeight; 
		int				mSpritesInRow; 
		int				mSpritesInColumn; 
		std::string		mTexturePathString; 
public:
	ConfigLoader();
	~ConfigLoader();

		bool			Initialize(std::string fileName);
		bool			IsNoError(const tinyxml2::XMLError& err);
		bool			WriteToXML(std::string fileName, int width, int height, int spritesInRow, int spriteInColumn);
		int				GetWindowHeight() const;
		int				GetWindowWidth() const; 
		int				GetSpritesInRow() const; 
		int				GetSpritesInColumn() const; 
		std::string		GetTexturePath() const; 
};

#endif //CONFIG_LOADER_H
