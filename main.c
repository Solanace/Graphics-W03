#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
	srand(time(NULL));
	printf("GENERAL MATRIX STUFF:\n=====================\n");
	struct matrix *a, *b;
	a = new_matrix(4, 4);
	b = new_matrix(4, 6);
	printf("Identity matrix:\n");
	ident(a);
	print_matrix(a);
	int row, col;
	for (row = 0; row < a->rows; row ++) {
		for (col = 0; col < a->cols; col ++) {
			a->m[row][col] = row + col;
		}
	}
	for (row = 0; row < b->rows; row ++) {
		for (col = 0; col < b->cols; col ++) {
			b->m[b->rows - row - 1][b->cols - col - 1] = row + col;
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
	
	printf("GRAPHICS MATRIX STUFF\n=====================\n");
	screen s;
	color c;
	struct matrix *edges, *trans;

	edges = new_matrix(4, 1);
	trans = new_matrix(4, 4);
	ident(trans);
	
	// 5
	add_edge(edges, 0, 20, 0, 15, 20, 0);
	add_edge(edges, 0, 20, 0, 0, 10, 0);
	add_edge(edges, 0, 10, 0, 15, 10, 0);
	add_edge(edges, 15, 10, 0, 15, 0, 0);
	add_edge(edges, 0, 0, 0, 15, 0, 0);
	
	// A
	add_edge(edges, 30, 0, 0, 38, 20, 0);
	add_edge(edges, 38, 20, 0, 46, 0, 0);
	add_edge(edges, 34, 10, 0, 42, 10, 0);
	
	// M
	add_edge(edges, 55, 0, 0, 55, 20, 0);
	add_edge(edges, 55, 20, 0, 63, 0, 0);
	add_edge(edges, 63, 0, 0, 71, 20, 0);
	add_edge(edges, 71, 20, 0, 71, 0, 0);
	
	// Chinese modern art
	translate(edges, trans, s, c, 12, 375);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, -100, -70);
	translate(edges, trans, s, c, -100, -70);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, -200, -70);
	translate(edges, trans, s, c, 200, 0);
	translate(edges, trans, s, c, -300, -70);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, 100, 0);
	translate(edges, trans, s, c, 100, 0);

	display(s);
	save_extension(s, "matrix.png");
	free_matrix(edges);
	free_matrix(trans);
}
