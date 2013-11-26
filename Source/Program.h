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
			bool							LoadSpriteSheet();
			bool							InitializeSFML();
			int								Run(); 
			void							ProcessHandle(sf::Event& event);

			//public members
			std::unique_ptr<Animation>		mAnimation;
			sf::RenderWindow				mRenderWindow;
			ConfigLoader					mConfigLoader; 
};


#endif PROGRAM_H