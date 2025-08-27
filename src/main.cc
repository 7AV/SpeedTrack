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
        float rotationSpeed = 180.f;

        car.handleInput(deltaTime, rotationSpeed);

        // --- Collision ---
        sf::Vector2f pos = car.getPosition();
        sf::Vector2f halfSize(car.getSize().x / 2.f, car.getSize().y / 2.f);

        // Clamp to window boundaries
        pos.x = std::clamp(pos.x, halfSize.x, 800.f - halfSize.x);
        pos.y = std::clamp(pos.y, halfSize.y, 600.f - halfSize.y);

        car.setPosition(pos);
        //============================================================================================================================================================

        window.clear(sf::Color::Green);  // background
        track.draw(window);
        car.draw(window);
        window.display();
    }

    return 0;
}
