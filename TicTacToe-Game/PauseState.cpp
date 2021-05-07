//
//  PauseState.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 5/1/21.
//

#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include "MainMenuState.hpp"


PauseState::PauseState(GameDataRef data)
: _data(data){
    
}


void PauseState::init(){
    
    // setting variables and load textures
    this->_data->assets.loadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
    this->_data->assets.loadTexture("Resume Button", RESUME_BUTTON_PATH);
    this->_data->assets.loadTexture("Home Button", HOME_BUTTON_PATH);
    
    // setting textures
    this->_background.setTexture(this->_data->assets.getTexture("Pause Background"));
    this->_resumeButton.setTexture(this->_data->assets.getTexture("Resume Button"));
    this->_homeButton.setTexture(this->_data->assets.getTexture("Home Button"));
    
    
    // adjusting positions
    this->_resumeButton.setPosition( (this->_data->window.getSize().x/2) - (_resumeButton.getLocalBounds().width/2),
                                     (this->_data->window.getSize().y/3) - (this->_resumeButton.getLocalBounds().height/2) );
    this->_homeButton.setPosition( (this->_data->window.getSize().x/2) - (_homeButton.getLocalBounds().width/2),
                                     (this->_data->window.getSize().y/3*2) - (this->_homeButton.getLocalBounds().height/2) );
    
}


void PauseState::handleInput(){
    sf::Event event;
    while(this->_data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->_data->window.close();
        }
        
        if(this->_data->input.isSpriteClicked(this->_resumeButton,
                                              sf::Mouse::Left,
                                              this->_data->window)){
            // go back to gamestate, which means just remove the top state
            this->_data->machine.removeState();
            std::cout << "Resume the game\n";
            
        }
        
        if(this->_data->input.isSpriteClicked(this->_homeButton,
                                                    sf::Mouse::Left,
                                                    this->_data->window)){
            this->_data->machine.removeState();  // now is in gamestate
            this->_data->machine.addState(StateRef(new MainMenuState(this->_data)), true );
            std::cout << "Go back to home\n";
        }
           
    }
}


void PauseState::update(float dt){
     // do nothing
}


void PauseState::draw(float dt){
    this->_data->window.clear();
    this->_data->window.draw(_background);
    this->_data->window.draw(_resumeButton);
    this->_data->window.draw(_homeButton);
    this->_data->window.display();
}

