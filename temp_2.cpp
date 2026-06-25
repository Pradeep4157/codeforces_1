#include <bits/stdc++.h>
using namespace std;
std::mutex cout_mutex;
int main()
{
    int n;
    cin >> n;
    std::vector<std::thread> threads;
    threads.reserve(n);
    for (int i = 0; i < n; i++)
    {
        threads.emplace_back([i]()
                             {
            std::this_thread::sleep_for(std::chrono::milliseconds(10 * (i + 1)));
            lock_guard<mutex>lock(cout_mutex);
            std::cout << "Worker #" << i << " thread id : " << std::this_thread::get_id() << std::endl; });
    }
    for (auto &a : threads)
    {
        a.join();
    }
}