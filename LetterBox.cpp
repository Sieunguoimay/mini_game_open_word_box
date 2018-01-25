#include"LetterBox.h"
LetterBox::LetterBox(std::string character,int x,int y, int w,int h)
:Button(x,y,w,h),character(character){
	triggered = false;
}
void LetterBox::Draw(){
	int w = GetRect().w*0.1;
	SDL_Rect rect2 = {GetRect().x-w,GetRect().y-w,GetRect().w+2*w,GetRect().h+2*w};
	SDL_SetRenderDrawColor(Screen.GetRenderer(),0xff,250,200,0xff);
	SDL_RenderFillRect(Screen.GetRenderer(),&rect2);
	Button::Draw();
	if(IsClicked())
		triggered = true;
	if(triggered){
		Text.Render(character,GetRect().x+GetRect().w*0.2f,GetRect().y,GetRect().w*1.2);
	}
}
