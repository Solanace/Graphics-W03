#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
	/*
	screen s;
	color c;
	struct matrix *edges;

	edges = new_matrix(4, 4);
	ident(edges);
	print_matrix(edges);

	draw_lines(edges, s, c);
	//display(s);
	free_matrix( edges );
	*/
	
	struct matrix *a, *b;
	a = new_matrix(4, 4);
	b = new_matrix(4, 6);
	int r, c;
	for (r = 0; r < a->rows; r ++) {
		for (c = 0; c < a->cols; c ++) {
			a->m[r][c] = r + c;
		}
	}
	for (r = 0; r < b->rows; r ++) {
		for (c = 0; c < b->cols; c ++) {
			b->m[b->rows - r - 1][b->cols - c - 1] = r + c;
		}
	}
	printf("Matrix a:\n");
	print_matrix(a);
	printf("Matrix b:\n");
	print_matrix(b);
	
	printf("Multiplying matrices a and b:\n");
	matrix_mult(a, b);
	print_matrix(b);
	
	free_matrix(a);
	free_matrix(b);
}
