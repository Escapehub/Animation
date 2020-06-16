#include "../header/player.h"

Player::Player(sf::Texture &texture) {
    _sprite.setTexture(texture);
}

void Player::setSpeed(float speed) {
    _speed = speed;
}

void Player::Move(Direction direction) {
    switch (direction){
        case Up:
            _sprite.move(0, -_speed);
            update(0);
            break;
        case Down:
            _sprite.move(0, _speed);
            update(1);
            break;
        case Left:
            _sprite.move(-_speed, 0);
            update(2);
            break;
        case Right:
            _sprite.move(_speed, 0);
            update(3);
            break;
    };
}

void Player::Adjust(Direction direction) {
    switch (direction){
        case Up:
            _sprite.move(0, -0.3f);
            break;
        case Down:
            _sprite.move(0, 0.3f);
            break;
        case Left:
            _sprite.move(-0.3f, 0);
            break;
        case Right:
            _sprite.move(0.3f, 0);
            break;
    };
}