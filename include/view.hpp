#ifndef VIEW_HPP
#define VIEW_HPP


#include <list>
#include <memory>


class Model;


class View {
public:
	View(std::shared_ptr<Model> model);

	virtual void update(const float &dt) = 0;


protected:
	std::shared_ptr<Model> model;
};


#endif
