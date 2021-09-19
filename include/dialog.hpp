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

/*
 * Base class for the dialog system in the game
 */
class DialogSystem {
public:

	/*
	 * Usual class constructor
	 */
	DialogSystem();

	/*
	 * Usual class deconstructor
	 */
	~DialogSystem();

	/*
	 * @return the next line of the dialog
	 */
	void advance();

	/*
	 * @return the bool "endOfDialog"
	 */
	bool getEndOfDialog();

	/*
	 * @return the int "enterKeyPressed"
	 */
	int returnEnterKeyPressed();

	/*
	 * @enum creates custom types of variables for styles of text (globally accessible)
	 */
	enum TEXTSTYLE {Regular, Underline, Bold, Underline_Bold};

	/*
	 * @enum creates custom types of variables for colors (globally accessible)
	 */
	enum SETCOLOR {White, Red, Blue, Green};

	/*
	 * @param load font and dialog filepaths
	 */
	void loadDialogText(std::string fontPath,std::string filePath);

	/*
	 * @return the current line of the dialog file
	 */
	std::string setDialogString();

	/*
	 * @return set and draw the initial Dialog Text (first line of dialog file)
	 */
	void setInitialDialogText();

	/*
	 * @params Text scale and size (x,y,int) of the Dialogue
	 */
	void setDialogTextScale_Size(float xscale,float yscale, int charSize);

	/*
	 * @params Use enum declarations to set style and text color
	 */
	void setDialogTextStyle_Color(TEXTSTYLE style,SETCOLOR textColor);

	/*
	 * @params set the position
	 */
	void setDialogTextPosition(float posx,float posy);

	/*
	 * @params find a phrase in a string; substr stands for substring
	 */
	bool findDialogString(std::string substr);

	/*
	 * @params set the size of the rect box according to x and y
	 */
	void setDialogBoxSize(int sizex,int sizey);

	/*
	 * @params Use enum declarations to set outline, fill color and outline color
	 */
	void setDialogBoxStyle(int outlineThickness, SETCOLOR FillColor, SETCOLOR outlineColor);

	/*
	 * @params Set the position of the rect box
	 */
	void setDialogBoxPosition(float posx, float posy);

	/*
	 * @params Draw the dialog on the main window
	 */
	void drawDialog(std::shared_ptr<sf::RenderWindow> window);

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
