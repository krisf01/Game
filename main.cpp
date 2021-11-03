#include <SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	//player.setFillColor(sf::Color::Red);
	//player.setOrigin(50.0f, 50.0f);
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("baby.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(3, 1), 0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	// NOT NECESSARY ANYMORE FOR ANIMATION sf::Vector2u textureSize = playerTexture.getSize();
	//textureSize.x /= 3;
	//textureSize.y /= 9;

	// NOT NECESSARY ANYMORE FOR ANIMATION player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 0, textureSize.x, textureSize.y));

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		//Keyboard Input
		//if (sfKeyboard::isKeyPressed(sf::Keyboard::Key::A))
		//	{
		//		player.move(-0.1f, 0.0f);
		//	}

		//MOUSE INPUT
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)mousePos.y);
		}

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear(sf::Color::Cyan);
		window.draw(player);
		window.display();

	}

	return 0;
}
