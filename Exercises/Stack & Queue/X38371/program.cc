#include <queue>
#include <iostream>
using namespace std;

void recalc(queue <int> q, int& min, int& max) {
    max = -1000; 
    min = 1000;
    while (not q.empty()) {
        if (max < q.front()) max = q.front();
        if (min > q.front()) min = q.front();
        q.pop();
    }

}

int main() {
    int n, max, min;
    max = -1000;
    min = 1000;
    double total = 0;
    queue <int> q;

    while (cin >> n and n >= -1001 and n < 1001) {
        if (n != -1001) {
            q.push(n);
            if (n > max) max = n;
            if (n < min) min = n;
            total += n;
        }
        else if (not q.empty()) {
            int num = q.front();
            q.pop();
            total -= num;
            if (num == max or num == min) recalc(q, min, max);
        }

        if (q.empty()) {
            cout << "0" << endl;
            max = -1000;
            min = 1000;
        }
        else cout << "min " << min << "; max " << max << "; media " << (total/q.size()) << endl; 
    }
}