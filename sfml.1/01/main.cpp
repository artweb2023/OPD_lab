#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "title");

    sf::CircleShape shape1(40);
    shape1.setFillColor(sf::Color(0xFF,0x0,0x0));
    shape1.setPosition(200,120);

    sf::CircleShape shape2(48);
    shape2.setFillColor(sf::Color(0x0,0xFF,0x0));
    shape2.setPosition(260,120);

    sf::CircleShape shape3(60);
    shape3.setFillColor(sf::Color(0x0,0x0,0xFF));
    shape3.setPosition(320,160);

    sf::CircleShape shape4(75);
    shape4.setFillColor(sf::Color(0xFF,0xFF,0x0));
    shape4.setPosition(330,220);

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