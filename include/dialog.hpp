#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>

#include <box2d/box2d.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>

#include "game_controller.hpp"

class DialogSystem {
public:
	DialogSystem();
	~DialogSystem();
	void Advance();
	void End();
	bool GetEndOfDialog();
	int ReturnEnterKeyPressed();
	enum textStyle {Regular, Underline, Bold, Underline_Bold};
	enum SetColor {White, Red, Blue, Green};

	void LoadDialogText(std::string fontPath,std::string filePath);
	std::string GetDialogString();
	void SetInitialDialogText();
	void SetDialogTextScale_Size(float xscale,float yscale, int charSize);
	void SetDialogTextStyle_Color(textStyle style,SetColor textColor);
	void SetDialogTextPosition(float posx,float posy);
	bool FindDialogString(std::string substr);

	void SetDialogBoxSize(int sizex,int sizey);
	void SetDialogBoxStyle(int outlineThickness, SetColor FillColor, SetColor outlineColor);
	void SetDialogBoxPosition(float posx, float posy);

	void DrawDialog(std::shared_ptr<sf::RenderWindow> window);
private:
	std::shared_ptr<GameController> game;
	std::string dialogContent;
	sf::Text dialogText;
	sf::Font dialogFont;
	sf::RectangleShape dialogBox;
	std::ifstream input;
	std::string fileName;
	int enterKeyPressed = 0;
	bool endOfDialog = false;
};

#endif
