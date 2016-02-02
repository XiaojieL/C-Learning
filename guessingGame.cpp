#include<iostream>
using namespace std;

//Prompt the user to input an integer in range (1, 100) inclusive, will re-prompt if input is out of range
int getIntInRange(int minValue, int maxValue){
  int userInput;
  cout << "Enter a number from 1 to 100 (inclusive): ";
  cin >> userInput;

  while(userInput < minValue || userInput > maxValue){
    cout << "ERROR: Value is not within valid range. Try again." << endl;
    cout << "Enter a number from 1 to 100 (inclusive): ";
    cin >> userInput;
  }
  return userInput;
}

//Get the secret number from input and print 'clearing screen!' messages
int getSecretNumber(int minValue, int maxValue){
  int secretNum;
  int printCount;
  secretNum = getIntInRange(minValue, maxValue);
  if(minValue <= secretNum && secretNum <= maxValue){
    for(printCount=0; printCount < 30; printCount++){
      cout << "Clearing screen!\n";
    }
  }
  return secretNum;
}


//Get an input from user as a guess number, check if guess number equals secret number, and print out message showing if guess number is equal to, higher, or lower than secret number
bool getGuessAndCheck(int minValue, int maxValue, int secretNum){
  int userInput = getIntInRange(minValue, maxValue);
  bool guessResult;
 
  if(userInput < secretNum){
    cout << "The secret number is HIGHER than your guess" << endl;
    guessResult = false;
  }else if(userInput > secretNum){
    cout << "The secret number is LOWER than your guess" << endl;
    guessResult = false;
  }else{
    cout << "Congratulations! You guessed it!" << endl;
    guessResult = true;
    
  }
  return guessResult;
}

//Guessing game, prompt player 1 to enter a number as secret number, prompt player 2 to guess the secret number, keep track of player 2's guess counts, print out guess count message when game ends
int main(){
  const int MIN_VALUE = 1;
  const int MAX_VALUE = 100;
  int secretNum;
  bool guessResult = false;
  int guessCount = 0;

  cout << "Player 1: You will enter a secret number for the other player to try to guess" <<endl;
  secretNum = getSecretNumber(MIN_VALUE, MAX_VALUE);
  cout << "Player 2: You will try to guess the secret number" << endl;
  
  while(!guessResult){
    guessResult = getGuessAndCheck(MIN_VALUE, MAX_VALUE, secretNum);
    guessCount++;
  }
  
  if(guessCount == 1){
    cout << "It took you " << guessCount << " guess to guess it!" << endl;
  }else{
    cout << "It took you " << guessCount << " guesses to guess it!" << endl;
  }
  
  return guessCount;
}
