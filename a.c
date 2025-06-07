#include<stdio.h>

typedef struct{

	char value;
	int row, col;

}Pixel;

void read_image(Pixel pixels[]){

	FILE *fp = fopen("text.txt","r");

	int i=0;

	char buffer;

	while(!feof(fp)){

		fscanf(fp, "%c", &pixels[i].value);

		if(pixels[i].value == '\n'){

			fscanf(fp, "%c", &pixels[i].value);

		}

		getc(fp);

		fscanf(fp, "%d", &pixels[i].row);

		getc(fp);

		fscanf(fp, "%d", &pixels[i].col);

		getc(fp);

		i++;

	}

	fclose(fp);

}

void fill_canvas(Pixel pixels[], Pixel canvas[][9]){

	int i=0;

	for(;i<54;i++){

		canvas[pixels[i].row][pixels[i].col].value = pixels[i].value;

	}

}

void draw_image(Pixel canvas[][9]){

	int i, j;

	for(i=0;i<6;i++){

		for(j=0;j<9;j++)	printf("%c",canvas[i][j].value);

		printf("\n");
		
	}

}

int main(void){

	int row_number=6, col_number=9;
	int total_pixel_number = row_number * col_number;
	Pixel pixels[total_pixel_number];
	Pixel canvas[row_number][col_number];
	read_image(pixels);
	fill_canvas(pixels, canvas);
	draw_image(canvas);
	return 0;

}
