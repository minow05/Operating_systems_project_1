//
// Created by minow on 12-Apr-25.
//

#ifndef PWR_AIZO_PROJECT1_BUTTON_H
#define PWR_AIZO_PROJECT1_BUTTON_H

#include "SFML/Graphics.hpp"

class Button {
public:
    Button() = default;
    Button(sf::Vector2f position, float height, float width, sf::Font& font, const std::string& name);

    void handleEvent(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    bool pressed = false;
private:
    void update();
    sf::Clock pressClock;
    sf::Font font;
    sf::Text text = sf::Text(font, "", 10);
    sf::RectangleShape box;
};


#endif //PWR_AIZO_PROJECT1_BUTTON_H
