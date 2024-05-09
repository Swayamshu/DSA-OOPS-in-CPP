#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string Map[n];
        for (int i = 0; i < n; i++)
            cin >> Map[i];

        vector<int> lands;
        vector<pair<int, int> > neighbours{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

        auto insideMap = [&](pair<int, int> coordinates)
        {
            return coordinates.first >= 0 and coordinates.second >= 0 and coordinates.first < n and coordinates.second < m;
        };

        auto landCheck = [&](int x, int y)
        {
            queue<pair<int, int> > q;
            int landArea = 0;

            q.push({x, y});
            Map[x][y] = '0'; // occupied(or visited) land

            while (!q.empty())
            {
                pair<int, int> node = q.front();
                x = node.first, y = node.second;
                // auto [x, y] = q.front();
                q.pop();
                landArea++;

                for (auto neighbour : neighbours)
                {
                    int dx = neighbour.first, dy = neighbour.second;
                    if (Map[x + dx][y + dy] == '1' and insideMap({x + dx, y + dy}))
                    {
                        Map[x + dx][y + dy] = '0'; // occupied(or visited) land
                        q.push({x + dx, y + dy});
                        // landArea++;
                    }
                }
            }
            return landArea;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Map[i][j] == '1')
                {
                    lands.push_back(landCheck(i, j));
                    cout << lands[i] << " ";
                }
            }
        }

        sort(lands.begin(), lands.end(), greater<int>());

        int landOccupied = 0;
        for (int i = 1; i < lands.size(); i += 2)
            landOccupied += lands[i];

        cout << "--> " << landOccupied << endl;
    }

    return 0;
}