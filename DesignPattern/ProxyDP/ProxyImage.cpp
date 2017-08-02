#include <iostream>
#include <string>
using namespace std;

class Image{
public:
	virtual void display() = 0;
};
class RealImage: public Image{
private:
	string fileName;
public:
	RealImage(string fname):fileName(fname) {
		loadFromDisk(fileName);
	}
	void display(){
		cout<<"Display RealImage: "<< fileName<<endl;
	}
	void loadFromDisk(string fileName){
		cout<<"Loading... Image "<<fileName<<" From disk"<<endl;
	}
};

//Proxy pattern
class ProxyImage:public Image
{
private:
	RealImage *realImage;
	string fileName;
public:
	ProxyImage(string fname):fileName(fname){}
	void display(){
		if(realImage == NULL)
			realImage = new RealImage(fileName);
		realImage->display();
	}	
};

int main(int argc, char const *argv[])
{
	Image *img = new ProxyImage("test.jpeg");
	img->display();
	cout<<"-----------------\n";
	img->display();
	return 0;
}