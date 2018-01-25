#include<iostream>
#include"TheScreen.h"
#include"TextRenderer.h"
#include"LetterBox.h"
#include"MiniGame.h"
int main(int argc, char**argv){
	std::cout<<"Hello ngat trau\n";

	Screen.CreateWindow();
	Text.Setup();

	Game.Setup("Hello world from SDL");
	bool running = true;
	
	Button ExitButton(Screen.GetSize().w-70,20,50,50);
	ExitButton.SetNormalColor(229, 115, 115);
	ExitButton.SetHoverColor(211, 47, 47);
	ExitButton.SetClickColor(62, 39, 35);
	
	SDL_Event event;
	while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				running = false;
			Game.HandleEvent(event);
			ExitButton.HandleEvent(event);
			if(ExitButton.IsClicked())
				running = false;
		}
		SDL_SetRenderDrawColor(Screen.GetRenderer(),0xff,0xff,0xff,0xff);
		SDL_RenderClear(Screen.GetRenderer());
		Game.Draw();
		ExitButton.Draw();
		SDL_RenderPresent(Screen.GetRenderer());
	}
	return 0;
}