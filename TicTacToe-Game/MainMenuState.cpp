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
    this->_data->assets.loadTexture("Main Menu Play Button", MAIN_MENU_PLAY_BUTTON_PATH);
    this->_data->assets.loadTexture("Main Menu Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER_PATH);
    this->_data->assets.loadTexture("Main Menu Title", MAIN_MENU_TITLE_PATH);
    
    this->_background.setTexture(this->_data->assets.getTexture("Main Menu Background"));
    this->_playButton.setTexture(this->_data->assets.getTexture("Main Menu Play Button"));
    this->_playButtonOuter.setTexture(this->_data->assets.getTexture("Main Menu Play Button Outer"));
    this->_title.setTexture(this->_data->assets.getTexture("Main Menu Title"));
    
    
    // position adjustment
    this->_playButton.setPosition( (SCREEN_WIDTH/2) - (this->_playButton.getGlobalBounds().width/2),
                                  (SCREEN_HEIGHT/2) - (this->_playButton.getGlobalBounds().height/2));
    this->_playButtonOuter.setPosition(
        (SCREEN_WIDTH/2) - (this->_playButtonOuter.getGlobalBounds().width/2),
        (SCREEN_HEIGHT/2) - (this->_playButtonOuter.getGlobalBounds().height/2)
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
        
        if(this->_data->input.isSpriteClicked(this->_playButton,
                                              sf::Mouse::Left,
                                              this->_data->window)){
//            std::cout << "Go to Game Screen\n";
            this->_data->machine.addState(StateRef(new GameState(this->_data)), true);
        }
           
    }
}


void MainMenuState::update(float dt){
    
}


void MainMenuState::draw(float dt){
    this->_data->window.clear();
    this->_data->window.draw(_background);
    this->_data->window.draw(_playButton);
    this->_data->window.draw(_title);
    this->_data->window.draw(_playButtonOuter);
    this->_data->window.display();
}
