#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<fstream>

using namespace std;

void print_vector(const vector<string>& vec) {
    if(vec.empty()){
        cout << "Vec is Empty" << endl;
        return;
    }
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

}

int main() {
    
    string names; 

    //create unordered_set to look up followers fast
    unordered_set<string> followers; 
    vector<string> following;
    vector<string> not_following_back;


    ifstream fin;


    fin.open("followers.txt");
    if(!fin.is_open()){
    return 1; 
    } 
    

    while(getline(fin, names)){
        followers.insert(names); //adds names to the followers vector
    }

    fin.close(); //close file after reading followers

    fin.open("following.txt");
    if(!fin.is_open()){
        return 1;
    }
    
    
    while(getline(fin,names)){
        following.push_back(names); //adds names to the following vector
    }


    //print_vector(following);


    fin.close(); //close file after reading following

    for(int i = 0; i < following.size(); i++){
        if(followers.find(following[i]) == followers.end()){
            not_following_back.push_back(following[i]); //adds names to the not following back vector
        }
    }

    cout << "These are the people not following you back: " << endl;

    print_vector(not_following_back);

    return 0;
}