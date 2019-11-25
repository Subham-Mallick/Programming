class State
{
    public:
        virtual bool playMusic(MusicSystem *musicSystem){
            std::cout<<"Music cannot be played";
            return false;
        }
        virtual bool stopMusic(MusicSystem *musicSystem){
            std::cout<<"Music cannot be stopped";
            return false;
        }
        virtual bool previousMusic(MusicSystem *musicSystem){
            std::cout<<"Previous music cannot be played";
            return false;
        }
        virtual bool nextMusic(MusicSystem *musicSystem){
            std::cout<<"Next music cannot be played";
            return false;
        }
};

class PlayState: public State
{
    public:
        bool stopMusic(MusicSystem *musicSystem){
            musicSystem->setCurrentState( new StopState() );
            std::cout<<"Music Stopped";
            return true;
        }

        bool previousMusic(MusicSystem *musicSystem){
            std::cout<<"Playing Previous Song";
            return true;
        }

        bool nextMusic(MusicSystem *musicSystem){
            std::cout<<"Playing Next Song";
            return true;
        }
};

class StopState: public State
{
    public:
        bool playMusic(MusicSystem *musicSystem){
            musicSystem->setCurrentState(new PlayState());
            std::cout<<"Playing music";
            return true;
        }
};