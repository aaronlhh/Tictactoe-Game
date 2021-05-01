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
    turn = PLAYER_PIECE;
    
    this->AI = new AIPlayer(turn, this->_data);
    
    this->_data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    this->_data->assets.loadTexture("Pause Button", PAUSE_BUTTON_PATH);
    this->_data->assets.loadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
    this->_data->assets.loadTexture("X Piece", X_PIECE_FILEPATH);
    this->_data->assets.loadTexture("O Piece", O_PIECE_FILEPATH);
    // winning piece
    this->_data->assets.loadTexture("X Winning Piece", X_WINNING_PIECE_FILEPATH);
    this->_data->assets.loadTexture("O Winning Piece", O_WINNING_PIECE_FILEPATH);
    
    // setting textures
    this->_background.setTexture(this->_data->assets.getTexture("Game Background"));
    this->_pauseButton.setTexture(this->_data->assets.getTexture("Pause Button"));
    this->_gridSprite.setTexture(this->_data->assets.getTexture("Grid Sprite"));
    
    
    // position adjustment
    this->_pauseButton.setPosition(
                                   this->_data->window.getSize().x - _pauseButton.getLocalBounds().width,
                                   this->_pauseButton.getPosition().y
                                   );
    
    this->_gridSprite.setPosition( (SCREEN_WIDTH/2) - (_gridSprite.getGlobalBounds().width/2),
                                  (SCREEN_HEIGHT/2) - (_gridSprite.getGlobalBounds().height/2));
    
    initGridPiece();
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            gridArr[i][j] = EMPTY_PIECE;
        }
    }
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
            this->_data->machine.addState(StateRef(new PauseState(this->_data)), false);
            
//            std::cout << "Pause the game\n";
        }else if(this->_data->input.isSpriteClicked(this->_gridSprite,
                                                    sf::Mouse::Left,
                                                    this->_data->window)){
            // only can place pieces when nobody won
            if(gameState == STATE_PLAYING)
                checkAndPlacePiece();
        }
    }
}



void GameState::update(float dt){
    if(gameState == STATE_DRAW || gameState == STATE_WON || gameState == STATE_LOSE){
        if(this->clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER){
            this->_data->machine.addState( StateRef(new GameOverState(this->_data)), true);  // replacing gamestate
        }
    }
}


void GameState::draw(float dt){
    this->_data->window.clear();
    this->_data->window.draw(_background);
    this->_data->window.draw(_pauseButton);
    this->_data->window.draw(_gridSprite);
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this->_data->window.draw(_gridPieces[i][j]);
        }
    }
    this->_data->window.display();
}


void GameState::initGridPiece(){
    sf::Vector2u tempSpriteSize = this->_data->assets.getTexture("X Piece").getSize();
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // just want some sprite inside the grid, and we will set the opacity to zero
            // so no one is gonna see them
            _gridPieces[i][j].setTexture(this->_data->assets.getTexture("X Piece"));
            _gridPieces[i][j].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x)*j - 7,
                                          _gridSprite.getPosition().y + (tempSpriteSize.y)*i -7);
            
            // white color, (r,g,b,opacity)
            _gridPieces[i][j].setColor(sf::Color(255,255,255,0));
        }
    }
}


void GameState::checkAndPlacePiece(){
    sf::Vector2i touchPoint = this->_data->input.getMousePosition(this->_data->window);
    sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
    sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width)/2,
                                                 (SCREEN_HEIGHT - gridSize.height)/2);
    
    // touchpoint position relative to grid
    sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x,
                                                  touchPoint.y - gapOutsideOfGrid.y);
    
    // size of each section inside grid
    sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width/3, gridSize.height/3);
    
    // check which col and row user clicked
    int col, row;
    if(gridLocalTouchPos.x < gridSectionSize.x ){
        col = 1;
    }else if(gridLocalTouchPos.x < gridSectionSize.x*2){
        col = 2;
    }else{
        //  if(gridLocalTouchPos.x < gridSize.width)
        col = 3;
    }
    
    if(gridLocalTouchPos.y < gridSectionSize.y){
        row = 1;
    }else if(gridLocalTouchPos.y < gridSectionSize.y*2){
        row = 2;
    }else{
        // if(gridLocalTouchPos.y < gridSize.height)
        row = 3;
    }
    
    
    if(gridArr[row-1][col-1] == EMPTY_PIECE){
        gridArr[row-1][col-1] = turn;
        if(turn == PLAYER_PIECE){
            // loading textures
            _gridPieces[row-1][col-1].setTexture(this->_data->assets.getTexture("X Piece"));
            checkPlayerHasWon(turn);
//            turn = AI_PIECE;
        }
//        else if(turn == AI_PIECE){
//            _gridPieces[row-1][col-1].setTexture(this->_data->assets.getTexture("O Piece"));
//            checkPlayerHasWon(turn);
//            turn = PLAYER_PIECE;
//        }
        
        _gridPieces[row-1][col-1].setColor(sf::Color(255,255,255,255));
    }
}


void GameState::checkPlayerHasWon(int turn){
    check3PiecesForMatch(0, 0, 1, 0, 2, 0, turn);
    check3PiecesForMatch(0, 1, 1, 1, 2, 1, turn);
    check3PiecesForMatch(0, 2, 1, 2, 2, 2, turn);
    check3PiecesForMatch(0, 0, 0, 1, 0, 2, turn);
    check3PiecesForMatch(1, 0, 1, 1, 1, 2, turn);
    check3PiecesForMatch(2, 0, 2, 1, 2, 2, turn);
    check3PiecesForMatch(0, 0, 1, 1, 2, 2, turn);
    check3PiecesForMatch(0, 2, 1, 1, 2, 0, turn);
    
    if(gameState != STATE_WON){
        gameState = STATE_AI_PLAYING;
        AI->placePiece(gridArr, _gridPieces, gameState);
        check3PiecesForMatch(0, 0, 1, 0, 2, 0, AI_PIECE);
        check3PiecesForMatch(0, 1, 1, 1, 2, 1, AI_PIECE);
        check3PiecesForMatch(0, 2, 1, 2, 2, 2, AI_PIECE);
        check3PiecesForMatch(0, 0, 0, 1, 0, 2, AI_PIECE);
        check3PiecesForMatch(1, 0, 1, 1, 1, 2, AI_PIECE);
        check3PiecesForMatch(2, 0, 2, 1, 2, 2, AI_PIECE);
        check3PiecesForMatch(0, 0, 1, 1, 2, 2, AI_PIECE);
        check3PiecesForMatch(0, 2, 1, 1, 2, 0, AI_PIECE);
    }
    
    int emptyNum = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(gridArr[i][j] != EMPTY_PIECE)
                emptyNum--;
        }
    }
    
    if(emptyNum == 0 && gameState != STATE_WON && gameState != STATE_LOSE){
        gameState = STATE_DRAW;
    }
    
    if(gameState == STATE_DRAW || gameState == STATE_WON || gameState == STATE_LOSE){
        // show game over
        // clock starts count when draw/won/lose
        // after 3 secs, gameOverState will show up (in update function)
        this->clock.restart();
    }
    
    std::cout << gameState << std::endl;
}

void GameState::check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck){
    if(pieceToCheck == gridArr[x1][y1] &&
       pieceToCheck == gridArr[x2][y2] &&
       pieceToCheck == gridArr[x3][y3]){
        std::string winningPieceStr;
        if(pieceToCheck == O_PIECE){
            winningPieceStr = "O Winning Piece";
        }else{
            winningPieceStr = "X Winning Piece";
        }
        
        _gridPieces[x1][y1].setTexture(this->_data->assets.getTexture(winningPieceStr));
        _gridPieces[x2][y2].setTexture(this->_data->assets.getTexture(winningPieceStr));
        _gridPieces[x3][y3].setTexture(this->_data->assets.getTexture(winningPieceStr));
        if(pieceToCheck == PLAYER_PIECE){
            gameState = STATE_WON;
        }else
            gameState = STATE_LOSE;
    }
}
