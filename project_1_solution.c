//Azra Karin Yilmaz - 2638369 - Assignment 1
#include <stdio.h>
#include <math.h>

int main() {
    char option; //option is for users chocice on a or b -- base is for users choice on 2 or 10
    int base,number,control=1,temp,remainder,binary,decimal,foundation;//number is for input, control is for controlling the loop condition,temp,foundation and remainder is for used in binary-decimal conversing
    int s1,s0,d,Y3,Y2,Y1,Y0;

    do{//i put it in do while because even the condition is wrong it would print it at least 1 time
        printf(" \nWelcome to 1 TO 4 DEMULTIPLEXER \n\n");
        printf("   a) Compute and Display the outputs \n   b)Quit\n");

        printf("\nYou choose: ");
        scanf(" %c", &option);

        if(option=='a') {//if user choose a
            printf("You have chosen option a\n");
            do{
                printf("Wich base will you use to enter input?(base 2 or base 10):");
                scanf("%d", &base);
                if(base ==2){//one of the correct answer, it will break thee "Which base loop" and continue with other
                    break;
                }else if(base==10){//the other correct input, it will leave the game
                    break;
                }else{//if something other than a or b entered my code will ask to enter a base again thats why there is no "break;"
                    printf("Invalid option ! Chooese either a or b!\n");
                }
            }while(base!=2 ||base!=10);//if entered base is not equal to 2 or 10 it will have a loop of asking to enter a base

            if(base==2){//for base 2:
                do {//i used do-while to consider if the number netered true or false i dont know the number input yet so do while is the best option
                    printf("Please enter your input:");
                    scanf("%d", &number);//got the number from user


                    d=number%10;//our assignment said d should be the first digit from left so i got d as this
                    s0=(number%(10*10))/10;//assignment said s0 is middle digit so i get it
                    s1=(number%(10*10*10))/100;//assignment said s1 should be the last digit

                    if(number<100){//if number less than 100 there wont be s1 so there should be error!!
                        if((s1!=1 && s1!=0) || (s0!=1 && s0!=0) || (d !=1 && d!=0)){ //this part is for numbers other than 0 and 1 for example 22 entered this error should be displayed
                            printf("%d is not a valid number in base 2!Please try again!\n", number);
                        }else{//else is for example 01 11 10 kinda numbers, when there is no s1 there will be always this error
                            printf("You entered less than 3 bits!Please try again\n");
                        }
                    }else{//if number is >100 means if number has all d, s0 and s1
                        Y0=(!s1 && !s0 && d);//i looked this calculations from assignment
                        Y1=(!s1 && s0 && d);
                        Y2=(s1 && !s0 && d);
                        Y3=(s1 && s0 && d);

                        decimal=0;//this will store decimal value
                        foundation=0;;//this will follow the power of 2
                        temp=number;//temporary number for used in calculation
                        while(temp>0){ //this part shortly convert binary to decimal so that i can calculate bit number easily because from number 8 it will starting being 4 bits and i can say "more than 3 bit" error more easily
                            remainder=temp%10;//find the last digit of our temporaray number
                            decimal=decimal+(remainder*pow(2, foundation));//updating the decimal number
                            temp/=10;//removing the last digit from our temporary number
                            foundation++;//move to next power of 2 becasue for example 101 first digit from left is 1x2^0 and middle digit is 0x2^1 and last digit is 1x2^2 so the power of 2 is always increaisng by one(1)
                        }//now we found the decimal so we can say if its 3 bits or not
                        if (decimal>=0 && decimal<8){//as we know number from 0 to 7 they are 3 bits and 8 and more are 4 bits and more
                            printf("Y3 iss %d,Y2 is %d, Y1 is %d, Y0 is %d\n", Y3,Y2,Y1,Y0); //so if its stick between 0 to 7 SO its correct
                            control=0;//this do while will continue if control==1 so control=0 makes it break from the loop
                        }else if(decimal >= 8) {//if number is 8 and more it should be at least 4 bits and we may have
                            printf("You entered more than 3 bits! Please try again!\n");//this error for having 4 bits and more
                            control=1;//loop will continue if control=1
                        }
                    }


                }while(control==1);//controlling if the loop should continue or break

            } else if(base ==10){//if base 10 is entered
                do{
                    printf("\nPlease enter your input:");
                    scanf("%d", &number);


                    if(number>=0 && number<8){ //because from 8, the numbers will be equal or more than 4 bits so thats why we stop at 7
                        binary=0; //to store binary value
                        foundation=1;//this will follow the power of 10
                        temp=number; // i did this to keep number's value the same
                        while(temp>0 && temp<8) {//it will only convert number from 0 to 7 because thats what we need
                            remainder=temp%2; //finding the last binary digit
                            temp/=2;//removing the last digit
                            binary=binary+(remainder*foundation);//updating to binary numbr
                            foundation*= 10;//moving to the next power of 10
                        }//ive converted decimal to binary so i can calculate d,s0,s1 easily AND IF I DO THAT i could calculate Y0,Y1,Y2,Y3 easily too

                        d=(binary%10); //d is equal to first digit from the left of the number
                        s0=((binary/10)%10); //s0 is equal to second digit (middle digit) of the number
                        s1=((binary /(10*10))%10); //s1 is equal to third and last digit from left of the number

                        Y0=(!s1 && !s0 && d); //this calculation is from assignment paper
                        Y1=(!s1 && s0 && d);
                        Y2=(s1 && !s0 && d);
                        Y3=(s1 && s0 && d);

                        printf("Y3 iss %d,Y2 is %d, Y1 is %d, Y0 is %d\n",Y3, Y2,Y1,Y0); //this is the case if everything went correct!
                    }else{//if something other than 0-1-2-3-4-5-6-7 entered THEY CANNOT BE REPRESENTED BY 3 BITS so it will give error
                        printf("Decimal %d cannot ne represented with 3 bits. Please try again!\n ",number);//error message for number>=8
                    }


                }while(number<0 || number>7);//if number is other than being between 0 and 7 this loop will keep going till the correct answer
            }
        }else if(option =='b'){//if the user choose option b
            printf("You have chosen option b\n");
            printf("BYEE!!\n");//the process will stop
        } else{//if user choose other than a or b this error message will be givin
            printf("\nInvalid option! Choose either a or b!\n\n");
        }
    }while(option!='b');//while the option input is not b the loop will continue till be is entered


    return 0;
}