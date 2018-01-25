#ifndef MINI_GAME_H
#define MINI_GAME_H
#include"LetterBox.h"
#include<vector>
class MiniGame{
	MiniGame();

	MiniGame(const MiniGame&);
	MiniGame*operator=(const MiniGame&);
	std::vector<LetterBox*>LetterBoxes;
	std::string KeyWord;
	void PutSingleWord(std::string word, int centerX, int centerY, int boxSize);
	void ShowAll();
	Button ShowAllButton;
	std::string Question;
public:
	~MiniGame();
	static MiniGame&Instance();
	void Setup(std::string keyWord = "Hello world");
	void Draw();
	void HandleEvent(SDL_Event&event);

};
#define Game MiniGame::Instance()
#endif//MINI_GAME_H