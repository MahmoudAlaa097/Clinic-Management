#include <stdio.h>
#include <stdlib.h>
#include "stdtypes.h"
#include "List_struct.h"

void AddNewPatient(pu16 name,pu16 gender,u8 age,u8 id,List* L)
{
	Node* N=(Node*)malloc(sizeof(Node));
	if(L->start==NULL)
	{
		L->start=N;
		N->prev=NULL;
	}
	else
	{
		L->end->next=N;
		N->prev=L->end;
	}
	N->next=NULL;
	L->end=N;
	N->name=name;
	N->gender=gender;
	N->age=age;
	N->id=id;
}
Node* SearchNode(u8 id,List L)
{
	Node* temp=L.start;
	while((temp != NULL) && (temp->id != id))
	{
		temp = temp ->next;
	}
	return temp;
}
void CheckID(pu8 id, List L)
{
	u8 flag=1;
	Node* N;
	while(flag==1)
	{
		N= SearchNode(*id,L);
		if(N != NULL)
		{
			printf("This ID is already exist. Try another: ");
			scanf("%d",id);
		}
		else
		{
			flag=0;
		}
	}
}
void ViewNode(Node*N)
{
	printf("Name: %s\n",N->name);
	printf("Gender: %s\n",N->gender);
	printf("Age: %u\n",N->age);
	printf("ID: %u\n",N->id);
}
void EditNode(pu16 name,pu16 gender,u8 age,u8 id,Node* N)
{
	u8 i;
	pu16 Name=(pu16)malloc(sizeof(pu16));
	for(i=0;i<sizeof(Name);i++)
	{
		Name[i]=name[i];
	}
	pu16 Gender=(pu16)malloc(sizeof(pu16));
	Gender=gender;
	N->name = Name;
	N->gender = Gender;
	N->age = age;
	N->id = id;
}
void ViewSlots(Slots S)
{
	if((S.Slot1!=NULL)&&(S.Slot2!=NULL)&&(S.Slot3!=NULL)&&(S.Slot4!=NULL)&&(S.Slot5!=NULL))
	{
		printf("There is no available S.\n");
	}
	else
	{
		printf("The available Slots are:\n");
		if(S.Slot1==NULL)
		{
			printf("2:00 PM to 2:30 PM\n");
		}
		if(S.Slot2==NULL)
		{
			printf("2:30 PM to 3:00 PM\n");
		}
		if(S.Slot3==NULL)
		{
			printf("3:30 PM to 4:00 PM\n");
		}
		if(S.Slot4==NULL)
		{
			printf("4:00 PM to 4:30 PM\n");
		}
		if(S.Slot5==NULL)
		{
			printf("4:30 PM to 5:00 PM\n");
		}
	}
}
void ViewReservations(Slots S)
{
	if((S.Slot1==NULL)&&(S.Slot2==NULL)&&(S.Slot3==NULL)&&(S.Slot4==NULL)&&(S.Slot5==NULL))
	{
		printf("There is no reservations today.\n");
	}
	else
	{
		printf("Reservation List for today:\n");
		if(S.Slot1!=NULL)
		{
			printf("2:00 PM to 2:30 PM\n");
		}
		if(S.Slot2!=NULL)
		{
			printf("2:30 PM to 3:00 PM\n");
		}
		if(S.Slot3!=NULL)
		{
			printf("3:30 PM to 4:00 PM\n");
		}
		if(S.Slot4!=NULL)
		{
			printf("4:00 PM to 4:30 PM\n");
		}
		if(S.Slot5!=NULL)
		{
			printf("4:30 PM to 5:00 PM\n");
		}
	}
}