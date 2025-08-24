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

        // --- Movement ---
        sf::Vector2f move(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
            move.x -= car.getSpeed() * deltaTime; 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            move.x += car.getSpeed() * deltaTime;        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
            move.y -= car.getSpeed() * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
            move.y += car.getSpeed() * deltaTime;
        
        car.move(move);

        // --- Collision ---

//============================================================================================================================================================

        window.clear(sf::Color::Green);  // background
        track.draw(window);
        car.draw(window);
        window.display();
    }

    return 0;
}
