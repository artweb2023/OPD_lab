#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "House");

    sf::RectangleShape wall;
    wall.setSize(sf::Vector2f(400, 200));
    wall.setPosition(200,350);
    wall.setFillColor(sf::Color(0x65,0x43,0x21));

    sf::RectangleShape door;
    door.setSize(sf::Vector2f(100, 150));
    door.setPosition(250,400);
    door.setFillColor(sf::Color(0x29,0x31,0x33));

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(0x48, 0x06, 0x07));
    roof.setPosition(400, 250);
    roof.setPointCount(4);
    roof.setPoint(0, sf::Vector2f(-150, 0));
    roof.setPoint(1, sf::Vector2f(150, 0));
    roof.setPoint(2, sf::Vector2f(300, 100));
    roof.setPoint(3, sf::Vector2f(-300, 100));

    sf::RectangleShape chimney;
    chimney.setSize(sf::Vector2f(50, 80));
    chimney.setPosition(480,220);
    chimney.setFillColor(sf::Color(0x43,0x4B,0x4D));

    sf::RectangleShape chimney1;
    chimney1.setSize(sf::Vector2f(100, 50));
    chimney1.setPosition(455,190);
    chimney1.setFillColor(sf::Color(0x43,0x4B,0x4D));


    sf::CircleShape smoke(20);
    smoke.setFillColor(sf::Color(0xBB,0xBB,0xBB));
    smoke.setPosition(505,155);

    sf::CircleShape smoke1(25);
    smoke1.setFillColor(sf::Color(0xBB,0xBB,0xBB));
    smoke1.setPosition(510,120);

    sf::CircleShape smoke2(30);
    smoke2.setFillColor(sf::Color(0xBB,0xBB,0xBB));
    smoke2.setPosition(515,80);

    sf::CircleShape smoke3(35);
    smoke3.setFillColor(sf::Color(0xBB,0xBB,0xBB));
    smoke3.setPosition(520,40);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(wall);
        window.draw(door);
        window.draw(roof);
        window.draw(smoke);
        window.draw(smoke1);
        window.draw(smoke2);
        window.draw(smoke3);
        window.draw(chimney);
        window.draw(chimney1);
        window.display();
    }

    return 0;
}