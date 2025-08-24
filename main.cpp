#include <SFML/Graphics.hpp>
#include "Car.hh"
#include "Track.hh"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Racing Game");
    window.setFramerateLimit(60);

//============================================================================================================================================================
/// Instantiate Objects
//============================================================================================================================================================    

    Car car;
    Track track;
    sf::Clock clock;     // for frame timing

//============================================================================================================================================================
    

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();         // Time since last frame

        //============================================================================================================================================================
        /// Movement & collision control
        //============================================================================================================================================================        
        float rotationSpeed = 120.f;
        float speed = car.getSpeed();

        // --- Rotate ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            car.rotate(-rotationSpeed * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            car.rotate(rotationSpeed * deltaTime);

        // --- Movement ---
        sf::Vector2f dir = car.getDirection();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            car.move(dir * car.getSpeed() * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            car.move(-dir * car.getSpeed() * deltaTime);
                
        // --- Collision ---

        //============================================================================================================================================================

        window.clear(sf::Color::Green);  // background
        track.draw(window);
        car.draw(window);
        window.display();
    }

    return 0;
}
