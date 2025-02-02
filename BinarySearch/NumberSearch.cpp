#include <bits/stdc++.h>
using namespace std;

int main() {
    int target, min_index = 0, max_index, calc_count = 0;
    vector<int> numbers;
    random_device rng;
    uniform_int_distribution<int> number_dist(1, 100);
    uniform_int_distribution<int> list_size_dist(2, 1000);

    for (int i = 0; i < list_size_dist(rng); i++) {
        numbers.push_back(number_dist(rng));
    }

    cout << "Enter a number to search: ";
    cin >> target;
    if (target > *max_element(begin(numbers), end(numbers)) || target < *min_element(begin(numbers), end(numbers))) {
        cout << target << " is out of range." << endl;
        return 0;
    }

    // Binary search (manually)
    sort(numbers.begin(), numbers.end());
    max_index = numbers.size() - 1;
    for (int i = 0; i < numbers.size(); i++) {
        if (min_index == max_index) {
            cout << "No" << endl;
            break;
        }
        calc_count++;
        if (numbers[int((max_index - 1) / 2)] == target) {
            cout << "Yes" << endl;
            break;
        } else if (numbers[int((max_index - 1) / 2)] < target) {
            max_index = int(max_index / 2) - 1;
        } else {
            min_index = int(max_index / 2);
            max_index = numbers.size() - 1;
        }
        if (i == numbers.size() - 1) {
            cout << "No" << endl;
        }
    }
    cout << "Calculation count: " << calc_count << endl;
    return 0;
}
