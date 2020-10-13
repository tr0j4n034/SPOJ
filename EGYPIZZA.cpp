    #include <iostream>
    #include<stdio.h>
    #include<math.h>
    #include<string.h>
    using namespace std;
     
    int main() {
        int n;
        int half=0,one4=0,three4=0;
        scanf("%d",&n);//no. of slices
        char st[5];
        while(n--)
        {
         scanf(" %s",st);
         if(strcmp(st,"1/4")==0) one4++;
         if(strcmp(st,"1/2")==0) half++;
         if(strcmp(st,"3/4")==0) three4++;//counting no.of slices of each type
        }
        int sum=three4;//counting no.of 3/4 slices
        three4-=one4;//fitting them with 1/4 slices
        if(three4<0)//if its negative, means there still some 1/4 slices
          {
              double k=(-three4 * 1.0/4.0);//sum all left over 1/4 slices
              sum=sum+(int)k;//add no.of pizzas
              k=k-(int)k;//amount cut off last pizza,its <1
              k=1-k;//amount left in last pizza
              if(k>=0.5 && half>0)//if amount left is still >=0.5
                half--;//cut off a half from it
              sum++;//add no. of pizza
          }
        sum=sum+(ceil(half*0.5));//add rest of half slices
        sum=sum+1;//add one pizza of winner
        printf("%d\n",sum);
        return 0;
    } 