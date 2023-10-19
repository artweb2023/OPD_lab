#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

// Переводиим радианы в градусы
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

// Обрабатывает событиие MouseMove, обновляем позиициб мыши
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition.x = float(event.x);
    mousePosition.y = float(event.y);
}
// Опрашивает и обрабатывает доступные события в цикле.
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition, sf::Sprite &laser, bool &MouseButtonPressed)
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
            laser.setPosition(event.mouseButton.x, event.mouseButton.y);
            MouseButtonPressed = true;
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}
// Инициализирует из картинки кота и указки
void init(sf::Sprite &cat, sf::Texture &catTexture, sf::Sprite &laser, sf::Texture &laserTexture)
{
    catTexture.loadFromFile("cat.png", sf::IntRect(0, 0, 40, 40));
    catTexture.setSmooth(true);
    cat.setTexture(catTexture);
    cat.setPosition(400, 300);

    laserTexture.loadFromFile("red_pointer.png", sf::IntRect(0, 0, 40, 40));
    laserTexture.setSmooth(true);
    laser.setTexture(laserTexture);
    laser.setPosition(200, 100);
    laser.setOrigin(16, 16);
}

// Обновляет фигуру, указывающую на мышь
void update(sf::Sprite &laser, sf::Sprite &cat, float &deltaTime)
{
    const sf::Vector2f delta = laser.getPosition() - cat.getPosition();
    float distance = hypot(delta.x, delta.y);
    sf::Vector2f direction(delta.x / distance, delta.y / distance);
    float speed = 90.f;
    if ((delta.x && delta.y) != 0.f)
    {
        float move = std::min(speed * deltaTime, distance);
        cat.setPosition(cat.getPosition() + direction * move);
    }
    if (laser.getPosition().x < cat.getPosition().x)
    {
        cat.setScale(-1, 1);
    }
    else
    {
        cat.setScale(1, 1);
    }
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow &window, sf::Sprite &cat, sf::Sprite &laser, bool MouseButtonPressed)
{
    window.clear(sf::Color(255, 255, 255));
    if (MouseButtonPressed)
    {
        window.draw(laser);
    }
    window.draw(cat);
    window.display();
}

// Программа рисует в окне кота гонящегося за указкой
int main()
{
    const unsigned WINDOW_WIDTH = 800;
    const unsigned WINDOW_HEIGHT = 600;

    sf::Clock clock;
    sf::Vector2f mousePosition;
    bool MouseButtonPressed = false;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Kitten follows laser", sf::Style::Default, settings);

    sf::Texture catTexture;
    sf::Texture laserTexture;
    sf::Sprite cat;
    sf::Sprite laser;

    init(cat, catTexture, laser, laserTexture);

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        pollEvents(window, mousePosition, laser, MouseButtonPressed);
        update(laser, cat, deltaTime);
        redrawFrame(window, cat, laser, MouseButtonPressed);
    }
}