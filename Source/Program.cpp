#include "Program.h"
#include <iostream>
#include <string>

#include <unistd.h>
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
				return LoadNewSpriteSheet();
				}
			case 'B':
			case 'b':
				{
				return LoadRecentSpriteSheet();
				
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
bool Program::LoadRecentSpriteSheet()
	{
	if (!mConfigLoader.Initialize("..//Resources//ConfigFile.xml")) 
		{ 
		cin.get(); //hold application just to show error-message  
		return false; 
		}
	texturePath += "..//Resources//";
	texturePath.append(mConfigLoader.GetTexturePath());
	spritesInRow = mConfigLoader.GetSpritesInRow(); 
	spritesInColumn = mConfigLoader.GetSpritesInColumn();
	InitializeSFML();
	return true; 
	}
bool Program::LoadNewSpriteSheet()
	{

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
	
		cout << "file found. Enter Number of Sprites in Row: "; 
		cin >> spritesInRow; 
		cin.ignore(); 
		if (spritesInRow <= 0) 
			{
			cout << "wrong input, terminating";
			return false; 
			}

		cout << "\nEnter Number of Columns: ";
		cin >> spritesInColumn; 
		cin.ignore();
		if (spritesInColumn <= 0)
		{
			cout << "wrong input, terminating";
			return false;
		}
	InitializeSFML();
	return true; 
	}
bool Program::InitializeSFML()
	{
	
	 
	if (!spriteSheetTexture.loadFromFile(texturePath)) return false;
	
	mAnimation = std::unique_ptr<Animation>(new Animation);
	mAnimation->GetSprite().setTexture(spriteSheetTexture);
	mAnimation->SetRectangleShapePosition();

	sf::Rect<float> imageRect = mAnimation->GetSprite().getGlobalBounds();
	SpriteWidth = (int)imageRect.width / spritesInRow; 
	SpriteHeight = (int)imageRect.height / spritesInColumn; 
	mAnimation->SetSpriteRectangle(SpriteWidth, SpriteHeight);
	mAnimation->SetSpritePosition(sf::Vector2f( ( (imageRect.width / 2) - (SpriteWidth/2)),
											    ( (imageRect.height / 2) - (SpriteHeight / 2) ) ) );

	imageRect.width += mAnimation->GetRectShape().getSize().x;
	WindowWidth = (int)imageRect.width;
	WindowHeight = (int)imageRect.height; 
	cout << "Window Width: " << WindowWidth << "\n"; 
	cout << "Window Height" << WindowHeight << "\n";
    mRenderWindow.create(sf::VideoMode(WindowWidth, WindowHeight), "AnimatonDisplayer v.01");



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
		mRenderWindow.clear(sf::Color::Blue);
		mRenderWindow.draw(mAnimation->GetSprite());
		mRenderWindow.draw(mAnimation->GetRectShape());
		mRenderWindow.display();
		} // end of main loop

	mConfigLoader.WriteToXML(texturePath, WindowWidth, WindowHeight, spritesInRow, spritesInColumn);
	return 0; 
	}
