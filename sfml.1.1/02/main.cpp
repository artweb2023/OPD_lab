#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Initials");

    sf::RectangleShape shape1;
    shape1.setSize(sf::Vector2f(50, 300));
    shape1.setPosition(150,150);
    shape1.setFillColor(sf::Color(0x0,0xFF,0x80));

    sf::RectangleShape shape2;
    shape2.setSize(sf::Vector2f(70, 140));
    shape2.setRotation(-45);
    shape2.setPosition(150,200);
    shape2.setFillColor(sf::Color(0x0,0xFF,0x80));

    sf::RectangleShape shape3;
    shape3.setSize(sf::Vector2f(50, 300));
    shape3.setPosition(300,150);
    shape3.setFillColor(sf::Color(0x0,0xFF,0x80));

    sf::RectangleShape shape4;
    shape4.setSize(sf::Vector2f(70, 140));
    shape4.setRotation(45);
    shape4.setPosition(300,150);
    shape4.setFillColor(sf::Color(0x0,0xFF,0x80));


    sf::RectangleShape shape5;
    shape5.setSize(sf::Vector2f(50, 200));
    shape5.setPosition(400,250);
    shape5.setFillColor(sf::Color(0x80,0x0,0x80));

    sf::RectangleShape shape6;
    shape6.setSize(sf::Vector2f(50, 200));
    shape6.setPosition(550,250);
    shape6.setFillColor(sf::Color(0x80,0x0,0x80));

    sf::RectangleShape shape7;
    shape7.setSize(sf::Vector2f(100, 50));
    shape7.setPosition(450,350);
    shape7.setFillColor(sf::Color(0x80,0x0,0x80));

    sf::RectangleShape shape8;
    shape8.setSize(sf::Vector2f(65, 142));
    shape8.setRotation(45);
    shape8.setPosition(500,150);
    shape8.setFillColor(sf::Color(0x80,0x0,0x80));

    sf::RectangleShape shape9;
    shape9.setSize(sf::Vector2f(65, 140));
    shape9.setRotation(-45);
    shape9.setPosition(457,200);
    shape9.setFillColor(sf::Color(0x80,0x0,0x80));

    sf::RectangleShape shape10;
    shape10.setSize(sf::Vector2f(50, 200));
    shape10.setPosition(650,250);
    shape10.setFillColor(sf::Color(0x0,0x0,0xFF));


    sf::RectangleShape shape11;
    shape11.setSize(sf::Vector2f(50, 200));
    shape11.setPosition(800,250);
    shape11.setFillColor(sf::Color(0x0,0x0,0xFF));

    sf::RectangleShape shape12;
    shape12.setSize(sf::Vector2f(100, 50));
    shape12.setPosition(700,350);
    shape12.setFillColor(sf::Color(0x0,0x0,0xFF));

    sf::RectangleShape shape13;
    shape13.setSize(sf::Vector2f(65, 142));
    shape13.setRotation(45);
    shape13.setPosition(750,150);
    shape13.setFillColor(sf::Color(0x0,0x0,0xFF));

    sf::RectangleShape shape14;
    shape14.setSize(sf::Vector2f(65, 140));
    shape14.setRotation(-45);
    shape14.setPosition(707,200);
    shape14.setFillColor(sf::Color(0x0,0x0,0xFF));



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
        window.draw(shape5);
        window.draw(shape6);
        window.draw(shape7);
        window.draw(shape8);
        window.draw(shape9);
        window.draw(shape10);
        window.draw(shape11);
        window.draw(shape12);
        window.draw(shape13);
        window.draw(shape14);
        window.display();
    }

    return 0;
}