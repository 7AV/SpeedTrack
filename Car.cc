#include "Car.hh"
#include <cmath>


Car::Car()
{
    // Car setup
    shape.setSize(sf::Vector2f(50.f, 30.f)); // width 50, height 30
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(375.f, 285.f);
    shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f); // This ensures rotation happens around the middle of the car
    speed = 200.f;    // pixels per second 
}

void Car::handleInput(float deltaTime)
{
    // Input handling
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        shape.move(0.f, speed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        shape.move(0.f, -speed * deltaTime);        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        shape.move(-speed * deltaTime, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shape.move(speed * deltaTime, 0.f);
}

void Car::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Car::move(const sf::Vector2f& offset)
{
    shape.move(offset);
}

void Car::rotate(float angle)
{
    shape.rotate(angle);
}


//============================================================================================================================================================
// GETTERS
//============================================================================================================================================================

sf::Vector2f Car::getDirection() const
{
    float pi = M_PI;
    float rad = shape.getRotation() * pi / 180.f;
    return sf::Vector2f(std::cos(rad), std::sin(rad));
}

sf::FloatRect Car::getBounds() const
{
    return shape.getGlobalBounds();
}

sf::Vector2f Car::getPosition() const
{
    return shape.getPosition();
}

float Car::getSpeed() const
{
    return speed;
}


//============================================================================================================================================================
// SETTERS
//============================================================================================================================================================

void Car::setPosition(const sf::Vector2f& pos)
{
    shape.setPosition(pos);
}
