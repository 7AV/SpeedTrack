#include "Car.hh"
#include <cmath>
#include <iostream>

Car::Car()
{
    // Car setup
    shape.setSize(sf::Vector2f(50.f, 30.f)); // width 50, height 30
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(375.f, 285.f);
    shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f); // This ensures rotation happens around the middle of the car
    
    acceleration = 300.f;
    maxSpeed = 500.f;    // pixels per second 
    velocity = 0.f;
}

void Car::handleInput(float deltaTime, float rotationSpeed)
{
    // Rotate
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        rotate(-rotationSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        rotate(rotationSpeed * deltaTime);

    // Accelerate / Decelerate
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity += acceleration * deltaTime;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocity -= acceleration * deltaTime;
    else
        velocity *= 0.95f; // friction

    // Clamp velocity
    if (velocity > maxSpeed)
        velocity = maxSpeed;
    if (velocity < -maxSpeed)
        velocity = -maxSpeed;

    // Move along facing direction
    sf::Vector2f dir = getDirection();
    sf::Vector2f movement(dir.x * velocity * deltaTime, dir.y * velocity * deltaTime);
    shape.move(movement);    

    // Debugging
    //std::cout << "Velocity: " << velocity << '\n';
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

sf::Vector2f Car::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f Car::getSize() const
{
    return shape.getSize();
}

sf::FloatRect Car::getBounds() const
{
    return shape.getGlobalBounds();
}

float Car::getSpeed() const
{
    return velocity;
}

//============================================================================================================================================================
// SETTERS
//============================================================================================================================================================

void Car::setPosition(const sf::Vector2f& pos)
{
    shape.setPosition(pos);
}
