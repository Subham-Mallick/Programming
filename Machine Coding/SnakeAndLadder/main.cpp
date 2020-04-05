#include<bits/stdc++.h>
using namespace std;


//----------------MODEL----------------

class Ladder{
    private:
        int start;
        int end;

    public:
        Ladder(int start,int end){
            this->start = start;
            this->end = end;
        }

        int getStart()
        {
            return this->start;
        }

        int getEnd()
        {
            return this->end;
        }
};


class Player{
    private:
        std::string name;
    public:
        Player(std::string name){
            this->name = name;
        }
        
        std::string getName() {
            return this->name;
        }
};

class Snake{
    private:
        int start;
        int end;

    public:
        Snake(int start,int end){
            this->start = start;
            this->end = end;
        }

        int getStart()
        {
            return this->start;
        }

        int getEnd()
        {
            return this->end;
        }
};

class Board{
    private:
        int size;
        list<Ladder> ladders;
        list<Snake> snakes;
        unordered_map<std::string,int> playerPosition;

    public:
        Board(int size){
            this->size = size;
        }

        int getSize() {
            return this->size;
        }
        void setSize(int size) {
            this->size = size;
        }

        list<Ladder> getLadders() {
        	return this->ladders;
        }
        void setLadders(list<Ladder> ladders) {
        	this->ladders = ladders;
        }

        list<Snake> getSnakes() {
        	return this->snakes;
        }
        void setSnakes(list<Snake> snakes) {
        	this->snakes = snakes;
        }

        unordered_map<std::string,int> getPlayerPosition() {
        	return this->playerPosition;
        }
        void setPlayerPosition(unordered_map<std::string,int> playerPosition) {
        	this->playerPosition = playerPosition;
        }
};

//----------------SERVICES----------------
int diceRoll(){
    // srand(time(0));
    return rand()%6 + 1;
}

void printPosition(std::string name,int start,int end){
    cout<<"Player : "<<name<<" moved from "<<start<<" to "<<end<<endl;
}

class GameInitialize{
    private:
        Board *board;
        int numberOfPlayers;
        queue<Player> players;
    public:
        GameInitialize(int size){
            board = new Board(size);
        }
        void setPlayers(list<Player> players){
            numberOfPlayers = players.size();
            
            unordered_map<std::string,int> playerPositions;
            for(Player player:players){
                this->players.push(player);
                playerPositions[player.getName()] = 0;
            }
            board->setPlayerPosition(playerPositions);
        }

        void setSnakes(list<Snake> snakes){
            board->setSnakes(snakes);
        }

        void setLadders(list<Ladder> ladders){
            board->setLadders(ladders);
        }

        int getNewPosition(int newPosition){
            int prevPosition;
            do{
                prevPosition = newPosition;
                
                for(Snake snake:board->getSnakes()){
                    if(snake.getStart()==newPosition){
                        newPosition = snake.getEnd();
                    }
                }

                for(Ladder ladder:board->getLadders()){
                    if(ladder.getStart()==newPosition){
                        newPosition = ladder.getEnd();
                    }
                }
            }while(newPosition!=prevPosition);

            return newPosition;
        }

        void movePlayer(Player player,int positions){
            int oldPosition = board->getPlayerPosition()[player.getName()];
            int newPosition = oldPosition + positions;
            int boardSize = board->getSize();

            if(newPosition > boardSize){
                newPosition = oldPosition;
            }
            else{
                newPosition = getNewPosition(newPosition);
            }
            
            unordered_map<string,int> tempPlayerPosition = board->getPlayerPosition();
            tempPlayerPosition[player.getName()] = newPosition;
            board->setPlayerPosition(tempPlayerPosition);
            printPosition(player.getName(),oldPosition,newPosition);

        }

        int getDiceRoll(){
            return diceRoll();
        }

        bool hasPlayerWon(Player player){
            int playerPosition = board->getPlayerPosition()[player.getName()];
            int lastPosition = board->getSize();

            return playerPosition == lastPosition;
        }

        bool isGameCompleted(){
            int currentPlayingPlayers = players.size();
            return  (currentPlayingPlayers < numberOfPlayers);
        }

        void start(){
            while(!isGameCompleted())
            {
                int diceValue = getDiceRoll();
                Player currentPlayer = players.front();
                players.pop();
                movePlayer(currentPlayer,diceValue);
                if(hasPlayerWon(currentPlayer)){
                    cout<<"WIN : "<<currentPlayer.getName()<<endl;
                    board->getPlayerPosition().erase(currentPlayer.getName());
                }
                else
                {
                    players.push(currentPlayer);
                }
            }
        }
};

int main(){

    int snakes_c,ladder_c,player_c;
    int temp1,temp2;
    std::string temp3;

    list<Snake> snakes;
    list<Ladder> ladders;
    list<Player> players;

    cout<<"Enter Number of snakes : ";
    cin>>snakes_c;

    for(int i=0;i<snakes_c;i++){
        cout<<"Enter starting position of snake "<<i+1<<" : ";
        cin>>temp1;
        cout<<"Enter ending position of snake "<<i+1<<" : ";
        cin>>temp2;
        Snake tempSnake(temp1,temp2);
        snakes.push_back(tempSnake);
        cout<<endl;
    }


    cout<<"Enter Number of Ladders : ";
    cin>>ladder_c;

    for(int i=0;i<ladder_c;i++){
        cout<<"Enter starting position of ladder "<<i+1<<" : ";
        cin>>temp1;
        cout<<"Enter ending position of ladder "<<i+1<<" : ";
        cin>>temp2;
        Ladder tempLadder(temp1,temp2);
        ladders.push_back(tempLadder);
        cout<<endl;
    }


    cout<<"Enter Number of Player : ";
    cin>>player_c;

    for(int i=0;i<player_c;i++)
    {
        cout<<"Enter name of player "<<i+1<<" : ";
        cin>>temp3;
        cout<<endl;
        Player player(temp3);
        players.push_back(player);
    }

    GameInitialize gameInitialize(100);
    gameInitialize.setLadders(ladders);
    gameInitialize.setPlayers(players);
    gameInitialize.setSnakes(snakes);

    gameInitialize.start();


}