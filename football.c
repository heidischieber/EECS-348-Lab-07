#include "football.h" //includes header football.h
#include <stdio.h> //includes library stdio.h that has stuff such as printf and scanf

//function count_combinations
// param: int points
// returns an integer
int count_combinations(int points){ //this function counts the number of different combinations to add up to points
    int total_count; //intializes int variable total_count
    total_count = 0; //sets total_count to 0
    /*
    possible points: 8, 7, 6, 3, 2
    */
    int p8 = points; //way of scoring worth 8pts~ p8 set to points
    for (int pts8 = 0; pts8 <= (p8/8); pts8++){ //iterating through number of 8 points that are possible ~ p8/8 iterates from 0 to p8/8 which is how many times 8pts can fit into total points
        int p7; //initializes int p7
        if ((p8 - 8*pts8) >= 0){ //True if pts8*8 is possible and won't make p8 negative
            p7 = p8 - 8*pts8; //if true then p7 equals p8 - 8*pts8
        }   
        for (int pts7 = 0; pts7 <= (p7/7); pts7++){//iteterating through number of 7 points ~ p7/7 iterates from 0 to p7/7 which is how many times 7pts can fit into total points
            int p6; //initializes int p6
            if ((p7 - 7*pts7) >= 0){ //True if pts7*7 is possible and won't make p7 negative
                p6 = p7 - 7*pts7; //if true then p6 equals p7 - 7*pts7
            }
            for (int pts6 = 0; pts6 <= (p6/6); pts6++){//iterating through number of 6 points ~ p6/6 iterates from 0 to p6/6 which is how many times 6pts can fit into total points
                int p3; //initializes int p3
                if ((p6 - 6*pts6) >= 0){ //True if pts6*6 is possible and won't make p6 negative
                    p3 = p6 - 6*pts6; //if true then p3 equals p6 - 6*pts6
                }
                for (int pts3 = 0; pts3 <= (p3/3); pts3++){//iterating through number of 3 points ~ p3/3 iterates from 0 to p3/3 which is how many times 3pts can fit into total points
                    int p2; //initializes int p2
                    if ((p3 - 3*pts3) >= 0){ //True if pts3*3 is possible and won't make p3 negative
                        p2 = p3 - 3*pts3; //if true then p2 equals p3 - 3*pts3
                    }
                    for (int pts2 = 0; pts2 <= (p2/2); pts2++){//iterating through number of 2 points ~ ~ p2/2 iterates from 0 to p2/2 which is how many times 2pts can fit into total points
                        if ((p2 - 2*pts2) == 0){ //the final combination must be equal to 0 thus meaning that all original points are accounted for
                            total_count += 1; //if this is True then one is added to total_count 
                        }
                    }
                }
            }
        }
    }
    return total_count; //return total_count
}


void print_combinations(int points){
    /*
    possible points: 8, 7, 6, 3, 2
    */
    int p8 = points; //way of scoring worth 8pts~ p8 set to points
    for (int pts8 = 0; pts8 <= (p8/8); pts8++){ //iterating through number of 8 points that are possible ~ p8/8 iterates from 0 to p8/8 which is how many times 8pts can fit into total points
        int p7; //initializes int p7
        if ((p8 - 8*pts8) >= 0){ //True if pts8*8 is possible and won't make p8 negative
            p7 = p8 - 8*pts8; //if true then p7 equals p8 - 8*pts8
        }   
        for (int pts7 = 0; pts7 <= (p7/7); pts7++){//iteterating through number of 7 points ~ p7/7 iterates from 0 to p7/7 which is how many times 7pts can fit into total points
            int p6; //initializes int p6
            if ((p7 - 7*pts7) >= 0){ //True if pts7*7 is possible and won't make p7 negative
                p6 = p7 - 7*pts7; //if true then p6 equals p7 - 7*pts7
            }
            for (int pts6 = 0; pts6 <= (p6/6); pts6++){//iterating through number of 6 points ~ p6/6 iterates from 0 to p6/6 which is how many times 6pts can fit into total points
                int p3; //initializes int p3
                if ((p6 - 6*pts6) >= 0){ //True if pts6*6 is possible and won't make p6 negative
                    p3 = p6 - 6*pts6; //if true then p3 equals p6 - 6*pts6
                }
                for (int pts3 = 0; pts3 <= (p3/3); pts3++){//iterating through number of 3 points ~ p3/3 iterates from 0 to p3/3 which is how many times 3pts can fit into total points
                    int p2; //initializes int p2
                    if ((p3 - 3*pts3) >= 0){ //True if pts3*3 is possible and won't make p3 negative
                        p2 = p3 - 3*pts3; //if true then p2 equals p3 - 3*pts3
                    }
                    for (int pts2 = 0; pts2 <= (p2/2); pts2++){//iterating through number of 2 points ~ ~ p2/2 iterates from 0 to p2/2 which is how many times 2pts can fit into total points
                        if ((p2 - 2*pts2) == 0){ //the final combination must be equal to 0 thus meaning that all original points are accounted for
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", pts8, pts7, pts6, pts3, pts2); //prints the number of different pts to add up to variable points
                        }
                    }
                }
            }
        }
    }
    printf("\n"); //prints a newline at the end for better readability 
}