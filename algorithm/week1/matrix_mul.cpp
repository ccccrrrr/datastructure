#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int M, N, K;
#define P 2000
int A[P][P], B[P][P];

class Matrix {
public:
    int startx;
    int x_length;
    int starty;
    int y_length;
    bool hascalculate;
    int matrix[2000][2000];

    int sub11x;
    int sub11y;
    int sub21x;int sub21y;
    int sub12x;int sub12y;
    int sub22x;int sub22y;

    Matrix* _sub11;
    Matrix* _sub12;
    Matrix* _sub21;
    Matrix* _sub22;

    Matrix(int startx, int x_length, int starty, int y_length):startx(startx),x_length(x_length),starty(starty),y_length(y_length),hascalculate(false) {
        for(int i = 0 ; i < 2000; i++)
            for(int j = 0; j < 2000; j++)
                this->matrix[i][j] = 0;
    }

    ~Matrix() {
        delete _sub11;
        delete _sub12;
        delete _sub21;
        delete _sub22;
    }

    void printMatrix() {
        for(int i = 0; i < this->x_length; i++) {
            for(int j = 0; j < this->y_length; j++)
                if(j == this->y_length -1)
                    printf("%d", this->matrix[this->startx+i][this->starty+j]);
                else
                    printf("%d ", this->matrix[this->startx+i][this->starty+j]);
            if(i < this->x_length - 1)
                printf("\n");
        }
    }

    void calculate() {
        if(hascalculate)
            return;
        int sub11x=0;int sub11y=0;
        int sub21x=0;int sub21y=0;
        int sub12x=0;int sub12y=0;
        int sub22x=0;int sub22y=0;

        _sub11 = new Matrix(0, (x_length+1)/2, 0, (y_length+1)/2);
        _sub12 = new Matrix(0, (x_length+1)/2, 0, y_length-(y_length+1)/2);
        _sub21 = new Matrix(0, x_length-(x_length+1)/2, 0, (y_length+1)/2);
        _sub22 = new Matrix(0, x_length-(x_length+1)/2, 0, y_length-(y_length+1)/2);
        // _sub22->printMatrix();
        for(int i = startx; i < startx + (x_length+1) / 2; i++) {
            sub11y = 0;
            for(int j = starty; j < starty+(y_length+1) / 2; j++)
                _sub11->matrix[sub11x][sub11y++] = this->matrix[i][j];
            sub11x++;
        }
        for(int i = startx; i < startx + (x_length+1)/2; i++) {
            sub12y = 0;
            for(int j = starty+(y_length+1)/2; j < starty + y_length; j++) {
                _sub12->matrix[sub12x][sub12y++] = this->matrix[i][j];
            }
            sub12x++;
        }
        for(int i = startx+(x_length+1)/2; i < startx + x_length; i++) {
            sub21y = 0;
            for(int j = starty; j < starty + (y_length+1)/2; j++)
                _sub21->matrix[sub21x][sub21y++] = this->matrix[i][j];
            sub21x++;
        }
        for(int i = startx + (x_length+1)/2; i < startx+x_length; i++) {
            sub22y = 0;
            for(int j = starty + (y_length+1)/2; j < starty + y_length; j++) {
                _sub22->matrix[sub22x][sub22y++] = this->matrix[i][j];
            }
            sub22x++;
        }
        hascalculate = true;

    }
};

Matrix* Add(Matrix* A, Matrix* B) {
    int xx = max(A->x_length, B->x_length);
    int yy = max(A->y_length, B->y_length);
    Matrix* C = new Matrix(0, xx, 0, yy);
    for(int i = 0; i < xx; i++) 
        for(int j = 0; j < yy; j++) {
            int value1=0, value2 = 0;
            if(i >= A->x_length || j >= A->y_length) value1 = 0;
            else value1 = A->matrix[A->startx+i][A->starty+j];
            if(i >= B->x_length || j >= B->y_length) value2 = 0;
            else value2 = B->matrix[B->startx+i][B->starty+j];
            C->matrix[i][j] = value1 + value2;
        }
    return C;
}

Matrix* Minus(Matrix* A, Matrix* B) {
    int xx = max(A->x_length, B->x_length);
    int yy = max(A->y_length, B->y_length);
    Matrix* C = new Matrix(0, xx, 0, yy);
    for(int i = 0; i < xx; i++) 
        for(int j = 0; j < yy; j++) {
            int value1=0, value2 = 0;
            if(i >= A->x_length || j >= A->y_length) value1 = 0;
            else value1 = A->matrix[A->startx+i][A->starty+j];
            if(i >= B->x_length || j >= B->y_length) value2 = 0;
            else value2 = B->matrix[B->startx+i][B->starty+j];
            C->matrix[i][j] = value1 - value2;
        }
    return C;
}

Matrix * Mul(Matrix* A, Matrix* B) {
    if(A->y_length <= 1 || A->x_length <= 1 || B-> y_length <= 1) {
        Matrix * res = new Matrix(0, A->x_length, 0, B->y_length);
        for(int i = 0; i < res->x_length; i++) {
            for(int j = 0; j < res->y_length; j++) {
                for(int k = 0; k < A->y_length; k++) {
                    // printf("%d %d %d %d %d %d\n",res->startx+i,res->starty+j,A->startx+i,k+A->starty, B->startx+k,B->starty+j);
                    res->matrix[res->startx+i][res->starty+j] += A->matrix[A->startx+i][k+A->starty]*B->matrix[B->startx+k][B->starty+j];
                }
            }
        }
        return res;
    } else {
        // printf("A:(%d %d), B:(%d,%d)\n", A->x_length, A->y_length, B->x_length, B->y_length);
        A->calculate();
        B->calculate();
        Matrix * p1 = Mul(A->_sub11, Minus(B->_sub12, B->_sub22));
        Matrix * p2 = Mul(Add(A->_sub11, A->_sub12), B->_sub22);
        Matrix * p3 = Mul(Add(A->_sub21, A->_sub22), B->_sub11);
        Matrix * p4 = Mul(A->_sub22, Minus(B->_sub21, B->_sub11));
        Matrix * p5 = Mul(Add(A->_sub11, A->_sub22), Add(B->_sub11, B->_sub22));
        Matrix * p6 = Mul(Minus(A->_sub12, A->_sub22), Add(B->_sub21, B->_sub22));
        Matrix * p7 = Mul(Minus(A->_sub11, A->_sub21), Add(B->_sub11, B->_sub12));

        Matrix * C11 = Add(p5, Minus(p4, Minus(p2, p6)));
        Matrix * C12 = Add(p1, p2);
        Matrix * C21 = Add(p3, p4);
        Matrix * C22 = Add(p5,Minus(p1,Add(p3, p7)));
        
        // printf("\n=========================\n");
        // C11->printMatrix();
        // printf("\n=========================\n");
        // C12->printMatrix();
        // printf("\n=========================\n");
        // C21->printMatrix();
        // printf("\n=========================\n");
        // C22->printMatrix();
        // printf("\n=========================\n");

        Matrix * res = new Matrix(0, A->x_length, 0, B->y_length);
        int xx = (1+res->x_length)/2;int yy = (1+res->y_length) / 2;
        int x = 0; int y = 0;
        for(int i = 0; i < C11->x_length && x < xx; i++) {
            y = 0;
            for(int j = 0; j < C11->y_length && y < yy; j++) {
                res->matrix[x][y] += C11->matrix[C11->startx+i][C11->starty+j];
                y++;
            }
            x++;
        }
        x = 0; y = B->y_length - 1;
        for(int i = 0; i < C12->x_length && x < xx; i++) {
            y = yy;
            for(int j = 0; j < C12->y_length && y < res->y_length; j++) {
                res->matrix[x][y] += C12->matrix[C12->startx+i][C12->starty+j];
                y--;
            }
            x++;
        }
        x = xx;y = 0;
        for(int i = 0; i < C21->x_length && x < res->x_length; i++) {
            y = 0;
            for(int j = 0; j < C21->y_length && y < yy; j++) {
                res->matrix[x][y] += C21->matrix[C21->startx+i][C21->starty+j];
                y++;
            }
            x++;
        }
        x = xx; y = yy;;
        for(int i = 0; i < C22->x_length && x < res->x_length; i++) {
            y = yy;
            for(int j = 0; j < C22->y_length && y < res->y_length; j--) {
                res->matrix[x][y] += C22->matrix[C22->startx+i][C22->starty+j];
                y++;
            }
            x++;
        }
        return res;

    }
}



int main(){
    scanf("%d %d %d", &M, &N, &K);
    // for(int i = 0; i < M; i++)
    //     for(int j = 0; j < N; j++)
    //         scanf("%d", &A[i][j]);
    // for(int i = 0; i < N; i++)
    //     for(int j = 0; j < K; j++)
    //         scanf("%d", &B[i][j]);
    Matrix * A = new Matrix(0, M, 0, N);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &A->matrix[i][j]);
    A->calculate();
    Matrix * B = new Matrix(0, N, 0, K);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < K; j++)
            scanf("%d", &B->matrix[i][j]);
    B->calculate();
    Matrix* res = Mul(A, B);
    res->printMatrix();
    delete A;
    delete B;
    return 0;
} 