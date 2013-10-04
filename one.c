#include <stdio.h>

#define R 4
#define C 5

int main(void){
	int mat[R][C] = {
			{3, 0, 9, 5, 2},
			{7, 3, 8, 4, 3},
			{1, 6, 5, 8, 1},
			{2, 3, 2, 4, 6}
		};

	int i, j, x, y, found, same_element;

	for (i = 0; i < R; ++i){
		for (j = 0; j < C; ++j){
			//printf("reading %d at Row: %d Column: %d\n", mat[i][j], i, j);
			found = 1;
			x = i-1;
			while(x <= i+1){
				if(x >= 0 && x < R){
					y = j-1;
					while(y <= j+1){
						if(i == x && j == y){
							same_element = 1;
						}else{
							same_element = 0;
						}

						if(y >= 0 && y < C && same_element == 0){
							printf("checking %d/%d with %d/%d\n", i, j, x, y);
							if(mat[i][j] > mat[x][y]){
								found = 0;
							}
						}
						++y;
					}
				}
				++x;
			}

			if(found == 1){
				printf("%d\n", mat[i][j]);
				//printf("%d at Row: %d, Column: %d -  IS Local minimum\n", mat[i][j], i, j);
			}else{
				//printf("%d at Row: %d, Column: %d - IS NOT a local minimum\n", mat[i][j], i, j);
			}
		}
		printf("\n");
	}
	return 0;
}