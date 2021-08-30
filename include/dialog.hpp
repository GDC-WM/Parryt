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
	void Advance();

	/*
	 * @return the bool "endOfDialog"
	 */
	bool GetEndOfDialog();

	/*
	 * @return the int "enterKeyPressed"
	 */
	int ReturnEnterKeyPressed();

	/*
	 * @enum creates custom types of variables for styles of text (globally accessible)
	 */
	enum textStyle {Regular, Underline, Bold, Underline_Bold};

	/*
	 * @enum creates custom types of variables for colors (globally accessible)
	 */
	enum SetColor {White, Red, Blue, Green};

	/*
	 * @param load font and dialog filepaths
	 */
	void LoadDialogText(std::string fontPath,std::string filePath);

	/*
	 * @return the current line of the dialog file
	 */
	std::string GetDialogString();

	/*
	 * @return set and draw the initial Dialog Text (first line of dialog file)
	 */
	void SetInitialDialogText();

	/*
	 * @params Text scale and size (x,y,int) of the Dialogue
	 */
	void SetDialogTextScale_Size(float xscale,float yscale, int charSize);

	/*
	 * @params Use enum declarations to 
	 */
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
