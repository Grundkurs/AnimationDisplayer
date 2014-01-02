#ifndef PROGRAM_H
#define PROGRAM_H
#include <SFML\Graphics.hpp>
#include <memory>
#include "ConfigLoader.h"
#include "Animation.h"
#include <vector>
class InputControl
    {

    float mPressRate = 0.2f;
    float mCounter = 0.f;
public:
    void Update(const sf::Time& elapsedTime) { mCounter += elapsedTime.asSeconds();}
    void Reset() {mCounter = 0.f; }
    bool CanPress()
        {
        return mCounter > mPressRate ? true : false;
        }

    };


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
            short							GetSpritesInColumn() const;
            short                           GetSpritesInRow() const;
			short							GetSingleAnimationRows(); 
            InputControl                    mInputControl;


private:
			int								WindowWidth;
			int								WindowHeight; 
			int								SpriteWidth; 
			int								SpriteHeight; 
			short							spritesInRow;
			short							spritesInColumn; 
			short							singleAnimationRows; 
			std::unique_ptr<Animation>		mAnimation;
			sf::RenderWindow				mRenderWindow;
			ConfigLoader					mConfigLoader; 

			std::string						texturePath; 
			sf::Texture						spriteSheetTexture; 

            sf::Font                        font;
            std::vector<sf::Text>           text;

            sf::Time                        mframeDelta;
            sf::Clock                       elapsedTime;
};


#endif //PROGRAM_H
