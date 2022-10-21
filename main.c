#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))


float arr_x[] = {0.00, 0.15, 0.30, 0.45, 0.60, 0.75, 0.90, 1.05};
const  float arr_y[] = {1.00, 0.838771, 0.655336, 0.450447, 0.225336, -0.018310, -0.278390, -0.552430};
const  float yP[] = {-1.00, -1.14944, -1.29552,-1.43497,-1.56464, -1.68164, -1.78333, -1.86742};

struct data { int head; int tail; };
typedef struct data2 { float value; float x1; float x2; } Values;

struct data getarr(int n, int number) {
    struct data result;
    if((n+1)/2 > number){
        result.head = 0;
        result.tail = n;
        return (result);
    }
    if(number + (n+1)/2 > ARRAY_SIZE(arr_x)-1){
        result.tail = ARRAY_SIZE(arr_x) - 1;
        result.head = result.tail - n;
        return result;
    }
    result.head = number - (n+1)/2;
    result.tail = result.head + n;

    return result;
}

Values * getarr_1(int n, struct data res){
    Values *ptr = calloc(n, sizeof(Values));

    for (int i = res.head; i < res.tail; i++) {
        ptr[i].value = (arr_y[i]-arr_y[i+1])/(arr_x[i] - arr_x[i+1]);
        ptr[i].x1 = arr_x[i];
        ptr[i].x2 = arr_x[i+1];

    }
    printf(" arr1 \n");
    return ptr;
}

void func() {
    Values *ptr5 = NULL;

    ptr5 = (Values *) malloc(5 * sizeof(Values));
}


Values * getarr_2( int n, struct data res, Values * arr1, int length){
    printf(" arr2 \n");

    Values *ptr1 = NULL;
    ptr1 = (Values *) malloc(2 * sizeof(Values));

//    if(ptr1 = NULL){
//                printf("ERROR )) \n");
//
//    }

//    int *param = calloc(3, sizeof (int));

//    for (int i = 0; i < length; i++) {
//        ptr[i].value = (arr1[i].value-arr1[i+1].value)/(arr1[i].x1 - arr1[i+1].x2);
//
//        ptr[i].x1 = arr_x[i];
//        ptr[i].x2 = arr_x[i+1];
//
//    }
    printf("GO )) \n");

    return ptr1;
}

float *getres( int n, struct data res) {
    float *ptr = calloc(n+1, sizeof(float));
    ptr[0] = arr_y[res.head];

    Values *arr1 = NULL;
    arr1 = getarr_1(n, res);
    ptr[1] = arr1[0].value;

    func();

//    Values *arr2 = NULL;
//    arr2 = getarr_2(n, res, arr1 , 3);
//    ptr[2] = arr2[0].value;

//    Values *arr3 = getarr_2(n, res, arr2 , 2);
//    ptr[3] = arr3[0].value;
//
//    Values *arr4 = getarr_2(n, res, arr3 , 1);
//    ptr[4] = arr4[0].value;

//    printf("Массив =>> %f \n",arr2[1].value);

    return ptr;
}



int main() {
    printf("Hello, World!\n");
    float arg;
    int n;
    int number=0;
//    arg = 0.525;
//    n=2;
    printf("Введите n: ");
    scanf("%d", &n);

    printf("Введите x: ");
    scanf("%f", &arg);


    for(int i =0; i < ARRAY_SIZE(arr_x); i++){
        if(arr_x[i] < arg){
            number = i;
        }
    }


    struct data res = getarr(n, number);

    printf("Начало: %d , конец массива: %d  \n", res.head, res.tail);

    float * result = getres(n, res);


    printf("Результат  \n");

    return 0;
}
