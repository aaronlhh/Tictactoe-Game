//
//  MainMenuState.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/30/21.
//

#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>



MainMenuState::MainMenuState(GameDataRef data): _data(data){
    
}

void MainMenuState::init(){
    this->_data->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    this->_data->assets.loadTexture("Main Menu Play Button", MAIN_MENU_TOUCH_BUTTON_PATH);
    this->_data->assets.loadTexture("Main Menu One Player", MAIN_MENU_ONE_PLAYER_BUTTON_PATH);
    this->_data->assets.loadTexture("Main Menu Two Player", MAIN_MENU_TWO_PLAYER_BUTTON_PATH);
    this->_data->assets.loadTexture("Main Menu One Player Selected", MAIN_MENU_ONE_PLAYER_SELECTED_PATH);
    this->_data->assets.loadTexture("Main Menu Two Player Selected", MAIN_MENU_TWO_PLAYER_SELECTED_PATH);
    this->_data->assets.loadTexture("Main Menu Title", MAIN_MENU_TITLE_PATH);
    
    this->_background.setTexture(this->_data->assets.getTexture("Main Menu Background"));
    this->_playButton.setTexture(this->_data->assets.getTexture("Main Menu Play Button"));
    this->_onePlayer.setTexture(this->_data->assets.getTexture("Main Menu One Player"));
    this->_twoPlayer.setTexture(this->_data->assets.getTexture("Main Menu Two Player"));
    this->_title.setTexture(this->_data->assets.getTexture("Main Menu Title"));
    
    
    // position adjustment
    
    this->_playButton.setPosition( (SCREEN_WIDTH/2) - (this->_playButton.getGlobalBounds().width/2),
                                  (SCREEN_HEIGHT/2) - (this->_playButton.getGlobalBounds().height/2));
    this->_onePlayer.setPosition(
        (SCREEN_WIDTH/3*1) - (this->_onePlayer.getGlobalBounds().width/2),
        (SCREEN_HEIGHT/4*3) - (this->_onePlayer.getGlobalBounds().height/2)
    );
    this->_twoPlayer.setPosition(
        (SCREEN_WIDTH/3*2) - (this->_twoPlayer.getGlobalBounds().width/2),
        (SCREEN_HEIGHT/4*3) - (this->_twoPlayer.getGlobalBounds().height/2)
    );
    
    this->_title.setPosition(
        (SCREEN_WIDTH/2) - (this->_title.getGlobalBounds().width/2),
        (this->_title.getGlobalBounds().height * 0.1)
    ); // height * 0.1 since we wanna put title on really top
}


void MainMenuState::handleInput(){
    sf::Event event;
    while(this->_data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->_data->window.close();
        }
        
        if(this->_data->input.isSpriteClicked(this->_onePlayer,
                                              sf::Mouse::Left,
                                              this->_data->window)){
            if(buttonPicked == ONE_PLAYER){
                buttonPicked = NO_PLAYER;
            }else{
                buttonPicked = ONE_PLAYER;
            }
        }
        
        if(this->_data->input.isSpriteClicked(this->_twoPlayer,
                                              sf::Mouse::Left,
                                              this->_data->window)){
            if(buttonPicked == TWO_PLAYER){
                buttonPicked = NO_PLAYER;
            }else{
                buttonPicked = TWO_PLAYER;
            }
        }
        
        if(this->_data->input.isSpriteClicked(this->_playButton,
                                              sf::Mouse::Left,
                                              this->_data->window)){
            if(buttonPicked != NO_PLAYER){
                this->_data->machine.addState(StateRef(new GameState(this->_data)));
            }
        }
    }
}


void MainMenuState::update(float dt){
    if(buttonPicked == NO_PLAYER){
        _onePlayer.setTexture(this->_data->assets.getTexture("Main Menu One Player"));
        _twoPlayer.setTexture(this->_data->assets.getTexture("Main Menu Two Player"));
    }else if(buttonPicked == ONE_PLAYER){
        _onePlayer.setTexture(this->_data->assets.getTexture("Main Menu One Player Selected"));
        _twoPlayer.setTexture(this->_data->assets.getTexture("Main Menu Two Player"));
    }else if(buttonPicked == TWO_PLAYER){
        _onePlayer.setTexture(this->_data->assets.getTexture("Main Menu One Player"));
        _twoPlayer.setTexture(this->_data->assets.getTexture("Main Menu Two Player Selected"));
    }
}


void MainMenuState::draw(float dt){
    this->_data->window.clear();
    this->_data->window.draw(_background);
    this->_data->window.draw(_playButton);
    this->_data->window.draw(_title);
    this->_data->window.draw(_onePlayer);
    this->_data->window.draw(_twoPlayer);
    this->_data->window.display();
}
