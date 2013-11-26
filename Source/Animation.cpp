#include "Animation.h"


Animation::Animation()
{
}


Animation::~Animation()
{
}



void Animation::Update(){}
void Animation::Draw(){}

const sf::Sprite& Animation::GetSprite() const
{
	return mSprite; 
}