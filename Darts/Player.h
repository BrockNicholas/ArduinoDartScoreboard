
#include <Arduino.h>

class Player {

    private:
        int PriorScore = 501;
        int ScoreThisRound = 0;
        
    public:        

        static int WhoseTurn;
        
        int Score = 501;        
        int ThrowNumber = 1;
        
        void SetScore();
        void Broke();
};