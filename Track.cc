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
