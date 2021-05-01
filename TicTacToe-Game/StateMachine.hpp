//
//  StateMachine.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <memory>
#include <stack>

#include "States.hpp"

typedef std::unique_ptr<States> StateRef;

/**
Using stack for states
 
 
 */
class StateMachine{
public:
    StateMachine(){}
    ~StateMachine(){}
    
    void addState(StateRef newState, bool isReplacing = true);
    void removeState();
    
    void processStateChanges();
    
    StateRef& getActiveState();
    
private:
    std::stack<StateRef> _states;
    StateRef _newState;
    
    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
    
    
};

#endif /* StateMachine_hpp */
