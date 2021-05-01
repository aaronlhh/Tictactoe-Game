//
//  SplashState.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#include "SplashState.hpp"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"


SplashState::SplashState(GameDataRef data)
: _data(data){
    
}

void SplashState::init(){
    this->_data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
    _background.setTexture(this->_data->assets.getTexture("Splash State Background"));
}

void SplashState::handleInput(){
    
    // poll event
    sf::Event event;
    while(this->_data->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->_data->window.close();
        }
    }
    
}

void SplashState::update(float dt){
    if(this->_clock.getElapsedTime().asSeconds() >= SPLASH_STATE_SHOW_TIME){
        // switch to the main menu
//        std::cout << "Go to main menu\n";
        this->_data->machine.addState( StateRef(new MainMenuState(_data)), true );
    }
}

void SplashState::draw(float dt){
    this->_data->window.clear(sf::Color::Blue);
    this->_data->window.draw(this->_background);
    this->_data->window.display();
}
