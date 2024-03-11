#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int points[] = {8, 7, 6, 3, 2};

void print_output(int tdtp, int tdfg, int td, int fg, int sf) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tdtp, tdfg, td, fg, sf);
}

int main() {
    int tdtp = 0; // TD + 2pt
    int tdfg = 0; // TD + FG
    int td = 0;    // TD
    int fg = 0;    // FG
    int sf = 0;    // Safety

    int total_pts = 0;
    while (1) {
        printf("Enter 0 or 1 to STOP ");
        printf("Enter the number of points scored: ");
        scanf("%d", &total_pts);

        for (int i = 0; i <= total_pts / points[0]; i++) {
            for (int j = 0; j <= total_pts / points[1]; j++) {
                for (int k = 0; k <= total_pts / points[2]; k++) {
                    for (int l = 0; l <= total_pts / points[3]; l++) {
                        for (int m = 0; m <= total_pts / points[4]; m++) {
                            if ((points[0] * i + points[1] * j + points[2] * k + points[3] * l + points[4] * m) == total_pts) {
                                tdtp = i;
                                tdfg = j;
                                td = k;
                                fg = l;
                                sf = m;
                                print_output(tdtp, tdfg, td, fg, sf);
                            }
                        }
                    }
                }
            }
        }
        if (total_pts == 0 || total_pts == 1) {
            break;
        }
    }
    return 0;
}
