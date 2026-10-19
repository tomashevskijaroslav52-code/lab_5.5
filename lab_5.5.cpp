#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int sumDigits(int n, int currentDepth, int& maxDepth) {
    if (currentDepth > maxDepth) {
        maxDepth = currentDepth;
    }

    if (n < 10) {
        return n;
    }

    return (n % 10) + sumDigits(n / 10, currentDepth + 1, maxDepth);
}

int countDigits(int n, int currentDepth, int& maxDepth) {
    if (currentDepth > maxDepth) {
        maxDepth = currentDepth;
    }

    if (n < 10) {
        return 1;
    }

    return 1 + countDigits(n / 10, currentDepth + 1, maxDepth);
}

int maxDigit(int n, int currentDepth, int& maxDepth) {
    if (currentDepth > maxDepth) {
        maxDepth = currentDepth;
    }

    if (n < 10) {
        return n;
    }

    return max(n % 10, maxDigit(n / 10, currentDepth + 1, maxDepth));
}

int minDigit(int n, int currentDepth, int& maxDepth) {
    if (currentDepth > maxDepth) {
        maxDepth = currentDepth;
    }

    if (n < 10) {
        return n;
    }

    return min(n % 10, minDigit(n / 10, currentDepth + 1, maxDepth));
}

int main() {
    int number;
    cout << "Vvedit chyslo: ";
    cin >> number;

    int absNumber = abs(number);

    int maxDepthSum = 0;
    int maxDepthCount = 0;
    int maxDepthMax = 0;
    int maxDepthMin = 0;

    int sum = sumDigits(absNumber, 1, maxDepthSum);
    int count = countDigits(absNumber, 1, maxDepthCount);
    int mx = maxDigit(absNumber, 1, maxDepthMax);
    int mn = minDigit(absNumber, 1, maxDepthMin);

    cout << "Suma cyfr: " << sum << " (Glybyna: " << maxDepthSum << ")" << endl;
    cout << "Kilkist cyfr: " << count << " (Glybyna: " << maxDepthCount << ")" << endl;
    cout << "Maksymalna cyfra: " << mx << " (Glybyna: " << maxDepthMax << ")" << endl;
    cout << "Minimalna cyfra: " << mn << " (Glybyna: " << maxDepthMin << ")" << endl;

    return 0;
}
