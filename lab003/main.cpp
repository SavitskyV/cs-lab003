#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}



vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count, size_t* bin_max) {
    vector<size_t> bins(bin_count);
    double min=numbers[0], max=numbers[0];
    find_minmax(numbers, min, max);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    
    *bin_max = bins[0];
    for( size_t maxbin : bins )
        if( maxbin > *bin_max )
            *bin_max = maxbin;
    
    return bins;
}


int main() {
    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    
    size_t bin_max;
    // Обработка данных
    const vector<size_t>  bins = make_histogram(numbers, bin_count, &bin_max);
    
    show_histogram_svg( bins, bin_max );
    
    return 0;
}
