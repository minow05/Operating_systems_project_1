#ifndef PWR_AIZO_PROJECT1_CHECKBOXGROUP_H
#define PWR_AIZO_PROJECT1_CHECKBOXGROUP_H

#include "Checkbox.h"

class CheckboxGroup {
public:
    CheckboxGroup() = default;
    explicit CheckboxGroup(std::vector<Checkbox> checkboxes, std::vector<sf::Text> labels);
    void handleEvent(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    Checkbox* getCheckedId();
    void addCheckbox(Checkbox& checkbox);
private:
    std::vector<Checkbox> checkboxes;
    std::vector<sf::Text> labels;
};
#endif //PWR_AIZO_PROJECT1_CHECKBOXGROUP_H
