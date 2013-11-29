#include "Animation.h"


Animation::Animation()
{
	mMenuRect.setSize(sf::Vector2f(50.f, 400.f));
	mMenuRect.setFillColor(sf::Color::Yellow);
}


Animation::~Animation()
{
}



void Animation::Update(){}
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
	mSprite.setTextureRect(sf::Rect<int>(0,0,spriteWidth, spriteHeight));
}
void Animation::SetSpritePosition(sf::Vector2f pos)
{
	mSprite.setPosition(pos); 
}