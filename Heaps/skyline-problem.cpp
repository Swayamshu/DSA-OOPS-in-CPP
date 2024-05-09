// https://leetcode.com/problems/the-skyline-problem/

/*
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
*/

vector<vector<int> > getSkyline(vector<vector<int> > &buildings)
{
    vector<vector<int> > contour;
    multiset<int> pq{0};

    vector<pair<int, int> > points;
    for (auto v : buildings)
        points.push_back({v[0], -v[2]}), points.push_back({v[1], v[2]});

    sort(points.begin(), points.end());

    int height = 0;
    for (int i = 0; i < points.size(); i++)
    {
        int cur = points[i].first;
        int hgt = points[i].second;

        // cout << cur << " " << hgt << " ";

        if (hgt < 0)
            pq.insert(-hgt);
        else
            pq.erase(pq.find(hgt));

        auto it = *pq.rbegin();
        // cout << "-> " << it << "\n";
        if (height != it)
        {
            height = it;
            contour.push_back({cur, height});
        }
    }

    return contour;
}