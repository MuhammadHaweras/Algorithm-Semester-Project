#include <stdio.h>

int coins[100];
int numberofCoins, sum;

int solution(int sol, int i) {
    if (numberofCoins == 0 || sol > sum || i >= numberofCoins)
        return 0;
    else if (sol == sum)
        return 1;

    return solution(sol + coins[i], i) + solution(sol, i + 1);
}

int main() {
    FILE *fin = fopen("input_dp.txt", "r");
    FILE *fout = fopen("output_dp.txt", "w");

    fscanf(fin, "%d %d", &numberofCoins, &sum);
    for (int i = 0; i < numberofCoins; i++) {
        fscanf(fin, "%d", &coins[i]);
    }

    int result = solution(0, 0);

    fprintf(fout, "Total solutions: %d\n", result);

    fclose(fin);
    fclose(fout);

    return 0;
}
