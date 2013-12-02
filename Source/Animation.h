#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML\Graphics.hpp>
class Animation
{
public:
	Animation();
	~Animation();


    void					Update(const sf::Time& elapsedTime);
	void					Draw();
	void					SetRectangleShapePosition();
	void					SetSpriteRectangle(int spriteWidth, int spriteHeight);
	void					SetSpritePosition(sf::Vector2f pos); 
	sf::RectangleShape&		GetRectShape();
	sf::Sprite&				GetSprite();
	
private: 
	sf::RectangleShape		mMenuRect; 
	sf::Sprite				mSprite;
	float					mframeRate;
	float					mframeCounter; 
    int                     mTotalColumns;
    int                     mTotalRows;
    int                     mSpriteWidth;
    int                     mSpriteHeight;
    int                     mCurrentColumn;
    int                     mCurrentRow;
 
};

#endif //ANIMATION_H
