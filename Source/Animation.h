#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML\Graphics.hpp>

class Program;


class Animation
{
public:
    Animation(Program* pProgram);
	~Animation();


    void					Update(const sf::Time& elapsedTime);
	void					Draw();
	void					SetMenuRectShape();
	void					SetSpriteRectangle(int spriteWidth, int spriteHeight);
	void					SetSpritePosition(sf::Vector2f pos); 
	sf::RectangleShape&		GetRectShape();
	sf::Sprite&				GetSprite();
	
private: 
    Program*                mpProgram;
    bool                    canPress;
	sf::RectangleShape		mMenuRect; 
	sf::Sprite				mSprite;

    float                   mframeChangeAmount;
	float					mframeRate;
	float					mframeCounter; 
    int                     mTotalColumns;
	short					minRow; 
	short					maxRow; 
	short					startRow; 
	short					mSingleAnimationRows;
    short					mTotalRows;
    short					mSpriteWidth;
    short					mSpriteHeight;
    short					mCurrentColumn;
    short                     mCurrentRow;
 
};

#endif //ANIMATION_H
