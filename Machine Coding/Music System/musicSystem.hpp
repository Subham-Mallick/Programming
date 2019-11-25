class MusicSystem
{
    State* m_currState;
    public:
        MusicSystem(){ m_currState = new StopState(); }

        void setCurrentState(State *state){
            if(m_currState){
                delete m_currState;
                m_currState = NULL;
            }
            m_currState = state;
        }

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