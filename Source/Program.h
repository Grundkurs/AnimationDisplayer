#ifndef PROGRAM_H
#define PROGRAM_H
#include <SFML\Graphics.hpp>
#include <memory>
#include "ConfigLoader.h"
#include "Animation.h"
class Program
{
public:
	Program();
	~Program();

			bool							Startup();
			bool							LoadNewSpriteSheet();
			bool							LoadRecentSpriteSheet(); 
			bool							InitializeSFML();
			int								Run(); 
			void							ProcessHandle(sf::Event& event);

private:

			std::unique_ptr<Animation>		mAnimation;
			sf::RenderWindow				mRenderWindow;
			ConfigLoader					mConfigLoader; 



			std::string						texturePath; 
			sf::Texture						spriteSheetTexture; 
};


#endif PROGRAM_H