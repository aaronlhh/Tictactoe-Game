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

// 414*736

#define SPLASH_STATE_SHOW_TIME 3


#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/res/Main Menu Background.png"
#define GAME_BACKGROUND_FILEPATH "../Resources/res/Main Menu Background.png"
#define PAUSE_BACKGROUND_FILEPATH "../Resources/res/Main Menu Background.png"
#define RETRY_BACKGROUND_FILEPATH "../Resources/res/Main Menu Background.png"


#define MAIN_MENU_TITLE_PATH "../Resources/res/Game Title.png"


#define MAIN_MENU_PLAY_BUTTON_PATH "../Resources/res/Play Button.png"
#define RESUME_BUTTON_PATH "../Resources/res/Resume Button.png"
#define HOME_BUTTON_PATH "../Resources/res/Home Button.png"
#define PAUSE_BUTTON_PATH "../Resources/res/Pause Button.png"


#define MAIN_MENU_PLAY_BUTTON_OUTER_PATH "../Resources/res/Play Button Outer.png"


#define X_PIECE_FILEPATH "../Resources/res/X.png"
#define O_PIECE_FILEPATH "../Resources/res/O.png"
#define X_WINNING_PIECE_FILEPATH "../Resources/res/X Win.png"
#define O_WINNING_PIECE_FILEPATH "../Resources/res/O Win.png"


#define GRID_SPRITE_FILEPATH "../Resources/res/Grid.png"

    // keeping them different numbers just wanna keep them unique
    // from each other
#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
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
