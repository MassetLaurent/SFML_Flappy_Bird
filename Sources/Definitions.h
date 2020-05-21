#ifndef DEF_DEFINITIONS
#define DEF_DEFINITIONS

//application screen
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

//fonts
#define FLAPPY_FONT_FAILEPATH "Ressources/fonts/FlappyFont.ttf"

//splash state
#define	SPLASH_STATE_SHOW_TIME .5f
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Ressources/images/Splash Background.png"

//main menu state
#define MAIN_MENU_BACKGROUND_FILEPATH "Ressources/images/sky.png"
#define GAME_TITLE_FILEPATH "Ressources/images/title.png"
#define PLAY_BUTTON_FILEPATH "Ressources/images/PlayButton.png"

//Game state
#define GAME_BACKGROUND_FILEPATH "Ressources/images/Sky.png"
#define PIPE_UP_FILEPATH "Ressources/images/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Ressources/images/PipeDown.png"
#define LAND_FILEPATH "Ressources/images/Land.png"
#define SCORING_PIPE_FILEPATH "Ressources/images/InvisibleScoringPipe.png"

//pipe
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.5f

//bird
#define BIRD_FRAME_1_FILEPATH "Ressources/images/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Ressources/images/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Ressources/images/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Ressources/images/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define GRAVITY 350.f
#define FLYING_SPEED 350.f
#define FLYING_DURATION 0.25f
#define BIRD_ROTATION_SPEED 100.f

//Game over state
#define GAME_OVER_BACKGROUND_FILEPATH "Ressources/images/Sky.png"
#define GAME_OVER_TITLE_FILEPATH "Ressources/images/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Ressources/images/Game-Over-Body.png"

#define BRONZE_MEDAL_FILEPATH "Ressources/images/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "Ressources/images/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "Ressources/images/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "Ressources/images/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 1
#define SILVER_MEDAL_SCORE 10
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

#define HIGHSCORE_FILEPATH "Ressources/Highscore.txt"
#define FLASH_SPEED 2500.f
#define TIME_BEFORE_GAME_OVER 1.f

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#endif // !DEF_DEFINITIONS