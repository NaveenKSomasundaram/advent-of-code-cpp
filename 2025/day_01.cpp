#include <bits/stdc++.h>
using namespace std;


int move_dial(string operation, int start){

    if(operation[0] == 'R')
        start += stoi(operation.substr(1, operation.length()));

    else if(operation[0] == 'L')
        start -= stoi(operation.substr(1, operation.length()));
    start = ((start % 100) + 100) % 100;
    return start;
}

vector<string> parse_input(){
    vector<string> input;
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }
    return input;
}

int count_zero_crosses(string operation, int start){

    int value = stoi(operation.substr(1, operation.length()));
    int count = value / 100; // Add rotations
    value %= 100;

    // When starting at zero
    if (start == 0){
        if(count > 0 && value == 0) // Remove one if it ends at zero
            count -= 1;
    }
    else if(operation[0] == 'R'){
        if (start + value > 100)
            count += 1;
    }
    else if(operation[0] == 'L'){
        if (start - value < 0)
            count += 1;
    }

    return count;
}

int solve_1(vector<string> operations){
    int ans = 0, position = 50;
    for(auto operation:operations){
        position = move_dial(operation, position);
        if (position == 0)
            ans += 1;
    }
    return ans;
}

int solve_2(vector<string> operations){
    int ans = 0, position = 50;
    for(auto operation:operations){
        ans += count_zero_crosses(operation, position);
        position = move_dial(operation, position);
        if (position == 0)
            ans += 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int ans = 0;
    vector<string> input = parse_input();
    string line;

    cout << "Part 1: " << solve_1(input) << endl;
    cout << "Part 2: " << solve_2(input) << endl;
    return 0;
}
