//
//  SplashState.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#ifndef SplashState_hpp
#define SplashState_hpp

#include <SFML/Graphics.hpp>
#include "States.hpp"
#include "TicTacToeGame.hpp"


class SplashState: public States{
public:
    SplashState(GameDataRef data);
    
    void init(); // initialization
    
    void handleInput();
    void update(float dt);
    void draw(float dt);  // dt = frame rate, keep in same pace
    
private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _background;
};


#endif /* SplashState_hpp */
