#include "Animation.h"
#include "Program.h"
#include <iostream>

Animation::Animation(Program* pProgram)
:
mpProgram(pProgram),
canPress(true),
mframeChangeAmount(0.00005f),
mframeRate(0.15f),
mframeCounter(0.f),
minRow{0},
mTotalColumns(pProgram->GetSpritesInColumn()),
mTotalRows(pProgram->GetSpritesInRow()),
mSingleAnimationRows(pProgram->GetSingleAnimationRows()),
mCurrentRow(minRow)
{
	maxRow = minRow + mSingleAnimationRows;
	mCurrentRow = minRow; 
}


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
			mCurrentRow++;
            }
		if (mCurrentRow > (maxRow -1))
			{
			mCurrentColumn = 0;
			mCurrentRow = minRow; 
			}

        }

	mSprite.setTextureRect(sf::Rect<int>(mSpriteWidth * mCurrentColumn, //X-position within spriteSheet
										 mSpriteHeight * mCurrentRow, //Y-Position within spriteSheet
										 mSpriteWidth, //width of displayed sprite within spriteSheet
										 mSpriteHeight)); //height of displayed sprite within spriteSheet


    //user input
    if(mpProgram->mInputControl.CanPress())
        {


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) mframeRate -= mframeChangeAmount; //fasten up

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) mframeRate += mframeChangeAmount; //slow down

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
            short result =  minRow - mSingleAnimationRows;
			if (result < 0) return;
				
			mCurrentRow = minRow = result; 
			maxRow = minRow + mSingleAnimationRows;
			
			mpProgram->mInputControl.Reset();
			}
			
            
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
			short result = minRow + mSingleAnimationRows;            
			if (result > (mTotalRows - 1)) return;

			mCurrentRow = minRow = result; 
			maxRow = minRow + mSingleAnimationRows;

			mpProgram->mInputControl.Reset();
            }

        } //end of if(canPress)



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
