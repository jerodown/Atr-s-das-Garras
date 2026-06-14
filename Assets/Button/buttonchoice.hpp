#pragma once
#include <SDL3/SDL.h>
#include <string>
#include <functional>
#include <SDL3/SDL_image.h>
#include "../../include/conditions.hpp"

enum ButtonType {
	CHOICEBUTTON,
	ENUMBUTTON



};


class Button {
private:
	SDL_FRect rect;

public:
	ButtonType type;

	SDL_Texture* texttexture;
	SDL_Texture* texture;

	Button(float x, float y, float w, float h, SDL_Texture* texture,
	SDL_Texture* texttexture,	ButtonType type);

	void render(SDL_Renderer* renderer);
};

void buttontest(SDL_Renderer* renderer);

extern TTF_Font* font;

void ttf();

SDL_Texture* buttontext();