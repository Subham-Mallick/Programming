#include<bits/stdc++.h>
using namespace std;

class MusicSystem;
class State;
class PlayState;
class StopState;

class State
{
    public:
        virtual bool playMusic(MusicSystem *musicSystem){
            std::cout<<"Music cannot be played\n";
            return false;
        }
        virtual bool stopMusic(MusicSystem *musicSystem){
            std::cout<<"Music cannot be stopped\n";
            return false;
        }
        virtual bool previousMusic(MusicSystem *musicSystem){
            std::cout<<"Previous music cannot be played\n";
            return false;
        }
        virtual bool nextMusic(MusicSystem *musicSystem){
            std::cout<<"Next music cannot be played\n";
            return false;
        }
};

class PlayState: public State
{
    public:
        bool stopMusic(MusicSystem *musicSystem);
        bool previousMusic(MusicSystem *musicSystem){
            std::cout<<"Playing Previous Song\n";
            return true;
        }
        bool nextMusic(MusicSystem *musicSystem){
            std::cout<<"Playing Next Song\n";
            return true;
        }
};

class StopState: public State
{
    public:
        bool playMusic(MusicSystem *musicSystem);
};

class MusicSystem
{
    State* m_currState;
    public:
        MusicSystem();

        void setCurrentState(State *state);

        bool playMusic(){
            if(m_currState)
                return m_currState->playMusic(this);
            return false;
        }

        bool stopMusic(){
            if(m_currState)
                return m_currState->stopMusic(this);
            return false;
        }

        bool previousMusic(){
            if(m_currState)
                return m_currState->previousMusic(this);
            return false;
        }

        bool nextMusic(){
            if(m_currState)
                return m_currState->nextMusic(this);
            return false;
        }

};

bool PlayState::stopMusic(MusicSystem *musicSystem){
    musicSystem->setCurrentState( new StopState() );
    std::cout<<"Music Stopped\n";
    return true;
}

bool StopState::playMusic(MusicSystem *musicSystem){
    musicSystem->setCurrentState(new PlayState());
    std::cout<<"Playing music\n";
    return true;
}

MusicSystem::MusicSystem(){ 
    m_currState = new StopState(); 
}

void MusicSystem::setCurrentState(State *state){
    if(m_currState){
        delete m_currState;
        m_currState = NULL;
    }
    m_currState = state;
}

int main() {
    MusicSystem obj;
    obj.playMusic();
    obj.nextMusic();
    obj.stopMusic();
    obj.previousMusic();
    obj.playMusic();   
}