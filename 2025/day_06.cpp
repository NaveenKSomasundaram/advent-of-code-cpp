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

void pad_with_trailing_spaces(vector<string> &input){
    size_t max_w = 0;
    for(auto l:input){
        max_w = max(max_w, l.length());
    }
    for(auto &l:input){
        l.resize(max_w, ' ');
    }
}

template<typename Type>
Type vector_sum(const vector<Type> &vec){
    Type ans = 0;
    for(auto v:vec)
        ans += v;

    return ans;
}

template<typename Type>
Type vector_product(const vector<Type> &vec){
    Type ans = 1;
    for(auto v:vec)
        ans *= v;

    return ans;
}

long long solve_1(const vector<string> &input, const string &operations){
    long long ans = 0;

    size_t n_cols = operations.length();

    int col_end = n_cols;
    for(int col = n_cols - 1; col >= 0; col--){
        if(operations[col] != ' '){
            vector<long long> operands;
            for(auto& line:input){
                operands.push_back(stoll(line.substr(col, col_end - col)));
            }

            if(operations[col] == '+')
                ans += vector_sum(operands);
            else if(operations[col] == '*')
                ans += vector_product(operands);

            col_end = col - 1;
        }
    }

    return ans;
}

long long solve_2(const vector<string> &input, const string &operations){
    long long ans = 0;

    size_t num_cols = operations.length();
    size_t num_rows = input.size();

    vector<long long> operands;

    for(int col = num_cols - 1; col >= 0; col--){

        long long num = 0;
        bool column_has_number = false;
        for(size_t row = 0; row < num_rows; row++){
            if(isdigit(input[row][col])){
                num = num * 10 + (input[row][col]- '0');
                column_has_number = true;
            }
        }

        if(column_has_number)
            operands.push_back(num);

        if(operations[col] == '+'){
            ans += vector_sum(operands);
            operands.clear();
        }
        else if (operations[col] == '*'){
            ans += vector_product(operands);
            operands.clear();
        }

    }

    return ans;
}

int main(){
    vector<string> input = parse_input();
    pad_with_trailing_spaces(input);

    string operations = input.back();
    input.pop_back();

    cout << "Part 1 answer: " << solve_1(input, operations) << endl;
    cout << "Part 2 answer: " << solve_2(input, operations) << endl;
    return 0;
}
