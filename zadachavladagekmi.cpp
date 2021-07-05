#include <iostream>
using namespace std;
const int N = 30;
int main() {
    long a[N];
    long i, j, k;
    for (i = 0; i < N; i++)
        cin >> a[i];

    j = 0;
    for (i = 0; i < N; ++i) {
        if (a[i] > 100 && !(a[i] % 4)) {
            a[i] = -1;
            ++j;
        }
    }

    k = 0;
    for (i = 0; i < N && k < j; ++i) {
        if (a[i] == -1) {
            a[i] = j;
            ++k;
        }
    }

    for (i = 0; i < N; i++)
        cout << a[i] << '\n';

    return 0;
}