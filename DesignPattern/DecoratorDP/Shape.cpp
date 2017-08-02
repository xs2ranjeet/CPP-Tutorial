#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
};

class Circle : public Shape{
public:
	void draw(){
		cout<< "Shape: Circle"<<endl;
	}
};
class Rectangle : public Shape{
public:
	void draw(){
		cout<< "Shape: Rectangle"<<endl;
	}
};

class ShapeDecorator:public Shape{
protected:
	Shape *shape;
public:
	ShapeDecorator(Shape *shape){
		this->shape = shape;
	}
	virtual void draw() = 0;
};
class RedShapeDecorator: public ShapeDecorator{

public:
	RedShapeDecorator(Shape *shape):ShapeDecorator(shape){

	}
	void draw(){
		cout<<"Red Color Draw"<<endl;
		shape->draw();
	}
};
int main(int argc, char const *argv[])
{
	Shape *circle = new Circle();
	Shape *rectangle =  new Rectangle();
	circle->draw();
	rectangle->draw();
	ShapeDecorator *shp = new RedShapeDecorator(circle);
	shp->draw();
	ShapeDecorator *shp1 = new RedShapeDecorator(rectangle);
	shp1->draw();
	
	return 0;
}