#include "Program.h"
#include <iostream>
#include <string>
#include <io.h>
using std::cout;
using std::cin; 
#define R_OK 4
Program::Program()
{
}


Program::~Program()
{
}


bool Program::Startup()
	{
	if (!mConfigLoader.Initialize("..//Resources//ConfigFile.xml")) return false;
	cout << "a) Load new SpriteSheet\n"; 
	cout << "b) Display last SpriteSheet\n"; 
	cout << "x) Quit\n";
	char input; 
	bool correctChoice; 

	do
		{
		correctChoice = true; 
		std::cin >> input;
		std::cin.ignore(); 
		switch (input)
			{
			case 'A':
			case 'a':
				{
				return LoadSpriteSheet();
				}
			case 'B':
			case 'b':
				{
				InitializeSFML();
				return true;
				}
			case 'X':
			case 'x':
				{ 
				return false;
				}
			default:
				{
				cout << "wrong input\n";
				correctChoice = false;
				break; 
				}
		}
	} while (!correctChoice);

	}
bool Program::LoadSpriteSheet()
	{
	//if file not found or other problem
	//return false
	//otherwise
	//if Input correct, load png from given path, 
	//initialize sfml and return true, so program.run() will get evoked in main.cpp
	cout << "Type in name of SpriteSheet residing in the Resources-Folder:";
	bool foundFile = false;
	
	do
	{

		std::string fileName;
		std::getline(std::cin, fileName);

		if (fileName == "exit")
		{
			return false;
		}
		texturePath = "..//Resources//";
		texturePath.append(fileName);
		if (_access(texturePath.c_str(), R_OK) == -1)
		{
			//error
			cout << "no such File found!\n";
		}else{ foundFile = true; }
			
	} while (!foundFile);
	
	cout << "file found. loading...\n";
	InitializeSFML();
	return true; 
	}
bool Program::InitializeSFML()
	{
	
	 
	if (!spriteSheetTexture.loadFromFile(texturePath)) return false;
	
	auto WindowHeight = mConfigLoader.GetWindowHeight();
	auto WindowWidth = mConfigLoader.GetWindowWidth();
	cout << "Window Width: " << WindowWidth << "\n"; 
	cout << "Window Height" << WindowHeight << "\n";
	mRenderWindow.create(sf::VideoMode(WindowWidth, WindowHeight), "AnimatonShower v.01");
	mAnimation = std::unique_ptr<Animation>(new Animation);
	mAnimation->GetSprite().setTexture(spriteSheetTexture);


	return true;
	}

void Program::ProcessHandle(sf::Event& event)
{
}
int	Program::Run()
	{
	sf::Event event; 

	//main program loop
	while (mRenderWindow.isOpen()) 
		{
		while (mRenderWindow.pollEvent(event))
			{
			if (event.type == sf::Event::Closed) mRenderWindow.close();
			ProcessHandle(event);
			}
		mAnimation->Update();
		mRenderWindow.clear(sf::Color::Black);
		mRenderWindow.draw(mAnimation->GetSprite());
		mRenderWindow.display();
		}
	return 0; 
	}