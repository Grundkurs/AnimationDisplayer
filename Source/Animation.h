#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML\Graphics.hpp>
class Animation
{
public:
	Animation();
	~Animation();


	void Update();
	void Draw();


	sf::Sprite& GetSprite();
private: 

	sf::Sprite mSprite;
 
};

#endif //ANIMATION_H