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


const sf::Sprite& GetSprite() const; 
private: 

	sf::Sprite mSprite;
 
};

#endif //ANIMATION_H