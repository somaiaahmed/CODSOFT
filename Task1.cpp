#include <bits/stdc++.h>

using namespace std;


int main() {


    random_device rd;
    mt19937 mt(rd());


    cout<<"Welcome to the number guessing game! \n";

    int min_num=1;
    int max_num=500;

    cout<<"I'm thinking of a number between "<<min_num<<" and "<<max_num<<" . Try to guess it. \n";

    uniform_int_distribution<int> distribution(min_num, max_num);
    int secret_num=distribution(mt);

 //   cout<<secret_num<<endl;

    cout<<"Enter the guess: \n";
    int guessed_num;
    cin>>guessed_num;

    int attempt=1;

    while(guessed_num!=secret_num){

        attempt++;
        if(guessed_num<secret_num) {

            if (secret_num - guessed_num >= 50)
                cout << "The guess is too low! Try again." << endl;
          else
              cout << "The guess is low! Try again." << endl;
        }
        if(guessed_num>secret_num) {

            if (guessed_num - secret_num >= 50)
                cout << "The guess is too high! Try again." << endl;
           else
               cout << "The guess is high! Try again." << endl;
        }
        cin>>guessed_num;

    }

    cout<<"Congratulations! You guessed the number "<<secret_num<<" in "<<attempt<<" attempts! \n";
}
