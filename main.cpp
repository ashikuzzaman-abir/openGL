#include <iostream>
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

/*=======SDL2=======*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

using namespace std;


bool isRunning = true;

int main(int argc, char* argv[])
{
    //Error Checking/Initialisation
    if (SDL_Init(SDL_INIT_NOPARACHUTE & SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return -1;
    }
    else
    {
        //Specify OpenGL Version (4.2)
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_Log("SDL Initialised");
    }

    //Create Window Instance
    SDL_Window* window = SDL_CreateWindow(
        "Game Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_OPENGL
    );

    //Check that the window was succesfully created
    if(window == NULL)
    {
        //Print error, if null
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    else
        SDL_Log("Window Successful Generated");


    //Map OpenGL Context to Window
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    //Render
    while (isRunning){
    // Swap Render Buffers
    glClearColor(255.0f, 250.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    
    SDL_GL_SwapWindow(window);
    SDL_GL_DeleteContext(glContext);
    //Free up resources
    SDL_Quit();

    //

    // glUseProgram(theProgram);

    // glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    // glEnableVertexAttribArray(0);
    // glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

    // glDrawArrays(GL_TRIANGLES, 0, 3);

    // glDisableVertexAttribArray(0);
    // glUseProgram(0);

    // glutSwapBuffers();

    }



    return 0;
}