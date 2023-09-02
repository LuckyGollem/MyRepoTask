#include <stdio.h>
#include <stdlib.h>

float Kalman(float arr1[],float Variance1,float arr2[],float Variance2,int i){

    if(arr1[i]==0&&arr2[i]==0)
        return 0;
    else{
        float K1=Variance1/(Variance1+Variance2);
        return arr1[i]+K1*(arr2[i]-arr1[i]);
    }
}
int main()
{
    float est[10]={1};
    float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    float mpu6050_Variance = 0.79;
    float bno55_Variance =0.92;

    for(int i=0;i<10;i++)
    est[i]=Kalman(mpu6050,mpu6050_Variance,bno55,bno55_Variance,i);

    for(int i=0;i<10;i++)
        printf("%f\n",est[i]);
    return 0;
}
