#include <stdio.h>
#include <stdlib.h>
#include "stdtypes.h"
#include "List_struct.h"

void main(void)
{
	u16 i;
	u8 mode,feature,exit=1,id,age,slot;
	u16 pass,gender[6],name[sizeof(pu16)];
	Node* Patient;
	Slots Reservations;
	PatientList.start=NULL;
	PatientList.end=NULL;
	Reservations.Slot1=NULL;
	Reservations.Slot2=NULL;
	Reservations.Slot3=NULL;
	Reservations.Slot4=NULL;
	Reservations.Slot5=NULL;
	while(exit=1)
	{
		printf("Please Enter 0 for Admin mode or 1 for User mode: ");
		scanf("%d",&mode);
		if(mode==0)
		{
				printf("Please Enter the password: ");
				scanf("%d",&pass);
				for(i=0;i<2;i++)
				{
					if(pass != 1234)
					{
						printf("Try Again: ");
						scanf("%d",&pass);
					}
					else
					{
						break;
					}	
				}
				if(pass == 1234)
				{
					printf("What do you want to do?\n0- Add new patient.\n1- Edit patient record.\n2- Reserve a slot with the doctor.\n3- Cancel reservation.\n");
					scanf("%d",&feature);
					if(feature==0)
					{
						printf("Enter patient name: ");
						scanf("%s",name);
						printf("Enter patient gender: ");
						scanf("%s",gender);
						printf("Enter patient age : ");
						scanf("%d",&age);
						printf("Enter patient ID : ");
						scanf("%d",&id);
						CheckID(&id,PatientList);
						printf("Patient added.\n");
						AddNewPatient(name,gender,age,id,&PatientList);
					}
					else if(feature==1)
					{
						u8 edit;
						printf("Enter Patient ID: ");
						scanf("%d",&id);
						Patient = SearchNode(id, PatientList);
						if(Patient != NULL)
						{
							ViewNode(Patient);
							printf("What do want to edit?\n0- Name only.\n1- Gender only.\n2- Age only.\n3-More than one.\n");
							scanf("%d",&edit);
							if(edit==0)
							{
								printf("New Name: ");
								scanf("%s",name);
								for(i=0;i<2;i++)
								{
									gender[i]=Patient->gender[i];
								}
								age = Patient->age;
								id = Patient->id;
							}
							else if(edit==1)
							{
								printf("New Gender: ");
								scanf("%s",gender);
								for(i=0;i<sizeof(name);i++)
								{
									name[i]=Patient->name[i];
								}
								age = Patient->age;
								id = Patient->id;
							}
							else if(edit==2)
							{
								printf("New Age: ");
								scanf("%u",&age);
								for(i=0;i<sizeof(name);i++)
								{
									name[i]=Patient->name[i];
								}
								for(i=0;i<2;i++)
								{
									gender[i]=Patient->gender[i];
								}
								id = Patient->id;
							}
							else if(edit==3)
							{
								printf("New Name: ");
								scanf("%s",name);
								printf("New Gender: ");
								scanf("%s",gender);
								printf("New Age: ");
								scanf("%u",age);
								printf("New ID: ");
								scanf("%u",id);
								
							}
							else
							{
								printf("Wrong number.");
							}
						}
						else{}
						EditNode(name,gender,age,id,Patient);
					}
					else if(feature==2)
					{
						printf("Enter Patient ID: ");
						scanf("%u",&id);
						Patient=SearchNode(id,PatientList);
						if(Patient==NULL)
						{
							printf("This ID does not exist.\n");
						}
						else
						{
							ViewSlots(Reservations);
						if((Reservations.Slot1!=NULL)&&(Reservations.Slot2!=NULL)&&(Reservations.Slot3!=NULL)&&(Reservations.Slot4!=NULL)&&(Reservations.Slot5!=NULL))
						{}
						else
						{
							printf("Select an empty slot(1,2,3,4,5): ");
							scanf("%u",&slot);
							if(slot==1)
							{
								if(Reservations.Slot1!=NULL)
								{
									printf("This slot is not empty.\n");
								}
								else
								{
									Reservations.Slot1=Patient;
								}
							}
							else if(slot==2)
							{
								if(Reservations.Slot2!=NULL)
								{
									printf("This slot is not empty.\n");
								}
								else
								{
									Reservations.Slot2=Patient;
								}
							}
							else if(slot==3)
							{
								if(Reservations.Slot3!=NULL)
								{
									printf("This slot is not empty.\n");
								}
								else
								{
									Reservations.Slot3=Patient;
								}
							}
							else if(slot==4)
							{
								if(Reservations.Slot4!=NULL)
								{
									printf("This slot is not empty.\n");
								}
								else
								{
									Reservations.Slot4=Patient;
								}
							}
							else if(slot==5)
							{
								if(Reservations.Slot5!=NULL)
								{
									printf("This slot is not empty.\n");
								}
								else
								{
									Reservations.Slot5=Patient;
								}
							}
							else if(slot>5)
							{
								printf("Wrong number.\n");
							}
						
						}
						}
					}
					else if(feature==3)
					{
						printf("Enter Patient ID: ");
						scanf("%u",&id);
						Patient=SearchNode(id,PatientList);
						printf("Enter your reserved slot: ");
						scanf("%u",&slot);
						if(slot==1)
						{
							if(Reservations.Slot1==Patient)
							{
								Reservations.Slot1=NULL;
								printf("Reservation Canceled\n");
							}
						}
						else if (slot==2)
						{
							if(Reservations.Slot2==Patient)
							{
								Reservations.Slot2=NULL;
								printf("Reservation Canceled\n");
							}
						}
						else if (slot==3)
						{
							if(Reservations.Slot3==Patient)
							{
								Reservations.Slot3=NULL;
								printf("Reservation Canceled\n");
							}
						}
						else if (slot==4)
						{
							if(Reservations.Slot4==Patient)
							{
								Reservations.Slot4=NULL;
								printf("Reservation Canceled\n");
							}
						}
						else if (slot==5)
						{
							if(Reservations.Slot5==Patient)
							{
								Reservations.Slot5=NULL;
								printf("Reservation Canceled\n");
							}
						}
						else
						{
							printf("Wrong number.\n");
						}
					}
					else 
					{
						printf("Wrong number.\n");
					}
				}
		}
		else if(mode==1)
		{
				printf("What do you want to do?\n0- View patient record.\n1- View todays reservations.\n");
				scanf("%d",&feature);
				if(feature==0)
				{
					printf("Enter Patient ID: ");
					scanf("%u",&id);
					Patient = SearchNode(id,PatientList);
					ViewNode(Patient);
				}
				else if(feature==1)
				{
					ViewReservations(Reservations);
				}
				else
				{
					printf("Wrong number.");
				}
		}
		else
		{
				printf("Wrong Number.");
		}
	}
}