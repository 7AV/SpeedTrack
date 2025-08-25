#pragma once
#include <SFML/Graphics.hpp>

class Track
{
    public:
        Track();
        void draw(sf::RenderWindow& window) const;
        const sf::ConvexShape& getOuter() const;
        const sf::ConvexShape& getInner() const;
        bool isInsideTrack(const sf::FloatRect& carBounds) const;
        sf::Vector2f getConvexShapeSize(const sf::ConvexShape& shape);

    private:
        sf::ConvexShape outer;
        sf::ConvexShape inner;

};