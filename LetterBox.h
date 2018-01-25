#ifndef LETTER_BOX_H
#define LETTER_BOX_H
#include"Button.h"
#include"TextRenderer.h"
class LetterBox:public Button{
	std::string character;
	bool triggered;
public:
	~LetterBox(){}
	LetterBox(std::string character,int x,int y, int w,int h);
	virtual void Draw();
};
#endif//LETTER_BOX_H