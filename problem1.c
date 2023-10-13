#include <stdio.h>

void monthly_report(float monthly_sales[], char month[][25]){
    printf("Monthly Sales Report for 2022:\n");
    printf("%-10s %-10s\n","Month", "Sales");
    for (int i = 0; i <= 11; i++){
      printf("%-10s $%-10.2f\n", month[i], monthly_sales[i]);
    }
    printf("\n");
}

void sales_summary(float monthly_sales[], char month[][25]){
  int max_indx = 0, min_indx = 0;
  float sum = 0;
  for (int i = 0; i <= 11; i++){
    if (monthly_sales[i] > monthly_sales[max_indx]){
      max_indx = i;
    }
    if (monthly_sales[i] < monthly_sales[min_indx]){
      min_indx = i;
    }
    sum += monthly_sales[i];
  }
  float avg = sum/12;
  printf("Sales Summary:\n");
  printf("Minimum Sales: $%-10.2f (%s)\n",monthly_sales[min_indx], month[min_indx]);
  printf("Maximum Sales: $%-10.2f (%s)\n",monthly_sales[max_indx], month[max_indx]);
  printf("Average Sales: $%-10.2f\n",avg);
  printf("\n");
}

void moving_avg(float monthly_sales[], char month[][25]){
  printf("Six-Month Moving Average Report:\n");
  for (int i = 0; i <= 6; i++){
    float sum = 0, avg;
    for (int j = i; j <= i + 5; j++){
      sum += monthly_sales[j];
    }
    avg = sum/6;
    printf("%-10s - %-10s $%.2f\n", month[i], month[i+5], avg);
  }
  printf("\n");
}

void sales_report(float monthly_sales[], char month[][25]){
  float ordered_sales[12];
  int indx_order[12];
  for (int i = 0; i <= 11; i++){
    ordered_sales[i] = monthly_sales[i];
    indx_order[i] = i;
  }
  for (int i = 0; i <= 11; i++){
    for (int j = 0; j <= 11 - i; j++){
      if (ordered_sales[j] < ordered_sales[j + 1]){
        float temp_sales= ordered_sales[j];
        ordered_sales[j] = ordered_sales[j + 1];
        ordered_sales[j + 1] = temp_sales;

        int temp_indx = indx_order[j];
        indx_order[j] = indx_order[j + 1];
        indx_order[j + 1] = temp_indx;
      }
    }
  }
  printf("Sales Report (Highest to Lowest)\n");
  printf("%-10s %-10s\n","Month", "Sales");
  for (int i = 0; i <= 11; i++){
    int indx = indx_order[i];
    printf("%-10s $%-10.2f\n", month[indx], ordered_sales[i]);
  }
  printf("\n");
}

int main(){
  float monthly_sales[12];
  char month[12][25] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  printf("Enter monthly sales for 2022:\n");
  for (int i = 0; i <= 11; i++){
    printf("%s: $", month[i]);
    scanf("%f", &monthly_sales[i]);
  }
  printf("\n");

  monthly_report(monthly_sales, month);
  sales_summary(monthly_sales, month);
  moving_avg(monthly_sales, month);
  sales_report(monthly_sales, month);
  return 0;
}