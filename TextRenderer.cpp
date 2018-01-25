#include"TextRenderer.h"
TextRenderer::TextRenderer(){
}
void TextRenderer::Setup(){
	if(TTF_Init()<0)
		std::cout<<"Error "<<TTF_GetError()<<"\n";
	font = TTF_OpenFont("data/Anaphora-Bold-trial.ttf",200);
	if(!font){
		std::cout<<"TTF_OpenFont: "<<TTF_GetError()<<"\n";
		//handle Error
	}else{
		std::cout<<"Open font successfully\n";
	}
	texture = NULL;
	SetColor(0,0,0);
}
TextRenderer::~TextRenderer(){
	if(texture!=NULL){
		SDL_DestroyTexture(texture);
		texture = NULL;
	}

	TTF_CloseFont(font);
	font = NULL;//To be safe...
	TTF_Quit();
}
TextRenderer&TextRenderer::Instance(){
	static TextRenderer instance;
	return instance;
}
void TextRenderer::Render(std::string text, int x, int y, int size,bool center){
	SDL_Surface *text_surface;
	if(texture!=NULL)
		SDL_DestroyTexture(texture);
	if(!(text_surface=TTF_RenderText_Solid(font,text.c_str(),color))){
		//handle error here
	}else{
		int w = text.length()*size/2;
		if(center){
			int wW,wH;
			SDL_GetWindowSize(Screen.GetWindow(),&wW,&wH);
			x = wW/2 - w/2;
		}
		
		SDL_Rect rect = {x,y,w,size};
		texture = SDL_CreateTextureFromSurface(Screen.GetRenderer(),text_surface);
		SDL_RenderCopy(Screen.GetRenderer(),texture,NULL,&rect);
	}
	SDL_FreeSurface(text_surface);
}

void TextRenderer::SetColor(int r, int g, int b){
	color.r = r;
	color.g = g;
	color.b = b;
}
SDL_Color TextRenderer::GetColor()const{
	return color;
}
