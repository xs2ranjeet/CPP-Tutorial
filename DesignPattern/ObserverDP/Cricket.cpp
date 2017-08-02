#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Observer{
public:
	virtual void update(int runs, int wicket, float overs) = 0;
};
class Subject{
public:
	virtual void registerObserver(Observer *o) = 0;
	virtual void unregisterObserver(Observer *o) = 0;
	virtual void notifyObservers() = 0;
};
class CricketData : public Subject{
private:
	int runs, wickets;
	float overs;
	std::list<Observer *> *observerList;
public:
	CricketData(){
		observerList = new std::list<Observer *>();
	}
	void registerObserver(Observer *o){
		observerList->push_back(o);
	}
	void unregisterObserver(Observer *o){
		observerList->remove(o);
	}
	void notifyObservers(){
		std::list<Observer *>::iterator it = observerList->begin();
		for(it = observerList->begin(); it != observerList->end(); it++){
			Observer *o = (Observer *)*it;
			o->update(runs, wickets, overs);
		}
	}
	void dataChanged(){
		runs = getLatestRuns();
		wickets = getLatestWicket();
		overs = getLatestOver();
		notifyObservers();
	}
private:
	int getLatestRuns(){ return 90;}
	int getLatestWicket(){ return 2;}
	float getLatestOver() { return 12.4;}
};


class AverageScoreDisplay:public Observer{
private:
	float runRate;
	int predictedScore;
public:
	void update(int runs, int wicket, float overs){
		this->runRate = (float) runs/overs;
		this->predictedScore = (int)(this->runRate *50);
		display();
	}
	void  display(){
		cout<<"\nAvg Score Display: \nRun Rate: "<< runRate<<"\nPredictedScore: "<< predictedScore<<endl;
	}
};
class CurrentScoreDisplay:public Observer{
private:
	float overs;
	int runs,  wickets;
public:
	void update(int runs, int wicket, float overs){
		this->runs = runs;
		this->wickets = wickets;
		this->overs = overs;
		display();
	}
	void  display(){
		cout<<"\nCurrent Score Display: \nRun: "<< runs <<"\nWickets: "<<wickets<<"\nOvers: "<<overs<< endl;
	}
};

int  main(int argc, char const *argv[])
{
	AverageScoreDisplay *avg = new AverageScoreDisplay();
	CurrentScoreDisplay *curr = new CurrentScoreDisplay();

	CricketData *cric = new CricketData();
	cric->registerObserver(avg);
	cric->registerObserver(curr);

	cric->dataChanged();
	cric->unregisterObserver(avg);
	cric->dataChanged();
	return 0;
}