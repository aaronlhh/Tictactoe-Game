//
//  InputManager.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#include "InputManager.hpp"


bool InputManager::isSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window){
    
    if(sf::Mouse::isButtonPressed(button)){
        sf::IntRect rect(obj.getPosition().x, obj.getPosition().y,
                         obj.getGlobalBounds().width, obj.getGlobalBounds().height);
        if(rect.contains(getMousePosition(window))){
            return true;
        }
    }
    return false;
}


 
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window){
    return sf::Mouse::getPosition(window);
}
