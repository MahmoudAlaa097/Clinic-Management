Node* Create_node(void)
{
	return (Node*) malloc(sizeof(node));
}
void Append_Node(Node* N,List* L)
{
	if(L->start==Null)
	{
		L->start=N;
		L->end=N;
		N->next=Null;
		N->prev=Null;
	}
	else
	{
		L->end->next=N;
		N->next=Null;
		N->prev=L->end;
		L->end=N;
	}
}
Node* SearchNode(u8 id,List L)
{
	Node* temp=L.start;
	while(temp != NULL) && (temp->id != id)
	{
		temp = temp ->next;
	}
	return temp;
}
void CheckID(pu8 id, List L)
{
	u8 flag;
	Node* N;
	while(flag==1)
	{
		N= SearchNode(*id,L);
		if(N != NULL)
		{
			printf("Try Again: ");
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
	printf("age: %s\n",N->age);
	printf("ID: %s\n",N->id);
}

