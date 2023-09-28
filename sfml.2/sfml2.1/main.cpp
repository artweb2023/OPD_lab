#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

const unsigned WINDOW_WIDTH = 800;
const unsigned WINDOW_HEIGHT = 600;

int main()
{
    const float BALL_SIZE = 40;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wave Moving Ball");
    sf::Clock clock;

    sf::Vector2f position(10, 350);

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    sf::Vector2f speed(50.f, 15.f);
    float speedX = 100.f;
    float alltime = 0;
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

        const float amplitudeY = 80.f;
        const float periodY = 2;
        float deltaTime = clock.restart().asSeconds();
        alltime = deltaTime + alltime;
        float wavePhase = alltime * float(2 * M_PI);
        position.x += speedX * deltaTime;
        const float y = amplitudeY * std::sin(wavePhase / periodY);
        const sf::Vector2f offset(0, y);
        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0))
        {
            speedX = -speedX;
        }
        if ((position.x < 0) && (speedX < 0))
        {
            speedX = -speedX;
        }
        ball.setPosition(position + offset);

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}