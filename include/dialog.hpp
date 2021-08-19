#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>

#include <box2d/box2d.h>

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "user_view.hpp"

class DialogSystem {
public:
	DialogSystem();
	~DialogSystem();
	void Advance(std::string FileName);
	void End();
	bool ReturnBoolIsInDialog();

	enum textStyle {Underline, Bold, Underline_Bold};
	enum SetColor {White, Red, Blue, Green};

	void Load_SetDialogText(std::string FontPath,std::string FileName);
	void SetDialogTextScale_Size(float xscale,float yscale, int charSize);
	void SetDialogTextStyle_Color(textStyle style,SetColor textColor);
	void SetDialogTextPosition(float posx,float posy);

	void SetDialogBoxSize(int sizex,int sizey);
	void SetDialogBoxStyle(int outlineThickness, SetColor FillColor, SetColor outlineColor);
	void SetDialogBoxPosition(float posx, float posy);

	void DrawDialog(std::shared_ptr<sf::RenderWindow> window);
private:
	bool isInDialog;
	std::string dialogContent;
	sf::Text dialogText;
	sf::Font dialogFont;
	sf::RectangleShape dialogBox;
};

#endif
