#include "Animation.h"
#include "Program.h"
#include <iostream>

Animation::Animation(Program* pProgram)
:
mpProgram(pProgram),
canPress(true),
mframeChangeAmount(0.00005f),
mframeRate(0.30f),
mframeCounter(0.f),
mTotalColumns(pProgram->GetSpritesInColumn()),
mTotalRows(pProgram->GetSpritesInRow()),
mCurrentColumn(0),
mCurrentRow(0)
{}


Animation::~Animation()
{
}



void Animation::Update(const sf::Time& elapsedTime)
    {
    //pressing Space holds animation
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return;


    mframeCounter += elapsedTime.asSeconds();
    if(mframeCounter > mframeRate)
        {
        mframeCounter = 0.f;
        mCurrentColumn++;
        if(mCurrentColumn >= mTotalColumns)
            {
            mCurrentColumn = 0;
            }

        }



    //user input
    if(mpProgram->mInputControl.CanPress())
        {


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) mframeRate -= mframeChangeAmount; //fasten up

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) mframeRate += mframeChangeAmount; //slow down

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
            if(mCurrentRow > 0 ) --mCurrentRow;
            mpProgram->mInputControl.Reset();

            }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
            if(mCurrentRow < (mpProgram->GetSpritesInRow() - 1 )) ++mCurrentRow;
            mpProgram->mInputControl.Reset();
            }

        } //end of if(canPress)

    mSprite.setTextureRect(sf::Rect<int>(mSpriteWidth * mCurrentColumn, //X-position within spriteSheet
                                         mSpriteHeight * mCurrentRow, //Y-Position within spriteSheet
                                         mSpriteWidth, //width of displayed sprite within spriteSheet
                                         mSpriteHeight)); //height of displayed sprite within spriteSheet

    } // end of update

void Animation::Draw(){}

sf::RectangleShape& Animation::GetRectShape(){ return mMenuRect;  }
sf::Sprite& Animation::GetSprite() 
{
	return mSprite; 
}

void Animation::SetMenuRectShape()
{
	mMenuRect.setPosition(sf::Vector2f(mSprite.getGlobalBounds().width, 0.f));
	mMenuRect.setSize(sf::Vector2f(200.f, mSprite.getGlobalBounds().height));
	mMenuRect.setFillColor(sf::Color::Yellow);
}

void Animation::SetSpriteRectangle(int spriteWidth, int spriteHeight)
{
    //when setting TextureRect, tell the class what size the Sprites will have
    mSpriteWidth = spriteWidth;
    mSpriteHeight = spriteHeight;
	
	mSprite.setTextureRect(sf::Rect<int>(mSpriteWidth * mCurrentColumn, //X-position within spriteSheet
										 mSpriteHeight * mCurrentRow, //Y-Position within spriteSheet
                                        mSpriteWidth, //width of displayed sprite within spriteSheet
                                        mSpriteHeight)); //height of displayed sprite within spriteSheet
}
void Animation::SetSpritePosition(sf::Vector2f pos)
{
	mSprite.setPosition(pos); 
}
