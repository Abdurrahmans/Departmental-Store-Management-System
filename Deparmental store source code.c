#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define SIZE 256
void login(void);
void reg(void);
void category(void);
void offer(void);
void srch(void);
void showtransaction();
void myzone(void);
void helpcentre(void);
void product_list(void);
void buynow(void);
void transaction(void);
void smycart();
void vmycart(void);
void pendingorder(void);
void user_info(void);
void admin_panel(void);
void ttt(void);
void delay(unsigned int);
struct product{
char name[20];
int id;
float price;
float rating;
char review[50];
char details[100];
char category[20];
}p[100];
struct transaction{
   char name[30];
   int id;
   float unitprice;
   char dlocation[50];
   int quantity;
   char acname[20];
   float total;

}tr;
struct mycart{
int id;
char name[20];
float price,rating,utotal,quantity;
char rname[20],rlocation[50],acname[10],date[10];
}mc[50];
struct user{
char name[20];
char mail[30];
char pass[20];
int reward;
}uu[100];
struct Offer{
char off[20];
}o[11];
int i=0,t,tt,n,lp,lu,lt,home=0,admin=0,again=0,selectid,reward=0,from_offer=0,m;
float total,quantity,utotal;char acname[10],dlocation[50],name[30], fname[20],date[10],buffer[SIZE];;
FILE *file,*fp,*fl,*fr,*fpurchase,*fcart,*fadmin;
struct log{
char uname[20],upass[20],umail[30];
int ureward;
}u[50];
COORD coord = {0, 0};
COORD max_res,cursor_size;

char uname[30];
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
//system("COLOR 3F");
char ex[]="Thanks for using the system...";
char en[]="WELCOME TO A.R DEPARTMENTAL STORE";
system ("cls");
if(home==1)
goto AB;
ttt();
strcpy(date,buffer);
printf("%s",buffer);
system ("cls");
XY:
windoww(28,72,3,23);
gotoxy(29,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(29,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(29,6);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(36,10);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xB2 LOGIN \xB2\xDb\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(36,13);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xB2 REGISTER \xB2\xDb\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(36,16);
printf("\xDB\xDB\xDB\xDB\xDb\xB2 LOGIN AS ADMIN \xB2\xDb\xDB\xDB\xDB\xDB");
gotoxy(36,19);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xB2\xB2\xDb\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(36,5);
for(i=0;i<33;i++){
delay(70);
printf("%c",en[i]);
}
gotoxy(49,19);
n=_getch();
switch(n)
{
case '1': system ("cls");
login();
break;
case '2': system ("cls");
reg();
break;
case '3': system ("cls");
admin=1;
login();
break;
default: printf("\n\n\t\t\t\t\t NO MATCH FOUND");
printf("\n\t\t\t\t Press Enter to re-Enter the choice");
_getch();
system ("cls");
goto XY;
break;
}
AB:
system ("cls");
window(30,70,7,24);
windoww(28,72,3,25);
gotoxy(31,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 HOME MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(33,10);
printf("\xDB\xDB\xDB\xDb\xB2 1. Choose Category");
gotoxy(33,12);
printf("\xDB\xDB\xDB\xDb\xB2 2. Search Item");
gotoxy(33,14);
printf("\xDB\xDB\xDB\xDb\xB2 3. Hot Offers");
gotoxy(33,16);
printf("\xDB\xDB\xDB\xDb\xB2 4. My Zone");
gotoxy(33,18);
printf("\xDB\xDB\xDB\xDb\xB2 5. Ask For Help");
gotoxy(33,20);
printf("\xDB\xDB\xDB\xDb\xB2 6. Exit");
gotoxy(39,23);
printf("<<<<<<<<< >>>>>>>>>>");
gotoxy(49,23);
switch(_getch())
{
system ("cls");
case '1':
category();
break;
case '2':
srch();
goto AB;
break;
case '3':
offer();
getch();
goto AB;
case '4':
myzone();
case '5':
system("cls");
window(30,70,7,24);
gotoxy(31,5);
printf("<<<<<<<<<<<< Help Center >>>>>>>>>>>>>");
gotoxy(31,10);
printf("Please Contact us for any kind of query");
printf("\n\n\t\t\t\tContact No: +8801738526663");
printf("\n\t\t\t\tEmail: abdurrahmansmark1997@gmail.com");
printf("\n\n\n\n\t\t\t\t\t***** Thank You! *****");
_getch();
goto AB;
break;
case '6':
{
system("cls");
gotoxy(32,10);
for(i=0;i<31;i++)
{
delay(50);
printf("%c",ex[i]);
}
printf("\n\n\n");
delay(120);
exit(0);
}
default:
{
printf("\n\n\tWrong Entry!!Please re-entered correct option");
getch();
goto AB;
}
}
return 0;
}
void myzone()
{
system("cls");
window(30,70,7,24);
windoww(28,72,3,25);
gotoxy(31,5);
printf("=============== MY ZONE ===============");
gotoxy(33,10);
printf("\xB2\xB2\xB2 1. My Cart");
gotoxy(33,12);
printf("\xB2\xB2\xB2 2. My Pending Orders");
gotoxy(33,14);
printf("\xB2\xB2\xB2 3. My Rewards");
gotoxy(33,16);
printf("\xB2\xB2\xB2 4. Back to Home");
gotoxy(38,23);
printf("<<<<<<<<<< >>>>>>>>>>");
gotoxy(48,23);
switch(_getch())
{
system("cls");
case '1':
vmycart();
//_getch();
myzone();
break;
case '2':{
system("cls");
//pendingorder();
gotoxy(10,1);
//printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Pending Orders \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//pendingorder();
//usertransaction(uname);
printf("Press any key to continue...");
_getch();
myzone();
break;}
case '3':
user_info();
for(i=0;i<lu;i++){
if(strcmp(uu[i].name,name)==0){
reward=uu[i].reward;
}}
int need=500-reward;
system("cls");
windoww(23,80,3,25);
gotoxy(24,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MY REWARDS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\n\n\t\t\t\t\xDB\xDB\xDB\xDb\xB2 My Points: %d",reward);
printf("\n\n\t\t\t\t\xDB\xDB\xDB\xDb\xB2 Points need to get cashback: %d",need);
printf("\n\n\n\t\t\t Terms & Conditions:-\n\t\t\t >> After completing each transaction you will \n\t\t\treceive 50 points");
printf("\n\t\t\t >> For every 500 points, you will get 500 TK \n\t\t\tinstant cashback");
printf("\n\n\t\t\t Press Enter to back.....");
_getch();
home=1;
myzone();
break;
case '4':
home=1;
main();
break;
default:
{
printf("\n\n\t\t\tWrong Entry!!Please re-entered correct option");
_getch();
myzone();
break;
}
}
}
void smycart()
{
fcart=fopen(name,"a");
fprintf(fcart,"\n%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f",p[i].id,p[i].name,p[i].rating,quantity,p[i].price,utotal);
fclose(fcart);
system("cls");
gotoxy(32,6);
printf("******Selected Item has been added!!!\n\t\t\t\tCheck it to Home>> My Zone>> My Cart");
_getch();
home=1;
main();
}

void vmycart()
{
system("cls");
fcart=fopen(name,"r+");
tt=line_count(name);
tt=tt+1;
int jj=1;
if(fcart==NULL){
printf("\n\n\t\t\t\tYour Cart is Empty!");
_getch();
myzone();
}
else
{
for(i=0;i<tt;i++){
fscanf(fcart,"%d\t%s\t%f\t%f\t%f\t%f\n",&mc[i].id,mc[i].name,&mc[i].rating,&mc[i].quantity,&mc[i].price,&mc[i].
utotal);
}
int j,jj=0, temp;
float temp1;
char temp2[20];
for(i=0;i<tt-1;i++){
for(j=0;j<tt-1-i;j++){
if(mc[j].utotal<mc[j+1].utotal){
temp1=mc[j].utotal;
mc[j].utotal=mc[j+1].utotal;
mc[j+1].utotal=temp1;
temp=mc[j].id;
mc[j].id=mc[j+1].id;
mc[j+1].id=temp;
strcpy(temp2,mc[j].name);
strcpy(mc[j].name,mc[j+1].name);
strcpy(mc[j+1].name,temp2);
//strcpy(temp2,mc[j].date);
//strcpy(mc[j].date,mc[j+1].date);
//strcpy(mc[j+1].date,temp2);
temp1=mc[j].rating;
mc[j].rating=mc[j+1].rating;
mc[j+1].rating=temp1;
temp1=mc[j].price;
mc[j].price=mc[j+1].price;
mc[j+1].price=temp1;
}
}
}
ac:
printf("\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MY CART\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\n\t\t\t Name:\t\t ID\tRating \tQuantity\tUnit Price\tGross\n");
printf("\n\t\t\t---------------------------------------------------------------------------");
total=0;
for(i=0;i<tt-1;i++){
printf("\n\t\t\t%s\t%d\t%.2f\t %.2f \t%.2f\t%.2f",mc[i].name,mc[i].id,mc[i].rating,mc[i].quantity,mc[i].price,mc[i].utotal);
total=total+mc[i].utotal;
}
printf("\n\t\t\t===========================================================================");
fclose(fcart);
printf("\n\t\t\t>>1. Buy All\t >>2. Delete Item\t>>3. Back to Previous Menu\n\t\t\t\t");
switch(_getch())
{
case '1':
{j=0;
printf("\n\t\t\tEnter Delivery Location: ");
scanf("%s",dlocation);
//if(jj==1)
//tt=tt-1;
system("cls");
transaction();
remove(name);
fpurchase=fopen("purchase.txt","a");
FILE *ftransaction;
ftransaction=fopen("transaction.txt","a");
ttt();
for(i=0;i<tt-1;i++){
fprintf(fpurchase,"\n%s\t%d\t%s\t%.2f\t%s\t%s\t%s\t%.2f",name,mc[i].id,mc[i].name,mc[i].quantity,acname,dlocation,buffer,mc[i].utotal);
  tr.id =mc[i].id;
  strcpy(tr.name,mc[i].name);
  tr.quantity = mc[i].quantity;
  tr.total =mc[i].utotal;
  tr.unitprice = mc[i].price;
  strcpy(tr.acname,acname);
  strcpy(tr.dlocation,dlocation);
  //fprintf(ftransaction,"\n%s\t%d\t%d\t%.2f\t%.2f\t%s\t%s",tr.name,tr.id,tr.quantity,tr.unitprice,tr.total,tr.acname,tr.dlocation);
  fwrite(&tr,sizeof(tr),1,ftransaction);
}
fclose(ftransaction);
fclose(fpurchase);
break;}
case'2':
printf("\n\t\t\tEnter an ID to Remove from the Cart:");
int removeid,removeindex,nn=0;
char nullStr[20] = {"\0"};
scanf("%d",&removeid);
for(i=0;i<tt;i++){
if(removeid==mc[i].id){
removeindex=i;
nn=1;
}
}
if(nn==1){
for(j=removeindex;j<tt-1;j++){
mc[j].utotal=mc[j+1].utotal;
mc[j].id=mc[j+1].id;
strcpy(mc[j].name,mc[j+1].name);
mc[j].rating=mc[j+1].rating;
mc[j].price=mc[j+1].price;
jj=1;
}
tt=tt-1;
system("cls");
goto ac;}
else{printf("\n\n\aWrong Entry!!Please re-entered correct option");
_getch();
vmycart();
}
break;
case '3':
myzone();
break;
default :
printf("\n\n\aWrong Entry!!Please re-entered correct option");
_getch();
vmycart();
break;
}
}
}
void pendingorder()
{
fpurchase=fopen("purchase.txt","r");
lp=line_count("purchase.txt");
if(fpurchase!=NULL){
         while(fread(&tr,sizeof(tr),1,fpurchase)){
    printf("\n\t%s\t\t%d\t\t%d\t\t%.2f\t\t%.2f\t\t%s\t\t%s",tr.name,tr.id,tr.quantity,tr.unitprice,tr.total,tr.acname,tr.dlocation);
         }
}
else{

//printf("\nNo Request Available!");
//fclose(fpurchase);
}
fclose(fpurchase);
}
void category()
{
if(from_offer==1)
goto buy;
char categoryn[20];
ctgry:
system("cls");
product_list();
t=line_count("product_list.txt");
t=t+1;
window(30,70,7,24);
windoww(28,72,3,25);
gotoxy(31,5);
printf("XXXXXXXXXXXXXX CATEGORY XXXXXXXXXXXXXXX");
gotoxy(33,9);
printf("\xB2\xB2\xB2 1. Beverages");
gotoxy(33,11);
printf("\xB2\xB2\xB2 2. Bakery & Baking Items");
gotoxy(33,13);
printf("\xB2\xB2\xB2 3. Jarred Items");
gotoxy(33,15);
printf("\xB2\xB2\xB2 4. Dairy Items");
gotoxy(33,17);
printf("\xB2\xB2\xB2 5. Produce & Meat Items");
gotoxy(33,19);
printf("\xB2\xB2\xB2 6. Personal Care & Other Items");
gotoxy(33,21);
printf("\xB2\xB2\xB2 7. Back to Home");
gotoxy(38,23);
printf("<<<<<<<<<< >>>>>>>>>>");
gotoxy(48,23);
switch(_getch())
{
case '1':
strcpy(categoryn,"Beverages");
break;
case '2':
strcpy(categoryn,"Bakery & Baking Items");
break;
case '3':
strcpy(categoryn,"Jarred Items");
break;
case '4':
strcpy(categoryn,"Dairy Items");
break;
case '5':
strcpy(categoryn,"Produce & Meat Items");
break;
case '6':
strcpy(categoryn,"Personal Care & Other Items");
break;
case '7':
home=1;
main();
default:{
printf("\n\n\aWrong Entry!!Please re-entered correct option");
getch();
goto ctgry;
}
}
system("cls");
plist:
printf("\n\t============================================================================");
printf("\n\t ID\tCategory\t Name\t Price\tRating Replacement ");
printf("\n\t============================================================================");
for(i=0;i<t;i++){
if(strcmp(p[i].category,categoryn)==0){
printf("\n\t%d\t%s\t%s\t %.2f\t %.2f\t%s\n",p[i].id,p[i].category,p[i].name,p[i].price,p[i].rating,p[i].details);
}}
printf("\n\n\t\t\xDB\xDB\xDB\xDB\xDB 1. Select an Item \t\t\xDB\xDB\xDB\xDB\xDB 2. Back to Previous\n\t\t\t\t");
switch(_getch())
{case '1':
goto buy;
break;
case '2':
category();
break;
}
buy:
printf("\n\n\tEnter Product ID: ");
scanf("%d",&selectid);
for(i=0;i<t;i++){
if(p[i].id==selectid){
c:
system("cls");
printf("\n\t\t********** Selected Item: %s **********",p[i].name);
printf("\n\n\t\t\tProduct ID: %d",p[i].id);
printf("\n\n\t\t\tCategory: %s",p[i].category);
printf("\n\n\t\t\tUnit Price: %.2f",p[i].price);
printf("\n\n\t\t\tRating: %.2f",p[i].rating);
printf("\n\n\t\t\tReview: %s",p[i].review);
printf("\n\t\t---------------------------------------------");
printf("\n\t\t >>1. Buy Now\t\t>>2. Add to My Cart\n\n\t\t\t >>3. Back to Home\n\t\t\t ");
switch(_getch())
{
case '1':
buynow();
break;
case '2':
printf("\n\t\t\t******Item: %s******",p[i].name);
printf("\n\n\t\t\tEnter Quantity: ");
scanf("%f",&quantity);
utotal=quantity*p[i].price;
smycart();
break;
case '3':
home=1;
main();
break;
default:{
printf("\n\n\aWrong Entry!!Please re-entered correct option");
getch();
goto c;}
}
break;}
else if(i==t-1){
printf("\n\n\aWrong Entry!!Please re-entered correct option");
getch();
system("cls");
goto plist;
}
}
from_offer=0;
_getch();
//goto ab;home=1;
main();
}
void offer()
{
strcpy(o[0].off,"25% Off!!!");
strcpy(o[1].off,"05% Off!!!");
strcpy(o[2].off,"T-ShirtFree!!!");
strcpy(o[3].off,"10% Off!!!");
strcpy(o[4].off,"Buy1 Get1Free!!!");
strcpy(o[5].off,"30% Cash Back!!!");
strcpy(o[6].off,"18% Off!!!");
strcpy(o[7].off,"Buy 3 Get 1 Free!!!");
strcpy(o[8].off,"10% Cash Back!!!");
strcpy(o[9].off,"Buy3 Get1Free!!!");
strcpy(o[10].off,"Buy3 Get1Free!!!");
strcpy(o[11].off,"NoOfferAvailable");
system ("cls");
product_list();
t=line_count("product_list.txt");
t=t+1;
int x=0;
gotoxy(10,1);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ONGOINGOFFERS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\
xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(10,3);
printf("=====================================================================================================");
gotoxy(10,4);
printf("|");
gotoxy(12,4);
printf("ID");
gotoxy(17,4);
printf("|");
gotoxy(21,4);
printf("Category");
gotoxy(31,4);
printf("|");
gotoxy(35,4);
printf("Name");
gotoxy(52,4);
printf("|");
gotoxy(56,4);
printf("Price");
gotoxy(66,4);
printf("|");
gotoxy(68,4);
printf("Rating");
gotoxy(78,4);
printf("|");
gotoxy(80,4);
printf("Replacement");
gotoxy(91,4);
printf("|");
gotoxy(96,4);
printf("Offer*");
gotoxy(110,4);
printf("|");
gotoxy(10,5);
printf("=====================================================================================================");
int j=6;
for(i=0;i<t;i++){
gotoxy(10,j);
printf("|");
gotoxy(11,j);
printf("%d",p[i].id);
gotoxy(17,j);
printf("|");
gotoxy(19,j);
printf("%s",p[i].category);
gotoxy(31,j);
printf("|");
gotoxy(33,j);
printf("%s",p[i].name);
gotoxy(52,j);
printf("|");
gotoxy(54,j);
printf("%.2f",p[i].price);
gotoxy(66,j);
printf("|");
gotoxy(68,j);
printf("%.2f",p[i].rating);
gotoxy(78,j);
printf("|");
gotoxy(84,j);
printf("%s",p[i].details);
gotoxy(91,j);
printf("|");
gotoxy(93,j);
printf("%s",o[x].off);
gotoxy(110,j);
printf("|");
gotoxy(10,j+1);
printf("------------------------------------------------------------------------------------------------ -----");
j=j+2;
i=i+9;
x=x+1;
}
printf("\n\t\t1. Choose an Offer\t 2. Back to Home");
switch(_getch()){
case '1':
from_offer=1;
category();
break;
case '2':
home=1;
main();
break;
}
}
void product_list()
{
t=line_count("product_list.txt");
t=t+1;
fl=fopen("product_list.txt","r");
for(i=0;i<t;i++){
fscanf(fl,"%d\t%s\t%s\t%f\t%f\t%s",&p[i].id,p[i].category,p[i].name,&p[i].price,&p[i].rating,p[i].details);
}
fclose(fl);
fr=fopen("review.txt","r");
t=line_count("product_list.txt");
t=t+1;
for(i=0;i<t;i++){
fgets(p[i].review,50,fr);
}
}
void reg()
{
FILE *fp;
char c,mail[30],pass[20],checker[30];
int z=0;
fp=fopen("Web_reg.txt","a+");
gotoxy(26,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO REGISTER ZONE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
if(again==1){
printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
}
again=0;
printf("\n\n\t\t\t\t \xDB\xDB\xDB ENTER USERNAME: ");
scanf("%s",checker);
char file_name[]="Web_reg.txt";
t=line_count(file_name);
t=t+1;
for(i=0;i<t;i++)
{
fscanf(fp,"%s\t%s\t%s\t%d\n",u[i].uname,u[i].upass,u[i].umail,&u[i].ureward);
if(strcmp(checker,u[i].uname)==0)
{
system ("cls");
again=1;
reg();}
else
{
if(i==t-1){
break;}
}
}
printf("\n\n\t\t\t\t \xDB\xDB\xDB ENTER MOBILE NO: ");
scanf("%s",mail);
printf("\n\n\t\t\t\t \xDB\xDB\xDB DESIRED PASSWORD: ");
while((c=_getch())!=13)
{
pass[z++]=c;
printf("%c",'*');
}
pass[z]='\0';
fprintf(fp,"\n%s\t%s\t%s\t00",checker,pass,mail);
fclose(fp);
printf("\n\n\t\t\tPress enter if you agree with Username and Password");
if((c=_getch())==13)
{
system ("cls");
gotoxy(26,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO REGISTER ZONE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\n\t\t\t\tYou are successfully registered");
printf("\n\n\t\t\t\tTry login your account??\n\n\t\t\t\t ");
printf("> PRESS 1 FOR YES\n\n\t\t\t\t > PRESS 2 FOR NO\n\n\t\t\t\t");
scanf("%d",&n);
switch(n)
{
case 1: system ("cls");
login();
break;
case 2:{
printf("\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
_getch();
main();
break;}
}
}
_getch();
}
void login()
{
FILE *fp;
char c,pass[30]; int z=0,j;
int checku,checkp;
fp=fopen("Web_reg.txt","r");
if(admin==1){
gotoxy(26,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME ADMIN PORTAL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
}
else{
gotoxy(26,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO LOGIN ZONE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
}
for(i=0;i<1000;i++)
{
printf("\n\n\t\t\t\t \xDB\xDB\xDB ENTER USERNAME: ");
scanf("%s",name);
printf("\n\t\t\t\t \xDB\xDB\xDB ENTER PASSWORD: ");
while((c=_getch())!=13)
{
pass[z++]=c;
printf("%c",'*');
}
pass[z]='\0';
char file_name[]="Web_reg.txt";
t=line_count(file_name);
t=t+1;
for(i=0;i<t;i++)
{
fscanf(fp,"%s\t%s\t%s\t%d\n",u[i].uname,u[i].upass,u[i].umail,&u[i].ureward);
}
for(i=0;i<t;i++)
{
checku=strcmp(name,u[i].uname);
checkp=strcmp(pass,u[i].upass);
if(checku==0&&checkp==0)
{
    strcpy(uname,u[i].uname);
system ("cls");
gotoxy(26,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO LOGIN ZONE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\n\t\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!");
printf("\n\n\n\t\t\t\t\t WELCOME, HAVE A NICE DAY!!");
if(admin==1){
admin_panel();
exit(1);
}
_getch();
break;
}
else if(checku==0&&checkp!=0)
{
printf("\n\n\n\t\t\t\t WRONG PASSWORD!! Not %s??",pass);
printf("\n\n\t\t\t\t (Press any key to re-login)");
_getch();system ("cls");
login();

}
else if(checku!=0)
{
if(i==t-1){
printf("\n\n\n\t\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
if(_getch()==13)
system ("cls");
main();}
}
}
break;
}
//_getch();
}
int line_count(const char *filename)
{
int ch = 0;
int count = 0;
FILE *file= fopen(filename, "r");
if(file==NULL){
//printf("File not found\n");
//exit(1);
}
do {
ch = fgetc(file);
if ( ch == '\n')
count++;
} while (ch != EOF);
fclose(file);
return count;
}
void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock());
}
void buynow()
{
system("cls");
windoww(28,72,3,23);
gotoxy(29,5);
printf(":::::::::::::: ITEM SELECTION :::::::::::::");
gotoxy(33,9);
printf("\xDB\xDB\xDB Selected Item: %s",p[i].name);
strncpy(tr.name,p[i].name,30);
tr.id = p[i].id;
tr.unitprice = p[i].price;
gotoxy(33,12);
printf("\xDB\xDB\xDB Enter Quantity: ");
scanf("%f",&quantity);
tr.quantity=quantity;
gotoxy(33,15);
printf("\xDB\xDB\xDB Enter Delivery Location: ");
scanf("%s",dlocation);
strncpy(tr.dlocation,dlocation,50);
gotoxy(33,18);total=quantity*p[i].price;
tr.total = total;
system("cls");
windoww(28,72,3,25);
gotoxy(29,5);
printf(":::::::::::::: ITEM SELECTION :::::::::::::");
gotoxy(33,9);
printf("<o> Selected Item: %s",p[i].name);
gotoxy(33,11);
printf("<o> Quantity : %.1f",quantity);
gotoxy(33,13);
printf("<o> Unit Price : %.2f Tk.",p[i].price);
gotoxy(33,15);
printf("<o> Total Amount: %.2f Tk.",total);
gotoxy(33,17);
printf("<o> tLocation : %s",dlocation);
gotoxy(33,20);
printf("**Press Enter to Agree!");
_getch();
system("cls");
transaction();
ttt();
strncpy(tr.acname,acname,20);
FILE *ftransaction;
ftransaction=fopen("transaction.txt","a");
//fprintf(ftransaction,"\n%s\t%d\t%d\t%.2f\t%.2f\t%s\t%s",tr.name,tr.id,tr.quantity,tr.unitprice,tr.total,tr.acname,tr.dlocation);
fwrite(&tr,sizeof(tr),1,ftransaction);
fclose(ftransaction);
fpurchase=fopen("purchase.txt","a");
fprintf(fpurchase,"\n%s\t%d\t%s\t%.2f\t%s\t%s\t%s\t%.2f",name,p[i].id,p[i].name,quantity,acname,dlocation,buffer,total);
fclose(fpurchase);
}
void transaction()
{
char d[]="Thank You! Your Purchase was successful!!";
char dd[]="You will get a confirmation SMS soon...";
//gotoxy(20,17);;
as:
window(30,70,7,24);
windoww(28,72,3,25);
gotoxy(31,5);
printf("::::::Choose Your Payment Option:::::::");
gotoxy(33,10);
printf("\xB2\xB2\xB2 1. bKash");
gotoxy(33,12);
printf("\xB2\xB2\xB2 2. uKash");
gotoxy(33,14);
printf("\xB2\xB2\xB2 3. DBBL");
gotoxy(33,16);
printf("\xB2\xB2\xB2 4. EBL");
gotoxy(38,23);
printf("<<<<<<<<<< >>>>>>>>>>");
gotoxy(48,23);
switch(_getch())
{
case '1':
strcpy(acname,"bKash");
break;
case '2':
strcpy(acname,"uKash");
break;
case '3':
strcpy(acname,"DBBL");
break;
case '4':
strcpy(acname,"EBL");
break;
default:
printf("\n\n\t\t\t\taWrong Entry!!Please re-entered correct option");
_getch();
system("cls");
goto as;
break;
}
system("cls");
windoww(23,80,3,25);
gotoxy(27,5);
printf("====================== PAYMENT ======================");
gotoxy(29,8);
printf("\n\t\t\t Please pay BDT %.2f using your %s account",total,acname);
printf("\n\t\t\t Account No : 72066066");
printf("\n\t\t\t Counter Number: 3250");
printf("\n\t\t\t **After successfully completing the payment procedure\n\t\t\t\t You will receive a Transaction IDfrom %s",acname);
printf("\n\n\t\t\t Press Enter to continue......");
_getch();
printf("\n\n\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB Enter Transaction ID(5 digits integer): ");
int count,trid;
do
{
count=0;
scanf("%d",&trid);
while(trid != 0)
{
// trid = trid/10
trid /= 10;
++count;
}
switch(count){
case 5:
gotoxy(30,21);
for(i=0;i<41;i++)
{
delay(50);
printf("%c",d[i]);
}
gotoxy(32,23);
for(i=0;i<39;i++)
{
delay(50);
printf("%c",dd[i]);
}_getch();
user_info();
for(i=0;i<lu;i++){
if(strcmp(uu[i].name,name)==0){
uu[i].reward=uu[i].reward+50;
}
}
fp=fopen("Web_reg.txt","w");
for(i=0;i<lu;i++){
fprintf(fp,"%s\t%s\t%s\t%d",uu[i].name,uu[i].pass,uu[i].mail,uu[i].reward);
if(i!=lu-1)
fprintf(fp,"\n");
}
fclose(fp);
break;
default:
printf("\n\t\t\t\tInvalid Transaction!!\tTry again..... ");
break;
}
}while(count!=5);
}
void user_info()
{
fp=fopen("Web_reg.txt","r");
lu=line_count("Web_reg.txt");
lu=lu+1;
for(i=0;i<lu;i++){
fscanf(fp,"%s\t%s\t%s\t%d\n",uu[i].name,uu[i].pass,uu[i].mail,&uu[i].reward);
}
fclose(fp);
}
void srch()
{
char srchname[20];
int checksrc,bb=0;
system("cls");
product_list();
src:
gotoxy(26,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH ITEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(29,6);
printf("\xDB\xDB\xDB Enter a Product Name: ");
scanf("%s",srchname);
for(i=0;i<t;i++){
checksrc=strcmp(srchname,p[i].name);
if(checksrc==0){
bb=1;
cc:
system("cls");
gotoxy(26,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH ITEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\t\t\t\t********** Selected Item: %s **********",p[i].name);
printf("\n\n\t\t\t\tProduct ID: %d",p[i].id);
printf("\n\n\t\t\t\tCategory: %s",p[i].category);
printf("\n\n\t\t\t\tUnit Price: %.2f",p[i].price);
printf("\n\n\t\t\t\tRating: %.2f",p[i].rating);
printf("\n\n\t\t\t\tReview: %s",p[i].review);
printf("\n\t\t\t\t---------------------------------------------");
printf("\n\t\t\t\t >>1. Buy Now\t\t>>2. Add to My Cart\n\n\t\t\t\t\t >>3. Back to Home\n\t\t\t\t ");
switch(_getch())
{
case '1':
buynow();
break;
case '2':
printf("\n\t\t\t\t\t******Item: %s******",p[i].name);
printf("\n\n\t\t\t\tEnter Quantity: ");
scanf("%f",&quantity);
utotal=quantity*p[i].price;
smycart();
break;
case '3':
home=1;
main();
break;
default:{
printf("\n\n\\t\t\taWrong Entry!!Please re-entered correct option");
_getch();
goto cc;
break;}
}
break;
}
}
if(bb==0){
printf("\n\t\t\t\tItem not available!\n\t\t\t\tPlease enter correct name....");
printf("\n\t\t\t\tPress Esc to Back or any other key to Search again!");
i=getche();
if(i==27)
{
home=1;
main();
}
else
srch();
}
}
//>>>>>>ADMIN>>>>>>>>>>>>>>
void admin_panel()
{int Id,removeid,removeindex1,removeproduct,kkk=0,j,xx=0,ll;
float Price;
char Name[20], Category[20],Replace[5];
system("cls");
gotoxy(31,4);
printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
gotoxy(31,5);
printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Admin panel \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(31,6);
printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
for(i=4;i<25;i++){
gotoxy(30,i);
printf("::\t\t\t\t\t::\n");
}
gotoxy(32,24);
printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
gotoxy(33,10);
printf("\xB2\xB2 1. View Available Items");
gotoxy(33,12);
printf("\xB2\xB2 2. Add New Item");
gotoxy(33,14);
printf("\xB2\xB2 3. Delete Sold Item");
gotoxy(33,16);
printf("\xB2\xB2 4. View Active User List");
gotoxy(33,18);
printf("\xB2\xB2 5. Check All Transaction");
gotoxy(33,20);
printf("\xB2\xB2 6. Log Out");
gotoxy(38,23);
printf("**************************");
gotoxy(50,23);
switch(_getch())
{

case '1':
xxxx:
system("cls");
product_list();
t=line_count("product_list.txt");
t=t+1;
int x=0;
gotoxy(10,1);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PRODUCTS\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(10,3);
printf("=========================================================================================");
gotoxy(10,4);
printf("|");
gotoxy(12,4);
printf("ID");
gotoxy(17,4);
printf("|");
gotoxy(21,4);
printf("Category");
gotoxy(31,4);
printf("|");
gotoxy(35,4);
printf("Name");
gotoxy(52,4);
printf("|");
gotoxy(56,4);
printf("Price");
gotoxy(66,4);
printf("|");
gotoxy(68,4);
printf("Rating");
gotoxy(78,4);
printf("|");
gotoxy(80,4);
printf("Selfnumner");
gotoxy(95,4);
printf("|");
gotoxy(10,5);printf("=========================================================================================");
j=6;
for(i=0;i<t;i++){
gotoxy(10,j);
printf("|");
gotoxy(11,j);
printf("%d",p[i].id);
gotoxy(17,j);
printf("|");
gotoxy(19,j);
printf("%s",p[i].category);
gotoxy(31,j);
printf("|");
gotoxy(33,j);
printf("%s",p[i].name);
gotoxy(52,j);
printf("|");
gotoxy(54,j);
printf("%.2f",p[i].price);
gotoxy(66,j);
printf("|");
gotoxy(68,j);
printf("%.2f",p[i].rating);
gotoxy(78,j);
printf("|");
gotoxy(84,j);
printf("%s",p[i].details);
gotoxy(95,j);
printf("|");
gotoxy(10,j+1);
printf("-----------------------------------------------------------------------------------------");
j=j+2;
}
if(xx==1)
goto xxxxx;
else
{
printf("\nPress Enter to back ");
_getch();
admin_panel();
}
break;
case '2':
xx:
system("cls");
printf("\n\n\t\tPlease input the following information:");
printf("\n\n\t\t\t > Category: ");
scanf("%s",Category);
printf("\n\n\t\t\t > Product ID: ");
scanf("%d",&Id);
printf("\n\n\t\t\t > Name: ");
scanf("%s",Name);printf("\n\n\t\t\t > Price: ");
scanf("%f",&Price);
printf("\n\n\t\t\t > Selfnumber: ");
scanf("%s",Replace);
printf("\n\n\t\t\t Press Enter to Confirm....");
_getch();
fl=fopen("product_list.txt","a");
fprintf(fl,"\n%d\t%s\t%s\t%.2f\t5.00\t%s",Id,Category,Name,Price,Replace);
fclose(fl);
xxx:
system("cls");
printf("\n\n\n\t\t\tNew product has been added!!\n\t\t\tDo you want to add any more item?\n\t\t\t\t(y or n):");
switch(_getch())
{
case 'y':
goto xx;
break;
case 'n':
admin_panel();
break;
default:
printf("\n\n\t\t\tWrong Entry!!Please re-entered correct option");
_getch();
system("cls");
goto xxx;
break;
}
break;
case '3':
kk:
system("cls");
xx=1;
goto xxxx;
xxxxx:
printf("\n\n\t1. Delete an Item\t\t2. Back to Admin Panel");
switch(_getch())
{
case '1':{
printf("\n\n\nEnter a product ID you want to delete: ");
scanf("%d",&removeproduct);
for(i=0;i<t;i++){
if(removeproduct==p[i].id){
removeindex1=i;
kkk=1;
break;
}
}
if(kkk==0){
printf("\n\n\aWrong Entry!!Please re-entered correct option");
_getch();
system("cls");
goto kk;
}
for(j=removeindex1;j<t-1;j++){
        p[j].id=p[j+1].id;
p[j].price=p[j+1].price;
p[j].rating=p[j+1].rating;
strcpy(p[j].name,p[j+1].name);
strcpy(p[j].category,p[j+1].category);
strcpy(p[j].details,p[j+1].details);
}
kkk=0;
t=t-1;
system("cls");
fl=fopen("product_list.txt","w");
for(i=0;i<t;i++){
fprintf(fl,"%d\t%s\t%s\t%.2f\t%.2f\t%s",p[i].id,p[i].category,p[i].name,p[i].price,p[i].rating,p[i].details);
if(i!=t-1)
fprintf(fl,"\n");
}
fclose(fl);
goto kk;}
//_getch();
//admin_panel();
case '2':
admin_panel();
break;
default:
printf("\n\n\t\t\tWrong Entry!!Please re-entered correct option");
_getch();
system("cls");
goto xxxx;
break;
}
break;
case '4':
system("cls");
user_info();
printf("\n\t\t********************** Active Users *************************\n\n");
printf("\n\t\tUsername\t Mobile\t\tRewards(points)");
printf("\n\t\t============================================================");
for(i=0;i<lu;i++){
printf("\n\t\t%s\t\t%s\t\t %d",uu[i].name,uu[i].mail,uu[i].reward);
printf("\n\t\t-------------------------------------------------------------");
}
_getch();
admin_panel();
break;
case '5':
system("cls");
gotoxy(18,1);
printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB TODAY'S ALL TRANSACTIONS \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
/*fadmin=fopen("purchase.txt","r");
line_count("purchase.txt");
ll=ll+1;*/
float gtotal=0;
/*if(fadmin==NULL){
printf("\n\n\n\t\t\tNo Transaction Available!!\n");
_getch();
admin_panel();
break;
}
for(i=0;i<ll;i++){
fscanf(fadmin,"%s\t%d\t%s\t%f\t%s\t%s\t%s\t%f\n",mc[i].rname,&mc[i].id,mc[i].name,&mc[i].quantity,mc[i].acname,mc[i].rlocation,mc[i].date,&mc[i].utotal);
}
fclose(fp);*/

ttt();
gotoxy(75,2);
printf("Today is %s",buffer);
//gotoxy(18,4);
printf("\n========================================================================================================================");
//gotoxy(18,5);
printf("\n\t| Product Name\t Productid\t Quantity\tUnit Price\tTotal Price\tPayment Type \tLocation |");
/*gotoxy(34,5);
printf("Productid\t");
gotoxy(44,5);
printf("Quantity\t");
gotoxy(60,5);
printf("Unit Price\t");
gotoxy(70,5);
printf("Total Price\t");
gotoxy(79,5);
printf("Payment Type \t");
gotoxy(89,5);
printf("Location |");*/
//gotoxy(18,6);
printf("\n========================================================================================================================");
//Showing all transactions//
showtransaction();
/*m=7;
for(i=0;i<ll;i++){
if(strcmp(mc[i].date,buffer)==0){
gotoxy(18,m);
printf("|");
gotoxy(20,m);
printf("%s",mc[i].name);
gotoxy(36,m);
printf("| %.2f",mc[i].quantity);
gotoxy(45,m);
printf("| %s",mc[i].rname);
gotoxy(58,m);
printf("| %s",mc[i].date);
gotoxy(70,m);
printf("| %s",mc[i].acname);
gotoxy(80,m);
printf("| %.2f",mc[i].utotal);
gotoxy(92,m);printf("|");
gotoxy(18,m+1);
if(i!=ll-1)
printf("---------------------------------------------------------------------------");
else
printf("===========================================================================");
m=m+2;
gtotal = gtotal + mc[i].utotal;
}
}
gotoxy(66,m);
printf("Gross Amount: %.2f TK",tr.total);
gotoxy(40,m+2);
printf("<<<<<<<<<< >>>>>>>>>>");*/
gotoxy(50,m+2);
_getch();
admin_panel();
break;
case '6':
system("cls");
gotoxy(25,10);
printf("****Thank you for using this system!!!\n\n\t\t\t\tHave a nice day!!!");
_getch();
exit(0);
default:
_getch();
admin_panel();
}
_getch();
}
void ttt(void) //for time
{
time_t curtime;
struct tm *loctime;
curtime = time (NULL);
loctime = localtime (&curtime);
strftime (buffer, SIZE, "%d.%m.%y", loctime);
}
int window(int a,int b,int c,int d)
{
int i;
system("cls");
gotoxy(20,10);
for (i=a;i<=b;i++){gotoxy(i,4);printf("\xcd");
gotoxy(i,6);printf("\xcd");
gotoxy(i,c);printf("\xcd");
gotoxy(i,d);printf("\xcd");
}
gotoxy(a,4);printf("\xc9");
gotoxy(a,5);printf("\xba");
gotoxy(a,6);printf("\xc8");
gotoxy(b,4);printf("\xbb");
gotoxy(b,5);printf("\xba");
gotoxy(b,6);printf("\xbc");
for(i=c;i<=d;i++){
gotoxy(a,i);printf("\xba");
gotoxy(b,i);printf("\xba");
}
gotoxy(a,c);printf("\xc9");
gotoxy(a,d);printf("\xc8");
gotoxy(b,c);printf("\xbb");
gotoxy(b,d);printf("\xbc");
}
int windoww(int e,int f,int g,int h)
{
int i;
gotoxy(20,10);
for (i=e;i<=f;i++){
gotoxy(i,g);printf("\xcd");gotoxy(i,h);printf("\xcd");
}
gotoxy(e,4);printf("\xc9");
gotoxy(e,5);printf("\xba");
gotoxy(e,6);printf("\xc8");
gotoxy(f,4);printf("\xbb");
gotoxy(f,5);printf("\xba");
gotoxy(f,6);printf("\xbc");
for(i=g;i<=h;i++){
gotoxy(e,i);printf("\xba");
gotoxy(f,i);printf("\xba");
}
gotoxy(e,g);printf("\xc9");
gotoxy(e,h);printf("\xc8");
gotoxy(f,g);printf("\xbb");
gotoxy(f,h);printf("\xbc");
}
void showtransaction(){
FILE *ftransaction;
ftransaction=fopen("transaction.txt","r");
while(fread(&tr,sizeof(tr),1,ftransaction)){
    printf("\n\t%s\t\t%d\t\t%d\t\t%.2f\t\t%.2f\t\t%s\t\t%s",tr.name,tr.id,tr.quantity,tr.unitprice,tr.total,tr.acname,tr.dlocation);
}fclose(ftransaction);
}



