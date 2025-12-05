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

set<tuple<long long, long long>> get_fresh_ingredients(vector<string> input){
    set<tuple<long long, long long>> fresh_ingredients;
    string del = "-";

    for(const string &line:input){
        size_t pos = line.find('-');
        if (pos != string::npos){
            string ing_s = line.substr(0, pos);
            string ing_e = line.substr(pos+1);
            fresh_ingredients.insert(make_tuple(stoll(ing_s), stoll(ing_e)));
        }
    }

    return fresh_ingredients;
}

set<long long> get_available_ingredients(vector<string> input){
    set<long long> available_ingredients;
    string del = "-";

    for(const string &line:input){
        if (line.find('-') == string::npos && line != ""){
            available_ingredients.insert(stoll(line));
        }
    }
    return available_ingredients;
}

long long solve_1(set<tuple<long long, long long>> fresh_ingredients, set<long long> available_ingredients){
    long long ans = 0;
    auto it = fresh_ingredients.begin();
    for(auto ingredient:available_ingredients){
        while(it != fresh_ingredients.end()){
            long long fresh_start = get<0>(*it);
            long long fresh_end = get<1>(*it);
            if(ingredient < fresh_start)
                break;

            if(ingredient >= fresh_start && ingredient <= fresh_end){
                ans += 1;
                break;
            }

            it = next(it);
        }
    }

    return ans;
}

long long solve_2(set<tuple<long long, long long>> fresh_ingredients){
    long long ans = 0;
    long long curr_ingredient = -1;

    for(auto ingredient_range:fresh_ingredients){
        if (curr_ingredient > get<1>(ingredient_range)) continue;
        curr_ingredient = max(curr_ingredient, get<0>(ingredient_range));
        ans += get<1>(ingredient_range) - curr_ingredient + 1;
        curr_ingredient = get<1>(ingredient_range) + 1;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<string> input = parse_input();
    string line = input[0];
    set<tuple<long long, long long>> fresh_igredients = get_fresh_ingredients(input);
    set<long long> available_igredients = get_available_ingredients(input);
    cout << "Part 1 answer: " << solve_1(fresh_igredients, available_igredients) << endl;
    cout << "Part 2 answer: " << solve_2(fresh_igredients) << endl;
    return 0;
}
