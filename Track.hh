#pragma once
#include <SFML/Graphics.hpp>

class Track
{
    public:
        Track();
        void draw(sf::RenderWindow& window);
        const sf::RectangleShape& getOuter() const;
        const sf::RectangleShape& getInner() const;
        bool isInsideTrack(const sf::FloatRect& carBounds) const;

    private:
        sf::RectangleShape outer;
        sf::RectangleShape inner;

};