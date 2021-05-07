//
//  MainMenuState.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/30/21.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include "States.hpp"
#include "TicTacToeGame.hpp"
#include "GameState.hpp"


class MainMenuState: public States{
public:
    
    MainMenuState(GameDataRef data);
    
    void init();
    
    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _playButton;
    sf::Sprite _onePlayer;
    sf::Sprite _twoPlayer;
    sf::Sprite _title;
    
};

#endif /* MainMenuState_hpp */
