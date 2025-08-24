#pragma once
#include <SFML/Graphics.hpp>

class Car
{
    public:
        Car();
        void handleInput(float deltaTime);
        void draw(sf::RenderWindow& window);
        sf::FloatRect getBounds() const;

    private:
        sf::RectangleShape shape;
        float speed;
};