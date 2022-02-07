#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int s, n, m;
    cin >> s >> n >> m;
    int sunday = s / 7;
    int availble_day_to_buy = s - sunday;
    int food_req = s * m;
    int days_to_buy = food_req / n;
    if (food_req % n != 0)
        days_to_buy++;
    if (days_to_buy > availble_day_to_buy)
        cout << "No" << endl;
    else
        cout << "Yes " << days_to_buy << endl;

    return 0;
}