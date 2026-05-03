#include<SDL3/SDL.h>
#include "tinyexpr.h"
#include <iomanip>
#include<iostream>
#define max_x 10
#define min_x -10
#define max_y 5
#define min_y -5
#define WIDTH 980
#define HEIGHT 980
void Grid(SDL_Surface * psurface,SDL_Window*pwindow){
    SDL_Rect grid = {0,0,1,1};
    int x_axis = HEIGHT/2;
    int y_axis = WIDTH/2;
    for(int i = 0;i<HEIGHT;++i){
        SDL_FillSurfaceRect(psurface,&grid,0xFFFFFF);
        grid.x = y_axis;
        grid.y = i;
    }
    for(int i = 0;i<WIDTH;++i){
        SDL_FillSurfaceRect(psurface,&grid,0xFFFFFF);
        grid.y = x_axis;
        grid.x = i;
    }
}
void draw_at_grid_coordinates(SDL_Surface* psurface,int x,int y){

    SDL_Rect pxl = {x,y,2,2};
    SDL_FillSurfaceRect(psurface,&pxl,0xFFFFFF);
}
void evaluate_exp(SDL_Window* pwindow,SDL_Surface* psurface,char* exp){
    double pixel_x = 0;
    double eval_x = 0;
    float pixel_y = 0;
    float eval_y = 0;
    double t = 0;
    te_parser parser;
    parser.set_variables_and_functions({{"x",&eval_x},{"t",&t}});
    auto result = parser.evaluate(exp);
    SDL_Rect pixel = {(int)pixel_x,(int)pixel_y,1,1};
    while (pixel_x<=WIDTH){
        eval_x = (2*max_x*pixel_x/WIDTH) - max_x;
        eval_y = -(parser.evaluate());
        pixel_y = ((eval_y+max_y)*HEIGHT)/(2*max_y);
        draw_at_grid_coordinates(psurface,(int)pixel_x,(int)pixel_y);
        SDL_UpdateWindowSurface(pwindow);
        SDL_Delay(3);
        t+=2;
        pixel_x+=1;//this is the main logic this while loop
    }
}

int main(int argc,char* argv[]){
    
    te_parser parser;
    auto a = parser.evaluate("10+10");
    SDL_Window* pwindow = SDL_CreateWindow("plotter",WIDTH,HEIGHT,0);
    SDL_Surface * psurface = SDL_GetWindowSurface(pwindow);
    
    Grid(psurface,pwindow);
    if (argc >= 2){
        evaluate_exp(pwindow,psurface,argv[1]);
    }
    SDL_UpdateWindowSurface(pwindow);
    
    bool running = true;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                running = false;
            }
        SDL_UpdateWindowSurface(pwindow);
        }
    }
}
