#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H
#include <SFML\Graphics.hpp>
#include "ConfigLoader.h"
class Program
{
public:
	Program();
	~Program();

			bool							Initialize();
			int								Run(); 


			sf::RenderWindow				mRenderWindow;
			ConfigLoader					mConfigLoader; 
};


#endif PROGRAM_H