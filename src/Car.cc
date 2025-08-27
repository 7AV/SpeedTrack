#include "Car.hh"
#include <cmath>
#include <iostream>

Car::Car()
{
    // Car setup
    // shape.setSize(sf::Vector2f(50.f, 30.f)); // width 50, height 30
    // shape.setFillColor(sf::Color::Red);
    // shape.setPosition(375.f, 285.f);
    // shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f); // This ensures rotation happens around the middle of the car
    
    // Load car texture
    if (!texture.loadFromFile("assets/f1.png"))
    {
        // Handle error
        std::cerr << "Failed to load car texture!" << std::endl;
    }

    sprite.setTexture(texture);
    sf::Vector2u texSize = texture.getSize();
    sprite.setPosition(400.f, 300.f); // Start position
    sprite.setRotation(90.f);
    sprite.setOrigin(texSize.x / 2.f, texSize.y / 2.f);
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
    sprite.move(movement);    

    // Debugging
    //std::cout << "Velocity: " << velocity << '\n';
}


void Car::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Car::move(const sf::Vector2f& offset)
{
    sprite.move(offset);
}

void Car::rotate(float angle)
{
    sprite.rotate(angle);
}


//============================================================================================================================================================
// GETTERS
//============================================================================================================================================================

sf::Vector2f Car::getDirection() const
{
    float pi = M_PI;
    float rad = sprite.getRotation() * pi / 180.f;
    return sf::Vector2f(std::cos(rad), std::sin(rad));
}

sf::Vector2f Car::getPosition() const
{
    return sprite.getPosition();
}

sf::Vector2f Car::getSize() const
{
    sf::FloatRect bounds = sprite.getLocalBounds();
    return sf::Vector2f(bounds.width, bounds.height);
    //return shape.getSize();
}

sf::FloatRect Car::getBounds() const
{
    return sprite.getGlobalBounds();
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
    sprite.setPosition(pos);
}
