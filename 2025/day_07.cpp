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

void save_matrix_as_pgm(const std::vector<std::vector<long long>>& matrix, const std::string& filename) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    ofstream out(filename);
    out << "P2\n" << cols << " " << rows << "\n255\n"; // Header

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            // Ensure value is between 0-255
            int val = 0;
            if (matrix[r][c] > 0){
                val = 200;
            }

            out << val << " ";
        }
        out << "\n";
    }
}

vector<long long> solve_1(vector<string> &grid){
    size_t n_rows = grid.size();
    size_t n_cols = grid[0].length();

    long long num_active_splitters = 0, num_beams=0;

    vector<vector<long long>> beam_counts(n_rows + 1, vector<long long>(n_cols, 0));

    int source_col = grid[0].find('S');

    beam_counts[0][source_col] += 1;

    for(size_t row = 0; row < n_rows; row++){
        for(size_t col = 0; col < n_cols; col++){
            if (beam_counts[row][col] == 0)
                continue;
            if(grid[row][col] == '^'){
                beam_counts[row + 1][col + 1] += beam_counts[row][col];
                beam_counts[row + 1][col - 1] += beam_counts[row][col];
                num_active_splitters += 1;
            }
            else if(grid[row][col] == '.' || grid[row][col] == 'S')
                beam_counts[row + 1][col] += beam_counts[row][col];
        }
    }

    for(auto &nb: beam_counts[n_rows]){
        num_beams += nb;
    }

    //save_matrix_as_pgm(beam_counts, "output_07.pgm");

    return {num_active_splitters, num_beams};
}

int solve_2(vector<string> &grid){
    return 0;
}

int main(){
    vector<string> input = parse_input();

    vector<long long> ans = solve_1(input);
    cout << "Part 1 answer: " << ans[0] << endl;
    cout << "Part 2 answer: " << ans[1] << endl;
    return 0;
}