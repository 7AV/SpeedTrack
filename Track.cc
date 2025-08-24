#include "Track.hh"

Track::Track()
{
    outer.setSize(sf::Vector2f(600.f, 400.f));
    outer.setFillColor(sf::Color::White);
    outer.setPosition(100.f, 100.f);

    inner.setSize(sf::Vector2f(500.f, 300.f));
    inner.setFillColor(sf::Color::Black);
    inner.setPosition(150.f, 150.f);
}

void Track::draw(sf::RenderWindow& window) 
{
    window.draw(outer);
    window.draw(inner);
}

const sf::RectangleShape& Track::getOuter() const
{
    return outer;
}

const sf::RectangleShape& Track::getInner() const
{
    return inner;
}

bool Track::isInsideTrack(const sf::FloatRect& carBounds) const {
    // Road is the area between outer and inner rectangles
    sf::FloatRect outerBounds = outer.getGlobalBounds();
    sf::FloatRect innerBounds = inner.getGlobalBounds();

    // Check if car is inside outer rectangle
    bool insideOuter = outerBounds.contains(carBounds.left, carBounds.top) &&
                       outerBounds.contains(carBounds.left + carBounds.width, carBounds.top) &&
                       outerBounds.contains(carBounds.left, carBounds.top + carBounds.height) &&
                       outerBounds.contains(carBounds.left + carBounds.width, carBounds.top + carBounds.height);

    // Check if car is outside inner rectangle
    bool outsideInner = !(innerBounds.contains(carBounds.left, carBounds.top) ||
                          innerBounds.contains(carBounds.left + carBounds.width, carBounds.top) ||
                          innerBounds.contains(carBounds.left, carBounds.top + carBounds.height) ||
                          innerBounds.contains(carBounds.left + carBounds.width, carBounds.top + carBounds.height));

    return insideOuter && outsideInner;
}
