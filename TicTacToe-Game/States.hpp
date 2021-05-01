//
//  States.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#ifndef States_h
#define States_h

/*
    Abstract class (Interface)
    listing all functions needed for each State
 */
class States{
public:
    virtual void init() = 0;
    
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw(float dt) = 0;  // dt = frame rate, keep in same pace
    
    virtual void pause(){}
    virtual void resume(){}
};

#endif /* States_h */
