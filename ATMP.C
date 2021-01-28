//Code for ATM
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct customer
{
char type[10];
char pin[5];
char name[20],add[50],acno[17],phno[11];
long int bal;
}c;
FILE *fp;
int i,cho;
char ch,w;
void with_drawal()
{
long int with_bal;
while(1)
{
printf("\n\n\t********************************************************");
printf("\n\n\n\n\t\tenter amount in 100's: ");
scanf("%ld",&with_bal);
clrscr();
if(with_bal>c.bal)
{
printf("\n\n\t********************************************************");
printf("\n\n\n\n\t\tinsufficient balance ");
}
else
{
fp=fopen("kamala","r");
fread(&c,sizeof(c),1,fp);
c.bal-=with_bal;
fclose(fp);
printf("\n\n\t********************************************************");
printf("\n\n\n\n\n\n\n\t\tYour Transaction has been processing...");
sleep(3);
clrscr();
printf("\n\n\t********************************************************");
printf("\n\n\n\n\n\n\n\n\n\t\t\tTake your Money. ");
fp=fopen("kamala","w");
fwrite(&c,sizeof(c),1,fp);
fclose(fp);
sleep(2);
clrscr();
break;
}
sleep(3);
clrscr();
}
}
void bal_enquiry()
{

fp=fopen("kamala","r");
fread(&c,sizeof(c),1,fp);
printf("\n\n\t********************************************************");
printf("\n\n\n\n\t\t");
printf("\n\tHi %s",c.name);
printf("\n\n\t\t Your Total Balance is: ");
printf("%li",c.bal);
sleep(2);
clrscr();
}
void pinn(char *q)
{
for(i=0;i<4;i++)
{
q[i]=getch();
printf("*");
}
fflush(stdin);
getch();
sleep(1);
q[4]='\0';
clrscr();
printf("\n\n\t********************************************************");
}
void pin_change()
{
char q1[5],q2[5];
while(1)
{
printf("\n\n\t********************************************************");
printf("\n\n\n\n\n\n\n\t\t Enter a new pin number \n\n\t\t\t");
pinn(q1);
printf("\n\n\n\n\n\n\n\t\t re-enter your pin number \n\n\t\t\t");
pinn(q2);
if(strcmp(q1,q2))
{
printf("\n\n\n\n\n\n\n\t\tpin number is not matched. ");
}
else
{
fp=fopen("kamala","w");
strcpy(c.pin,q1);
fwrite(&c,sizeof(c),1,fp);
fclose(fp);
printf("\n\n\n\n\n\n\n\n\t\t Your pin number has been changed successfully.");
break;
}
}
sleep(4);
clrscr();
}
void view_acc()
{
fp=fopen("kamala","r");
fread(&c,sizeof(c),1,fp);

printf("\n\n\n\t*******************************************");
printf("\n\t\tYour account details");
printf("\n\t-------------------------------------------");
printf("\n\tName :%s",c.name);
printf("\n\tAdd :%s",c.add);
printf("\n\tA/C no :%s",c.acno);
printf("\n\tph no :%s",c.phno);
printf("\n\tbalance :%ld",c.bal);
sleep(5);
clrscr();
}
void details()
{
fp=fopen("kamala","w");
strcpy(c.type,"saving");
strcpy(c.acno,"998745623456");
strcpy(c.phno,"9999444488");
strcpy(c.pin,"1234");
strcpy(c.name,"Kamala Kasula");
strcpy(c.add,"bachupally, hyderabad");
c.bal=10000;
fwrite(&c,sizeof(c),1,fp);
fclose(fp);
}
void main()
{
char p[5];
clrscr();
details();
printf("\tVNR Vignana Jyothi Institute Of engineering and Technology");
printf("\n\n\t********************************************************");
printf("\n\t\tWelcome to Taxes Bank ATM");
printf("\n\n\n\n\n\n\n\n\n\n\n\t\tINSERT YOUR CARD");
sleep(5);
clrscr();
fp=fopen("kamala","r");
fread(&c,sizeof(c),1,fp);
while(1)
{
printf("\n\n\t********************************************************");
printf("\n\n\n\t\tEnter your pin number\n\n\t\t\t");
pinn(p);
clrscr();
printf("\n\n\t********************************************************");
if(strcmp(p,c.pin))
printf("\n\n\n\n\n\t\t\tInvalid pin number.");
else
{
printf("\n\n\n\t1.Withdrawal\n\t2.view Account\n\t3.Balance Enquiry\n\t4.pin change\n\t5.Exit");
printf("\n\n\n\t\tEnter your choice: ");
scanf("%d",&cho);
clrscr();
switch(cho)
{
case 1:with_drawal();break;
case 2:view_acc();break;

case 3:bal_enquiry();break;
case 4:pin_change();break;
case 5:printf("\n\n\n\n\n\n\n\tThank You for visiting our Taxes Bank.");
getch();exit(0);break;
default:printf("\n\nInvalid choice");
sleep(2);
clrscr();
}
}
printf("\n\n\t********************************************************");
printf("\n\n\n\n\tDo you want to make another transaction(y/n): ");
fflush(stdin);
scanf("%c",&w);
if(w=='n')
{
printf("\n\n\n\n\n\n\n\tThank You for visiting our Taxes Bank.");
sleep(2); getch();
break;
}
sleep(1);
clrscr();
}
fclose(fp);
}