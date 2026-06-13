#include "buttonchoice.hpp"


Button::Button(
    float x,
    float y,
    float w,
    float h,
    SDL_Texture* texture,
SDL_Texture* texttexture)
{
    rect = { x, y, w, h };
    this->texture = texture;
    this->texttexture = texttexture;
}
void Button::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderTexture(renderer, texture, nullptr, &rect);

    SDL_FRect textrect = {
    rect.x + 20,
    rect.y + 10,
    200,
    40
    };
    SDL_RenderTexture(renderer, texttexture, nullptr, &textrect);
}

TTF_Font* font = nullptr;
void ttf() {
    font = TTF_OpenFont("C:/Atrás das Garras/Assets/Fonts/modern_romance/Modern Romance.otf", 48);
}

SDL_Texture* buttontext() 
{
    SDL_Surface* buttonsurface = IMG_Load("C:/Atrás das Garras/Assets/Sprites/Red Button.png");
    SDL_Texture* buttontexture = SDL_CreateTextureFromSurface(renderer, buttonsurface);
    SDL_DestroySurface(buttonsurface);

 
    return buttontexture;
}