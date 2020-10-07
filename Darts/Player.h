
#include <Arduino.h>

class Player {

        
    public:        

        static int WhoseTurn;
        
        int ScoreThisRound = 0;
        int Score = 501;        
        int ThrowNumber = 1;
        
        void SetScore();
        
};