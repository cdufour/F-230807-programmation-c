#include <stdio.h>
#include <string.h>

union Data {
    int x;
    double y;
    //char z[32];
};

typedef struct {
    int type;
    union {
        char x[1024];
        float y[1024];
        double z[1024];
    } buffer;
} Info;


int main() {
    union Data mydata;

    mydata.x = 10;
    //mydata.y = 20.5;
    //strcpy(mydata.z, "super test");

    printf("mydata.x = %d\n", mydata.x);
    printf("mydata.y = %f\n", mydata.y);
    //printf("mydata.z = %s\n", mydata.z);

    printf("mydata size: %lu\n", sizeof(mydata));

    mydata.y = 20.5;

    printf("mydata.x = %d\n", mydata.x);
    printf("mydata.y = %f\n", mydata.y);
    //printf("mydata.z = %s\n", mydata.z);


    Info info;
    info.type = 0;

    memset(info.buffer.x, 'x', 1024);
    //info.buffer.y[1017] = 3.14;
    //printf("%c\n", info.buffer.x[500]);

    if (info.type == 1) {
        for (int i = 0; i < 1024; i++) {
            printf("info.buffer.z[%d] = %c\n", i, info.buffer.z[i]);
        }
    } else if (info.type == 1) {
        for (int i = 0; i < 1024; i++) {
            printf("info.buffer.y[%d] = %f\n", i, info.buffer.y[i]);
        }
    }

    return 0;
}