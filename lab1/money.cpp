#include "money.h"
#include <fstream>
#include <iostream>

using namespace std;

void add_costs(Cost first, Cost second, Cost &out) {
    out.grn = first.grn + second.grn;
    out.cop = first.cop + second.cop;

    if (out.cop > 99) {
        out.grn += out.cop / 100;
        out.cop = out.cop % 100;
    }
}

void calc_total(Cost unit, int amount, Cost &out) {
    out.grn = unit.grn * amount;
    out.cop = unit.cop * amount;

    if (out.cop > 99) {
        out.grn += out.cop / 100;
        out.cop = out.cop % 100;
    }
}

void make_rounded(Cost in_cost, Cost &out_cost) {
    int full_amount = in_cost.grn * 100 + in_cost.cop;
    int last = full_amount % 10;

    if (last < 5) {
        full_amount -= last;
    } else {
        full_amount += (10 - last);
    }

    out_cost.grn = full_amount / 100;
    out_cost.cop = full_amount % 100;
}

void readfile(const char* file_name) {
    int g, count;
    short c;

    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "Cannot open file!" << endl;
        return;
    }

    Cost overall = {0, 0};

    while (fin >> g >> c >> count) {
        Cost current = {g, c};      
        Cost row_sum = {0, 0};  
        Cost new_total = {0, 0};   

        calc_total(current, count, row_sum);

        add_costs(overall, row_sum, new_total);
        overall = new_total;
    }

    fin.close();

    cout << "Sum before rounding: "
         << overall.grn << " grn " << overall.cop << " cop" << endl;

    Cost final_rounded = {0, 0};
    make_rounded(overall, final_rounded);

    cout << "Sum after rounding: "
         << final_rounded.grn << " grn " << final_rounded.cop << " cop" << endl;
}