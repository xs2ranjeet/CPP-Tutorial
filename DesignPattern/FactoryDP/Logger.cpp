#include <iostream>
#include <string>
using namespace std;

class AppLogger
{
public:
	virtual void log(string text) = 0;	
};

class FileLogger : public AppLogger
{
public:
	void log(string text){
		cout<< text <<endl;
	}
};
class DatabaseLogger : public AppLogger
{
public:
	void log(string text){
		cout<< text <<endl;
	}
};
class ConsoleLogger : public AppLogger
{
public:
	void log(string text){
		cout<< text <<endl;
	}
};
class LoggerFactory
{
public:
	LoggerFactory(){}
	~LoggerFactory(){}
	AppLogger *getLogger(int type){
		switch(type){
			case 1: return new FileLogger();
			case 2: return new DatabaseLogger();
			case 3: return new ConsoleLogger();
			default:  return NULL;
		}
	}
};

int main(){
	LoggerFactory lg;
	AppLogger *file = lg.getLogger(1);
	AppLogger *db = lg.getLogger(2);
	AppLogger *con = lg.getLogger(3);
	file->log("file  log");
	db->log("DB log");
	con->log("Console log");
	delete file;
	delete db;
	delete con;
}