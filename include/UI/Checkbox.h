#ifndef PWR_AIZO_PROJECT1_CHECKBOX_H
#define PWR_AIZO_PROJECT1_CHECKBOX_H

#include <SFML/Graphics.hpp>

class Checkbox{
public:
    Checkbox();
    explicit Checkbox(sf::Vector2f position);

    void handleEvent(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    bool checked;
private:
    sf::RectangleShape box;
    sf::RectangleShape checkMark;

};

#endif //PWR_AIZO_PROJECT1_CHECKBOX_H
