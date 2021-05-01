//
//  GameState.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/30/21.
//

#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include "PauseState.hpp"
#include "GameOverState.hpp"

GameState::GameState(GameDataRef data)
: _data(data){
    
}


void GameState::init(){
    
    // setting variables and load textures
    gameState = STATE_PLAYING;
    turn = PLAY_PIECE;
    this->_data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    this->_data->assets.loadTexture("Pause Button", PAUSE_BUTTON_PATH);
    
    // setting textures
    this->_background.setTexture(this->_data->assets.getTexture("Game Background"));
    this->_pauseButton.setTexture(this->_data->assets.getTexture("Pause Button"));
    
    
    // position adjustment
    this->_pauseButton.setPosition(
                                   this->_data->window.getSize().x - _pauseButton.getLocalBounds().width,
                                   this->_pauseButton.getPosition().y
                                   );
    
    
    
}


void GameState::handleInput(){
    sf::Event event;
    while(this->_data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->_data->window.close();
        }
        
        if(this->_data->input.isSpriteClicked(this->_pauseButton,
                                              sf::Mouse::Left,
                                              this->_data->window)){
            // false because we dont want replace gamestate
            //this->_data->machine.addState(StateRef(new PauseState(this->_data)), false);
            this->_data->machine.addState(StateRef(new GameOverState(this->_data)), true);
            
//            std::cout << "Pause the game\n";
        }
           
    }
}


void GameState::update(float dt){
     // do nothing
}


void GameState::draw(float dt){
    this->_data->window.clear();
    this->_data->window.draw(_background);
    this->_data->window.draw(_pauseButton);
    this->_data->window.display();
}
