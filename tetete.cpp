#include <stdio.h>
// define function

void pcrRegistration(){
    char cUserName;
    printf("masukkan ininsial anda: ");
	scanf(" %c", cUserName);
}

int pcrChooseVehicle(char* cChoiceVehicle,int* nHour){
    printf("S = Sedan  || (RM/h = 20.00)\n");
    printf("L = Luxury || (RM/h = 35.00)\n");
    printf("M = MPV    || (RM/h = 45.00)\n");
    printf("Insert type car for rent: ");
    scanf(" %c", *cChoiceVehicle);
    printf("Total hours of renting: ");
    scanf(" %i", *nHour);
    return cChoiceVehicle;
    return nHour;
}

int TotalPrice(const char* cChoiceVehicle, const int nHour){
    float resultprice;
    if(cChoiceVehicle == 'S'){
        resultprice = nHour * 20.00;
        if(nHour > 18){
            resultprice = resultprice - resultprice*0.1;
        }
    } else if(cChoiceVehicle == 'L'){
        resultprice = nHour * 35.00;
        if(nHour > 18){
            resultprice = resultprice - resultprice*0.15;
        }
    }else if (cChoiceVehicle == 'M'){
        resultprice = nHour * 45.00;
        if (nHour > 18){
            resultprice = resultprice - resultprice*0.2;
        }
    }
    return resultprice;
}

int main(){
    char cUserName;
    char cChoiceVehicle;
    int nHour;
    int nResultPrice;
    int cChoiceMenu;
    
    while (1)
    {
        printf("***********************************************\n");
        printf("**********ELECTRIC VEHICLE RENTAL APP**********\n");
        printf("*				MENU	 				      *\n");
        printf("*PROGRAM		DESCRIPTION			          *\n");
        printf("*   1			Registration			      *\n");
        printf("*   2			Choose vehicle	   		      *\n");
        printf("*   3			Details & Payments			  *\n");
        printf("*   4			Exit			              *\n");
        printf("***********************************************\n");
        printf("***********************************************\n");
        scanf("%d", &cChoiceMenu);

        switch (cChoiceMenu)
        {
        case 1:
            pcrRegistration();
            continue;
            
        case 2:
            pcrChooseVehicle(cChoiceVehicle, nHour);
            continue;
            
        case 3:
            nResultPrice = TotalPrice(cChoiceVehicle, nHour);
            printf("your car was %c\ntime: %i Hours\n", cChoiceVehicle, nHour);
    		printf("total price: %.2f RM\n", nResultPrice);
			printf("atas nama %s\n", cUserName);
            continue;

        case 4:
            printf("Exitting app");
            break;

        default:
            printf("input false coba lagi");
            break;
        }
        break;
    }
}