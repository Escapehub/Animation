#ifndef PLAYER_H
#define PLAYER_H
#include "animation.h"
#include <string>

class Player : public Animation
{
private:
    float _speed;
    
public: 
    Player(sf::Texture&);
    void setSpeed(float);
    enum Direction {Up, Down, Left, Right};
    void Move(Direction);
    void Adjust(Direction);
};
#endif