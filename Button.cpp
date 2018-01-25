#include"Button.h"
Button::Button(int x, int y, int w, int h){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	Normal();
	SetHoverColor(200,200,200);
	SetClickColor(150,150,200);	
	SetNormalColor(50,200,200);
}
void Button::Draw(){
	SDL_SetRenderDrawColor(Screen.GetRenderer(),Colors[state].r, Colors[state].g, Colors[state].b,0xff);
	SDL_RenderFillRect(Screen.GetRenderer(),&rect);
}
void Button::HandleEvent(SDL_Event&event){
	if(CheckInside(event.motion.x,event.motion.y)){
		Onhover();
		if(event.type == SDL_MOUSEBUTTONUP)
			Onclick();
	}else{
		Normal();
	}
}

void Button::SetPosition(int x, int y){
	rect.x = x;
	rect.y = y;
}

void Button::Onhover(){
	state = HOVER;
}
void Button::Onclick(){
	state = CLICK;
	clicked = true;
}
void Button::Normal(){
	state = NORMAL;
	clicked = false;
}
bool Button::IsClicked(){
	return clicked;	
}
bool Button::CheckInside(int x, int y){
	if(x<rect.x||x>rect.x+rect.w)
		return false;
	if(y<rect.y||y>rect.y+rect.h)
		return false;
	return true;
}

SDL_Rect&Button::GetRect(){
	return rect;
}

void Button::SetNormalColor(int r, int g, int b){
	Colors[NORMAL].r =r;
	Colors[NORMAL].g = g;
	Colors[NORMAL].b = b;
}
void Button::SetHoverColor(int r, int g, int b){
	Colors[HOVER].r =r;
	Colors[HOVER].g = g;
	Colors[HOVER].b = b;
}
void Button::SetClickColor(int r, int g, int b){
	Colors[CLICK].r =r;
	Colors[CLICK].g = g;
	Colors[CLICK].b = b;
}
