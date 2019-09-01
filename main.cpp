#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

typedef int numType;

void swap(int *x, int *y) {
    int tmp = *x;

    *x = *y;
    *y = tmp;
}

int calculateFlips(vector<int> nums) {
    int numFlips = 0;

    for (int i = 0; i < nums.size() - 1; i++)
        for (int k = 0; k < nums.size() - 1 - i; k++)
            if (nums.at(k) > nums.at(k + 1)) {
                swap(&nums.at(k + 1), &nums.at(k));
                numFlips++;
            }

    return numFlips;
}

int main() {

    int n;
    numType x = 0;
    vector<numType> nums;

    while (scanf("%d", &n) != EOF) {

        nums.clear();
        for (int i = 0; i < n; i++) {
            //cin>>x;
            scanf("%d", &x);
            nums.push_back(x);
        }

        if (nums.size() == 0)
            break;

        auto flipNums = calculateFlips(nums);

        printf("Minimum exchange operations : %d\n", flipNums);
    }

    return 0;
}