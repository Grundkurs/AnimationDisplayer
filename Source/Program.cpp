#include "Program.h"


Program::Program()
{
}


Program::~Program()
{
}



bool Program::Initialize()
	{
	if (!mConfigLoader.Initialize("..//Resources//ConfigFile.xml")) return false;  
	auto WindowHeight = mConfigLoader.GetWindowHeight();
	auto WindowWidth = mConfigLoader.GetWindowWidth();
	mRenderWindow.create(sf::VideoMode(WindowHeight, WindowWidth), "AnimatonShower v.01");

	return true;
	}

int	Program::Run()
	{

	return 0; 
	}