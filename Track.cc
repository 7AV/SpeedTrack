#include "Track.hh"
#include <cmath>

Track::Track() 
{
    const size_t pointCount = 60; // more points = smoother curve
    const sf::Vector2f center(400.f, 300.f); // window center
    const float outerRx = 350.f;
    const float outerRy = 250.f;
    const float innerRx = 250.f;
    const float innerRy = 150.f;

    // --- Outer oval ---
    outer.setPointCount(pointCount);
    for (size_t i = 0; i < pointCount; ++i) {
        float angle = i * 2.f * M_PI / pointCount;
        float x = center.x + outerRx * std::cos(angle);
        float y = center.y + outerRy * std::sin(angle);
        outer.setPoint(i, sf::Vector2f(x, y));
    }
    outer.setFillColor(sf::Color(100, 100, 100)); // gray road

    // --- Inner oval ---
    inner.setPointCount(pointCount);
    for (size_t i = 0; i < pointCount; ++i) {
        float angle = i * 2.f * M_PI / pointCount;
        float x = center.x + innerRx * std::cos(angle);
        float y = center.y + innerRy * std::sin(angle);
        inner.setPoint(i, sf::Vector2f(x, y));
    }
    inner.setFillColor(sf::Color(0, 150, 0)); // grass
}

void Track::draw(sf::RenderWindow& window) const {
    window.draw(outer);
    window.draw(inner);
}

bool Track::isInsideTrack(const sf::FloatRect& carBounds) const {
    // Road is the area between outer and inner rectangles
    return carBounds.intersects(outer.getGlobalBounds()) &&  // check car is inside outer
           !carBounds.intersects(inner.getGlobalBounds());   // check car is not inside inner (grass)
}

const sf::ConvexShape& Track::getOuter() const
{
    return outer;
}

const sf::ConvexShape& Track::getInner() const
{
    return inner;
}

sf::Vector2f Track::getConvexShapeSize(const sf::ConvexShape& shape)
{
    if (shape.getPointCount() == 0)
        return sf::Vector2f(0.f, 0.f);

    float minX = shape.getPoint(0).x;
    float maxX = shape.getPoint(0).x;
    float minY = shape.getPoint(0).y;
    float maxY = shape.getPoint(0).y;

    for (size_t i = 1; i < shape.getPointCount(); ++i) {
        sf::Vector2f p = shape.getPoint(i);
        if (p.x < minX) minX = p.x;
        if (p.x > maxX) maxX = p.x;
        if (p.y < minY) minY = p.y;
        if (p.y > maxY) maxY = p.y;
    }

    return sf::Vector2f(maxX - minX, maxY - minY);
}