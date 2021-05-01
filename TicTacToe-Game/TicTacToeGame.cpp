//
//  TicTacToeGame.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#include "TicTacToeGame.hpp"
#include "SplashState.hpp"


TicTacToeGame::TicTacToeGame(int width, int height, std::string name){
    _data->window.create(sf::VideoMode(width, height), name, sf::Style::Close | sf::Style::Titlebar);
    
    // add splashState
    _data->machine.addState(StateRef(new SplashState(this->_data)));
    
    this->run();
}

void TicTacToeGame::run(){
    float newTime, frameTime, interpolation;
    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;
    
    while(this->_data->window.isOpen()){
        this->_data->machine.processStateChanges();
        newTime = this->_clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        if(frameTime > 0.25f){
            frameTime = 0.25f;
        }
        currentTime = newTime;
        accumulator += frameTime;   // total of frametime
        
        while(accumulator >= dt){
            this->_data->machine.getActiveState()->handleInput();
            this->_data->machine.getActiveState()->update(dt);
            
            accumulator -= dt;
        }
        
        interpolation = accumulator / dt;
        
        this->_data->machine.getActiveState()->draw(interpolation);
    }
}
