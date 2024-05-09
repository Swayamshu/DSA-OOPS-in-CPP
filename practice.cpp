#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int max_green = 13, max_red = 12, max_blue = 14;
    int total_game_id = 0;
    string input_line;

    while (getline(cin, input_line))
    {
        stringstream ss(input_line);
        string game, game_id, set_info;
        int red, green, blue;

        getline(ss, game, ' ');
        getline(ss, game_id, ':');

        while (getline(ss, set_info, ';'))
        {
        }
    }

    return 0;
}