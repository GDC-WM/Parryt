#ifndef VIEW_HPP
#define VIEW_HPP


#include <list>
#include <memory>


class Model;


class View : public std::enable_shared_from_this<View> {
public:
	View(void) {};

	View(std::shared_ptr<Model> model) { this->model = model; };

	virtual void update(void) = 0;


protected:
	std::shared_ptr<Model> model;
};


#endif
