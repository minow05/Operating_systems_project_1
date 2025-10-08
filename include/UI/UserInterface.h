#ifndef PWR_AIZO_PROJECT1_USERINTERFACE_H
#define PWR_AIZO_PROJECT1_USERINTERFACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Checkbox.h"
#include <iostream>
#include "SlideBar.h"
#include "CheckboxGroup.h"
#include "Dropdown.h"
#include "Button.h"


#define WINDOW_SIZE 800


class UserInterface {
public:
    explicit UserInterface();
    Checkbox checkbox;
    SlideBar sizeBar;
    Dropdown algorithmsDropdown;
    Dropdown datatypeDropdown;
    Dropdown dataFormatDropdown;
    Button runButton;
private:
    sf::Font font;
    sf::Text checkBoxLabel = sf::Text(font, "Slow Mode", 12);
    sf::Text sizeBarLabel = sf::Text(font, "Size", 12);
    sf::Text sizeBarValue = sf::Text(font, "0", 12);
    sf::RenderWindow window;
    void run();
};

#endif //PWR_AIZO_PROJECT1_USERINTERFACE_H