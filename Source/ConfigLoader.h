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
		int				mSingleAnimationRows; 
		std::string		mTexturePathString; 
public:
	ConfigLoader();
	~ConfigLoader();

		bool			Initialize(std::string fileName);
		bool			IsNoError(const tinyxml2::XMLError& err);
		bool			WriteToXML(std::string fileName, 
												int width, 
												int height, 
												int spritesInRow, 
												int spriteInColumn, 
												int singleAnimationRows);
		int				GetWindowHeight() const;
		int				GetWindowWidth() const; 
		int				GetSpritesInRow() const; 
		int				GetSpritesInColumn() const;
		int			GetSingleAnimationRows() ;
		std::string		GetTexturePath() const; 
};

#endif //CONFIG_LOADER_H
