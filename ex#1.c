#include <stdio.h>
#define PRICE 15.00
#define RATE 0.05

int Capture(int ticket);
double TicketPay(int ticket);
double CalcDiscount(double pricebfr);
double CalcNetPay(double pricebfr, double discount);
void Display();

int main()
{
    Display();

    return 0;
}

int Capture(int ticket)
{
    double tot_price, tot_discount, net_price;
    
    TicketPay(ticket);
    
    CalcDiscount(TicketPay(ticket));
    
    return ticket;
}

double TicketPay(int ticket)
{
    double tot_price;
    tot_price = (double)ticket * PRICE;
    
    return tot_price;
}

double CalcDiscount(double pricebfr)
{
    double discount;
    discount = pricebfr * RATE;

    return discount;
}

double CalcNetPay(double pricebfr, double discount)
{
    double nett_pay;
    nett_pay = pricebfr - discount;

    return nett_pay;
}

void Display()
{
    int ticket, no_ticket;
    double payment, discount, tot_price, nett_pay;

    printf("\t\t~~Welcome To CFS Ticketing System~~\n\n");

    printf("Enter number of tickets: ");
    scanf("%d", &ticket);
    Capture(ticket);    
    
    printf("\nPAYMENT INFORMATION\n");

    no_ticket = Capture(ticket);
    printf("Number of tickets = %d\n", no_ticket);
    
    payment = TicketPay(ticket);
    printf("Total price = RM%.2lf\n", payment);

    discount = CalcDiscount(TicketPay(ticket));
    printf("Discount = RM%.2lf\n", discount);

    nett_pay = CalcNetPay(TicketPay(ticket),CalcDiscount(TicketPay(ticket)));
    printf("Nett pay = RM%.2lf\n", nett_pay);

    return;
}
