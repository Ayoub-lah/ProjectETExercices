#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include "raylib.h"
using namespace std ;

int WIDTH = 25;   
int HEIGHT = 25;  
const int CELL_SIZE = 24; 
const int RIGHT_PADDING = 160; 

vector<vector<int>> maze;

void initMaze() {
    maze = vector<vector<int>>(WIDTH, vector<int>(HEIGHT, 1));
}

void generateMaze(int x, int y) {
    maze[x][y] = 0; 
    int directions[] = {0, 1, 2, 3}; 
    random_shuffle(begin(directions), end(directions)); 

    for (int i = 0; i < 4; ++i) {
        int dx = 0, dy = 0;
        switch (directions[i]) {
            case 0: dy = -2; break; 
            case 1: dx = 2; break; 
            case 2: dy = 2; break; 
            case 3: dx = -2; break;
        }

        int nx = x + dx;
        int ny = y + dy;

        if (nx > 0 && nx < WIDTH - 1 && ny > 0 && ny < HEIGHT - 1 && maze[nx][ny] == 1) {
            maze[x + dx / 2][y + dy / 2] = 0; 
            maze[nx][ny] = 0; 
            generateMaze(nx, ny); 
        }
    }
}

void drawMaze(Texture2D wallTexture, Texture2D pathTexture) {
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            if (maze[x][y] == 1) {
                DrawTexture(wallTexture, x * CELL_SIZE, y * CELL_SIZE, WHITE);
            } else {
                DrawTexture(pathTexture, x * CELL_SIZE, y * CELL_SIZE, WHITE);
            }
        }
    }
}

enum GameState {
    MENU,
    LEVEL_SELECTION,
    PLAYING,
    EXIT
};

int main() {
    srand(time(0)); 

    int windowWidth = WIDTH * CELL_SIZE + RIGHT_PADDING;
    int windowHeight = HEIGHT * CELL_SIZE;
    InitWindow(windowWidth, windowHeight, "Maze Game with Levels");
    SetTargetFPS(60);

int playerX = 1, playerY = 1;
    bool win = false;           
    bool timerStarted = false;  
    float startTime = 00.0f;  
    int score = 0;            
    bool gameOver = false;  
    const int screenWidth = 770;
    const int screenHeight = 600;
    
    Texture2D wallTexture = LoadTexture("img/wall.png");    
    Texture2D pathTexture = LoadTexture("img/path.png");    
    Texture2D playerTexture = LoadTexture("img/player.png");
    Texture2D goalTexture = LoadTexture("img/goal.png");    
    Texture2D buttonStart = LoadTexture("img/str.png");
    Texture2D buttonExit = LoadTexture("img/quit.png");
    Texture2D background = LoadTexture("img/back.png");
    Texture2D buttonEasy = LoadTexture("img/facile.png");
    Texture2D buttonMedium = LoadTexture("img/moyen.png");
    Texture2D buttonHard = LoadTexture("img/difficile.png");
    Texture2D niv = LoadTexture("img/niv.png");

    Rectangle restartButton = { WIDTH * CELL_SIZE + 20, 100, 120, 40 };
    Rectangle exitButton = { WIDTH * CELL_SIZE + 20, 160, 120, 40 };

    Rectangle sourceRect = { 0, 0, (float)background.width, (float)background.height };
    Rectangle destRect = { 0, 0, (float)windowWidth, (float)windowHeight };

    Rectangle buttonStartRect = { 100.0f, screenHeight - buttonStart.height - 20.0f, (float)buttonStart.width, (float)buttonStart.height };
    Rectangle buttonExitRect = { screenWidth - buttonExit.width - 100.0f, screenHeight - buttonExit.height - 20.0f, (float)buttonExit.width, (float)buttonExit.height };
    GameState gameState = MENU;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (gameState == MENU) {
            DrawTexturePro(background, sourceRect, destRect, Vector2{ 0, 0 }, 0.0f, WHITE);
            DrawTexture(buttonStart, (int)buttonStartRect.x, (int)buttonStartRect.y, WHITE);
            DrawTexture(buttonExit, (int)buttonExitRect.x, (int)buttonExitRect.y, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), buttonStartRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                gameState = LEVEL_SELECTION;
            }
            if (CheckCollisionPointRec(GetMousePosition(), buttonExitRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                gameState = EXIT;
            }
        } else if (gameState == LEVEL_SELECTION) {
            ClearBackground(BROWN);
            DrawText("Sélectionnez un niveau", windowWidth / 2.5 - 50, 60, 28, WHITE);
        
            Rectangle buttonEasyRect = { (screenWidth - buttonEasy.width) / 2.0f, 200.0f, (float)buttonEasy.width, (float)buttonEasy.height };
            Rectangle buttonMediumRect = { (screenWidth - buttonMedium.width) / 2.0f, 300.0f, (float)buttonMedium.width, (float)buttonMedium.height };
            Rectangle buttonHardRect = { (screenWidth - buttonHard.width) / 2.0f, 400.0f, (float)buttonHard.width, (float)buttonHard.height };

            DrawTexture(buttonEasy, (int)buttonEasyRect.x, (int)buttonEasyRect.y, WHITE);
            DrawTexture(buttonMedium, (int)buttonMediumRect.x, (int)buttonMediumRect.y, WHITE);
            DrawTexture(buttonHard, (int)buttonHardRect.x, (int)buttonHardRect.y, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), buttonEasyRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                WIDTH = 25;
                HEIGHT = 25;
                initMaze();
                generateMaze(1, 1);
                gameState = PLAYING;
            }
            if (CheckCollisionPointRec(GetMousePosition(), buttonMediumRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                WIDTH = 25;
                HEIGHT = 25;
                initMaze();
                generateMaze(3, 4);
                gameState = PLAYING;
            }
            if (CheckCollisionPointRec(GetMousePosition(), buttonHardRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                WIDTH = 25;
                HEIGHT = 28;
                initMaze();
                generateMaze(7, 3);
                gameState = PLAYING;
            }
        } else if (gameState == PLAYING) {
            if (!win && !gameOver) {
            if (IsKeyPressed(KEY_UP) && maze[playerX][playerY - 1] == 0) {
                playerY--;
                if (!timerStarted) {
                    timerStarted = true;
                    startTime = GetTime(); 
                }
                score += 10;
            }
            if (IsKeyPressed(KEY_DOWN) && maze[playerX][playerY + 1] == 0) {
                playerY++;
                if (!timerStarted) {
                    timerStarted = true;
                    startTime = GetTime();
                }
                score += 10;
            }
            if (IsKeyPressed(KEY_LEFT) && maze[playerX - 1][playerY] == 0) {
                playerX--;
                if (!timerStarted) {
                    timerStarted = true;
                    startTime = GetTime();
                }
                score += 10;
            }
            if (IsKeyPressed(KEY_RIGHT) && maze[playerX + 1][playerY] == 0) {
                playerX++;
                if (!timerStarted) {
                    timerStarted = true;
                    startTime = GetTime();
                }
                score += 10;
            }
        }

        if (playerX == WIDTH - 2 && playerY == HEIGHT - 2 && !win) {
            win = true;
        }

        if (!gameOver && timerStarted && GetTime() - startTime > 60) {
            gameOver = true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawMaze(wallTexture, pathTexture); 

        DrawTexture(playerTexture, playerX * CELL_SIZE, playerY * CELL_SIZE, WHITE);

        DrawTexture(goalTexture, (WIDTH - 2) * CELL_SIZE, (HEIGHT - 2) * CELL_SIZE, WHITE);

        float currentTime = timerStarted && !win ? GetTime() - startTime : startTime; 
        DrawText(TextFormat("Temps: %.2f s", currentTime), WIDTH * CELL_SIZE + 20, 20, 20, BLACK);

        DrawText(TextFormat("Score: %d", score), WIDTH * CELL_SIZE + 20, 60, 20, BLACK);

        DrawRectangleRec(restartButton, BROWN);
        DrawText("Restart", restartButton.x + 20, restartButton.y + 10, 20, WHITE);

        DrawRectangleRec(exitButton, BROWN);
        DrawText("Quit", exitButton.x + 40, exitButton.y + 10, 20, WHITE);


        if (CheckCollisionPointRec(GetMousePosition(), restartButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    // Réinitialiser les variables de jeu
    playerX = 1;
    playerY = 1;
    score = 0;
    win = false;
    gameOver = false;
    timerStarted = false;
    startTime = 0.0f;
    
    // Réinitialiser le labyrinthe
    initMaze();
    generateMaze(1, 1);
}

        if (CheckCollisionPointRec(GetMousePosition(), exitButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            CloseWindow(); 
        }

    if (win) {
    DrawRectangle(0, 0, windowWidth, windowHeight, BROWN);
    
    // Texte "You Win" au centre
    const char* winText = "Félicitations, vous avez gagné !";
    int winTextWidth = MeasureText(winText, 40); 
    int winTextX = (windowWidth - winTextWidth) / 2; 
    int winTextY = (windowHeight / 2) - 100; // Plus haut que le centre
    DrawText(winText, winTextX, winTextY, 40, WHITE);
    
    // Texte du temps final au centre
    const char* finalTimeText = TextFormat("Heure finale: %.2f s", currentTime);
    int finalTimeWidth = MeasureText(finalTimeText, 20); 
    int finalTimeX = (windowWidth - finalTimeWidth) / 2;
    int finalTimeY = (windowHeight / 2) - 40; // Position centrale
    DrawText(finalTimeText, finalTimeX, finalTimeY, 20, BLACK);
    
    // Texte du score final au centre
    const char* finalScoreText = TextFormat("Score final: %d", score);
    int finalScoreWidth = MeasureText(finalScoreText, 20); 
    int finalScoreX = (windowWidth - finalScoreWidth) / 2; 
    int finalScoreY = finalTimeY + 40; // Juste en dessous du temps final
    DrawText(finalScoreText, finalScoreX, finalScoreY, 20, BLACK);
    
    // Bouton "Play Again" centré
    Rectangle playAgainButton = { windowWidth / 2 - 60, finalScoreY + 60, 120, 40 };
    Rectangle exitWinButton = { windowWidth / 2 - 60, playAgainButton.y + 60, 120, 40 };
    
    DrawRectangleRec(playAgainButton, WHITE);
    DrawText("Rejouer", playAgainButton.x + 15, playAgainButton.y + 10, 20, BLACK); // Centré par rapport au bouton
    
    DrawRectangleRec(exitWinButton, WHITE);
    DrawText("Quit", exitWinButton.x + 35, exitWinButton.y + 10, 20, BLACK); // Centré par rapport au bouton
    
    // Détection de clic sur les boutons
    if (CheckCollisionPointRec(GetMousePosition(), playAgainButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    //    / Redémarrer le jeu
    gameState = LEVEL_SELECTION;
    }
    if (CheckCollisionPointRec(GetMousePosition(), exitWinButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        CloseWindow(); // Quitter le jeu
    }


}else if (gameOver) {
DrawRectangle(0, 0, windowWidth, windowHeight, BROWN);

// Texte "Game Over!" centré
const char *gameOverText = "Jeu terminé!";
int gameOverTextWidth = MeasureText(gameOverText, 40); 
int gameOverTextX = (windowWidth - gameOverTextWidth) / 2; 
int gameOverTextY = (windowHeight / 2) - 80; // Légèrement au-dessus du centre
DrawText(gameOverText, gameOverTextX, gameOverTextY, 40, RED);

// Texte "Final Score" centré
const char *finalScoreText = TextFormat("Score final: %d", score);
int finalScoreWidth = MeasureText(finalScoreText, 20);
int finalScoreX = (windowWidth - finalScoreWidth) / 2; 
int finalScoreY = (windowHeight / 2) - 40; // Juste en dessous du "Game Over"
DrawText(finalScoreText, finalScoreX, finalScoreY, 20, BLACK);

// Bouton "Play Again" centré
Rectangle restartGameButton = { windowWidth / 2 - 60, (windowHeight / 2) + 20, 120, 40 };
DrawRectangleRec(restartGameButton, WHITE);
DrawText("Rejouer", restartGameButton.x + 20, restartGameButton.y + 10, 20, BLACK);

// Bouton "Exit" centré
Rectangle exitGameButton = { windowWidth / 2 - 60, restartGameButton.y + 60, 120, 40 };
DrawRectangleRec(exitGameButton, WHITE);
DrawText("Quit", exitGameButton.x + 35, exitGameButton.y + 10, 20, BLACK);

// Détection des clics
if (CheckCollisionPointRec(GetMousePosition(), restartGameButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    gameState = LEVEL_SELECTION; // Redémarrer le jeu
}
if (CheckCollisionPointRec(GetMousePosition(), exitGameButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    CloseWindow(); // Quitter le jeu
}


            if (CheckCollisionPointRec(GetMousePosition(), restartGameButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                playerX = 1;
                playerY = 1;
                score = 0;
                win = false;
                gameOver = false;
                generateMaze(1, 1); 
                startTime = 0.0f;
                timerStarted = false;
            }
            if (CheckCollisionPointRec(GetMousePosition(), exitGameButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                CloseWindow();
            }
        }

    } else if (gameState == EXIT) {
            CloseWindow();
            break;
        }

        EndDrawing();
    }

    UnloadTexture(wallTexture);
    UnloadTexture(pathTexture);
    UnloadTexture(playerTexture);
    UnloadTexture(goalTexture);
    UnloadTexture(buttonStart);
    UnloadTexture(buttonExit);

    CloseWindow(); 
    return 0;
}


