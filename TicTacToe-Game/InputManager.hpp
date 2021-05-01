//
//  InputManager.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#ifndef InputManager_hpp
#define InputManager_hpp
#include <SFML/Graphics.hpp>

class InputManager{
public:
    InputManager(){}
    ~InputManager(){}
    
    bool isSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window);
    sf::Vector2i getMousePosition(sf::RenderWindow& window);
};

#endif /* InputManager_hpp */
