#include "Program.h"
#include <iostream>
#include <string>
#include <memory>
#include <io.h>
using std::cout;
using std::cin; 
#define R_OK 4
Program::Program()
{
    elapsedTime.restart();
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

    //in fact redunant, but to avoid compiler-warning
    return false;

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
	singleAnimationRows = mConfigLoader.GetSingleAnimationRows(); 
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
        if(fileName.empty())
            {
            cout << "error. no input\n";
            continue;
            }
		texturePath = "..//Resources//";
		texturePath.append(fileName);
		if (_access(texturePath.c_str(), R_OK) == -1)
			{
			//error
			cout << "no such File found!\n";
			}else{ foundFile = true; }
			
	} while (!foundFile);
	
        cout << "file found. Enter Number of Sprites in Column: ";
        cin >> spritesInColumn;
		cin.ignore(); 
        if (spritesInColumn <= 0)
			{
			cout << "wrong input, terminating";
			return false; 
			}

        cout << "\nEnter Number of Rows: ";
        cin >> spritesInRow;
		cin.ignore();
        if (spritesInRow <= 0)
			{
			cout << "wrong input, terminating";
			return false;
			}
		cout << "\nEnter Number of Rows needed for single Animation in SpriteSheet: ";
		cin >> singleAnimationRows;
		cin.ignore();
	InitializeSFML();
	return true; 
	}
bool Program::InitializeSFML()
	{
	
	 
	if (!spriteSheetTexture.loadFromFile(texturePath)) return false;
	if (!font.loadFromFile("..//Resources//times.ttf")) 
		{
		cout << "no font loaded"; 
		return false; 
		}


	
    mAnimation = std::unique_ptr<Animation>(new Animation(this));
	mAnimation->GetSprite().setTexture(spriteSheetTexture);
	mAnimation->SetMenuRectShape();

	sf::Rect<float> imageRect = mAnimation->GetSprite().getGlobalBounds();
    SpriteWidth = (int)imageRect.width / spritesInColumn;
    SpriteHeight = (int)imageRect.height / spritesInRow;
	mAnimation->SetSpriteRectangle(SpriteWidth, SpriteHeight);
	mAnimation->SetSpritePosition(sf::Vector2f( ( (imageRect.width / 2) - (SpriteWidth/2)),
											    ( (imageRect.height / 2) - (SpriteHeight / 2) ) ) );

	imageRect.width += mAnimation->GetRectShape().getSize().x;
	WindowWidth = (int)imageRect.width;
	WindowHeight = (int)imageRect.height; 
	cout << "Window Width: " << WindowWidth << "\n"; 
	cout << "Window Height" << WindowHeight << "\n";

    //create Text
	float TextPos = 0.f; 
	float offSet = imageRect.height / 4; 
    sf::Text newText;
    newText.setString(std::string("Arrow Up\n = increase Animation-Speed"));
    newText.setCharacterSize(15);
    newText.setColor(sf::Color::Black);
    newText.setFont(font);
	newText.setPosition(sf::Vector2f(mAnimation->GetRectShape().getGlobalBounds().left, TextPos));
    text.push_back(newText);

	TextPos += offSet; 
	newText.setString(std::string("Arrow Down\n = decrease Animation-Speed"));
	newText.setPosition(sf::Vector2f(mAnimation->GetRectShape().getGlobalBounds().left, TextPos));
	text.push_back(newText);

	TextPos += offSet; 
	newText.setString(std::string("Arrow Left\n = upper Row"));
	newText.setPosition(sf::Vector2f(mAnimation->GetRectShape().getGlobalBounds().left, TextPos));
	text.push_back(newText);

	TextPos += offSet;
	newText.setString(std::string("Arrow Right\n = lower Row"));
	newText.setPosition(sf::Vector2f(mAnimation->GetRectShape().getGlobalBounds().left, TextPos));
	text.push_back(newText);

    mRenderWindow.create(sf::VideoMode(WindowWidth, WindowHeight), "AnimatonDisplayer v.01");



	return true;
	}

void Program::ProcessHandle(sf::Event& event)
{
    switch(event.type)
    {
    case (sf::Event::KeyPressed):
        {
        mInputControl.Reset();
        }
    default:{}
    }


}
int	Program::Run()
	{
    //save all files before shooting main Loop
    mConfigLoader.WriteToXML(texturePath, WindowWidth, WindowHeight, spritesInRow, spritesInColumn, singleAnimationRows);

    sf::Event event;

    sf::Time now = elapsedTime.getElapsedTime();
    sf::Time last = now;

	//main program loop
	while (mRenderWindow.isOpen()) 
		{
            now = elapsedTime.getElapsedTime();
            mframeDelta = now - last;
            last = now;

		while (mRenderWindow.pollEvent(event))
			{
			if (event.type == sf::Event::Closed) mRenderWindow.close();
			}



        mInputControl.Update(mframeDelta);
        mAnimation->Update(mframeDelta);
		mRenderWindow.clear(sf::Color::Blue);
		mRenderWindow.draw(mAnimation->GetSprite());
		mRenderWindow.draw(mAnimation->GetRectShape());
        for(auto& i : text)
            {
            mRenderWindow.draw(i);
            }
		mRenderWindow.display();
		} // end of main loop

	return 0; 
	}


short Program::GetSpritesInColumn() const{return spritesInColumn;}
short Program::GetSpritesInRow() const{ return spritesInRow;}

short Program::GetSingleAnimationRows(){ return singleAnimationRows; }