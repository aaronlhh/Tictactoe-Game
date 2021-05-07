//
//  DEFINITIONS.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#ifndef DEFINITIONS_h
#define DEFINITIONS_h

// screen attributes
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1136

#define SPLASH_STATE_SHOW_TIME 3


#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/AAA/Background.png"
#define GAME_BACKGROUND_FILEPATH "../Resources/res/Main Menu Background.png"
#define PAUSE_BACKGROUND_FILEPATH "../Resources/res/Main Menu Background.png"
#define RETRY_BACKGROUND_FILEPATH "../Resources/res/Main Menu Background.png"


#define MAIN_MENU_TOUCH_BUTTON_PATH "../Resources/AAA/Group 4.png"
#define RESUME_BUTTON_PATH "../Resources/res/Resume Button.png"
#define HOME_BUTTON_PATH "../Resources/res/Home Button.png"
#define PAUSE_BUTTON_PATH "../Resources/res/Pause Button.png"

// used in main menu choosing players feature
static int buttonPicked;
#define ONE_PLAYER 1
#define TWO_PLAYER 2
#define NO_PLAYER 0
#define MAIN_MENU_ONE_PLAYER_BUTTON_PATH "../Resources/AAA/1 player.png"
#define MAIN_MENU_ONE_PLAYER_SELECTED_PATH "../Resources/AAA/1 player( white).png"
#define MAIN_MENU_TWO_PLAYER_BUTTON_PATH "../Resources/AAA/2 player.png"
#define MAIN_MENU_TWO_PLAYER_SELECTED_PATH "../Resources/AAA/2 player( white).png"
#define MAIN_MENU_TITLE_PATH "../Resources/AAA/Title.png"


#define X_PIECE_FILEPATH "../Resources/res/X.png"
#define O_PIECE_FILEPATH "../Resources/res/O.png"
#define X_WINNING_PIECE_FILEPATH "../Resources/res/X Win.png"
#define O_WINNING_PIECE_FILEPATH "../Resources/res/O Win.png"


#define GRID_SPRITE_FILEPATH "../Resources/res/Grid.png"

    // keeping them different numbers just wanna keep them unique
    // from each other
#define X_PIECE 8
#define O_PIECE 7
#define EMPTY_PIECE 9
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE
#define PLAYER2_PIECE O_PIECE
    
#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define TIME_BEFORE_SHOWING_GAME_OVER 3





#endif /* DEFINITIONS_h */
