#include <SFML/Graphics.hpp>
#include <iostream>
#include "header/player.h"
#include "header/menu.h"
#include "header/tilemap.h"

bool IsPlaying = false;
bool HasKey = false;

int main() {
  float width = 512;
  float height = 256;
  sf::RenderWindow window(sf::VideoMode(512,256), "SFML Base");
  sf::Event event;

  // Menu
  Menu menu(window.getSize().x, window.getSize().y);

  // Player
  sf::Texture playerTexture;
  playerTexture.loadFromFile("sprites/character.png");
  Player player(playerTexture);
  player.setEndFrame(192);
  player.setAnimationSpeed(.1f);
  player.setSpeed(.1f);
  player.setPos(sf::Vector2f(window.getSize().x / 2, window.getSize().y /2));
  player.addAnimation(sf::IntRect(0, 192, 64, 64)); // up
  player.addAnimation(sf::IntRect(0, 0, 64, 64)); // down
  player.addAnimation(sf::IntRect(0, 64, 64, 64)); // left
  player.addAnimation(sf::IntRect(0, 128, 64, 64)); // right

  // Collision Blocks
  sf::RectangleShape r;
  r.setSize(sf::Vector2f(100.f, 100.f));
  r.setPosition(sf::Vector2f(500.f,500.f));

  // Pickup
  sf::Texture keyTexture;
  keyTexture.loadFromFile("sprites/keyicons.png");
  sf::Sprite key(keyTexture, sf::IntRect(32, 0, 32, 32));
  key.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
  sf::Font font;
  font.loadFromFile("fonts/arcade.ttf");
  sf::Text havekey;
  havekey.setFont(font);
  havekey.setString("You have the key!");
  havekey.setCharacterSize(50);
  havekey.setPosition(sf::Vector2f(window.getSize().x / 3.5, 0)); // Top center of the screen


  // create the tilemap from the level definition
  TileMap map;
  int levelone[] =
  {
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
    0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
    2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
    0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
  };
  int leveltwo[] =
  {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  int levelthree[] =
  {
    0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
    0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 2,
  };
  int* levels[] = {levelone, leveltwo, levelthree};
  if (!map.load("sprites/tileset.png", sf::Vector2u(32, 32), levels[2], 16, 8))
    return -1;

  while (window.isOpen()) {
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed)
        window.close();

        switch (event.type)
        {
          case sf::Event::KeyReleased:
          switch (event.key.code)
          {
            case sf::Keyboard::Up:
            menu.moveUp();
            break;
            case sf::Keyboard::Down:
            menu.moveDown();
            break;
            case sf::Keyboard::Return:
            switch (menu.GetPressedItem())
            {
              case 0:
              IsPlaying = true;
              break;
              case 1:
              std::cout << "Option pressed" << std::endl;
              break;
              case 2:
              window.close();
              break;
            }
            break;
          }
          break;
        }
      }

      // Pick up detection
      window.clear();
      if (player.getSprite().getGlobalBounds().intersects(key.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        HasKey = true;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        IsPlaying = false;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        if (!player.getSprite().getGlobalBounds().intersects(r.getGlobalBounds()))
          player.Move(Player::Direction::Up);
        else
          player.Adjust(Player::Direction::Down);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        if (!player.getSprite().getGlobalBounds().intersects(r.getGlobalBounds()))
          player.Move(Player::Direction::Down);
        else
          player.Adjust(Player::Direction::Up);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        if (!player.getSprite().getGlobalBounds().intersects(r.getGlobalBounds()))
          player.Move(Player::Direction::Left);
        else
          player.Adjust(Player::Direction::Right);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        if (!player.getSprite().getGlobalBounds().intersects(r.getGlobalBounds()))
          player.Move(Player::Direction::Right);
        else
          player.Adjust(Player::Direction::Left);

      if (IsPlaying) {
        window.draw(map);
        window.draw(r);
        window.draw(player.getSprite());
        if (HasKey)
          window.draw(havekey);
        else
          window.draw(key);
      }
      else
        menu.Draw(window);

      window.display();
    }
  return 0;
}
