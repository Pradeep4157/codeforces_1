#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    there are 2 cases :

        i) i form a number closest to x and <= x :

            we can use digit dp here ..

            we are going to keep idx and tight and if tight we will use from 0..a[i]

            else 0..9 , add the diff of this digit and return

            i can use leading zeroes.. but once started i cant do that..



        ii) is greater than x :

            for this case i have 2 ideas :

                a) either i add smallest number in the whole array to the front

                of smallest ele <= x

                b) i replace some digit in the closest <= x number with it and make it

                > x

                and i can bf...




*/
string first;
int n;
int SIZE;
vector<int> arr;
int binpow(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res *= a;

        a *= a;
        b >>= 1;
    }

    return res;
}

int get_diff(string temp, int second)
{
    int first = 0;
    for (auto a : temp)
    {
        first = first * 10 + (a - '0');
    }
    return abs(first - second);
}
signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> first >> n;
        SIZE = first.size();
        int int_first = 0;
        for (auto a : first)
        {
            int_first = (int_first * 10) + (a - '0');
        }
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (int_first == 0)
        {
            cout << abs(int_first - arr[0]) << endl;
            continue;
        }

        int min_diff = LLONG_MAX;
        // now we will find the y <= x using the greedy method..
        {
            if (arr[0] == 0)
            {
                min_diff = min(min_diff, int_first); // because we use that zero and diff becomes int_first...
            }

            int mini = 0;
            for (auto a : arr)
            {
                if (a > 0)
                {
                    mini = a;
                    break;
                }
            }
            if (mini > 0 && (mini <= int_first))
            {
                int curr = mini;
                if (arr[0] == 0)
                {
                    // this is true lowest..
                    while (true)
                    {
                        int next = (curr * 10);
                        if (next > int_first)
                            break;
                        curr = next;
                    }
                }
                else
                {
                    // now this is true lowest..
                    while (true)
                    {
                        // now its still <= first..
                        int next = (curr * 10) + mini;
                        if (next > int_first)
                            break;
                        curr = next;
                    }
                }

                // now we will push it as close to int_first as we can..
                // there is one more case that we use some non zero mini once and keep using zeroes till we can..
                // so forming the curr only changes the remining  methods remains same that is pushing this ele to int_first..
                // now we push the min val to int_first..
                string temp = to_string(curr);
                sort(arr.rbegin(), arr.rend());
                for (int i = 0; i < temp.size(); i++)
                {
                    for (auto a : arr)
                    {
                        string new_temp = temp;
                        int prev_temp = stoll(temp);
                        new_temp[i] = (a + '0');
                        int int_temp = stoll(new_temp);
                        if (int_temp > int_first)
                            continue;
                        // now this is from 0...int_first..
                        int first_diff = abs(prev_temp - int_first);
                        int second_diff = abs(int_temp - int_first);
                        if (second_diff < first_diff)
                        {
                            temp = new_temp;
                            break;
                        }
                    }
                }
                int last_temp = stoll(temp);

                if (last_temp <= int_first)
                {
                    min_diff = min(min_diff, abs(last_temp - int_first));
                }
            }
        }
        {
            int maxi = *max_element(arr.begin(), arr.end());
            int curr = 0;
            if (maxi > 0)
            {
                while (true)
                {
                    if (curr > int_first)
                        break;
                    curr = (curr * 10) + maxi;
                }

                string temp = to_string(curr);
                min_diff = min(min_diff, abs(int_first - curr));
                sort(arr.begin(), arr.end());
                for (int i = 0; i < temp.size(); i++)
                {
                    for (auto a : arr)
                    {

                        string new_temp = temp;
                        int prev_temp = stoll(temp);
                        new_temp[i] = (a + '0');
                        int int_temp = stoll(new_temp);

                        if (int_temp <= int_first)
                            continue;
                        // it is atleast >= int_First
                        // now if abs is low then obv better..
                        int first_diff = abs(prev_temp - int_first);
                        int second_diff = abs(int_temp - int_first);
                        if (second_diff < first_diff)
                        {
                            temp = new_temp;
                            break;
                        }
                    }
                }
                int last_temp = stoll(temp);
                if (last_temp > int_first)
                {
                    min_diff = min(min_diff, abs(last_temp - int_first));
                }
            }
        }
        cout << min_diff << endl;
    }
    return 0;
}
