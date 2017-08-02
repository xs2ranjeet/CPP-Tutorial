#include <iostream>
#include <string>
using namespace std;
enum LOGLEVEL
{
	INFO = 0, DEBUG, ERROR
};
class AbstractLogger{
protected:
	int loglevel;
	AbstractLogger *nextLogger;
public:
	void setNextLogger(AbstractLogger *nextLogger){ this->nextLogger = nextLogger;}
	void logMessage(int level, string msg){
		if(this->loglevel <= level)
			write(msg);
		if(nextLogger != NULL)
			nextLogger->logMessage(level, msg);
	}
private:
	virtual void write(string msg) = 0;
};
class ConsoleLogger:public AbstractLogger{
public:
	ConsoleLogger(int level){this->loglevel = level;}
private:
	void write(string msg){
		std::cout<<"Standard Console::Logger: "<< msg<<std::endl;
	}
};
class ErrorLogger:public AbstractLogger{
public:
	ErrorLogger(int level){this->loglevel = level;}
private:
	void write(string msg){
		std::cout<<"Error Console::Logger: "<<msg<<std::endl;
	}
};
class FileLogger:public AbstractLogger{
public:
	FileLogger(int level){this->loglevel = level;}
private:
	void write(string msg){
		std::cout<<"File Console::Logger: "<<msg<<std::endl;
	}
};
AbstractLogger * getChainOfLoggers(){
	AbstractLogger *errLogger= new ErrorLogger(LOGLEVEL::ERROR);
	AbstractLogger *fileLogger= new FileLogger(LOGLEVEL::DEBUG);
	AbstractLogger *consoleLogger= new ConsoleLogger(LOGLEVEL::INFO);
	errLogger->setNextLogger(fileLogger);
	fileLogger->setNextLogger(consoleLogger);
	return errLogger;

}
int main(int argc, char const *argv[])
{
	 AbstractLogger *loggerChain = getChainOfLoggers();

      loggerChain->logMessage(LOGLEVEL::INFO, 
         "This is an information.");

      loggerChain->logMessage(LOGLEVEL::DEBUG, 
         "This is an debug level information.");

      loggerChain->logMessage(LOGLEVEL::ERROR, 
         "This is an error information.");
	return 0;
}