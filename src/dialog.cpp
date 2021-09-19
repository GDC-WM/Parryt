#include "dialog.hpp"

DialogSystem::DialogSystem() {

}

DialogSystem::~DialogSystem() {}

int DialogSystem::returnEnterKeyPressed() {
	return this->enterKeyPressed = this->enterKeyPressed + 1;
}

void DialogSystem::loadDialogText(std::string fontPath, std::string fileName) {

	dialogFont.~Font();
	dialogFont.loadFromFile(fontPath);
	dialogText.setFont(dialogFont);
	this->fileName = fileName;
	//DialogSystem::SetInitialDialogText();

}

void DialogSystem::setInitialDialogText(){
	
	if (this->enterKeyPressed == 0) {

		this->input.open(this->fileName, std::ios::in);
		getline(this->input,this->dialogContent);
		this->dialogText.setString(this->dialogContent);
		returnEnterKeyPressed();

	} else 
		return;
	//this->input.close();

}

void DialogSystem::advance() {

	//this->input.open(this->fileName, std::ios::in);

	if (getline(this->input, this->dialogContent) && this->dialogContent != "") {

		this->endOfDialog = false;
		this->dialogText.setString(this->dialogContent);

		// std::cout << "enter:" << enterKeyPressed << std::endl; //debugging
		// std::string msg = this->dialogText.getString(); //debugging
		// std::cout << msg << std::endl; //debugging

	} else {

		this->dialogText.setString("");
		this->dialogContent.clear();
		//this->game->toggleDialog(); //currently segfaults
		this->input.close();
		this->endOfDialog = true;
		return;

	}

}

bool DialogSystem::getEndOfDialog() {

	return this->endOfDialog;

}

void DialogSystem::setDialogTextScale_Size(float xscale, float yscale, int charSize) {

	dialogText.setScale(xscale, yscale);
	dialogText.setCharacterSize(charSize);

}

void DialogSystem::setDialogTextStyle_Color(textStyle style, setColor textColor) {

	switch (style) {
		case Regular:
			dialogText.setStyle(sf::Text::Regular);
			break;
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

void DialogSystem::setDialogTextPosition(float posx,float posy) {

	dialogText.setPosition(posx, posy);

}

bool DialogSystem::findDialogString(std::string substr) {
	
	std::string line = this->dialogText.getString();
	if (line.find(substr) != std::string::npos)
		return true;

	return false;
}

void DialogSystem::setDialogBoxStyle(int outlineThickness, setColor FillColor, setColor outlineColor) {

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

void DialogSystem::setDialogBoxSize(int sizex,int sizey) {

	dialogBox.setSize(sf::Vector2f(sizex,sizey));

}

void DialogSystem::setDialogBoxPosition(float posx, float posy) {
	dialogBox.setPosition(sf::Vector2f(posx,posy));
}

void DialogSystem::drawDialog(std::shared_ptr<sf::RenderWindow> window) {

	window->draw(dialogBox);
	window->draw(dialogText);

}
