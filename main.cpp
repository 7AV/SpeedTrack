#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Racing Game");
    window.setFramerateLimit(60);

    // Car setup
    sf::RectangleShape car(sf::Vector2f(50.f, 30.f)); // width 50, height 30
    car.setFillColor(sf::Color::Red);
    car.setPosition(375.f, 285.f);

    float speed = 200.f; // pixels per second
    sf::Clock clock;     // for frame timing

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Time since last frame
        float deltaTime = clock.restart().asSeconds();

        // Input handling
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            car.move(0.f, -speed * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            car.move(0.f, speed * deltaTime);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            car.move(-speed * deltaTime, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            car.move(speed * deltaTime, 0.f);


        window.clear(sf::Color::Blue);  // background
        window.draw(car);               // draw car
        window.display();
    }

    return 0;
}
