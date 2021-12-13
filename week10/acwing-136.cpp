//136. 邻值查找
//https://www.acwing.com/problem/content/138/
#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    
    cin >> n;
	
    set<pair<long long, int>> numSet;
    numSet.insert({1e12 + 10,0});
    numSet.insert({-(1e12 + 10),0});
    
    for (int i = 1; i <= n; i++) {
		long long num;
        cin >> num;
        
        if (i > 1)
        {
            auto t1 = numSet.upper_bound({num, i}); //t1->first是比x大的最小的值 
            auto t2 = t1;
            t2--; //t2->first是比x小的最大的值
            long long d1 = t1->first - num;
			long long d2 = num - t2->first;
            if (d1 < d2)
                cout << d1 << " " << t1->second << endl;
            else 
                cout << d2 << " " << t2->second << endl;
        }
        numSet.insert({num, i});
    }
}