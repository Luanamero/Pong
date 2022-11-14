#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define DELTA_TIME GetFrameTime()

#define LATERAL_DISTANCE 50 // Paddle distance from screen borders



//----------------------------------------------------------------------------------
// State Machine's enum definition
//----------------------------------------------------------------------------------
typedef enum {
    SERVE_ENTER,
    SERVE_UPDATE,

    GAME_ENTER,
    GAME_UPDATE,

    END_ENTER,
    END_UPDATE
} STATE_MACHINE;



//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------

// General Purposes Functions
int min(int a, int b);
int max(int a, int b);
bool collides(Rectangle a, Rectangle b);


// Game State Functions
void Serve_Enter();
void Serve_Update();
void Serve_Draw();

void Game_Enter();
void Game_Update();
void Game_Draw();

void End_Enter();
void End_Update();
void End_Draw();



//----------------------------------------------------------------------------------
// Global variables
//----------------------------------------------------------------------------------
static STATE_MACHINE Global_StateMachine;

static Rectangle Player;
static Rectangle AI_Paddle;
static Rectangle Ball;

static int PlayerPoints;
static int AIPoints;



//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

    // Global State Machine
    Global_StateMachine = SERVE_ENTER;

    // Player and AI paddle
    Player.width = 18;
    Player.height = 86;
    Player.x = LATERAL_DISTANCE;
    Player.y = SCREEN_HEIGHT/2 - Player.height/2;

    AI_Paddle.width = 18;
    AI_Paddle.height = 86;
    AI_Paddle.x = SCREEN_WIDTH - (LATERAL_DISTANCE + AI_Paddle.width);
    AI_Paddle.y = SCREEN_HEIGHT/2 - AI_Paddle.height/2;

    // Ball
    Ball.width = Ball.height = 15;
    Ball.x = SCREEN_WIDTH/2 - Ball.width/2;
    Ball.y = SCREEN_HEIGHT/2 - Ball.height/2;

    // Points
    PlayerPoints = AIPoints = 0;


    //--------------------------------------------------------------------------------------

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    srand(time(NULL)); // Ensure random numbers when calling rand()

    //--------------------------------------------------------------------------------------


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update variables
        switch(Global_StateMachine)
        {
            case SERVE_ENTER:
                Serve_Enter();
                break;
            case SERVE_UPDATE:
                Serve_Update();
                break;

            case GAME_ENTER:
                Game_Enter();
                break;
            case GAME_UPDATE:
                Game_Update();
                break;

            case END_ENTER:
                End_Enter();
                break;
            case END_UPDATE:
                End_Update();
                break;
        }


        // Draw in screen
        BeginDrawing();

        switch(Global_StateMachine)
        {
            case SERVE_ENTER:
            case SERVE_UPDATE:
                Serve_Draw();
                break;

            case GAME_ENTER:
            case GAME_UPDATE:
                Game_Draw();
                break;

            case END_ENTER:
            case END_UPDATE:
                End_Draw();
                break;

            default:
                break;
        }

        EndDrawing();
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}




//----------------------------------------------------------------------------------
// Serve State Functions
//----------------------------------------------------------------------------------
int min(int a, int b) {
    return (a < b ? a : b);
}


int max(int a, int b) {
    return (a > b ? a : b);
}


bool collides(Rectangle a, Rectangle b) {

    // Check if it is possible to have collision based on X axis
    if (a.x > (b.x + b.width) || b.x > (a.x + a.width))
    {
        return false;
    }

    // Check if it is possible to have collision based on Y axis
    if (a.y > (b.y + b.height) || b.y > (a.y + a.height))
    {
        return false;
    }

    return true;
}




//----------------------------------------------------------------------------------
// Serve State Functions
//----------------------------------------------------------------------------------
void Serve_Enter() {


    // Change State to Update
    Global_StateMachine = SERVE_UPDATE;
}


void Serve_Update() {

}


void Serve_Draw() {

    DrawRectangle(Player.x, Player.y, Player.width, Player.height, WHITE); // Player Paddle
    DrawRectangle(AI_Paddle.x, AI_Paddle.y, AI_Paddle.width, AI_Paddle.height, WHITE); // AI Paddle
    DrawRectangle(Ball.x, Ball.y, Ball.width, Ball.height, WHITE); // Ball
}




//----------------------------------------------------------------------------------
// Game State Functions
//----------------------------------------------------------------------------------
void Game_Enter() {


    // Change State to Update
    Global_StateMachine = GAME_UPDATE;
}


void Game_Update() {

}


void Game_Draw() {

}




//----------------------------------------------------------------------------------
// End State Functions
//----------------------------------------------------------------------------------
void End_Enter() {


    // Change State to Update
    Global_StateMachine = END_UPDATE;
}


void End_Update() {

}


void End_Draw() {

}