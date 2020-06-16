#include "../header/animation.h"

Animation::Animation() {

}

Animation::~Animation() {

}

sf::Sprite Animation::getSprite() {
    return _sprite;
}

void Animation::setAnimationSpeed(float speed) {
    animationSpeed = speed;
}

void Animation::setEndFrame(int endframe) {
    endFrame = endframe;
}

void Animation::addAnimation(sf::IntRect animation) {
    Animations.push_back(animation);
}

void Animation::update(int animation) {
    if (clock.getElapsedTime().asSeconds() > animationSpeed) {
        if (Animations[animation].left == endFrame) 
            Animations[animation].left = 0;
        else 
            Animations[animation].left += 64;
        
        _sprite.setTextureRect(Animations[animation]);
        clock.restart();
    }
}