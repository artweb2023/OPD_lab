#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangles and circle");

    sf::ConvexShape triangle;
    triangle.setFillColor(sf::Color(0xFF,0x80,0x0));
    triangle.setPosition(200,120);
    triangle.setPointCount(3);
    triangle.setPoint(0,sf::Vector2f(50, -20));
    triangle.setPoint(1,sf::Vector2f(50, 20));
    triangle.setPoint(2,sf::Vector2f(-100, 0));

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    trapeze.setPosition(400, 300);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, sf::Vector2f(-90, 0));
    trapeze.setPoint(1, sf::Vector2f(90, 0));
    trapeze.setPoint(2, sf::Vector2f(120, 60));
    trapeze.setPoint(3, sf::Vector2f(-120, 60));




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(triangle);
        window.draw(trapeze);
        window.display();
    }

    return 0;
}