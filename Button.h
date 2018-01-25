#ifndef BUTTON_H
#define BUTTON_H
#include<SDL2/SDL.h>
#include"TheScreen.h"
enum State{
	NORMAL,
	HOVER,
	CLICK,
	STATE_NUM
};

class Button{
	bool clicked;
	bool hovered;
	SDL_Rect rect;
	SDL_Color Colors[STATE_NUM];
	int state;
public:
	Button(int x, int y, int w, int h);	
	virtual ~Button(){}
	virtual void Draw();
	void HandleEvent(SDL_Event&event);
	void SetPosition(int x, int w);

	void Onhover();
	void Onclick();
	void Normal();
	bool IsClicked();
	bool CheckInside(int x, int y);
	SDL_Rect&GetRect();
	void SetNormalColor(int r, int g, int b);
	void SetHoverColor(int r, int g, int b);
	void SetClickColor(int r, int g, int b);
};
#endif//BUTTON_H