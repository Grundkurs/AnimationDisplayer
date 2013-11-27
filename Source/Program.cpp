#include "Program.h"
#include <iostream>
#include <string>
#include <io.h>
using std::cout;

Program::Program()
{
}


Program::~Program()
{
}


bool Program::Startup()
	{
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
	std::string path;
	std::getline(std::cin, path);
	
	//_access
/*Look up the access() function. You can replace your function with

if( access( fname, F_OK ) != -1 ) {
    // file exists
} else {
    // file doesn't exist
}

You can also use R_OK, W_OK, and X_OK in place of F_OK to check for read permission, write permission, and execute permission (respectively) rather than existence, and you can OR any of them together (i.e. check for both read and write permission using R_OK|W_OK)

Update: Note that on Windows, you can't use W_OK to reliably test for write permission, since the access function does not take DACLs into account. access( fname, W_OK ) may return 0 (success) because the file does not have the read-only attribute set, but you still may not have permission to write to the file.
*/

	cout << "Opening: " << path; 
	InitializeSFML();
	return true; 
	}
bool Program::InitializeSFML()
	{
	
	if (!mConfigLoader.Initialize("..//Resources//ConfigFile.xml")) return false;  
	auto WindowHeight = mConfigLoader.GetWindowHeight();
	auto WindowWidth = mConfigLoader.GetWindowWidth();
	cout << "Window Width: " << WindowWidth << "\n"; 
	cout << "Window Height" << WindowHeight << "\n";
	mRenderWindow.create(sf::VideoMode(WindowWidth, WindowHeight), "AnimatonShower v.01");
	mAnimation = std::unique_ptr<Animation>(new Animation);


	return true;
	}

void Program::ProcessHandle(sf::Event& event)
{
}
int	Program::Run()
	{
	sf::Event event; 
	while (mRenderWindow.isOpen())
		{
		while (mRenderWindow.pollEvent(event))
			{
			if (event.type == sf::Event::Closed) mRenderWindow.close();
			ProcessHandle(event);
			}
		mAnimation->Update();
		mRenderWindow.draw(mAnimation->GetSprite());
		mRenderWindow.display();
		}
	return 0; 
	}