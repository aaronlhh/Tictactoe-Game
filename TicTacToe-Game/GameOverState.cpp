//
//  GameOverState.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 5/1/21.
//

#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include "MainMenuState.hpp"


GameOverState::GameOverState(GameDataRef data)
: _data(data){
    
}


void GameOverState::init(){
    
    // setting variables and load textures
    this->_data->assets.loadTexture("Retry Button", RESUME_BUTTON_PATH);
    this->_data->assets.loadTexture("Home Button", HOME_BUTTON_PATH);
    
    // setting textures
    this->_retryButton.setTexture(this->_data->assets.getTexture("Retry Button"));
    this->_homeButton.setTexture(this->_data->assets.getTexture("Home Button"));
    
    
    // adjusting positions
    this->_retryButton.setPosition( (this->_data->window.getSize().x/2) - (_retryButton.getLocalBounds().width/2),
                                     (this->_data->window.getSize().y/3) - (this->_retryButton.getLocalBounds().height/2) );
    this->_homeButton.setPosition( (this->_data->window.getSize().x/2) - (_homeButton.getLocalBounds().width/2),
                                     (this->_data->window.getSize().y/3*2) - (this->_homeButton.getLocalBounds().height/2) );
    
}


void GameOverState::handleInput(){
    sf::Event event;
    while(this->_data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->_data->window.close();
        }
        
        if(this->_data->input.isSpriteClicked(this->_retryButton,
                                              sf::Mouse::Left,
                                              this->_data->window)){
            
            this->_data->machine.addState(StateRef(new GameState(this->_data)), true );
            std::cout << "Resume the game\n";
            
        }
        
        if(this->_data->input.isSpriteClicked(this->_homeButton,
                                                    sf::Mouse::Left,
                                                    this->_data->window)){
            
            this->_data->machine.addState(StateRef(new MainMenuState(this->_data)), true );
            std::cout << "Go back to home\n";
        }
           
    }
}


void GameOverState::update(float dt){
     // do nothing
}


void GameOverState::draw(float dt){
    this->_data->window.clear(sf::Color::Red); // this can be used as background color
    this->_data->window.draw(_retryButton);
    this->_data->window.draw(_homeButton);
    this->_data->window.display();
}
