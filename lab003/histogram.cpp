#include "histogram.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max) {
   
    if(numbers.size()!=0) {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }
    }
}

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height << "' "
    << "viewBox='0 0 " << width << " " << height << "' "
    << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" <<text<< "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "#EF867B"){
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

void show_histogram_svg(const vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    //svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
    //svg_rect(TEXT_WIDTH, 0, bins[0] * 10, BIN_HEIGHT);
    double top = 0;
    for (size_t bin : bins) {
        const double bin_width = 10 * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "#e64e4e");
        top += BIN_HEIGHT;
    }
    svg_end();
}

