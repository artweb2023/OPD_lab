#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(160, 380), "Traffic light");

    sf::RectangleShape shape1;
    shape1.setSize(sf::Vector2f(120, 340));
    shape1.setPosition(20,20);
    shape1.setFillColor(sf::Color(0x4C,0x4E,0x52));

    sf::CircleShape shape2(50);
    shape2.setPosition(30,30);
    shape2.setFillColor(sf::Color(0x0,0xFF,0x80));

    sf::CircleShape shape3(50);
    shape3.setPosition(30,140);
    shape3.setFillColor(sf::Color(0xFF,0xFF,0x0));

    sf::CircleShape shape4(50);
    shape4.setPosition(30,250);
    shape4.setFillColor(sf::Color(0xFF,0x0,0x0));

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
        window.draw(shape4);
        window.display();
    }

    return 0;
}