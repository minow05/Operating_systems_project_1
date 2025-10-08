#ifndef PWR_AIZO_PROJECT1_SLIDEBAR_H
#define PWR_AIZO_PROJECT1_SLIDEBAR_H

#include <SFML/Graphics.hpp>
#include <DataGeneration.h>

class SlideBar {
public:
    SlideBar(sf::Vector2f position, float width, int minValue, int maxValue);

    SlideBar();

    void handleEvent(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    int getValue() const;
private:
    sf::RectangleShape bar;
    sf::CircleShape knob;
    int maxValue, minValue;
    int currentValue = 0;
};
#endif //PWR_AIZO_PROJECT1_SLIDEBAR_H
