#include<iostream>      
#include<vector>        //for using vectors
#include<string>        //for using strings
#include<unordered_set> //for using unordered sets
#include<fstream>       //for file input and output

using namespace std;

/*
    Function to print the contents of a vector of strings
    Parameters:
        const vector<string>& vec = reference to the vector of strings to be printed
*/

void print_vector(const vector<string>& vec)
{
    if(vec.empty()){        //check if the vector is empty first
        cout << "Vec is Empty" << endl;
        return;             //exit function if empty
    }

    //loop through vector and print each element
    for(int i = 0; i < vec.size(); i++) {       
        cout << vec[i] << endl;
    }

}

int main() {
    
    string names;       //variable to hold each name read from the files

    
    unordered_set<string> followers;        //create unordered_set to look up followers fast
    vector<string> following;               //create vector to hold following names
    vector<string> not_following_back;      //create vector to hold names not following back


    ifstream fin;       //declare input file stream


    fin.open("followers.txt");  //open the followers file
    
    if(!fin.is_open())          //check if the followers file opened successfully
    {
    return 1;                   //exit if file did not open
    } 
    

    while(getline(fin, names))  //read each line from the followers file
    {
        followers.insert(names); //adds names to the followers vector
    }

    fin.close(); //close file after reading followers

    fin.open("following.txt");  //open the following file
    
    if(!fin.is_open())          //check if the following file opened successfully
    {
        return 1;               //exit if file did not open
    }
    
    
    while(getline(fin,names))   //read each line from the following file 
    {
        following.push_back(names); //adds names to the following vector
    }

    fin.close(); //close file after reading following

    //loop through following vector and check if each name is in followers set
    for(int i = 0; i < following.size(); i++)
    {
        if(followers.find(following[i]) == followers.end()){    //check if name is not in follower set using .end() to confirm absence 
            not_following_back.push_back(following[i]);         //adds names to the not following back vector
        }
    }

    cout << "These are the people not following you back: " << endl;

    print_vector(not_following_back);   //print the names of people not following back   

    return 0;
}