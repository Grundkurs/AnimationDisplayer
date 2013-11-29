#include "Animation.h"


Animation::Animation()
{
	mMenuRect.setSize(sf::Vector2f(40.f, 400.f));
	mMenuRect.setFillColor(sf::Color::Yellow);
	mMenuRect.setPosition(300.f, 0.f);
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