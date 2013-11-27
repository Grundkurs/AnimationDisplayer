#include "Animation.h"


Animation::Animation()
{
}


Animation::~Animation()
{
}



void Animation::Update(){}
void Animation::Draw(){}

sf::Sprite& Animation::GetSprite() 
{
	return mSprite; 
}