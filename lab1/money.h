#ifndef LAB1_H
#define LAB1_H

struct Cost {
    int grn;
    short cop;
};

void add_costs(Cost first, Cost second, Cost &out);
void calc_total(Cost unit, int amount, Cost &out);
void make_rounded(Cost in_cost, Cost &out_cost);
void readfile(const char* file_name);

#endif