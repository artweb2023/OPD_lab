#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// Инициализирует фигуру-стрелку
void init(sf::ConvexShape &arrow)
{
    arrow.setFillColor(sf::Color(255, 255, 0));
    arrow.setPosition(400, 300);
    arrow.setPointCount(7);

    arrow.setPoint(0, sf::Vector2f(0, 0));
    arrow.setPoint(1, sf::Vector2f(-50, 50));
    arrow.setPoint(2, sf::Vector2f(-25, 50));
    arrow.setPoint(3, sf::Vector2f(-25, 100));
    arrow.setPoint(4, sf::Vector2f(25, 100));
    arrow.setPoint(5, sf::Vector2f(25, 50));
    arrow.setPoint(6, sf::Vector2f(50, 50));

    arrow.setOutlineColor(sf::Color(0, 0, 0));
    arrow.setOutlineThickness(3);
}

// Опрашивает и обрабатывает доступные события в цикле.

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
        default:
            break;
        }
    }
}

// Рисует и выводит один кадр

void drawFrame(sf::RenderWindow &window, sf::ConvexShape &arrow)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(arrow);
    window.display();
}

// Программа рисует в окне стрелку
int main()
{
    const unsigned WINDOW_WIDTH = 800;
    const unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "rrow", sf::Style::Default, settings);

    sf::ConvexShape arrow;
    init(arrow);

    while (window.isOpen())
    {
        pollEvents(window);
        drawFrame(window, arrow);
    }
}