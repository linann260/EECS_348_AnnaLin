#include <stdio.h>

void possible_combo(int score){
    for(int a = 2; a <= floor(score/8)){
        for(int b = 2; b <= floor(score/7); b++){
            for(int c = 2; c <= floor(score/6); c++){
                for(int d = 2; d <= floor(score/3); d++){
                    for(int e = 2; e <= floor(score/2); e++){
                        if 
                    }
                }
            }
        }
    }
}

int main(){
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: \n");
    scanf("%d", &score);

    while (score !< 2){
        possible_combo(score)
    }
    return 0;
}