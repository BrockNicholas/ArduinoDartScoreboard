#include "Player.h"


void Player::SetScore(){    
    PriorScore = Score;
    Score = ScoreThisRound;
    ScoreThisRound = 0;
    ThrowNumber = 1;
}

void Player::Broke(){
    Score = PriorScore;
}