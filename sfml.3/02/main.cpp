#include <SFML/Graphics.hpp>
#include <iostream>

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            std::cout << "mouse pressed,"
                      << "x=" << event.mouseButton.x
                      << "y=" << event.mouseButton.y
                      << std::endl;
            break;
        case sf::Event::MouseButtonReleased:
            std::cout << "mouse relesed,"
                      << "x=" << event.mouseButton.x
                      << "y=" << event.mouseButton.y
                      << std::endl;
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window)
{
    window.clear();
    window.display();
}

int main()
{
    const unsigned WINDOW_WIDTH = 800;
    const unsigned WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Prints mouse events to terminal");
    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window);
    }
    return 0;
}