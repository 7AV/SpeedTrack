#pragma once
#include <SFML/Graphics.hpp>

class Car
{
    public:
        Car();
        void handleInput(float deltaTime);
        void draw(sf::RenderWindow& window);
        sf::FloatRect getBounds() const;
        sf::Vector2f getPosition() const;
        void setPosition(const sf::Vector2f& pos);
        void move(const sf::Vector2f& offset);
        float getSpeed() const;

    private:
        sf::RectangleShape shape;
        float speed;
};