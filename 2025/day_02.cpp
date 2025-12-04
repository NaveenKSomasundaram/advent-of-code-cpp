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

vector<string> get_id_ranges(string input){
    vector<string> id_ranges;
    string del = ",";
    auto pos = input.find(del);
    while(pos != string::npos){
        id_ranges.push_back(input.substr(0, pos));
        input.erase(0, pos + del.length());
        pos = input.find(del);
    }
    if (!input.empty())
        id_ranges.push_back(input);
    return id_ranges;
}

bool is_invalid_id(string id){

    if(id.length() < 2) return false;

    int mid = id.length() / 2;

    return id.substr(0, mid) == id.substr(mid);
}

bool is_invalid_id_silly(string id){

    int id_len = id.length();

    if(id_len < 2) return false;

    for(int num_repeats=2; num_repeats <= id_len; num_repeats++){

       if(id_len % num_repeats != 0) continue;

       int pattern_len = id_len / num_repeats;

       bool pattern_matched = true;
       for(int i = 0; i < id_len; i ++){
            if(id[i] != id[i % pattern_len]){
                pattern_matched = false;
                break;
            }
       }
       if (pattern_matched) return true;
    }

    return false;

}

long long solve_1(vector<string> id_ranges){
    long long ans = 0;
    string del = "-";
    for(const string &id_range:id_ranges){
        size_t pos = id_range.find(del);
        if(pos == string::npos) continue;

        long long start_id = stoll(id_range.substr(0, pos));
        long long end_id = stoll(id_range.substr(pos + del.length()));
        for(long long id=start_id; id<=end_id; id++){
            if (is_invalid_id(to_string(id)))
                ans += id;
        }
    }
    return ans;
}

long long solve_2(vector<string> id_ranges){
    long long ans = 0;
    string del = "-";
    for(const string &id_range:id_ranges){
        size_t pos = id_range.find(del);
        if(pos == string::npos) continue;

        long long start_id = stoll(id_range.substr(0, pos));
        long long end_id = stoll(id_range.substr(pos + del.length()));

        for(long long id=start_id; id<=end_id; id++){
            if (is_invalid_id_silly(to_string(id)))
                ans += id;
        }

    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<string> input = parse_input();
    string line = input[0];
    input = get_id_ranges(line);
    cout << "Part 1 answer: " << solve_1(input) << endl;
    cout << "Part 2 answer: " << solve_2(input) << endl;
    return 0;
}
