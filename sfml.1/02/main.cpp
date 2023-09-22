#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangles and circle");

    sf::RectangleShape shape1;
    shape1.setSize(sf::Vector2f(60, 20));
    shape1.setRotation(75);
    shape1.setPosition(200,120);
    shape1.setFillColor(sf::Color(0xFF,0x0,0x0));


    sf::CircleShape shape2(48);
    shape2.setPosition(260,120);
    shape2.setFillColor(sf::Color(0x0,0xFF,0x0));

    sf::RectangleShape shape3;
    shape3.setSize(sf::Vector2f(120, 15));
    shape3.setRotation(-30);
    shape3.setPosition(200,120);
    shape3.setFillColor(sf::Color(0xFF,0x0,0xFF));
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
    }

    return 0;
}