#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    const int pointCount = 200;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(800, 600), "Polar Rose",
        sf::Style::Default, settings);

    sf::ConvexShape rose;
    rose.setPosition(400, 320);
    rose.setFillColor(sf::Color(0xFF, 0x09, 0x80));
    rose.setPointCount(pointCount);

    sf::Vector2f position(400, 200);
    sf::Clock clock;
    float angle = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        for (int pointNo = 0; pointNo < pointCount; pointNo++)
        {
            float angle = float(2 * M_PI * pointNo) / float(pointCount);
            float radius = 200 * sin(6 * angle);
            sf::Vector2f point(
                radius * std::sin(angle),
                radius * std::cos(angle));
            rose.setPoint(pointNo, point);
        }
        float deltaTime = clock.restart().asSeconds();
        angle += 0.01;
        position.x += deltaTime + std::cos(angle);
        position.y += std::sin(angle);
        rose.setPosition(position);

        window.clear();
        window.draw(rose);
        window.display();
    }

    return 0;
}