
	int find_dublicate(node*temp,int data)
	{
		if (temp==NULL)
		{
			return dublicate_number;
		}
		else
		{
			if (temp->data == data&&temp->dubliate == false)
			{
				dublicate_number++;
				temp->dubliate = true;
			}
			find_dublicate(temp->left, data);
			find_dublicate(temp->right, data);
		}
		
	}