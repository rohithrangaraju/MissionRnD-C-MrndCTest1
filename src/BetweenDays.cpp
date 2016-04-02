/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
struct Date
{
	int dt, mt, yr;
};

int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
int leap(Date d);

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL) return -1;
	struct node* temp;
	//struct node* temp1;
	char s[8], b[8];
	temp = date1head;
	for (int i = 0; i < 8;i++){
		s[i]= temp->data;
		temp = temp->next;
	}
	temp = date2head;
	for (int i = 0; i < 8; i++){
		b[i] = temp->data;
		temp = temp->next;
	}
	Date d1,d2;
	d1.dt = s[0]*10+s[1];
	d1.mt = s[2] * 10 + s[3];
	d1.yr = s[4] * 1000 + s[5] * 100 + s[6] * 10 + s[7];
	d2.dt = b[0] * 10 + b[1];
	d2.mt = b[2] * 10 + b[3];
	d2.yr = b[4] * 1000 + b[5] * 100 + b[6] * 10 + b[7];
	if (d1.dt == d2.dt&&d1.mt == d2.mt&&d1.yr == d2.yr)  return 0;
	int count1, count2;
    count1= d1.yr * 365 + d1.dt;
	count2 = d2.yr * 365 + d2.dt;
	for (int i = 0; i<d1.mt - 1; i++)
		count1 += monthDays[i];
    
	for (int i = 0; i<d2.mt - 1; i++)
		count2 += monthDays[i];
	count1 += leap(d1);
	count2 += leap(d2);
	if (count1>count2) return (count1 - count2) - 1;
	else return (count2 - count1) - 1;
}
int leap(Date d){
	int years = d.yr;

	if (d.mt <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}