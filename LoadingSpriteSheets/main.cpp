
#include "raylib.h"
#include <vector>


const int screenWidth = 1600;
const int screenHeight = 900;
const char* appTitle = "Using Sprite Sheets";
const int fpsCap = 60;
Color bgColor = Color{164,117,160,255};

 void UpdateFrames(float &frameIndex,float frameSpeed,float deltaTime,const int maxFrameCount){

        frameIndex += frameSpeed * deltaTime;
        if(frameIndex > maxFrameCount){
            frameIndex = 0.0f;
        }

}



int main(){

    InitWindow(screenWidth,screenHeight,appTitle);
    SetTargetFPS(fpsCap);

    Image spriteSheet = LoadImage("./images/catspritesx4.gif");

    std::vector<Texture2D>catWalkingFrames;
    std::vector<Rectangle>catWalkingFrameRecs;
    std::vector<Texture2D>catRunningFrames;
    std::vector<Rectangle>catRunningFrameRecs;

    const int maxFrameCount = 6;
    float walkingFrameIndex = 0.0f;
    float runningFrameIndex = 0.0f;
    float walkingFrameSpeed = 12.0f;
    float runningFrameSpeed = 12.0f;


    Vector2 walkframeRecSize = Vector2{72,60};

    catWalkingFrameRecs = {
        Rectangle{7,68,walkframeRecSize.x,walkframeRecSize.y},
        Rectangle{96,70,walkframeRecSize.x,walkframeRecSize.y},
        Rectangle{184,68,walkframeRecSize.x,walkframeRecSize.y},
        Rectangle{271,67,walkframeRecSize.x,walkframeRecSize.y},
        Rectangle{356,70,walkframeRecSize.x,walkframeRecSize.y},
        Rectangle{443,68,walkframeRecSize.x,walkframeRecSize.y}

    };

    catRunningFrameRecs = {
        Rectangle{13,143,75,52},
        Rectangle{99,135,77,61},
        Rectangle{192,143,79,57},
        Rectangle{280,146,80,54},
        Rectangle{372,152,79,48},
        Rectangle{466,151,82,49}
    };

    for(int frameCount = 0; frameCount < maxFrameCount; frameCount++){

        catWalkingFrames.push_back(LoadTextureFromImage(ImageFromImage(spriteSheet,catWalkingFrameRecs[frameCount])));
        catRunningFrames.push_back(LoadTextureFromImage(ImageFromImage(spriteSheet,catRunningFrameRecs[frameCount])));
    }

   


    while(!WindowShouldClose()){
        float deltaTime = GetFrameTime();

        UpdateFrames(walkingFrameIndex,walkingFrameSpeed,deltaTime,maxFrameCount);
        UpdateFrames(runningFrameIndex,runningFrameSpeed,deltaTime,maxFrameCount);

        BeginDrawing();
        ClearBackground(bgColor);

        // DrawTexture(catWalkingFrames[walkingFrameIndex],100,100,WHITE);
        // DrawTexture(catRunningFrames[runningFrameIndex],screenWidth - 500,100,WHITE);

        DrawTextureEx(catWalkingFrames[walkingFrameIndex],Vector2{screenWidth - 500,screenHeight/2.0f},0,4.0f,WHITE);
        DrawTextureEx(catRunningFrames[runningFrameIndex],Vector2{100,screenHeight/2.0f},0,4.0f,WHITE);

        EndDrawing();




    }

    for(auto &walkingFrame : catWalkingFrames){
        UnloadTexture(walkingFrame);
    }
    for(auto &runningFrame : catRunningFrames){
        UnloadTexture(runningFrame);
    }
    catWalkingFrames.clear();
    catRunningFrames.clear();
    catWalkingFrameRecs.clear();
    catRunningFrameRecs.clear();


    CloseWindow();

    return 0;
}
