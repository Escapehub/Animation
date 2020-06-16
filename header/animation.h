#ifndef ANI_H
#define ANI_H
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation();
    virtual ~Animation();
    sf::Sprite getSprite();
    void addAnimation(sf::IntRect);
    void setAnimationSpeed(float);
    void setEndFrame(int);
private:
    sf::Clock clock;
    int endFrame;
    float animationSpeed;
protected:
    void update(int);
    std::vector<sf::IntRect> Animations;
    sf::Sprite _sprite;
};

#endif