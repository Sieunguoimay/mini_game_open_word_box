#include"MiniGame.h"
#include<sstream>
#include<string>
#include<fstream>
MiniGame::MiniGame()
:ShowAllButton(Screen.GetSize().w/2-200,Screen.GetSize().h - 100,400,50){
	ShowAllButton.SetNormalColor(156, 204, 101 );
	ShowAllButton.SetHoverColor(85, 139, 47 );
	ShowAllButton.SetClickColor(27, 94, 32);
}
MiniGame::~MiniGame(){
	for(auto&b:LetterBoxes)
		delete b;
}
MiniGame&MiniGame::Instance(){
	static MiniGame instance;
	return instance;
}
void MiniGame::PutSingleWord(std::string word, int centerX, int centerY, int boxSize){
	int word_length = word.length();
	for(int i = 0; i<word_length;i++){
		if(word[i]!=' '){
			char s[1];
			s[0] = word[i];
			std::string ss = s;
			ss.assign(s,0,1);
			float x = (float)centerX-((float)word_length*0.5f-(float)i)*boxSize;
			LetterBoxes.push_back(new LetterBox(ss,
				(int)x,centerY-boxSize/2,boxSize,boxSize));
		}
	}

}
void MiniGame::Setup(std::string keyWord){
	//load from .txt file
	std::ifstream file("data/content.txt",std::ifstream::in);
	
	std::getline(file,Question);
	std::getline(file,KeyWord);

	file.close();

	if(KeyWord.empty())
		KeyWord = keyWord;

	int w,h;
	int boxSize = 150;
	SDL_GetWindowSize(Screen.GetWindow(),&w,&h);
	const unsigned int MAX_WORD_LENGTH = w/boxSize;

	std::vector<std::string>words;
	std::cout<<KeyWord<<"\n";
	std::stringstream ss(KeyWord);
	std::string a;
	while(!ss.eof()){
		ss>>a;
		std::cout<<a<<"\n";
		if(!words.empty()){
			if(words.at(words.size()-1).length()+a.length()<MAX_WORD_LENGTH){
				words.at(words.size()-1)+=a;
				continue;
			}
		}
		words.push_back(a);
	}
	float y = (float)h*0.5f-(float)(words.size()*boxSize)*0.5f+boxSize*0.5f;
	for(size_t i = 0; i<words.size();i++){
		PutSingleWord(words[i],w/2,y+i*boxSize,boxSize);
	}
}
void MiniGame::Draw(){
	Text.Render("MiniGame",10,20,50);
	Text.Render(Question,0,Screen.GetSize().h*0.1,50,true);
	for(auto&b:LetterBoxes)
		b->Draw();
	ShowAllButton.Draw();
}
void MiniGame::HandleEvent(SDL_Event&event){
	for(auto&b:LetterBoxes)
		b->HandleEvent(event);
	ShowAllButton.HandleEvent(event);
	if(ShowAllButton.IsClicked())
		ShowAll();
}

void MiniGame::ShowAll(){
	for(auto&b:LetterBoxes)
		b->Onclick();
}
