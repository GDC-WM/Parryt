#include "dialog.hpp"

DialogSystem::DialogSystem() {

}

DialogSystem::~DialogSystem() {}

bool DialogSystem::ReturnBoolIsInDialog() {
	return this->game->isInDialogMode();
}

int DialogSystem::ReturnEnterKeyPressed() {
	return this->enterKeyPressed = this->enterKeyPressed + 1;
}

void DialogSystem::LoadDialogText(std::string fontPath, std::string fileName) {

	dialogFont.~Font();
	dialogFont.loadFromFile(fontPath);
	dialogText.setFont(dialogFont);

	this->fileName = fileName;
	
	//DialogSystem::SetInitialDialogText();

}

void DialogSystem::SetInitialDialogText(){

	this->input.open(this->fileName, std::ios::in);
	getline(this->input,this->dialogContent);
	this->input.close();
	this->dialogText.setString(this->dialogContent);
	this->dialogContent.clear();
	this->enterKeyPressed = this->enterKeyPressed + 1;

}

void DialogSystem::Advance() {

	this->input.open(this->fileName, std::ios::in);
	
	for (int i = 0; i <= this->enterKeyPressed; ++i)
		getline(this->input, this->dialogContent);
		//std::cout << "i:" << i << std::endl; //debugging

	this->input.close();

	//Check input

	if (this->dialogContent != "") {

		std::cout << "enter:" << enterKeyPressed << std::endl; //debugging

		this->dialogText.setString(this->dialogContent);

		ReturnEnterKeyPressed();

	} else {

		this->dialogText.setString("");
		this->dialogContent.clear();
		//this->game->toggleDialog(); //currently segfaults
		return;

	}

}

void DialogSystem::End() {

	dialogText.setString("");

}

void DialogSystem::SetDialogTextScale_Size(float xscale,float yscale, int charSize) {

	dialogText.setScale(xscale, yscale);
	dialogText.setCharacterSize(charSize);

}

void DialogSystem::SetDialogTextStyle_Color(textStyle style,SetColor textColor) {

	switch (style) {
		case Underline:
			dialogText.setStyle(sf::Text::Underlined);
			break;
		case Bold:
			dialogText.setStyle(sf::Text::Bold);
			break;
		case Underline_Bold:
			dialogText.setStyle(sf::Text::Underlined | sf::Text::Bold);
			break;
		default:
			break;
	}
	
	switch (textColor) {
		case White:
			dialogText.setFillColor(sf::Color::White);
			break;
		case Red:
			dialogText.setFillColor(sf::Color::Red);
			break;
		case Blue:
			dialogText.setFillColor(sf::Color::Blue);
			break;
		case Green:
			dialogText.setFillColor(sf::Color::Green);
			break;
		default:
			break;
	}

}

void DialogSystem::SetDialogTextPosition(float posx,float posy) {

	dialogText.setPosition(posx, posy);

}

void DialogSystem::SetDialogBoxStyle(int outlineThickness, SetColor FillColor, SetColor outlineColor) {

	dialogBox.setOutlineThickness(outlineThickness);

	switch (FillColor) {
		case White:
			dialogBox.setFillColor(sf::Color::White);
			break;
		case Red:
			dialogBox.setFillColor(sf::Color::Red);
			break;
		case Blue:
			dialogBox.setFillColor(sf::Color::Blue);
			break;
		case Green:
			dialogBox.setFillColor(sf::Color::Green);
			break;
		default:
			break;
	}

	switch (outlineColor) {
		case White:
			dialogBox.setOutlineColor(sf::Color::White);
			break;
		case Red:
			dialogBox.setOutlineColor(sf::Color::Red);
			break;
		case Blue:
			dialogBox.setOutlineColor(sf::Color::Blue);
			break;
		case Green:
			dialogBox.setOutlineColor(sf::Color::Green);
			break;
		default:
			break;
	}
	
}

void DialogSystem::SetDialogBoxSize(int sizex,int sizey) {

	dialogBox.setSize(sf::Vector2f(sizex,sizey));

}

void DialogSystem::SetDialogBoxPosition(float posx, float posy) {
	dialogBox.setPosition(sf::Vector2f(posx,posy));
}

void DialogSystem::DrawDialog(std::shared_ptr<sf::RenderWindow> window) {

	window->draw(dialogBox);
	window->draw(dialogText);

}
