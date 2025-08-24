#include "Car.hh"

Car::Car()
{
    // Car setup
    shape.setSize(sf::Vector2f(50.f, 30.f)); // width 50, height 30
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(375.f, 285.f);
    speed = 200.f;    // pixels per second 
}

void Car::handleInput(float deltaTime)
{
    // Input handling
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        shape.move(0.f, -speed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        shape.move(0.f, speed * deltaTime);        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        shape.move(-speed * deltaTime, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shape.move(speed * deltaTime, 0.f);
}

void Car::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::FloatRect Car::getBounds() const
{
    return shape.getGlobalBounds();
}

sf::Vector2f Car::getPosition() const
{
    return shape.getPosition();
}

void Car::setPosition(const sf::Vector2f& pos)
{
    return shape.setPosition(pos);
}

void Car::move(const sf::Vector2f& offset)
{
    return shape.move(offset);
}

float Car::getSpeed() const
{
    return speed;
}