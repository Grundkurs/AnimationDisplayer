#include "Animation.h"


Animation::Animation()
    :
      mframeRate(0.f),
      mframeCounter(0.f)
{
	mMenuRect.setSize(sf::Vector2f(50.f, 400.f));
	mMenuRect.setFillColor(sf::Color::Yellow);
}


Animation::~Animation()
{
}



void Animation::Update(const sf::Time& elapsedTime)
    {
    //stops Animation
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return;


    mframeCounter += elapsedTime.asSeconds();
    if(mframeCounter > mframeRate)
        {
        mframeCounter = 0.f;





        }


    }
void Animation::Draw(){}

sf::RectangleShape& Animation::GetRectShape(){ return mMenuRect;  }
sf::Sprite& Animation::GetSprite() 
{
	return mSprite; 
}

void Animation::SetRectangleShapePosition()
{
	mMenuRect.setPosition(sf::Vector2f(mSprite.getGlobalBounds().width, 0.f));
}

void Animation::SetSpriteRectangle(int spriteWidth, int spriteHeight)
{
    //when setting TextureRect, tell the class what size the Sprites will have
    mSpriteWidth = spriteWidth;
    mSpriteHeight = spriteHeight;
    mSprite.setTextureRect(sf::Rect<int>((mCurrentColumn * spriteWidth), //X-position within spriteSheet
                                         (mCurrentRow * spriteHeight), //Y-Position within spriteSheet
                                          spriteWidth, //width of displayed sprite within spriteSheet
                                          spriteHeight)); //height of displayed sprite within spriteSheet
}
void Animation::SetSpritePosition(sf::Vector2f pos)
{
	mSprite.setPosition(pos); 
}
