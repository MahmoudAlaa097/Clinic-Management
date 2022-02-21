#ifndef list_steuct
#define list_steuct
typedef struct
{
	u8 age;
	u8 id;
	pu16 name;
	pu16 gender;
	struct Node* next;
	struct Node* prev;
	
}Node;

typedef struct
{
	Node* start;
	Node* end;
}List;
List PatientList;
typedef struct
{
	Node* Slot1;
	Node* Slot2;
	Node* Slot3;
	Node* Slot4;
	Node* Slot5;
}Slots;
#endif
void AddNewPatient(pu16 name,pu16 gendre,u8 age,u8 id,List* PatientList);
Node* SearchNode(u8 id,List L);
void CheckID(pu8 id, List L);
void ViewNode(Node*N);
void ViewSlots(Slots S);
void ViewReservations(Slots S);