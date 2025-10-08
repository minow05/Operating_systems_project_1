
#ifndef PWR_AIZO_PROJECT1_DROPDOWN_H
#define PWR_AIZO_PROJECT1_DROPDOWN_H

#include <SFML/Graphics.hpp>

class Dropdown {
private:
    sf::RectangleShape box;
    sf::Font font;
    sf::Text selectedText = sf::Text(font, " ", 20);
    std::vector<sf::Text> options;
    std::vector<sf::RectangleShape> optionBoxes;
    bool expanded = false;
    int selectedIndex = 0;


public:
    Dropdown(sf::Vector2f position, float width, float height, const std::vector<std::string>& items, sf::Font &font);
    Dropdown() = default;

    void handleEvent(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);


    std::string getSelected() const;
};


#endif //PWR_AIZO_PROJECT1_DROPDOWN_H
