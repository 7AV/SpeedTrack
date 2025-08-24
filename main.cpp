#include <SFML/Graphics.hpp>
#include "Car.hh"
#include "Track.hh"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Racing Game");
    window.setFramerateLimit(60);

    Car car;
    Track track;

    sf::Clock clock;     // for frame timing
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Time since last frame
        float deltaTime = clock.restart().asSeconds();

        // Move the car
        car.handleInput(deltaTime);

        // Constrain car within track (simple rectangle logic)
        sf::FloatRect carBounds = car.getBounds();
        sf::FloatRect outer = track.getOuter().getGlobalBounds();
        sf::FloatRect inner = track.getInner().getGlobalBounds();

        // If car is outside the road area (between outer and inner)
        if (!(carBounds.intersects(inner) || !carBounds.intersects(outer)))
        {
            // Push the car back inside
            // This just moves it back one frame (can refine later)
            car.handleInput(-deltaTime);
        }

        window.clear(sf::Color::Green);  // background
        track.draw(window);
        car.draw(window);
        window.display();
    }

    return 0;
}
