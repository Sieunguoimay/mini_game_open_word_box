#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H
#include<SDL2/SDL_ttf.h>
#include"TheScreen.h"
#include<iostream>
#include<string>
class TextRenderer{
	TextRenderer();

	TextRenderer(const TextRenderer&);
	TextRenderer*operator=(const TextRenderer&);

	TTF_Font*font;
	SDL_Texture*texture;
	SDL_Color color;
public:
	~TextRenderer();
	static TextRenderer&Instance();
	void Setup();
	void Render(std::string text, int x, int y, int size = 10,bool center = false);
	void SetColor(int r, int g, int b);
	SDL_Color GetColor()const;
};
#define Text TextRenderer::Instance()
#endif//TEXT_RENDERER_H