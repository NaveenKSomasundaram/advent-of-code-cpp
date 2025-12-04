#include <bits/stdc++.h>
using namespace std;


vector<string> parse_input(){
    vector<string> input;
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }
    return input;
}

long long get_joltage(string bank, int selection_size){
    string joltage = string(selection_size, '0');

    for(int i = 0; i < bank.length(); i++){
        int digit_pos = min(selection_size, (int)bank.length() - i) - 1;
        while(digit_pos >= 0){
            int idx = joltage.length() - digit_pos - 1;
            if (bank[i] > joltage[idx]){
                joltage[idx] = bank[i];
                fill(joltage.begin()+idx + 1, joltage.end(), '0');
                break;
            }
            digit_pos--;
        }
    }
    return stoll(joltage);
}

long long solve_1(vector<string> banks){
    long long ans = 0;
    for(const auto& bank:banks){
        ans += get_joltage(bank, 2);
    }

    return ans;
}

long long solve_2(vector<string> banks){
    long long ans = 0;
    for(const auto& bank:banks){
        ans += get_joltage(bank, 12);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<string> input = parse_input();

    cout << "Part 1 answer: " << solve_1(input) << endl;
    cout << "Part 2 answer: " << solve_2(input) << endl;
    return 0;
}
