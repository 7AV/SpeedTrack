#pragma once
#include <SFML/Graphics.hpp>

class Car
{
    public:

        // Constructor(s)
        Car();

        // Methods
        void handleInput(float deltaTime, float rotationSpeed);      
        void draw(sf::RenderWindow& window);
        void move(const sf::Vector2f& offset);
        void rotate(float angle);

        // Getters
        sf::Vector2f getDirection() const;  
        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;
        sf::FloatRect getBounds() const;
        float getSpeed() const;
        
        // Setters
        void setPosition(const sf::Vector2f& pos);


    private:        
        sf::RectangleShape shape;
        sf::Sprite sprite;
        sf::Texture texture;
        float acceleration;
        float maxSpeed;
        float velocity;
};