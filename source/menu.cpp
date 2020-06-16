#include "../header/menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("fonts/arcade.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }

    title.setFont(font);
    title.setCharacterSize(200);
    title.setFillColor(sf::Color::White);
    title.setString("MAZE GAME");
    title.setPosition(sf::Vector2f(width / 3, 0));

    menu[0].setFont(font);
    menu[0].setCharacterSize(100);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setCharacterSize(100);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setCharacterSize(100);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Menu::~Menu() {

}

void Menu::Draw(sf::RenderWindow &window) {
    window.draw(title);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

void Menu::moveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}