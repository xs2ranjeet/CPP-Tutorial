#include <iostream>
#include <string>
using namespace  std;

class  MediaPlayer{
public:
	virtual void play(string audioType, string filename) = 0;
};
class AdvanceMediaPlayer{
public:
	virtual void playVlc(string filename) = 0;
	virtual void playMp4(string filename) = 0;
};
class VlcPlayer : public AdvanceMediaPlayer{
public:
	void playMp4(string filename){}
	void playVlc(string filename){
		cout <<"Playing Vlc: "<<filename<<endl;
	}
};
class Mp4Player : public AdvanceMediaPlayer{
public:
	void playVlc(string filename){}
	void playMp4(string filename){
		cout <<"Playing Mp4: "<<filename<<endl;
	}
};
class MediaAdapter: public MediaPlayer
{
	AdvanceMediaPlayer *amp;
public:
	MediaAdapter(string audioType){
		if(audioType.compare("vlc") == 0){
			amp = new  VlcPlayer();
		} 
		else if(audioType.compare("mp4")==0){
			amp = new Mp4Player();
		} 
	}
	void play(string audioType, string filename) {
		if(audioType.compare("vlc") == 0){
			amp->playVlc(filename);
		} 
		else if(audioType.compare("mp4") == 0){
			amp->playMp4(filename);
		} 
	}

};
class AudioPlayer : public MediaPlayer{
	MediaAdapter *ma;
public:
	void play(string audioType, string filename){
		cout <<"audioType: "<<audioType<<endl;
		if(audioType.compare("mp3") == 0){
			cout << "Playing Mp3: "<< filename<<endl;
		}
		else if((audioType.compare("vlc")==0) || (audioType.compare("mp4")==0)){
			cout <<".........................1"<<endl;
			ma = new MediaAdapter(audioType);
			ma->play(audioType, filename);
		}
		else
			cout<<"Invalid media"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	AudioPlayer *ap = new AudioPlayer();
	ap->play("mp3","Song");
	ap->play("mp4","test.mp4");
	ap->play("vlc","Hello.vlc");
	ap->play("avi","Song.avi");
	return 0;
}