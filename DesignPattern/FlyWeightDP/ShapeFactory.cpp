#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Shape{
public:
	virtual void draw() = 0;
};

class Circle: public Shape{
private:
	int x, y, radius;
	string color;
public:
	Circle(string color){ this->color = color;}
	void setX(int x){ this->x = x;}
	void setY(int y){ this->y = y;}
	void setRadius(int r){ this->radius = r;}
	void draw(){
		cout<<"Circle: Draw()[ Color: "<< color<<", X: "<< x <<", Y: "<<y<<", Radius: "<< radius <<" ]"<<endl;
	}
};
//Flyweight  class
class ShapeFactory
{
private:
	std::unordered_map<std::string, Circle *> circleMap;
public:
	Circle *getCircle(string color){
		Circle *circle = (Circle *)circleMap[color];
		if(circle == NULL){
			circle = new Circle(color);
			circleMap[color] = circle;
			std::cout<<"Creating Circle of color: "<< color<<std::endl;
		}
		return circle;
	}	
};
string colors[] = {"Red","Green","Blue","White","Black"};
int getRandomX(){
	return (int)rand()%100;
}
int getRandomY(){
	return (int)rand()%100+1;
}
string getRandomColor(){
	return colors[rand()%5];
}
int main(int argc, char const *argv[])
{
	ShapeFactory shp;
	
	for(int i = 0; i < 20; i++){
		Circle *circle = (Circle*)shp.getCircle(getRandomColor());
		circle->setX(getRandomX());
		circle->setY(getRandomY());
		circle->setRadius(100);
		circle->draw();
	}

	/* code */
	return 0;
}