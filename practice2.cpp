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
#include <iomanip>

using namespace std;

#define int long long
typedef long long ll;
#define FOR(a, b, c) for (int a = b; a < (int)c; ++a)
#define FORN(a, b, c) for (int a = b; a >= (int)c; --a)
#define MAX INT_MAX
#define MIN INT_MIN
#define MAXll LLONG_MAX
#define ii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define print(arr)     \
    for (auto i : arr) \
        cout << i << " ";
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()
const ll MOD = 1e9 + 7;

class EmployeeData
{
private:
    int employee_id;
    int employee_salary;
    int timestamp_of_joining;
    int timestamp_of_leaving;
    string employee_name;
    string employee_job;

public:
    EmployeeData(int &id, string &name, string &job, int &salary, int &join_time, int &leave_time)
        : employee_id(id),
          employee_name(name),
          employee_job(job),
          employee_salary(salary),
          timestamp_of_joining(join_time),
          timestamp_of_leaving(leave_time)
    {
    }

    int getEmployeeId()
    {
        return employee_id;
    }

    string getEmployeeName()
    {
        return employee_name;
    }

    string getEmployeeJob()
    {
        return employee_job;
    }

    int getEmployeeSalary()
    {
        return employee_salary;
    }

    int getEmployeeJoinTime()
    {
        return timestamp_of_joining;
    }

    int getEmployeeLeaveTime()
    {
        return timestamp_of_leaving;
    }
};

struct parsed_data
{
    vector<EmployeeData *> employees;
};

// file: employee_salary
// cols: id,name,job,salary,join_time,leave_time
// types: int,str,str,int,int,int

parsed_data parse_stdin()
{
    struct parsed_data employee_data;
    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        int idx = 0;
        string field;

        int id, salary, join_time, leave_time;
        string name, job;

        while (getline(ss, field, ','))
        {
            switch (idx)
            {
            case 0:
                id = stoi(field);
                break;
            case 1:
                name = field;
                break;
            case 2:
                job = field;
                break;
            case 3:
                salary = stoi(field);
                break;
            case 4:
                join_time = field == "" ? 0 : stoi(field);
                break;
            case 5:
                leave_time = field == "" ? time(nullptr) : stoi(field);
                break;
            }
            idx++;
        }
        EmployeeData *employee = new EmployeeData(id, name, job, salary, join_time, leave_time);
        employee_data.employees.push_back(employee);
    }
    return employee_data;
};

int earned_more_than_30K(parsed_data const &data)
{
    int salaries_more_than_30K = 0;
    for (EmployeeData *employee : data.employees)
    {
        int salary = employee->getEmployeeSalary();
        if (30000 < salary)
        {
            salaries_more_than_30K++;
        }
    }
    return salaries_more_than_30K;
}

string held_longest_job(parsed_data const &data)
{
    string longest_job_employee;
    int longest_job_duration = 0;
    for (EmployeeData *employee : data.employees)
    {
        int time_of_join = employee->getEmployeeJoinTime();
        int time_of_leave = employee->getEmployeeLeaveTime();
        int duration_of_job = time_of_leave - time_of_join;

        if (longest_job_duration < duration_of_job)
        {
            longest_job_employee = employee->getEmployeeName();
            longest_job_duration = duration_of_job;
        }
    }
    return longest_job_employee;
}

bool salary_comparator(EmployeeData *employee_1, EmployeeData *employee_2)
{
    int salary_1 = employee_1->getEmployeeSalary();
    int salary_2 = employee_2->getEmployeeSalary();

    return salary_1 > salary_2;
}

string second_highest_salary(parsed_data const &data)
{
    vector<EmployeeData *> employee_data = data.employees;
    sort(employee_data.begin(), employee_data.end(), salary_comparator);
    EmployeeData *second_highest_earner = employee_data[1];
    string employee_name = second_highest_earner->getEmployeeName();
    return employee_name;
}

// ---------------------------------------------------------------------------------------------

int convert_to_decimal(vector<int> a)
{
    int num = 0;
    int k = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (i % 2 == 0)
            k = 1 << i;
        else
            k = (1 << i) * -1;
        num = num + a[i] * k;
    }
    return num;
}

void convert_to_neg(int a, vector<int> &ans)
{
    if (a == 0)
    {
        ans.push_back(0);
        return;
    }
    while (a != 0)
    {
        int r = a % (-2);
        a = a / -2;
        if (r < 0)
        {
            r = r + (2);
            a = a + 1;
        }
        ans.push_back(r);
    }
}

void ques()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k = convert_to_decimal(a);
    vector<int> ans;
    convert_to_neg(ceil(k / 2.0), ans);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

// -----------------------------------------------------------------

int solve3(vector<int> &a)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < a.size(); i++)
    {
        pq.push(a[i]);
    }
    int cost = 0;
    while (pq.size() > 1)
    {
        int b = pq.top();
        pq.pop();
        int c = pq.top();
        pq.pop();
        cost = cost + (b + c);
        pq.push(b + c);
    }
    return cost;
}
void ques2()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve3(a) << endl;
}

// -----------------------------------------------------------------

int solution(const string &s, const vector<int> &c)
{
    int left = 0, right = c.size();
    while (left <= right)
    {
        const int mid = (left + right) >> 1;
        unordered_set<int> all(c.begin(), c.begin() + mid);
        vector<char> have(26, -1);
        bool mark = true;
        for (int i = 0, temp = -1; mark && i < s.length(); ++i)
        {
            int p = s[i] - 'a';
            if (have[p] > temp)
            {
                mark = false;
            }
            have[p] = i;
            if (all.count(i + 1))
            {
                temp = i;
            }
        }
        if (mark)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ++right > c.size() ? (-1) : right;
}

// -----------------------------------------------------------------

int func(vector<int> &a, int k)
{
    sort(a.begin(), a.end());
    int n = a.size();

    int lef = n / 3 - 1;
    int rig = 2 * n / 3;

    int answer = 0;
    answer = a[rig] - a[lef];

    for (int check = 1;; check++)
    {
        if (rig + check == n)
        {
            answer += k / (n / 3);
            break;
        }
        else
        {
            int tomodify = (a[lef] - a[lef - check]) + (a[rig + check] - a[rig]);
            if (tomodify * check <= k)
            {
                k -= tomodify * check;
                answer += tomodify;
            }
            else
            {
                answer += k / check;
                break;
            }
            a[lef] = a[lef - check];
            a[rig] = a[rig + check];
        }
    }
    return answer;
}

// -----------------------------------------------------------------

void solve2()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << func(a, k) << endl;
}

// ----------------------------------------------------------------------------------------

int solution(vector<int> &Y)
{
    int n = Y.size();

    int top = *max_element(all(Y));
    vector<int> holder(top + 1, 0);
    vector<int> holder1(top * 2, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int start = Y[i], end = Y[i + 1];
        if (end < start)
        {
            while (end < start)
            {
                holder[start]++;
                holder1[(start * 2) - 1]++;
                start--;
            }
        }
        else
        {
            while (start < end)
            {
                holder[start]++;
                holder1[(start * 2) + 1]++;
                start++;
            }
        }
    }

    holder[Y[n - 1]]++;
    int total = 0, ans = 0;
    for (int i = 0; i <= top; i++)
    {
        if (total < holder[i])
        {
            total = holder[i];
            ans = i;
        }
    }

    for (int i = 0; i < top * 2; i++)
    {
        if (total < holder1[i])
        {
            total = holder1[i];
            ans = i;
        }
    }

    return total;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> Y(n);
    for (int &i : Y)
        cin >> i;

    unordered_map<int, int> common;
    vector<vector<int> > intervals;
    FOR(i, 1, n)
    {
        int l = min(Y[i - 1], Y[i]);
        int r = max(Y[i - 1], Y[i]);
        intervals.pb({l, r});
        if (i != n - 1)
            common[Y[i]]++;
    }

    sort(all(intervals));

    int count = 1, max_count = 0;
    int start = intervals[0][0], end = intervals[0][1];

    vector<vector<int> > cnts;

    FOR(i, 1, intervals.size())
    {
        vector<int> curr_interval = intervals[i];

        if (!(end < curr_interval[0] || curr_interval[1] < start))
        {
            start = max(start, curr_interval[0]);
            end = min(end, curr_interval[1]);

            max_count = max(++count, max_count);
        }
        else
        {
            start = max(start, curr_interval[0]);
            end = min(end, curr_interval[1]);

            cnts.pb({count, start, end});
            count = 1;
        }
    }
    cnts.pb({count, start, end});

    int ans = 0;
    for (auto v : cnts)
    {
        int count = v[0],
            start = v[1],
            end = v[2];

        int min_cnt = 1e5;
        for (auto [point, cnt] : common)
        {
            if (start <= point && point <= end)
                min_cnt = min(min_cnt, cnt);
        }

        if (min_cnt == 1e5)
            min_cnt = 0;
        ans = max(ans, count - min_cnt);
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
        cout << "\n";
    }
}