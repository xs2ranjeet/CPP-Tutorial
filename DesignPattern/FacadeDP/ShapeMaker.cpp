#include <iostream>
using namespace std;

class Shape{
public:
	virtual void draw() = 0;
};
class Circle: public Shape{
public:
	void draw(){
		cout<<"Circle::Draw"<<endl;
	}
};
class Square: public Shape{
public:
	void draw(){
		cout<<"Square::Draw"<<endl;
	}
};
class Rectangle: public Shape{
public:
	void draw(){
		cout<<"Rectangle::Draw"<<endl;
	}
};
// Create Facade class

class ShapeMaker{
private:
	Shape *circle;
	Shape *rectangle;
	Shape *square;
public:
	ShapeMaker(){
		circle = new Circle();
		rectangle = new Rectangle();
		square = new Square();
	}
	void drawCircle(){
		circle->draw();
	}
	void drawRectangle(){
		rectangle->draw();
	}
	void drawSquare(){
		square->draw();
	}
};

int main(int argc, char const *argv[])
{
	ShapeMaker shp;
	shp.drawCircle();
	shp.drawSquare();
	shp.drawRectangle();
	return 0;
}